#include "mirror_display.h"

MirrorDisplay::MirrorDisplay(esp_lcd_panel_io_handle_t io_handle,
                             esp_lcd_panel_handle_t panel_handle, int width, int height,
                             int offset_x, int offset_y, bool mirror_x, bool mirror_y, bool swap_xy)
    : SpiLcdDisplay(io_handle, panel_handle, width, height, offset_x, offset_y, mirror_x, mirror_y,
                    swap_xy) {}

void MirrorDisplay::SetupUI() {
    SpiLcdDisplay::SetupUI();

    DisplayLockGuard lock(this);

    auto hide_if_exists = [](lv_obj_t* obj) {
        if (obj != nullptr) {
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    };
    auto screen = lv_screen_active();

    overlay_container_ = lv_obj_create(screen);
    lv_obj_remove_style_all(overlay_container_);
    lv_obj_set_size(overlay_container_, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(overlay_container_, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(overlay_container_, LV_OPA_COVER, 0);
    lv_obj_align(overlay_container_, LV_ALIGN_CENTER, 0, 0);

    if (emoji_image_ != nullptr) {
        lv_obj_set_parent(emoji_image_, overlay_container_);
        lv_obj_set_size(emoji_image_, LV_HOR_RES, LV_VER_RES);
        lv_obj_align(emoji_image_, LV_ALIGN_CENTER, 0, 0);
    }

    hide_if_exists(top_bar_);
    hide_if_exists(status_bar_);
    hide_if_exists(side_bar_);
    hide_if_exists(bottom_bar_);
    hide_if_exists(content_);
    hide_if_exists(preview_image_);
    hide_if_exists(emoji_label_);
    hide_if_exists(emoji_box_);
    hide_if_exists(chat_message_label_);
}
