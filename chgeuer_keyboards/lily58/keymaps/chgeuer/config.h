// Lily58

#pragma once

#define ________ KC_TRNS
#define XXXXXXXX KC_NO

// registered keybinding for Snagit Capture
#define SnagIt LCTL(LSFT(DE_S))

#define GUI_DE_A LGUI_T(DE_A)
#define ALT_DE_R LALT_T(DE_R)
#define SFT_DE_S LSFT_T(DE_S)
#define CTL_DE_T LCTL_T(DE_T)
#define CTL_DE_N RCTL_T(DE_N)
#define SFT_DE_E RSFT_T(DE_E)
#define ALT_DE_I LALT_T(DE_I)
#define GUI_DE_O RGUI_T(DE_O)

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// Underglow
/*
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
*/
