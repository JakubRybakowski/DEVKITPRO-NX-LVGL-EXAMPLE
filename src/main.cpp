#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>
#include <SDL2/SDL.h>
#include <lvgl/lvgl.h>
#include <lvgl/src/draw/sdl/lv_draw_sdl.h>
#include <lvgl/src/drivers/sdl/lv_sdl_window.h>
#include <ui/ui.h>


#define MY_DISP_HOR_RES 1280
#define MY_DISP_VER_RES 720
#define BYTE_PER_PIXEL 32

static SDL_Thread* tick_thread;
lv_display_t * disp;
bool mainLopp = true;

void read_cb(lv_indev_t *indev, lv_indev_data_t *data) {
    (void) indev;

    HidTouchScreenState state = {0};

    int16_t last_x = 0;
    int16_t last_y = 0;
    bool touch_down = false;

    if (hidGetTouchScreenStates(&state, 1)) {
        for (s32 i = 0; i < state.count; i++) {
            touch_down = true;
            last_x = state.touches[i].x;
            last_y = state.touches[i].y;
        }
    }

    data->point.x = last_x;
    data->point.y = last_y;
    data->state = touch_down ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}

static int tick_handler(void *data) {
    while (mainLopp) {
        SDL_Delay(5);
        lv_tick_inc(5);
    }
    return 0;
}

void my_log_cb(lv_log_level_t level, const char * buf)
{
  printf(buf);
}

static void lvgl_init(void) {
    lv_log_register_print_cb(my_log_cb);

    lv_init();
    SDL_Init(SDL_INIT_JOYSTICK);
    disp = lv_sdl_window_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    static uint8_t buf1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    static uint8_t buf2[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    lv_display_set_buffers(disp, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_DIRECT);
    lv_display_set_default(disp);

    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, read_cb);

    tick_thread = SDL_CreateThread(tick_handler, "tick", NULL);

    ui_init();
}

void mainLoop() {
    SDL_Event event;
    
    while (appletMainLoop() && mainLopp) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_JOYAXISMOTION:
                    SDL_Log("Joystick %d axis %d value: %d\n",
                            event.jaxis.which,
                            event.jaxis.axis, event.jaxis.value);
                    break;

                case SDL_JOYBUTTONDOWN:
                    SDL_Log("Joystick %d button %d down\n", event.jbutton.which, event.jbutton.button);
                    if (event.jbutton.which == 0) {
                        if (event.jbutton.button == 1) {
                            lv_obj_set_parent(ui_screen1_panel_panelpopup, ui_main);
                            lv_obj_clear_flag(ui_screen1_panel_panelpopup, LV_OBJ_FLAG_HIDDEN);
                        } else if (event.jbutton.button == 10) {
                            mainLopp = false;
                        }
                    }
                    break;

                default:
                    break;
            }
        }

        lv_timer_handler();
    }
}

static void quitApp() {
    SDL_WaitThread(tick_thread, NULL);
    lv_display_delete(disp);
    lv_sdl_quit();
    //romfsExit();
    socketExit();
}

int main(int argc, char *argv[]) {
    socketInitializeDefault();
	nxlinkStdio();

    //romfsInit();

    printf("Hello World!\n");

    lvgl_init();


    for (int i = 0; i < 2; i++) {
        if (SDL_JoystickOpen(i) == NULL) {
            SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
            //quit();
            //return -1;
        }
    }

    mainLoop();

    quitApp();

    return 0;
}

