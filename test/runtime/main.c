//
// Created by alexp on 9/6/2022.
//

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

static void publisher(void* pvParameters);

void main(void)
{
    printf("Hello world!");
    xTaskCreate(publisher, "publisher", 1000, NULL, 1, NULL);
}


static void publisher(void* pvParameters)
{
    while(1)
    {
        printf("Hello world!");
        vTaskDelay(1000);
    }
}