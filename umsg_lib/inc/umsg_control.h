// Generated with umsg_gen on 2022-09-17
#pragma once
#include <umsg_types.h>

// msg structure typedefs
typedef struct
{
    float w[3];
    float vel_b[3];
    float quat[4];
} umsg_control_setpoints_t;

// api function headers
umsg_sub_handle_t umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_control_setpoints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_control_setpoints_publish(umsg_control_setpoints_t* data);
void umsg_control_setpoints_publish_ch(umsg_control_setpoints_t* data, uint8_t channel);
uint8_t umsg_control_setpoints_receive(umsg_sub_handle_t queue, umsg_control_setpoints_t* data, uint32_t timeout);
uint8_t umsg_control_setpoints_peek(umsg_control_setpoints_t* data);

