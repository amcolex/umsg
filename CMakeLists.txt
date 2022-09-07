cmake_minimum_required(VERSION 3.15)
project(uMsgTest)

# Choose UMSG port
set(UMSG_PORT "FREERTOS")

# config and add umsg library
add_subdirectory(umsg_lib)

# FreeRTOS Test Executable
if("${UMSG_PORT}" STREQUAL "FREERTOS")
    # config and add freertos library
    set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    set(FREERTOS_HEAP "5")
    set(FREERTOS_PORT "MSVC_MINGW")
    add_subdirectory(FreeRTOS-Kernel)
    
    # link umsg with freertos
    target_link_libraries(uMsgLib freertos_kernel)
    
    # create test executable
    add_executable(uMsgTest
            test/freertos/main.c
            test/freertos/main_blinky.c)
    
    # link test executable with umsg & freertos
    target_link_libraries(uMsgTest uMsgLib freertos_kernel)
endif()
