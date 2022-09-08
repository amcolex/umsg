//
// Created by alexp on 9/6/2022.
//

#ifndef UMSG_UMSG_PORT_H
#define UMSG_UMSG_PORT_H

#include <umsg_types.h>

void * umsg_port_malloc(uint32_t size);
void * umsg_port_queue_create(uint32_t size, uint8_t length);
void umsg_port_queue_send(void * queue, void * data);
uint8_t umsg_port_queue_receive(umsg_sub_handle_t queue, void * data, uint32_t timeout);

#endif //UMSG_UMSG_PORT_H
