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
  umsg_sub_handle_t sub_0 = umsg_test_uints_subscribe_ch(1, 1, 0);  // subscribe ch 0
  umsg_sub_handle_t sub_1 = umsg_test_uints_subscribe_ch(1, 1, 1);  // subscribe ch 1
  umsg_sub_handle_t sub_2 = umsg_test_uints_subscribe_ch(1, 1, 2);  // subscribe ch 2
  umsg_test_uints_t msg_tx;
  umsg_test_uints_t msg_rx;
  while (1) {

    // send a message to each channel
    msg_tx.u8 = 0x10;
    umsg_test_uints_publish_ch(&msg_tx, 0);
    msg_tx.u8 = 0x20;
    umsg_test_uints_publish_ch(&msg_tx, 1);
    msg_tx.u8 = 0x30;
    umsg_test_uints_publish_ch(&msg_tx, 2);

    // reach each channel and check if value matches
    umsg_test_uints_receive(sub_0, &msg_rx, portMAX_DELAY);
    if (msg_rx.u8 != 0x10) {
      printf("Received message does not match expected value!\n");
      exit(1);
    }

    umsg_test_uints_receive(sub_1, &msg_rx, portMAX_DELAY);
    if (msg_rx.u8 != 0x20) {
      printf("Received message does not match expected value!\n");
      exit(1);
    }

    umsg_test_uints_receive(sub_2, &msg_rx, portMAX_DELAY);
    if (msg_rx.u8 != 0x30) {
      printf("Received message does not match expected value!\n");
      exit(1);
    }

    printf("All tasks received the message!\n");
    exit(0);
  }
}
