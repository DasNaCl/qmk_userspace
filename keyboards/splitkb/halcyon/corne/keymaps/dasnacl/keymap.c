/* SPDX-License-Identifier: GPL-2.0-or-later */
#include QMK_KEYBOARD_H
#if __has_include("config.h")
#  include "config.h"
#endif
#if __has_include("keymap.h")
#  include "keymap.h"
#endif

#include <keymap_german.h>

enum unicode_names {
  // greek
  LOWER_ALPHA,
  LOWER_BETA,
  LOWER_GAMMA,
  UPPER_GAMMA,
  LOWER_DELTA,
  UPPER_DELTA,
  LOWER_EPSILON,
  LOWER_ETA,
  LOWER_THETA,
  UPPER_THETA,
  LOWER_LAMBDA,
  UPPER_LAMBDA,
  LOWER_MU,
  LOWER_NU,
  LOWER_PI,
  UPPER_PI,
  LOWER_RHO,
  LOWER_SIGMA,
  UPPER_SIGMA,
  LOWER_TAU,
  LOWER_PHI,
  UPPER_PHI,
  LOWER_PSI,
  UPPER_PSI,
  LOWER_XI,
  UPPER_XI,
  LOWER_OMEGA,
  UPPER_OMEGA,
  // logic
  LOWER_AND,
  UPPER_AND,
  LOWER_OR,
  UPPER_OR,
  SUBSETS,
  SUPSETS,
  IN_EL,
  NI_EL,
  FORALL,
  EXISTS,
  VDASH,
  VDASHEQ,
  TOP,
  BOT,
  // computation
  CEIL_LEFT,
  CEIL_RIGHT,
  FLOOR_LEFT,
  FLOOR_RIGHT,
  SEMOP_LEFT,
  SEMOP_RIGHT,
  // fun
  LIGHTNING,
  BIOHAZARD,
};
const uint32_t PROGMEM unicode_map[] = {
  // greek
  [LOWER_ALPHA]   = 0x3B1, //α
  [LOWER_BETA]    = 0x3B2, //β
  [LOWER_GAMMA]   = 0x3B3, //γ
  [UPPER_GAMMA]   = 0x393, //Γ
  [LOWER_DELTA]   = 0x3B4, //δ
  [UPPER_DELTA]   = 0x394, //Δ
  [LOWER_EPSILON] = 0x3B5, //ε
  [LOWER_ETA]     = 0x3B7, //η
  [LOWER_THETA]   = 0x3B8, //θ
  [UPPER_THETA]   = 0x398, //Θ
  [LOWER_LAMBDA]  = 0x3BB, //λ
  [UPPER_LAMBDA]  = 0x39B, //Λ
  [LOWER_MU]      = 0x3BC, //μ
  [LOWER_NU]      = 0x3BD, //ν
  [LOWER_PI]      = 0x3C0, //π
  [UPPER_PI]      = 0x3A0, //Π
  [LOWER_RHO]     = 0x3C1, //ρ
  [LOWER_SIGMA]   = 0x3C3, //σ
  [UPPER_SIGMA]   = 0x3A3, //Σ
  [LOWER_TAU]     = 0x3C4, //τ
  [LOWER_PHI]     = 0x3C6, //φ
  [UPPER_PHI]     = 0x3A6, //Φ
  [LOWER_PSI]     = 0x3C8, //ψ
  [UPPER_PSI]     = 0x3A8, //Ψ
  [LOWER_XI]      = 0x3C7, //χ
  [UPPER_XI]      = 0x39E, //Ξ
  [LOWER_OMEGA]   = 0x3C9, //ω
  [UPPER_OMEGA]   = 0x3A9, //Ω
  //logic
  [LOWER_AND]     = 0x2227, //∧
  [UPPER_AND]     = 0x22C0, //⋀
  [LOWER_OR]      = 0x2228, //∨
  [UPPER_OR]      = 0x22C1, //⋁
  [SUBSETS]       = 0x2286, //⊆
  [SUPSETS]       = 0x2287, //⊇
  [IN_EL]         = 0x2208, //∈
  [NI_EL]         = 0x220B, //∋
  [FORALL]        = 0x2200, //∀
  [EXISTS]        = 0x2203, //∃
  [VDASH]         = 0x22A2, //⊢
  [VDASHEQ]       = 0x22A7, //⊧
  [TOP]           = 0x22A4, //⊤
  [BOT]           = 0x22A5, //⊥
  //computation
  [CEIL_LEFT]     = 0x2308, //⌈
  [CEIL_RIGHT]    = 0x2309, //⌉
  [FLOOR_LEFT]    = 0x230A, //⌊
  [FLOOR_RIGHT]   = 0x230B, //⌋
  [SEMOP_LEFT]    = 0x2987, //⦇
  [SEMOP_RIGHT]   = 0x2988, //⦈
  //fun
  [LIGHTNING]     = 0x26A1, //⚡
  [BIOHAZARD]     = 0x2623, //☣
};
#define UC_ALPHA       UP(LOWER_ALPHA, FORALL)
#define UC_BETA        UP(LOWER_BETA, BIOHAZARD)
#define UC_GAMMA       UP(LOWER_GAMMA, UPPER_GAMMA)
#define UC_DELTA       UP(LOWER_DELTA, UPPER_DELTA)
#define UC_EPSILON     UP(LOWER_EPSILON, EXISTS)
#define UC_ETA         UP(LOWER_ETA, IN_EL)
#define UC_THETA       UP(LOWER_THETA, UPPER_THETA)
#define UC_LAMBDA      UP(LOWER_LAMBDA, UPPER_LAMBDA)
#define UC_NU          UP(LOWER_NU, SEMOP_LEFT)
#define UC_MU          UP(LOWER_MU, LIGHTNING)
#define UC_OMEGA       UP(LOWER_OMEGA, UPPER_OMEGA)
#define UC_PI          UP(LOWER_PI, UPPER_PI)
#define UC_RHO         UP(LOWER_RHO, SEMOP_RIGHT)
#define UC_SIGMA       UP(LOWER_SIGMA, UPPER_SIGMA)
#define UC_TAU         UP(LOWER_TAU, TOP)
#define UC_PHI         UP(LOWER_PHI, UPPER_PHI)
#define UC_PSI         UP(LOWER_PSI, UPPER_PSI)
#define UC_XI          UP(LOWER_XI, UPPER_XI)
#define UC_AND         UP(LOWER_AND, UPPER_AND)
#define UC_OR          UP(LOWER_OR, UPPER_OR)
#define UC_SUBSUP      UP(SUBSETS, SUPSETS)
#define UC_VDASH       UP(VDASH, VDASHEQ)
#define UC_ROUNDL      UP(CEIL_LEFT, FLOOR_LEFT)
#define UC_ROUNDR      UP(CEIL_RIGHT, FLOOR_RIGHT)

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
        KC_ESC,       DE_X,       DE_V,       DE_L,       DE_C,       DE_W,                        DE_K,       DE_H,       DE_G,       DE_F,       DE_Q,      DE_SS,
        KC_TAB, USR_LCTL_U, LT(4,DE_I),       DE_A, USR_LGUI_E,       DE_O,                        DE_S, USR_RGUI_N,       DE_R, LT(4,DE_T), USR_RCTL_D,       DE_Y,
       XXXXXXX,    DE_UDIA,    DE_ODIA,    DE_ADIA,       DE_P,       DE_Z,                        DE_B,       DE_M,    DE_COMM,     DE_DOT,       DE_J,    KC_PSCR,
                                           SFTLLCK,   KC_SPACE, TD(TD_LYR),                  TD(TD_LYR),     KC_ENT,    SFTRLCK,                                     KC_MUTE,KC_NO,KC_NO,KC_NO,KC_NO, KC_MUTE,KC_NO,KC_NO,KC_NO,KC_NO),
  [1] = LAYOUT_corne_hlc(
       XXXXXXX,    DE_ACUT,    DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,                     DE_EXLM,    DE_LABK,    DE_RABK,     DE_EQL,    DE_AMPR,    XXXXXXX,
       XXXXXXX,    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,                     DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,      DE_AT,
       XXXXXXX,    DE_HASH,     DE_DLR,    DE_PIPE,    DE_TILD,     DE_GRV,                     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,    XXXXXXX,
                                             TT(3),    XXXXXXX,      TO(0),                       TO(0),    XXXXXXX,      TT(3),                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
  [2] = LAYOUT_corne_hlc(
       XXXXXXX,       DE_7,       DE_6,       DE_5,       DE_4,    XXXXXXX,                      KC_F11,      KC_F7,      KC_F6,      KC_F5,      KC_F4,     KC_F10,
          DE_8,       DE_0,       DE_1,       DE_2,       DE_3,       DE_9,                       KC_F8,  QK_LEADER,      KC_F1,      KC_F2,      KC_F3,      KC_F9,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                      KC_F12,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KC_BRID,    KC_BRIU,
                                             MO(3),    KC_LGUI,      TO(0),                       TO(0),    KC_RGUI,      MO(3),                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
  [3] = LAYOUT_corne_hlc(
       XXXXXXX,    XXXXXXX,    KC_BSPC,      KC_UP,  KC_DELETE,    XXXXXXX,                     MS_WHLU,    MS_BTN1,      MS_UP,    MS_BTN2,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,   KC_RIGHT,    XXXXXXX,                     MS_WHLD,    MS_LEFT,    MS_DOWN,    MS_RGHT,    XXXXXXX,    XXXXXXX,
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    MS_WHLL,    MS_BTN3,    MS_WHLR,    XXXXXXX,    XXXXXXX,
                                           XXXXXXX,      TO(0),    XXXXXXX,                     XXXXXXX,      TO(1),    XXXXXXX,                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
  [4] = LAYOUT_corne_hlc(
     UC_ROUNDL,      UC_XI,      UC_NU,  UC_LAMBDA,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,   UC_GAMMA,     UC_PHI,     UC_PSI,  UC_ROUNDR,
      UC_VDASH,    XXXXXXX,  UC_SUBSUP,   UC_ALPHA, UC_EPSILON,   UC_OMEGA,                    UC_SIGMA,    XXXXXXX,     UC_RHO,     UC_TAU,   UC_DELTA,    XXXXXXX,
       XXXXXXX,    XXXXXXX,     UC_AND,      UC_OR,      UC_PI,    XXXXXXX,                     UC_BETA,      UC_MU,     UC_ETA,    XXXXXXX,   UC_THETA,    XXXXXXX,
                                           SFTLLCK,      TO(0),    XXXXXXX,                     XXXXXXX,      TO(0),    SFTRLCK,                                     _______,_______,_______,_______,_______, _______,_______,_______,_______,_______),
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
    else if (leader_sequence_two_keys(KC_D, KC_D)) {
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
  .state = TD_NONE
};
// Functions that control what our tap dance key does
//
// Layers
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
  [TD_LYR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
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
