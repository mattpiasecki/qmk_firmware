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

    #define sTap KC_SLASH
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
        KC_Z, KC_X, KC_C, KC_V, KC_B, MTAB,   KC_N, KC_M, KC_COMM, KC_DOT, KC_BSLS,
                TG(_MOUSE), KC_LGUI, NAV,    SYM, NUM, TD(X_NUMTAP)
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
        KC_GRV, KC_7, KC_8, KC_9, KC_ASTR,   xxx, KC_F7, KC_F8, KC_F9, KC_F12,
        xxx, KC_4, KC_5, KC_6, KC_MINS, xxx,   xxx, KC_F4, KC_F5, KC_F6, KC_F11,
        xxx, KC_1, KC_2, KC_3, KC_PLUS, xxx,  xxx, KC_F1, KC_F2, KC_F3, KC_F10,
        RESET, KC_DOT, KC_0,    xxx, TG(_NUM), xxx
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
