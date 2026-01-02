// Copyright 2025 EPOMAKER (@Epomaker)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"

enum layers {
    _BL = 0,
    _FL,
    _MBL,
    _MFL,
    _GBL, // gamemode
    _GFL
};

#define ______ HS_BLACK

enum custom_keycodes {
    QMK_A = SAFE_RANGE,
    QMK_D,
};

bool is_a_pressed = false;
bool is_d_pressed = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT( /* Base Layer */
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                 KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,
        MO(_FL),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                 KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LCMD,  KC_LALT,  KC_SPC,                                   KC_SPC,   KC_RALT,  MO(_FL),  KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),

    [_FL] = LAYOUT( /* Base Function Layer*/
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   EE_CLR,  _______,
        RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_BT4,   KC_BT5,               _______,  _______,  _______,  _______,  _______,  RGB_HUD,  RGB_HUI,  _______, KC_INS,
        _______,  TO(_BL),  KC_S,     _______,  _______,  TO(_GBL),             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  RGB_SAD,  RGB_SAI,  _______,           KC_HOME,
        KC_LSFT,  _______,  RGB_TOG,  _______,  _______,  _______,              NK_TOGG,  TO(_MBL),  _______,  _______,  _______,            _______,  RGB_VAI, KC_END,
        KC_LCTL,  GU_TOGG,  _______,  KC_BATQ,                                  KC_BATQ,  _______,  _______,  _______,                      RGB_SPD,  RGB_VAD, RGB_SPI),

    [_MBL] = LAYOUT( /* Mac base layer*/
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                 KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                 KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LALT,  KC_LGUI,  KC_SPC,                                   KC_SPC,   KC_RGUI,  MO(_MFL), KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),

    [_MFL] = LAYOUT( /* Mac function layer */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   EE_CLR,  _______,
        RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_BT4,   KC_BT5,               _______,  _______,  _______,  _______,  _______,  RGB_HUD,  RGB_HUI,  _______, KC_INS,
        _______,  TO(_BL),  KC_S,     _______,  _______,  TO(_GBL),             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  RGB_SAD,  RGB_SAI,  _______,           KC_HOME,
        KC_LSFT,  _______,  RGB_TOG,  _______,  _______,  _______,              NK_TOGG,  TO(_BL),  _______,  _______,  _______,            _______,  RGB_VAI, KC_END,
        KC_LCTL,  _______,  _______,  KC_BATQ,                                  KC_BATQ,  _______,  _______,  _______,                      RGB_SPD,  RGB_VAD, RGB_SPI),
    [_GBL] = LAYOUT( /* Game base layer (QWERTY)*/
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                 KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,
        _______,  QMK_A,    KC_S,     QMK_D,    KC_F,     KC_G,                 KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LCMD,  KC_LALT,  KC_SPC,                                   KC_SPC,   KC_RALT,  MO(_GFL),  KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),

    [_GFL] = LAYOUT( /* Game function layer (QWERTY)*/
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   EE_CLR,  _______,
        RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_BT4,   KC_BT5,               _______,  _______,  _______,  _______,  _______,  RGB_HUD,  RGB_HUI,  _______, KC_INS,
        _______,  TO(_BL),  KC_S,     _______,  _______,  TO(_GBL),             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  RGB_SAD,  RGB_SAI,  _______,           KC_HOME,
        KC_LSFT,  _______,  RGB_TOG,  _______,  _______,  _______,              NK_TOGG,  _______,  _______,  _______,  _______,            _______,  RGB_VAI, KC_END,
        KC_LCTL,  GU_TOGG,  _______,  KC_BATQ,                                  KC_BATQ,  _______,  _______,  _______,                      RGB_SPD,  RGB_VAD, RGB_SPI),

};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
};
#endif
// clang-format on

bool is_keyboard_master(void) {
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMK_A:
            if (record->event.pressed) {
                is_a_pressed = true;
                if (is_d_pressed) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
            } else {
                is_a_pressed = false;
                unregister_code(KC_A);
                if (is_d_pressed) {
                    register_code(KC_D);
                }
            }
            return false;

        case QMK_D:
            if (record->event.pressed) {
                is_d_pressed = true;
                if (is_a_pressed) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
            } else {
                is_d_pressed = false;
                unregister_code(KC_D);
                if (is_a_pressed) {
                    register_code(KC_A);
                }
            }
            return false;
    }
    return true;
}
