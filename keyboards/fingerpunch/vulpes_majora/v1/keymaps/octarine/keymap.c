#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _ADJUST,
    _MOUSE,
    _NAV,
    _NUM,
    _SYM,
    _BUTTON
};

#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define BUTTON MO(_BUTTON)


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
  _______,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                KC_Y,    KC_U,KC_I,KC_O,KC_P,_______,
  _______, HOME_A,   HOME_S, HOME_D, HOME_F, KC_G,                                                      KC_H,    HOME_J, HOME_K, HOME_L, HOME_QUOT,  _______,
  _______, BU_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          _______,
                                     KC_ESC,        LT(NUM,KC_BSPC),       LT(SYM,KC_TAB),        KC_MS_BTN3,     KC_MS_BTN1,   KC_MS_BTN2,    KC_ENT,   LT(NAV,KC_SPC),       KC_DEL,
           KC_VOLU,                  KC_MS_BTN1,     KC_MS_BTN3,   KC_MS_BTN2,                                                KC_VOLD, KC_MUTE,      KC_VOLU,                    KC_VOLU,
  KC_MPRV, KC_MPLY, KC_MNXT,                                                                                                                                            KC_MPRV, KC_MPLY, KC_MNXT,
           KC_VOLD,                                                                                                                                                              KC_VOLD
),


[_NAV] = LAYOUT_vulpes_majora(
  _______,  KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS,                                _______, _______, _______, _______, _______, _______,
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG,                              _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______, _______, KC_PGDN, KC_PGUP, _______, _______,                             _______, _______, _______, _______, _______, _______,
                             KC_DEL, KC_BSPC, KC_ENT,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_NUM] = LAYOUT_vulpes_majora(
  _______, _______, _______, _______, _______, _______,                             KC_LBRC, KC_7, KC_8, KC_9,  KC_RBRC,  _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  EE_CLR,                             KC_EQL,  KC_4, KC_5, KC_6,  KC_SCLN,  _______,
  _______, KC_CAPS, _______, _______, QK_RBT,  QK_BOOT,                             KC_BSLS, KC_1, KC_2, KC_3,  KC_GRV,   _______,
                             _______, _______, _______,  _______, _______, _______, KC_MINS, KC_0, KC_DOT,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_SYM] = LAYOUT_vulpes_majora(
  _______, _______, _______, _______, _______, _______,                             KC_LCBR, KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,  _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  EE_CLR,                             KC_PLUS, KC_DLR,   KC_PERC,  KC_CIRC,  KC_COLN,  _______,
  _______, KC_CAPS, _______, _______, QK_RBT,  QK_BOOT,                             KC_PIPE, KC_EXLM,  KC_AT,    KC_HASH,  KC_TILD,  _______,
                             _______, _______, _______,  _______, _______, _______, KC_UNDS, KC_LPRN, KC_RPRN,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_BUTTON] = LAYOUT_vulpes_majora(
  _______, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                             U_RDO,  U_PST,   U_CPY,   U_CUT,   U_UND,  _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                           _______,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  _______,
  _______, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                             U_RDO,  U_PST,   U_CPY,   U_CUT,   U_UND,  _______,
                             KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,  _______, _______, _______, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),


[_ADJUST] =  LAYOUT_vulpes_majora(
  _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______,                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, _______,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,                             KC_F11,  KC_F12,  _______, _______, QK_BOOT, _______,
                              _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,           _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                    _______, _______, _______,
           _______,                                                                                                      _______
), 

[_MOUSE] =  LAYOUT_vulpes_majora(
  _______, _______, KC_WH_U, _______, KC_WH_D, _______,                             _______, _______, _______, _______, _______, _______,
  _______, KC_WH_L, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_R,                             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _ADJUST);
}
