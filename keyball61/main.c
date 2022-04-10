#include <stdio.h>

#include "pico/stdlib.h"

#include "config.h"
#include "matrix.h"
#include "ledarray.h"
#include "backlight.h"

#if 0
void matrix_suppressed(uint64_t when, uint knum, bool on, uint64_t last, uint64_t elapsed) {
    // disable "suppressed" logs
}
#endif

int main() {
    stdio_init_all();
    matrix_init();
    ledarray_init();
    backlight_init();

    uint64_t last = 0;
    while(true) {
        uint64_t now = time_us_64();
        matrix_task(now);
        backlight_task(now);
        ledarray_task(now);
        if ((now - last) > 1000000) {
            last = now;
            printf("Hello Keyball61\n");
        }
    }
}
