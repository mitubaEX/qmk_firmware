// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                      KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,LGUI_T(KC_ESC), LT(_RAISE, KC_TAB),KC_SPACE,   LCTL_T(KC_ENT),  LT(_LOWER, KC_BSPC),KC_LSFT,XXXXXXX,XXXXXXX,XXXXXXX
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_TAB,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,XXXXXXX,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
     KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                   KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_GRV,XXXXXXX,XXXXXXX,XXXXXXX,KC_QUOT,                   KC_MINS, KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     KC_TILD,XXXXXXX,XXXXXXX,XXXXXXX,KC_DQUO,                   KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------.                  ,---------------------------------------.
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                     KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
      KC_F11, KC_F12,  QK_BOOT,KC_PSCR, KC_INS,                   RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,XXXXXXX,
  //|-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGBRST,
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______
  //|-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------|
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
#endif
            break;
    }
    return true;
}
