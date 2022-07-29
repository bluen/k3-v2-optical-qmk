/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Pablo Ramirez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "keymap_user.h"
#include "keymap_german_osx.h"
#include "rgb_matrix_user.h"

enum {
  TD_0,
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7
};

qk_tap_dance_action_t tap_dance_actions[] = {};


#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_SNIP LGUI(LSFT(KC_S))    // Windows snip tool

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Mac base layout
    +------------------------------------------------------------------------------+
    | ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|PSCR|DEL|RMOD|
    +------------------------------------------------------------------------------+
    |  ~ |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |PGUP|
    +------------------------------------------------------------------------------+
    |  TAB |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |      |PGDN|
    +-------------------------------------------------------------------  RET -----+
    |CAPSLCK|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  # |     |HOME|
    +------------------------------------------------------------------------------+
    |LSHFT|  \ |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSHIFT| UP | END|
    +------------------------------------------------------------------------------+
    |LCTRL| LALT| LGUI|            SPACE            | RALT| FN |RCTL|LEFT|DOWN|RGHT|
    +------------------------------------------------------------------------------+
*/
  [MAC_BASE] = LAYOUT_75_iso(
  /*  0          1          2          3        4        5        6         7        8        9          10          11          12         13         14         15        */
      KC_ESC,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   RGB_VAD, RGB_VAI,  KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,     KC_F12,    KC_MSNP,   KC_DEL,    KC_F19    ,
      DE_CIRC,   DE_1,      DE_2,      DE_3,    DE_4,    DE_5,    DE_6,     DE_7,    DE_8,    DE_9,      DE_0,       DE_SS,      DE_ACUT,   KC_BSPC,              KC_PGUP   ,
      KC_TAB,    DE_Q,      DE_W,      DE_E,    DE_R,    DE_T,    DE_Z,     DE_U,    DE_I,    DE_O,      DE_P,       DE_UDIA,    DE_PLUS,                         KC_PGDN   ,
      KC_CAPS,   DE_A,      DE_S,      DE_D,    DE_F,    DE_G,    DE_H,     DE_J,    DE_K,    DE_L,      DE_ODIA,    DE_ADIA,    DE_HASH,   KC_ENT,               KC_HOME   ,
      KC_LSFT,   DE_LABK,   DE_Y,      DE_X,    DE_C,    DE_V,    DE_B,     DE_N,    DE_M,    DE_COMM,   DE_DOT,     DE_MINS,               KC_RSFT,   KC_UP,     KC_END    ,
      KC_LCTL, OSM(MOD_LALT), KC_LGUI,                              KC_SPC,                              KC_RGUI,   MO(MAC_FN),  KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT
  ),

