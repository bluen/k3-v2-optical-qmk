#pragma once

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  MAC_BASE = 0,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

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