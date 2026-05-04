#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE ZSA_SAFE_RANGE

extern rgb_config_t rgb_matrix_config;

enum modmap_indexes {
  MOD_MAIN = 0,
  MOD_RU = 1,
  MOD_MOUSE = 2,
  MOD_MOVE = 3,
  MOD_WINDOW = 4,
  MOD_WORKSPACE = 5,
  MOD_NUMBER = 6,
  MOD_CONFIG = 7,
  MOD_MUSIC = 8,
  MOD_SYMBOL = 9,
  MOD_GAME = 10,
  MOD_NO = 20,
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  SEND_PASSWORD,
  TO_MAIN,
  TO_SWITCH_MAIN,
  SYMBOL_MACRO_1,
  SYMBOL_MACRO_2,
  SYMBOL_MACRO_3,
  SYMBOL_MACRO_4,
  SYMBOL_MACRO_5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MOD_MAIN] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_X,                KC_Y,                KC_P,                KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_F,                KC_G,                KC_C,                KC_R,                KC_L,                KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_A,                KC_O,                KC_E,                KC_U,                KC_I,                KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_D,                KC_H,                KC_T,                KC_N,                KC_S,                KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_Q,                KC_J,                KC_K,                KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_B,                KC_M,                KC_W,                KC_V,                KC_Z,                KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ TO_SWITCH_MAIN,      TO(MOD_MOVE),        KC_SPACE
  ),

  [MOD_RU] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               RU_SCLN,             RU_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            RU_RPRN,             RU_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         RU_SHTI,             RU_TSE,              RU_U,                RU_IE,               RU_EF,               RU_EXLM,
    /* RIGHT */ RU_QUES,             RU_SHCH,             RU_GHE,              RU_TE,               RU_EN,               RU_ZE,               RU_HARD,

    // THREE
    /* LEFT  */ KC_TAB,              RU_KA,               RU_EM,               RU_VE,               RU_A,                RU_PE,               RU_MINS,
    /* RIGHT */ RU_DQUO,             RU_ER,               RU_O,                RU_EL,               RU_DE,               RU_ZHE,              RU_E,

    // FOUR
    /* LEFT  */ KC_SPACE,            RU_YA,               RU_CHE,              RU_ES,               RU_I,                RU_YERU,             /* EMPTY */
    /* RIGHT */ /* EMPTY */          RU_SHA,              RU_SOFT,             RU_BE,               RU_YU,               RU_HA,               RU_YO,

    // FIVE
    /* LEFT  */ RU_COMM,             TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      RU_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ TO_SWITCH_MAIN,      TO(MOD_MOVE),        KC_SPACE
  ),

  [MOD_WORKSPACE] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         LCTL(KC_Q),          LCTL(KC_W),          LCTL(KC_E),          LCTL(KC_R),          KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             LGUI(KC_7),          LGUI(KC_8),          LGUI(KC_9),          KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              LCTL(KC_A),          LCTL(KC_S),          LCTL(KC_D),          LCTL(KC_F),          KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            LGUI(KC_4),          LGUI(KC_5),          LGUI(KC_6),          KC_NO,               KC_NO,               KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            LCTL(KC_Z),          LCTL(KC_X),          LCTL(KC_C),          LCTL(KC_V),          LCTL(KC_SLASH),      /* EMPTY */
    /* RIGHT */ /* EMPTY */          LGUI(KC_1),          LGUI(KC_2),          LGUI(KC_3),          LGUI(KC_0),          KC_NO,               KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO_MAIN,             TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ LALT(KC_LEFT_GUI),   KC_NO,               KC_SPACE
  ),

  [MOD_WINDOW] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               LALT(LGUI(KC_H)),    LALT(LGUI(KC_J)),    LALT(LGUI(KC_K)),    LALT(LGUI(KC_L)),    KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              LGUI(KC_G),          LGUI(KC_S),          LGUI(KC_F),          LGUI(KC_D),          KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               LGUI(KC_H),          LGUI(KC_J),          LGUI(KC_K),          LGUI(KC_L),          KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               LALT(LGUI(LSFT(KC_H))),LALT(LGUI(LSFT(KC_J))),LALT(LGUI(LSFT(KC_K))),LALT(LGUI(LSFT(KC_L))),KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO_MAIN,             TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_NO,               KC_SPACE
  ),

  [MOD_SYMBOL] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_TILD,             KC_GRAVE,            KC_PERC,             KC_AT,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               KC_LBRC,             KC_RBRC,             SYMBOL_MACRO_1,      SYMBOL_MACRO_2,      KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_EQUAL,            KC_PIPE,             KC_AMPR,             KC_DLR,              KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               KC_LPRN,             KC_RPRN,             KC_LABK,             KC_RABK,             KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_CIRC,             KC_HASH,             KC_ASTR,             KC_BACKSLASH,        KC_SLASH,            /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_LCBR,             KC_RCBR,             SYMBOL_MACRO_3,      SYMBOL_MACRO_4,      KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO_MAIN,             /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_NO,               KC_SPACE
  ),

  [MOD_NUMBER] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_F12,              KC_F11,              KC_F10,              KC_F9,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_7,                KC_8,                KC_9,                KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_NO,               KC_F8,               KC_F7,               KC_F6,               KC_F5,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_4,                KC_5,                KC_6,                KC_NO,               KC_NO,               KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_F4,               KC_F3,               KC_F2,               KC_F1,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_1,                KC_2,                KC_3,                KC_0,                KC_NO,               KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO_MAIN,             TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_NO,               KC_SPACE
  ),

  [MOD_MUSIC] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    /* RIGHT */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // TWO
    /* LEFT  */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    /* RIGHT */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    /* RIGHT */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // FOUR
    /* LEFT  */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // FIVE
    /* LEFT  */ KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          MU_TOGG,
    /* RIGHT */ MU_NEXT,             /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // SIX
    /* LEFT  */ TOGGLE_LAYER_COLOR,  RGB_MODE_FORWARD,    RGB_TOG,
    /* RIGHT */ TO_MAIN,             KC_NO,               KC_NO
  ),

  [MOD_MOVE] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               KC_HOME,             KC_PGDN,             KC_PAGE_UP,          KC_END,              KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_H,                KC_J,                KC_K,                KC_L,                KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               TO_MAIN,             KC_SPACE
  ),

  [MOD_CONFIG] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               RGB_VAI,             KC_AUDIO_VOL_UP,     KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP,       KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               RGB_VAD,             KC_AUDIO_VOL_DOWN,   KC_NO,               KC_NO,               KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_SYSTEM_POWER,     KC_AUDIO_MUTE,       KC_NO,               QK_BOOT,             KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO(MOD_MOUSE),       TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO_MAIN,             KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_NO,               KC_SPACE
  ),

  [MOD_MOUSE] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_UP,            KC_MS_RIGHT,         KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_MS_WH_LEFT,       KC_MS_WH_DOWN,       KC_MS_WH_UP,         KC_MS_WH_RIGHT,      KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            TO_MAIN,             TO(MOD_GAME),        TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_MS_BTN4,          /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_MS_BTN3,          KC_MS_BTN1,          KC_MS_BTN2
  ),

  [MOD_GAME] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           KC_1,                KC_2,                KC_3,                KC_4,                KC_5,                KC_6,
    /* RIGHT */ KC_7,                KC_8,                KC_9,                KC_0,                KC_MINS,             KC_EQUAL,            KC_ESCAPE,

    // TWO
    /* LEFT  */ KC_NO,               KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                KC_NO,
    /* RIGHT */ KC_NO,               KC_Y,                KC_U,                KC_I,                KC_UP,               KC_P,                KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                KC_LALT,
    /* RIGHT */ KC_RALT,             KC_H,                KC_J,                KC_LEFT,             KC_DOWN,             KC_RIGHT,            KC_NO,

    // FOUR
    /* LEFT  */ KC_LEFT_SHIFT,       KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,                /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_N,                KC_M,                KC_COMM,             KC_DOT,              KC_SLASH,            KC_RIGHT_SHIFT,

    // FIVE
    /* LEFT  */ KC_LEFT_CTRL,        TO(MOD_MOUSE),       TO_MAIN,             TO(MOD_WORKSPACE),   TO(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_GUI,
    /* RIGHT */ KC_NO,               /* EMPTY */          TO(MOD_NUMBER),      TO(MOD_WINDOW),      TO(MOD_MUSIC),       TO(MOD_CONFIG),      KC_RIGHT_CTRL,

    // SIX
    /* LEFT  */ KC_SPACE,            KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_L,                KC_NO,               KC_NO
  ),
};

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} moon_rgb_t;

