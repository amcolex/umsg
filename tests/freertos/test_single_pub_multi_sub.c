#include "FreeRTOS.h"
#include "task.h"
#include <umsg_sensors.h>
#include <stdio.h>
#include <stdlib.h>

static void pub_task(void* params);
static void sub_task(void* params);

static uint8_t received_flags[3];

int main(void) {
  xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
  xTaskCreate(sub_task, "sub_task1", 1000, "1", 2, NULL);
  xTaskCreate(sub_task, "sub_task2", 1000, "2", 2, NULL);
  xTaskCreate(sub_task, "sub_task3", 1000, "3", 2, NULL);
  vTaskStartScheduler();

  return 0;
}

static void sub_task(void* params) {
  umsg_sub_handle_t  sub = umsg_sensors_imu_subscribe(1, 1);
  umsg_sensors_imu_t msg;
  while (1) {
    umsg_sensors_imu_receive(sub, &msg, portMAX_DELAY);
    printf("Received IMU Data! Task # %s \n", (char*)params);
    received_flags[atoi((char*)params) - 1] = 1;
  }
}

static void pub_task(void* params) {
  umsg_sensors_imu_t imu_data   = {.accel = {1, 2, 3}, .gyro = {4, 5, 6}, .temperature = 66};
  uint8_t            send_count = 0;
  while (1) {
    umsg_sensors_imu_publish(&imu_data);
    send_count++;
    vTaskDelay(pdMS_TO_TICKS(5));

    // check if all tasks received the message
    if (received_flags[0] && received_flags[1] && received_flags[2]) {
      printf("All tasks received the message!");
      exit(0);
    } else {
      printf("Not all tasks received the message!");
      exit(1);
    }
  }
}
