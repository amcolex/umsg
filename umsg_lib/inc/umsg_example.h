// Generated with umsg_gen on 2024-08-07
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <umsg_types.h>

#include "umsg_classes.h"
// msg structure typedefs

typedef enum
{
  GREEN,
  BLUE,
  READ
} umsg_example_colors_t;


// enumeration of topics
typedef enum
{
  EXAMPLE_COLOR_SELECTION,
  EXAMPLE_SIMPLE_MSG
} umsg_enum_example_t;


typedef struct
{
  umsg_example_colors_t chosen_color;
} umsg_example_color_selection_t;

typedef struct
{
  char    name[10];
  uint8_t age;
  float   height;
  uint8_t married : 1, has_children : 1, has_dog : 1;
} umsg_example_simple_msg_t;

// api function headers
umsg_sub_handle_t umsg_example_color_selection_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_example_color_selection_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_example_color_selection_publish(umsg_example_color_selection_t* data);
void              umsg_example_color_selection_publish_ch(umsg_example_color_selection_t* data, uint8_t channel);
uint8_t           umsg_example_color_selection_receive(umsg_sub_handle_t queue, umsg_example_color_selection_t* data, uint32_t timeout);
uint8_t           umsg_example_color_selection_peek(umsg_example_color_selection_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_example_color_selection_serialize(umsg_example_color_selection_t* data, uint8_t* buffer);
uint8_t  umsg_example_color_selection_deserialize(umsg_example_color_selection_t* data,
                                                  uint8_t*                        buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_example_simple_msg_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_example_simple_msg_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_example_simple_msg_publish(umsg_example_simple_msg_t* data);
void              umsg_example_simple_msg_publish_ch(umsg_example_simple_msg_t* data, uint8_t channel);
uint8_t           umsg_example_simple_msg_receive(umsg_sub_handle_t queue, umsg_example_simple_msg_t* data, uint32_t timeout);
uint8_t           umsg_example_simple_msg_peek(umsg_example_simple_msg_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_example_simple_msg_serialize(umsg_example_simple_msg_t* data, uint8_t* buffer);
uint8_t umsg_example_simple_msg_deserialize(umsg_example_simple_msg_t* data, uint8_t* buffer);  // this function includes check that the message type is correct


#ifdef __cplusplus
}
#endif
