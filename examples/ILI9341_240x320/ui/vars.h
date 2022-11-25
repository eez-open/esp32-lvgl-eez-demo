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
extern const char *get_var_ch1_v();
extern void set_var_ch1_v(const char *value);
extern const char *get_var_ch1_a();
extern void set_var_ch1_a(const char *value);
extern const char *get_var_ch2_v();
extern void set_var_ch2_v(const char *value);
extern const char *get_var_ch2_a();
extern void set_var_ch2_a(const char *value);


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
extern char CH1_V[];
extern char CH1_A[];
extern char CH2_V[];
extern char CH2_A[];

#endif /*EEZ_LVGL_UI_VARS_H*/