
#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"

enum layers {
  _COLEMAK_DH,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    CH_TICK,
    CH_BACKTICK,
    CH_CARET,
    CH_EURO
};

#define ________ KC_NO

// registered keybinding for Snagit Capture
#define SNAGIT    LCTL(LSFT(DE_S))
#define ZOOM      LALT(LCTL(LSFT(DE_Q)))
#define LIVEZOOM  LALT(LCTL(LSFT(DE_T)))
#define DRAW      LALT(LCTL(LSFT(KC_F11)))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_ortho_4x12(
        KC_ESC   , DE_Q     , DE_W     , DE_F     , DE_P     , DE_B     , DE_J     , DE_L     , DE_U     , DE_Y     , DE_SS    , DE_PLUS  ,
        KC_TAB   , DE_A     , DE_R     , DE_S     , DE_T     , DE_G     , DE_M     , DE_N     , DE_E     , DE_I     , DE_O     , DE_HASH  ,
        KC_LSFT  , DE_Z     , DE_X     , DE_C     , DE_D     , DE_V     , DE_K     , DE_H     , DE_COMM  , DE_DOT   , DE_MINS  , KC_RSFT  ,
        KC_LCTL  , KC_LGUI  , KC_LALT  , KC_BSPC  , LOWER    , KC_SPC   , KC_SPC   , RAISE    , KC_ENT   , KC_DEL   , KC_RGUI  , KC_RCTL ),

    [_LOWER] = LAYOUT_ortho_4x12(
        CH_CARET , DE_EXLM  , DE_DQUO  , DE_DLR     , DE_AMPR  , DE_PERC  , ________ , DE_LPRN  , DE_RPRN  , DE_MINS  , DE_EQL   , DE_BSLS  ,
        DE_PIPE  , DE_AT    , DE_TILD  , DE_EURO    , ________ , ________ , ________ , DE_LCBR  , DE_RCBR  , DE_LBRC  , DE_RBRC  , DE_QUOT  ,
        KC_LSFT  , ________ , DE_DEG   , DE_SECT    , ________ , ________ , ________ , DE_LABK  , DE_RABK  , DE_COLN  , DE_SLSH  , CH_BACKTICK  ,
        KC_LCTL  , KC_LGUI  , KC_LALT  , KC_BSPC    , KC_TRNS  , KC_SPC   , KC_SPC   , ADJUST   , ________ , ________ , ________ , CH_TICK  ),

    [_RAISE] = LAYOUT_ortho_4x12(
        ________ , DE_1     , DE_2     , DE_3     , DE_4     , DE_5     , DE_6      , DE_7     , DE_8     , DE_9     , DE_0     , KC_HOME  ,
        ________ , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6     , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , KC_PGUP  ,
        KC_LSFT  , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12    , KC_MS_L  , KC_MS_D  , KC_MS_U  , KC_MS_R  , KC_PGDN  ,
        KC_LCTL  , KC_LGUI  , KC_LALT  , KC_BSPC  , ADJUST   , KC_SPC   , KC_SPC    , KC_TRNS  , KC_BTN1  , KC_BTN2  , ________ , KC_END   ),

    [_ADJUST] = LAYOUT_ortho_4x12(
        RGB_TOG  , RGB_MOD  , RGB_HUI  , RGB_M_P  , RGB_SAI  , RGB_VAI  , KC_BRIU   , KC_VOLU  , KC_MPRV  , KC_MNXT  , ________ , MAGIC_SWAP_RALT_RGUI ,
        ________ , RGB_RMOD , RGB_HUD  , RGB_M_G  , RGB_SAD  , RGB_VAD  , KC_BRID   , KC_VOLD  , KC_MUTE  , KC_MPLY  , KC_MSTP  , RESET ,
        KC_LSFT  , KC_LALT  , ________ , BL_DEC   , ZOOM     , LIVEZOOM , DRAW      , DE_ADIA  , DE_ODIA  , DE_UDIA  , DE_SS    , KC_RSFT ,
        KC_LCTL  , KC_LGUI  , KC_LALT  , KC_BSPC  , KC_TRNS  , SNAGIT   , SNAGIT    , KC_TRNS  , ________ , ________ , ________ , ________ )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
            break;
        case _LOWER:
            switch (keycode) {
                case CH_TICK:
                    if (record->event.pressed) {
                        SEND_STRING("= ");
                    }
                    break;
                case CH_BACKTICK:
                    if (record->event.pressed) {
                        SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(10) SS_TAP(X_SPACE));
                    }
                    break;
                case CH_CARET:
                    if (record->event.pressed) {
                        SEND_STRING("` ");
                    }
                    break;
                default:
                    break;
            }
            break;
        case _RAISE:
            break;
        case _ADJUST:
            break;
        default:
            break;
    }
    return true;
};

