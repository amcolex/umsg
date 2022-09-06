//
// Created by alexp on 9/6/2022.
//

#ifndef UMSG_UMSG_H
#define UMSG_UMSG_H
#include <umsg_port.h>

typedef struct
{
    void * queue_handle;
    uint32_t prescaler;
    void* next_sub;
} umsg_sub_t;

typedef struct
{
    umsg_sub_t* sub_list;
    void* msg_value;
    uint32_t counter;
} umsg_msg_metadata_t;

typedef struct {
    umsg_msg_metadata_t sensor_imu;
    umsg_msg_metadata_t control_setpoints;
} umsg_msg_instance_t;


#endif //UMSG_UMSG_H