#define KEYCODE_LIST_SIZE(list) (sizeof(list) / sizeof((list)[0]))

static const uint16_t PROGMEM purple_keycodes[] = {
  LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R),
  LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_X), LCTL(KC_SLASH),
  LGUI(KC_0), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),
  LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_Z)
};

static const uint16_t PROGMEM gold_keycodes[] = {
  KC_SCLN, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, KC_QUOTE, KC_MINUS, KC_COMMA, KC_DOT,
  KC_TILD, KC_GRAVE, KC_PERC, KC_AT, KC_EXLM, KC_EQUAL, KC_PIPE, KC_AMPR, KC_DLR,
  KC_KP_PLUS, KC_CIRC, KC_HASH, KC_ASTR, KC_BACKSLASH, KC_SLASH, KC_LBRC, KC_RBRC,
  KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_MINS, KC_COMM, KC_SLSH, KC_QUOT, KC_GRV,
  SYMBOL_MACRO_1, SYMBOL_MACRO_2, SYMBOL_MACRO_3, SYMBOL_MACRO_4, SYMBOL_MACRO_5,
  RU_SCLN, RU_LPRN, RU_RPRN, RU_COLN, RU_EXLM, RU_QUES, RU_MINS, RU_DQUO, RU_COMM, RU_DOT
};

