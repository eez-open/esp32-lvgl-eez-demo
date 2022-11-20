#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

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


extern char WIFI_SSID[50];
extern char WIFI_PASS[50];
extern char WIFI_IP[20];
extern char BB3_IP[20];
extern bool BB3_CONNECTED;
extern bool WIFI_CONNECTED;

#endif /*EEZ_LVGL_UI_VARS_H*/