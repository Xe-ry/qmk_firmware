#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE    0 // default layer
#define QWERTY  1 // QWERTY layer
#define V60     2 // V60 Fn layer
#define MSTK    3 // mouse keys and tenkeypad
#define FPS     4

#define CG(kc)  LCTL(LGUI(kc))

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// enum {
//   TD_EN = 0,
//   TD_JP
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  F20 |           |QWERTY|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |   [  |           |   ]  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BS/Ctrl|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~V60 | LGUI |  FPS | LAlt | F23/ |                                       |  F24 | RAlt | RGUI | ~V60 |      |
 *   `-----------------------------CTRL-'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | C#Lft| C#Rgt|       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |Space/|  BS  |------|       |------| Tab  |Enter |
 *                                 |LShift|      | EVTHG|       | PgDn |      | /MSTK|
 *                                 `--------------------'       `--------------------'
 */
  [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,     KC_2,     KC_3,   KC_4,   KC_5,       KC_F20,
        KC_TAB,         KC_Q,     KC_W,     KC_F,   KC_P,   KC_G,       KC_LBRC,
        CTL_T(KC_BSPC), KC_A,     KC_R,     KC_S,   KC_T,   KC_D,
        KC_LSFT,        KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,       KC_MINS,
        MO(V60),        KC_LGUI,  TG(FPS),  KC_LALT,CTL_T(KC_F23),
                                                          CG(KC_LEFT),  CG(KC_RGHT),
                                                                        XXXXXXX,
                                            SFT_T(KC_SPC),KC_BSPC,      LALT(KC_A),
        // right hand
        TG(QWERTY), KC_6,   KC_7,   KC_8,     KC_9,     KC_0,           KC_MINS,
        KC_RBRC,    KC_J,   KC_L,   KC_U,     KC_Y,     KC_SCLN,        KC_BSLS,
                    KC_H,   KC_N,   KC_E,     KC_I,     KC_O,           KC_QUOT,
        KC_EQL,     KC_K,   KC_M,   KC_COMM,  KC_DOT,   CTL_T(KC_SLSH), KC_RSFT,
                            KC_F24, KC_RALT,  KC_RGUI,  MO(V60),        XXXXXXX,
        KC_HOME,    KC_END,
        KC_PGUP,
        KC_PGDN,    KC_TAB, LT(MSTK,KC_ENT)
  ),
/* Keymap 1: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BS/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~V60 | LGUI |      | LAlt | F23/ |                                       | F24  | RAlt | RGUI | ~V60 | MSTK |
 *   `-----------------------------CTRL-'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | C#Lft| C#Rgt|       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |Space/|  BS  |------|       |------| Tab  |Enter |
 *                                 |LShift|      | EVTHG|       | PgDn |      | /MSTK|
 *                                 `--------------------'       `--------------------'
 */
// QWERTY version of BASE layer.
  [QWERTY] = KEYMAP(
        // left hand
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_E,   KC_R,   KC_T,   _______,
        _______,_______,KC_S,   KC_D,   KC_F,   KC_G,
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,XXXXXXX,_______,_______,
                                                _______,_______,
                                                        _______,
                                        _______,_______,_______,
        // right hand
        _______,_______,_______,_______,_______,_______,_______,
        _______,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   _______,
                _______,KC_J,   KC_K,   KC_L,   KC_SCLN,_______,
        _______,KC_N,   _______,_______,_______,_______,_______,
                        _______,_______,_______,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
    ),
