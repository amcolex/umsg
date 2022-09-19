// Generated with umsg_gen on 2022-09-19
#include <umsg.h>
#include <umsg_control.h>

// msg instances
static umsg_msg_metadata_t msg_control_setpoints = {.name = "control_setpoints"};

// msg api's
// control_setpoints
umsg_sub_handle_t umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_control_setpoints, prescaler, sizeof(umsg_control_setpoints_t), length, 0);
}
umsg_sub_handle_t umsg_control_setpoints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_control_setpoints, prescaler, sizeof(umsg_control_setpoints_t), length, channel);
}
void umsg_control_setpoints_publish(umsg_control_setpoints_t* data)
{
    umsg_publish(&msg_control_setpoints, data, 0);
}
void umsg_control_setpoints_publish_ch(umsg_control_setpoints_t* data, uint8_t channel)
{
    umsg_publish(&msg_control_setpoints, data, channel);
}
uint8_t umsg_control_setpoints_receive(umsg_sub_handle_t queue, umsg_control_setpoints_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_control_setpoints_peek(umsg_control_setpoints_t* data)
{
    return umsg_peek(&msg_control_setpoints, data, sizeof(umsg_control_setpoints_t));
}

