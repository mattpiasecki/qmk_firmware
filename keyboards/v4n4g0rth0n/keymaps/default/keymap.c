#include "V4N4G0RTH0N.h"
#include "analog.h"
int16_t max_pot_val = 1023;
int16_t max_ticks = 20;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
bool moving     = false;
#define POT_TOLERANCE 50
#define POT_PIN F0
#include "print.h"


void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);
}

void matrix_scan_user(void){
    pot_val   = (analogReadPin(POT_PIN));

    // If there is a big enough change, then we need to do something
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        moving = true;
        pot_oldVal = pot_val;
    }
    else{
        if (moving){
            // Do some fancy conversion to get 'absolute' position to num tap_codes to send
            // Reset moving to 0 so that we don't get multiple attempts to do this
            int num_ticks = ((float)pot_val/max_pot_val)*max_ticks;
            for (int i = 0; i<max_ticks;++i){
                tap_code(KC_VOLD);
            }
            for (int i = 0; i<num_ticks;++i){
                tap_code(KC_VOLU);
            }
            moving = false;
        }
    }
}

enum layers{
  _BASE,
  _NAV,
  _SYM,
  _NUM,
  _GAME
};

#ifdef COMBO_ENABLE
    enum combo_events {
    COMBO_ENT,
    COMBO_NUMBAK,
    COMBO_DEL,
    COMBO_RPRN,
    };

    const uint16_t PROGMEM combo_ent[] = {KC_SCLN, KC_QUOT, COMBO_END};
    const uint16_t PROGMEM combo_numbak[] = {KC_9, KC_ASTR, COMBO_END};
    const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM combo_rprn[] = {KC_Z, KC_X, COMBO_END};

    combo_t key_combos[COMBO_COUNT] = {
    [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
    [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
    [COMBO_DEL] = COMBO(combo_del,KC_DEL),
    [COMBO_RPRN] = COMBO(combo_rprn,KC_RPRN),
    };
#endif

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

#define GuiG LGUI_T(KC_G)
#define SftF LSFT_T(KC_F)
#define CtlD LCTL_T(KC_D)
#define AltS LALT_T(KC_S)
#define GuiH LGUI_T(KC_H)
#define SftJ RSFT_T(KC_J)
#define CtlK RCTL_T(KC_K)
#define AltL RALT_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU,
            KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I,    KC_O,   KC_P, LT(_NUM,KC_BSPC),
            KC_TAB,  KC_A,  AltS, CtlD, SftF, GuiG,      GuiH, SftJ, CtlK,    AltL,   KC_SCLN, LT(_NUM,KC_QUOT),
            KC_LSPO, KC_Z,  KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
            KC_LCTL,KC_LALT,KC_LGUI,LT(_NAV,KC_SPC),     LT(_SYM,KC_BSPC),         KC_LEFT, KC_DOWN, KC_RGHT),
  [_NAV] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
            KC_TRNS,KC_NO,   S(KC_HOME),  S(KC_UP),    S(KC_END),S(KC_PGUP),      KC_PGUP, KC_HOME,   KC_UP,  KC_END,   KC_NO, KC_TRNS,
            KC_TRNS,KC_NO,S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),S(KC_PGDN),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO, KC_TRNS,
            KC_TRNS,C(KC_Z),    C(KC_X),   C(KC_C),      C(KC_V),     KC_NO,      KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO, S(KC_0),
            KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS,                          KC_DEL,          KC_TRNS, KC_TRNS, KC_TRNS),
  [_SYM] = LAYOUT(KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU,
            KC_TRNS,KC_QUOT,C(S(A(KC_W))), KC_EQL,  KC_F5, KC_TILD,     KC_NO,          KC_UNDS,      KC_EXLM,        KC_NO, KC_PERC, KC_TRNS,
            KC_CAPS,  KC_AT,      KC_MINS, KC_DLR,  KC_NO,  KC_GRV,     KC_HASH,S(A(C(KC_TAB))), C(A(KC_TAB)),      KC_PIPE, KC_SCLN, KC_TRNS,
            KC_LBRC,KC_RBRC,      KC_ASTR,KC_COLN,KC_CIRC, KC_AMPR,     KC_NLCK,          KC_NO,C(G(KC_LEFT)),C(G(KC_RGHT)), KC_BSLS, S(KC_0),
            KC_TRNS,KC_TRNS, KC_TRNS,              KC_TRNS,                               KC_TRNS,                    KC_MRWD, KC_MPLY, KC_MFFD),
  [_NUM] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
            KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_ASTR,       KC_TRNS, KC_F7, KC_F8, KC_F9,  KC_F10,  KC_F11,
            KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_MINS,       KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PLUS,       KC_TRNS, KC_F1, KC_F2, KC_F3,  KC_F11,  KC_F12,
            RESET, KC_TRNS, KC_PDOT,      KC_P0,                        KC_F10,       KC_F11,  KC_F12, TG(_GAME)),
  [_GAME] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
            KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I,    KC_O,   KC_P, KC_BSPC,
            KC_LCTL,  KC_A,  KC_S, KC_D, KC_F, KC_G,      KC_H, SftJ, CtlK,    AltL,   KC_SCLN, LT(_NUM,KC_QUOT),
            KC_LSFT, KC_Z,  KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
            KC_TAB, KC_TRNS, KC_LGUI,  KC_SPC,      KC_BSPC,         KC_TRNS, KC_TRNS, TG(_GAME)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};

void keyboard_post_init_user(void) {
    setPinOutput(B4);
    writePinHigh(B4);

    setPinOutput(D7);
    setPinOutput(D6);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            writePinHigh(D7);
            break;
        case _SYM:
            writePinHigh(D6);
            break;
        case _NUM:
            writePinHigh(D7);
            writePinHigh(D6);
            break;
        case _GAME:
            writePinLow(B4);
            writePinLow(D7);
            writePinLow(D6);
            break;
        default:
            writePinHigh(B4);
            writePinLow(D7);
            writePinLow(D6);
    }
    return state;
};
