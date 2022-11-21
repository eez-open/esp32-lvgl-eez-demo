/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */

#include "main.h"
#include "gui_task.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "main"

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void example_task1(void *pvParameters)
{
    static const char *ETAG  = "task1";
    uint32_t           count = 0;

    for (;;) {
        ++count;
        // ESP_LOGI(ETAG, "count = %d", count);
        // if ((count) == 10) {
        //     disp_spi_change_device_speed(20 * 1000 * 1000);
        // }
        // if ((count) == 15) {
        //     disp_spi_change_device_speed(16 * 1000 * 1000);
        // }
        ESP_LOGI(ETAG,
                 "free_heap_size = %d Byte,\t%.2f KByte,\t%.2f MByte",
                 esp_get_free_heap_size(),
                 esp_get_free_heap_size() / 1024.0,
                 esp_get_free_heap_size() / (1024.0 * 1024.0));
        vTaskDelay(pdMS_TO_TICKS(30 * 1000));
    }
    vTaskDelete(NULL);
}

/**********************
 *   APPLICATION MAIN
 **********************/
void app_main()
{
    xTaskCreate(example_task1,             /* 指向需要创建的任务 */
                "example_task1",           /* 任务的文本名字，用于调试 */
                1024 * 8,                  /* 栈深，单位字节 */
                NULL,                      /* 传入任务的参数 */
                configMAX_PRIORITIES - 24, /* 任务优先级 */
                NULL                       /* 控制该任务的句柄，注意要'&' */
    );
    gui_task_init();
}
