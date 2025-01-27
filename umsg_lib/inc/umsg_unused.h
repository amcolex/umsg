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
  UNUSED_USED_VAR,
  UNUSED_UNUSED_VAR
} umsg_enum_unused_t;


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
void              umsg_unused_used_var_publish(umsg_unused_used_var_t* data);
void              umsg_unused_used_var_publish_ch(umsg_unused_used_var_t* data, uint8_t channel);
uint8_t           umsg_unused_used_var_receive(umsg_sub_handle_t queue, umsg_unused_used_var_t* data, uint32_t timeout);
uint8_t           umsg_unused_used_var_peek(umsg_unused_used_var_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_unused_used_var_serialize(umsg_unused_used_var_t* data, uint8_t* buffer);
uint8_t  umsg_unused_used_var_deserialize(umsg_unused_used_var_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_unused_unused_var_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_unused_unused_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_unused_unused_var_publish(umsg_unused_unused_var_t* data);
void              umsg_unused_unused_var_publish_ch(umsg_unused_unused_var_t* data, uint8_t channel);
uint8_t           umsg_unused_unused_var_receive(umsg_sub_handle_t queue, umsg_unused_unused_var_t* data, uint32_t timeout);
uint8_t           umsg_unused_unused_var_peek(umsg_unused_unused_var_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_unused_unused_var_serialize(umsg_unused_unused_var_t* data, uint8_t* buffer);
uint8_t  umsg_unused_unused_var_deserialize(umsg_unused_unused_var_t* data, uint8_t* buffer);  // this function includes check that the message type is correct


#ifdef __cplusplus
}
#endif
