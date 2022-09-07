//
// Created by A.Pabouctsidis on 9/7/2022.
//

#include <umsg_types.h>

void * umsg_port_malloc(uint32_t size)
{
    return 0;
}
umsg_queue_handle_t umsg_port_queue_create(uint32_t size, uint8_t length)
{
    return 0;
}
void * umsg_port_queue_send(void * queue, void * data)
{
    return 0;
}
uint8_t umsg_port_queue_receive(umsg_queue_handle_t queue, void * data, uint32_t timeout)
{
    return 0;
}