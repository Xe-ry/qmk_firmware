#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "config.h"

extern keymap_config_t keymap_config;

//Following line allows macro to read current RGB settings
// extern rgblight_config_t rgblight_config;


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _QWERTY 1
#define _DVORAK 2
#define _XELOMAK 3
// #define _RGBLED 4
// #define _V60 5
#define _MSTK 6
#define _LOWER 10
#define _RAISE 11
#define _ADJUST 21

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  // RGBLED,
  MSTK,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  // RGBLED_TOGGLE,
  // RGBLED_STEP_MODE,
  // RGBLED_INCREASE_HUE,
  // RGBLED_DECREASE_HUE,
  // RGBLED_INCREASE_SAT,
  // RGBLED_DECREASE_SAT,
  // RGBLED_INCREASE_VAL,
  // RGBLED_DECREASE_VAL,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |  [   |  ]   |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |  -   |  =   |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  `   |  '   |   K  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,         KC_LBRC, KC_RBRC, KC_J,              KC_L,       KC_U,     KC_Y,     KC_SCLN, \
  KC_A,    KC_R,    KC_S,    KC_T,          KC_D,         KC_MINS, KC_EQL,  KC_H,              KC_N,       KC_E,     KC_I,     KC_O,    \
  KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,         KC_GRV,  KC_QUOT, KC_K,              KC_M,       KC_COMM,  KC_DOT,   KC_SLSH, \
  LOWER,   _______, KC_LGUI, CTL_T(KC_F23), SFT_T(KC_SPC),KC_BSPC, KC_TAB,  LT(_MSTK,KC_ENT),  ALT_T(KC_F24), _______,  _______,  RAISE   \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 [_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  _ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


/* MSTK
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MSTK] = KEYMAP( \
  _______,  KC_WH_U,  KC_MS_U,  KC_WH_D,  _______,  _______,  _______,  _______,    KC_7,   KC_8,       KC_9,   LSFT(KC_SCLN),  \
  KC_ACL0,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  LSFT(KC_9), KC_4,   KC_5,       KC_6,   LSFT(KC_0), \
  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, _______,  _______,  _______,  KC_LBRC,    KC_1,   KC_2,       KC_3,   KC_RBRC,   \
  _______,  _______,  _______,  KC_BTN3,  KC_BTN1,  KC_BTN2,  _______,  _______,    KC_0,   KC_COMM,    KC_DOT, KC_MINS   \
),
/* Lower
 */
[_LOWER] = KEYMAP( \
  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,     _______,   _______,  KC_6,     KC_7,     KC_8,    KC_9,    KC_0, \
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______,   _______,  KC_DEL,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, \
  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,   KC_BSLS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END, \
  _______,  _______, _______, _______, _______, _______,    _______,  _______,  KC_PSCR,  KC_SLCK, KC_PAUS, _______ \
),
/* Raise
 */
[_RAISE] = KEYMAP( \
  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______,  KC_JYEN,  LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),\
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______,   KC_RO,  KC_DEL,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, \
  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,   KC_BSLS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END, \
  _______,  _______, _______, _______, _______, _______,    _______,  _______,  KC_PSCR,  KC_SLCK, KC_PAUS, _______ \
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |RGBLED|      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Xelomk|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,DEBUG,    \
  KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,COLEMAK,QWERTY, _______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______   \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//     // rgblight_mode(RGB_current_mode);
//     layer_on(layer3);
//   } else {
//     layer_off(layer3);
//   }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
