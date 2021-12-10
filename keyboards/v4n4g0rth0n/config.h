/*
Copyright 2021 jpuerto

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xB33F
#define PRODUCT_ID   0x58E4
#define MANUFACTURER s8erdude
#define PRODUCT      v4n4g0rth0n

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#ifdef VIAL_ENABLE
    #define VIAL_KEYBOARD_UID {0x98, 0xE0, 0x67, 0xEF, 0x09, 0x06, 0xF6, 0x6F}
    #define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
    #define VIAL_UNLOCK_COMBO_COLS { 4, 11 }
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// TOP, MID, BOT
// B4, D7, D6
#define LED_NUM_LOCK_PIN B4
#define LED_CAPS_LOCK_PIN D7
#define LED_SCROLL_LOCK_PIN D6

#ifdef COMBO_ENABLE
    #define COMBO_COUNT 7
    #define COMBO_TERM 40
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

#define POT_TOLERANCE 10
#define POT_PIN F0

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
