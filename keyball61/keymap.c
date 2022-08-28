#include "diykb/keymap.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const keycode_t keymaps[][KEY_NUM] = {

    [0] = {
      KC_ESC  ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
      KC_TAB  ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
      KC_LCTL ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT ,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,
      KC_GRV  , KC_LALT,                             KC_SPC, KC_LGUI
    },

    /*
    [NEW LAYER] = {
      _______ , _______, _______, _______, _______, _______,
      _______ , _______, _______, _______, _______, _______,
      _______ , _______, _______, _______, _______, _______,
      _______ , _______, _______, _______, _______, _______, _______,
      _______ , _______,                            _______, _______
    },
    */

};

const size_t KEYMAP_LAYER_MAX = count_of(keymaps);

