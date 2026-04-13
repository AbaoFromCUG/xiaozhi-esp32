#ifndef ZHENGCHEN_EYE_MIRROR_DISPLAY_H
#define ZHENGCHEN_EYE_MIRROR_DISPLAY_H

#include "display/lcd_display.h"

class MirrorDisplay : public SpiLcdDisplay {
public:
    MirrorDisplay(esp_lcd_panel_io_handle_t io_handle, esp_lcd_panel_handle_t panel_handle,
                  int width, int height, int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                  bool swap_xy);

    void SetupUI() override;

private:
    lv_obj_t* overlay_container_ = nullptr;
};

#endif  // ZHENGCHEN_EYE_MIRROR_DISPLAY_H
