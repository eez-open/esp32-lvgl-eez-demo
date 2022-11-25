#include "vars.h"

char WIFI_SSID[50] = "W1_1047581318";
char WIFI_PASS[50] = "SunceMojeMalo";
char WIFI_IP[20] = "";
char BB3_IP[20] = "192.168.100.80";
char BB3_RESPONSE[500] = "";
char CH1_V[10] = "0.0000";
char CH1_A[10] = "0.0000";
char CH2_V[10] = "0.0000";
char CH2_A[10] = "0.0000";
bool BB3_CONNECTED = false;
bool WIFI_CONNECTED = false;
bool SCPI_UPDATED = false;
bool CH1_UPDATE = false;
bool CH1_POWER_ON = false;
bool CH2_UPDATE = false;
bool CH2_POWER_ON = false;

const char *get_var_wifi_ssid(){return WIFI_SSID;}
void set_var_wifi_ssid(const char *value){sprintf(WIFI_SSID,value);}
const char *get_var_wifi_pass(){return WIFI_PASS;}
void set_var_wifi_pass(const char *value){sprintf(WIFI_PASS,value);}
const char *get_var_wifi_ip(){return WIFI_IP;}
void set_var_wifi_ip(const char *value){}
bool get_var_wifi_connected(){return WIFI_CONNECTED;}
void set_var_wifi_connected(bool value){}
const char *get_var_bb3_ip(){return BB3_IP;}
void set_var_bb3_ip(const char *value){sprintf(BB3_IP,value);}
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
const char *get_var_ch1_v(){return CH1_V;}
void set_var_ch1_v(const char *value){sprintf(CH1_V,value);}
const char *get_var_ch1_a(){return CH1_A;}
void set_var_ch1_a(const char *value){sprintf(CH1_A,value);}
const char *get_var_ch2_v(){return CH2_V;}
void set_var_ch2_v(const char *value){sprintf(CH2_V,value);}
const char *get_var_ch2_a(){return CH2_A;}
void set_var_ch2_a(const char *value){sprintf(CH2_A,value);}