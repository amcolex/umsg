//
// Created by A.Pabouctsidis on 9/6/2022.
//

#include <umsg.h>
#include <umsg_port.h>
#include <string.h>

umsg_queue_handle_t umsg_subscribe(umsg_msg_metadata_t* msg, uint32_t prescaler, uint32_t size, uint8_t length)
{
    if(msg->sub_list == NULL)
    {
        msg->msg_value = umsg_port_malloc(size);

        msg->sub_list = umsg_port_malloc(sizeof(umsg_sub_t));
        msg->sub_list->queue_handle = umsg_port_queue_create(size,length);
        msg->sub_list->prescaler = prescaler;
        msg->sub_list->next_sub = NULL;
        return msg->sub_list->queue_handle;
    }
    else
    {
        umsg_sub_t* sub = msg->sub_list;
        while(sub->next_sub != NULL)
        {
            sub = sub->next_sub;
        }
        sub->next_sub = umsg_port_malloc(sizeof(umsg_sub_t));
        ((umsg_sub_t*)sub->next_sub)->queue_handle = umsg_port_queue_create(size,length);
        ((umsg_sub_t*)sub->next_sub)->prescaler = prescaler;
        ((umsg_sub_t*)sub->next_sub)->next_sub = NULL;
        return ((umsg_sub_t*)sub->next_sub)->queue_handle;
    }
}

void umsg_publish(umsg_msg_metadata_t* msg, void* data)
{
    msg->msg_value = data;
    msg->counter++;
    umsg_sub_t* sub = msg->sub_list;
    while(sub != NULL)
    {
        if(msg->counter % sub->prescaler == 0)
        {
            umsg_port_queue_send(sub->queue_handle, data);
        }
        sub = sub->next_sub;
    }
}

uint8_t umsg_receive(umsg_queue_handle_t queue, void* data, uint32_t timeout)
{
    return umsg_port_queue_receive(queue, data, timeout);
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