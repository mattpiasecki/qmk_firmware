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

enum layers{
  _BASE,
  _NAV,
  _SYM,
  _NUM,
  _MOUS
};

enum combo_events {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_DEL,
};

#define KC_SF MT(MOD_LSFT,KC_F)
#define KC_CD MT(MOD_LCTL,KC_D)
#define KC_AS MT(MOD_LALT,KC_S)
#define KC_SJ MT(MOD_RSFT,KC_J)
#define KC_CK MT(MOD_RCTL,KC_K)
#define KC_AL MT(MOD_RALT,KC_L)
#define KC_LTNS LT(_NUM, KC_BSPC)
#define KC_CTAB LCTL_T(KC_TAB)
#define KC_CENT LCTL_T(KC_ENT)
#define KC_SF10 S(KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CTAB,    KC_A,   KC_AS,   KC_CD,   KC_SF,    KC_G,                         KC_H,   KC_SJ,   KC_CK,   KC_AL, KC_QUOT, KC_CENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(_NAV), KC_SPC,KC_TRNS,KC_LTNS, MO(_SYM),LT(_MOUS,KC_SF10)
  ),


    [_NAV] = LAYOUT(
       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,S(KC_PGUP),S(KC_HOME),S(KC_UP),S(KC_END),XXXXXXX,                    KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,TG(_MOUS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,S(KC_PGDN),S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),XXXXXXX,           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                      XXXXXXX, KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,KC_TRNS,KC_DEL, _______, _______
  ),

    [_SYM] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB, KC_QUOT,C(S(A(KC_W))),KC_EQL,  KC_F5, KC_TILD,                      XXXXXXX, KC_UNDS, KC_EXLM, XXXXXXX, KC_PERC, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,   KC_AT, KC_MINS,  KC_DLR, XXXXXXX, KC_GRV,                     KC_HASH,S(A(C(KC_TAB))),C(A(KC_TAB)),KC_PIPE,KC_SCLN,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_ASTR,KC_COLN, KC_CIRC, KC_AMPR,                     KC_NLCK, XXXXXXX,C(G(KC_LEFT)),C(G(KC_RGHT)), KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,TG(_NUM), _______,KC_TRNS,_______, _______, _______
  ),

    [_NUM] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_NUM), XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PAST,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PPLS,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,     KC_0, _______,KC_TRNS,_______, _______, _______
  ),

    [_MOUS] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_MOUS),XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_D,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1, KC_BTN2,KC_TRNS,_______, _______, _______
  )

};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_tab[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_9, KC_ASTR, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_P, KC_LBRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
};
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
        case _BASE:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;
        case _NAV:
            clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
            break;
        case _SYM:
            //used for encoder based text selection
            register_code(KC_LSHIFT);
            register_code(KC_LCTRL);
            clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
            // clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
            break;
        case _NUM:
            //used for encoder based text selection
            register_code(KC_LSHIFT);
            register_code(KC_LCTRL);
            clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
            // clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
            break;
        case _MOUS:
            clockwise ? tap_code(KC_MFFD) : tap_code(KC_MRWD);
            break;
        default:
            clockwise ? tap_code(KC_MS_WH_RIGHT) : tap_code(KC_MS_WH_LEFT);
            break;
    }
}
