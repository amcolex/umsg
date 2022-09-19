// Generated with umsg_gen on 2022-09-19
#include <umsg.h>
#include <umsg_unused.h>

// msg instances
static umsg_msg_metadata_t msg_unused_used_var = {.name = "unused_used_var"};
static umsg_msg_metadata_t msg_unused_unused_var = {.name = "unused_unused_var"};

// msg api's
// unused_used_var
umsg_sub_handle_t umsg_unused_used_var_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_unused_used_var, prescaler, sizeof(umsg_unused_used_var_t), length, 0);
}
umsg_sub_handle_t umsg_unused_used_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_unused_used_var, prescaler, sizeof(umsg_unused_used_var_t), length, channel);
}
void umsg_unused_used_var_publish(umsg_unused_used_var_t* data)
{
    umsg_publish(&msg_unused_used_var, data, 0);
}
void umsg_unused_used_var_publish_ch(umsg_unused_used_var_t* data, uint8_t channel)
{
    umsg_publish(&msg_unused_used_var, data, channel);
}
uint8_t umsg_unused_used_var_receive(umsg_sub_handle_t queue, umsg_unused_used_var_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_unused_used_var_peek(umsg_unused_used_var_t* data)
{
    return umsg_peek(&msg_unused_used_var, data, sizeof(umsg_unused_used_var_t));
}

// unused_unused_var
umsg_sub_handle_t umsg_unused_unused_var_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_unused_unused_var, prescaler, sizeof(umsg_unused_unused_var_t), length, 0);
}
umsg_sub_handle_t umsg_unused_unused_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel)
{
    return umsg_subscribe(&msg_unused_unused_var, prescaler, sizeof(umsg_unused_unused_var_t), length, channel);
}
void umsg_unused_unused_var_publish(umsg_unused_unused_var_t* data)
{
    umsg_publish(&msg_unused_unused_var, data, 0);
}
void umsg_unused_unused_var_publish_ch(umsg_unused_unused_var_t* data, uint8_t channel)
{
    umsg_publish(&msg_unused_unused_var, data, channel);
}
uint8_t umsg_unused_unused_var_receive(umsg_sub_handle_t queue, umsg_unused_unused_var_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_unused_unused_var_peek(umsg_unused_unused_var_t* data)
{
    return umsg_peek(&msg_unused_unused_var, data, sizeof(umsg_unused_unused_var_t));
}

