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

#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X32
  #define OLED_TIMEOUT 30000
#endif

#define USE_SERIAL_PD2

#ifdef COMBO_ENABLE
    #define COMBO_COUNT 6
    #define COMBO_TERM 30
#endif

#ifdef MOUSEKEY_ENABLE
    #define MK_COMBINED
    #define MK_3_SPEED
    #define MK_C_OFFSET_UNMOD 16
    #define MK_C_INTERVAL_UNMOD 16
    #define MK_C_OFFSET_0 4
    #define MK_C_INTERVAL_0 32
    #define MK_C_OFFSET_1 8
    #define MK_C_INTERVAL_1 16
    #define MK_C_OFFSET_2 22
    #define MK_C_INTERVAL_2 16
    #define MOUSEKEY_DELAY 250
    #define MOUSEKEY_INTERVAL 16
    #define MOUSEKEY_MAX_SPEED 10
    #define MOUSEKEY_TIME_TO_MAX 0
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 10
    #define MOUSEKEY_WHEEL_INTERVAL 25
    #define MOUSEKEY_WHEEL_MAX_SPEED 128
    #define MOUSEKEY_WHEEL_DELAY 200
#endif

#define USE_SERIAL_PD2

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
