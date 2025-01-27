#include "FreeRTOS.h"
#include "task.h"
#include <umsg_sensors.h>
#include <stdio.h>
#include <stdlib.h>

static void pub_task(void* params);
static void sub_task(void* params);

int main(void) {
  xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
  xTaskCreate(sub_task, "sub_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void sub_task(void* params) {
  umsg_sub_handle_t  sub = umsg_sensors_imu_subscribe(1, 1);
  umsg_sensors_imu_t msg;
  while (1) {
    umsg_sensors_imu_receive(sub, &msg, portMAX_DELAY);
    printf("Received IMU Data!");
    exit(0);
  }
}

static void pub_task(void* params) {
  umsg_sensors_imu_t imu_data = {.accel = {1, 2, 3}, .gyro = {4, 5, 6}, .temperature = 66};
  while (1) {
    umsg_sensors_imu_publish(&imu_data);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
