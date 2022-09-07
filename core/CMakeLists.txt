add_library(uMsg_core STATIC
        src/umsg.c)

if ("${UMSG_PORT}" STREQUAL "UMSG_PORT_FREERTOS")
    target_sources(uMsg_core src/port_freertos.c)
endif ()

target_include_directories(uMsg_core PUBLIC inc)