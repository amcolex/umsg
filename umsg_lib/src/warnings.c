// Generated with umsg_gen on 2022-09-07
#include <umsg.h>
#include <umsg_warnings.h>

// msg instances
static umsg_msg_metadata_t msg_warnings_battery = {.name = "warnings_battery"};

// msg api's
// warnings_battery
umsg_queue_handle_t umsg_warnings_battery_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_warnings_battery, prescaler, sizeof(umsg_warnings_battery_t), length);
}
void umsg_warnings_battery_publish(umsg_warnings_battery_t* data)
{
    umsg_publish(&msg_warnings_battery, data);
}
uint8_t umsg_warnings_battery_receive(umsg_queue_handle_t queue, umsg_warnings_battery_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_warnings_battery_peek(umsg_warnings_battery_t* data)
{
    return umsg_peek(&msg_warnings_battery, data, sizeof(umsg_warnings_battery_t));
}

