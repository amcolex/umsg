//
// Created by alexp on 9/6/2022.
//

#include <FreeRTOS.h>
#include <Queue.h>
#include <stdint.h>

void * umsg_port_malloc(uint32_t size)
{
    return pvPortMalloc(size);
}

void * umsg_port_queue_create(uint32_t size)
{
    return (void*)xQueueCreate(1, size);
}

void * umsg_port_queue_send(void * queue, void * data)
{
    xQueueSend((QueueHandle_t)queue, data, 0);
}