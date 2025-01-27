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
  ENUM_A,
  ENUM_B,
  ENUM_C
} umsg_test_enum_test_t;


// enumeration of topics
typedef enum
{
  TEST_FLOATS,
  TEST_UINTS,
  TEST_INTS,
  TEST_STRINGS,
  TEST_BOOLS,
  TEST_ENUMS,
  TEST_BITFIELD
} umsg_enum_test_t;


typedef struct
{
  float  single;
  double double_var;
  float  single_array[3];
  double double_array[3];
} umsg_test_floats_t;

typedef struct
{
  uint8_t  u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;
  uint8_t  u8array[3];
  uint16_t u16array[3];
  uint32_t u32array[3];
  uint64_t u64array[3];
} umsg_test_uints_t;

typedef struct
{
  int8_t  i8;
  int16_t i16;
  int32_t i32;
  int64_t i64;
  int8_t  i8array[3];
  int16_t i16array[3];
  int32_t i32array[3];
  int64_t i64array[3];
} umsg_test_ints_t;

typedef struct
{
  char single;
  char array[20];
} umsg_test_strings_t;

typedef struct
{
  bool a;
  bool b[3];
} umsg_test_bools_t;

typedef struct
{
  umsg_test_enum_test_t single_enum;
  umsg_test_enum_test_t enum_array[3];
} umsg_test_enums_t;

typedef struct
{
  uint8_t a : 1, b : 2, c : 4;
} umsg_test_bitfield_t;

// api function headers
umsg_sub_handle_t umsg_test_floats_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_floats_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_floats_publish(umsg_test_floats_t* data);
void              umsg_test_floats_publish_ch(umsg_test_floats_t* data, uint8_t channel);
uint8_t           umsg_test_floats_receive(umsg_sub_handle_t queue, umsg_test_floats_t* data, uint32_t timeout);
uint8_t           umsg_test_floats_peek(umsg_test_floats_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_floats_serialize(umsg_test_floats_t* data, uint8_t* buffer);
uint8_t  umsg_test_floats_deserialize(umsg_test_floats_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_uints_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_uints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_uints_publish(umsg_test_uints_t* data);
void              umsg_test_uints_publish_ch(umsg_test_uints_t* data, uint8_t channel);
uint8_t           umsg_test_uints_receive(umsg_sub_handle_t queue, umsg_test_uints_t* data, uint32_t timeout);
uint8_t           umsg_test_uints_peek(umsg_test_uints_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_uints_serialize(umsg_test_uints_t* data, uint8_t* buffer);
uint8_t  umsg_test_uints_deserialize(umsg_test_uints_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_ints_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_ints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_ints_publish(umsg_test_ints_t* data);
void              umsg_test_ints_publish_ch(umsg_test_ints_t* data, uint8_t channel);
uint8_t           umsg_test_ints_receive(umsg_sub_handle_t queue, umsg_test_ints_t* data, uint32_t timeout);
uint8_t           umsg_test_ints_peek(umsg_test_ints_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_ints_serialize(umsg_test_ints_t* data, uint8_t* buffer);
uint8_t  umsg_test_ints_deserialize(umsg_test_ints_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_strings_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_strings_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_strings_publish(umsg_test_strings_t* data);
void              umsg_test_strings_publish_ch(umsg_test_strings_t* data, uint8_t channel);
uint8_t           umsg_test_strings_receive(umsg_sub_handle_t queue, umsg_test_strings_t* data, uint32_t timeout);
uint8_t           umsg_test_strings_peek(umsg_test_strings_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_strings_serialize(umsg_test_strings_t* data, uint8_t* buffer);
uint8_t  umsg_test_strings_deserialize(umsg_test_strings_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_bools_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_bools_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_bools_publish(umsg_test_bools_t* data);
void              umsg_test_bools_publish_ch(umsg_test_bools_t* data, uint8_t channel);
uint8_t           umsg_test_bools_receive(umsg_sub_handle_t queue, umsg_test_bools_t* data, uint32_t timeout);
uint8_t           umsg_test_bools_peek(umsg_test_bools_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_bools_serialize(umsg_test_bools_t* data, uint8_t* buffer);
uint8_t  umsg_test_bools_deserialize(umsg_test_bools_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_enums_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_enums_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_enums_publish(umsg_test_enums_t* data);
void              umsg_test_enums_publish_ch(umsg_test_enums_t* data, uint8_t channel);
uint8_t           umsg_test_enums_receive(umsg_sub_handle_t queue, umsg_test_enums_t* data, uint32_t timeout);
uint8_t           umsg_test_enums_peek(umsg_test_enums_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_enums_serialize(umsg_test_enums_t* data, uint8_t* buffer);
uint8_t  umsg_test_enums_deserialize(umsg_test_enums_t* data, uint8_t* buffer);  // this function includes check that the message type is correct

umsg_sub_handle_t umsg_test_bitfield_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_test_bitfield_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void              umsg_test_bitfield_publish(umsg_test_bitfield_t* data);
void              umsg_test_bitfield_publish_ch(umsg_test_bitfield_t* data, uint8_t channel);
uint8_t           umsg_test_bitfield_receive(umsg_sub_handle_t queue, umsg_test_bitfield_t* data, uint32_t timeout);
uint8_t           umsg_test_bitfield_peek(umsg_test_bitfield_t* data);

// function headers for converting to binary format that can be used for message passing or logging the first symbols in the buffer indicate the message class
// and type for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future please take
// care that the messages are build properly to avoid padding issues if the messages are opened on different system
uint32_t umsg_test_bitfield_serialize(umsg_test_bitfield_t* data, uint8_t* buffer);
uint8_t  umsg_test_bitfield_deserialize(umsg_test_bitfield_t* data, uint8_t* buffer);  // this function includes check that the message type is correct


#ifdef __cplusplus
}
#endif
