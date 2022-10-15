/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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
  _NUM,
  _NAV,
  _SYM,
  _MOUSE,
  _GAME,
  _GAME2
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
        combo_DEL,
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
        [combo_DEL] = COMBO(del_combo, KC_DEL),
        [combo_TAB] = COMBO(tab_combo, KC_TAB),
        [combo_DELETE] = COMBO(del_combo, KC_DEL),
        [combo_ENTER] = COMBO(ent_combo, KC_ENT),
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
        SOME_OTHER_DANCE
    };

    #define sTap KC_BSLS
    #define sHold KC_RPRN
    #define dTap KC_PIPE

    td_state_t cur_dance(qk_tap_dance_state_t *state);

    // For the x tap dance. Put it here so it can be used in any keymap
    void x_finished(qk_tap_dance_state_t *state, void *user_data);
    void x_reset(qk_tap_dance_state_t *state, void *user_data);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KPLAY,
        KC_TAB, CtlA, AltS, GuiD, SftF, KC_G, KC_H, SftJ, GuiK, AltL, CtlScln, KC_QUOT, KC_ENT,
        KC_LSPO,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(X_BSLH), KC_UP,
        TG(_GAME), KC_LCPO, KC_RAPC, KC_LGUI, NAV, KC_SPC, KC_SPC, SYM, NUM, MOUSE, End, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_NUM] = LAYOUT_ortho(
        xxx, xxx, KC_P7, KC_P8, KC_P9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F12, xxx, xxx, xxx,
        xxx, xxx, KC_P4, KC_P5, KC_P6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, KC_F11, xxx, xxx,
        xxx, xxx, KC_P1, KC_P2, KC_P3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, KC_F10, xxx, xxx,
        xxx, xxx,KC_BSPC,KC_DOT,KC_P0,KC_P0, KC_ENT, xxx, xxx, xxx, xxx, xxx, xxx,xxx
    ),

    [_SYM] = LAYOUT_ortho(
        KC_TILD, KC_QUOT,xxx,KC_EQL,KC_F5,KC_TILD,xxx,KC_UNDS,KC_EXLM,xxx,KC_PERC, KC_F11, KC_F12, xxx,
        xxx, KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,PRVAPP,NXTAPP,KC_PIPE,KC_SCLN, xxx, xxx,
        xxx, xxx, KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,KC_MAIL,WinPrv,WinNxt,TD(X_BSLH), xxx, xxx,
        xxx, xxx, xxx, xxx, MO(_NAV), xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx
    ),

    [_NAV] = LAYOUT_ortho(
        KC_GESC,xxx,S(G(KC_LEFT)),S(KC_UP),S(G(KC_RIGHT)),S(G(KC_UP)),G(KC_UP),G(KC_LEFT),KC_UP,G(KC_RGHT), xxx, xxx, xxx, RGB_TOG,
        xxx,G(KC_A),S(A(KC_LEFT)),S(KC_DOWN),S(A(KC_RGHT)),S(G(KC_DOWN)),G(KC_DOWN),KC_LEFT,KC_DOWN,KC_RGHT, xxx, xxx, xxx,
        xxx, G(KC_Z),G(KC_X),G(KC_C),G(KC_V), xxx,xxx, xxx, TabPrv, TabNxt, xxx, xxx, RGB_VAI,
        xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_DEL, KC_CAPS, xxx, xxx, RGB_HUD, RGB_VAD, RGB_HUI
    ),

    [_MOUSE] = LAYOUT_ortho(
        RESET, xxx, KC_WH_L,KC_MS_U,KC_WH_R, xxx, xxx, xxx, KC_WH_U, xxx, xxx, xxx, TG(_GAME), xxx,
        DEBUG, xxx, KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx, xxx, xxx,
        xxx, xxx, KC_ACL0,KC_ACL1,KC_ACL2,KC_WH_D, xxx, KC_ACL0, KC_ACL1, KC_ACL2, xxx, xxx, KC_MFFD,
        xxx, xxx, xxx, KC_BTN3, KC_BTN1,KC_BTN2,KC_BTN2, xxx, xxx, xxx, xxx, KC_MPRV, KC_MRWD, KC_MNXT
    ),

    [_GAME] = LAYOUT_ortho(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, TG(_GAME), KC_MPLY,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSPO,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(X_BSLH), KC_UP,
        TG(_GAME), KC_LCPO, KC_RAPC, KC_LGUI, KC_LCTRL, KC_SPC, KC_SPC, SYM, GNUM, MOUSE, End, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_GAME2] = LAYOUT_ortho(
        KC_ESC, KC_Q, KC_7, KC_8, KC_9, KC_ASTR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, TG(_GAME), KC_MPLY,
        KC_TAB, KC_A, KC_4, KC_5, KC_6, KC_MINUS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSPO,KC_Z, KC_1, KC_2, KC_3, KC_PLUS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(X_BSLH), KC_UP,
        xxx, KC_LCPO, KC_RAPC, KC_LGUI, KC_0, KC_SPC, KC_SPC, SYM, GNUM, MOUSE, End, KC_LEFT, KC_DOWN, KC_RGHT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NXTAPP:
      if (record->event.pressed) {
        if (!is_gui_tab_active) {
            register_code(KC_LGUI);
        }
        gui_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LGUI);
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
        unregister_code(KC_LSFT);
        unregister_code(KC_GRAVE);
        unregister_code(KC_LGUI);
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

void matrix_init_user(void) {
    // set  LED 1 to output and low
    setPinOutput(B5);
    writePinLow(B5);
    // set LED 2 to output and low
    setPinOutput(B6);
    writePinLow(B6);
    // set LED 3 to output and low
    setPinOutput(B7);
    writePinLow(B7);
}

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    switch (get_highest_layer(state)) {
        case _MOUSE:
            writePinHigh(B7);
            break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    writePin(B6, led_state.num_lock);
    return false;
}

//Optional RGB layer indicator
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
        switch (layer){
            case _BASE:
                if (has_layer_changed) {
                    rgblight_sethsv (0,0,0);
                }
                break;
            case _NUM:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_BLUE);
                }
                break;
            case _NAV:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_CORAL);
                }
                break;
            case _SYM:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_SPRINGGREEN);
                }
                break;
            case _MOUSE:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_PURPLE);
                }
                break;
            case _GAME:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_RED);
                }
                break;
            case _GAME2:
                if (has_layer_changed) {
                    rgblight_sethsv (HSV_ORANGE);
                }
                break;
            default:
                if (has_layer_changed) {
                    rgblight_sethsv (0,0,0);
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
            case _BASE:
                    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
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
            case _SYM:
                //Word selection
                register_code(KC_LSFT);
                register_code(KC_LCTRL);
                clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTRL);
                break;
            case _MOUSE:
                clockwise ? tap_code(KC_WH_R) : tap_code(KC_WH_L);
                break;
            case _GAME:
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                break;
            case _GAME2:
                clockwise ? tap_code(KC_MFFD) : tap_code(KC_MRWD);
                break;
        }
        return true;
    }
#endif

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
            case TD_DOUBLE_HOLD: layer_on(_MOUSE); break;
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
            case TD_DOUBLE_HOLD: layer_off(_MOUSE);
            case TD_DOUBLE_SINGLE_TAP: unregister_code16(sTap);
            default: break;
        }
        xtap_state.state = TD_NONE;
    }

    qk_tap_dance_action_t tap_dance_actions[] = {
        [X_BSLH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
    };
#endif