static const uint16_t PROGMEM ru_symbol_key_letters[] = {
  RU_BE, RU_YU, RU_HA, RU_YO, RU_ZHE, RU_E, RU_HARD
};

static const uint16_t PROGMEM green_keycodes[] = {
  KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, KC_HOME, KC_END, KC_PGDN, KC_PAGE_UP
};

static const uint16_t PROGMEM game_green_keycodes[] = {
  KC_W, KC_A, KC_S, KC_D
};

static const uint16_t PROGMEM springgreen_keycodes[] = {
  KC_LEFT_GUI, KC_LEFT_SHIFT, KC_BSPC, KC_ENTER, KC_SPACE, KC_TAB, KC_PSCR
};

static const uint16_t PROGMEM red_keycodes[] = {
  KC_ESCAPE, KC_LEFT_CTRL, KC_RIGHT_CTRL, KC_LALT, KC_RALT, SEND_PASSWORD, QK_BOOT, KC_SYSTEM_POWER,
  KC_AUDIO_MUTE, KC_MEDIA_STOP, RGB_TOG, MU_TOGG, MU_NEXT
};

static const uint16_t PROGMEM turquoise_keycodes[] = {
  KC_MS_LEFT, KC_MS_RIGHT, KC_MS_UP, KC_MS_DOWN, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_MS_WH_UP,
  KC_MS_WH_DOWN, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN4
};

static const uint16_t PROGMEM config_green_keycodes[] = {
  RGB_VAI, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE
};

static const uint16_t PROGMEM config_goldenrod_keycodes[] = {
  RGB_VAD, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK
};

static bool keycode_in_list(uint16_t keycode, const uint16_t *list, uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    if (keycode == pgm_read_word(&list[i])) {
      return true;
    }
  }

  return false;
}

