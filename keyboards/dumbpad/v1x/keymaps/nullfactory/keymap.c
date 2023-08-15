/* Copyright 2020 imchipwood
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

enum custom_layers {
    _BASE,
    _SUB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
          BASE LAYER
     /-----------------------------------------------------`
     |             |  VOL-   |  VOL+   |  Mute   |   F24   |
     |             |---------|---------|---------|---------|
     |             |  F13    |   F14   |   F15   |   F16   |
     |             |---------|---------|---------|---------|
     |             |  F17    |   F18   |   F19   |   F20   |
     |-------------|---------|---------|---------|---------|
     | Play/Pause  | TT(SUB) |    0    |    .    |  Enter  |
     \-----------------------------------------------------'
    */
    [_BASE] = LAYOUT(
                      KC_VOLD,    KC_VOLU,  KC_MUTE,   KC_F24,
                      KC_F13,     KC_F14,   KC_F15,    KC_F16,
                      KC_F17,     KC_F18,   KC_F19,    KC_F20,
      MEH_T(KC_MPLY), TT(_SUB),   KC_P0,    KC_PDOT,   KC_KP_ENTER
    ),
    /*
          SUB LAYER
     /-----------------------------------------------------`
     |             |   F7    |   F8    |   F9    | Del/NLK |
     |             |---------|---------|---------|---------|
     |             |   F4    |   F5    |   F6    |    -    |
     |             |---------|---------|---------|---------|
     |             |   F1    |   F2    |   F3    |    /    |
     |-------------|---------|---------|---------|---------|
     |    MUTE     |         |  LSFT   |  LCTL   |    =    |
     \-----------------------------------------------------'
    */
    [_SUB] = LAYOUT(
                      KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
                      KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
                      KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_MUTE,      _______,    _______,    _______,    _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                // main layer - volume up/down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

            case _SUB:
                // sub layer - next/previous track
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;

            default:
                // default - volume up/down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}
