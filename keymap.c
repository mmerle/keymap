#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _BASE,
  _SYM,
  _NUM,
  _ADJUST,
};

enum planck_keycodes {
  BACKLIT,
};

// layers
#define SYM MO(_SYM)
#define NUM MO(_NUM)

// ctl / escape
#define CTL_ESC RCTL_T(KC_ESC)

// one shot meh
#define OS_MEH OSM(MOD_MEH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* [_QWE] - qwerty
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │ tab │  q  │  w  │  e  │  r  │  t  │  y  │  u  │  i  │  o  │  p  │ bsp │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │esc/^│  a  │  s  │  d  │  f  │  g  │  h  │  j  │  k  │  l  │  ;  │ ent │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ sft │  z  │  x  │  c  │  v  │  b  │  n  │  m  │  ,  │  .  │  /  │ sft │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │ alt │ cmd │ SYM │   space   │ NUM │ cmd │ alt │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_BASE] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
  OS_MEH,  XXXXXXX, KC_LALT, KC_LGUI, SYM,     KC_SPC,  KC_SPC, NUM,     KC_RGUI,  KC_LALT, XXXXXXX, OS_MEH 
),

/* [_SYM] - symbols
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │  `  │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  |  │  {  │  }  │  '  │     │     │  -  │  =  │  +  │  :  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  \  │  [  │  ]  │  "  │     │     │  _  │  <  │  >  │  ?  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │ ▓▓▓ │           │     │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_SYM] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
  CAPSWRD, KC_PIPE, KC_LCBR, KC_RCBR, KC_QUOT, _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_COLN, _______,
  _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_DQUO, _______, _______, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* [_NUM] - numbers / nav
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │  ◀  │  ▼  │  ▲  │  ▶  │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │           │ ▓▓▓ │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_NUM] = LAYOUT_planck_grid(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______, _______, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),

/* [_ADJ] - adjust
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │reset│     │     │     │     │     │ prv │  v- │  v+ │ nxt │     │ play│
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │ ▓▓▓ │           │ ▓▓▓ │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_ADJUST] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  QK_BOOT, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
  _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

// adjust layer
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _SYM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
