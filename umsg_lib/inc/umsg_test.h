// Generated with umsg_gen on 2022-09-10
#pragma once
#include <umsg_types.h>

// msg structure typedefs
typedef struct
{
    float single;
    double double_var;
    float single_array[3];
    double double_array[3];
} umsg_test_floats_t;

typedef struct
{
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    uint8_t u8array[3];
    uint16_t u16array[3];
    uint32_t u32array[3];
    uint64_t u64array[3];
} umsg_test_uints_t;

typedef struct
{
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    int8_t i8array[3];
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

// api function headers
umsg_sub_handle_t umsg_test_floats_subscribe(uint32_t prescaler, uint8_t length);
void umsg_test_floats_publish(umsg_test_floats_t* data);
uint8_t umsg_test_floats_receive(umsg_sub_handle_t queue, umsg_test_floats_t* data, uint32_t timeout);
uint8_t umsg_test_floats_peek(umsg_test_floats_t* data);

umsg_sub_handle_t umsg_test_uints_subscribe(uint32_t prescaler, uint8_t length);
void umsg_test_uints_publish(umsg_test_uints_t* data);
uint8_t umsg_test_uints_receive(umsg_sub_handle_t queue, umsg_test_uints_t* data, uint32_t timeout);
uint8_t umsg_test_uints_peek(umsg_test_uints_t* data);

umsg_sub_handle_t umsg_test_ints_subscribe(uint32_t prescaler, uint8_t length);
void umsg_test_ints_publish(umsg_test_ints_t* data);
uint8_t umsg_test_ints_receive(umsg_sub_handle_t queue, umsg_test_ints_t* data, uint32_t timeout);
uint8_t umsg_test_ints_peek(umsg_test_ints_t* data);

umsg_sub_handle_t umsg_test_strings_subscribe(uint32_t prescaler, uint8_t length);
void umsg_test_strings_publish(umsg_test_strings_t* data);
uint8_t umsg_test_strings_receive(umsg_sub_handle_t queue, umsg_test_strings_t* data, uint32_t timeout);
uint8_t umsg_test_strings_peek(umsg_test_strings_t* data);

umsg_sub_handle_t umsg_test_bools_subscribe(uint32_t prescaler, uint8_t length);
void umsg_test_bools_publish(umsg_test_bools_t* data);
uint8_t umsg_test_bools_receive(umsg_sub_handle_t queue, umsg_test_bools_t* data, uint32_t timeout);
uint8_t umsg_test_bools_peek(umsg_test_bools_t* data);

