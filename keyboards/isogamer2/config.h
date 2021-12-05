#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x6942
#define PRODUCT_ID 0x6942
#define DEVICE_VER 0x6942
#define MANUFACTURER DrHigsby
#define PRODUCT ISOGamer2

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B1, B3, B2, B5, B4, E6, D7, C6, D4, D0, D1, B6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Define encoder pads */
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }

/* #define RGB_DI_PIN F0
   #define RGBLED_NUM 1  */

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
