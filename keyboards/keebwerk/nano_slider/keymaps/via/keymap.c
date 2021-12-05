/* Copyright 2020 Duckle
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
#include "analog.h"
#include "qmk_midi.h"

// Defines names for use in layer keycodes and the keymap
#define _BASE 0
#define _FN 1
#define _MEDIA 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        LT(_FN,KC_ESC),
        C(G(KC_LEFT)), G(KC_DOT),  C(G(KC_RGHT)),
        C(S(KC_A)),    C(S(KC_Y)), A(S(KC_S)),    KC_SPACE
    ),
    [_FN] = LAYOUT(
        KC_TRNS,
        RGB_TOG, RGB_M_P,  RGB_VAI,
        RESET,   RGB_M_G,  RGB_VAD, TG(_MEDIA)
    ),
    [_MEDIA] = LAYOUT(
        TG(_MEDIA),
        KC_MRWD, KC_MSTP, KC_MFFD,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE
    )
};

uint8_t divisor = 0;

void slider(void) {
    if (divisor++) { // only run the slider function 1/256 times it's called
        return;
    }

    midi_send_cc(&midi_device, 2, 0x3E, 0x7F - (analogReadPin(SLIDER_PIN) >> 3));
}

void matrix_scan_user(void) {
    slider();
}
