// Generated with umsg_gen on 2022-09-10
#include <umsg.h>
#include <umsg_battery.h>

// msg instances
static umsg_msg_metadata_t msg_battery_state = {.name = "battery_state"};

// msg api's
// battery_state
umsg_sub_handle_t umsg_battery_state_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_battery_state, prescaler, sizeof(umsg_battery_state_t), length);
}
void umsg_battery_state_publish(umsg_battery_state_t* data)
{
    umsg_publish(&msg_battery_state, data);
}
uint8_t umsg_battery_state_receive(umsg_sub_handle_t queue, umsg_battery_state_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_battery_state_peek(umsg_battery_state_t* data)
{
    return umsg_peek(&msg_battery_state, data, sizeof(umsg_battery_state_t));
}

