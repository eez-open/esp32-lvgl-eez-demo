#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 600);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 600);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -80, -80);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 211, 229);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ESP IDF: 4.4.3");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 250, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LVGL: 8.3");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 106, 75);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "with flow support enabled");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 72, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "eez-open/esp32-lvgl-eez-demo");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 194, 194);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Platform: ESP32");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 90, 40);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "EEZ Studio LVGL GUI builder");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 166, 282);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Inkplate (Soldered)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
}

void create_screen_page1() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.page1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 600);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 600);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -80, -80);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -30, -30);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 261, 271);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ESP IDF: 4.4.3");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 300, 201);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LVGL: 8.3");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 156, 117);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "with flow support enabled");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 122, 425);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "eez-open/esp32-lvgl-eez-demo");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 244, 236);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Platform: ESP32");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 140, 82);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "EEZ Studio LVGL GUI builder");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 216, 324);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Inkplate (Soldered)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_page1() {
    void *flowState = getFlowState(0, 1);
}

void create_screen_page2() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.page2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 600);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 600);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -80, -80);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -30, -30);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 20, 20);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 288, 297);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ESP IDF: 4.4.3");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 327, 227);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LVGL: 8.3");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 183, 143);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "with flow support enabled");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 149, 451);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "eez-open/esp32-lvgl-eez-demo");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 271, 262);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Platform: ESP32");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 167, 108);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EEZ Studio LVGL GUI builder");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 243, 350);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Inkplate (Soldered)");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_page2() {
    void *flowState = getFlowState(0, 2);
}

void create_screen_page3() {
    void *flowState = getFlowState(0, 3);
    lv_obj_t *obj = lv_obj_create(0);
    objects.page3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 600);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 600);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -80, -80);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, -30, -30);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 20, 20);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 70, 75);
                    lv_obj_set_size(obj, 640, 440);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 337, 344);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ESP IDF: 4.4.3");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 376, 274);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LVGL: 8.3");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 232, 190);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "with flow support enabled");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 320, 309);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Platform: ESP32");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 216, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EEZ Studio LVGL GUI builder");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 292, 397);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Inkplate (Soldered)");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 198, 501);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "eez-open/esp32-lvgl-eez-demo");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_page3() {
    void *flowState = getFlowState(0, 3);
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_page1();
    create_screen_page2();
    create_screen_page3();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_page1,
    tick_screen_page2,
    tick_screen_page3,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
