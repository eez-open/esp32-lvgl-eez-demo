#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main_page;
    lv_obj_t *ch_voltage;
    lv_obj_t *ch_on_off_page;
    lv_obj_t *setup_wifi;
    lv_obj_t *setup_bb3;
    lv_obj_t *txt_ch2_i;
    lv_obj_t *txt_ch1_i;
    lv_obj_t *txt_ch1_v;
    lv_obj_t *txt_ch2_v;
    lv_obj_t *lbl_conn_status;
    lv_obj_t *txt_ssid;
    lv_obj_t *txt_pass;
    lv_obj_t *kbd_setup_wifi;
    lv_obj_t *lbl_conn_status_1;
    lv_obj_t *txt_bb3_ip;
    lv_obj_t *kbd_setup_bb3;
    lv_obj_t *keyboard_1;
    lv_obj_t *label_1;
    lv_obj_t *button_11;
    lv_obj_t *label_2;
} objects_t;

extern objects_t objects;

void create_screen_main_page();
void tick_screen_main_page();

void create_screen_ch_voltage();
void tick_screen_ch_voltage();

void create_screen_ch_on_off_page();
void tick_screen_ch_on_off_page();

void create_screen_setup_wifi();
void tick_screen_setup_wifi();

void create_screen_setup_bb3();
void tick_screen_setup_bb3();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/