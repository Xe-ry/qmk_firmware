#include "../../config.h"
#undef MANUFACTURER
#define MANUFACTURER "Xe"
#undef USBSTR_MANUFACTURER
#define USBSTR_MANUFACTURER    'X', '\x00', 'e', '\x00'
#undef PRODUCT
#define PRODUCT "Infinity Ergodox w/QMK"
#undef USBSTR_PRODUCT
#define USBSTR_PRODUCT         'I', '\x00', 'n', '\x00', 'f', '\x00', 'i', '\x00', 'n', '\x00', 'i', '\x00', 't', '\x00', 'y', '\x00', ' ', '\x00', 'E', '\x00', 'r', '\x00', 'g', '\x00', 'o', '\x00', 'd', '\x00', 'o', '\x00', 'x', '\x00', ' ', '\x00', 'w', '\x00', '/', '\x00', 'Q', '\x00', 'M', '\x00', 'K', '\x00'
#define PREVENT_STUCK_MODIFIERS

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 20
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0