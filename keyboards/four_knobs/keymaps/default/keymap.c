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
#include "four_knobs.h"

// Do not delete _NUM_OF_LAYERS, it's use for determine total number of layers
// in further functions
enum layers { _MACRO0, _MACRO1, _MACRO2, _MEDIA, _MOUSE, _NUM_OF_LAYERS };


// Tap Dance setup
// Tap Dance Layer Toggler - press once, base layer, press twice next layer, etc
enum { TD_LAYER_TOGGLER };

void td_layer_toggler(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t desired_layer = state->count - 1;

    dprintf("\n\ncurrent layer=%d\ndesired layer=%d", layer_state, desired_layer);

    if (desired_layer == 0) {
        layer_clear();

    } else if (0 < desired_layer && desired_layer < _NUM_OF_LAYERS ) {
        dprint("\nmoving to layer");

        layer_move(desired_layer);
    }

    dprintf("\nnew layer=%d", layer_state);

}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER_TOGGLER] = ACTION_TAP_DANCE_FN(td_layer_toggler)
};


// Keymap definitions, standard keycodes for switches under encoders and
// rotary functionalities
#define TD_LM TD(TD_LAYER_TOGGLER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MACRO0]  = LAYOUT(  KC_F13,  KC_F14,  KC_F15,   TD_LM),
    [_MACRO1]  = LAYOUT(  KC_F17,  KC_F18,  KC_F19,   TD_LM),
    [_MACRO2]  = LAYOUT(  KC_F21,  KC_F22,  KC_F23,   TD_LM),
    [_MEDIA] = LAYOUT( KC_MUTE, KC_MPLY, KC_MNXT, _______),
    [_MOUSE] = LAYOUT( KC_BTN1, KC_BTN2, KC_BTN2, _______)
};

// encoder map:
// for each layer(_NUM_OF_LAYERS), for each state (clockwise, anti: 2), for each
// knob (4)
const uint16_t encodermaps[_NUM_OF_LAYERS][2][4] = {
    [_MACRO0]  = {
        { S(KC_F13), S(KC_F14), S(KC_F15), S(KC_F16)},
        { C(KC_F13), C(KC_F14), C(KC_F15), C(KC_F16)}
    },
    [_MACRO1]  = {
        { S(KC_F17), S(KC_F18), S(KC_F19), S(KC_F20)},
        { C(KC_F17), C(KC_F18), C(KC_F19), C(KC_F20)}
    },
    [_MACRO2]  = {
        { S(KC_F21), S(KC_F22), S(KC_F23), S(KC_F24)},
        { C(KC_F21), C(KC_F22), C(KC_F23), C(KC_F24)}
    },
    [_MEDIA]  = {
        { KC_VOLU, KC_MNXT, KC_BRIU, XXXXXXX},
        { KC_VOLD, KC_MPRV, KC_BRID, XXXXXXX}
    },
    [_MOUSE]  = {
        { KC_MS_U, KC_MS_R, KC_WH_U, XXXXXXX},
        { KC_MS_D, KC_MS_L, KC_WH_D, XXXXXXX}
    }
};

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = biton32(layer_state);

    uint16_t kc = encodermaps[current_layer][!clockwise][index];

    dprintf("\n\nENCODER=%u\nlayer_state=%u\ncurrent_layer=%u\nkc=%u", index, layer_state, current_layer, kc);

    tap_code16(kc);
}


// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
//   print("init");
// }
