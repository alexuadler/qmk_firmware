// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#if !defined (MIRYOKU_MAPPING)
  #define MIRYOKU_MAPPING LAYOUT_miryoku
#endif

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define FUN_DEL LT(U_FUN,KC_DEL)
#define NUM_BSP LT(U_NUM,KC_BSPC)
#define SYM_ENT LT(U_SYM,KC_ENT)
#define MO_TAB LT(U_MOUSE,KC_TAB) 
#define NAV_SPC LT(U_NAV,KC_SPC)
#define MED_ESC LT(U_MEDIA,KC_ESC)
#define NUM_SPC LT(U_NUM,KC_SPC)
#define SYM_TAB LT(U_SYM,KC_TAB)
#define MO_ENT LT(U_MOUSE,KC_ENT) 
#define NAV_BSP LT(U_NAV,KC_BSPC)
#define MO_SLSH LT(U_MOUSE,KC_SLSH)
#define BU_Z LT(U_BUTTON,KC_Z)
#define BU_SLSH LT(U_BUTTON,KC_SLSH)


#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT LGUI_T(KC_QUOT)

#define HOME_Z LALT_T(KC_Z)
#define HOME_X LCTL_T(KC_X)
#define HOME_C LSFT_T(KC_C)

#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#else
  #define U_RDO KC_AGIN
  #define U_PST S(KC_INS)
  #define U_CPY C(KC_INS)
  #define U_CUT S(KC_DEL)
  #define U_UND KC_UNDO
#endif
