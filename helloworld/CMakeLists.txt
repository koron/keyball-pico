add_executable(helloworld main.c)

pico_enable_stdio_usb(helloworld 1)
pico_enable_stdio_uart(helloworld 0)

target_link_libraries(helloworld
	pico_stdlib
	pico_bootsel_via_double_reset)

pico_add_extra_outputs(helloworld)
