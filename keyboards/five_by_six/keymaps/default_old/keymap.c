/* Copyright 2019 Maciej Matczak
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
#include "five_by_six.h"


enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _NAVIG,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPC_NV LT(_NAVIG, KC_SPC)

// Biggest kudos goes for Smittey:
// https://github.com/Smittey/qmk_firmware/blob/master/keyboards/planck/keymaps/smittey/keymap.c
// https://www.smittey.co.uk/the-planck-key-theory/
// Additional modification prior customizations and additonal row
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.  ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl | LGUI | Alt  |      |Lower |Space |  |Spc_NV|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_BASE] = LAYOUT(
    KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_ESC,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,   LOWER,  KC_SPC,  SPC_NV,  RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
  ),

/* ,-----------------------------------------.  ,-----------------------------------------.
 * | `    |      |      |      |      |      |  |      |      |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   7  |   8  |   9  |   +  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   4  |   5  |   6  |   +  |  \   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   1  |   2  |   3  |Enter |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | LGUI | Alt  |      |      |Space |  |Space |      |   0  |   .  |Enter |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_LOWER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, KC_PPLS,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PPLS, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, KC_PENT, MT(MOD_RSFT, KC_ENT),
    _______, _______, _______, XXXXXXX, _______,  KC_SPC,  KC_SPC, _______,    KC_0, KC_PDOT, KC_PENT, KC_RGHT
  ),

/* ,-----------------------------------------.  ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   ~  |  !   |  @   |  #   |  $   |  %   |  |  ^   |  &   |  *   |  (   |  )   | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  /   |  {   |  [   |  |  ]   |  }   |  \   |  -   |  =   |  |   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |  _   |  +   |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |Space |  |Space |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_RAISE] = LAYOUT(
     KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, KC_SLSH, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS,  KC_EQL, KC_PIPE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, MT(MOD_LSFT, KC_ENT),
    _______, _______, _______, XXXXXXX, _______,  KC_SPC,  KC_SPC, _______, _______, _______, _______, _______
  ),

/* ,-----------------------------------------.  ,-----------------------------------------.
 * |      |      |      |      |      |      |  |      |      |      |      |      | PSCR |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  UP  |      |      |  |      | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      | LEFT | DOWN | RGHT |      |  |      | LEFT | DOWN |  UP  | RGHT |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      | MUTE | VOL- | VOL+ |      |  |      | |>|| | |<|  | |>|  |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |Space |  |      |      |      |      |      | RST  |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_NAVIG] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
    _______, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
    _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______,  KC_SPC, _______, _______, _______, _______, _______,   RESET
  ),
};
