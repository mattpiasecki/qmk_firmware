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

bool is_gui_tab_active = false; // ADD this near the begining of keymap.c
uint16_t gui_tab_timer = 0;     // we will be using them soon.
uint16_t gui_tab_delay = 1000;  // amount of time to keep mod "held"

enum layers{
  _BASE,
  _APPS,
  _NUM,
  _MAG,
  _NAV,
  _SYM,
  _MOUSE
};

enum my_keycodes {
  PRVAPP = SAFE_RANGE,
  NXTAPP
};

#ifdef COMBO_ENABLE
    enum combo_events {
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

#ifdef TAP_DANCE_ENABLE
    typedef enum {
        TD_NONE,
        TD_UNKNOWN,
        TD_SINGLE_TAP,
        TD_SINGLE_HOLD,
        TD_DOUBLE_TAP,
        TD_DOUBLE_HOLD,
        TD_DOUBLE_SINGLE_TAP, // Send two single taps
        TD_TRIPLE_TAP,
        TD_TRIPLE_HOLD
    } td_state_t;

    typedef struct {
        bool is_press_action;
        td_state_t state;
    } td_tap_t;

    // Tap dance enums
    enum {
        X_BSLH,
        X_NUMTAP
    };

    #define sTap KC_SLSH
    #define sHold KC_BSLS
    #define dTap KC_PIPE
    #define dHold _MOUSE

    #define nsTap KC_ENT
    #define nsHold _MOUSE
    #define ndTap KC_F12
    #define ndHold _NUM

    td_state_t cur_dance(qk_tap_dance_state_t *state);

    // For the x tap dance. Put it here so it can be used in any keymap
    void x_finished(qk_tap_dance_state_t *state, void *user_data);
    void x_reset(qk_tap_dance_state_t *state, void *user_data);
    void nx_finished(qk_tap_dance_state_t *state, void *user_data);
    void nx_reset(qk_tap_dance_state_t *state, void *user_data);
#endif

#define NUM LT(_NUM,A(KC_SPC))
#define NAV LT(_NAV,KC_SPC)
#define GS LM(_APPS,MOD_LGUI)
#define MAG LT(_MAG,C(KC_SPC))
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, AltS, GuiD, SftF, CtlG, CtlH, SftJ, GuiK, AltL, KC_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                MAG, GS, NAV, SYM, NUM, TD(X_NUMTAP)
    ),

    [_APPS] = LAYOUT(
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_UP, xxx, xxx,
        xxx, xxx, xxx, xxx, xxx, xxx, KC_LEFT, KC_DOWN, KC_TAB, KC_ENT,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
        xxx, xxx, xxx, xxx, xxx, xxx
    ),

    [_NUM] = LAYOUT(
        xxx, KC_P7, KC_P8, KC_P9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F12,
        xxx, KC_P4, KC_P5, KC_P6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, KC_F11,
        xxx, KC_P1, KC_P2, KC_P3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, KC_F10,
        xxx, KC_DOT, KC_P0, xxx, xxx, xxx
    ),


    [_MAG] = LAYOUT(
        xxx, C(A(KC_E)), xxx, C(A(KC_T)), xxx, xxx, C(A(KC_U)), C(A(KC_UP)), C(A(KC_I)), xxx,
        xxx, C(A(KC_D)), C(A(KC_F)), C(A(KC_G)), xxx, xxx, C(A(KC_LEFT)), C(A(KC_DOWN)), C(A(KC_RGHT)), C(A(KC_ENT)),
        xxx, xxx, xxx, xxx, xxx, xxx, C(A(KC_J)), C(A(KC_DOWN)), C(A(KC_K)), xxx,
        xxx, xxx, xxx, xxx, xxx, xxx
    ),

    [_NAV] = LAYOUT(
        KC_GESC,S(G(KC_LEFT)),S(KC_UP),S(G(KC_RIGHT)),S(G(KC_UP)),G(KC_UP),G(KC_LEFT),KC_UP,G(KC_RGHT),xxx,
        G(KC_A),S(A(KC_LEFT)),S(KC_DOWN),S(A(KC_RGHT)),S(G(KC_DOWN)),G(KC_DOWN),KC_LEFT,KC_DOWN,KC_RGHT,xxx,
        G(KC_Z),G(KC_X),G(KC_C),G(KC_V), xxx, xxx, xxx, G(A(KC_LEFT)), G(A(KC_RGHT)), xxx,
        xxx, xxx, xxx, KC_DEL, KC_CAPS, xxx
    ),

    [_SYM] = LAYOUT(
        C(G(KC_Q)),G(KC_W),KC_EQL,KC_F5,KC_TILD,C(G(KC_SPC)),KC_UNDS,KC_EXLM,G(S(KC_A)),KC_PERC,
        KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,PRVAPP,NXTAPP,KC_PIPE,KC_SCLN,
        KC_LBRC,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,xxx,C(KC_LEFT), C(KC_RGHT),KC_BSLS,
        KC_LBRC, KC_RBRC, TG(_MOUSE), xxx, xxx, xxx
    ),

    [_MOUSE] = LAYOUT(
        RESET,KC_WH_L,KC_MS_U,KC_WH_R, xxx, xxx, xxx, KC_WH_U, xxx, xxx,
        xxx,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx,
        xxx,KC_ACL0,KC_ACL1,KC_ACL2,KC_WH_D, xxx, KC_ACL0, KC_ACL1, KC_ACL2, xxx,
        TG(_MOUSE), KC_BTN3,KC_BTN1,KC_BTN2, TG(_MOUSE), xxx
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NXTAPP:
      if (record->event.pressed) {
        if (!is_gui_tab_active) {
          is_gui_tab_active = true;
          register_code(KC_LGUI);
        }
        gui_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false; // Skip all further processing of this key
    case PRVAPP:
      if (record->event.pressed) {
        if (!is_gui_tab_active) {
          is_gui_tab_active = true;
          register_code(KC_LGUI);
        }
        gui_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_GRAVE);
      } else {
        unregister_code(KC_GRAVE);
        unregister_code(KC_LSFT);
      }
      return false; // Skip all further processing of this key
    case MAGL:
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_LPRN);
            return false;        // Return false to ignore further processing of key
        }
    case MAGR:
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_LPRN);
            return false;        // Return false to ignore further processing of key
        }
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

