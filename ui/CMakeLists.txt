SET(SOURCES screens/ui_main.c
    screens/ui_screen1.c
    screens/ui_screen2.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_30e1e5aed207066f1b8acb2c7d2a3e532b3d8707615c58e40635bc5d84377ce3_png.c
    images/ui_img_29c1ff1b697b468082d43540425fca8f538865a8d1f876de46ae5490203b6c2e_png.c
    images/ui_img_399bd3a4f656457bb63e921378eb701908298c8f2b2ad3193c437c206da97681_png.c
    images/ui_img_3c3011e367e82258bbd36283bfe89d7292e6f44792bda005da3b964cd6388013_png.c
    images/ui_img_4b53da7ca4b118fe37c8b8040609b84dc63214d6131c51592486de9bf29ef29c_png.c
    images/ui_img_4ffe57aabf1b6a2bf19cab0139a8bb4f99d14ef2f0031f83acd0f28810f66dbf_png.c
    images/ui_img_628f3436b87a02061bf9014ee7949fc379564c75364e66dca290fb1e54e9c095_png.c
    images/ui_img_66b639f88213ebf50af4a9eaca2da8c64a24a7314a0c80d587fec466df74d8b9_png.c
    images/ui_img_7f4d41bf9dbc8f7379e2f7530b8e969220dfdc933506ec8eaab7085267533a50_png.c
    images/ui_img_9743b1bb18f8b7e40947a037557131be402985046b4e57f7c2c4796abe024b30_png.c
    images/ui_img_ad4d31f664a1ce704f0219da2805f8459595bc3c01c3f04df2e32ba34a05b8c6_png.c
    images/ui_img_aeab72bcb6fb6c79c32bddec987764f6e47c3e90cd32642a84de75f631b4eed0_png.c
    images/ui_img_b7c8b605f109a0f090fd4231a33c87eaf91ff1bb3a1b6fe94b9057a822162a6d_png.c
    images/ui_img_bfeb5333a4473854d4cba8332d64152d595879c3714e687b45c47ad33b234a08_png.c
    images/ui_img_d3c210e61e8487200fc4c344987243a60257838187a69a6a81c42d7447d5d192_png.c
    images/ui_img_f9dc003e469d3986eb0f7b6d972629ef201946028d530ac946823886e22ca3b2_png.c
    images/ui_img_dark_theme_a_button_png.c
    images/ui_img_dark_theme_b_button_png.c
    images/ui_img_dark_theme_plus_button_png.c)

add_library(ui ${SOURCES})
