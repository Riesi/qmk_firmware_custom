/* Copyright 2023 Riesi
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define MOUSE_EXTENDED_REPORT

#define PLOOPY_DPI_OPTIONS { 625, 625, 625 }

#define TAPPING_TERM 300

#undef RGBLIGHT_LIMIT_VAL
#undef RGBLIGHT_DEFAULT_HUE
#undef RGBLIGHT_DEFAULT_SAT444

#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_DEFAULT_HUE 200
#define RGBLIGHT_DEFAULT_SAT UINT8_MAX
#define RGBLIGHT_VAL_STEP 25
#define RGBLIGHT_HUE_STEP 15

#define RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_TWINKLE
#undef RGBLIGHT_SLEEP




