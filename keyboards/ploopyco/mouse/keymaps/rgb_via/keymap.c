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
#include QMK_KEYBOARD_H
// https://docs.qmk.fm/#/keycodes?id=rgb-lighting
// https://docs.qmk.fm/#/feature_rgblight?id=configuration
// https://docs.qmk.fm/#/feature_layers
// [0] = LAYOUT(C(KC_C), KC_BTN1, KC_BTN3, KC_BTN2, C(KC_V), KC_BTN4, KC_BTN5, DPI_CONFIG),

#define _BL 0
#define _RGBL 1

#ifdef TAP_DANCE_ENABLE

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    X_CTL,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(_BL)) {
                keyboard_config.dpi_config = (keyboard_config.dpi_config + 1) % 3;
                eeconfig_update_kb(keyboard_config.raw);
                pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
            } else {

            }
            break;
        case TD_DOUBLE_TAP:
            if (layer_state_is(_RGBL)) {
                // If already set, then switch it off
                layer_off(_RGBL);
            } else {
                // If not already set, then switch the layer on
                layer_on(_RGBL);
            }
            break;
        default: break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_DOUBLE_HOLD:  break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

enum {
    TD_DPI_RGB,
    TD_MODE_RGB,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for DPI, twice for RGB layer
//    [TD_DPI_RGB] = ACTION_TAP_DANCE_LAYER_TOGGLE(DPI_CONFIG, _RGBL),
    [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL]   = LAYOUT(RGB_VAI, KC_BTN1, KC_BTN3, KC_BTN2, RGB_VAD, KC_BTN4, KC_BTN5, TD(X_CTL)),
    [_RGBL] = LAYOUT(RGB_MOD, RGB_HUI, RGB_TOG, RGB_VAI, RGB_VAD, KC_BTN4, KC_BTN5, TD(X_CTL)),
    [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [4] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [5] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______)
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL]   = LAYOUT(RGB_VAI, KC_BTN1, KC_BTN3, KC_BTN2, RGB_VAD, KC_BTN4, KC_BTN5, TG(_RGBL)),
    [_RGBL] = LAYOUT(RGB_MOD, RGB_HUI, RGB_TOG, RGB_VAI, RGB_VAD, KC_BTN4, KC_BTN5, TG(_RGBL)),
    [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [4] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______),
    [5] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______)
};
#endif
