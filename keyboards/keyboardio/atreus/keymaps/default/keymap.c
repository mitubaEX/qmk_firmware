// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    _______, _______, _______, LGUI_T(KC_ESC), LT(_LW, KC_TAB), KC_SPACE, LCTL_T(KC_ENT), LT(_RS, KC_BSPC),  KC_LSFT, _______, _______, _______ ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6, KC_7,  KC_8,    KC_9,   KC_0,
    _______, _______, _______, _______, _______,                  KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,   _______,
    _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,_______, _______,
    _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,_______, _______
    ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR,  KC_ASTR,    KC_LPRN,   KC_RPRN,
    KC_GRV,_______,_______,_______, KC_QUOT,                         KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TILD,_______,_______,_______, KC_DQUO,   _______, _______,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______,_______, _______,_______, _______,_______, _______,_______, _______,_______, _______
    )
};
