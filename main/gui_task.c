/**
 * @file gui_task.c
 * @author catcatBlue (1625237402@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-05-14
 *
 * @copyright Copyright (c) 2022
 */

/*set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "gui_task.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#include "lv_port/lv_port.h"
#include "lvgl/demos/lv_demos.h"

/*********************
 *      DEFINES
 *********************/
#define TAG               "demo"
#define LV_TICK_PERIOD_MS 1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);
#ifndef CONFIG_LV_USE_DEMO_EEZ
static void create_demo_application(void);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void gui_task_init(void)
{
    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    /* TODO: ！！！史前巨坑！！！优先级要改大点 */
    xTaskCreatePinnedToCore(guiTask, "gui", 4096 * 2, NULL, 10, NULL, 1);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter)
{
    (void)pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    // /* Initialize SPI or I2C bus used by the drivers */
    // lvgl_driver_init();

    /* 显示初始化 */
    lv_port_disp_init();

    /* Initialize SPI or I2C bus used by the drivers */
    /**
     * 由于设置显示器的分辨率不再是全局定义的，
     * 所以lvgl驱动初始化必须要在指定lvgl分辨率之后进行,
     * 因为其中包括设置spi最大传输大小，这里需要屏幕分辨率参数
     */
    lvgl_driver_init();

    /* 输入设备初始化 */
    lv_port_indev_init();

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name     = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    /* Create the demo application */
    #ifdef CONFIG_LV_USE_DEMO_EEZ
      /*Create a "Hello world!" label*/
      #ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
      lv_obj_t * label = lv_label_create(lv_scr_act());
      lv_label_set_text(label, "Hello world!");
      lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
      #else
      flowInit();
    #endif
    #else
      create_demo_application();
    #endif
    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(1));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            #ifdef CONFIG_LV_USE_DEMO_EEZ
              #ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
                flowTick();
              #endif
            #endif
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

#ifndef CONFIG_LV_USE_DEMO_EEZ
static void create_demo_application(void)
{
    /* When using a monochrome display we only show "Hello World" centered on the
     * screen */
#if defined CONFIG_LV_TFT_DISPLAY_MONOCHROME || \
    defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S || \
    defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D

    /* use a pretty small demo for monochrome displays */
    /* Get the current screen  */
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);

    /*Create a Label on the currently active screen*/
    lv_obj_t *label1 = lv_label_create(scr, NULL);

    /*Modify the Label's text*/
    lv_label_set_text(label1, "Hello\nworld");

    /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

#else
    /* Otherwise we show the selected demo */
#if defined   CONFIG_LV_USE_DEMO_WIDGETS
    lv_demo_widgets();
#elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
    lv_demo_keypad_encoder();
#elif defined CONFIG_LV_USE_DEMO_EEZ
    lv_demo_eez();
#elif defined CONFIG_LV_USE_DEMO_BENCHMARK
    lv_demo_benchmark();
#elif defined CONFIG_LV_USE_DEMO_STRESS
    lv_demo_stress();
#elif defined CONFIG_LV_USE_DEMO_MUSIC
    lv_demo_music();
#else
#error "No demo application selected."
#endif
#endif
}
#endif
static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}


#else /*Enable this file at the top*/
/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