/* Keymap 2: V60 Fn layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |XXXXXX|  F6  |  F7  |  F8  |  f9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |  BS  | Home |      |           |      | PgUp | PrtSc| ScrLk| Pause|      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Down | Right| Del  | End  |------|           |------| PgDn |   ~  | Ins  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MPrv | MPlay| MNxt | VolDn| VolUp| Mute |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |XXXXXX|      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
  [V60] = KEYMAP(
       // left hand
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,
        _______,  _______,  KC_UP,    _______,  KC_BSPC,  KC_HOME,  _______,
        _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,   KC_END,
        _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MUTE,
        _______,  _______,  XXXXXXX,  _______,  _______,
                                                          _______,  _______,
                                                                    _______,
                                                _______,  _______,  _______,
       // right hand
        XXXXXXX,  KC_F6,    KC_F7,        KC_F8,    KC_F9,    KC_F10,   KC_F11,
        _______,  KC_PGUP,  KC_PSCR,      KC_SLCK,  KC_PAUS,  _______,  KC_F12,
                  KC_PGDN,  LSFT(KC_GRV), KC_INS,   _______,  _______,  _______,
        _______,  _______,  _______,      _______,  _______,  _______,  _______,
                            _______,      _______,  _______,  _______,  _______,
        _______,  _______,
        _______,
        _______,  _______,  _______
  ),
/* Keymap 3:  Mouse keys and tenkeypad layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |XXXXXX|      |   /  |   *  |   -  |   +  |    _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |MsWhUp| MsUp |MsWhDn|      |      |           |      |      |   7  |   8  |   9  |   :  |    |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsAcl0|MsLeft|MsDown|MsRght|      |------|           |------|   (  |   4  |   5  |   6  |   )  |    "   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left |  Up  | Down | Right|      |      |           |      |   [  |   1  |   2  |   3  |   ]  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |XXXXXX|      |      |                                       |   0  |   ,  |   .  |   -  |   =  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |      |
 *                                 |      |      | Mclk |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
  [MSTK] = KEYMAP(
       // left hand
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_WH_U,  KC_MS_U,  KC_WH_D,  _______,  _______,
        _______,  KC_ACL0,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,
        _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, _______,  _______,
        _______,  _______,  XXXXXXX,  _______,  _______,
                                                          _______,  _______,
                                                                    _______,
                                                KC_BTN1,  KC_BTN2,  KC_BTN3,
       // right hand
        XXXXXXX,  _______,    KC_SLSH,LSFT(KC_8), KC_MINS,LSFT(KC_EQL), LSFT(KC_MINS),
        _______,  _______,    KC_7,   KC_8,       KC_9,   LSFT(KC_SCLN),LSFT(KC_BSLS),
                  LSFT(KC_9), KC_4,   KC_5,       KC_6,   LSFT(KC_0),   LSFT(KC_QUOT),
        _______,  KC_LBRC,    KC_1,   KC_2,       KC_3,   KC_RBRC,      _______,
                              KC_0,   KC_COMM,    KC_DOT, KC_MINS,      KC_EQL,
        _______,  _______,
        _______,
        _______,  _______,    _______
  ),
/* Keymap 4: FPS layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           | XXXX |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl | LCtl |      | LAlt | Space|                                       | MHEN | RAlt | RGUI | ~V60 | MSTK |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       | PgUp |      |      |
 *                                 |Space | ~V60 |------|       |------| Tab  |Enter |
 *                                 |      |      | PgDn |       | PgDn |      | /MSTK|
 *                                 `--------------------'       `--------------------'
 */
  [FPS] = KEYMAP(
        // left hand
        _______,_______,_______,_______,_______,_______,_______,
        KC_TAB, _______,_______,KC_E,   KC_R,   KC_T,   _______,
        KC_TAB, _______,KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,_______,_______,_______,_______,_______,_______,
        KC_LCTL,KC_LCTL,_______,KC_LALT,KC_SPC,
                                                KC_HOME,KC_END,
                                                        KC_PGUP,
                                        KC_SPC, MO(V60),KC_PGDN,
        // right hand
        XXXXXXX,_______,_______,_______,_______,_______,_______,
        _______,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   _______,
                _______,KC_J,   KC_K,   KC_L,   KC_SCLN,_______,
        _______,KC_N,   _______,_______,_______,_______,_______,
                        KC_F24, _______,_______,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
    ),
};

// void dance_en (qk_tap_dance_state_t *state, void *user_data) {
//   if(state->count > 0) {
//     register_code (KC_MHEN);
//     unregister_code (KC_MHEN);
//     register_code (KC_LANG2);
//     unregister_code (KC_LANG2);
//     register_code (KC_F23);
//     unregister_code (KC_F23);
//   }
// };

// void dance_jp (qk_tap_dance_state_t *state, void *user_data) {
//   if(state->count > 0) {
//     register_code (KC_HENK);
//     unregister_code (KC_HENK);
//     register_code (KC_LANG1);
//     unregister_code (KC_LANG1);
//     register_code (KC_F24);
//     unregister_code (KC_F24);
//   }
// };

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_EN]  = ACTION_TAP_DANCE_FN (dance_en),
//   [TD_JP]  = ACTION_TAP_DANCE_FN (dance_jp)
// };

const uint16_t PROGMEM fn_actions[] = {
    [QWERTY]  = ACTION_LAYER_TAP_TOGGLE(QWERTY),  // FN1 - Momentary Layer 1 (QWERTY)
    [V60]     = ACTION_LAYER_TAP_TOGGLE(V60),     // FN2 - Momentary Layer 2 (V60)
    [MSTK]    = ACTION_LAYER_TAP_TOGGLE(MSTK),    // FN3 - Momentary Layer 3 (mouse & tenkeypad)
    [FPS]     = ACTION_LAYER_TAP_TOGGLE(FPS)      // FN4 - Momentary Layer 4 (FPS)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case V60:
            ergodox_right_led_1_on();
            break;
        case MSTK:
            ergodox_right_led_3_on();
            break;
        case FPS:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case QWERTY:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
