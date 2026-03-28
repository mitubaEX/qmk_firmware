// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LCTL_T(KC_A), LSFT_T(KC_S), KC_D,         KC_F,         KC_G,     KC_H, KC_J,         KC_K,         RSFT_T(KC_L), RCTL_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 LT(_NAV, KC_ESC), LT(_NUM, KC_TAB), KC_SPC, KC_ENT, LT(_SYM, KC_BSPC), KC_LGUI
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                 XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_GRV,  XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TILD, XXXXXXX, KC_LABK, KC_RABK, KC_DQUO,    KC_PLUS, KC_SLSH, KC_SCLN, KC_COLN, KC_QUOT,
                 XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX,             KC_ENT,  XXXXXXX, KC_BSPC
    ),

};
