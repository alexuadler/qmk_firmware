// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE

#define ROTATIONAL_TRANSFORM_ANGLE -25

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER 5

// #define AUTO_MOUSE_DEFAULT_LAYER 5

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
HOME_A,          HOME_S,            HOME_D,            HOME_F,              KC_G,              KC_H,              HOME_J,          HOME_K,            HOME_L,         HOME_QUOT,   \
BU_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,    MO_SLSH,\
U_NP,              U_NP,              MED_ESC,           NAV_SPC,         MO_TAB,           SYM_ENT,            NUM_BSP,  LT(U_FUN,KC_DEL), U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              S_D_MOD,              DPI_MOD,           U_NU,           U_NU,           U_NU,           \
KC_LGUI,         KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                   KC_WH_U,              U_NU,           SNIPING,           U_NU,           U_NU,           \
U_UND,              U_CUT,             U_CPY,             U_PST,            U_RDO,              U_NU,             KC_BTN1,           KC_BTN2,           DRGSCRL,         U_NU,             \
U_NP,              U_NP,              SNIPING,              KC_BTN1,           KC_BTN2,              TD(U_TD_U_BASE),           TD(U_TD_U_MOUSE),           U_NP,           U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_NP,             \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

