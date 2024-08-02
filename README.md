# DEVKITPRO-NX-LVGL-EXAMPLE

Example usage LVGL v9.1 with SDL on Nintendo Switch


![example](https://raw.githubusercontent.com/JakubRybakowski/DEVKITPRO-NX-LVGL-EXAMPLE/main/example.png)


## BUILDING

https://gbatemp.net/threads/lvgl-v9-1-on-nintendo-switch.659093/post-10469274

## FORUM

https://gbatemp.net/threads/lvgl-v9-1-on-nintendo-switch.659093/

## SDL

Only SDL software works properly. SDL acceleration causes images not to load. This is an LVGL error. They're working on it.


/* Draw using cached SDL textures*/

#define LV_USE_DRAW_SDL 1
