// Generated with umsg_gen on 2022-09-19
#include <umsg.h>
#include <umsg_test.h>

// msg instances
static umsg_msg_metadata_t msg_test_floats = {.name = "test_floats"};
static umsg_msg_metadata_t msg_test_uints = {.name = "test_uints"};
static umsg_msg_metadata_t msg_test_ints = {.name = "test_ints"};
static umsg_msg_metadata_t msg_test_strings = {.name = "test_strings"};
static umsg_msg_metadata_t msg_test_bools = {.name = "test_bools"};
static umsg_msg_metadata_t msg_test_enums = {.name = "test_enums"};
static umsg_msg_metadata_t msg_test_bitfield = {.name = "test_bitfield"};

// msg api's
// test_floats
umsg_sub_handle_t umsg_test_floats_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_floats, prescaler, sizeof(umsg_test_floats_t), length, 0);
}
umsg_sub_handle_t umsg_test_floats_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_floats, prescaler, sizeof(umsg_test_floats_t), length, channel);
}
void umsg_test_floats_publish(umsg_test_floats_t* data)
{
    umsg_publish(&msg_test_floats, data, 0);
}
void umsg_test_floats_publish_ch(umsg_test_floats_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_floats, data, channel);
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
    return umsg_subscribe(&msg_test_uints, prescaler, sizeof(umsg_test_uints_t), length, 0);
}
umsg_sub_handle_t umsg_test_uints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_uints, prescaler, sizeof(umsg_test_uints_t), length, channel);
}
void umsg_test_uints_publish(umsg_test_uints_t* data)
{
    umsg_publish(&msg_test_uints, data, 0);
}
void umsg_test_uints_publish_ch(umsg_test_uints_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_uints, data, channel);
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
    return umsg_subscribe(&msg_test_ints, prescaler, sizeof(umsg_test_ints_t), length, 0);
}
umsg_sub_handle_t umsg_test_ints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_ints, prescaler, sizeof(umsg_test_ints_t), length, channel);
}
void umsg_test_ints_publish(umsg_test_ints_t* data)
{
    umsg_publish(&msg_test_ints, data, 0);
}
void umsg_test_ints_publish_ch(umsg_test_ints_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_ints, data, channel);
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
    return umsg_subscribe(&msg_test_strings, prescaler, sizeof(umsg_test_strings_t), length, 0);
}
umsg_sub_handle_t umsg_test_strings_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_strings, prescaler, sizeof(umsg_test_strings_t), length, channel);
}
void umsg_test_strings_publish(umsg_test_strings_t* data)
{
    umsg_publish(&msg_test_strings, data, 0);
}
void umsg_test_strings_publish_ch(umsg_test_strings_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_strings, data, channel);
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
    return umsg_subscribe(&msg_test_bools, prescaler, sizeof(umsg_test_bools_t), length, 0);
}
umsg_sub_handle_t umsg_test_bools_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_bools, prescaler, sizeof(umsg_test_bools_t), length, channel);
}
void umsg_test_bools_publish(umsg_test_bools_t* data)
{
    umsg_publish(&msg_test_bools, data, 0);
}
void umsg_test_bools_publish_ch(umsg_test_bools_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_bools, data, channel);
}
uint8_t umsg_test_bools_receive(umsg_sub_handle_t queue, umsg_test_bools_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_bools_peek(umsg_test_bools_t* data)
{
    return umsg_peek(&msg_test_bools, data, sizeof(umsg_test_bools_t));
}

// test_enums
umsg_sub_handle_t umsg_test_enums_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_enums, prescaler, sizeof(umsg_test_enums_t), length, 0);
}
umsg_sub_handle_t umsg_test_enums_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_enums, prescaler, sizeof(umsg_test_enums_t), length, channel);
}
void umsg_test_enums_publish(umsg_test_enums_t* data)
{
    umsg_publish(&msg_test_enums, data, 0);
}
void umsg_test_enums_publish_ch(umsg_test_enums_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_enums, data, channel);
}
uint8_t umsg_test_enums_receive(umsg_sub_handle_t queue, umsg_test_enums_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_enums_peek(umsg_test_enums_t* data)
{
    return umsg_peek(&msg_test_enums, data, sizeof(umsg_test_enums_t));
}

// test_bitfield
umsg_sub_handle_t umsg_test_bitfield_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_test_bitfield, prescaler, sizeof(umsg_test_bitfield_t), length, 0);
}
umsg_sub_handle_t umsg_test_bitfield_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_test_bitfield, prescaler, sizeof(umsg_test_bitfield_t), length, channel);
}
void umsg_test_bitfield_publish(umsg_test_bitfield_t* data)
{
    umsg_publish(&msg_test_bitfield, data, 0);
}
void umsg_test_bitfield_publish_ch(umsg_test_bitfield_t* data, uint8_t channel)
{
    umsg_publish(&msg_test_bitfield, data, channel);
}
uint8_t umsg_test_bitfield_receive(umsg_sub_handle_t queue, umsg_test_bitfield_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_test_bitfield_peek(umsg_test_bitfield_t* data)
{
    return umsg_peek(&msg_test_bitfield, data, sizeof(umsg_test_bitfield_t));
}

