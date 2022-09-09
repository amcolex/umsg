//
// Created by alexp on 9/6/2022.
//
#include <umsg.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <stdint.h>

// obtained from cmsis core.h. All cortex M processors have this register at this address
const uint32_t* ARM_CORTEX_ICSR = (uint32_t*)(0xE000E000UL+0x0D00UL+0x004);
const uint32_t SCB_ICSR_VECTACTIVE_POS = 0x1FFUL;

bool is_isr_active()
{
#if defined(__GNUC__) && defined(__arm__)
    // if the current active vector is 0, then we are not in an ISR
    return (*ARM_CORTEX_ICSR & SCB_ICSR_VECTACTIVE_POS) != 0;
#endif
    return false;
}

void * umsg_port_malloc(uint32_t size)
{
    return pvPortMalloc(size);
}

umsg_sub_handle_t umsg_port_create(uint32_t size, uint8_t length)
{
    return xQueueCreate(length, size);
}

void umsg_port_send(umsg_sub_t* sub, void * data)
{
    QueueHandle_t queue = (QueueHandle_t)sub->sub_handle;
    if(sub->length > 1)
    {
        if(is_isr_active())
        {
            xQueueSendToBack(queue, data, 0);
        }
        else
        {
            BaseType_t xHigherPriorityTaskWoken;
            xQueueSendToBackFromISR(queue, data,
                                    &xHigherPriorityTaskWoken);
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
    else
    {
        // check if in interrupt context
        if(is_isr_active())
        {
            xQueueOverwrite(queue, data);
        }
        else
        {
            BaseType_t xHigherPriorityTaskWoken;
            xQueueOverwriteFromISR(queue, data,
                                   &xHigherPriorityTaskWoken);
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
}

uint8_t umsg_port_receive(umsg_sub_handle_t sub_handle, void * data, uint32_t timeout)
{
    return xQueueReceive((QueueHandle_t)sub_handle, data, timeout);
}