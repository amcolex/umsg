//
// Created by A.Pabouctsidis on 9/6/2022.
//

#include <umsg.h>
#include <umsg_port.h>
#include <string.h>

umsg_sub_handle_t umsg_subscribe(umsg_msg_metadata_t* msg, uint16_t prescaler, uint32_t size, uint8_t length, uint8_t ch_id)
{
    if(msg->sub_list == NULL)
    {
        msg->msg_value = umsg_port_malloc(size);

        msg->sub_list = umsg_port_malloc(sizeof(umsg_sub_t));
        msg->sub_list->sub_handle = umsg_port_create(size,length);
        msg->sub_list->prescaler = prescaler;
        msg->sub_list->length = length;
        msg->sub_list->channel = ch_id;
        msg->sub_list->next_sub = NULL;
        return msg->sub_list->sub_handle;
    }
    else
    {
        umsg_sub_t* sub = msg->sub_list;
        while(sub->next_sub != NULL)
        {
            sub = sub->next_sub;
        }
        sub->next_sub = umsg_port_malloc(sizeof(umsg_sub_t));
        sub = sub->next_sub;
        sub->sub_handle = umsg_port_create(size,length);
        sub->prescaler = prescaler;
        sub->length = length;
        sub->channel = ch_id;
        sub->next_sub = NULL;
        return sub->sub_handle;
    }
}

void umsg_publish(umsg_msg_metadata_t* msg, void* data, uint8_t ch_id)
{
    msg->msg_value = data;
    msg->counter++;
    umsg_sub_t* sub = msg->sub_list;
    while(sub != NULL)
    {
        if(msg->counter % sub->prescaler == 0 && sub->channel == ch_id)
        {
            umsg_port_send(sub, data);
        }
        sub = sub->next_sub;
    }
}

uint8_t umsg_receive(umsg_sub_handle_t queue, void* data, uint32_t timeout)
{
    return umsg_port_receive(queue, data, timeout);
}

uint8_t umsg_peek(umsg_msg_metadata_t* msg, void* data, uint32_t size)
{
    if(msg->counter > 0)
    {
        memcpy(data, msg->msg_value, size);
        return 1;
    }
    return 0;
}