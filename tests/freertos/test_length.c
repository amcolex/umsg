#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <umsg_test.h>
#include <stdlib.h>

#define QUEUE_LENGTH 5

static void main_task(void* params);

int main(void) {
  // single task which will publish messages and then read them back
  xTaskCreate(main_task, "main_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void main_task(void* params) {
  umsg_sub_handle_t sub_1 = umsg_test_uints_subscribe(1, 1);             // queue size of 1 (always latest message)
  umsg_sub_handle_t sub_5 = umsg_test_uints_subscribe(1, QUEUE_LENGTH);  // queue size of 5 (keeps 5 earliest messages)
  umsg_test_uints_t msg_tx;
  umsg_test_uints_t msg_rx;
  while (1) {
    // publish message 10 times
    for (uint8_t counter = 1; counter <= 10; counter++) {
      msg_tx.u8 = counter;
      umsg_test_uints_publish(&msg_tx);
      vTaskDelay(pdMS_TO_TICKS(10));
    }

    // receive messages of sub1 untill timeout
    while (umsg_test_uints_receive(sub_1, &msg_rx, 0) == pdTRUE) {
      printf("Received message from queue size of 1: %d\n", msg_rx.u8);
    }

    // value should be equal to last sent message
    if (msg_rx.u8 != msg_tx.u8) {
      printf("Received message does not match last sent message!\n");
      exit(1);
    }

    // receive messages of sub 5 untill timeout
    while (umsg_test_uints_receive(sub_5, &msg_rx, pdMS_TO_TICKS(10)) == pdTRUE) {
      printf("Received message from queue size of 5: %d\n", msg_rx.u8);
    }

    // counter should on reach to the size of queue. messages sent after are lost.
    if (msg_rx.u8 != QUEUE_LENGTH) {
      printf("Received message does not match queue length!\n");
      exit(1);
    }

    exit(0);
  }
}
