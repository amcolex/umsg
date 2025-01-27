// Generated with umsg_gen on 2024-08-07
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <umsg_types.h>

#include "umsg_classes.h"
// msg structure typedefs

// enumeration of topics
typedef enum
{
  CONTROL_SETPOINTS
} umsg_enum_control_t;


typedef struct
{
  float w[3];
  float vel_b[3];
  float quat[4];
} umsg_control_setpoints_t;

// api function headers
umsg_sub_handle_t umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_control_setpoints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_control_setpoints_publish(umsg_control_setpoints_t* data);
void              umsg_control_setpoints_publish_ch(umsg_control_setpoints_t* data, uint8_t channel);
uint8_t           umsg_control_setpoints_receive(umsg_sub_handle_t queue, umsg_control_setpoints_t* data, uint32_t timeout);
uint8_t           umsg_control_setpoints_peek(umsg_control_setpoints_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_control_setpoints_serialize(umsg_control_setpoints_t* data, uint8_t* buffer);
uint8_t  umsg_control_setpoints_deserialize(umsg_control_setpoints_t* data, uint8_t* buffer);  // this function includes check that the message type is correct


#ifdef __cplusplus
}
#endif
