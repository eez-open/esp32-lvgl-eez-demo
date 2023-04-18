#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_page__obj_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_main_page__obj_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 4, 1);
    }
}

static void event_handler_cb_main_page__obj_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 12, 1);
    }
}

static void event_handler_cb_ch_voltage__obj_button_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_ch_voltage_txt_ch2_i(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 4, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 4, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 4, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_ch_voltage_txt_ch1_i(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 7, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 7, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 7, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_ch_voltage_txt_ch1_v(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 10, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 10, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 10, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_ch_voltage__obj_button_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 11, 1);
    }
}

static void event_handler_cb_ch_voltage__obj_button_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 13, 1);
    }
}

static void event_handler_cb_ch_voltage_txt_ch2_v(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 15, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 15, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 15, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_ch_voltage_kbd_setup_voltage(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CANCEL) {
        flowPropagateValue(flowState, 16, 1);
    }
}

static void event_handler_cb_ch_on_off_page__obj_button_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_ch_on_off_page__obj_button_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 4, 1);
    }
}

static void event_handler_cb_ch_on_off_page__obj_button_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 10, 1);
    }
}

static void event_handler_cb_ch_on_off_page__obj_button_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 12, 1);
    }
}

static void event_handler_cb_setup_wifi__obj_button_12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 3, 1);
    }
}

static void event_handler_cb_setup_wifi_txt_ssid(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 7, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 7, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 7, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_setup_wifi_txt_pass(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 8, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 8, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 8, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_setup_wifi__obj_button_13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 9, 1);
    }
}

static void event_handler_cb_setup_bb3_txt_bb3_ip(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_FOCUSED) {
        flowPropagateValue(flowState, 4, 1);
    }
    if (event == LV_EVENT_DEFOCUSED) {
        flowPropagateValue(flowState, 4, 2);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        const char *value = lv_textarea_get_text(ta);
        if (tick_value_change_obj != ta) {
            assignStringProperty(flowState, 4, 2, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_setup_bb3__obj_button_14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 5, 1);
    }
}

void create_screen_main_page() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdc8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
                    objects._obj_spinner_0 = obj;
                    lv_obj_set_pos(obj, 170, 170);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_set_style_arc_opa(obj, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff680d9a), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff8d2ba5), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_1 = obj;
                    lv_obj_set_pos(obj, 93, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_page__obj_button_1, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -2, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Setup BB3");
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_2 = obj;
                    lv_obj_set_pos(obj, -11, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_page__obj_button_2, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -2, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Setup WIFI");
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 1, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EEZ Studio LVGL GUI builder");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 33, 20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Flow support enabled");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 100, 54);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LVGL: 8.3");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 65, 76);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Platform: ESP32");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 76, 94);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ESP IDF: 4.4.3");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 48, 124);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WIFI BB3 controller");
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_semi_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_3 = obj;
                    lv_obj_set_pos(obj, 200, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_page__obj_button_3, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 8, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Set CH");
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_main_page() {
    void *flowState = getFlowState(0, 0);
    {
        bool new_val = evalBooleanProperty(flowState, 0, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_spinner_0, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_spinner_0;
            if (new_val) lv_obj_add_flag(objects._obj_spinner_0, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_spinner_0, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 2, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_button_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_button_1;
            if (new_val) lv_obj_add_flag(objects._obj_button_1, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_button_1, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_button_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_button_3;
            if (new_val) lv_obj_add_flag(objects._obj_button_3, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_button_3, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_ch_voltage() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.ch_voltage = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdc8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_4 = obj;
                    lv_obj_set_pos(obj, 95, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage__obj_button_4, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 22, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "GET");
                        }
                    }
                }
                {
                    // txt_ch2_i
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ch2_i = obj;
                    lv_obj_set_pos(obj, 89, 115);
                    lv_obj_set_size(obj, 200, 40);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage_txt_ch2_i, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -3, 127);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CH2 current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -3, 45);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CH1 current");
                }
                {
                    // txt_ch1_i
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ch1_i = obj;
                    lv_obj_set_pos(obj, 89, 33);
                    lv_obj_set_size(obj, 200, 40);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage_txt_ch1_i, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -3, 86);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CH2 voltage");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -3, 4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CH1 voltage");
                }
                {
                    // txt_ch1_v
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ch1_v = obj;
                    lv_obj_set_pos(obj, 89, -8);
                    lv_obj_set_size(obj, 200, 40);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage_txt_ch1_v, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_5 = obj;
                    lv_obj_set_pos(obj, 200, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage__obj_button_5, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 22, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "SET");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_6 = obj;
                    lv_obj_set_pos(obj, -11, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage__obj_button_6, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 17, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Back");
                        }
                    }
                }
                {
                    // txt_ch2_v
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ch2_v = obj;
                    lv_obj_set_pos(obj, 89, 74);
                    lv_obj_set_size(obj, 200, 40);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage_txt_ch2_v, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // kbd_setupVoltage
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    objects.kbd_setup_voltage = obj;
                    lv_obj_set_pos(obj, -3, -8);
                    lv_obj_set_size(obj, 301, 177);
                    lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_voltage_kbd_setup_voltage, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 6, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 40, LV_PART_ITEMS | LV_STATE_DEFAULT);
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.kbd_setup_voltage, objects.txt_ch1_v);
}

