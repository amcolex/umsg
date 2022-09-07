// Generated with umsg_gen on 2022-09-07

#pragma once
#include <umsg_types.h>

// msg structure typedefs
typedef struct
{
    uint8_t system_ok;
    uint8_t system_critical;
    uint8_t low_battery : 1, critical_battery : 1, low_signal : 1, high_temperature : 1;
} umsg_system_warnings_t;


// api function headers
umsg_queue_handle_t umsg_system_warnings_subscribe(uint32_t prescaler, uint8_t length);
void umsg_system_warnings_publish(umsg_system_warnings_t* data);
uint8_t umsg_system_warnings_receive(umsg_queue_handle_t queue, umsg_system_warnings_t* data, uint32_t timeout);
uint8_t umsg_system_warnings_peek(umsg_system_warnings_t* data);

