# create library
add_library(uMsgLib STATIC
    core/src/umsg.c
    # generated files
    src/control.c
    src/sensors.c
)
# select port
if(NOT DEFINED UMSG_PORT)
    message(FATAL_ERROR "UMSG_PORT is not defined")
endif()

if("${UMSG_PORT}" STREQUAL "FREERTOS")
    target_sources(uMsgLib PRIVATE
            core/src/port_freertos.c
    )
elseif("${UMSG_PORT}" STREQUAL "POSIX")
        target_sources(uMsgLib PRIVATE
                core/src/port_posix.c
        )
endif()

# add includes
target_include_directories(uMsgLib PUBLIC inc core/inc)