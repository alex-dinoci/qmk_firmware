#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DIRECTION,
  _I3WM,
  _MEDIA,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  TEST_MACRO
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    LT(_MEDIA, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT),
    _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(_DIRECTION, KC_SPC),  KC_SPC,  RAISE,   LT(_MEDIA, KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
     KC_GRV,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,      KC_PERC,  KC_CIRC,  KC_AMPR,     KC_ASTR,    KC_LPRN,    KC_RPRN,  KC_BSPC,
    _______,  _______,  KC_LCBR,  KC_LBRC,  KC_LPRN,     KC_MINUS,   KC_EQL,  KC_RPRN,     KC_RBRC,    KC_RCBR,  KC_BSLASH,  _______,
    _______,  _______,  _______,  TEST_MACRO,   KC_DLR,      KC_UNDS,  KC_PLUS,  KC_PIPE,  S(KC_COMM),  S(KC_DOT),    _______,  _______,
    _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,     _______,    _______,    _______,  _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,   KC_DEL,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,     KC_4,    KC_5,     KC_6,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,     KC_1,    KC_2,     KC_3,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______
),

[_ADJUST] = LAYOUT_planck_grid(
      RESET, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______,
    _______,    _______,    _______,    _______,    _______,    _______, LGUI(KC_H), LGUI(KC_J), LGUI(KC_K), LGUI(KC_L),    _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_DIRECTION] = LAYOUT_planck_grid(
    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,     KC_END,    _______, _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,      KC_UP,   KC_RIGHT,    _______, _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______
),

[_MEDIA] = LAYOUT_planck_grid(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,
    _______,    KC_MPRV,    KC_MSTP,    KC_MPLY,    KC_MNXT,    _______,    _______,    KC_VOLD,    KC_MUTE,    KC_VOLU,    _______,  _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     KC_PWR,  _______,
    _______,    _______,    _______,    _______,    KC_SYSTEM_SLEEP,    KC_WAKE,    _______,    _______,    _______,    _______,    _______,  _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TEST_MACRO:
        if (record->event.pressed) {
          SEND_STRING("->");
        } else {
        }
        break;
  }
  return true;
}

