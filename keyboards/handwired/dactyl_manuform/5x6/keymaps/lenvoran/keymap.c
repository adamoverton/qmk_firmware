/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

// override the normal 5x6 because we wired it differently
#ifdef LAYOUT_5x6
#undef LAYOUT_5x6
#endif

#define LAYOUT_5x6(\
  L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
            L42, L43,                                              R42, R43,           \
                      L44, L45,                          R40, R41,                     \
                                L52, L55,      R50, R53,                               \
                                L53, L54,      R51, R52                                \
  ) \
  { \
    { L00,   L01,   L02, L03, L04, L05 }, \
    { L10,   L11,   L12, L13, L14, L15 }, \
    { L20,   L21,   L22, L23, L24, L25 }, \
    { L30,   L31,   L32, L33, L34, L35 }, \
    { KC_NO, KC_NO, L42, L43, L44, L45 }, \
    { KC_NO, KC_NO, L52, L53, L54, L55 }, \
                                          \
    { R00, R01, R02, R03, R04,   R05   }, \
    { R10, R11, R12, R13, R14,   R15   }, \
    { R20, R21, R22, R23, R24,   R25   }, \
    { R30, R31, R32, R33, R34,   R35   }, \
    { R40, R41, R42, R43, KC_NO, KC_NO }, \
    { R50, R51, R52, R53, KC_NO, KC_NO }  \
}


#define _QWERTY 0
#define _FN 1

#define BEARD MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EQL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SLSH, KC_VOLU,
     KC_BSLASH, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT, KC_MUTE,KC_VOLD,
                      KC_LBRC,KC_RBRC,                                                       KC_HOME, KC_END,
                                      KC_LALT, KC_LCTL,                        KC_LGUI, BEARD,
                                      KC_QUOT, KC_SPC,                         KC_BSPC,  KC_DEL,
                                      KC_SCLN, KC_ESC,                        KC_ENT, KC_MPLY
  ),

  [_FN] = LAYOUT_5x6(
        KC_F12, KC_F1,  KC_F2,   KC_F3, KC_F4,   KC_F5,             KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,KC_LEFT,KC_UP, KC_DOWN,KC_RGHT, KC_TRNS,           KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_PGUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_PGDN,
                         KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS
  ),
};
