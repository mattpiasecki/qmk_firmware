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
#define _DEBUG 3

bool has_layer_changed = false;
static uint8_t current_layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                  |                   | Knob 2: Vol Up/Dn |
        | Open Fave App    |  Toggle RGB Layer |    Press: Mute    |
        |      Prev        |        Next       |  Tgl Brwsr/Play   |
     */
    [_MEDIA] = LAYOUT(
        HYPR(KC_S), LT(_MACRO,KC_ENT), KC_MUTE,
        KC_MPRV, KC_MNXT, LT(_BROWSER,KC_MPLY)
    ),
    /*
        |                  |          | Knob 2: Desktops  |
        |       Back       |   Fwd    |    Press: Stop    |
        |     PrevTab      | NextTab  |     BrwsrSrch     |
     */
    [_BROWSER] = LAYOUT(
        KC_WBAK, KC_WFWD, KC_WSTP,
        S(C(KC_TAB)), C(KC_TAB), KC_WSCH
    ),
    /*
        |               |                        | Knob 2: Windows   |
        | Slack Status  |       Transparent      | Toggle Debug Layer|
        |  WinScrnSht   |        Task View       |  Zoom Toggle Mute |
     */
    [_MACRO] = LAYOUT(
        C(S(KC_Y)), KC_TRNS, TG(_DEBUG),
        G(S(KC_S)), G(KC_TAB), A(KC_A)
    ),
    /*
        |               |                        |Knob2:F10/F11|
        |   LCtrl/F5    |       LShift/F9        |             |
        |      F10      |          F11           |     F12     |
     */
    [_DEBUG] = LAYOUT(
        LCTL_T(KC_F5), LSFT_T(KC_F9), TG(_DEBUG),
        KC_F10, KC_F11, KC_F12
    ),
};

void matrix_scan_user(void) {
    int layer = biton32(layer_state);
    switch (layer){
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
        case _DEBUG:
            if (has_layer_changed) {
                rgblight_sethsv (HSV_GREEN);
            }
            break;
    }
    if (current_layer == layer) {
        has_layer_changed = false;
    } else {
        has_layer_changed = true;
        current_layer = layer;
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
        case _MEDIA:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;
        case _BROWSER:
            register_code(KC_LCTRL);
            register_code(KC_LGUI);
            clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTRL);
            break;
        case _MACRO:
            if (!clockwise) { register_code(KC_LSFT); }
            register_code(KC_LCTRL);
            register_code(KC_LALT);
            tap_code(KC_TAB);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LALT);
            if(!clockwise) { unregister_code(KC_LSFT); }
            break;
        case _DEBUG:
            clockwise ? tap_code(KC_F10) : tap_code(KC_F11);
            break;
    }
}
