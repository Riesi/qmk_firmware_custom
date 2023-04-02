// Copyright 2023 Riesi (@Riesi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RGB_DI_PIN GP28
#define RGBLED_NUM 5

#undef RGBLIGHT_LIMIT_VAL
#undef RGBLIGHT_DEFAULT_HUE
#undef RGBLIGHT_DEFAULT_VAL
#undef RGBLIGHT_DEFAULT_SAT

#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_DEFAULT_HUE 100
#define RGBLIGHT_DEFAULT_SAT UINT8_MAX
#define RGBLIGHT_DEFAULT_VAL 50
#define RGBLIGHT_VAL_STEP 25
#define RGBLIGHT_HUE_STEP 15

#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_TWINKLE
#undef RGBLIGHT_SLEEP

#undef RGBLIGHT_DEFAULT_MODE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
