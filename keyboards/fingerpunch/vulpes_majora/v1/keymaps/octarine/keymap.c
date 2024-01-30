#include QMK_KEYBOARD_H
#include "features/achordion.h"

void matrix_scan_user(void) {
  achordion_task();
}

//#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _BUTTON

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _GAME,
    _BUTTON,
    _MEDIA,
    _NAV,
    _NUM,
    _SYM,
    _GAMENUM,
    _FUN
};

#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define BUTTON MO(_BUTTON)
#define GAME MO(_GAME)
#define GAMENUM MO(_GAMENUM)
#define FUN MO(_FUN)
#define MEDIA MO(_MEDIA)

#define XXXXXXX KC_NO // key is not present 
#define BSP_NUM LT(NUM,KC_BSPC)
#define TAB_SYM LT(SYM,KC_TAB)
#define ENT_FUN LT(FUN,KC_ENT)
#define SPC_NAV LT(NAV,KC_SPC)
#define DEL_MED LT(MEDIA,KC_DEL)
#define MO_SNP FP_SNIPE_MOMENT
#define S_DPI_U FP_SNIPE_DPI_UP
#define S_DPI_D FP_SNIPE_DPI_DN 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 *  Key layout visual aid
 *
 * ,-----------------------------------------.                                          ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |                                          |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |                                          |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |                                          |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'                                          `-----------------------------------------'
 *                          ,--------------------.      ,--------------------.      ,--------------------.
 *                          |   \  | Enter| LOWER|      | RAISE| Space| Del  |      | RAISE| Space| Del  |
 *                          `--------------------'      `--------------------'      `--------------------'
 *          ,------.        ,--------------------.                                  ,--------------------.        ,------.
 *          |Vol Up|        |Mouse1|Mouse3|Mouse2|                                  |Vol Up| Mute |Vol Dn|        |Vol Up|
 *   ,------+------+------. `--------------------'                                  `--------------------' ,------+------+------.
 *   | Prev | Play | Next |   3 way thumb rocker                                      3 way thumb rocker   | Prev | Play | Next |  5 way switch
 *   `------+------+------'                                                                                `------+------+------'
 *          |Vol Dn|                                                                                              |Vol Dn|
 *          `------'                                                                                              `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_vulpes_majora(
  XXXXXXX,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                           KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,
  XXXXXXX,    HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,                                           KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_QUOT,  XXXXXXX,
  XXXXXXX,    BU_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                           KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                      KC_ESC,     BSP_NUM,    TAB_SYM,    KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, ENT_FUN,    SPC_NAV,    DEL_MED,
              KC_UP,                  KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2,                                     KC_VOLD,    KC_MUTE,    KC_VOLU,                KC_VOLU,
  KC_LEFT,    _______,    KC_RIGHT,                                                                                                               KC_MPRV,    KC_MPLY,    KC_MNXT,
              KC_DOWN,                                                                                                                                        KC_VOLD
),


[_NAV] = LAYOUT_vulpes_majora( 
  XXXXXXX,    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_INS,                                         _______,    DF(_GAME),  _______,    DF(_QWERTY),_______,    XXXXXXX,
  XXXXXXX,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    CW_TOGG,                                        _______,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,
  XXXXXXX,    _______,    KC_PGDN,    KC_PGUP,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
                                      KC_DEL,     KC_BSPC,    KC_ENT,     _______,    _______,    _______,    _______,    _______,    _______,
              _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                _______,
  _______,    _______,    _______,                                                                                                                _______,    _______,    _______,
              _______,                                                                                                                                        _______
),

[_NUM] = LAYOUT_vulpes_majora(
  XXXXXXX,    _______,    _______,    _______,    _______,    _______,                                        KC_LBRC,    KC_7,       KC_8,       KC_9,       KC_RBRC,    XXXXXXX,
  XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,     EE_CLR,                                        KC_EQL,     KC_4,       KC_5,       KC_6,       KC_SCLN,    XXXXXXX,
  XXXXXXX,    KC_CAPS,    _______,    _______,    QK_RBT,     QK_BOOT,                                        KC_BSLS,    KC_1,       KC_2,       KC_3,       KC_GRV,     XXXXXXX,
                                      _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,    KC_0,       KC_DOT,  
              _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                _______,
  _______,    _______,    _______,                                                                                                                _______,    _______,    _______,
              _______,                                                                                                                                        _______
),

