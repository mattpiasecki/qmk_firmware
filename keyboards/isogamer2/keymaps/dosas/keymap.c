#include QMK_KEYBOARD_H
#include "bit-c_led.h"

enum layers{
  _BASE,
  _NUM,
  _NAV,
  _SYM
};

#ifdef COMBO_ENABLE
    enum combo_events {
    combo_ESC,
    combo_BACK,
    combo_TAB,
    combo_DELETE,
    combo_ENTER,
    };

    const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM bspc_combo[] = {KC_P, KC_LBRC, COMBO_END};
    const uint16_t PROGMEM tab_combo[] = {KC_W, KC_E, COMBO_END};
    const uint16_t PROGMEM del_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
    const uint16_t PROGMEM ent_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};


    combo_t key_combos[COMBO_COUNT] = {
    [combo_ESC] = COMBO(esc_combo, KC_ESC),
    [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
    [combo_TAB] = COMBO(tab_combo, KC_TAB),
    [combo_DELETE] = COMBO(del_combo, KC_DEL),
    [combo_ENTER] = COMBO(ent_combo, KC_ENT),
    };
#endif

#define NUM LT(_NUM,KC_BSPC)
#define NAV LT(_NAV,KC_RGHT)
#define SYM LT(_SYM,KC_BSPC)
#define SYMent LT(_SYM,KC_ENT)
// #define MOUSE LT(_MOUSE,KC_ENT)
#define xxx KC_TRNS
#define GuiG LGUI_T(KC_G)
#define SftF LSFT_T(KC_F)
#define CtlD LCTL_T(KC_D)
#define AltS LALT_T(KC_S)
#define GuiH RGUI_T(KC_H)
#define SftJ RSFT_T(KC_J)
#define CtlK RCTL_T(KC_K)
#define AltL RALT_T(KC_L)
#define End LM(MOD_LCTL,_NAV)
#define WinPrv S(C(A(KC_TAB)))
#define WinNxt C(A(KC_TAB))
#define DskPrv C(G(KC_LEFT))
#define DskNxt C(G(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
   KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, NUM,
   LSFT_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, GuiH, SftJ, CtlK, AltL, KC_QUOT, SYMent,
   xxx, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, xxx,
       KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, SYM, KC_LEFT, KC_DOWN, NAV
  ),

  [_NAV] = LAYOUT(
    RESET, xxx, S(KC_HOME),S(KC_UP),S(KC_END),S(KC_PGUP),KC_PGUP,KC_HOME,KC_UP,KC_END, xxx, xxx,
    DEBUG, xxx, S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),S(KC_PGDN),KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT, xxx, xxx,
    xxx, C(KC_Z),C(KC_X),C(KC_C),C(KC_V), xxx, xxx, xxx, xxx, xxx, KC_PGDN, xxx,
               xxx, xxx, xxx, xxx, KC_DEL, KC_HOME, KC_PGDN, KC_END
  ),

  [_NUM] = LAYOUT(
    KC_MPLY, xxx, KC_7, KC_8, KC_9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    xxx, xxx, KC_4, KC_5, KC_6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, xxx, KC_F12,
    xxx, xxx, KC_1, KC_2, KC_3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, xxx, xxx,
               xxx, xxx, xxx, KC_0, xxx, xxx, xxx, xxx
  ),

  [_SYM] = LAYOUT(
    KC_MPLY, KC_SLSH,C(S(A(KC_W))),KC_EQL,KC_F5,KC_TILD,xxx,KC_UNDS,KC_EXLM,xxx,KC_PERC, xxx,
    KC_CAPS, KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,WinPrv,WinNxt,KC_PIPE,KC_SCLN, xxx,
    xxx,KC_LBRC,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,xxx,DskPrv,DskNxt,KC_BSLS,xxx,
              xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
   )

};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        led_state.caps_lock ? set_bit_c_LED(LED_ON) : set_bit_c_LED(LED_OFF);
    }
    return res;
}

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        switch (biton32(layer_state))
        {
            case _BASE:
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                break;
            case _NUM:
                clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
                break;
            case _NAV:
                //Word selection
                register_code(KC_LSFT);
                register_code(KC_LCTRL);
                clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTRL);
                break;
            case _SYM:
                clockwise ? tap_code(KC_MFFD) : tap_code(KC_MRWD);
                break;
            // case _MOUSE:
            //     clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
            //     break;
        }
        return true;
    }
#endif