void tick_screen_ch_voltage() {
    void *flowState = getFlowState(0, 1);
    {
        const char *new_val = evalTextProperty(flowState, 4, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_ch2_i);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_ch2_i;
            lv_textarea_set_text(objects.txt_ch2_i, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_ch1_i);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_ch1_i;
            lv_textarea_set_text(objects.txt_ch1_i, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_ch1_v);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_ch1_v;
            lv_textarea_set_text(objects.txt_ch1_v, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_ch2_v);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_ch2_v;
            lv_textarea_set_text(objects.txt_ch2_v, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_ch_on_off_page() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.ch_on_off_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdc8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_7 = obj;
                    lv_obj_set_pos(obj, 21, 9);
                    lv_obj_set_size(obj, 111, 60);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_on_off_page__obj_button_7, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_CHECKABLE);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0a74e9), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff10539b), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_CHECKED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // lbl_CH1_STATUS
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_ch1_status = obj;
                            lv_obj_set_pos(obj, 15, 12);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "CH1 ON");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_8 = obj;
                    lv_obj_set_pos(obj, 158, 9);
                    lv_obj_set_size(obj, 111, 60);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_on_off_page__obj_button_8, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_CHECKABLE);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0a74e9), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff10539b), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_CHECKED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // lbl_CH2_STATUS
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_ch2_status = obj;
                            lv_obj_set_pos(obj, 13, 12);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "CH2 ON");
                        }
                    }
                }
                {
                    // lbl_CH1_V
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_ch1_v = obj;
                    lv_obj_set_pos(obj, 71, 107);
                    lv_obj_set_size(obj, 81, 16);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl_CH1_A
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_ch1_a = obj;
                    lv_obj_set_pos(obj, 71, 132);
                    lv_obj_set_size(obj, 79, 16);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl_CH2_V
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_ch2_v = obj;
                    lv_obj_set_pos(obj, 210, 109);
                    lv_obj_set_size(obj, 90, 16);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl_CH2_A
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_ch2_a = obj;
                    lv_obj_set_pos(obj, 210, 132);
                    lv_obj_set_size(obj, 90, 16);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_9 = obj;
                    lv_obj_set_pos(obj, -11, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_on_off_page__obj_button_9, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 17, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Back");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_10 = obj;
                    lv_obj_set_pos(obj, 200, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_ch_on_off_page__obj_button_10, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -2, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Set values");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects._obj_label_11 = obj;
                    lv_obj_set_pos(obj, 131, 128);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 36, 127);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "BB3 response:");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 28, 122);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Voltage:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 167, 124);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Voltage:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 26, 147);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Current:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 165, 147);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Current:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 54, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "CH1 Status");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 190, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "CH2 Status");
        }
    }
}

