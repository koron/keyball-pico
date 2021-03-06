#pragma once

//////////////////////////////////////////////////////////////////////////////
// for usb_descriptors.c

#define VENDOR_ID       0x5957
#define PRODUCT_ID      0x0101
#define DEVICE_VER      0x0001
#define MANUFACTURER    Yowkees
#define PRODUCT         Keyball61/RP2

//////////////////////////////////////////////////////////////////////////////
// Global configurations

#define KEY_NUM     29

//////////////////////////////////////////////////////////////////////////////
// for matrix.c

//#define MATRIX_SCAN_PERFORMANCE_COUNT

#define MATRIX_SCAN_INTERVAL 499

#define MATRIX_PIN_SELECT_DELAY     1
#define MATRIX_PIN_UNSELECT_DELAY   matrix_pin_unselect_delay

extern int32_t matrix_pin_unselect_delay;

//#define MATRIX_DEBOUNCE_USEC      (10*1000)

//////////////////////////////////////////////////////////////////////////////
// for ledarray.c

#define LEDARRAY_NUM    34
#define LEDARRAY_PIN    0
#define LEDARRAY_PIO    pio0

//////////////////////////////////////////////////////////////////////////////
// development flags
