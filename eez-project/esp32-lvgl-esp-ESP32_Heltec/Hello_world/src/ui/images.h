#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include "lvgl/lvgl.h"


typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;

extern const ext_img_desc_t images[0];


#endif /*EEZ_LVGL_UI_IMAGES_H*/