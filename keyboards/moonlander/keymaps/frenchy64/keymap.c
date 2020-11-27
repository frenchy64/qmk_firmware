/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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



#include QMK_KEYBOARD_H
#include "version.h"
#include <print.h>

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// combos

enum combos {
  SD_LPRN, // s+d => (
  DF_RPRN, // d+f => )
  JK_ESC,  // j+k => esc
  XC_LBRC, // x+c => [
  CV_RBRC, // c+v => ]
  WE_LCBR, // w+e => {
  ER_RCBR, // e+r => }
  QW_OPEN_CLJ_SET, // q+w => #{
  QS_OPEN_CLJ_FN   // q+s => #(
};

const uint16_t PROGMEM sd_combo [] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM df_combo [] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM jk_combo [] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM xc_combo [] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM cv_combo [] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM we_combo [] = { KC_W, KC_E, COMBO_END };
const uint16_t PROGMEM er_combo [] = { KC_E, KC_R, COMBO_END };
const uint16_t PROGMEM qw_combo [] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM qs_combo [] = { KC_Q, KC_S, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [SD_LPRN] = COMBO(sd_combo, KC_LPRN),
  [DF_RPRN] = COMBO(df_combo, KC_RPRN),
  [JK_ESC]  = COMBO(jk_combo, KC_ESC),
  [XC_LBRC] = COMBO(xc_combo, KC_LBRC),
  [CV_RBRC] = COMBO(cv_combo, KC_RBRC),
  [WE_LCBR] = COMBO(we_combo, KC_LCBR),
  [ER_RCBR] = COMBO(er_combo, KC_RCBR),
  [QW_OPEN_CLJ_SET] = COMBO_ACTION(qw_combo),
  [QS_OPEN_CLJ_FN]  = COMBO_ACTION(qs_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case QW_OPEN_CLJ_SET:
      if (pressed) {
        tap_code16(KC_HASH);
        tap_code16(KC_LCBR);
      }
      break;
    case QS_OPEN_CLJ_FN:
      if (pressed) {
        tap_code16(KC_HASH);
        tap_code16(KC_LPRN);
      }
      break;
  }
}

//end combos

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           TO(SYMB), KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TG(MDIA),         TG(MDIA),  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT,  KC_RGHT, LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   TO(BASE),           TO(MDIA), KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,   _______, _______, _______,    _______, TO(SYMB),           TO(BASE), _______, _______, _______, _______, _______, RESET,
        _______, _______,    KC_WH_U, KC_MS_U, KC_WH_D,    _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    KC_MS_L, KC_MS_D, KC_MS_R,    _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, KC_MS_BTN1, _______, _______, _______,    _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______,    _______, _______, KC_MS_BTN2,          _______,           _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                               KC_MS_BTN1, KC_BTN2, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 

    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;

  //attempt to turn off default rbg animation
  rgb_matrix_set_flags(LED_FLAG_NONE);
  //keyboard_config.rgb_matrix_enable = false;
  //rgb_matrix_set_color_all(0, 0, 0);
}

/*
 * LED identifiers:

        0 5 10 15 20 25 29             65 61 56 51 46 41 36
        1 6 11 16 21 26 30             66 62 57 52 47 42 37
        2 7 12 17 22 27 31             67 63 58 53 48 43 38
        3 8 13 18 23 28                   64 59 54 49 44 39
        4 9 14 19 24          35 71          60 55 50 45 40
                        32 33 34 70 69 68
*/

void set_number_key_led_white(uint8_t layer_num) {
  rgb_matrix_set_color_all(0, 0, 0);
  switch (layer_num) {
    case BASE:
      // top left layer indicator
      rgb_matrix_set_color(0, 0xff, 0xff, 0xff);
      break;
    case SYMB:
      rgb_matrix_set_color(5, 0xff, 0xff, 0xff);
      break;
    case MDIA:
      rgb_matrix_set_color(10, 0xff, 0xff, 0xff);
      // mouse keys
      rgb_matrix_set_color(16, 0xff, 0xff, 0xff);
      rgb_matrix_set_color(12, 0xff, 0xff, 0xff);
      rgb_matrix_set_color(17, 0xff, 0xff, 0xff);
      rgb_matrix_set_color(22, 0xff, 0xff, 0xff);
      break;
    default:
      break;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  //print debugging for current layer
#ifdef CONSOLE_ENABLE
  switch(get_highest_layer(state)) {
    case BASE:
      dprintf("BASE layer\n");
      rgb_matrix_set_color_all(0, 0, 0);
      // set the key left of 1
      rgb_matrix_set_color(0, 0xff, 0xff, 0xff);
      break;
    case SYMB:
      dprintf("SYMB layer\n");
      set_number_key_led_white(SYMB);
      break;
    case MDIA:
      dprintf("MDIA layer\n");
      set_number_key_led_white(MDIA);
      break;
    default:
      dprintf("Unknown layer\n");
      rgb_matrix_set_color_all(0, 0, 0);
      break;
  }
#endif 

    return state;
}
