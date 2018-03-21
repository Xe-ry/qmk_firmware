/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "xd75.h"
#include "action_layer.h"

 extern keymap_config_t keymap_config;

enum planck_layers {
  _XELOMAK,
  _COLEMAK,
  _QWERTY,
  _MSTK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  XELOMAK = SAFE_RANGE,
  COLEMAK,
  QWERTY,
  MSTK,
  LOWER,
  RAISE,
  BACKLIT
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
[_XELOMAK] = KEYMAP( \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  KC_Q,    KC_W,    KC_G,    KC_D,          KC_F,         KC_LBRC,_______,_______,_______,KC_RBRC, KC_J,              KC_L,       KC_U,     KC_Y,     KC_SCLN, \
  KC_S,    KC_A,    KC_O,    KC_T,          KC_K,         KC_MINS,_______,_______,_______,KC_EQL,  KC_R,              KC_N,       KC_E,     KC_I,     KC_H,    \
  KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,         KC_GRV, _______,_______,_______,KC_QUOT, KC_P,              KC_M,       KC_COMM,  KC_DOT,   KC_SLSH, \
  LOWER,   _______, KC_LGUI, CTL_T(KC_F23), SFT_T(KC_SPC),KC_BSPC,_______,_______,_______,KC_TAB,  LT(_MSTK,KC_ENT),  ALT_T(KC_F24), _______,  _______,  RAISE   \
  /* _______,_______,_______,_______,      _______,      _______,_______,_______,_______,_______,_______,          _______,      _______,_______,_______,\
  // KC_SCLN,KC_Q,   KC_F,   KC_W,         KC_B,         KC_LBRC,_______,_______,_______,KC_RBRC,KC_P,             KC_Y,         KC_D,   KC_G,   KC_SLSH,\
  // KC_I,   KC_A,   KC_O,   KC_U,         KC_E,         KC_MINS,_______,_______,_______,KC_EQL, KC_M,             KC_N,         KC_T,   KC_R,   KC_S,\
  // KC_Z,   KC_X,   KC_C,   KC_V,         KC_COMM,      KC_GRV, _______,_______,_______,KC_QUOT,KC_DOT,           KC_H,         KC_J,   KC_K,   KC_L,\
  // LOWER,  _______,KC_LGUI,CTL_T(KC_F23),SFT_T(KC_SPC),KC_BSPC,_______,_______,_______,KC_TAB, LT(_MSTK,KC_ENT), ALT_T(KC_F24),_______,_______,RAISE\
  */
),
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
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,         KC_LBRC,_______,_______,_______,KC_RBRC, KC_J,              KC_L,       KC_U,     KC_Y,     KC_SCLN, \
  KC_A,    KC_R,    KC_S,    KC_T,          KC_D,         KC_MINS,_______,_______,_______,KC_EQL,  KC_H,              KC_N,       KC_E,     KC_I,     KC_O,    \
  KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,         KC_GRV, _______,_______,_______,KC_QUOT, KC_K,              KC_M,       KC_COMM,  KC_DOT,   KC_SLSH, \
  LOWER,   _______, KC_LGUI, CTL_T(KC_F23), SFT_T(KC_SPC),KC_BSPC,_______,_______,_______,KC_TAB,  LT(_MSTK,KC_ENT),  ALT_T(KC_F24), _______,  _______,  RAISE   \
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
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,_______,_______,KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,_______,_______,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,_______,_______,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  _ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  _______,_______,_______,KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
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
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,\
  _______,  KC_WH_U,  KC_MS_U,  KC_WH_D,  _______,  _______,  _______,_______,_______,_______,  _______,    KC_7,   KC_8,       KC_9,   LSFT(KC_SCLN),  \
  KC_ACL0,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,_______,_______,_______,  LSFT(KC_9), KC_4,   KC_5,       KC_6,   LSFT(KC_0), \
  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, _______,  _______,  _______,_______,_______,_______,  KC_LBRC,    KC_1,   KC_2,       KC_3,   KC_RBRC,   \
  _______,  _______,  _______,  KC_BTN3,  KC_BTN1,  KC_BTN2,  _______,_______,_______,_______,  _______,    KC_0,   KC_COMM,    KC_DOT, KC_MINS   \
),

/* Lower
 */
[_LOWER] = KEYMAP( \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,\
  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,     _______,   _______,_______,_______,_______,  KC_6,     KC_7,     KC_8,    KC_9,    KC_0, \
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______,   _______,_______,_______,_______,  KC_DEL,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, \
  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    _______,_______,_______,KC_F12,   KC_BSLS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END, \
  _______,  _______, _______, _______, _______, _______,    _______,_______,_______,_______,  _______,  KC_PSCR,  KC_SLCK, KC_PAUS, _______ \
),
/* Raise
 */
[_RAISE] = KEYMAP( \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,\
  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______,  _______,_______,_______,KC_JYEN,  LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),\
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_ESC,    _______,_______,_______,KC_RO,  KC_DEL,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, \
  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    _______,_______,_______,KC_F12,   KC_BSLS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END, \
  _______,  _______, _______, _______, _______, _______,    _______,_______,_______,_______,  _______,  KC_PSCR,  KC_SLCK, KC_PAUS, _______ \
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
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  RESET,  _______,_______,_______,_______,AU_ON,  _______,_______,_______,AU_OFF, _______,_______,_______,_______,DEBUG,    \
  KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,_______,MI_ON,  _______,_______,_______,MI_OFF, XELOMAK,COLEMAK,QWERTY, _______,_______,  \
  _______,_______,_______,MUV_DE, MUV_IN, MU_ON,  _______,_______,_______,MU_OFF, _______,_______,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______   \
)


};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XELOMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_XELOMAK);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
  }
  return true;
}
