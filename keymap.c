#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_204_255_255,
  HSV_111_255_255,
  LANG_LAYOUT_SWITCH_0, 
  LANG_LAYOUT_SWITCH_1,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_LPRN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN,        KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0,     
    KC_TAB,         KC_TRANSPARENT, KC_X,           KC_Y,           KC_P,           KC_TRANSPARENT, KC_EXLM,                                        KC_QUES,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRANSPARENT, 
    LCTL(KC_C),     KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_MINUS,                                       KC_QUOTE,       KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_RIGHT,       
    LCTL(KC_V),     KC_TRANSPARENT, KC_Q,           KC_J,           KC_K,           KC_TRANSPARENT,                                                                 KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRANSPARENT, 
    KC_COMMA,       TG(9),          TG(7),          OSL(5),         OSL(3),                         KC_LEFT_CTRL,                                   KC_LEFT_GUI,                    OSL(2),         OSL(4),         TO(6),          OSL(8),         KC_DOT,         
                                                                    KC_LEFT_SHIFT,  KC_BSPC,        KC_ENTER,                                       LANG_LAYOUT_SWITCH_1,OSL(7),    KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_SCLN,        RU_LPRN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, RU_RPRN,        RU_COLN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_IE,          RU_EF,          RU_EXLM,                                        RU_QUES,        RU_SHCH,        RU_GHE,         RU_TE,          RU_EN,          RU_ZE,          RU_HARD,        
    KC_TRANSPARENT, RU_KA,          RU_EM,          RU_VE,          RU_A,           RU_PE,          RU_MINS,                                        RU_DQUO,        RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_I,           RU_YERU,                                                                        RU_SHA,         RU_SOFT,        RU_BE,          RU_YU,          RU_HA,          RU_YO,          
    RU_COMM,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RU_DOT,         
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LANG_LAYOUT_SWITCH_0,KC_TRANSPARENT,KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          LGUI(KC_5),     LGUI(KC_6),     LGUI(KC_7),     KC_NO,          KC_NO,          
    KC_NO,          LCTL(KC_A),     LCTL(KC_S),     LALT(KC_D),     LCTL(KC_F),     KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     KC_NO,          
    KC_NO,          LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_SLASH),                                                                 KC_NO,          LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          LGUI(KC_ENTER),                                 LGUI(KC_Z),                     KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_PSCR,        
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(KC_LEFT_GUI),KC_NO,        KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          LALT(LGUI(KC_H)),LALT(LGUI(KC_J)),LALT(LGUI(KC_K)),LALT(LGUI(KC_L)),KC_NO,          
    KC_NO,          LGUI(KC_G),     LGUI(KC_S),     LGUI(KC_F),     LGUI(KC_D),     KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          LGUI(KC_H),     LGUI(KC_J),     LGUI(KC_K),     LGUI(KC_L),     KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          LALT(LGUI(LSFT(KC_H))),LALT(LGUI(LSFT(KC_J))),LALT(LGUI(LSFT(KC_K))),LALT(LGUI(LSFT(KC_L))),KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                 LGUI(KC_ENTER),                                 LGUI(KC_Z),                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PSCR,        
                                                                    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_TILD,        KC_GRAVE,       KC_PERC,        KC_AT,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_LBRC,        KC_RBRC,        ST_MACRO_1,     ST_MACRO_2,     KC_NO,          
    KC_NO,          KC_EQUAL,       KC_PIPE,        KC_AMPR,        KC_DLR,         KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_LPRN,        KC_RPRN,        KC_LABK,        KC_RABK,        KC_NO,          
    KC_NO,          KC_CIRC,        KC_HASH,        KC_ASTR,        KC_SLASH,       KC_NO,                                                                          KC_NO,          KC_LCBR,        KC_RCBR,        ST_MACRO_3,     ST_MACRO_4,     KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_NO,                                          KC_NO,                          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          
                                                                    KC_TRANSPARENT, KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO
  ),
  [5] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_F8,          KC_F7,          KC_F6,          KC_F5,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,          
    KC_NO,          KC_F4,          KC_F3,          KC_F2,          KC_F1,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_0,           KC_NO,          
    KC_NO,          KC_F12,         KC_F11,         KC_F10,         KC_F9,          KC_NO,                                                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, RU_COMM,        KC_NO,          KC_TRANSPARENT, KC_NO,                          KC_NO,                                          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          RU_DOT,         KC_TRANSPARENT, 
                                                                    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          MU_TOGG,                                        MU_NEXT,                        KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          
                                                                    TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_TOG,                                    TO(0),          HSV_204_255_255,HSV_111_255_255
  ),
  [7] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_END,         KC_PGDN,        KC_PAGE_UP,     KC_HOME,        KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_H,           KC_J,           KC_K,           KC_L,           KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,                          KC_TRANSPARENT,                                 KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                                    KC_TRANSPARENT, KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO
  ),
  [8] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          ST_MACRO_5,     
    KC_NO,          KC_NO,          KC_NO,          RGB_VAD,        RGB_VAI,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO,                                                              KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_SYSTEM_POWER,                                QK_BOOT,                        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          
                                                                    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO
  ),
  [9] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,                          KC_TRANSPARENT,                                 KC_MS_BTN4,                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                                    KC_TRANSPARENT, KC_LEFT_GUI,    KC_NO,                                          KC_MS_BTN3,     KC_MS_BTN1,     KC_MS_BTN2
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {34,218,204}, {214,255,255}, {214,255,255}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {128,255,255}, {0,0,0}, {0,0,136}, {0,0,255}, {0,0,136}, {18,255,255}, {34,218,204}, {0,0,136}, {0,0,255}, {0,0,136}, {190,218,204}, {34,218,204}, {0,0,136}, {0,0,255}, {0,0,136}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,136}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {82,218,204}, {0,255,255}, {0,255,255}, {82,218,204}, {0,255,255}, {0,0,0}, {18,255,255}, {0,0,0}, {34,218,204}, {0,0,0}, {0,0,136}, {0,0,255}, {0,0,136}, {0,255,255}, {0,0,0}, {0,0,136}, {0,0,255}, {0,0,136}, {103,255,255}, {34,218,204}, {0,0,136}, {0,0,255}, {0,0,136}, {34,218,204}, {34,218,204}, {0,0,136}, {0,0,255}, {0,0,136}, {214,255,255}, {0,0,0}, {0,0,136}, {0,0,136}, {0,0,136}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {18,255,255}, {170,255,255}, {82,218,204} },

    [1] = { {0,255,255}, {34,218,204}, {214,255,255}, {214,255,255}, {34,218,204}, {0,0,0}, {170,255,110}, {170,255,255}, {170,255,110}, {128,255,255}, {0,0,0}, {170,255,110}, {170,255,255}, {170,255,110}, {18,255,255}, {34,218,204}, {170,255,110}, {170,255,255}, {170,255,110}, {190,218,204}, {34,218,204}, {170,255,110}, {170,255,255}, {170,255,110}, {190,218,204}, {0,0,0}, {0,0,0}, {170,255,110}, {170,255,110}, {0,0,0}, {34,218,204}, {34,218,204}, {82,218,204}, {0,255,255}, {0,255,255}, {82,218,204}, {0,255,255}, {170,255,110}, {170,255,110}, {170,255,110}, {34,218,204}, {0,0,0}, {170,255,110}, {170,255,255}, {170,255,110}, {0,255,255}, {0,0,0}, {170,255,110}, {170,255,255}, {170,255,110}, {103,255,255}, {34,218,204}, {170,255,110}, {170,255,255}, {170,255,110}, {34,218,204}, {34,218,204}, {170,255,110}, {170,255,255}, {170,255,110}, {214,255,255}, {0,0,0}, {170,255,110}, {170,255,110}, {170,255,110}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {18,255,255}, {0,0,255}, {82,218,204} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {214,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {86,218,204}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,0}, {0,0,0}, {214,255,255}, {214,255,255}, {214,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {0,0,0}, {86,218,204}, {0,255,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {175,255,255}, {175,255,255}, {175,255,255}, {0,0,0}, {0,0,0}, {175,255,255}, {175,255,255}, {175,255,255}, {0,0,0}, {0,0,0}, {175,255,255}, {175,255,255}, {175,255,255}, {0,0,0}, {0,0,0}, {175,255,255}, {175,255,255}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,255}, {0,0,0}, {34,218,204}, {34,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {34,218,204}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,255}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {0,0,0}, {0,0,0}, {190,218,204}, {0,0,0}, {34,218,204}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {190,218,204}, {190,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,218,204}, {86,218,204}, {86,218,204}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {111,255,255}, {204,255,255}, {0,0,255}, {0,255,255} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,218,204}, {0,0,0}, {0,0,0}, {82,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {18,255,255}, {18,255,255}, {18,255,255}, {0,0,0}, {0,0,0}, {18,255,255}, {18,255,255}, {18,255,255}, {0,0,0}, {0,0,0}, {18,255,255}, {18,255,255}, {18,255,255}, {0,0,0}, {0,0,0}, {18,255,255}, {18,255,255}, {18,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {34,218,204}, {34,218,204}, {83,218,204}, {0,0,0}, {0,0,0}, {83,218,204}, {83,218,204}, {34,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,218,204}, {82,218,204}, {0,0,0}, {82,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {128,255,255}, {128,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LANG_LAYOUT_SWITCH_0:
      if (record->event.pressed) { 
        layer_move(0);
        register_code(KC_LSFT); 
        tap_code(KC_LALT);
        unregister_code(KC_LSFT);
      }
      break; 
    case LANG_LAYOUT_SWITCH_1:
      if (record->event.pressed) {
        layer_move(1);
        register_code(KC_LSFT); 
        tap_code(KC_LALT);
        unregister_code(KC_LSFT);
      } 
      break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3) SS_DELAY(100) SS_TAP(X_2)  SS_DELAY(100) SS_TAP(X_ENTER));
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
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3) SS_DELAY(100) SS_TAP(X_2)  SS_DELAY(100) SS_TAP(X_ENTER));
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
    case HSV_204_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(204,255,255);
        }
        return false;
    case HSV_111_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(111,255,255);
        }
        return false;
  }
  return true;
}



