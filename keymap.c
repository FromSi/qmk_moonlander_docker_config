#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL

extern rgb_config_t rgb_matrix_config;

enum modmap_indexes {
  MOD_NO = 20,
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
};

enum colormaps {
  COLOR_BLACK = 0,
  COLOR_WHITE,
  COLOR_GREY,
  COLOR_RED,
  COLOR_GOLDENROD,
  COLOR_GOLD,
  COLOR_GREEN,
  COLOR_PINK,
  COLOR_PURPLE,
  COLOR_TURQUOISE,
  COLOR_CYAN,
  COLOR_SPRINGGREEN,
  COLOR_BLUE,
  COLOR_CORAL,
  COLOR_ORANGE,
};

const uint8_t PROGMEM colormap[][3] = {
  [COLOR_BLACK] = {0, 0, 0},
  [COLOR_WHITE] = {0, 0, 255},
  [COLOR_GREY] = {0, 0, 136},
  [COLOR_RED] = {0, 255, 255},
  [COLOR_GOLDENROD] = {30, 218, 218},
  [COLOR_GOLD] = {36, 255, 255},
  [COLOR_GREEN] = {85, 255, 255},
  [COLOR_PINK] = {234, 128, 255},
  [COLOR_PURPLE] = {191, 255, 255},
  [COLOR_TURQUOISE] = {123,  90, 112},
  [COLOR_CYAN] = {128, 255, 255},
  [COLOR_SPRINGGREEN] = {106, 255, 255},
  [COLOR_BLUE] = {170, 255, 255},
  [COLOR_CORAL] = {11, 176, 255},
  [COLOR_ORANGE] = {21, 255, 255},
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  SWITCH_MOD_MAIN,
  SWITCH_MOD_RU,
  SEND_PASSWORD,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
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
    /* LEFT  */ KC_COMMA,            TG(MOD_MOUSE),       TG(MOD_GAME),        TG(MOD_WORKSPACE),   TG(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TG(MOD_NUMBER),      TG(MOD_WINDOW),      TO(MOD_MUSIC),       TG(MOD_CONFIG),      KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ SWITCH_MOD_RU,       TG(MOD_MOVE),        KC_SPACE
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
    /* LEFT  */ RU_COMM,             TG(MOD_MOUSE),       TG(MOD_GAME),        TG(MOD_WORKSPACE),   TG(MOD_SYMBOL),      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          TG(MOD_NUMBER),      TG(MOD_WINDOW),      TO(MOD_MUSIC),       TG(MOD_CONFIG),      RU_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ SWITCH_MOD_MAIN,       TG(MOD_MOVE),        KC_SPACE
  ),

  [MOD_WORKSPACE] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         LCTL(KC_Q),          LCTL(KC_W),          LCTL(KC_E),          LCTL(KC_R),          KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               LGUI(KC_5),          LGUI(KC_6),          LGUI(KC_7),          KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              LCTL(KC_A),          LCTL(KC_S),          LCTL(KC_D),          LCTL(KC_F),          LALT(KC_D),          KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               LGUI(KC_1),          LGUI(KC_2),          LGUI(KC_3),          LGUI(KC_4),          KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            LCTL(KC_Z),          LCTL(KC_X),          LCTL(KC_C),          LCTL(KC_V),          LCTL(KC_SLASH),      /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               LGUI(KC_8),          LGUI(KC_9),          LGUI(KC_0),          KC_NO,               KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            KC_NO,               KC_NO,               KC_TRANSPARENT,      KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_DOT,

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
    /* LEFT  */ KC_TAB,              LGUI(KC_G),          LGUI(KC_S),          LGUI(KC_F),          LGUI(KC_D),          LGUI(KC_Z),          KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               LGUI(KC_H),          LGUI(KC_J),          LGUI(KC_K),          LGUI(KC_L),          KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               LALT(LGUI(LSFT(KC_H))),LALT(LGUI(LSFT(KC_J))),LALT(LGUI(LSFT(KC_K))),LALT(LGUI(LSFT(KC_L))),KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_NO,               KC_TRANSPARENT,      KC_NO,               KC_NO,               KC_DOT,

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
    /* RIGHT */ KC_QUES,             KC_NO,               KC_LBRC,             KC_RBRC,             ST_MACRO_1,          ST_MACRO_2,          KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_EQUAL,            KC_PIPE,             KC_AMPR,             KC_DLR,              KC_KP_PLUS,          KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               KC_LPRN,             KC_RPRN,             KC_LABK,             KC_RABK,             KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_CIRC,             KC_HASH,             KC_ASTR,             KC_SLASH,            KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_LCBR,             KC_RCBR,             ST_MACRO_3,          ST_MACRO_4,          KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            KC_NO,               KC_NO,               KC_NO,               KC_TRANSPARENT,      /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_NO,               KC_SPACE
  ),

  [MOD_NUMBER] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_F8,               KC_F7,               KC_F6,               KC_F5,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             KC_NO,               KC_4,                KC_5,                KC_6,                KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_F4,               KC_F3,               KC_F2,               KC_F1,               KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_NO,               KC_1,                KC_2,                KC_3,                KC_0,                KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_F12,              KC_F11,              KC_F10,              KC_F9,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_NO,               KC_7,                KC_8,                KC_9,                KC_NO,               KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            RU_COMM,             KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_TRANSPARENT,      KC_NO,               KC_NO,               RU_DOT,              KC_DOT,

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
    /* RIGHT */ TO(MOD_MAIN),          KC_NO,               KC_NO
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
    /* LEFT  */ KC_COMMA,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_DOT,

    // SIX
    /* LEFT  */ KC_LEFT_SHIFT,       KC_BSPC,             KC_ENTER,
    /* RIGHT */ KC_NO,               KC_TRANSPARENT,      KC_SPACE
  ),

  [MOD_CONFIG] = LAYOUT_moonlander(
    // ONE
    /* LEFT  */ KC_ESCAPE,           LCTL(KC_Z),          KC_NO,               KC_SCLN,             KC_LPRN,             LCTL(KC_C),          LCTL(KC_V),
    /* RIGHT */ KC_LEFT,             KC_RIGHT,            KC_RPRN,             KC_COLN,             KC_NO,               KC_PSCR,             SEND_PASSWORD,

    // TWO
    /* LEFT  */ KC_LEFT_GUI,         KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_EXLM,
    /* RIGHT */ KC_QUES,             QK_BOOT,             RGB_VAI,             RGB_VAD,             KC_NO,               KC_NO,               KC_NO,

    // THREE
    /* LEFT  */ KC_TAB,              KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_MINUS,
    /* RIGHT */ KC_QUOTE,            KC_SYSTEM_POWER,     KC_AUDIO_VOL_UP,     KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_NO,               KC_NO,

    // FOUR
    /* LEFT  */ KC_SPACE,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */
    /* RIGHT */ /* EMPTY */          LGUI(KC_Z),          KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP,       KC_MEDIA_PREV_TRACK, KC_NO,

    // FIVE
    /* LEFT  */ KC_COMMA,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_LALT,             /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_TRANSPARENT,      KC_DOT,

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
    /* LEFT  */ KC_COMMA,            KC_TRANSPARENT,      KC_NO,               KC_NO,               KC_NO,               /* EMPTY */          KC_LEFT_CTRL,
    /* RIGHT */ KC_MS_BTN4,          /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_DOT,

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
    /* LEFT  */ KC_TAB,              KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                KC_NO,
    /* RIGHT */ KC_NO,               KC_H,                KC_J,                KC_LEFT,             KC_DOWN,             KC_RIGHT,            KC_NO,

    // FOUR
    /* LEFT  */ KC_LEFT_SHIFT,       KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,                /* EMPTY */
    /* RIGHT */ /* EMPTY */          KC_N,                KC_M,                KC_COMM,             KC_DOT,              KC_SLASH,            KC_RIGHT_SHIFT,

    // FIVE
    /* LEFT  */ KC_LEFT_CTRL,        KC_NO,               KC_TRANSPARENT,      KC_NO,               KC_NO,               /* EMPTY */          KC_NO,
    /* RIGHT */ KC_NO,               /* EMPTY */          KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_RIGHT_CTRL,

    // SIX
    /* LEFT  */ KC_SPACE,            KC_LALT,             KC_NO,
    /* RIGHT */ KC_L,                KC_RALT,             KC_NO
  ),
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT] = {
  [MOD_MAIN] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_WHITE,         COLOR_WHITE,         COLOR_WHITE,         COLOR_WHITE,         COLOR_GREY,          COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_GREY,          COLOR_WHITE,         COLOR_WHITE,         COLOR_WHITE,         COLOR_WHITE,         COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_GREY,          COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_TURQUOISE,     COLOR_GOLDENROD,     COLOR_PURPLE,        COLOR_GOLD,          /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_CYAN,          COLOR_ORANGE,        COLOR_BLUE,          COLOR_RED,           COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_PINK,          COLOR_GREEN,         COLOR_SPRINGGREEN
  },

  [MOD_RU] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_PINK,          COLOR_PINK,          COLOR_PINK,          COLOR_PINK,          COLOR_CORAL,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_CORAL,         COLOR_PINK,          COLOR_PINK,          COLOR_PINK,          COLOR_PINK,          COLOR_CORAL,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_TURQUOISE,     COLOR_GOLDENROD,     COLOR_PURPLE,        COLOR_GOLD,          /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_CYAN,          COLOR_ORANGE,        COLOR_BLUE,          COLOR_RED,           COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_WHITE,         COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_WORKSPACE] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_BLACK,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_PURPLE,        COLOR_PURPLE,        COLOR_PURPLE,        COLOR_BLACK,         COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_WHITE,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_WINDOW] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_ORANGE,        COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_WHITE,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_SYMBOL] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_WHITE,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_NUMBER] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_BLACK,         COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_WHITE,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_MUSIC] = {
    // ONE
    /* LEFT  */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // TWO
    /* LEFT  */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // SIX
    /* LEFT  */ COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,
    /* RIGHT */ COLOR_WHITE,         COLOR_BLACK,         COLOR_BLACK
  },

  [MOD_MOVE] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_GREEN,         COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_BLACK,         COLOR_WHITE,         COLOR_SPRINGGREEN
  },

  [MOD_CONFIG] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_RED,           COLOR_GREEN,         COLOR_GOLDENROD,     COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_RED,           COLOR_GREEN,         COLOR_GOLDENROD,     COLOR_RED,           COLOR_BLACK,         COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_RED,           COLOR_GOLDENROD,     COLOR_GREEN,         COLOR_RED,           COLOR_GOLDENROD,     COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_WHITE,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLACK,         COLOR_SPRINGGREEN
  },

  [MOD_MOUSE] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_PURPLE,        COLOR_BLACK,         COLOR_GOLD,          COLOR_GOLD,          COLOR_PURPLE,        COLOR_PURPLE,
    /* RIGHT */ COLOR_GREEN,         COLOR_GREEN,         COLOR_GOLD,          COLOR_GOLD,          COLOR_BLACK,         COLOR_SPRINGGREEN,   COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,
    /* RIGHT */ COLOR_GOLD,          COLOR_BLACK,         COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLACK,         COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_BLACK,

    // FIVE
    /* LEFT  */ COLOR_GOLD,          COLOR_WHITE,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_RED,
    /* RIGHT */ COLOR_RED,           /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_GOLD,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,
    /* RIGHT */ COLOR_TURQUOISE,     COLOR_TURQUOISE,     COLOR_TURQUOISE
  },

  [MOD_GAME] = {
    // ONE
    /* LEFT  */ COLOR_RED,           COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,
    /* RIGHT */ COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_CYAN,          COLOR_GOLD,          COLOR_GOLD,          COLOR_RED,

    // TWO
    /* LEFT  */ COLOR_BLACK,         COLOR_BLUE,          COLOR_CORAL,         COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_CORAL,         COLOR_BLUE,          COLOR_BLACK,

    // THREE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_BLUE,          COLOR_BLUE,          COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         COLOR_BLUE,          COLOR_BLUE,          COLOR_CORAL,         COLOR_CORAL,         COLOR_CORAL,         COLOR_BLACK,

    // FOUR
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          /* EMPTY */
    /* RIGHT */ /* EMPTY */          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_BLUE,          COLOR_SPRINGGREEN,

    // FIVE
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_BLACK,         COLOR_WHITE,         COLOR_BLACK,         COLOR_BLACK,         /* EMPTY */          COLOR_BLACK,
    /* RIGHT */ COLOR_BLACK,         /* EMPTY */          COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_BLACK,         COLOR_SPRINGGREEN,

    // SIX
    /* LEFT  */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_BLACK,
    /* RIGHT */ COLOR_SPRINGGREEN,   COLOR_SPRINGGREEN,   COLOR_BLACK
  },
};

