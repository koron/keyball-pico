add_executable(keyball61 layout.c main.c)

pico_enable_stdio_usb(keyball61 1)
pico_enable_stdio_uart(keyball61 0)

target_include_directories(keyball61 PUBLIC .)

target_link_libraries(keyball61
	diykb
	hardware_spi
	pico_bootsel_via_double_reset)

pico_add_extra_outputs(keyball61)
