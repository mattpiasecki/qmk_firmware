/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NAV,
  _SYM,
  _NUM,
  _MOUS,
  _GAME
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
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CTAB,    KC_A,   KC_AS,   KC_CD,   KC_SF,    KC_G,                         KC_H,   KC_SJ,   KC_CK,   KC_AL, KC_QUOT, KC_CENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(_NAV), KC_SPC,    KC_LTNS, MO(_SYM),LT(_MOUS,KC_SF10)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,S(KC_PGUP),S(KC_HOME),S(KC_UP),S(KC_END),XXXXXXX,                    KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,TG(_MOUS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,S(KC_PGDN),S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)),XXXXXXX,           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_DEL, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB, KC_QUOT,C(S(A(KC_W))),KC_EQL,  KC_F5, KC_TILD,                      XXXXXXX, KC_UNDS, KC_EXLM, XXXXXXX, KC_PERC, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,   KC_AT, KC_MINS,  KC_DLR, XXXXXXX, KC_GRV,                     KC_HASH,S(A(C(KC_TAB))),C(A(KC_TAB)),KC_PIPE,KC_SCLN,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_ASTR,KC_COLN, KC_CIRC, KC_AMPR,                     KC_NLCK, XXXXXXX,C(G(KC_LEFT)),C(G(KC_RGHT)), KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,TG(_NUM), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_NUM), XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PAST,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PPLS,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,     KC_0, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_MOUS),XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,TG(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_D,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1, KC_BTN2,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, TG(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CTAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,   KC_SJ,   KC_CK,   KC_AL, KC_QUOT, KC_CENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(_NAV), KC_SPC,    KC_LTNS, MO(_SYM),LT(_MOUS,S(KC_F10))
                                      //`--------------------------'  `--------------------------'

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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void render_corne_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
};

char wpm_str[10];
uint16_t wpm_graph_timer = 0;
static uint8_t zero_bar_count = 0;
static uint8_t bar_count = 0;

static void render_wpm_graph(void) {
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
        render_corne_logo();
        wpm_graph_timer = timer_read();
        return;
    }
    if(timer_elapsed(wpm_graph_timer) > 500) {
	wpm_graph_timer = timer_read();

	if(OLED_DISPLAY_HEIGHT == 64)
		bar_height = get_current_wpm() / 2;
	if(OLED_DISPLAY_HEIGHT == 32)
		bar_height = get_current_wpm() / 4;
	if(bar_height > OLED_DISPLAY_HEIGHT)
		bar_height = OLED_DISPLAY_HEIGHT;

	if(bar_height == 0) {
	    // keep track of how many zero bars we have drawn.  If
	    // there is a whole screen worth, turn the display off and
	    // wait until there is something to do
	    if (zero_bar_count > (OLED_DISPLAY_WIDTH/32)) {
            oled_clear();
            wpm_graph_timer = 0;
		return;
	    }
	    zero_bar_count++;
	} else
	    zero_bar_count=0;

	oled_pan(false);
	bar_count++;
	for (uint8_t i = (OLED_DISPLAY_HEIGHT / 8); i > 0; i--) {
	    if (bar_height > 7) {
		if (i % 2 == 1 && bar_count % 3 == 0)
		    bar_segment = 254;
		else
		    bar_segment = 255;
		bar_height -= 8;
	    } else {
		switch (bar_height) {
		    case 0:
			bar_segment = 0;
			break;

		    case 1:
			bar_segment = 128;
			break;

		    case 2:
			bar_segment = 192;
			break;

		    case 3:
			bar_segment = 224;
			break;

		    case 4:
			bar_segment = 240;
			break;

		    case 5:
			bar_segment = 248;
			break;

		    case 6:
			bar_segment = 252;
			break;

		    case 7:
			bar_segment = 254;
			break;
		}
		bar_height = 0;

		if (i % 2 == 1 && bar_count % 3 == 0)
		    bar_segment++;
	    }
	    oled_write_raw_byte(bar_segment, (i-1) * OLED_DISPLAY_WIDTH);
	}
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR(" NAV"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR(" SYM"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR(" NUM"), false);
            break;
        case _MOUS:
            oled_write_ln_P(PSTR("MOUS"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}

#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

//Text only renders
void render_keylogger_status(void) {
    oled_write_P(PSTR("-----"), false);
    oled_write(keylog_str, false);
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_state.caps_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    if (is_master) {
        // oled_render_layer_state();
        // oled_render_keylog();
        sprintf(wpm_str, "WPM: %03d", get_current_wpm());
        oled_write(wpm_str,false);
        oled_set_cursor(0,3);
        render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc)
	    render_mod_status(get_mods()|get_oneshot_mods());
	    render_keylock_status(host_keyboard_led_state());
	    render_keylogger_status();
    } else {
        get_current_wpm() > 0 ? render_wpm_graph() : render_corne_logo();
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
  return true;
}
#endif //OLED_DRIVER_ENABLE
