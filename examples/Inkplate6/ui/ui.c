#include "ui.h"
#include "screens.h"
#include "images.h"
#include "flow_def.h"
#include "actions.h"

ActionExecFunc actions[] = {
    0
};


void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick() {
    eez_flow_tick();
    tick_screen(g_currentScreen);
}
