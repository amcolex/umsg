// Generated with umsg_gen on 2022-09-09
#include <umsg.h>
#include <umsg_test.h>

// msg instances
static umsg_msg_metadata_t msg_test_floats = {.name = "test_floats"};
static umsg_msg_metadata_t msg_test_uints = {.name = "test_uints"};
static umsg_msg_metadata_t msg_test_ints = {.name = "test_ints"};
static umsg_msg_metadata_t msg_test_strings = {.name = "test_strings"};
static umsg_msg_metadata_t msg_test_bools = {.name = "test_bools"};

// msg api's
// test_floats
umsg_sub_handle_t umsg_test_floats_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_floats, prescaler, sizeof(umsg_test_floats_t), length);
}
void umsg_test_floats_publish(umsg_test_floats_t* data)
{
    umsg_publish(&msg_test_floats, data);
}
uint8_t umsg_test_floats_receive(umsg_sub_handle_t queue, umsg_test_floats_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_floats_peek(umsg_test_floats_t* data)
{
    return umsg_peek(&msg_test_floats, data, sizeof(umsg_test_floats_t));
}

// test_uints
umsg_sub_handle_t umsg_test_uints_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_uints, prescaler, sizeof(umsg_test_uints_t), length);
}
void umsg_test_uints_publish(umsg_test_uints_t* data)
{
    umsg_publish(&msg_test_uints, data);
}
uint8_t umsg_test_uints_receive(umsg_sub_handle_t queue, umsg_test_uints_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_uints_peek(umsg_test_uints_t* data)
{
    return umsg_peek(&msg_test_uints, data, sizeof(umsg_test_uints_t));
}

// test_ints
umsg_sub_handle_t umsg_test_ints_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_ints, prescaler, sizeof(umsg_test_ints_t), length);
}
void umsg_test_ints_publish(umsg_test_ints_t* data)
{
    umsg_publish(&msg_test_ints, data);
}
uint8_t umsg_test_ints_receive(umsg_sub_handle_t queue, umsg_test_ints_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_ints_peek(umsg_test_ints_t* data)
{
    return umsg_peek(&msg_test_ints, data, sizeof(umsg_test_ints_t));
}

// test_strings
umsg_sub_handle_t umsg_test_strings_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_strings, prescaler, sizeof(umsg_test_strings_t), length);
}
void umsg_test_strings_publish(umsg_test_strings_t* data)
{
    umsg_publish(&msg_test_strings, data);
}
uint8_t umsg_test_strings_receive(umsg_sub_handle_t queue, umsg_test_strings_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_strings_peek(umsg_test_strings_t* data)
{
    return umsg_peek(&msg_test_strings, data, sizeof(umsg_test_strings_t));
}

// test_bools
umsg_sub_handle_t umsg_test_bools_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_bools, prescaler, sizeof(umsg_test_bools_t), length);
}
void umsg_test_bools_publish(umsg_test_bools_t* data)
{
    umsg_publish(&msg_test_bools, data);
}
uint8_t umsg_test_bools_receive(umsg_sub_handle_t queue, umsg_test_bools_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_bools_peek(umsg_test_bools_t* data)
{
    return umsg_peek(&msg_test_bools, data, sizeof(umsg_test_bools_t));
}

