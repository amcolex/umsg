#include "FreeRTOS.h"
#include "task.h"
#include <umsg_sensors.h>
#include <umsg_test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void pub_task(void* params);
static void sub_task(void* params);

int main(void) {
  xTaskCreate(pub_task, "pub_task", 1000, NULL, 2, NULL);
  xTaskCreate(sub_task, "sub_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void sub_task(void* params) {
  umsg_sub_handle_t  sub = umsg_sensors_imu_subscribe(1, 1);
  umsg_sensors_imu_t msg;
  umsg_test_bools_t  msg_bools;
  while (1) {
    umsg_sensors_imu_receive(sub, &msg, portMAX_DELAY);

    // peek imu data and check it matches
    umsg_sensors_imu_t peek_msg;
    umsg_sensors_imu_peek(&peek_msg);

    // empty peek
    umsg_test_bools_peek(&msg_bools);

    if (memcmp(&msg, &peek_msg, sizeof(umsg_sensors_imu_t)) != 0) {
      printf("Peeked message does not match received message!");
      exit(1);
    }

    exit(0);
  }
}

static void pub_task(void* params) {
  umsg_sensors_imu_t imu_data = {.accel = {1, 2, 3}, .gyro = {4, 5, 6}, .temperature = 66};
  while (1) {
    umsg_sensors_imu_publish(&imu_data);

    // peek from subscriber and check it matches
    umsg_sensors_imu_t peeked_msg;
    umsg_sensors_imu_peek(&peeked_msg);
    if (memcmp(&imu_data, &peeked_msg, sizeof(umsg_sensors_imu_t)) != 0) {
      printf("Peeked message does not match published message!");
      exit(1);
    }

    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
