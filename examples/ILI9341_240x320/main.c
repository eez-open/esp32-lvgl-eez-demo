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
#include "ui/vars.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "main"

#define CONFIG_EXAMPLE_IPV4
#define HOST_IP_ADDR "192.168.100.80"
#define PORT 34089

static const char *CH1_STATUS = "OUTP? CH1\n";
static const char *CH2_STATUS = "OUTP? CH2\n";

static const char *CH1_ON = "OUTP ON, CH1\n";
static const char *CH1_OFF = "OUTP OFF, CH1\n";
static const char *CH2_ON = "OUTP ON, CH2\n";
static const char *CH2_OFF = "OUTP OFF, CH2\n";

static const char *CH_ALL_STAT = "MEAS:VOLT? CH1;:MEAS:CURR? CH1;:MEAS:VOLT? CH2;:MEAS:CURR? CH2\n";
char ALL_CH_STAT[50] = "";

extern char CH1_V[];
extern char CH1_A[];
extern char CH2_V[];
extern char CH2_A[];
extern char WIFI_SSID[];
extern char WIFI_PASS[];
extern char WIFI_IP[];
extern char BB3_IP[];
extern bool BB3_CONNECTED;
extern bool WIFI_CONNECTED;
extern bool SCPI_UPDATED;
extern bool CH1_UPDATE;
extern bool CH1_POWER_ON;
extern bool CH2_UPDATE;
extern bool CH2_POWER_ON;
extern char BB3_RESPONSE[];

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


xSemaphoreHandle connectionSemaphore;

//Manejador de eventos - event task
//https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/wifi.html
static esp_err_t event_handler(void *ctx, system_event_t *event)
{
  switch (event->event_id)
  {
  case SYSTEM_EVENT_STA_START:
    esp_wifi_connect();
    ESP_LOGI(TAG,"connecting...\n");
    break;

  case SYSTEM_EVENT_STA_CONNECTED:
    ESP_LOGI(TAG,"connected\n");
    break;

  case SYSTEM_EVENT_STA_GOT_IP:
    ESP_LOGI(TAG,"got ip\n");
    xSemaphoreGive(connectionSemaphore);
    break;

  case SYSTEM_EVENT_STA_DISCONNECTED:
    ESP_LOGI(TAG,"disconnected\n");
    break;

  default:
    break;
  }
  return ESP_OK;
}

void wifiInit()
{
  ESP_ERROR_CHECK(nvs_flash_init()); //inicialización de memoria flash 
  tcpip_adapter_init();
  //inicialización del Controlador de eventos
  ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL)); 

  wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_config));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

  wifi_config_t wifi_config =
      {
          .sta = {
              //.ssid = WIFI_SSID,
              //.password = WIFI_PASS,
              .sae_pwe_h2e = WPA3_SAE_PWE_BOTH,
              }};
  memcpy(wifi_config.ap.ssid,WIFI_SSID,strlen(WIFI_SSID));
  memcpy(wifi_config.ap.password,WIFI_PASS,strlen(WIFI_PASS));
  esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);
  ESP_ERROR_CHECK(esp_wifi_start());
}

static void parseCH_ALL_STAT(){
  printf("RECVEIVED ALL CH STATUS: %s", BB3_RESPONSE);

  //char    str[]= "ls -l";
  char ** res  = NULL;
  char *  p    = strtok (BB3_RESPONSE, ";");
  int n_spaces = 0;


  /* split string and append tokens to 'res' */

  while (p) {
    res = realloc (res, sizeof (char*) * ++n_spaces);

    if (res == NULL)
      exit (-1); /* memory allocation failed */

    res[n_spaces-1] = p;

    p = strtok (NULL, ";");
  }

  /* realloc one extra element for the last NULL */

  res = realloc (res, sizeof (char*) * (n_spaces+1));
  res[n_spaces] = 0;
  printf("Got %i parameter/s", n_spaces);
  if (n_spaces == 4){
    /* print the result */
    printf("%d\n",sizeof(res[0]));
    if (sizeof(res[0]) == 1){sprintf(CH1_V, "0.0000");}else{sprintf(CH1_V, res[0]);}
    if (sizeof(res[1]) == 1){sprintf(CH1_A, "0.0000");}else{sprintf(CH1_A, res[1]);}
    if (sizeof(res[2]) == 1){sprintf(CH2_V, "0.0000");}else{sprintf(CH2_V, res[2]);}
    if (sizeof(res[3]) == 1){sprintf(CH2_A, "0.0000");}else{sprintf(CH2_A, res[3]);}
  }
  /* free the memory allocated */

  free (res);
}

