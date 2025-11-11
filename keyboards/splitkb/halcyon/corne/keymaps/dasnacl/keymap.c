/* SPDX-License-Identifier: GPL-2.0-or-later */
#include QMK_KEYBOARD_H
#if __has_include("config.h")
#  include "config.h"
#endif
#if __has_include("keymap.h")
#  include "keymap.h"
#endif

#include <keymap_german.h>

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_TAP_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
  TD_LYR,
};
// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

#define USR_LCTL_U MT(MOD_LCTL, KC_U) // left control when hold, U when tapped
#define USR_RCTL_D MT(MOD_RCTL, KC_D) // right control when hold, D when tapped
#define USR_LGUI_E MT(MOD_LGUI, KC_E) // left gui when hold, E when tapped
#define USR_RGUI_N MT(MOD_RGUI, KC_N) // right gui when hold, N when tapped

#define SFTLLCK MT(MOD_LSFT,KC_0) // act as lshift on press, as layer lock on tap. KC_0 is placeholder
#define SFTRLCK MT(MOD_RSFT,KC_0) // act as rshift on press, as layer lock on tap. KC_0 is placeholder

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_corne_hlc(
       QK_LEAD,       DE_X,       DE_V,       DE_L,       DE_C,       DE_W,                        DE_K,       DE_H,       DE_G,       DE_F,       DE_Q,      DE_SS,
        KC_TAB, USR_LCTL_U,       DE_I,       DE_A, USR_LGUI_E,       DE_O,                        DE_S, USR_RGUI_N,       DE_R,       DE_T, USR_RCTL_D,       DE_Y,
       XXXXXXX,    DE_UDIA,    DE_ODIA,    DE_ADIA,       DE_P,       DE_Z,                        DE_B,       DE_M,    DE_COMM,     DE_DOT,       DE_J,    KC_PSCR,
                                           SFTLLCK,   KC_SPACE, TD(TD_LYR),                  TD(TD_LYR),     KC_ENT,    SFTRLCK,                                     KC_MUTE,KC_NO,KC_NO,KC_NO,KC_NO, KC_MUTE,KC_NO,KC_NO,KC_NO,KC_NO),
  [1] = LAYOUT_corne_hlc(
       XXXXXXX,    DE_ACUT,    DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,                     DE_EXLM,    DE_LABK,    DE_RABK,     DE_EQL,    DE_AMPR,    XXXXXXX,
       XXXXXXX,    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,                     DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,      DE_AT,
       XXXXXXX,    DE_HASH,     DE_DLR,    DE_PIPE,    DE_TILD,     DE_GRV,                     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,    XXXXXXX,
                                             TT(3),    XXXXXXX,      TO(0),                       TO(0),    XXXXXXX,      TT(3),                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
  [2] = LAYOUT_corne_hlc(
       XXXXXXX,       DE_7,       DE_6,       DE_5,       DE_4,    XXXXXXX,                      KC_F11,      KC_F7,      KC_F6,      KC_F5,      KC_F4,     KC_F10,
          DE_8,       DE_0,       DE_1,       DE_2,       DE_3,       DE_9,                       KC_F8,     KC_ESC,      KC_F1,      KC_F2,      KC_F3,      KC_F9,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                      KC_F12,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KC_BRID,    KC_BRIU,
                                             MO(3),    KC_LGUI,      TO(0),                       TO(0),    KC_RGUI,      MO(3),                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
  [3] = LAYOUT_corne_hlc(
       XXXXXXX,    XXXXXXX,    KC_BSPC,      KC_UP,  KC_DELETE,    XXXXXXX,                     MS_WHLU,    MS_BTN1,      MS_UP,    MS_BTN2,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,   KC_RIGHT,    XXXXXXX,                     MS_WHLD,    MS_LEFT,    MS_DOWN,    MS_RGHT,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    MS_WHLL,    MS_BTN3,    MS_WHLR,    XXXXXXX,    XXXXXXX,
                                           XXXXXXX,      TO(0),    XXXXXXX,                     XXXXXXX,      TO(1),    XXXXXXX,                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
    /*
  [*] = LAYOUT_corne_hlc(
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                           XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
    */
};

void leader_start_user(void) {
}
void leader_end_user(void) {
  /*
  if (leader_sequence_one_key(KC_F)) {
    // Leader, f => Types the below string
    SEND_STRING("QMK is awesome.");
  } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    // Leader, d, d => Ctrl+A, Ctrl+C
    SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
  } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
    // Leader, d, d, s => Types the below string
    SEND_STRING("https://start.duckduckgo.com\n");
  } else if (leader_sequence_two_keys(KC_A, KC_S)) {
    // Leader, a, s => GUI+S
    tap_code16(LGUI(KC_S));
  }
  */
}
layer_state_t layer_state_set_user(layer_state_t state) {
  /*
  switch (get_highest_layer(state)) {
  case _RAISE:
      rgblight_setrgb (0x00,  0x00, 0xFF);
      break;
  case _LOWER:
      rgblight_setrgb (0xFF,  0x00, 0x00);
      break;
  case _PLOVER:
      rgblight_setrgb (0x00,  0xFF, 0x00);
      break;
  case _ADJUST:
      rgblight_setrgb (0x7A,  0x00, 0xFF);
      break;
  default: //  for any other layers, or the default layer
      rgblight_setrgb (0x00,  0xFF, 0xFF);
      break;
  }*/
  return state;
}

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  } else if (state->count == 2) {
        if(!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_TAP_HOLD;
    }
  else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case TD_SINGLE_TAP:
      set_oneshot_layer(1, ONESHOT_START);
    break;
    case TD_SINGLE_HOLD:
      layer_on(3);
    break;
    case TD_DOUBLE_TAP:
      set_oneshot_layer(2, ONESHOT_START);
    break;
    case TD_DOUBLE_TAP_HOLD:
      layer_on(2);
    default:
    break;
  }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
      layer_off(3);
      reset_oneshot_layer();
    } else if (ql_tap_state.state == TD_DOUBLE_TAP_HOLD) {
      layer_off(2);
      reset_oneshot_layer();
    } else if (ql_tap_state.state == TD_SINGLE_TAP
            || ql_tap_state.state == TD_DOUBLE_TAP) {
      clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_LYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SFTLLCK:
    if (record->tap.count) {
      if (record->event.pressed) {
        // Toggle the lock on the highest layer.
        layer_lock_invert(get_highest_layer(layer_state));
      }
      return false;
    }
    break;
  }

  return true;
}


#ifdef OTHER_KEYMAP_C
#  include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
