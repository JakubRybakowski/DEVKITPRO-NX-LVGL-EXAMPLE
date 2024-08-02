// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_main
void ui_main_screen_init(void);
lv_obj_t *ui_main;
lv_obj_t *ui_main_panel_bottomline;
lv_obj_t *ui_main_label_label1;
lv_obj_t *ui_main_image_image4;
lv_obj_t *ui_main_image_image1;
lv_obj_t *ui_main_label_label2;
lv_obj_t *ui_main_label_label3;
lv_obj_t *ui_main_panel_panel1;
lv_obj_t *ui_main_image_image3;
lv_obj_t *ui_main_image_image5;
lv_obj_t *ui_main_image_image6;
lv_obj_t *ui_main_image_image7;
lv_obj_t *ui_main_image_image8;
lv_obj_t *ui_main_image_image9;
lv_obj_t *ui_main_image_image10;
lv_obj_t *ui_main_image_image11;
lv_obj_t *ui_main_image_image2;
lv_obj_t *ui_main_image_image12;
lv_obj_t *ui_main_image_image13;
lv_obj_t *ui_main_image_image14;
lv_obj_t *ui_main_image_image15;
lv_obj_t *ui_main_image_image16;
lv_obj_t *ui_main_image_image17;
lv_obj_t *ui_main_image_image18;
lv_obj_t *ui_main_container_container1;
lv_obj_t *ui_startevents____initial_actions0;
const lv_image_dsc_t *ui_imgset_0e1e5aed207066f1b8acb2c7d2ae52bd8707615c58e4065bc5d8477ce[1] = {&ui_img_30e1e5aed207066f1b8acb2c7d2a3e532b3d8707615c58e40635bc5d84377ce3_png};
const lv_image_dsc_t *ui_imgset_399bd3a4f656457bb63e921378eb701908298c8f2b2ad3193c437c206da[1] = {&ui_img_399bd3a4f656457bb63e921378eb701908298c8f2b2ad3193c437c206da97681_png};
const lv_image_dsc_t *ui_imgset_3c3011e367e82258bbd36283bfe89d7292e6f44792bda005da3b964cd[1] = {&ui_img_3c3011e367e82258bbd36283bfe89d7292e6f44792bda005da3b964cd6388013_png};
const lv_image_dsc_t *ui_imgset_628f3436b87a02061bf9014ee7949fc379564c75364e66dca290fb1e54e9c[1] = {&ui_img_628f3436b87a02061bf9014ee7949fc379564c75364e66dca290fb1e54e9c095_png};
const lv_image_dsc_t *ui_imgset_66b63f88213ebf50af4aeaca2da8c64a24a7314a0c80d587fec466df74d8b[1] = {&ui_img_66b639f88213ebf50af4a9eaca2da8c64a24a7314a0c80d587fec466df74d8b9_png};
const lv_image_dsc_t *ui_imgset_7f4d41bf9dbc8f7379e2f7530b8e969220dfdc9336ec8eaab7085267533a[1] = {&ui_img_7f4d41bf9dbc8f7379e2f7530b8e969220dfdc933506ec8eaab7085267533a50_png};
const lv_image_dsc_t *ui_imgset_9743b1bb18f8b7e40947a037557131be402985046b4e57f7c2c4796abe024b[1] = {&ui_img_9743b1bb18f8b7e40947a037557131be402985046b4e57f7c2c4796abe024b30_png};
const lv_image_dsc_t *ui_imgset_ad4d31f4a1ce704f0219da2805f8459595bc3c01c3f04df2e32ba34a05b8c[1] = {&ui_img_ad4d31f664a1ce704f0219da2805f8459595bc3c01c3f04df2e32ba34a05b8c6_png};
const lv_image_dsc_t *ui_imgset_aeab72bcb6fb6c79c32bddec987764f6e47c3e9cd32642a84de75f631b4eed[1] = {&ui_img_aeab72bcb6fb6c79c32bddec987764f6e47c3e90cd32642a84de75f631b4eed0_png};
const lv_image_dsc_t *ui_imgset_bfeb5333a4473854d4cba8332d64152d595879c3714e687b45c47ad33b234a[1] = {&ui_img_bfeb5333a4473854d4cba8332d64152d595879c3714e687b45c47ad33b234a08_png};
const lv_image_dsc_t *ui_imgset_d3c210e61e8487200fc4c344987243a60257838187a69a6a81c42d7447d5d[1] = {&ui_img_d3c210e61e8487200fc4c344987243a60257838187a69a6a81c42d7447d5d192_png};
const lv_image_dsc_t *ui_imgset_f9dc003e469d3986eb0f7b6d9769ef0194608d530ac94683886eca3b[1] = {&ui_img_f9dc003e469d3986eb0f7b6d972629ef201946028d530ac946823886e22ca3b2_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_display_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_main_screen_init();
ui_startevents____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_main);
}