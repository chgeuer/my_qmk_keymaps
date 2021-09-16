#pragma once

// keyboards/preonic/keymaps/chgeuer/config.h
// Preonic

#define ENCODERS_PAD_A { B12 }

#define ENCODERS_PAD_B { B13 }

// https://docs.splitkb.com/hc/en-us/articles/360011068659-My-encoder-is-skipping-actions-when-turning-it
//
// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10
