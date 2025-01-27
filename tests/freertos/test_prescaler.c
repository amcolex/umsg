#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <umsg_test.h>
#include <stdlib.h>

static void pub_task(void* params);
static void sub_task(void* params);

const uint8_t PRESCALERS[] = {1, 5, 10};
uint8_t       received_msgs;
int           main(void) {
  // publisher task lower priority than subscriber task to make they receive the first message
  xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
  xTaskCreate(sub_task, "sub_task_prescaler_1", 1000, (void*)&PRESCALERS[0], 2, NULL);
  xTaskCreate(sub_task, "sub_task_prescaler_2", 1000, (void*)&PRESCALERS[1], 2, NULL);
  xTaskCreate(sub_task, "sub_task_prescaler_5", 1000, (void*)&PRESCALERS[2], 2, NULL);
  vTaskStartScheduler();

  return 0;
}

static void sub_task(void* params) {
  uint8_t           prescaler = *(uint8_t*)params;
  umsg_sub_handle_t sub       = umsg_test_uints_subscribe(prescaler, 1);
  umsg_test_uints_t msg;
  while (1) {
    // receive first msg
    umsg_test_uints_receive(sub, &msg, portMAX_DELAY);

    // check u8 value matches prescaler
    if (msg.u8 != prescaler) {
      printf("Received message does not match prescaler!\n");
      exit(1);
    }
    printf("Received message matches prescaler! Prescaler: %d\n", prescaler);
    received_msgs++;
    vTaskSuspend(NULL);
  }
}

static void pub_task(void* params) {
  umsg_test_uints_t msg     = {0};
  uint8_t           counter = 0;
  while (1) {
    counter++;
    // store message counter in u8 field
    msg.u8 = counter;
    umsg_test_uints_publish(&msg);
    vTaskDelay(pdMS_TO_TICKS(10));

    if (received_msgs == 3) {
      printf("All tasks received the message!\n");
      exit(0);
    }
  }
}
