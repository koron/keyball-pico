#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"

#include "config.h"
#include "matrix.h"
#include "ledarray.h"
#include "backlight.h"
#include "layout.h"

#if 0
void matrix_suppressed(uint64_t when, uint knum, bool on, uint64_t last, uint64_t elapsed) {
    // disable "suppressed" logs
}
#endif

#define SPI_PORT    spi_default
#define SPI_RX      PICO_DEFAULT_SPI_RX_PIN
#define SPI_SCK     PICO_DEFAULT_SPI_SCK_PIN
#define SPI_TX      PICO_DEFAULT_SPI_TX_PIN
#define SPI_CSN     PICO_DEFAULT_SPI_CSN_PIN

static inline void cs_select() {
    asm volatile("nop \n nop \n nop");
    gpio_put(SPI_CSN, false);
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() {
    asm volatile("nop \n nop \n nop");
    gpio_put(SPI_CSN, true);
    asm volatile("nop \n nop \n nop");
}

uint8_t reg_read(uint8_t addr) {
    cs_select();
    addr &= 0x7f;
    spi_write_blocking(SPI_PORT, &addr, 1);
    busy_wait_us_32(160);
    uint8_t data = 0;
    spi_read_blocking(SPI_PORT, 0, &data, 1);
    busy_wait_us_32(20);
    cs_deselect();
    return data;
}

void reg_write(uint8_t addr, uint8_t data) {
    uint8_t buf[] = {addr | 0x80, data};
    cs_select();
    spi_write_blocking(SPI_PORT, buf, 2);
    cs_deselect();
    busy_wait_us_32(180);
}

uint8_t pid = 0, rev = 0;

void pmw3360_init() {
    // SPI bus
    gpio_set_function(SPI_RX, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(SPI_TX, GPIO_FUNC_SPI);
    bi_decl(bi_3pins_with_func(SPI_RX, SPI_TX, SPI_SCK, GPIO_FUNC_SPI));
    // SPI CSN
    gpio_init(SPI_CSN);
    gpio_set_dir(SPI_CSN, GPIO_OUT);
    gpio_put(SPI_CSN, true);
    bi_decl(bi_1pin_with_name(SPI_CSN, "SPI CS"));

    // SPI initialize.
    spi_init(SPI_PORT, 2*1000*1000);
    spi_set_format(SPI_PORT, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);

    // reboot
    reg_write(0x3a, 0x5a);
    busy_wait_us_32(50);
    // read five registers of motion and discard those values
    reg_read(0x02);
    reg_read(0x03);
    reg_read(0x04);
    reg_read(0x05);
    reg_read(0x06);
    // configuration
    reg_write(0x10, 0x00);
    // read and verify identifiers
    pid = reg_read(0x00);
    rev = reg_read(0x01);
}

static void toggle_backlight() {
    if (backlight_is_enable()) {
        backlight_disable();
    } else {
        backlight_enable();
    }
}

int32_t matrix_pin_unselect_delay = 79;
static bool tick_log_enable = true;

static const int32_t delays[] = { 79, 49, 9 };
static int delay_idx = 0;

void matrix_changed(uint64_t when, uint knum, bool on) {
    printf("matrix_changed: knum=%d %s when=%llu\n", knum, on ? "ON" : "OFF", when);
    if (on) {
        switch (knum) {
            case 0:
                toggle_backlight();
                break;
            case 6:
                if (++delay_idx >= count_of(delays)) {
                    delay_idx = 0;
                }
                matrix_pin_unselect_delay = delays[delay_idx];
                printf("changed: matrix_pin_unselect_delay=%d\n", matrix_pin_unselect_delay);
                break;
            case 25:
                tick_log_enable = !tick_log_enable;
                break;
        }
    }
}

int main() {
    stdio_init_all();
    pmw3360_init();
    matrix_init();
    ledarray_init();
    backlight_init();

    uint64_t last = 0;
    while(true) {
        uint64_t now = time_us_64();
        matrix_task(now);
        backlight_task(now);
        ledarray_task(now);
        if (tick_log_enable && (now - last) > 1000000) {
            last = now;
            printf("tick: pid=%02x rev=%02x rx=%d sck=%d tx=%d\n", pid, rev, SPI_RX, SPI_SCK, SPI_TX);
        }
    }
}
