cmake_minimum_required(VERSION 3.20)
project(uMsg)

add_subdirectory(core)
add_library(uMsg STATIC output/control.c
        output/sensors.c)

target_include_directories(uMsg PUBLIC output)

set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(FREERTOS_HEAP "5")
set(FREERTOS_PORT "MSVC_MINGW")
add_subdirectory(FreeRTOS-Kernel)

target_link_libraries(uMsg uMsg_core freertos_kernel)

add_executable(uMsgTest
        test/runtime/main.c
        test/runtime/main_blinky.c)

target_link_libraries(uMsgTest uMsg)