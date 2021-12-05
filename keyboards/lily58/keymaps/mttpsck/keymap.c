#include QMK_KEYBOARD_H

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Home  |    |   End |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \  ENT \  |RAISE | RGUI | LOCK |
 *                   |      |      | SPC  |/       /         \      \ | BSPC |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRAVE, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_LCTL,KC_QUOT), \
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_HOME, KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC, \
                 KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC),KC_SPC,        KC_ENT, LT(_RAISE,KC_BSPC), KC_RGUI, KC_CAPSLOCK \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |  5   |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------| Play  |    |       |------+------+------+------+------+------|
 * |      |ctrl z|ctrl x|ctrl c|ctrl v|      |-------|    |-------|   =  |   -  |   _  |   [  |   ]  |  Sft |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \      \  | BSPC |  {   |  }   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PLUS,\
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, KC_MPLY, LCA(KC_A), KC_EQL, KC_MINS, KC_UNDS , KC_LBRC, KC_RBRC, _______, \
                             _______, _______, _______, _______, S(LCA(KC_W)),  KC_BSPC, KC_LCBR, KC_RCBR\
),
/* RAISE -- Left half wtih mods for text selection
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | bF1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | RWD  | Prev | Play | Next |  FFD |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PGUP | Home |  Up  | End  |      |                    | PGUP | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PGDN | Left | Down | Right|      |-------.    ,-------| PGDN | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    | NUMPAD|------+------+------+------+------+------|
 * |      |      | P Tab| N Tab|      |      |-------|    |-------|   +  | Mail | P Win| N Win|      |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \ Del  \  |RAISE | RGUI | LOCK |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD, _______, \
  _______, S(KC_PGUP),S(KC_HOME),S(KC_UP),S(KC_END), _______,              KC_PGUP, KC_HOME, KC_UP,   KC_END, _______,    _______, \
  _______, S(KC_PGDN),S(C(KC_LEFT)),S(KC_DOWN),S(C(KC_RGHT)), _______,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,   XXXXXXX, XXXXXXX, \
  _______, _______,LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), _______, _______, _______, TG(_NUMPAD),KC_PLUS, KC_MAIL ,S(C(A(KC_TAB))),C(A(KC_TAB)), _______, _______,  \
                             _______, _______, _______,  _______, KC_DEL,  _______, _______, _______ \
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |   7  |   8  |   9  |   *  |                    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |   +  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |   -  |-------.    ,-------| MWUP | MWLT | MSU  | MWRT |      |      |
 * |------+------+------+------+------+------|       |    |DEFAULT|------+------+------+------+------+------|
 * |      |      |   0  |   0  |   .  |   /  |-------|    |-------| MWDN |  MSL | MSD  |  MSR |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /       /       \ LMS  \  | RMS  | RGUI | Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUMPAD] = LAYOUT(
  TG(_NUMPAD), XXXXXXX, KC_7, KC_8, KC_9, KC_ASTR,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, \
  XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_PLUS,                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_MINS,                   KC_MS_WH_UP,  KC_MS_WH_LEFT  ,  KC_MS_U  ,  KC_MS_WH_RIGHT  , XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_0, KC_0, KC_DOT, KC_SLSH, _______, TG(_NUMPAD), KC_MS_WH_DOWN,  KC_MS_L  ,  KC_MS_D  , KC_MS_R, XXXXXXX, XXXXXXX,\
                     _______, _______, _______, _______, KC_MS_BTN1,KC_MS_BTN2,_______, KC_DEL \
  )
};

void matrix_init_user(void) {
    /*#ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif*/
}

void render_YOUR_logo(void) {
    static const char PROGMEM YOUR_logo[] = {
        // 'Custom_logo_hex here', 128x32px
    };
    oled_write_raw_P(YOUR_logo, sizeof(YOUR_logo));
}

//#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_mode_icon(bool swap);
//const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);
char wpm_str[10];
uint16_t wpm_graph_timer = 0;
static uint8_t zero_bar_count = 0;
static uint8_t bar_count = 0;

static void render_wpm_graph(void) {
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
        render_YOUR_logo();
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
            //render_YOUR_logo();
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

void oled_task_user(void) {
  // Host Keyboard Layer Status
  //snprintf(encoder_debug, sizeof(encoder_debug), "%i   %i", counter, lastIndex );
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_ln(wpm_str, false);
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(encoder_debug, false);
    //oled_write_ln(read_timelog(), false);
  } else {
      render_wpm_graph();
    // oled_write(read_logo(), false);
    // oled_write_ln(encoder_debug, false);
  }
}
//#endif OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    //set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case NUMPAD:
        if (record->event.pressed) {
          layer_on(_NUMPAD);
        } else {
          layer_off(_NUMPAD);
        }
        return false;
        break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
    case _QWERTY:
        clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
        break;
    case _LOWER:
        clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
        break;
    case _RAISE:
        clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
        break;
    case _NUMPAD:
        //used for encoder based text selection
        //register_code(KC_LSHIFT);
        //register_code(KC_LCTRL);
        //clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
        //unregister_code(KC_LSHIFT);
        //unregister_code(KC_LCTRL);
        clockwise ? tap_code(KC_MS_WH_RIGHT) : tap_code(KC_MS_WH_LEFT);
        break;
    default:
        clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
        break;
    }
}
