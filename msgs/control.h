//
// Created by A.Pabouctsidis on 9/6/2022.
//

#ifndef UMSG_CONTROL_H
#define UMSG_CONTROL_H
#include <umsg_types.h>

typedef struct
{
    float roll;
    float pitch;
    float yaw;
    float thrust;
} msg_control_setpoints_t;

umsg_queue_handle_t umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length);
void umsg_control_setpoints_publish(msg_control_setpoints_t* data);
uint8_t umsg_control_setpoints_receive(umsg_queue_handle_t queue, msg_control_setpoints_t* data, uint32_t timeout);
uint8_t umsg_control_setpoints_peek(msg_control_setpoints_t* data);
#endif //UMSG_CONTROL_H
