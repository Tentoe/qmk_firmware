/* Copyright 2020 Paul James
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

enum lumber_layers {
    _BASE,
    _GAME,
    _LOWER,
    _RAISE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,         KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,         KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,         KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, LT(2,KC_ENT), LT(3,KC_SPC), KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, TO(1)
),
[_GAME] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RSFT_T(KC_ENT),
    KC_LCTL, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, TO(0)
),
[_LOWER] = LAYOUT_ortho_5x12(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_RAISE] = LAYOUT_ortho_5x12(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

void keyboard_pre_init_user() {
    writePin(LED1, true);
    writePin(LED2, true);
}

void keyboard_post_init_user() {
    writePin(LED1, false);
    writePin(LED2, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    writePin(LED2, record->event.pressed);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
        writePinLow(LED2);

    // Game layer
    if (get_highest_layer(state) == 1)
        writePinHigh(LED1);
    else
        writePinLow(LED1);

    return state;
}
