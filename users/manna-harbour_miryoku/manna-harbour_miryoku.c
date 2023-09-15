// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"
#include "features/achordion.h"

// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
};

//void pointing_device_init_user(void) {
//   set_auto_mouse_layer(U_MOUSE);
//   set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
//}

// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
// my combos
// mousing
const uint16_t PROGMEM lclick[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rclick[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mclick[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM whlup[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM whldn[] = {KC_H, KC_N, COMBO_END};
// base stuff
const uint16_t PROGMEM rf_lprn[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM uj_rprn[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM de_lbrc[] = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM ki_rbrc[] = {KC_K, KC_I, COMBO_END};
const uint16_t PROGMEM ws_lcbr[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM ol_rcbr[] = {KC_O, KC_L, COMBO_END};
// gaming 
const uint16_t PROGMEM rf_g[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM fv_b[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM gaming_zero[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM gaming_rsft[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM gaming_rctl[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM gaming_ralt[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM gaming_esc[] = {KC_T, KC_Q, COMBO_END};
const uint16_t PROGMEM gaming_tab[] = {U_NAV, KC_SPC, COMBO_END};



  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};

enum combo_events {
    THUMBCOMBOS_BASE_RIGHT,
    THUMBCOMBOS_BASE_LEFT,
    THUMBCOMBOS_NAV,
    THUMBCOMBOS_MOUSE,
    THUMBCOMBOS_MEDIA,
    THUMBCOMBOS_NUM,
    LCLICK,
    RCLICK,
    MCLICK,
    WHLUP,
    WHLDN,
    RF_LPRN,
    UJ_RPRN,
    DE_LBRC,
    KI_RBRC,
    WS_LCBR,
    OL_RCBR,
    RF_G,
    FV_B,
    GAMING_ZERO,
    GAMING_RSFT,
    GAMING_RCTL,
    GAMING_RALT,
    GAMING_ESC,
    GAMING_TAB,
    THUMBCOMBOS_SYM,
    THUMBCOMBOS_FUN
};


combo_t key_combos[COMBO_COUNT] = {
  [THUMBCOMBOS_BASE_RIGHT] = COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  [THUMBCOMBOS_BASE_LEFT] = COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  [THUMBCOMBOS_NAV] = COMBO(thumbcombos_nav, KC_DEL),
  [THUMBCOMBOS_MOUSE] = COMBO(thumbcombos_mouse, KC_BTN3),
  [THUMBCOMBOS_MEDIA] = COMBO(thumbcombos_media, KC_MUTE),
  [THUMBCOMBOS_NUM] = COMBO(thumbcombos_num, KC_DOT),
  // my combos
  [LCLICK] = COMBO(lclick, KC_BTN1),
  [RCLICK] = COMBO(rclick, KC_BTN2),
  [MCLICK] = COMBO(mclick, KC_BTN3),
  [WHLUP] = COMBO(whlup, KC_WH_U),
  [WHLDN] = COMBO(whldn, KC_WH_D),
  // base stuff
  [RF_LPRN] = COMBO(rf_lprn, KC_LPRN),
  [UJ_RPRN] = COMBO(uj_rprn, KC_RPRN),
  [DE_LBRC] = COMBO(de_lbrc, KC_LBRC),
  [KI_RBRC] = COMBO(ki_rbrc, KC_RBRC),
  [WS_LCBR] = COMBO(ws_lcbr, KC_LCBR),
  [OL_RCBR] = COMBO(ol_rcbr, KC_RCBR),
  // gaming stuff
  [RF_G] = COMBO(rf_g, KC_G),
  [FV_B] = COMBO(fv_b, KC_B),
  [GAMING_ZERO] = COMBO(gaming_zero, KC_0),
  [GAMING_RSFT] = COMBO(gaming_rsft, KC_RSFT),
  [GAMING_RCTL] = COMBO(gaming_rctl, KC_RCTL),
  [GAMING_RALT] = COMBO(gaming_ralt, KC_RALT),
  [GAMING_ESC] = COMBO(gaming_esc, KC_ESC),
  [GAMING_TAB] = COMBO(gaming_tab, KC_TAB),


  #if defined (MIRYOKU_LAYERS_FLIP)
  [THUMBCOMBOS_SYM] = COMBO(thumbcombos_sym, KC_RPRN),
  #else
  [THUMBCOMBOS_SYM] = COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  [THUMBCOMBOS_FUN] = COMBO(thumbcombos_fun, KC_APP)
};
#endif


//Callback to replicate layer_state_is(layer) for default layer state
layer_state_t default_layer_state;

bool default_layer_state_is(layer_state_t layer) {
    return (default_layer_state & ((layer_state_t)1 << layer)) != 0;
}


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  //disable and enable some left hand combos when on game layer 
    switch (combo_index) {
        case RF_G ... GAMING_TAB:
            return default_layer_state_is(U_TAP);
        case RF_LPRN ... OL_RCBR:
            return !default_layer_state_is(U_TAP);
    }
    return true;
}


enum custom_keycodes {
    RPIPE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RPIPE:
        if (record->event.pressed) {
            // when keycode RPIPE is pressed
            SEND_STRING("%>%");
        } else {
            // when keycode RPIPE is released
        }
        break;
    }
    return true;
};

// achordion
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case FUN_DEL:
        case NUM_BSP:
        case SYM_ENT:
        case MO_TAB:
        case NAV_SPC:
        case MED_ESC:
        case NUM_SPC:
        case SYM_TAB:
        case MO_ENT: 
        case NAV_BSP:
        case MO_SLSH:
        case BU_Z:
            return 0;

        default:
            return 800;
    }

    return 800;
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}
