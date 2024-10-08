# DEVKITPRO-NX-LVGL-EXAMPLE

Example usage LVGL v9.1 with SDL on Nintendo Switch


![example](https://raw.githubusercontent.com/JakubRybakowski/DEVKITPRO-NX-LVGL-EXAMPLE/main/example.png)


## BUILDING

https://gbatemp.net/threads/lvgl-v9-1-on-nintendo-switch.659093/post-10469274

## FORUM

https://gbatemp.net/threads/lvgl-v9-1-on-nintendo-switch.659093/

## SDL

Only SDL software works properly. SDL cached textures causes images not to load. This is an LVGL error. They're working on it.

## SDL acceleration

lv_conf.h:

/* Draw using cached SDL textures*/
#define LV_USE_DRAW_SDL 0

lv_sdl_window.c line 323:

dsc->renderer = SDL_CreateRenderer(dsc->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

## Disable keyboard on startup

comment lv_windows_sdl.c line 88:
//SDL_StartTextInput();

## Cached textures - not working well with SDL acceleration, not recommended anymore with SDL acceleration

lv_conf.h:
/* Draw using cached SDL textures*/
#define LV_USE_DRAW_SDL 1

edit lv_draw_sdl.c line 226:

case LV_DRAW_TASK_TYPE_IMAGE: {
    lv_draw_image_dsc_t image_dsc;
    lv_draw_image_dsc_init(&image_dsc);
    lv_memcpy(&image_dsc, task->draw_dsc, sizeof(image_dsc));
    image_dsc.base.user_data = lv_sdl_window_get_renderer(disp);
    lv_draw_image(&dest_layer, &image_dsc, &task->area);
    break;
}