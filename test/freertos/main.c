
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include <umsg_sensors.h>
#include <umsg_battery.h>
static void pub_task(void* params);
static void sub_task(void* params);
static void sub_task2(void* params);
int main( void )
{

    xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
    xTaskCreate(sub_task, "sub_task", 1000, NULL, 1, NULL);
    xTaskCreate(sub_task2, "sub_task", 1000, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1);

    return 0;
}

static void sub_task(void* params)
{
    umsg_sub_handle_t queue = umsg_sensors_imu_subscribe(1,1);
    umsg_sensors_imu_t msg;
    while(1) {
        umsg_sensors_imu_receive(queue,&msg,portMAX_DELAY);
        printf("received imu data! Counter: %f\n",msg.temperature);

    }
}

static void sub_task2(void* params)
{
    umsg_sub_handle_t battery_sub = umsg_battery_state_subscribe(1,1);
    umsg_sub_handle_t imu_sub = umsg_sensors_imu_subscribe(1,1);
    umsg_battery_state_t msg;
    umsg_sensors_imu_t imu_msg;
    while(1) {
        umsg_battery_state_receive(battery_sub,&msg,portMAX_DELAY);
        umsg_sensors_imu_receive(imu_sub,&imu_msg,portMAX_DELAY);
        printf("received battery state & imu! Counter: %d\n",msg.state);

    }
}
static void pub_task(void* params)
{
    uint32_t count = 0;
    umsg_sensors_imu_t imu_data = {.accel= {1,2,3}, .gyro = {4,5,6}, .temperature = 66};
    umsg_battery_state_t battery_data = {.state = 1};
    while(1)
    {
        count++;
        imu_data.temperature = count;
        umsg_sensors_imu_publish(&imu_data);
        battery_data.state = count/2;
        umsg_battery_state_publish(&battery_data);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
    while(1);
}

