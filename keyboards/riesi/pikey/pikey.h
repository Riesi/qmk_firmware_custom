// Copyright 2023 Riesi
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"
//#include QMK_KEYBOARD_H

// Layout content

#define MATRIX_ROWS 9
#define MATRIX_COLS 14

#define LAYOUT_pi_max(k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N, k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, k4M, k4N, k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L, k5M, k5N, k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L, k6M, k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, k7I, k7J, k7K, k7L, k7M, k7N, k8A, k8C, k8B) {\
	 {k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, KC_NO}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, KC_NO}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, k4M, k4N}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L, k5M, k5N}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L, k6M, KC_NO}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, k7I, k7J, k7K, k7L, k7M, k7N}, \
	 {k8A, k8B, k8C, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO} \
}
