#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

extern const char *get_var_wifi_ssid();
extern void set_var_wifi_ssid(const char *value);
extern const char *get_var_wifi_pass();
extern void set_var_wifi_pass(const char *value);
extern const char *get_var_wifi_ip();
extern void set_var_wifi_ip(const char *value);
extern bool get_var_wifi_connected();
extern void set_var_wifi_connected(bool value);
extern const char *get_var_bb3_ip();
extern void set_var_bb3_ip(const char *value);
extern bool get_var_bb3_connected();
extern void set_var_bb3_connected(bool value);
extern bool get_var_scpi_updated();
extern void set_var_scpi_updated(bool value);
extern bool get_var_ch1_update();
extern void set_var_ch1_update(bool value);
extern bool get_var_ch1_power_on();
extern void set_var_ch1_power_on(bool value);
extern bool get_var_ch2_update();
extern void set_var_ch2_update(bool value);
extern bool get_var_ch2_power_on();
extern void set_var_ch2_power_on(bool value);
extern const char *get_var_bb3_response();
extern void set_var_bb3_response(const char *value);


extern volatile char WIFI_SSID[50];
extern volatile char WIFI_PASS[50];
extern volatile char WIFI_IP[20];
extern volatile char BB3_IP[20];
extern volatile bool BB3_CONNECTED;
extern volatile bool WIFI_CONNECTED;
extern volatile bool SCPI_UPDATED;
extern volatile bool CH1_UPDATE;
extern volatile bool CH1_POWER_ON;
extern volatile bool CH2_UPDATE;
extern volatile bool CH2_POWER_ON;
extern volatile char BB3_RESPONSE[];

#endif /*EEZ_LVGL_UI_VARS_H*/