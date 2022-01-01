#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM,
  _NAV,
  _SYM,
  _MOUSE
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
        X_ETR,
        B_BKSP,
    };

    #define sTap KC_ENT
    #define sHold KC_QUOT
    #define dTap KC_SCLN
    #define dHold _MOUSE

    #define bsTap KC_B
    #define bsHold _SYM
    #define bdTap KC_COMM
    #define bdHold KC_CAPS

    td_state_t cur_dance(qk_tap_dance_state_t *state);
    // For the x tap dance. Put it here so it can be used in any keymap
    void x_finished(qk_tap_dance_state_t *state, void *user_data);
    void x_reset(qk_tap_dance_state_t *state, void *user_data);
    // For the b tap dance. Put it here so it can be used in any keymap
    void b_finished(qk_tap_dance_state_t *state, void *user_data);
    void b_reset(qk_tap_dance_state_t *state, void *user_data);
#endif

#define NUM LT(_NUM,KC_N)
#define NAV LT(_NAV,KC_V)
#define SYM_SPC LT(_SYM,KC_SPC)
#define MOUSE LT(_MOUSE,KC_M)
#define xxx KC_TRNS
#define GuiG LGUI_T(KC_G)
#define SftF LSFT_T(KC_F)
#define CtlD LCTL_T(KC_D)
#define AltS LALT_T(KC_S)
#define GuiH RGUI_T(KC_H)
#define SftJ RSFT_T(KC_J)
#define CtlK RCTL_T(KC_K)
#define AltL RALT_T(KC_L)
#define WinPrv S(C(A(KC_TAB)))
#define WinNxt C(A(KC_TAB))
#define DskPrv C(G(KC_LEFT))
#define DskNxt C(G(KC_RGHT))

enum custom_keycodes {
	MACRO1 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case MACRO1:
				SEND_STRING("Sent from my 1lb alpha");
				return false;
		}
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, AltS, CtlD, SftF, GuiG, GuiH, SftJ, CtlK, AltL, TD(X_ETR),
		KC_Z, KC_X, KC_C, NAV, SYM_SPC, TD(B_BKSP), NUM, MOUSE),

	[_NUM] = LAYOUT(
		TG(_NUM), KC_P7, KC_P8, KC_P9, KC_ASTR, xxx, KC_F7, KC_F8, KC_F9, KC_F12,
        xxx, KC_P4, KC_P5, KC_P6, KC_MINS, xxx, KC_F4, KC_F5, KC_F6, KC_F11,
		xxx, KC_P1, KC_P2, KC_P3, KC_0, KC_COMM, KC_DOT, KC_SLSH),

	[_NAV] = LAYOUT(
		WinPrv,S(KC_HOME),S(KC_UP),S(KC_END),S(KC_PGUP),KC_PGUP,KC_HOME,KC_UP,KC_END,xxx,
        WinNxt,S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),S(KC_PGDN),KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,xxx,
		C(KC_Z),C(KC_X),C(KC_C),C(KC_V), MACRO1, KC_BSPC, DskPrv, DskNxt),

	[_SYM] = LAYOUT(
		KC_QUOT,C(S(A(KC_W))),KC_EQL,KC_F5,KC_TILD,xxx,KC_UNDS,KC_EXLM,xxx,KC_PERC,
        KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_HASH,S(A(C(KC_TAB))),C(A(KC_TAB)),KC_PIPE,KC_SCLN,
		KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, xxx, KC_COMM, KC_DOT, KC_SLSH),

    [_MOUSE] = LAYOUT(
		RESET, KC_WH_L,KC_MS_U,KC_WH_R, KC_WH_U, xxx, xxx, KC_WH_U, xxx, xxx,
        DEBUG,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx,
		KC_ACL0,KC_ACL1,KC_ACL2, KC_BTN1, KC_BTN2, KC_ACL0,KC_ACL1,KC_ACL2),
};

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
            case TD_DOUBLE_HOLD: layer_off(dHold); break;
            case TD_DOUBLE_SINGLE_TAP: unregister_code16(sTap);
            default: break;
        }
        xtap_state.state = TD_NONE;
    }

    void b_finished(qk_tap_dance_state_t *state, void *user_data) {
        xtap_state.state = cur_dance(state);
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: register_code16(bsTap); break;
            case TD_SINGLE_HOLD: layer_on(bsHold); break;
            case TD_DOUBLE_TAP: register_code16(bdTap); break;
            case TD_DOUBLE_HOLD: register_code16(bdHold); break;
            // Last case is for fast typing. Assuming your key is `f`:
            // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
            // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
            case TD_DOUBLE_SINGLE_TAP: tap_code16(bsTap); register_code16(bsTap);
            default: break;
        }
    }

    void b_reset(qk_tap_dance_state_t *state, void *user_data) {
        switch (xtap_state.state) {
            case TD_SINGLE_TAP: unregister_code16(bsTap); break;
            case TD_SINGLE_HOLD: layer_off(bsHold); break;
            case TD_DOUBLE_TAP: unregister_code16(bdTap); break;
            case TD_DOUBLE_HOLD: unregister_code16(bdHold); break;
            case TD_DOUBLE_SINGLE_TAP: unregister_code16(bsTap);
            default: break;
        }
        xtap_state.state = TD_NONE;
    }

    qk_tap_dance_action_t tap_dance_actions[] = {
        [X_ETR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
        [B_BKSP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, b_finished, b_reset)
    };
#endif
