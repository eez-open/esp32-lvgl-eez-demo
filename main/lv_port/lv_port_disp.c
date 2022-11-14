/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"

#include "disp_spi.h"
#include "esp_log.h"

/* Littlevgl specific */
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "lvgl_helpers.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "lv_port_disp"

#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
  #define MY_DISP_HOR_RES 400 /* 240 */
  #define MY_DISP_VER_RES 300 /* 320 */
  #define DISP_BUF_SIZE_CUSTOM (MY_DISP_HOR_RES * 8) /* 10240 */
#else
  #define MY_DISP_HOR_RES 320 /* 240 */
  #define MY_DISP_VER_RES 240 /* 320 */
  #define DISP_BUF_SIZE_CUSTOM (MY_DISP_HOR_RES * 16) /* 10240 */
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
// static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
// static void disp_clear(lv_disp_drv_t *disp_drv);

/**********************
 *  STATIC VARIABLES
 **********************/
DMA_ATTR lv_color_t *buf1 = NULL;
DMA_ATTR lv_color_t *buf2 = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/
    /**
     * LVGL requires a buffer where it internally draws the widgets.
     * Later this buffer will passed to your display driver's `flush_cb` to copy its content to your display.
     * The buffer has to be greater than 1 display row
     *
     * There are 3 buffering configurations:
     * 1. Create ONE buffer:
     *      LVGL will draw the display's content here and writes it to your display
     *
     * 2. Create TWO buffer:
     *      LVGL will draw the display's content to a buffer and writes it your display.
     *      You should use DMA to write the buffer's content to the display.
     *      It will enable LVGL to draw the next part of the screen to the other buffer while
     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
     *
     * 3. Double buffering
     *      Set 2 screens sized buffers and set disp_drv.full_refresh = 1.
     *      This way LVGL will always provide the whole rendered screen in `flush_cb`
     *      and you only need to change the frame buffer's address.
     */

     ESP_LOGI(TAG, "MALLOC_CAP_SPIRAM SIZE: %d", heap_caps_get_total_size(MALLOC_CAP_DMA));
     ESP_LOGI(TAG, "DISP_BUF_SIZE_CUSTOM SIZE: %d", 2 * (DISP_BUF_SIZE_CUSTOM * sizeof(lv_color_t)));

    /* static lv_color_t * */
    buf1 = heap_caps_malloc(DISP_BUF_SIZE_CUSTOM * sizeof(lv_color_t),
                            MALLOC_CAP_DMA | MALLOC_CAP_8BIT /* MALLOC_CAP_DMA */);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    /* static lv_color_t * */
    buf2 = heap_caps_malloc(DISP_BUF_SIZE_CUSTOM * sizeof(lv_color_t),
                            MALLOC_CAP_DMA | MALLOC_CAP_8BIT /* MALLOC_CAP_DMA */);
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_draw_buf_t draw_buf_dsc_2;

    uint32_t size_in_px = DISP_BUF_SIZE_CUSTOM;

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820 || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8176 || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
    /* Actual size in pixels, not bytes. */
    size_in_px *= 8;
#endif

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf1, buf2, size_in_px /* DISP_BUF_SIZE_CUSTOM */);

    // /* Example for 3) also set disp_drv.full_refresh = 1 below*/
    // static lv_disp_draw_buf_t draw_buf_dsc_3;
    // static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*A screen sized buffer*/
    // static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*Another screen sized buffer*/
    // lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2, MY_DISP_VER_RES * LV_VER_RES);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_driver_flush;

    /*Set the resolution of the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;

    // disp_drv.full_refresh = 1;

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb  = disp_driver_set_px;
#endif

    disp_drv.draw_buf = &draw_buf_dsc_2;
    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);

    ESP_LOGI(TAG, "Display hor size: %d, ver size: %d", LV_HOR_RES, LV_VER_RES);
    ESP_LOGI(TAG, "Display buffer size: %d", DISP_BUF_SIZE_CUSTOM);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
