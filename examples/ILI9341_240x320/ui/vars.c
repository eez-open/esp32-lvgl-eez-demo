#include "vars.h"

volatile char WIFI_SSID[50] = "W1_1047581318";
volatile char WIFI_PASS[50] = "";
volatile char WIFI_IP[20] = "";
volatile char BB3_IP[20] = "192.168.100.80";
volatile char BB3_RESPONSE[500] = "";
volatile bool BB3_CONNECTED = false;
volatile bool WIFI_CONNECTED = false;
volatile bool SCPI_UPDATED = false;
volatile bool CH1_UPDATE = false;
volatile bool CH1_POWER_ON = false;
volatile bool CH2_UPDATE = false;
volatile bool CH2_POWER_ON = false;

const char *get_var_wifi_ssid(){return WIFI_SSID;}
void set_var_wifi_ssid(const char *value){}
const char *get_var_wifi_pass(){return WIFI_PASS;}
void set_var_wifi_pass(const char *value){}
const char *get_var_wifi_ip(){return WIFI_IP;}
void set_var_wifi_ip(const char *value){}
bool get_var_wifi_connected(){return WIFI_CONNECTED;}
void set_var_wifi_connected(bool value){}
const char *get_var_bb3_ip(){return BB3_IP;}
void set_var_bb3_ip(const char *value){}
bool get_var_bb3_connected(){return BB3_CONNECTED;}
void set_var_bb3_connected(bool value){}
bool get_var_scpi_updated(){return SCPI_UPDATED;}
void set_var_scpi_updated(bool value){SCPI_UPDATED = value;printf("SCPI_UPDATE: %d\n", SCPI_UPDATED);}
bool get_var_ch1_update(){return CH1_UPDATE;}
void set_var_ch1_update(bool value){CH1_UPDATE = value;printf("CH1_UPDATE: %d\n", CH1_UPDATE);}
bool get_var_ch1_power_on(){return CH1_POWER_ON;}
void set_var_ch1_power_on(bool value){CH1_POWER_ON = value;printf("CH1_POWER_ON: %d\n", CH1_POWER_ON);}
bool get_var_ch2_update(){return CH2_UPDATE;}
void set_var_ch2_update(bool value){CH2_UPDATE = value;printf("CH2_UPDATE: %d\n", CH2_UPDATE);}
bool get_var_ch2_power_on(){return CH2_POWER_ON;}
void set_var_ch2_power_on(bool value){CH2_POWER_ON = value;printf("CH2_POWER_ON: %d\n", CH2_POWER_ON);}
const char *get_var_bb3_response(){return BB3_RESPONSE;}
void set_var_bb3_response(const char *value){}