void tick_screen_ch_on_off_page() {
    void *flowState = getFlowState(0, 2);
    {
        const char *new_val = evalTextProperty(flowState, 6, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_ch1_v);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_ch1_v;
            lv_label_set_text(objects.lbl_ch1_v, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_ch1_a);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_ch1_a;
            lv_label_set_text(objects.lbl_ch1_a, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_ch2_v);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_ch2_v;
            lv_label_set_text(objects.lbl_ch2_v, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_ch2_a);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_ch2_a;
            lv_label_set_text(objects.lbl_ch2_a, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_11;
            lv_label_set_text(objects._obj_label_11, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_setup_wifi() {
    void *flowState = getFlowState(0, 3);
    lv_obj_t *obj = lv_obj_create(0);
    objects.setup_wifi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdc8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_conn_status
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_conn_status = obj;
                    lv_obj_set_pos(obj, 78, 45);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_12 = obj;
                    lv_obj_set_pos(obj, 201, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_wifi__obj_button_12, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -4, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Reconnect");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -10, -4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SSID:");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -10, 22);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Password:");
                }
                {
                    // txt_ssid
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ssid = obj;
                    lv_obj_set_pos(obj, 76, -8);
                    lv_obj_set_size(obj, 225, 24);
                    lv_textarea_set_max_length(obj, 50);
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_wifi_txt_ssid, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_pass
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_pass = obj;
                    lv_obj_set_pos(obj, 76, 18);
                    lv_obj_set_size(obj, 225, 24);
                    lv_textarea_set_max_length(obj, 50);
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, true);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_wifi_txt_pass, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_13 = obj;
                    lv_obj_set_pos(obj, -11, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_wifi__obj_button_13, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 17, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Back");
                        }
                    }
                }
                {
                    // kbd_setupWifi
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    objects.kbd_setup_wifi = obj;
                    lv_obj_set_pos(obj, -5, 45);
                    lv_obj_set_size(obj, 300, 120);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 6, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 40, LV_PART_ITEMS | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -10, 46);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Current IP: ");
                }
                {
                    // lbl_conn_status (1)
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_conn_status_1 = obj;
                    lv_obj_set_pos(obj, 78, 65);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -10, 65);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Status:");
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.kbd_setup_wifi, objects.txt_pass);
}

void tick_screen_setup_wifi() {
    void *flowState = getFlowState(0, 3);
    {
        const char *new_val = evalTextProperty(flowState, 2, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_conn_status);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_conn_status;
            lv_label_set_text(objects.lbl_conn_status, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 3, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_button_12, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_button_12;
            if (new_val) lv_obj_add_flag(objects._obj_button_12, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_button_12, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_ssid);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_ssid;
            lv_textarea_set_text(objects.txt_ssid, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_pass);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_pass;
            lv_textarea_set_text(objects.txt_pass, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lbl_conn_status_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lbl_conn_status_1;
            lv_label_set_text(objects.lbl_conn_status_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_setup_bb3() {
    void *flowState = getFlowState(0, 4);
    lv_obj_t *obj = lv_obj_create(0);
    objects.setup_bb3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdc8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -5, 21);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Connected:");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -5, -4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "BB3 IP:");
                }
                {
                    // txt_bb3_ip
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_bb3_ip = obj;
                    lv_obj_set_pos(obj, 70, -8);
                    lv_obj_set_size(obj, 225, 24);
                    lv_textarea_set_max_length(obj, 15);
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_bb3_txt_bb3_ip, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects._obj_button_14 = obj;
                    lv_obj_set_pos(obj, -11, 170);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_bb3__obj_button_14, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 17, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Back");
                        }
                    }
                }
                {
                    // kbd_setupBB3
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    objects.kbd_setup_bb3 = obj;
                    lv_obj_set_pos(obj, -5, 45);
                    lv_obj_set_size(obj, 300, 120);
                    lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 6, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 40, LV_PART_ITEMS | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects._obj_label_15 = obj;
                    lv_obj_set_pos(obj, 111, 21);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 200, 171);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd321f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff9e00ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 14, 7);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Set IP");
                        }
                    }
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.kbd_setup_bb3, objects.txt_bb3_ip);
}

void tick_screen_setup_bb3() {
    void *flowState = getFlowState(0, 4);
    {
        const char *new_val = evalTextProperty(flowState, 4, 2, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.txt_bb3_ip);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.txt_bb3_ip;
            lv_textarea_set_text(objects.txt_bb3_ip, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_15;
            lv_label_set_text(objects._obj_label_15, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main_page();
    create_screen_ch_voltage();
    create_screen_ch_on_off_page();
    create_screen_setup_wifi();
    create_screen_setup_bb3();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main_page,
    tick_screen_ch_voltage,
    tick_screen_ch_on_off_page,
    tick_screen_setup_wifi,
    tick_screen_setup_bb3,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
