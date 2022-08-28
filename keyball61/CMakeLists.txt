add_executable(keyball61 layout.c main.c keymap.c)

pico_set_program_name(keyball61 "keyball61")
pico_set_program_version(keyball61 "0.0.1-alpha.0")
pico_set_program_url(keyball61 "https://github.com/koron/keyball-pico")
pico_set_program_description(keyball61 "Keyball61 for RP2040")

pico_enable_stdio_usb(keyball61 1)
pico_enable_stdio_uart(keyball61 0)

target_include_directories(keyball61 PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(keyball61
	diykb
	hardware_spi
	pico_time
	pico_multicore
	pico_binary_info
	pico_bootsel_via_double_reset
	)

pico_add_extra_outputs(keyball61)
