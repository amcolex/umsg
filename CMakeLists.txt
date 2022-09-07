cmake_minimum_required(VERSION 3.20)
project(uMsgTest)

# config and add umsg library
set(UMSG_PORT "FREERTOS")
add_subdirectory(umsg_lib)

# config and add freertos library
set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(FREERTOS_HEAP "5")
set(FREERTOS_PORT "MSVC_MINGW")
add_subdirectory(FreeRTOS-Kernel)

# link umsg with freertos
target_link_libraries(uMsgLib freertos_kernel)

# create test executable
add_executable(uMsgTest
        test/runtime/main.c
        test/runtime/main_blinky.c)

# link test executable with umsg & freertos
target_link_libraries(uMsgTest uMsgLib freertos_kernel)