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

// row mods
#define ALT_C LALT_T(KC_C)
#define GUI_V LGUI_T(KC_V)
#define GUI_M RGUI_T(KC_M)
#define ALT_COMM LALT_T(KC_COMM)

// ctl / escape
#define CTL_ESC RCTL_T(KC_ESC)

// one shot meh
#define OS_MEH OSM(MOD_MEH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    /* Base
     * ,-----------------------------------------------------------------------.
     * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bksp |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |C/Esc|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |Enter|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Shift|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |HYPR |     | ALT | GUI | NUM |   Space   | SYM | GUI | ALT |     | NAV |
     * `-----------------------------------------------------------------------'
     */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    OS_MEH,  XXXXXXX, KC_LALT, KC_LGUI, NUM,     KC_SPC,  KC_SPC, SYM,     KC_RGUI,  KC_LALT, XXXXXXX, OS_MEH 
),

[_SYM] = LAYOUT_planck_grid(
    /* Symbol
     * ,-----------------------------------------------------------------------.
     * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  =  |  +  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |CAPSW|  "  |  '  |  (  |  )  |  `  |  ~  |  {  |  }  |  -  |  _  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |  <  |  >  |  \  |  |  |  [  |  ]  |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |           |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     * ,-----------------------------------------------------------------------.
     * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |CAPSW|     |     |  "  |  '  |  `  |  |  |  {  |  }  |  -  |  =  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |  \  |  [  |  ]  |  _  |  +  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |           |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_PLUS, _______,
    CAPSWRD, KC_DQUO, KC_QUOT, KC_LPRN, KC_RPRN, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_MINS, KC_UNDS, _______,
    _______, _______, _______, KC_LABK, KC_RABK, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    /* Number
     * ,-----------------------------------------------------------------------.
     * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |Left |Down | Up  |Right|     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |           |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------.
     * |     |Reset|Debug|     |     |     |     |     |     |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |HUE+ |     |     |HUE- |     |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |LED+ |LED Toggle |LED- |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_TOG, RGB_TOG, _______, _______, _______, _______, _______
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
