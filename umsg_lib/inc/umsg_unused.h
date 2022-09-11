// Generated with umsg_gen on 2022-09-11
#pragma once
#include <umsg_types.h>

// msg structure typedefs
typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
} umsg_unused_used_var_t;

typedef struct
{
    uint64_t a[512];
} umsg_unused_unused_var_t;

// api function headers
umsg_sub_handle_t umsg_unused_used_var_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_unused_used_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_unused_used_var_publish(umsg_unused_used_var_t* data);
void umsg_unused_used_var_publish_ch(umsg_unused_used_var_t* data, uint8_t channel);
uint8_t umsg_unused_used_var_receive(umsg_sub_handle_t queue, umsg_unused_used_var_t* data, uint32_t timeout);
uint8_t umsg_unused_used_var_peek(umsg_unused_used_var_t* data);

umsg_sub_handle_t umsg_unused_unused_var_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_unused_unused_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_unused_unused_var_publish(umsg_unused_unused_var_t* data);
void umsg_unused_unused_var_publish_ch(umsg_unused_unused_var_t* data, uint8_t channel);
uint8_t umsg_unused_unused_var_receive(umsg_sub_handle_t queue, umsg_unused_unused_var_t* data, uint32_t timeout);
uint8_t umsg_unused_unused_var_peek(umsg_unused_unused_var_t* data);

