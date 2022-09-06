cmake_minimum_required(VERSION 3.20)
project(uMsg)


add_library(uMsg STATIC
        src/umsg.c
        )

target_include_directories(uMsg PUBLIC msgs inc)

set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(FREERTOS_HEAP "4")
set(FREERTOS_PORT MSVC_MINGW)
add_subdirectory(FreeRTOS-Kernel)

target_link_libraries(uMsg FreeRTOS)