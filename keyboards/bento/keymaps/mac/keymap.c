/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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

#define _MEDIA 0
#define _BROWSER 1
#define _MACRO 2

bool has_layer_changed = false;
static uint8_t current_layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                  |                    |  Knob : Vol Up/Dn |
        |      Esc         | Toggle MACRO/Enter |    Press: Mute    |
        |      Prev        |         Next       |  Tgl Brwsr/Play   |
     */
    [_MEDIA] = LAYOUT(
        KC_ESCAPE, MO(_MACRO), KC_MUTE,
        KC_MRWD, KC_MFFD, LT(_BROWSER,KC_MPLY)
    ),
    /*
        |                  |          |  Knob : Desktops  |
        |       Back       |   Fwd    |    Press: Stop    |
        |     PrevTab      | NextTab  |    Transparent    |
     */
    [_BROWSER] = LAYOUT(
        G(KC_LBRC), G(KC_RBRC), KC_ESCAPE,
        S(C(KC_TAB)), C(KC_PGUP), KC_TRNS
    ),
    /*
        |               |                        |  Knob : Windows    |
        | ScrnSht Mar   |       Transparent      |    Transparent     |
        | ScrnSht Win   |     Mission Control    | Teams Toggle Mute  |
     */
    [_MACRO] = LAYOUT(
        G(S(KC_4)), KC_TRNS, KC_TRNS,
        G(S(KC_5)), KC_F3, C(S(KC_M))
    )
};

void matrix_scan_user(void) {
    if (rgblight_get_mode() != RGBLIGHT_MODE_STATIC_LIGHT) {
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    }
    int layer = biton32(layer_state);
    has_layer_changed = (current_layer == layer);
    //https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#colors
    switch (layer) {
        case _MEDIA:
            if (has_layer_changed) {
                rgblight_sethsv (0,0,0);
            }
            break;
        case _BROWSER:
            if (has_layer_changed) {
                rgblight_sethsv (HSV_BLUE);
            }
            break;
        case _MACRO:
            if (has_layer_changed) {
                rgblight_sethsv (HSV_RED);
            }
            break;
    }
    current_layer = layer;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
        case _MEDIA:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;
        case _BROWSER:
            register_code(KC_LCTRL);
            clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
            unregister_code(KC_LCTRL);
            break;
        case _MACRO:
            if (!clockwise) { register_code(KC_LSFT); }
            register_code(KC_LGUI);
            tap_code(KC_TAB);
            unregister_code(KC_LGUI);
            if(!clockwise) { unregister_code(KC_LSFT); }
            break;
    }
}
