/* Copyright 2020 drhigsby
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
  _BASE,
  _GAME,
  _GAME2,
  _NUM,
  _NAV,
  _SYM,
  _MOUSE
};

#ifdef COMBO_ENABLE
    enum combo_events {
    combo_GAME,
    combo_GAME2,
    combo_ESC,
    combo_BACK,
    combo_TAB,
    combo_DELETE,
    combo_MNXT,
    combo_MPLY,
    combo_MPRV,
    combo_MRWD,
    combo_MFFD,
    combo_MUTE,
    combo_VOLU,
    combo_VOLD,
    combo_LPRN,
    combo_RPRN,
    combo_MOUS3,
    };

    const uint16_t PROGMEM game_combo[] = {KC_Z, KC_P, COMBO_END};
    const uint16_t PROGMEM game2_combo[] = {KC_Q, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM bspc_combo[] = {KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM tab_combo[] = {KC_W, KC_E, COMBO_END};
    const uint16_t PROGMEM del_combo[] = {KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM mnxt_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM mply_combo[] = {KC_COMM, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM mprv_combo[] = {KC_COMM, KC_DOT, COMBO_END};
    const uint16_t PROGMEM mrwd_combo[] = {KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM mffd_combo[] = {KC_M, KC_COMM, COMBO_END};
    const uint16_t PROGMEM mute_combo[] = {KC_P, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM volu_combo[] = {KC_P, KC_QUOT, COMBO_END};
    const uint16_t PROGMEM vold_combo[] = {KC_QUOT, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM lprn_combo[] = {KC_Z, KC_X, COMBO_END};
    const uint16_t PROGMEM rprn_combo[] = {KC_X, KC_C, COMBO_END};
    const uint16_t PROGMEM mous3_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

    combo_t key_combos[COMBO_COUNT] = {
    [combo_GAME] = COMBO(game_combo, TG(_GAME)),
    [combo_GAME2] = COMBO(game2_combo, TG(_GAME2)),
    [combo_ESC] = COMBO(esc_combo, KC_ESC),
    [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
    [combo_TAB] = COMBO(tab_combo, KC_TAB),
    [combo_DELETE] = COMBO(del_combo, KC_DEL),
    [combo_MNXT] = COMBO(mnxt_combo, KC_MNXT),
    [combo_MPLY] = COMBO(mply_combo, KC_MPLY),
    [combo_MPRV] = COMBO(mprv_combo, KC_MPRV),
    [combo_MRWD] = COMBO(mrwd_combo, KC_MRWD),
    [combo_MFFD] = COMBO(mffd_combo, KC_MFFD),
    [combo_MUTE] = COMBO(mute_combo, KC_MUTE),
    [combo_VOLU] = COMBO(volu_combo, KC_VOLU),
    [combo_VOLD] = COMBO(vold_combo, KC_VOLD),
    [combo_LPRN] = COMBO(lprn_combo, KC_LPRN),
    [combo_RPRN] = COMBO(rprn_combo, KC_RPRN),
    [combo_MOUS3] = COMBO(mous3_combo, KC_BTN3),
    };
#endif

#define NUM LT(_NUM,KC_F10)
#define NAV LT(_NAV,KC_SPC)
#define NAVENT LT(_NAV,KC_ENT)
#define NAVPLY LT(_NAV,KC_MPLY)
#define SYM LT(_SYM,KC_BSPC)
#define MOUSE LT(_MOUSE,KC_ENT)
#define xxx KC_TRNS
#define MTAB LT(_NAV,KC_MUTE)
#define GuiG LGUI_T(KC_G)
#define SftF LSFT_T(KC_F)
#define CtlD LCTL_T(KC_D)
#define AltS LALT_T(KC_S)
#define GuiH RGUI_T(KC_H)
#define SftJ RSFT_T(KC_J)
#define CtlK RCTL_T(KC_K)
#define AltL RALT_T(KC_L)
#define tapDelay 80

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, AltS, CtlD, SftF, GuiG, NAVPLY,   GuiH, SftJ, CtlK, AltL, KC_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B, MTAB,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                TG(_MOUSE), KC_LGUI, NAV,    SYM, NUM, MOUSE
  ),

    [_GAME] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_MPLY,   GuiH, SftJ, CtlK, AltL, KC_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                KC_LSFT, KC_LCTL, KC_SPC,    SYM, NUM, NAVENT
  ),

    [_GAME2] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_F5,   GuiH, SftJ, CtlK, AltL, KC_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F6,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                KC_LSFT, KC_LCTL, KC_SPC,    SYM, NUM, NAVENT
  ),

    [_NUM] = LAYOUT(
        xxx, KC_7, KC_8, KC_9, KC_ASTR,   xxx, KC_F7, KC_F8, KC_F9, KC_F12,
        xxx, KC_4, KC_5, KC_6, KC_MINS, xxx,   xxx, KC_F4, KC_F5, KC_F6, KC_F11,
        xxx, KC_1, KC_2, KC_3, KC_PLUS, xxx,  xxx, KC_F1, KC_F2, KC_F3, KC_F10,
        RESET, KC_DOT, KC_0,    xxx, xxx, xxx
  ),

    [_NAV] = LAYOUT(
        xxx,S(KC_HOME),S(KC_UP),S(KC_END),S(KC_PGUP),   KC_PGUP,KC_HOME,KC_UP,KC_END,xxx,
        xxx,S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),S(KC_PGDN), KC_MSEL,  KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,xxx,
        C(KC_Z),C(KC_X),C(KC_C),C(KC_V), xxx, KC_ENT,   xxx, xxx, xxx, xxx, xxx,
        xxx, xxx, xxx,   KC_DEL, KC_CAPS, xxx
  ),

    [_SYM] = LAYOUT(
        KC_QUOT,C(S(A(KC_W))),KC_EQL,KC_F5,KC_TILD, xxx,KC_UNDS,KC_EXLM,xxx,KC_PERC,
        KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV, KC_MSEL,  KC_HASH,S(A(C(KC_TAB))),C(A(KC_TAB)),KC_PIPE,KC_SCLN,
        KC_LBRC,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR, xxx,    KC_NLCK,KC_MAIL,C(G(KC_LEFT)),C(G(KC_RGHT)),KC_BSLS,
        KC_LBRC, KC_RBRC, TG(_MOUSE),    xxx, xxx, xxx
  ),

  [_MOUSE] = LAYOUT(
        xxx,KC_WH_L,KC_MS_U,KC_WH_R, xxx, xxx, xxx, KC_WH_U, xxx, xxx,
        xxx,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U, KC_BTN2, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx,
        xxx,KC_ACL0,KC_ACL1,KC_ACL2,KC_WH_D, KC_BTN1, xxx, KC_ACL0, KC_ACL1, KC_ACL2, xxx,
        TG(_MOUSE), KC_BTN3,KC_BTN1,    KC_BTN2, TG(_MOUSE), xxx
  ),

};

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) { /* bottom encoder */
            switch (biton32(layer_state))
            {
                case _BASE:
                    clockwise ? tap_code(KC_MFFD) : tap_code(KC_MRWD);
                    break;
                case _GAME:
                    clockwise ? tap_code_delay(KC_F10,1695) : tap_code_delay(KC_F9,1695);
                    break;
                case _GAME2:
                    clockwise ? tap_code_delay(KC_F2,tapDelay) : tap_code_delay(KC_F6,tapDelay);
                    break;
                case _NUM:
                    //Word selection
                    register_code(KC_LSFT);
                    register_code(KC_LCTRL);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTRL);
                    break;
                case _NAV:
                    //Tab jumping
                    if(!clockwise) { register_code(KC_LSFT); }
                    register_code(KC_LCTRL);
                    tap_code(KC_TAB);
                    unregister_code(KC_LCTRL);
                    if(!clockwise) { unregister_code(KC_LSFT); }
                    break;
                case _SYM:
                    //Word jumping
                    register_code(KC_LCTRL);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LCTRL);
                    break;
                case _MOUSE:
                    clockwise ? tap_code(KC_MS_WH_RIGHT) : tap_code(KC_MS_WH_LEFT);
                    break;
            }
        } else if (index == 1) { /* top encoder */
            switch (biton32(layer_state))
            {
                case _BASE:
                    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                    break;
                case _GAME:
                    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                    break;
                case _GAME2:
                    clockwise ? tap_code_delay(KC_F4,tapDelay*3) : tap_code_delay(KC_F5,tapDelay*3);
                    break;
                case _NUM:
                    //Page selection
                    register_code(KC_LSFT);
                    clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
                    unregister_code(KC_LSFT);
                    break;
                case _NAV:
                    //Destkop jumping
                    register_code(KC_LCTRL);
                    register_code(KC_LGUI);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LCTRL);
                    unregister_code(KC_LGUI);
                    break;
                case _SYM:
                    //Page jumping
                    clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
                    break;
                case _MOUSE:
                    clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
                    break;
            }
        }
        return true;
    }
#endif
