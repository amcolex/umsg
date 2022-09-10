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
add_executable(test_single_publisher_single_subscriber
        test/freertos/single_pub_sub.c)
target_link_libraries(test_single_publisher_single_subscriber uMsgLib freertos_kernel)
add_test(NAME test_single_publisher_single_subscriber COMMAND test_single_publisher_single_subscriber)

add_executable(test_single_publisher_multiple_subscribers
        test/freertos/single_pub_multi_sub.c)
target_link_libraries(test_single_publisher_multiple_subscribers uMsgLib freertos_kernel)
add_test(NAME test_single_publisher_multiple_subscribers COMMAND test_single_publisher_multiple_subscribers)

add_executable(test_message_types
        test/freertos/message_types.c)
target_link_libraries(test_message_types uMsgLib freertos_kernel)
add_test(NAME test_message_types COMMAND test_message_types)


