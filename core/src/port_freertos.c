//
// Created by alexp on 9/6/2022.
//
#include <umsg_types.h>
#include <FreeRTOS.h>
#include <Queue.h>
#include <stdint.h>

void * umsg_port_malloc(uint32_t size)
{
    return pvPortMalloc(size);
}

umsg_queue_handle_t umsg_port_queue_create(uint32_t size, uint8_t length)
{
    return xQueueCreate(length, size);
}

void * umsg_port_queue_send(void * queue, void * data)
{
    xQueueSend((QueueHandle_t)queue, data, 0);
}

uint8_t umsg_port_queue_receive(umsg_queue_handle_t queue, void * data, uint32_t timeout)
{
    return xQueueReceive((QueueHandle_t)queue, data, timeout);
}