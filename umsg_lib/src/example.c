// Generated with umsg_gen on 2022-09-19
#include <umsg.h>
#include <umsg_example.h>

// msg instances
static umsg_msg_metadata_t msg_example_color_selection = {.name = "example_color_selection"};
static umsg_msg_metadata_t msg_example_simple_msg = {.name = "example_simple_msg"};

// msg api's
// example_color_selection
umsg_sub_handle_t umsg_example_color_selection_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_example_color_selection, prescaler, sizeof(umsg_example_color_selection_t), length, 0);
}
umsg_sub_handle_t umsg_example_color_selection_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_example_color_selection, prescaler, sizeof(umsg_example_color_selection_t), length, channel);
}
void umsg_example_color_selection_publish(umsg_example_color_selection_t* data)
{
    umsg_publish(&msg_example_color_selection, data, 0);
}
void umsg_example_color_selection_publish_ch(umsg_example_color_selection_t* data, uint8_t channel)
{
    umsg_publish(&msg_example_color_selection, data, channel);
}
uint8_t umsg_example_color_selection_receive(umsg_sub_handle_t queue, umsg_example_color_selection_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_example_color_selection_peek(umsg_example_color_selection_t* data)
{
    return umsg_peek(&msg_example_color_selection, data, sizeof(umsg_example_color_selection_t));
}

// example_simple_msg
umsg_sub_handle_t umsg_example_simple_msg_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_example_simple_msg, prescaler, sizeof(umsg_example_simple_msg_t), length, 0);
}
umsg_sub_handle_t umsg_example_simple_msg_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_example_simple_msg, prescaler, sizeof(umsg_example_simple_msg_t), length, channel);
}
void umsg_example_simple_msg_publish(umsg_example_simple_msg_t* data)
{
    umsg_publish(&msg_example_simple_msg, data, 0);
}
void umsg_example_simple_msg_publish_ch(umsg_example_simple_msg_t* data, uint8_t channel)
{
    umsg_publish(&msg_example_simple_msg, data, channel);
}
uint8_t umsg_example_simple_msg_receive(umsg_sub_handle_t queue, umsg_example_simple_msg_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_example_simple_msg_peek(umsg_example_simple_msg_t* data)
{
    return umsg_peek(&msg_example_simple_msg, data, sizeof(umsg_example_simple_msg_t));
}

