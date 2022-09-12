// Generated with umsg_gen on 2022-09-12
#pragma once
#include <umsg_types.h>

// msg structure typedefs

typedef enum
{
    GREEN,
    BLUE,
    READ
} umsg_example_colors_t;

typedef struct
{
    umsg_example_colors_t chosen_color;
} umsg_example_color_selection_t;

typedef struct
{
    char name[10];
    uint8_t age;
    float height;
    uint8_t married : 1, has_children : 1, has_dog : 1;
} umsg_example_simple_msg_t;

// api function headers
umsg_sub_handle_t umsg_example_color_selection_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_example_color_selection_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_example_color_selection_publish(umsg_example_color_selection_t* data);
void umsg_example_color_selection_publish_ch(umsg_example_color_selection_t* data, uint8_t channel);
uint8_t umsg_example_color_selection_receive(umsg_sub_handle_t queue, umsg_example_color_selection_t* data, uint32_t timeout);
uint8_t umsg_example_color_selection_peek(umsg_example_color_selection_t* data);

umsg_sub_handle_t umsg_example_simple_msg_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_example_simple_msg_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_example_simple_msg_publish(umsg_example_simple_msg_t* data);
void umsg_example_simple_msg_publish_ch(umsg_example_simple_msg_t* data, uint8_t channel);
uint8_t umsg_example_simple_msg_receive(umsg_sub_handle_t queue, umsg_example_simple_msg_t* data, uint32_t timeout);
uint8_t umsg_example_simple_msg_peek(umsg_example_simple_msg_t* data);