static uint16_t base_keycode(uint16_t keycode) {
  if (IS_QK_MODS(keycode)) {
    return QK_MODS_GET_BASIC_KEYCODE(keycode);
  }

  return keycode;
}

static moon_rgb_t layer_accent_color(uint8_t layer) {
  switch (layer) {
    case MOD_RU:
      return (moon_rgb_t){RGB_CORAL};
    case MOD_WORKSPACE:
      return (moon_rgb_t){RGB_PURPLE};
    case MOD_WINDOW:
      return (moon_rgb_t){RGB_ORANGE};
    case MOD_SYMBOL:
      return (moon_rgb_t){RGB_GOLD};
    case MOD_NUMBER:
      return (moon_rgb_t){RGB_CYAN};
    case MOD_MUSIC:
      return (moon_rgb_t){RGB_BLUE};
    case MOD_MOVE:
      return (moon_rgb_t){RGB_GREEN};
    case MOD_CONFIG:
      return (moon_rgb_t){RGB_RED};
    case MOD_MOUSE:
      return (moon_rgb_t){RGB_TURQUOISE};
    case MOD_GAME:
      return (moon_rgb_t){RGB_BLUE};
    default:
      return (moon_rgb_t){RGB_WHITE};
  }
}

static moon_rgb_t layer_switch_color(uint8_t target_layer) {
  switch (target_layer) {
    case MOD_MAIN:
    case MOD_RU:
      return (moon_rgb_t){RGB_WHITE};
    case MOD_MOUSE:
      return (moon_rgb_t){RGB_TURQUOISE};
    case MOD_GAME:
      return (moon_rgb_t){RGB_GOLDENROD};
    case MOD_WORKSPACE:
      return (moon_rgb_t){RGB_PURPLE};
    case MOD_SYMBOL:
      return (moon_rgb_t){RGB_GOLD};
    case MOD_NUMBER:
      return (moon_rgb_t){RGB_CYAN};
    case MOD_WINDOW:
      return (moon_rgb_t){RGB_ORANGE};
    case MOD_MUSIC:
      return (moon_rgb_t){RGB_BLUE};
    case MOD_CONFIG:
      return (moon_rgb_t){RGB_RED};
    case MOD_MOVE:
      return (moon_rgb_t){RGB_GREEN};
    default:
      return (moon_rgb_t){RGB_BLACK};
  }
}

static moon_rgb_t keycode_color(uint8_t layer, uint16_t keycode) {
  if (keycode == KC_NO || keycode == KC_TRANSPARENT) {
    return (moon_rgb_t){RGB_BLACK};
  }

  if (keycode == TO_MAIN || keycode == TO_SWITCH_MAIN) {
    return layer_switch_color(MOD_MAIN);
  }

  if (IS_QK_TO(keycode)) {
    return layer_switch_color(QK_TO_GET_LAYER(keycode));
  }

  if (layer == MOD_RU && keycode_in_list(keycode, ru_symbol_key_letters, KEYCODE_LIST_SIZE(ru_symbol_key_letters))) {
    return layer_accent_color(layer);
  }

  if (keycode_in_list(keycode, red_keycodes, KEYCODE_LIST_SIZE(red_keycodes))) {
    return (moon_rgb_t){RGB_RED};
  }
  if (keycode_in_list(keycode, springgreen_keycodes, KEYCODE_LIST_SIZE(springgreen_keycodes))) {
    return (moon_rgb_t){RGB_SPRINGGREEN};
  }
  if (keycode_in_list(keycode, purple_keycodes, KEYCODE_LIST_SIZE(purple_keycodes))) {
    return (moon_rgb_t){RGB_PURPLE};
  }
  if (keycode_in_list(keycode, gold_keycodes, KEYCODE_LIST_SIZE(gold_keycodes))) {
    return (moon_rgb_t){RGB_GOLD};
  }
  if (keycode_in_list(keycode, green_keycodes, KEYCODE_LIST_SIZE(green_keycodes))) {
    return (moon_rgb_t){RGB_GREEN};
  }
  if (layer == MOD_GAME && keycode_in_list(keycode, game_green_keycodes, KEYCODE_LIST_SIZE(game_green_keycodes))) {
    return (moon_rgb_t){RGB_GREEN};
  }
  if (keycode_in_list(keycode, turquoise_keycodes, KEYCODE_LIST_SIZE(turquoise_keycodes))) {
    return (moon_rgb_t){RGB_TURQUOISE};
  }
  if (keycode_in_list(keycode, config_green_keycodes, KEYCODE_LIST_SIZE(config_green_keycodes))) {
    return (moon_rgb_t){RGB_GREEN};
  }
  if (keycode_in_list(keycode, config_goldenrod_keycodes, KEYCODE_LIST_SIZE(config_goldenrod_keycodes))) {
    return (moon_rgb_t){RGB_GOLDENROD};
  }

  uint16_t basic = base_keycode(keycode);

  if (KC_1 <= basic && basic <= KC_0) {
    return (moon_rgb_t){RGB_CYAN};
  }
  if (KC_F1 <= basic && basic <= KC_F12) {
    return (moon_rgb_t){RGB_CYAN};
  }

  if (IS_QK_MODS(keycode)) {
    return layer_accent_color(layer);
  }

  if (KC_A <= basic && basic <= KC_Z) {
    return layer_accent_color(layer);
  }

  return layer_accent_color(layer);
}

