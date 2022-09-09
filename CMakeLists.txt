cmake_minimum_required(VERSION 3.15)
project(uMsgTest)

# we'll be running tests
include(CTest)

# generate umsg_lib directory
execute_process(COMMAND python .\\umsg_gen\\umsg_gen\\umsg_gen.py -d ./messages -o ./umsg_lib
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Choose umsg port
set(UMSG_PORT "FREERTOS")

# config and add umsg library
add_subdirectory(umsg_lib)

# FreeRTOS Test Executable
# config and add freertos library
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "FreeRTOS Directory")
set(FREERTOS_HEAP "4" CACHE STRING "Memory heap type")
set(FREERTOS_PORT "MSVC_MINGW" CACHE STRING "FreeRTOS Port")

add_subdirectory(FreeRTOS-Kernel)

# link umsg with freertos
target_link_libraries(uMsgLib freertos_kernel)

# create and link test executables
add_executable(uMsgTest
        test/freertos/single_pub_sub.c)
target_link_libraries(uMsgTest uMsgLib freertos_kernel)
add_test(NAME uMsgTest COMMAND uMsgTest)


