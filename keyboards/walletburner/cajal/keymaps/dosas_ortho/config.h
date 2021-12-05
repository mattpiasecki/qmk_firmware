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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5742 // WB
#define PRODUCT_ID      0x6361 // CJ
#define DEVICE_VER      0x0001
#define MANUFACTURER    Walletburner
#define PRODUCT         Cajal

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, D5, C7, C6 }
#define MATRIX_COL_PINS { F4, F1, F0, E6, B0, B1, B2, B3, D0, D1, D2, D3, B4, F6 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { D6 }
#define ENCODERS_PAD_B { D7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#ifdef COMBO_ENABLE
    #define COMBO_COUNT 5
    #define COMBO_TERM 20
#endif

#define ENCODER_DIRECTION_FLIP

#ifdef MOUSEKEY_ENABLE
    #define MK_COMBINED
    #define MK_3_SPEED
    #define MK_C_OFFSET_UNMOD 16
    #define MK_C_INTERVAL_UNMOD 16
    #define MK_C_OFFSET_0 4//u
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

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN F7
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 18
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif
