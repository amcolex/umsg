//
// Created by alexp on 9/6/2022.
//
#include <umsg.h>
#include <control.h>

static struct
{
    umsg_msg_metadata_t control_setpoints;
} umsg_control_msgs;

void * umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&umsg_control_msgs.control_setpoints, prescaler, sizeof(msg_control_setpoints_t), length);
}

void umsg_control_setpoints_publish(msg_control_setpoints_t* data)
{
    umsg_publish(&umsg_control_msgs.control_setpoints, data);
}

uint8_t umsg_control_setpoints_receive(umsg_queue_handle_t queue, msg_control_setpoints_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}

uint8_t umsg_control_setpoints_peek(msg_control_setpoints_t* data)
{
    return umsg_peek(&umsg_control_msgs.control_setpoints, data, sizeof(msg_control_setpoints_t));
}