void matrix_set_color(int layer, int key_index, int led_index) {
    uint8_t color = pgm_read_byte(&ledmap[layer][key_index]);

    HSV hsv = {
      .h = pgm_read_byte(&colormap[color][0]),
      .s = pgm_read_byte(&colormap[color][1]),
      .v = pgm_read_byte(&colormap[color][2]),
    };

    RGB rgb = hsv_to_rgb(hsv);
    float f = (float) rgb_matrix_config.hsv.v / UINT8_MAX;

    rgb_matrix_set_color(led_index, f * rgb.r, f * rgb.g, f * rgb.b);
  }

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  matrix_set_color(layer, 0, 0);
  matrix_set_color(layer, 1, 5);
  matrix_set_color(layer, 2, 10);
  matrix_set_color(layer, 3, 15);
  matrix_set_color(layer, 4, 20);
  matrix_set_color(layer, 5, 25);
  matrix_set_color(layer, 6, 29);
  matrix_set_color(layer, 7, 65);
  matrix_set_color(layer, 8, 61);
  matrix_set_color(layer, 9, 56);
  matrix_set_color(layer, 10, 51);
  matrix_set_color(layer, 11, 46);
  matrix_set_color(layer, 12, 41);
  matrix_set_color(layer, 13, 36);
  matrix_set_color(layer, 14, 1);
  matrix_set_color(layer, 15, 6);
  matrix_set_color(layer, 16, 11);
  matrix_set_color(layer, 17, 16);
  matrix_set_color(layer, 18, 21);
  matrix_set_color(layer, 19, 26);
  matrix_set_color(layer, 20, 30);
  matrix_set_color(layer, 21, 66);
  matrix_set_color(layer, 22, 62);
  matrix_set_color(layer, 23, 57);
  matrix_set_color(layer, 24, 52);
  matrix_set_color(layer, 25, 47);
  matrix_set_color(layer, 26, 42);
  matrix_set_color(layer, 27, 37);
  matrix_set_color(layer, 28, 2);
  matrix_set_color(layer, 29, 7);
  matrix_set_color(layer, 30, 12);
  matrix_set_color(layer, 31, 17);
  matrix_set_color(layer, 32, 22);
  matrix_set_color(layer, 33, 27);
  matrix_set_color(layer, 34, 31);
  matrix_set_color(layer, 35, 67);
  matrix_set_color(layer, 36, 63);
  matrix_set_color(layer, 37, 58);
  matrix_set_color(layer, 38, 53);
  matrix_set_color(layer, 39, 48);
  matrix_set_color(layer, 40, 43);
  matrix_set_color(layer, 41, 38);
  matrix_set_color(layer, 42, 3);
  matrix_set_color(layer, 43, 8);
  matrix_set_color(layer, 44, 13);
  matrix_set_color(layer, 45, 18);
  matrix_set_color(layer, 46, 23);
  matrix_set_color(layer, 47, 28);
  matrix_set_color(layer, 48, 64);
  matrix_set_color(layer, 49, 59);
  matrix_set_color(layer, 50, 54);
  matrix_set_color(layer, 51, 49);
  matrix_set_color(layer, 52, 44);
  matrix_set_color(layer, 53, 39);
  matrix_set_color(layer, 54, 4);
  matrix_set_color(layer, 55, 9);
  matrix_set_color(layer, 56, 14);
  matrix_set_color(layer, 57, 19);
  matrix_set_color(layer, 58, 24);
  matrix_set_color(layer, 59, 35);
  matrix_set_color(layer, 60, 71);
  matrix_set_color(layer, 61, 60);
  matrix_set_color(layer, 62, 55);
  matrix_set_color(layer, 63, 50);
  matrix_set_color(layer, 64, 45);
  matrix_set_color(layer, 65, 40);
  matrix_set_color(layer, 66, 32);
  matrix_set_color(layer, 67, 33);
  matrix_set_color(layer, 68, 34);
  matrix_set_color(layer, 69, 70);
  matrix_set_color(layer, 70, 69);
  matrix_set_color(layer, 71, 68);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SWITCH_MOD_MAIN:
      if (record->event.pressed) { 
        layer_move(MOD_MAIN);
        register_code(KC_LSFT); 
        tap_code(KC_LALT);
        unregister_code(KC_LSFT);
      }

      break; 
    case SWITCH_MOD_RU:
      if (record->event.pressed) {
        layer_move(MOD_RU);
        register_code(KC_LSFT); 
        tap_code(KC_LALT);
        unregister_code(KC_LSFT);
      } 

      break;
    case SEND_PASSWORD:
      if (record->event.pressed) {
        SEND_STRING("32" SS_TAP(X_ENTER));
      }

      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_NUBS)));
      }

      break;
    case ST_MACRO_2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_NUBS)));
      }

      break;
    case ST_MACRO_3:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_NUBS) SS_DELAY(100) SS_TAP(X_EQUAL));
      }

      break;
    case ST_MACRO_4:
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
