// Generated with umsg_gen on 2022-09-07
#include <umsg.h>
#include <umsg_system.h>

// msg instances
static umsg_msg_metadata_t msg_system_warnings = {.name = "system_warnings"};

// msg api's
// system_warnings
umsg_queue_handle_t umsg_system_warnings_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_system_warnings, prescaler, sizeof(umsg_system_warnings_t), length);
}
void umsg_system_warnings_publish(umsg_system_warnings_t* data)
{
    umsg_publish(&msg_system_warnings, data);
}
uint8_t umsg_system_warnings_receive(umsg_queue_handle_t queue, umsg_system_warnings_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_system_warnings_peek(umsg_system_warnings_t* data)
{
    return umsg_peek(&msg_system_warnings, data, sizeof(umsg_system_warnings_t));
}