/*  Mac Fn overlay
    +------------------------------------------------------------------------------+
    | RST|BRID|BRIU|MCTL|LPAD|RVAD|RVAI|MPRV|MPLY|MNXT|MUTE|VOLD|VOLU|MSNP|INS|RTOG|
    +------------------------------------------------------------------------------+
    |    |    |    |    |    |    |    |    |    |    |    |    |    |        |RM_P|
    +------------------------------------------------------------------------------+
    |      |    |    |    |    |    |    |    |    |    |    |    |    |      |    |
    +-------------------------------------------------------------------      -----+
    |       |    |    |    |    |    |    |    |    |    |    |    |    |     |    |
    +------------------------------------------------------------------------------+
    |     |    |    |    |    |    |    |    |    |    |    |    |       |RSAI|    |
    +------------------------------------------------------------------------------+
    |     |     |     |                             |     |    |    |RHUD|RSAD|RHUI|
    +------------------------------------------------------------------------------+
*/
  [MAC_FN] = LAYOUT_75_iso(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15         */
      RESET,      KC_BRID,    KC_BRIU,    KC_MSSN,    KC_FIND,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MSCR,    KC_INS,     RGB_TOG    ,
      _______,    DM_REC1,    DM_REC2,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                RGB_MOD    ,
      _______,    DM_PLY1,    DM_PLY2,    _______, EEPROM_RESET,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            RGB_RMOD   ,
      _______,    KC_ASTG,    KC_ASUP,    KC_ASDN,    KC_ASRP,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                RGB_SPI    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,  MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO,  _______,    _______,    _______,     _______,    RGB_SAI,    RGB_SPD    ,
      _______,    _______,    OSM(MOD_HYPR),                                  _______,                                 OSM(MOD_HYPR),_______,OSM(MOD_MEH),   RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

/*  Windows base layout
    +------------------------------------------------------------------------------+
    | ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|PSCR|DEL|RMOD|
    +------------------------------------------------------------------------------+
    |  ~ |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |PGUP|
    +------------------------------------------------------------------------------+
    |  TAB |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |      |PGDN|
    +-------------------------------------------------------------------  RET -----+
    |CAPSLCK|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  # |     |HOME|
    +------------------------------------------------------------------------------+
    |LSHFT|  \ |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSHIFT| UP | END|
    +------------------------------------------------------------------------------+
    |LCTRL| LGUI| LALT|            SPACE            | RALT| FN |RCTL|LEFT|DOWN|RGHT|
    +------------------------------------------------------------------------------+
*/
  [WIN_BASE] = LAYOUT_75_iso(
  /*  0          1          2          3        4        5        6         7        8        9          10          11          12         13         14         15        */
      KC_ESC,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,     KC_F12,    KC_PSCR,   KC_DEL,    RGB_MOD   ,
      KC_GRV,    KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,       KC_MINS,    KC_EQL,    KC_BSPC,              KC_PGUP   ,
      KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                         KC_PGDN   ,
      KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,    KC_QUOT,    KC_NUHS,   KC_ENT,               KC_HOME   ,
      KC_LSFT,   KC_NUBS,   KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,               KC_RSFT,   KC_UP,     KC_END    ,
      KC_LCTL,   KC_LGUI,   KC_LALT,                              KC_SPC,                                KC_RALT,    MO(WIN_FN), KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT
  ),

/*  Windows Fn overlay
    +------------------------------------------------------------------------------+
    | RST|BRID|BRIU|TASK|FLXP|RVAD|RVAI|MPRV|MPLY|MNXT|MUTE|VOLD|VOLU|    |INS|RTOG|
    +------------------------------------------------------------------------------+
    |    |    |    |    |    |    |    |    |    |    |    |    |    |        |RM_P|
    +------------------------------------------------------------------------------+
    |      |    |    |    |    |    |    |    |    |    |    |    |    |      |    |
    +-------------------------------------------------------------------      -----+
    |       |    |    |    |    |    |    |    |    |    |    |    |    |     |    |
    +------------------------------------------------------------------------------+
    |     |    |    |    |    |    |    |    |    |    |    |    |       |RSAI|    |
    +------------------------------------------------------------------------------+
    |     |     |     |                             |     |    |    |RHUD|RSAD|RHUI|
    +------------------------------------------------------------------------------+
*/
  [WIN_FN] = LAYOUT_75_iso(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15         */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                RGB_M_P    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______    ,
      _______,    _______,    _______,    _______,    _______,    _______, MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______    ,
      _______,    _______,    _______,                                        EEPROM_RESET,                                   _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),
};

bool dip_switch_update_user(uint8_t index, bool active) {
  switch(index) {
    case 0: // OS switch
      if (active) { // Mac/iOS mode
        layer_move(MAC_BASE);
      }
      else { // Windows/Android mode
        layer_move(WIN_BASE);
      }
      break;
    case 1: // Connection switch
      // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
      if (active) { // BT mode
        // do stuff
      }
      else { //Cable mode
        // do stuff
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable = true;
  // debug_matrix = true;
  // debug_keyboard = true;
  // debug_mouse = true;
}

void matrix_init_user(void) {
    rgb_matrix_init_user();
}

