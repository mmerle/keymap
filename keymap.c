#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _BASE = 0,
  _SYM,
  _NUM,
  _FUN,
};

enum planck_keycodes {
  BACKLIT,
};

// layers
#define SYM MO(_SYM)
#define NUM MO(_NUM)

// ctl / escape
#define CTL_ESC RCTL_T(KC_ESC)

#define SFT_TAB G(S(KC_TAB))

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
  │     │     │  ⌥  │  ⌘  │ SYM │   space   │ NAV │  ⌘  │  ⌥  │     │     │
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
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  |  │     │  `  │  '  │     │     │  -  │  =  │  {  │  }  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  \  │     │     │  "  │     │     │  _  │  +  │  [  │  ]  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │ ▓▓▓ │           │     │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_SYM] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
  _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_QUOT, _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_COLN, _______,
  _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_DQUO, _______, _______, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* [_NUM] - numbers / nav
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │sft/t│  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │ dlt │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  4  │  5  │  6  │     │     │  ◀  │  ▼  │  ▲  │  ▶  │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │  7  │  8  │  9  │     │     │Home │PgDn │PgUp │ End │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │  0  │     │     │           │ ▓▓▓ │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_NUM] = LAYOUT_planck_grid(
  SFT_TAB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, KC_7,    KC_8,    KC_9,    _______, _______, KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  _______, _______, KC_0,    _______, _______, _______, _______,  _______, _______, _______, _______, _______
),

/* [_FUN] - function
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │boot │ f1  │ f2  │ f3  │     │     │     │     │     │     │     │sleep│
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │caps │ f4  │ f5  │ f6  │     │     │ prv │  v- │  v+ │ nxt │     │play │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │ f7  │ f8  │ f9  │     │     │     │ br- │ br+ │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │ ▓▓▓ │           │ ▓▓▓ │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

[_FUN] = LAYOUT_planck_grid(
  QK_BOOT, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, _______, _______, _______, KC_SLEP,
  _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
  _______, KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, KC_BRMD, KC_BRMU, _______, _______, _______,
  RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* WIP [_ADJ] - adjust
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │           │     │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

/* WIP [_GAME] - game base
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │ tab │  q  │  w  │  e  │  r  │     │     │     │     │  ▲  │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ esc │  a  │  s  │  d  │  f  │     │     │     │  ◀︎  │  ▼  │  ▶︎  │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ sft │  1  │  2  │  3  │  4  │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │ ▲Y  │ ▼X  │     │           │     │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

/* [_LAYER] - layer template
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │     │     │     │     │     │     │     │
  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
  │     │     │     │     │     │           │     │     │     │     │     │
  └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

};


// trigger adjust layer
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NUM, _FUN);
}

// caps word combo
enum combo_events {
  CAPS_COMBO,
};

const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();
      }
      break;
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