static void tcp_client_task(void *pvParameters)
{
    char rx_buffer[128];
    char host_ip[] = HOST_IP_ADDR;
    int addr_family = 0;
    int ip_protocol = 0;
    while (1) {
      if(SCPI_UPDATED){
          SCPI_UPDATED= false;
          BB3_CONNECTED = false;
    printf("SCPI update: ");
      if (WIFI_CONNECTED == true){
      #if defined(CONFIG_EXAMPLE_IPV4)
              struct sockaddr_in dest_addr;
              inet_pton(AF_INET, host_ip, &dest_addr.sin_addr);
              dest_addr.sin_family = AF_INET;
              dest_addr.sin_port = htons(PORT);
              addr_family = AF_INET;
              ip_protocol = IPPROTO_IP;
      #elif defined(CONFIG_EXAMPLE_SOCKET_IP_INPUT_STDIN)
              struct sockaddr_storage dest_addr = { 0 };
              ESP_ERROR_CHECK(get_addr_from_stdin(PORT, SOCK_STREAM, &ip_protocol, &addr_family, &dest_addr));
      #endif

        int sock =  socket(addr_family, SOCK_STREAM, ip_protocol);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
            //break;
        }
        else{
          ESP_LOGI(TAG, "Socket created, connecting to %s:%d", host_ip, PORT);
          BB3_CONNECTED = true;
        }
        int err = connect(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err != 0) {
            ESP_LOGE(TAG, "Socket unable to connect: errno %d", errno);
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
            //break;
        }
        else{
          ESP_LOGI(TAG, "Successfully connected\n");
          BB3_CONNECTED = true;
        }
      if (BB3_CONNECTED){
        while (1) {
            int err = 0;
            printf("Connected to BB3 and waiting for SCPI commands\n");
              SCPI_UPDATED = false;
              BB3_CONNECTED = false;
              if(CH1_UPDATE){
                printf("CH1 update\n\r");
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
                if(CH1_POWER_ON){err = send(sock, CH1_ON, strlen(CH1_ON), 0);}
                else{err = send(sock, CH1_OFF, strlen(CH1_OFF), 0);}
                vTaskDelay(1 / portTICK_RATE_MS);
                err = send(sock, CH_ALL_STAT, strlen(CH_ALL_STAT), 0);
              }
              else if(CH2_UPDATE){
                printf("CH2 update\n\r");
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
                if(CH2_POWER_ON){err = send(sock, CH2_ON, strlen(CH2_ON), 0);} 
                else{err = send(sock, CH2_OFF, strlen(CH2_OFF), 0);}
                vTaskDelay(1 / portTICK_RATE_MS);
                err = send(sock, CH_ALL_STAT, strlen(CH_ALL_STAT), 0);
              }
              // Get status of BB3
              else{
                  err = send(sock, CH_ALL_STAT, strlen(CH_ALL_STAT), 0);
                  printf("GET ALL CH STATUS: %s", CH_ALL_STAT);
                  SCPI_UPDATED= false;
                  BB3_CONNECTED = false;
                  CH1_UPDATE = false;
                  CH2_UPDATE = false;
              }
            
            if (err < 0) {
                ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                  CH1_UPDATE = false;
                  CH2_UPDATE = false;
                break;
            }
            vTaskDelay(1 / portTICK_RATE_MS);
            int len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
            // Error occurred during receiving
            if (len < 0) {
                ESP_LOGE(TAG, "recv failed: errno %d", errno);
                SCPI_UPDATED = false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
               // break;
            }
            // Data received
            else {
                rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string
                sprintf(BB3_RESPONSE, rx_buffer);
                ESP_LOGI(TAG, "Received %d bytes from %s:", len, host_ip);
                ESP_LOGI(TAG, "%s", rx_buffer);
                parseCH_ALL_STAT();
                SCPI_UPDATED= false;
                BB3_CONNECTED = false;
                CH1_UPDATE = false;
                CH2_UPDATE = false;
                shutdown(sock, 0);
                close(sock);
                break;
            }
            //}
            vTaskDelay(100 / portTICK_RATE_MS);
        }
      }
        if (sock != -1) {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            CH1_UPDATE = false;
            CH2_UPDATE = false;
            BB3_CONNECTED = false;
            SCPI_UPDATED= false;
            shutdown(sock, 0);
            close(sock);
        }
            SCPI_UPDATED= false;
            CH1_UPDATE = false;
            CH2_UPDATE = false;
            BB3_CONNECTED = false;
            shutdown(sock, 0);
            close(sock);
    }
}
vTaskDelay(500 / portTICK_RATE_MS);
}
}


void OnConnected(void *para)
{
  while (true)
  {
    if (xSemaphoreTake(connectionSemaphore, 10000 / portTICK_RATE_MS))
    {
      ESP_LOGI(TAG, "connected");
      WIFI_CONNECTED = true;
      // do something
      tcpip_adapter_ip_info_t ip_info;
      ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info));
      printf("IP Addresss: %s\n", ip4addr_ntoa(&ip_info.ip));
      printf("Subnet Mask: %s\n", ip4addr_ntoa(&ip_info.netmask));
      printf("Gateway: %s\n", ip4addr_ntoa(&ip_info.ip));
      sprintf(WIFI_IP,ip4addr_ntoa(&ip_info.ip));
      printf("IP: %s\n", WIFI_IP);
      xSemaphoreTake(connectionSemaphore, portMAX_DELAY);
    }
    else
    {
      WIFI_CONNECTED = false;
      ESP_LOGE(TAG, "Failed to connect. Retry in");
      for (int i = 0; i < 10000; i++)
      {
        ESP_LOGE(TAG, "...%d", i);
        vTaskDelay(1000 / portTICK_RATE_MS);
      }
      esp_restart(); // si no hay conexion reiniciar el chip.
    }
  }
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
    esp_log_level_set(TAG, ESP_LOG_DEBUG);
    connectionSemaphore = xSemaphoreCreateBinary();
    wifiInit();
    xTaskCreate(&OnConnected, "handel comms", 1024 * 3, NULL, 5, NULL);
    xTaskCreate(&tcp_client_task, "tcp_client_task", 4096 * 2,NULL,2,NULL);
}