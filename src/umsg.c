//
// Created by A.Pabouctsidis on 9/6/2022.
//

#include <umsg.h>
#include <umsg_port.h>

#include "../msgs/sensors.h"
#include "../msgs/control.h"

static umsg_msg_instance_t umsg_msg_instance;

void * subscribe(umsg_msg_metadata_t* msg, uint32_t prescaler)
{
    if(msg->sub_list == NULL)
    {
        msg->sub_list = umsg_port_malloc(sizeof(umsg_sub_t));
        msg->sub_list->queue_handle = umsg_port_queue_create(sizeof(void*));
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
        ((umsg_sub_t*)sub->next_sub)->queue_handle = umsg_port_queue_create(sizeof(void*));
        ((umsg_sub_t*)sub->next_sub)->prescaler = prescaler;
        ((umsg_sub_t*)sub->next_sub)->next_sub = NULL;
        return ((umsg_sub_t*)sub->next_sub)->queue_handle;
    }
}

void publish(umsg_msg_metadata_t* msg, void* data)
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



inline void* umsg_control_setpoints_subscribe(uint32_t prescaler)
{
    return subscribe(&umsg_msg_instance.control_setpoints, prescaler);
}

inline void umsg_control_setpoints_publish(msg_control_setpoints_t* data)
{
    publish(&umsg_msg_instance.control_setpoints, data);
}