// Lily58

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( \
        ________,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                        DE_6,  DE_7,    DE_8,    DE_9,   DE_0,    KC_BSPC,  \
        KC_ESC,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,                        DE_J,  DE_L,    DE_U,    DE_Y,   DE_SS,   DE_PLUS,  \
        // KC_TAB, DE_A, DE_R,    DE_S,    DE_T,    DE_G,                        DE_M,  DE_N,    DE_E,    DE_I,   KC_O,    DE_HASH,
        KC_TAB,  DE_A, ALT_DE_R, SFT_DE_S, CTL_DE_T, DE_G,                    DE_M,  CTL_DE_N, SFT_DE_E, ALT_DE_I, DE_O, DE_HASH,  \
        KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,  KC_LGUI,     KC_RGUI, DE_K,  DE_H,    DE_COMM, DE_DOT, DE_MINS, KC_RSFT, \
                                   KC_LALT, KC_BSPC, LOWER, KC_SPC,      KC_SPC,  RAISE, KC_ENT, KC_RCTL \
  ),
  [_LOWER] = LAYOUT( \
        CH_CARET , ________, ________, ________,   ________, ________,                     ________, ________, ________, ________, ________, ________, \
        DE_PIPE  , DE_EXLM,  DE_DQUO , DE_DLR   ,  DE_PERC,  DE_AMPR,                      KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12, \
        KC_LSFT  , DE_AT,    DE_TILD , RALT(DE_D), ________, ________,                     KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
        KC_LCTL  , ________, ________, ________,   ________, ________, KC_LGUI,  KC_RGUI,  ________, KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                                       ________,   ________, ________, ________, ________, ADJUST,   ________, ________ \
  ),
  [_RAISE] = LAYOUT( \
        ________, ________, ________, ________, ________, ________,                        ________, ________, ________, ________, ________, KC_HOME, \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                            KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PGUP, \
        KC_LSFT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                           KC_F6,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PGDN, \
        KC_LCTL,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_LGUI,     KC_RGUI,  KC_F12,   KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_END,  \
                                      ________, ________,  ADJUST, ________,     ________, ________, KC_BTN1,  KC_BTN2 \
  ),
  [_ADJUST] = LAYOUT( \
        ________, ________, ________, ________,   ________,   ________,                        ________, ________, ________, ________, ________, CH_BACKTICK, \
        ________, ________, ________, ________,   ________,   ________,                        ________, ________, ________, ________, ________, DE_QUOT, \
        ________, ________, ________, ________,   ________,   ________,                        ________, ________, ________, ________, ________, CH_TICK, \
        ________, ________, ________, ________,   ________,   ________, SnagIt,      SnagIt,   DE_ADIA  , DE_ODIA, DE_UDIA,  DE_SS,    ________, CH_CARET, \
                                      ________,   ________,   ________, ________,    ________, ________, ________, ________ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
//     oled_write_P(qmk_logo, false);
// }

const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};
//
//static void fade_display(void) {
//    //Define the reader structure
//    oled_buffer_reader_t reader;
//    uint8_t buff_char;
//    if (random() % 30 == 0) {
//        srand(timer_read());
//        // Fetch a pointer for the buffer byte at index 0. The return structure
//        // will have the pointer and the number of bytes remaining from this
//        // index position if we want to perform a sequential read by
//        // incrementing the buffer pointer
//        reader = oled_read_raw(0);8
//        //Loop over the remaining buffer and erase pixels as we go
//        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
//            //Get the actual byte in the buffer by dereferencing the pointer
//            buff_char = *reader.current_element;
//            if (buff_char != 0) {
//                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
//            }
//            //increment the pointer to fetch a new byte during the next loop
//            reader.current_element++;
//        }
//    }
//}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}


// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// void oled_task_user(void) {
//   if (is_keyboard_master()) {
//      // If you want to change the display of OLED, you need to change here
//      oled_write_ln(read_layer_state(), false);
//      oled_write_ln(read_keylog(), false);
//      oled_write_ln(read_keylogs(), false);
//      //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
//      //oled_write_ln(read_host_led_state(), false);
//      //oled_write_ln(read_timelog(), false);
//    } else {
//      oled_write(read_logo(), false);
//    }
//     if (is_keyboard_master()) {
//         //render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
//     } else {
//         render_logo();  // Renders a static logo
//         oled_scroll_left();  // Turns on scrolling
//     }
// }


void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("Default\n"), false);
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
		set_keylog(keycode, record);
#endif
		// set_timelog();
	}

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
