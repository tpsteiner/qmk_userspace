#include QMK_KEYBOARD_H
#include "timer.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define POINT MO(LAYER_POINTER)

// #define PT_Z LT(LAYER_POINTER, KC_Z)
// #define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#define TABBACK LSFT(KC_TAB)
// #define ALTTAB LALT(KC_TAB)
// #define ALTTABB LALT(TABBACK)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_B,    KC_L,    KC_D,    KC_C,    KC_V,      KC_J,     KC_F,    KC_O,    KC_U, KC_COMM, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,      KC_Y,     KC_H,    KC_A,    KC_E,    KC_I, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,      KC_K,     KC_P, KC_QUOT, KC_SCLN,  KC_DOT, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    KC_ESC, KC_SPC, KC_LSFT,    KC_BSPC, KC_DEL,
                                            KC_LALT, KC_LGUI,     KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  // KC_BSPC KC_ENT KC_LGUI
  ),
  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, KC_GRV, KC_TILD,  KC_QUOT, KC_DQUO, XXXXXXX,    XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, KC_PIPE, KC_UNDS, KC_SLSH, KC_BSLS, XXXXXXX,    XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______,    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 _______, XXXXXXX, _______,    XXXXXXX, XXXXXXX,
                                          XXXXXXX, _______,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PMNS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, KC_MUTE, KC_VOLD, KC_VOLU,   POINT, KC_PSCR,    KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, _______,       KC_0,    KC_1,    KC_2,    KC_3, KC_PEQL, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 XXXXXXX, XXXXXXX, XXXXXXX,    _______, XXXXXXX,
                                          XXXXXXX, XXXXXXX,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PGUP,  KC_END, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, DM_REC1, DM_PLY1, DM_RSTP, XXXXXXX,    KC_PGDN, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, DM_REC2, DM_PLY2, XXXXXXX, _______,     KC_TAB, MS_BTN1, MS_BTN2, DRGSCRL,  KC_ESC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, XXXXXXX, _______,    _______, KC_RSFT,
                                           XXXXXXX, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


void pointing_device_init_user(void) {
    set_auto_mouse_layer(3);
    set_auto_mouse_enable(true);
}

// Forward-declare this helper function since it is defined in rgb_matrix.c.
#ifdef RGB_MATRIX_ENABLE
     void rgb_matrix_update_pwm_buffers(void);
#endif

// SHIFT + BACKSPACE = DEL
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color_all(0, 0, 0);

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {

                    switch(layer) {
                        case 3:
                            rgb_matrix_set_color(index, RGB_GREEN);
                            break;
                        case 2:
                            rgb_matrix_set_color(index, RGB_BLUE);
                            break;
                        case 1:
                            rgb_matrix_set_color(index, RGB_RED);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    return false;
}

// toggle between scrolling and cursor movement by pressing DRAG_SCROLL
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}