#ifdef TAP_DANCE_ENABLE
    /* Return an integer that corresponds to what kind of tap dance should be executed.
    *
    * How to figure out tap dance state: interrupted and pressed.
    *
    * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
    *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
    *
    * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
    *  has ended, but the key is still being pressed down. This generally means the key is being "held".
    *
    * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
    *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
    *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
    *
    * Good places to put an advanced tap dance:
    *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
    *
    * Criteria for "good placement" of a tap dance key:
    *  Not a key that is hit frequently in a sentence
    *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
    *    in a web form. So 'tab' would be a poor choice for a tap dance.
    *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
    *    letter 'p', the word 'pepper' would be quite frustating to type.
    *
    * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
    *
    */
    td_state_t cur_dance(qk_tap_dance_state_t *state) {
        if (state->count == 1) {
            if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
            // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
            else return TD_SINGLE_HOLD;
        } else if (state->count == 2) {
            // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
            // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
            // keystrokes of the key, and not the 'double tap' action/macro.
            if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
            else if (state->pressed) return TD_DOUBLE_HOLD;
            else return TD_DOUBLE_TAP;
        }

        // Assumes no one is trying to type the same letter three times (at least not quickly).
        // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
        // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
        if (state->count == 3) {
            if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
            else return TD_TRIPLE_HOLD;
        } else return TD_UNKNOWN;
    }

    // Create an instance of 'td_tap_t' for the 'x' tap dance.
    static td_tap_t xtap_state = {
        .is_press_action = true,
        .state = TD_NONE
    };

    void x_finished(qk_tap_dance_state_t *state, void *user_data) {
        xtap_state.state = cur_dance(state);
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: register_code16(sTap); break;
            case TD_SINGLE_HOLD: register_code16(sHold); break;
            case TD_DOUBLE_TAP: register_code16(dTap); break;
            case TD_DOUBLE_HOLD: layer_on(dHold); break;
            // Last case is for fast typing. Assuming your key is `f`:
            // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
            // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
            case TD_DOUBLE_SINGLE_TAP: tap_code16(sTap); register_code16(sTap);
            default: break;
        }
    }

    void x_reset(qk_tap_dance_state_t *state, void *user_data) {
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: unregister_code16(sTap); break;
            case TD_SINGLE_HOLD: unregister_code16(sHold); break;
            case TD_DOUBLE_TAP: unregister_code16(dTap); break;
            case TD_DOUBLE_HOLD: layer_off(dHold);
            case TD_DOUBLE_SINGLE_TAP: unregister_code16(sTap);
            default: break;
        }
        xtap_state.state = TD_NONE;
    }

    void nx_finished(qk_tap_dance_state_t *state, void *user_data) {
        xtap_state.state = cur_dance(state);
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: register_code16(nsTap); break;
            case TD_SINGLE_HOLD: layer_on(nsHold); break;
            case TD_DOUBLE_TAP: register_code16(ndTap); break;
            case TD_DOUBLE_HOLD: layer_on(ndHold); break;
            // Last case is for fast typing. Assuming your key is `f`:
            // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
            // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
            case TD_DOUBLE_SINGLE_TAP: tap_code16(nsTap); register_code16(nsTap);
            default: break;
        }
    }

    void nx_reset(qk_tap_dance_state_t *state, void *user_data) {
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: unregister_code16(nsTap); break;
            case TD_SINGLE_HOLD: layer_off(nsHold); break;
            case TD_DOUBLE_TAP: unregister_code16(ndTap); break;
            case TD_DOUBLE_HOLD: break;
            case TD_DOUBLE_SINGLE_TAP: unregister_code16(nsTap);
            default: break;
        }
        xtap_state.state = TD_NONE;
    }

    qk_tap_dance_action_t tap_dance_actions[] = {
        [X_BSLH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
        [X_NUMTAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nx_finished, nx_reset)
    };
#endif
