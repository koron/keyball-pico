cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD sparkfun_promicro)

include(pico_sdk_import.cmake)

project(keyball-pico C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(diykb)

add_subdirectory(helloworld)
add_subdirectory(keyball61)
