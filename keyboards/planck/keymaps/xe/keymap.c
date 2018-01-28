/* Copyright 2015-2017 Jack Humbert
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

 #include "planck.h"
 #include "action_layer.h"

 extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _MSTK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
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
[_COLEMAK] = KEYMAP( \
  KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,         KC_LBRC, KC_RBRC, KC_J,              KC_L,       KC_U,     KC_Y,     KC_SCLN, \
  KC_A,    KC_R,    KC_S,    KC_T,          KC_D,         KC_MINS, KC_EQL,  KC_H,              KC_N,       KC_E,     KC_I,     KC_O,    \
  KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,         KC_GRV,  KC_QUOT, KC_K,              KC_M,       KC_COMM,  KC_DOT,   KC_SLSH, \
  LOWER,   _______, KC_LGUI, CTL_T(KC_F23), SFT_T(KC_SPC),KC_BSPC, KC_TAB,  LT(_MSTK,KC_ENT),  ALT_T(KC_F24), _______,  _______,  RAISE   \
),
/* Colemak-ja
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |  [   |  ]   |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |  -   |  =   |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  `   |  '   |   K  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
[_COLEMAKja] = KEYMAP(\
  KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,         KC_RBRC, KC_BSLS, KC_J,              KC_L,       KC_U,     KC_Y,     KC_SCLN, \
  KC_A,    KC_R,    KC_S,    KC_T,          KC_D,         KC_MINS, KC_EQL,  KC_H,              KC_N,       KC_E,     KC_I,     KC_O,    \
  KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,         KC_RO,   KC_QUOT, KC_K,              KC_M,       KC_COMM,  KC_DOT,   KC_SLSH, \
  LOWER,   _______, KC_LGUI, CTL_T(KC_F23), SFT_T(KC_SPC),KC_BSPC, KC_TAB,  LT(_MSTK,KC_ENT),  ALT_T(KC_F24),_______,_______,  RAISE   \
),
*/
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

/* V60
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
[_V60] = KEYMAP( \
  _______,  _______,  KC_UP,  _______,  KC_BSPC,  KC_HOME,  KC_PGUP,  KC_PSCR,      KC_SLCK,  KC_PAUS,  _______,  _______, \
  _______,  KC_LEFT,  KC_DOWN,KC_RIGHT, KC_DEL,   KC_END,   KC_PGDN,  LSFT(KC_GRV), KC_INS,   _______,  _______,  _______, \
  _______,  KC_MPRV,  KC_MPLY,KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,      _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,_______,  _______,  _______,  _______,      _______,  _______,  _______,  _______ \
),*/

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
  RESET,  _______,_______,_______,_______,AU_ON,  AU_OFF, _______,_______,_______,_______,DEBUG,    \
  KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,_______,MI_ON,  MI_OFF, COLEMAK,QWERTY, _______,_______,_______,  \
  _______,_______,_______,MUV_DE, MUV_IN, MU_ON,  MU_OFF, _______,_______,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______   \
)


};


#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
