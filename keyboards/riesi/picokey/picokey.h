// Copyright 2023 Riesi
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"
//#include QMK_KEYBOARD_H

// Layout content

#define MATRIX_ROWS 6
#define MATRIX_COLS 4

#define LAYOUT_pi_num(k0A, k0B, k0C, k0D, k1A, k1B, k1C, k1D, k2A, k2B, k2C, k2D, k3A, k3B, k3C, k4A, k4B, k4C, k4D, k5A, k5B) {\
	 {k0A, k0B, k0C, k0D}, \
	 {k1A, k1B, k1C, k1D}, \
	 {k2A, k2B, k2C, k2D}, \
	 {k3A, k3B, k3C, KC_NO}, \
	 {k4A, k4B, k4C, k4D}, \
	 {KC_NO, k5A, k5B, KC_NO} \
}
