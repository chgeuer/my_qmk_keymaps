// Preonic

#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"
#include "config.h"

enum OrthoLayers {
  _COLEMAK_DH,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    CH_TICK,
    CH_BACKTICK,
    CH_CARET,
    CH_EURO
};

#define ________            KC_NO
#define _______KC_SPC______ KC_SPC

// registered keybinding for Snagit Capture
#define CTRL_SHIFT_S LCTL(LSFT(DE_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_preonic_1x2uC(
        ________ , DE_1     , DE_2     , DE_3     , DE_4     , DE_5     , DE_6     , DE_7     , DE_8     , DE_9     , DE_0     , ________ ,
        KC_ESC   , DE_Q     , DE_W     , DE_F     , DE_P     , DE_B     , DE_J     , DE_L     , DE_U     , DE_Y     , DE_SS    , DE_PLUS  ,
        KC_TAB   , DE_A     , DE_R     , DE_S     , DE_T     , DE_G     , DE_M     , DE_N     , DE_E     , DE_I     , DE_O     , DE_HASH  ,
        KC_LSFT  , DE_Z     , DE_X     , DE_C     , DE_D     , DE_V     , DE_K     , DE_H     , DE_COMM  , DE_DOT   , DE_MINS  , KC_RSFT  ,
        KC_LCTL  , KC_LALT  , KC_LGUI  , KC_BSPC  , LOWER    , _______KC_SPC______ , RAISE    , KC_ENT   , KC_DEL   , KC_RGUI  , KC_RCTL ),

    [_LOWER] = LAYOUT_preonic_1x2uC(
        ________ , ________ , ________ , ________ , ________ , ________ , ________ , ________ , ________ , ________ , ________ , ________ ,
        CH_CARET , DE_EXLM  , DE_DQUO  , DE_DLR   , DE_PERC  , DE_AMPR  , ________ , DE_LPRN  , DE_RPRN  , DE_MINS  , DE_EQL   , DE_BSLS  ,
        DE_PIPE  , DE_AT    , DE_TILD  , RALT(DE_D)  , ________ , ________ , ________ , DE_LCBR  , DE_RCBR  , DE_LBRC  , DE_RBRC  , DE_QUOT  ,
        KC_LSFT  , ________ , ________ , ________ , ________ , ________ , ________ , DE_LABK  , DE_RABK  , DE_COLN  , DE_SLSH  , CH_BACKTICK  ,
        KC_LCTL  , KC_LALT  , KC_LGUI  , KC_BSPC  , KC_TRNS  , _______KC_SPC______ , ADJUST   , ________ , ________ , ________ , CH_TICK  ),

    [_RAISE] = LAYOUT_preonic_1x2uC(
        KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
        ________ , DE_1     , DE_2     , DE_3     , DE_4     , DE_5     , DE_6     , DE_7     , DE_8     , DE_9     , DE_0     , KC_HOME  ,
        ________ , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , KC_PGUP  ,
        KC_LSFT  , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   , KC_MS_L  , KC_MS_D  , KC_MS_U  , KC_MS_R  , KC_PGDN  ,
        KC_LCTL  , KC_LALT  , KC_LGUI  , KC_BSPC  , ADJUST   , _______KC_SPC______ , KC_TRNS  , KC_BTN1  , KC_BTN2  , ________ , KC_END   ),

    [_ADJUST] = LAYOUT_preonic_1x2uC(
        ________ , ________ , ________ , BL_BRTG  , ________ , ________ , ________ , ________ , ________ , ________ , ________ , DEBUG    ,
        ________ , ________ , ________ , BL_TOGG  , ________ , ________ , KC_BRIU  , KC_VOLU  , ________ , ________ , ________ , MAGIC_SWAP_RALT_RGUI ,
        ________ , ________ , ________ , BL_INC   , ________ , ________ , KC_BRID  , KC_VOLD  , KC_MUTE  , ________ , ________ , ________ ,
        KC_LSFT  , KC_LALT  , ________ , BL_DEC   , ________ , ________ , ________ , DE_ADIA  , DE_ODIA  , DE_UDIA  , DE_SS    , KC_RSFT  ,
        KC_LCTL  , KC_LALT  , KC_LGUI  , KC_BSPC  , KC_TRNS  , CTRL_SHIFT_S        , KC_TRNS  , ________ , ________ , ________ , RESET    )
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        case _LOWER:
            if (clockwise) {
                register_code(KC_LALT);
                tap_code(KC_TAB);
                unregister_code(KC_LALT);
            } else {
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_TAB);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            break;
        case _RAISE:
            if (clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case _ADJUST:
            if (clockwise){
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
            break;
        default:
            break;
    }

    // Returning true will allow the keyboard level code to run, as well. 
    // Returning false will override the keyboard level code.
    return true;
};
