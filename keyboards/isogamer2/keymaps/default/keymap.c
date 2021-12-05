#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM, 
  _FN
};

enum combo_events {
  combo_DELETE,
  combo_QUOT,
  combo_LPRN,
  combo_RPRN,
  combo_SLSH,
};

const uint16_t PROGMEM del_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_UP, KC_DOT, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
     [combo_DELETE] = COMBO(del_combo, KC_DEL),
       [combo_QUOT] = COMBO(quot_combo, KC_QUOT),
        [combo_LPRN] = COMBO(lprn_combo, KC_LPRN),
         [combo_RPRN] = COMBO(rprn_combo, KC_RPRN),
          [combo_SLSH] = COMBO(slsh_combo, KC_SLSH),
};


#define NUM MO(_NUM_SYM)
#define FN MO(_FN)
#define xxx KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
   KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
   LSFT_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_ENT),
   xxx, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, xxx,
       KC_LCPO, KC_LGUI, KC_RAPC, NUM, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NUM_SYM] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, xxx,
    xxx, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQUAL, KC_QUOT,
    xxx, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, xxx,
               xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
  ),

  [_FN] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, 
              xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
   )

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
