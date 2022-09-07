// Generated with umsg_gen on 2022-09-07

#pragma once
#include <umsg_types.h>

// msg structure typedefs

typedef enum
{
    BATTERY_OK,
    BATTERY_DEAD,
    BATTERY_COLD
} battery_state_t;

typedef struct
{
    battery_state_t state;
    uint8_t system_critical;
    uint8_t low_battery : 1, critical_battery : 1, low_signal : 1, high_temperature : 1;
} umsg_warnings_battery_t;


// api function headers
umsg_queue_handle_t umsg_warnings_battery_subscribe(uint32_t prescaler, uint8_t length);
void umsg_warnings_battery_publish(umsg_warnings_battery_t* data);
uint8_t umsg_warnings_battery_receive(umsg_queue_handle_t queue, umsg_warnings_battery_t* data, uint32_t timeout);
uint8_t umsg_warnings_battery_peek(umsg_warnings_battery_t* data);

