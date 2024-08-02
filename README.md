# DEVKITPRO-NX-LVGL-EXAMPLE

Example usage LVGL v9.1 with SDL on Nintendo Switch


## SDL

Only SDL software works properly. SDL acceleration causes images not to load. This is an LVGL error. They're working on it.
/* Draw using cached SDL textures*/
#define LV_USE_DRAW_SDL 1