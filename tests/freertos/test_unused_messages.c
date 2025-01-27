#include "FreeRTOS.h"
#include "task.h"
#include <umsg_unused.h>
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
  umsg_sub_handle_t      sub = umsg_unused_used_var_subscribe(1, 1);
  umsg_unused_used_var_t msg;
  while (1) {
    umsg_unused_used_var_receive(sub, &msg, portMAX_DELAY);
    printf("Received msg!");
    exit(0);
  }
}

static void pub_task(void* params) {
  umsg_unused_used_var_t msg = {.a = 0x66, .b = 0x77, .c = 0x88};
  while (1) {
    umsg_unused_used_var_publish(&msg);
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
