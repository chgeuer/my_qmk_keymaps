#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"

// registered keybinding for Snagit Capture
#define SNAGIT    LCTL(LSFT(DE_S))
#define ZOOM      LALT(LCTL(LSFT(DE_Q)))
#define LIVEZOOM  LALT(LCTL(LSFT(DE_T)))
#define DRAW      LALT(LCTL(LSFT(KC_F11)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT(
        SNAGIT, ZOOM,     KC_VOLU, 
		DRAW,   LIVEZOOM, KC_VOLD),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO) };