//
// Created by alexp on 9/6/2022.
//

#ifndef UMSG_UMSG_PORT_H
#define UMSG_UMSG_PORT_H

#include <umsg.h>

void * umsg_port_malloc(uint32_t size);
void * umsg_port_create(uint32_t size, uint8_t length);
void umsg_port_send(umsg_sub_t* sub, void * data);
uint8_t umsg_port_receive(umsg_sub_handle_t sub_handle, void * data, uint32_t timeout);

#endif //UMSG_UMSG_PORT_H
