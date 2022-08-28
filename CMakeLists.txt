cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(keyball-pico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (NOT PICO_BOARD)
    set(PICO_BOARD sparkfun_promicro)
endif()
if (NOT DIYKB_PATH)
    set(DIYKB_PATH ../yuiop60pi/diykb)
endif()

pico_sdk_init()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(${DIYKB_PATH} diykb)
add_subdirectory(keyball61)

# vim:set ts=8 sts=4 sw=4 tw=0 et:
