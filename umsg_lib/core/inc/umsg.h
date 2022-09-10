//
// Created by alexp on 9/6/2022.
//

#ifndef UMSG_UMSG_H
#define UMSG_UMSG_H
#include <umsg_types.h>

typedef struct
{
    umsg_sub_handle_t sub_handle;
    uint16_t prescaler;
    uint8_t length;
    uint8_t channel;
    void* next_sub;
} umsg_sub_t;

typedef struct
{
    umsg_sub_t* sub_list;
    void* msg_value;
    uint32_t counter;
    char* name;
} umsg_msg_metadata_t;

umsg_sub_handle_t umsg_subscribe(umsg_msg_metadata_t* msg, uint16_t prescaler, uint32_t size, uint8_t length, uint8_t ch_id);
void umsg_publish(umsg_msg_metadata_t* msg, void* data, uint8_t ch_id);
uint8_t umsg_receive(umsg_sub_handle_t queue, void* data, uint32_t timeout);
uint8_t umsg_peek(umsg_msg_metadata_t* msg, void* data, uint32_t size);

#endif //UMSG_UMSG_H
