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

#define LAYER_DVORAK 0
#define LAYER_EXTENDED 1
#define LAYER_FN 2
#define LAYER_QWERTY 3

#define ASCEND MO(LAYER_EXTENDED)
#define FN MO(LAYER_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_DVORAK] = LAYOUT_5x6(
        KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,            KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_EQL,
        KC_TAB , KC_QUOT,KC_COMM,KC_DOT, KC_P  , KC_Y  ,            KC_F  , KC_G  , KC_C  , KC_R  , KC_L  , KC_SLSH,
        KC_LSFT, KC_A,   KC_O,   KC_E,   KC_U,   KC_I,              KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,
        KC_BSLS, KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,              KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_ESC,
                         KC_LBRC,KC_RBRC,                                           KC_HOME,KC_END,
                                        KC_BSPC, KC_LALT,           FN, KC_SPC,
                                        KC_LCTL, ASCEND,            DF(LAYER_QWERTY), KC_ENT,
                                        KC_LGUI, KC_MPLY,           KC_VOLD, KC_VOLU
        ),
	[LAYER_EXTENDED] = LAYOUT_5x6(
        KC_TILD, KC_EXLM,KC_AT, KC_HASH, KC_DLR, KC_PERC,           KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, KC_DEL,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_LBRC,           KC_RBRC,KC_P7,  KC_P8,  KC_P9,  KC_TRNS, KC_PLUS,
        KC_TRNS, KC_HOME,KC_PGUP, KC_PGDN, KC_END, KC_LPRN,         KC_RPRN, KC_P4, KC_P5, KC_P6,   KC_MINS, KC_PIPE,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_P1, KC_P2, KC_P3,   KC_EQL,  KC_UNDS,
                         KC_TRNS, KC_PSCR,                                          KC_TRNS, KC_P0,
                                        KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,           KC_MUTE, KC_TRNS
        ),
	[LAYER_FN] = LAYOUT_5x6(
        KC_F12, KC_F1,  KC_F2,   KC_F3, KC_F4,   KC_F5,             KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC,           KC_RBRC,KC_TRNS,KC_NLCK,KC_INS, KC_SLCK,KC_MUTE,
        KC_TRNS,KC_LEFT,KC_UP, KC_DOWN,KC_RGHT,KC_LPRN,           KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_TRNS,KC_VOLU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
                         KC_TRNS, KC_TRNS,                                            KC_EQL, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS
        ),
	[LAYER_QWERTY] = LAYOUT_5x6(
        KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,            KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_EQL,
        KC_TAB , KC_Q,   KC_W,   KC_E,   KC_R  , KC_T  ,            KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , KC_MINS,
        KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,              KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_BSLS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,              KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ESC,
                         KC_LBRC,KC_RBRC,                                           KC_HOME,KC_END,
                                        KC_BSPC, KC_LALT,           FN, KC_SPC,
                                        KC_LCTL, ASCEND,            DF(LAYER_DVORAK), KC_ENT,
                                        KC_LGUI, KC_MPLY,           KC_VOLD, KC_VOLU
        )
};

