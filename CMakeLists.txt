cmake_minimum_required(VERSION 3.15)
project(uMsgTest)

# we'll be running tests
include(CTest)

# generate umsg_lib directory
execute_process(COMMAND python ./umsg_gen/umsg_gen/umsg_gen.py -d ./msg_defs -o ./umsg_lib
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


# configure FreeRTOS
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "FreeRTOS Directory")
set(FREERTOS_HEAP "4" CACHE STRING "Memory heap type")

# if select MinGW or GCC POSIX port based on the host OS
if(WIN32)
    set(FREERTOS_PORT "MSVC_MINGW" CACHE STRING "FreeRTOS Port")
else()
    set(FREERTOS_PORT "GCC_POSIX" CACHE STRING "FreeRTOS Port")
    add_compile_options(-m32)
    add_link_options(-m32)
endif()

# Choose umsg port
set(UMSG_PORT "FREERTOS")

# add umsg and FreeRTOS libs
add_subdirectory(umsg_lib)
add_subdirectory(FreeRTOS-Kernel)

# link umsg with freertos
target_link_libraries(uMsgLib freertos_kernel)

# create and link test executables
# test single producer single consumer
add_executable(test_single_publisher_single_subscriber
        tests/freertos/test_single_pub_sub.c)
target_link_libraries(test_single_publisher_single_subscriber uMsgLib freertos_kernel)
add_test(NAME test_single_publisher_single_subscriber COMMAND test_single_publisher_single_subscriber)

# test single producer multiple consumer
add_executable(test_single_publisher_multiple_subscribers
        tests/freertos/test_single_pub_multi_sub.c)
target_link_libraries(test_single_publisher_multiple_subscribers uMsgLib freertos_kernel)
add_test(NAME test_single_publisher_multiple_subscribers COMMAND test_single_publisher_multiple_subscribers)

# test all message type primitives
add_executable(test_message_types
        tests/freertos/test_types.c)
target_link_libraries(test_message_types uMsgLib freertos_kernel)
add_test(NAME test_message_types COMMAND test_message_types)

# test message peeking
add_executable(test_peek
        tests/freertos/test_peek.c)
target_link_libraries(test_peek uMsgLib freertos_kernel)
add_test(NAME test_peek COMMAND test_peek)

# test subscribe prescaler
add_executable(test_prescaler
        tests/freertos/test_prescaler.c)
target_link_libraries(test_prescaler uMsgLib freertos_kernel)
add_test(NAME test_prescaler COMMAND test_prescaler)

# test variable queue length
add_executable(test_length
        tests/freertos/test_length.c)
target_link_libraries(test_length uMsgLib freertos_kernel)
add_test(NAME test_length COMMAND test_length)

# test multi channel
add_executable(test_multi_channel
        tests/freertos/test_multi_channels.c)
target_link_libraries(test_multi_channel uMsgLib freertos_kernel)
add_test(NAME test_multi_channel COMMAND test_multi_channel)

# test code size with unused messages with linker option (look at generated .map files to compare) (doesn't work on Mingw)
add_executable(test_unused_messages_no_code_removal
        tests/freertos/test_unused_messages.c)
target_link_libraries(test_unused_messages_no_code_removal uMsgLib freertos_kernel)
target_link_options(test_unused_messages_no_code_removal PRIVATE  -Xlinker -Map=no_code_removal.map )

add_executable(test_unused_messages_with_code_removal
        tests/freertos/test_unused_messages.c)
target_link_libraries(test_unused_messages_with_code_removal uMsgLib freertos_kernel)
target_link_options(test_unused_messages_with_code_removal PRIVATE -Wl,--gc-sections -Xlinker -Map=with_code_removal.map )

