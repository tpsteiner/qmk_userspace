#pragma once

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define MOUSE_EXTENDED_REPORT

#ifdef VIA_ENABLE
#   define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif

#ifndef __arm__
#   define NO_ACTION_ONESHOT
#endif

#define LAYER_INDICATOR_LED_1_INDEX   51
#define LAYER_INDICATOR_LED_2_INDEX   52
