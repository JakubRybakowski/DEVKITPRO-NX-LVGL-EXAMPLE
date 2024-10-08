#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>
#include <SDL2/SDL.h>
#include <lvgl/lvgl.h>
#include <ui/ui.h>
#include <lvgl/demos/lv_demos.h>


/*
lv_windows_sdl
//SDL_StartTextInput();

lv_draw_sdl
case LV_DRAW_TASK_TYPE_IMAGE: {
lv_draw_image_dsc_t image_dsc;
lv_draw_image_dsc_init(&image_dsc);
lv_memcpy(&image_dsc, task->draw_dsc, sizeof(image_dsc));
image_dsc.base.user_data = lv_sdl_window_get_renderer(disp);
lv_draw_image(&dest_layer, &image_dsc, &task->area);
break;
}
*/


#define MY_DISP_HOR_RES 1280
#define MY_DISP_VER_RES 720
#define BYTE_PER_PIXEL 32

static SDL_Thread* tick_thread;
lv_display_t * disp;
SDL_Event event;

bool running = true;

void read_pointer_cb(lv_indev_t *indev, lv_indev_data_t *data) {
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

void read_keypad_cb(lv_indev_t *indev, lv_indev_data_t *data) {
    (void) indev;

}

static int tick_handler(void *data) {
    while (appletMainLoop() && running) {
        SDL_Delay(1);
        lv_tick_inc(1);
    }
    return 0;
}

static void lvgl_init(void) {
    lv_init();

    disp = lv_sdl_window_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    static uint8_t buf1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    static uint8_t buf2[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    lv_display_set_buffers(disp, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_DIRECT);

    lv_indev_t * indev_pointer = lv_indev_create();
    lv_indev_set_type(indev_pointer, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev_pointer, read_pointer_cb);

    lv_indev_t * indev_keypad = lv_indev_create();
    lv_indev_set_type(indev_keypad, LV_INDEV_TYPE_KEYPAD);
    lv_indev_set_read_cb(indev_keypad, read_keypad_cb);

    lv_demo_benchmark();
    //lv_demo_stress();
    //ui_init();

    SDL_Init(SDL_INIT_JOYSTICK);
    for (int i = 0; i < 2; i++) {
        if (SDL_JoystickOpen(i) == NULL) {
            SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
        }
    }

    tick_thread = SDL_CreateThread(tick_handler, "tick", NULL);
}

void mainLoop() {
    if(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_JOYAXISMOTION:
                SDL_Log("Joystick %d axis %d value: %d\n", event.jaxis.which, event.jaxis.axis, event.jaxis.value);
                break;

            case SDL_JOYBUTTONDOWN:
                SDL_Log("Joystick %d button %d down\n", event.jbutton.which, event.jbutton.button);
                if (event.jbutton.which == 0) {
                    if (event.jbutton.button == 1) {
                        lv_obj_set_parent(ui_main_panel_panelpopup, ui_main);
                        lv_obj_clear_flag(ui_main_panel_panelpopup, LV_OBJ_FLAG_HIDDEN);
                    } else if (event.jbutton.button == 10) {
                        running = false;
                        //appletExit();
                    }
                }
                break;

            default:
                break;
        }
    }
}

static void quitApp() {
    SDL_WaitThread(tick_thread, NULL);
    lv_display_delete(disp);
    lv_sdl_quit();
    //romfsExit();
    socketExit();
    appletUnlockExit();
}

int main(int argc, char *argv[]) {
    socketInitializeDefault();
	nxlinkStdio();

    //romfsInit();

    lvgl_init();

    /*
    Handle type	SystemInfoType	SystemInfoSubType	Description
    Zero	0	0	TotalPhysicalMemorySize_Application
    Zero	0	1	TotalPhysicalMemorySize_Applet
    Zero	0	2	TotalPhysicalMemorySize_System
    Zero	0	3	TotalPhysicalMemorySize_SystemUnsafe
    Zero	1	0	UsedPhysicalMemorySize_Application
    Zero	1	1	UsedPhysicalMemorySize_Applet
    Zero	1	2	UsedPhysicalMemorySize_System
    Zero	1	3	UsedPhysicalMemorySize_SystemUnsafe
    Zero	2	0	InitialProcessIdRange_LowerBound
    Zero	2	1	InitialProcessIdRange_UpperBound
    */

    uint64_t total_memory = 0;
    Result rc;

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 0, INVALID_HANDLE, 0));
    if (rc) {
        printf("TotalPhysicalMemorySize_Application: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 0, INVALID_HANDLE, 1));
    if (rc) {
        printf("TotalPhysicalMemorySize_Applet: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }
    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 0, INVALID_HANDLE, 2));
    if (rc) {
        printf("TotalPhysicalMemorySize_System: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 0, INVALID_HANDLE, 3));
    if (rc) {
         printf("TotalPhysicalMemorySize_SystemUnsafe: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 1, INVALID_HANDLE, 0));
    if (rc) {
        printf("UsedPhysicalMemorySize_Application: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 1, INVALID_HANDLE, 1));
    if (rc) {
        printf("UsedPhysicalMemorySize_Applet: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 1, INVALID_HANDLE, 2));
    if (rc) {
        printf("UsedPhysicalMemorySize_System: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    rc = R_SUCCEEDED(svcGetSystemInfo(&total_memory, 1, INVALID_HANDLE, 3));
    if (rc) {
        printf("UsedPhysicalMemorySize_SystemUnsafe: %lu MB\n", total_memory / (1024 * 1024));
    } else {
        printf("Nie udało się pobrać pamięci: 0x%X\n", rc);
    }

    while (appletMainLoop() && running) {
        mainLoop();
        lv_timer_handler();
    }

    quitApp();

    return 0;
}