[_SYM] = LAYOUT_vulpes_majora(
  XXXXXXX,    _______,    _______,    _______,    _______,    _______,                                        KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,    XXXXXXX,
  XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    EE_CLR,                                         KC_PLUS,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_COLN,    XXXXXXX,
  XXXXXXX,    KC_CAPS,    _______,    _______,    QK_RBT,     QK_BOOT,                                        KC_PIPE,    KC_EXLM,    KC_AT,      KC_HASH,    KC_TILD,    XXXXXXX,
                                      _______,    _______,    _______,    _______,     _______,    _______,   KC_UNDS,    KC_LPRN,    KC_RPRN,
              _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                _______,
  _______,    _______,    _______,                                                                                                               _______,     _______,    _______,
              _______,                                                                                                                                        _______
),

[_BUTTON] = LAYOUT_vulpes_majora(
  XXXXXXX,    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,                                          U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,      XXXXXXX,
  XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    _______,                                        _______,    KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,    XXXXXXX,
  XXXXXXX,    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,                                          U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,      XXXXXXX,
                                      KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,
              DT_UP,                  _______,    _______,    _______,                                        _______,    _______,    _______,                S_DPI_U,
  _______,    DT_PRNT,    _______,                                                                                                                _______,    _______,    _______,
              DT_DOWN,                                                                                                                                        S_DPI_D
),


[_MEDIA] =  LAYOUT_vulpes_majora(
  XXXXXXX,    RGB_TOG,    RGB_RMOD,   RGB_MOD,    _______,    _______,                                        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      XXXXXXX,
  XXXXXXX,    RGB_SPI,    RGB_HUI,    RGB_SAI,    RGB_VAI,    _______,                                        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     XXXXXXX,
  XXXXXXX,    RGB_SPD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    _______,                                        KC_F11,     KC_F12,     _______,    QK_RBT,     QK_BOOT,    XXXXXXX,
                                      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
              _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                _______,
  _______,    _______,    _______,                                                                                                               _______,     _______,    _______,
              _______,                                                                                                                                        _______
), 

[_GAME] =  LAYOUT_vulpes_majora(
  XXXXXXX,    KC_T,       KC_Q,       KC_W,       KC_E,       KC_R,                                           KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,
  XXXXXXX,    KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,                                           KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,    XXXXXXX,
  XXXXXXX,    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,                                           KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                      GAMENUM,    KC_SPC,     NAV,        KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, ENT_FUN,    KC_BSPC,    KC_DEL,
              _______,                KC_ESC,     KC_ENT,     KC_TAB,                                         _______,    DF(_QWERTY),  _______,                KC_UP,
  _______,    _______,    _______,                                                                                                                KC_LEFT,    _______,    KC_RIGHT,
              KC_LALT,                                                                                                                                        KC_DOWN
), 

[_GAMENUM] =  LAYOUT_vulpes_majora(
  XXXXXXX,    KC_LBRC,    KC_7,      KC_8,        KC_9,       KC_RBRC,                                         _______,    _______,    _______,    _______,    _______,    XXXXXXX,
  XXXXXXX,    KC_SCLN,    KC_4,      KC_5,        KC_6,       KC_EQL,                                          _______,    KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,    XXXXXXX,
  XXXXXXX,    KC_GRV,     KC_1,      KC_2,        KC_3,       KC_BSLS,                                         _______,    _______,    _______,    _______,    _______,    XXXXXXX,
                                     _______,     _______,    _______,    _______,     _______,    _______,    _______,    _______,    _______,
              _______,               _______,     _______,    _______,                                         _______,    _______,    _______,                KC_UP,
  _______,    _______,    _______,                                                                                                                    KC_LEFT, _______, KC_RIGHT,
              _______,                                                                                                                                         KC_DOWN
),

[_FUN] =  LAYOUT_vulpes_majora(
  XXXXXXX,    KC_F12,     KC_F7,      KC_F8,      KC_F9,      KC_PSCR,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
  XXXXXXX,    KC_F11,     KC_F4,      KC_F5,      KC_F6,      KC_SCRL,                                        _______,    KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,    XXXXXXX,
  XXXXXXX,    KC_F10,     KC_F1,      KC_F2,      KC_F3,      KC_PAUS,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
                                      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
              _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                  KC_UP,
  _______,    _______,    _______,                                                                                                                KC_LEFT,    _______,    KC_RIGHT, 
              _______,                                                                                                                                        KC_DOWN
)

