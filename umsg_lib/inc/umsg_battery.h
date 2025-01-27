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
  BATTERY_OK,
  BATTERY_LOW,
  BATTERY_DEAD
} umsg_battery_battery_state_t;


// enumeration of topics
typedef enum
{
  BATTERY_STATE
} umsg_enum_battery_t;


typedef struct
{
  umsg_battery_battery_state_t state;
  uint8_t low_battery : 1, critical_battery : 1, high_temperature : 1, low_temperature : 1, charging : 1, discharging : 1, full : 1, not_present : 1;
} umsg_battery_state_t;

// api function headers
umsg_sub_handle_t umsg_battery_state_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_battery_state_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_battery_state_publish(umsg_battery_state_t* data);
void              umsg_battery_state_publish_ch(umsg_battery_state_t* data, uint8_t channel);
uint8_t           umsg_battery_state_receive(umsg_sub_handle_t queue, umsg_battery_state_t* data, uint32_t timeout);
uint8_t           umsg_battery_state_peek(umsg_battery_state_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_battery_state_serialize(umsg_battery_state_t* data, uint8_t* buffer);
uint8_t  umsg_battery_state_deserialize(umsg_battery_state_t* data, uint8_t* buffer);  // this function includes check that the message type is correct


#ifdef __cplusplus
}
#endif
