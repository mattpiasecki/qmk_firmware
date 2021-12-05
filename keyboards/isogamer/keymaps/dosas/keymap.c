#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM,
  _SYM
};

#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define xxx KC_TRNS
#define SftF LSFT_T(KC_F)
#define CtlD LCTL_T(KC_D)
#define AltS LALT_T(KC_S)
#define SftJ RSFT_T(KC_J)
#define CtlK RCTL_T(KC_K)
#define AltL RALT_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
   KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(_NUM,KC_BSPC),
   LSFT_T(KC_TAB),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, SftJ, CtlK, AltL, KC_QUOT, RSFT_T(KC_ENT),
   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,
   KC_LCPO, KC_RAPC, LT(_SYM, KC_SPC), KC_RGUI, MO(_NUM)
  ),

  [_NUM] = LAYOUT(
    DEBUG, xxx, KC_P7, KC_P8, KC_P9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    xxx, xxx, KC_P4, KC_P5, KC_P6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, xxx, KC_F12,
    xxx, KC_P1, KC_P2, KC_P3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, xxx,
    RESET, KC_DOT, KC_P0, xxx, xxx
  ),

  [_SYM] = LAYOUT(
    xxx, KC_QUOT,C(S(A(KC_W))),KC_EQL,KC_F5,KC_TILD,xxx,KC_UNDS,KC_EXLM,xxx,KC_PERC, xxx,
    KC_CAPS, KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,S(A(C(KC_TAB))),C(A(KC_TAB)),KC_PIPE,KC_SCLN, xxx,
    KC_LBRC,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,xxx,C(G(KC_LEFT)),C(G(KC_RGHT)),KC_BSLS,
    KC_LBRC, KC_RBRC, xxx, xxx, xxx
   ),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
        case _BASE:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;
        case _SYM:
            clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
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
    }
}
#endif