// [BLANK] = LAYOUT_vulpes_majora(
//   XXXXXXX,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
//   XXXXXXX,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
//   XXXXXXX,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX,
//                                       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
//               _______,                _______,    _______,    _______,                                        _______,    _______,    _______,                _______,
//   _______,    _______,    _______,                                                                                                                _______,    _______,    _______, 
//               _______,                                                                                                                                        _______
// ),

};

//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _NUM, _NAV, _ADJUST);
//}

// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_GUI, BSP_NUM, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    &delete_key_override,
    NULL
};

enum combo_events {
    BSPC_COMBO,
    DRGSCRL_COMBO,
    RF_LPRN,
    UJ_RPRN,
    DE_LBRC,
    KI_RBRC,
    WS_LCBR,
    OL_RCBR,
    FG_UNDS,
    RF_G,
    FV_B,
    GAMING_ZERO,
    GAMING_RSFT,
    GAMING_RCTL,
    GAMING_RALT,
//    GAMING_ESC,
//    GAMING_TAB,
};


const uint16_t PROGMEM bspc_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM drgscrl_combo[] = {KC_N, KC_H, COMBO_END};
// base stuff
const uint16_t PROGMEM rf_lprn[] = {KC_R, HOME_F, COMBO_END};
const uint16_t PROGMEM uj_rprn[] = {KC_U, HOME_J, COMBO_END};
const uint16_t PROGMEM de_lbrc[] = {HOME_D, KC_E, COMBO_END};
const uint16_t PROGMEM ki_rbrc[] = {HOME_K, KC_I, COMBO_END};
const uint16_t PROGMEM ws_lcbr[] = {KC_W, HOME_S, COMBO_END};
const uint16_t PROGMEM ol_rcbr[] = {KC_O, HOME_L, COMBO_END};
const uint16_t PROGMEM fg_unds[] = {HOME_F, KC_G, COMBO_END};
// gaming
const uint16_t PROGMEM rf_g[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM fv_b[] = {KC_V, KC_F, COMBO_END};
const uint16_t PROGMEM gaming_zero[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM gaming_rsft[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM gaming_rctl[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM gaming_ralt[] = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM gaming_esc[] = {KC_T, KC_Q, COMBO_END};
//const uint16_t PROGMEM gaming_tab[] = {MO(_NAV), KC_SPC, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
  [DRGSCRL_COMBO] = COMBO(drgscrl_combo, FP_SCROLL_MOMENT),
  // base stuff
  [RF_LPRN] = COMBO(rf_lprn, KC_LPRN),
  [UJ_RPRN] = COMBO(uj_rprn, KC_RPRN),
  [DE_LBRC] = COMBO(de_lbrc, KC_LBRC),
  [KI_RBRC] = COMBO(ki_rbrc, KC_RBRC),
  [WS_LCBR] = COMBO(ws_lcbr, KC_LCBR),
  [OL_RCBR] = COMBO(ol_rcbr, KC_RCBR),
  [FG_UNDS] = COMBO(fg_unds, KC_UNDS),
  // gaming stuff
  [GAMING_ZERO] = COMBO(gaming_zero, KC_0),
  [RF_G] = COMBO(rf_g, KC_G),
  [FV_B] = COMBO(fv_b, KC_B),
  [GAMING_RSFT] = COMBO(gaming_rsft, KC_RSFT),
  [GAMING_RCTL] = COMBO(gaming_rctl, KC_RCTL),
  [GAMING_RALT] = COMBO(gaming_ralt, KC_RALT),
//  [GAMING_ESC] = COMBO(gaming_esc, KC_ESC),
//  [GAMING_TAB] = COMBO(gaming_tab, KC_TAB),
};


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  //disable and enable some left hand combos when on game layer 
    switch (combo_index) {
        case RF_LPRN ... FG_UNDS:
            if (layer_state_is(_GAME)) {
                return false;
            }
    }
    return true;
}

//#ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
//layer_state_t layer_state_set_kb(layer_state_t state) {
//  state = layer_state_set_user(state);
//  charybdis_set_pointer_sniping_enabled(
//      layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
//  return state;
//}
//#endif  // CHARYBDIS_AUTO_SNIPING_ON_LAYER

// achordion
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case BSP_NUM:
        case TAB_SYM:
        case ENT_FUN:
        case SPC_NAV:
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
