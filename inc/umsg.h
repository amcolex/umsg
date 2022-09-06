//
// Created by alexp on 9/6/2022.
//

#ifndef UMSG_UMSG_H
#define UMSG_UMSG_H
#include <umsg_types.h>

typedef struct
{
    umsg_queue_handle_t queue_handle;
    uint32_t prescaler;
    void* next_sub;
} umsg_sub_t;

typedef struct
{
    umsg_sub_t* sub_list;
    void* msg_value;
    uint32_t counter;
    char* name;
} umsg_msg_metadata_t;

umsg_queue_handle_t umsg_subscribe(umsg_msg_metadata_t* msg, uint32_t prescaler, uint32_t size, uint8_t length);
void umsg_publish(umsg_msg_metadata_t* msg, void* data);
uint8_t umsg_receive(umsg_queue_handle_t queue, void* data, uint32_t timeout);
void umsg_peek(umsg_msg_metadata_t* msg, void* data);

#endif //UMSG_UMSG_H