static void matrix_set_key_color(uint8_t layer, uint8_t row, uint8_t col) {
  uint8_t led_index = g_led_config.matrix_co[row][col];

  if (led_index == NO_LED) {
    return;
  }

  uint16_t keycode = pgm_read_word(&keymaps[layer][row][col]);
  moon_rgb_t color = keycode_color(layer, keycode);

  rgb_matrix_set_color(led_index, color.r, color.g, color.b);
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
      matrix_set_key_color(layer, row, col);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control || keyboard_config.disable_layer_led) {
    return false;
  }

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  } else {
    set_layer_color(biton32(layer_state));
  }

  return true;
}

bool is_en_lang_current = true;
bool is_en_lang_temp = true;

void switch_language_os(void) {
  register_code(KC_LSFT);
  tap_code(KC_LALT);
  unregister_code(KC_LSFT);
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!is_en_lang_temp && get_highest_layer(layer_state) != MOD_RU) {
    is_en_lang_temp = !is_en_lang_temp;

    switch_language_os();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TO_MAIN:
      if (record->event.pressed) {
        if (is_en_lang_current != is_en_lang_temp) {
          is_en_lang_temp = is_en_lang_current;

          switch_language_os();
        }

        if (is_en_lang_current) {
          layer_move(MOD_MAIN);
        } else {
          layer_move(MOD_RU);
        }
      }

      return false;
    case TO_SWITCH_MAIN:
      if (record->event.pressed) {
        switch_language_os();

        is_en_lang_current = !is_en_lang_current;
        is_en_lang_temp = is_en_lang_current;

        if (is_en_lang_current) {
          layer_move(MOD_MAIN);
        } else {
          layer_move(MOD_RU);
        }
      }

      return false;
    case SEND_PASSWORD:
      if (record->event.pressed) {
        SEND_STRING("32" SS_TAP(X_ENTER));
      }

      break;
    case SYMBOL_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_NUBS)));
      }

      break;
    case SYMBOL_MACRO_2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_NUBS)));
      }

      break;
    case SYMBOL_MACRO_3:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_NUBS) SS_DELAY(100) SS_TAP(X_EQUAL));
      }

      break;
    case SYMBOL_MACRO_4:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_NUBS)) SS_DELAY(100) SS_TAP(X_EQUAL));
      }

      break;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }

        if (record->event.pressed) {
            rgblight_mode(1);
        }

        return false;
  }

  return true;
}
