// Copyright 2023 mituba (@mituba)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define DEBOUNCE 5

// Mod Tap Key と通常キーを連続して拘束に押したときに両方のキーを Tap として扱う
#define HOLD_ON_OTHER_KEY_PRESS
