/* Copyright 2021 drhigsby
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

bool is_gui_tab_active = false; // ADD this near the begining of keymap.c
bool is_winos = true; //Controls slider volume behavior allowing toggle between Win & Mac
uint16_t gui_tab_timer = 0;     // we will be using them soon.
uint16_t gui_tab_delay = 1000;  // amount of time to keep mod "held"

enum layers{
  _BASE,
  _APPS,
  _NUM,
  _NAV,
  _SYM,
  _MOUSE
};

enum my_keycodes {
  OSLTOG = USER00
};

#define NUM LT(_NUM,A(KC_SPC))
#define NAV LT(_NAV,KC_SPC)
#define GS LM(_APPS,MOD_LGUI)
#define MAGL LCA_T(KC_LPRN)
#define MAGR LCA_T(KC_RPRN)
#define SYM LT(_SYM,KC_BSPC)
#define MOUSE LT(_MOUSE,KC_ENT)
#define xxx KC_TRNS
#define CtlG LCTL_T(KC_G)
#define SftF LSFT_T(KC_F)
#define GuiD LGUI_T(KC_D)
#define AltS LALT_T(KC_S)
#define CtlH RCTL_T(KC_H)
#define SftJ RSFT_T(KC_J)
#define GuiK RGUI_T(KC_K)
#define AltL RALT_T(KC_L)

#define PUSHSPIN LT(_NAV, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_225u_2u(
        KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, PUSHSPIN,
        KC_TAB, KC_A, AltS, GuiD, SftF, CtlG, CtlH, SftJ, GuiK, AltL, KC_QUOT, KC_SCLN, KC_ENT,
        MAGL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MAGR, KC_UP,
        GS, KC_LCTL, KC_LALT, KC_LGUI, NAV, SYM, NUM, GS, VOLTOG, KC_LEFT, KC_DOWN, KC_RGHT
  ),

    [_APPS] = LAYOUT_225u_2u(
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_UP, xxx, xxx, xxx, xxx, xxx,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_LEFT, KC_DOWN, KC_TAB,xxx, xxx, KC_ENT,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
  ),

    [_NUM] = LAYOUT_225u_2u
    (
        RESET, xxx, KC_P7, KC_P8, KC_P9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F12, xxx, xxx, xxx,
        xxx, xxx, KC_P4, KC_P5, KC_P6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, KC_F11, xxx, xxx,
        xxx, xxx, KC_P1, KC_P2, KC_P3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, KC_F10, xxx, xxx,
        xxx, xxx, xxx, KC_DOT, KC_P0, xxx, xxx, xxx, xxx, xxx, xxx, xxx
  ),

    [_NAV] = LAYOUT_225u_2u(
        KC_GESC,xxx,S(G(KC_LEFT)),S(KC_UP),S(G(KC_RIGHT)),S(G(KC_UP)),G(KC_UP),G(KC_LEFT),KC_UP,G(KC_RGHT),xxx, xxx, xxx, xxx,
        xxx, G(KC_A),S(A(KC_LEFT)),S(KC_DOWN),S(A(KC_RGHT)),S(G(KC_DOWN)),G(KC_DOWN),KC_LEFT,KC_DOWN,KC_RGHT,xxx, xxx, xxx,
        xxx, G(KC_Z),G(KC_X),G(KC_C),G(KC_V), xxx, xxx, xxx, G(A(KC_LEFT)), G(A(KC_RGHT)), xxx, xxx, xxx,
        xxx, xxx, xxx, xxx, xxx, KC_DEL, KC_CAPS, xxx, xxx, xxx, xxx, xxx
  ),

    [_SYM] = LAYOUT_225u_2u(
        xxx, C(G(KC_Q)),G(KC_W),KC_EQL,KC_F5,KC_TILD,C(G(KC_SPC)),KC_UNDS,KC_EXLM,G(S(KC_A)),KC_PERC, KC_LPRN, KC_RPRN, xxx,
        KC_CAPS, KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,xxx,xxx,KC_PIPE,KC_SCLN, xxx, xxx,
        KC_LBRC, xxx,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,xxx,C(KC_LEFT), C(KC_RGHT),KC_BSLS, KC_RBRC, xxx,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
  ),

    [_MOUSE] = LAYOUT_225u_2u(
        RESET, xxx, KC_WH_L,KC_MS_U,KC_WH_R, xxx, xxx, xxx, KC_WH_U, xxx, xxx, xxx, xxx, xxx,
        xxx, xxx,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx, xxx, xxx,
        xxx, xxx,KC_ACL0,KC_ACL1,KC_ACL2,KC_WH_D, xxx, KC_ACL0, KC_ACL1, KC_ACL2, xxx, xxx, xxx,
        TG(_MOUSE), KC_BTN4, KC_BTN5, KC_BTN3,KC_BTN1,KC_BTN2, xxx, xxx, xxx, xxx, xxx, xxx
  ),



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OSTOG:
      if (record->event.pressed) {
        is_winos = is_winos ? false : true;
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

void matrix_scan_user(void) { // The very important timer.
  if (is_gui_tab_active) {
    if (timer_elapsed(gui_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_gui_tab_active = false;
    }
  }
}

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) {
            switch (biton32(layer_state))
            {
                case _BASE:
                    //Word jumping
                    register_code(KC_LALT);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                    break;
                case _NUM:
                    //Word jumping
                    register_code(KC_LALT);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                    break;
                case _NAV:
                    //Word selection
                    register_code(KC_LSFT);
                    register_code(KC_LALT);
                    clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                    unregister_code(KC_LSFT);
                    break;
                case _MOUSE:
                    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                    break;
            }
        }
        return true;
    }
#endif
