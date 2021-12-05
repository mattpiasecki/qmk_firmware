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
int16_t max_pot_val = 1023;
int16_t max_ticks = 50;
int16_t ticks = 0;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
#include "print.h"

uint8_t divisor = 0;

void slider(void) {
    if (divisor++) { // only run the slider function 1/256 times it's called
        return;
    }

    midi_send_cc(&midi_device, 2, 0x3E, 0x7F - (analogReadPin(SLIDER_PIN) >> 3));
}


void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);
    for (int i = 0; i<max_ticks;++i){
        tap_code(KC_VOLD);
    }
    ticks = 0;
}

void matrix_scan_user(void){
    slider();

    pot_val   = (analogReadPin(SLIDER_PIN));
    // If there is a big enough change, then we need to do something
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        // uprintf("Pot Val: %d",pot_val);
        int num_ticks = ((float)pot_val/max_pot_val)*max_ticks;
        int delta_ticks = num_ticks - ticks;
        if (delta_ticks < 0) {
            for (int i = 0; i<abs(delta_ticks);++i){
                tap_code(KC_VOLU);
            }
        } else {
            for (int i = 0; i<abs(delta_ticks);++i){
                tap_code(KC_VOLD);
            }
        }
        ticks = num_ticks;
        pot_oldVal = pot_val;
    }
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MEDIA
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    GAINE = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        LT(_FN,KC_ESC),
        A(C(S(KC_T))),A(C(S(KC_G))),A(C(S(KC_R))),
        C(G(KC_LEFT)), A(C(S(KC_W))),  C(G(KC_RGHT)), KC_SPACE
    ),
    [_FN] = LAYOUT(
        KC_TRNS,
        RGB_TOG, RGB_M_P,  RGB_VAI,
        RESET,   RGB_M_G,  RGB_VAD, TG(_MEDIA)
    ),
    [_MEDIA] = LAYOUT(
        TG(_MEDIA),
        KC_F17, KC_F18, KC_F19,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAINE:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("gaine");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}

