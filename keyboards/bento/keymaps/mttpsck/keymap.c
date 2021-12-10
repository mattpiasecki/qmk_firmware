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

enum layers{
  _MEDIA,
  _BROWSER,
  _MACRO,
  _DEBUG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                  |                    |  Knob : Left/Rght |
        |      Mail        | Toggle MACRO/Enter |    Press: Mute    |
        |      Prev        |         Next       |  Tgl Brwsr/Play   |
     */
    [_MEDIA] = LAYOUT(
        KC_F13, LT(_MACRO,KC_ENT), LT(_BROWSER,KC_MUTE),
        KC_F14, KC_F15, KC_SPC
    ),
    /*
        |                  |          |  Knob : Desktops  |
        |       Back       |   Fwd    |    Press: Stop    |
        |     PrevTab      | NextTab  |    Transparent    |
     */
    [_BROWSER] = LAYOUT(
        KC_WBAK, KC_WFWD, KC_WSTP,
        S(C(KC_TAB)), C(KC_TAB), KC_TRNS
    ),
    /*
        |               |                        |  Knob : Vol Up/Dn  |
        | Slack Status  |       Transparent      | Toggle Debug Layer |
        |  WinScrnSht   |        Task View       |  Zoom Toggle Mute  |
     */
    [_MACRO] = LAYOUT(
        KC_F16, KC_TRNS, TG(_DEBUG),
        G(KC_TAB), G(S(KC_S)), A(KC_A)
    ),
    /*
        |                |                        |  Knob:F10/F11 |
        |   LCtrl/F5     |       LShift/F9        |               |
        |   Breakpoints  |    Immediate Window    |      F12      |
     */
    [_DEBUG] = LAYOUT(
        LCTL_T(KC_F5), LSFT_T(KC_F9), TG(_DEBUG),
        C(A(KC_B)), C(A(KC_I)), KC_F12
    ),
};

#ifdef RGBLIGHT_ENABLE
    bool has_layer_changed = false;
    static uint8_t current_layer;

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
            case _DEBUG:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_PURPLE);
                }
                break;
        }
        current_layer = layer;
    }
#endif

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        switch (biton32(layer_state))
        {
            case _MEDIA:
                clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                break;
            case _BROWSER:
                //Tab jumping
                if(!clockwise) { register_code(KC_LSFT); }
                register_code(KC_LCTRL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTRL);
                if(!clockwise) { unregister_code(KC_LSFT); }
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
        return true;
    }
#endif
