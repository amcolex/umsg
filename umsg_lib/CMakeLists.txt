# add core library
add_subdirectory(core)

# create library
add_library(uMsgLib Static
    src/control.c
    src/sensors.c
)
# add includes
target_include_directories(uMsgLib PUBLIC inc)

# link with core library
target_link_libraries(uMsgLib PRIVATE uMsgCore)