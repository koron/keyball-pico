add_library(diykb INTERFACE)

target_include_directories(diykb INTERFACE .)

target_sources(diykb INTERFACE
	#action.c
	#kbd.c
	#keycode.c
	#layer.c
	backlight.c
	ledarray.c
	matrix.c
	)

target_link_libraries(diykb INTERFACE
	pico_stdlib
	#pico_unique_id
	hardware_pio
	hardware_dma
	#tinyusb_device
	#tinyusb_board
	)
