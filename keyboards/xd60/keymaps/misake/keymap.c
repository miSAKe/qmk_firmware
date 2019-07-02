#include QMK_KEYBOARD_H
#include "action_layer.h"

#define _BL 0
#define _FL1 1
#define _FL2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [_BL] = LAYOUT_all(
      KC_GESC,KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_NO,   \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_NO,   \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS,           KC_ENT,  \
      KC_LSFT, KC_NUBS,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_NO, KC_RSFT,KC_NO,  \
      KC_LCTL, MO(1), KC_LALT,                          KC_SPC,                          KC_RALT, KC_RGUI,  KC_NO, MO(2),  KC_RCTL),

  // 1: Function Layer 1
  [_FL1] = LAYOUT_all(
      KC_GRV ,RGB_TOG,   RGB_MOD,   RGB_HUI,   RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,  KC_NO,  \
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_PSCR, KC_HOME,   KC_END,           KC_NO,  \
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,              KC_ENT, \
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO, KC_RSFT,   KC_NO, \
      KC_LCTL, KC_TRNS, KC_LALT,                          KC_SPC,                          KC_RALT, KC_RGUI,  KC_NO,   KC_NO, KC_NO),

  // 2: Function Layer 2
  [_FL2] = LAYOUT_all(
    KC_GRV ,KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,  KC_NO,  \
    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   BL_TOGG, KC_VOLD,   KC_VOLU,           KC_NO,  \
    KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,              KC_ENT, \
    KC_LSFT, KC_NO, KC_NO, KC_NO,  KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, KC_NO, KC_RSFT,   KC_NO, \
    KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, KC_RGUI,  KC_TRNS,   KC_NO, KC_NO),
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _FL1:
        rgblight_setrgb (RGB_GREEN);
        break;
    case _FL2:
        rgblight_setrgb (RGB_BLUE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_disable();
        break;
    }
  return state;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        rgblight_setrgb (RGB_RED);
    } else {
       rgblight_disable();
    }
}
