// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// #define AUTO_MOUSE_DEFAULT_LAYER 5

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
HOME_A,          HOME_S,            HOME_D,            HOME_F,              KC_G,              KC_H,              HOME_J,          HOME_K,            HOME_L,         HOME_QUOT,   \
BU_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,    MO_SLSH,\
U_NP,              U_NP,              FUN_DEL,           NUM_BSP,         SYM_ENT,           MO_TAB,            NAV_SPC,  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_NU,              U_NU,           U_NU,           U_NU,           U_NU,           \
KC_LGUI,         KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                   KC_WH_U,              U_NU,           U_NU,           U_NU,           U_NU,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              KC_WH_D,             KC_BTN1,           KC_BTN2,           KC_BTN3,         U_NU,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              TD(U_TD_U_BASE),           TD(U_TD_U_MOUSE),           U_NP,           U_NP,              U_NP
