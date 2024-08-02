// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "../ui.h"

void ui_screen1_screen_init(void)
{
ui_screen1 = lv_obj_create(NULL);
lv_obj_remove_flag( ui_screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_screen1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_screen1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen1_panel_panelpopup = lv_obj_create(ui_screen1);
lv_obj_set_width( ui_screen1_panel_panelpopup, 442);
lv_obj_set_height( ui_screen1_panel_panelpopup, 163);
lv_obj_set_align( ui_screen1_panel_panelpopup, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_screen1_panel_panelpopup, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_screen1_label_label5 = lv_label_create(ui_screen1_panel_panelpopup);
lv_obj_set_width( ui_screen1_label_label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_screen1_label_label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_screen1_label_label5, 1 );
lv_obj_set_y( ui_screen1_label_label5, -38 );
lv_obj_set_align( ui_screen1_label_label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_screen1_label_label5,"Install application?");
lv_obj_set_style_text_font(ui_screen1_label_label5, &lv_font_montserrat_32, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen1_button_button1 = lv_button_create(ui_screen1_panel_panelpopup);
lv_obj_set_width( ui_screen1_button_button1, 100);
lv_obj_set_height( ui_screen1_button_button1, 50);
lv_obj_set_x( ui_screen1_button_button1, -120 );
lv_obj_set_y( ui_screen1_button_button1, 33 );
lv_obj_set_align( ui_screen1_button_button1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_screen1_button_button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_screen1_button_button1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_screen1_button_button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_screen1_button_button1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen1_label_label6 = lv_label_create(ui_screen1_button_button1);
lv_obj_set_width( ui_screen1_label_label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_screen1_label_label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_screen1_label_label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_screen1_label_label6,"YES");
lv_obj_set_style_text_color(ui_screen1_label_label6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_screen1_label_label6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_screen1_label_label6, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen1_button_button2 = lv_button_create(ui_screen1_panel_panelpopup);
lv_obj_set_width( ui_screen1_button_button2, 100);
lv_obj_set_height( ui_screen1_button_button2, 50);
lv_obj_set_x( ui_screen1_button_button2, 120 );
lv_obj_set_y( ui_screen1_button_button2, 33 );
lv_obj_set_align( ui_screen1_button_button2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_screen1_button_button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_screen1_button_button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_screen1_button_button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_screen1_button_button2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen1_label_label7 = lv_label_create(ui_screen1_button_button2);
lv_obj_set_width( ui_screen1_label_label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_screen1_label_label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_screen1_label_label7, LV_ALIGN_CENTER );
lv_label_set_text(ui_screen1_label_label7,"NO");
lv_obj_set_style_text_color(ui_screen1_label_label7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_screen1_label_label7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_screen1_label_label7, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_screen1_button_button1, ui_event_screen1_button_button1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_screen1_button_button2, ui_event_screen1_button_button2, LV_EVENT_ALL, NULL);

}
