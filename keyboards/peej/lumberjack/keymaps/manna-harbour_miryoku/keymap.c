// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



#undef MIRYOKU_LAYER_TAP
#define MIRYOKU_LAYER_TAP \
KC_ESC,           KC_Q,           KC_W,              KC_E,              KC_R,              KC_U,              KC_I,              KC_O,              KC_P,              KC_BSPC,\
KC_TAB,           KC_A,           KC_S,              KC_D,              KC_F,              KC_J,              KC_K,              KC_L,              KC_SCLN,           KC_QUOT,\
KC_LSFT,          KC_Z,           KC_X,              KC_C,              KC_V,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_ENT,\
KC_LALT,          MO(U_FUN),  MO(U_NUM),     KC_SPC,            KC_ENT,            KC_SPC,            MO(U_NAV),     KC_LCTL,           KC_LSFT,           U_NP
