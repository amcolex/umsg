//
// Created by A.Pabouctsidis on 9/6/2022.
//

#include <FreeRTOS.h>
#include <Queue.h>
#include <stdint.h>

#include "../msgs/sensors.h"
#include "../msgs/control.h"


typedef struct
{
    QueueHandle_t queue;
    uint32_t prescaler
} umsg_sub_t;

typedef struct
{
    umsg_sub_t sub;
    umsg_sub_t* next_sub;
} umsg_sub_linked_list_t;

typedef struct
{
    umsg_sub_linked_list_t* subs;
} umsg_t;