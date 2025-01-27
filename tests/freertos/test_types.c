#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <umsg_test.h>
#include <stdlib.h>
#include <string.h>

static umsg_test_ints_t msg_ints_ref = {
    .i8 = -1, .i16 = -2, .i32 = -3, .i64 = -4, .i8array = {-5, -6, -7}, .i16array = {-8, -9, -10}, .i32array = {-11, -12, -13}, .i64array = {-14, -15, -16}};
static umsg_test_uints_t msg_uints_ref = {
    .u8 = 1, .u16 = 2, .u32 = 3, .u64 = 4, .u8array = {5, 6, 7}, .u16array = {8, 9, 10}, .u32array = {11, 12, 13}, .u64array = {14, 15, 16}};
static umsg_test_floats_t  msg_floats_ref  = {.single = 1.1f, .double_var = 2.2, .single_array = {3.3f, 4.4f, 5.5f}, .double_array = {6.6, 7.7, 8.8}

};
static umsg_test_strings_t msg_strings_ref = {.single = 'a', .array = "Hello World!"};
static umsg_test_bools_t   msg_bools_ref   = {.a = true, .b = {false, true, false}};

static umsg_test_enums_t msg_enums_ref = {.single_enum = ENUM_A, .enum_array = {ENUM_A, ENUM_B, ENUM_C}};

static umsg_test_bitfield_t msg_bitfield_ref = {
    .a = 1,
    .b = 2,
    .c = 3,
};

static void pub_task(void* params);
static void sub_task(void* params);

int main(void) {

  xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
  xTaskCreate(sub_task, "sub_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void sub_task(void* params) {
  umsg_sub_handle_t sub_uints   = umsg_test_uints_subscribe(1, 1);
  umsg_sub_handle_t sub_ints    = umsg_test_ints_subscribe(1, 1);
  umsg_sub_handle_t sub_floats  = umsg_test_floats_subscribe(1, 1);
  umsg_sub_handle_t sub_strings = umsg_test_strings_subscribe(1, 1);
  umsg_sub_handle_t sub_bools   = umsg_test_bools_subscribe(1, 1);
  umsg_sub_handle_t sub_enums   = umsg_test_enums_subscribe(1, 1);


  umsg_test_uints_t   msg_uints;
  umsg_test_ints_t    msg_ints;
  umsg_test_floats_t  msg_floats;
  umsg_test_strings_t msg_strings;
  umsg_test_bools_t   msg_bools;
  umsg_test_enums_t   msg_enums;

  while (1) {
    uint8_t flag = 0;
    flag |= umsg_test_uints_receive(sub_uints, &msg_uints, pdMS_TO_TICKS(100));
    flag |= umsg_test_ints_receive(sub_ints, &msg_ints, pdMS_TO_TICKS(100));
    flag |= umsg_test_floats_receive(sub_floats, &msg_floats, pdMS_TO_TICKS(100));
    flag |= umsg_test_strings_receive(sub_strings, &msg_strings, pdMS_TO_TICKS(100));
    flag |= umsg_test_bools_receive(sub_bools, &msg_bools, pdMS_TO_TICKS(100));
    flag |= umsg_test_enums_receive(sub_enums, &msg_enums, portMAX_DELAY);

    if (flag == 1) {
      printf("Received all messages!\n");
    } else {
      printf("failed to receive all messages\n");
      exit(1);
    }

    // check messages match reference
    if (msg_uints.u8 != msg_uints_ref.u8) {
      printf("u8 mismatch!\n");
      exit(1);
    }
    if (msg_uints.u16 != msg_uints_ref.u16) {
      printf("u16 mismatch!\n");
      exit(1);
    }
    if (msg_uints.u32 != msg_uints_ref.u32) {
      printf("u32 mismatch!\n");
      exit(1);
    }
    if (msg_uints.u64 != msg_uints_ref.u64) {
      printf("u64 mismatch!\n");
      exit(1);
    }
    for (int i = 0; i < 3; i++) {
      if (msg_uints.u8array[i] != msg_uints_ref.u8array[i]) {
        printf("u8array mismatch!\n");
        exit(1);
      }
      if (msg_uints.u16array[i] != msg_uints_ref.u16array[i]) {
        printf("u16array mismatch!\n");
        exit(1);
      }
      if (msg_uints.u32array[i] != msg_uints_ref.u32array[i]) {
        printf("u32array mismatch!\n");
        exit(1);
      }
      if (msg_uints.u64array[i] != msg_uints_ref.u64array[i]) {
        printf("u64array mismatch!\n");
        exit(1);
      }
    }

    if (msg_ints.i8 != msg_ints_ref.i8) {
      printf("i8 mismatch!\n");
      exit(1);
    }
    if (msg_ints.i16 != msg_ints_ref.i16) {
      printf("i16 mismatch!\n");
      exit(1);
    }
    if (msg_ints.i32 != msg_ints_ref.i32) {
      printf("i32 mismatch!\n");
      exit(1);
    }
    if (msg_ints.i64 != msg_ints_ref.i64) {
      printf("i64 mismatch!\n");
      exit(1);
    }
    for (int i = 0; i < 3; i++) {
      if (msg_ints.i8array[i] != msg_ints_ref.i8array[i]) {
        printf("i8array mismatch!\n");
        exit(1);
      }
      if (msg_ints.i16array[i] != msg_ints_ref.i16array[i]) {
        printf("i16array mismatch!\n");
        exit(1);
      }
      if (msg_ints.i32array[i] != msg_ints_ref.i32array[i]) {
        printf("i32array mismatch!\n");
        exit(1);
      }
      if (msg_ints.i64array[i] != msg_ints_ref.i64array[i]) {
        printf("i64array mismatch!\n");
        exit(1);
      }
    }

    if (msg_floats.single != msg_floats_ref.single) {
      printf("single mismatch!\n");
      exit(1);
    }
    if (msg_floats.double_var != msg_floats_ref.double_var) {
      printf("double mismatch!\n");
      exit(1);
    }
    for (int i = 0; i < 3; i++) {
      if (msg_floats.single_array[i] != msg_floats_ref.single_array[i]) {
        printf("single_array mismatch!\n");
        exit(1);
      }
      if (msg_floats.double_array[i] != msg_floats_ref.double_array[i]) {
        printf("double_array mismatch!\n");
        exit(1);
      }
    }

    if (msg_strings.single != msg_strings_ref.single) {
      printf("single mismatch!\n");
      exit(1);
    }
    if (strcmp(msg_strings.array, msg_strings_ref.array) != 0) {
      printf("array mismatch!\n");
      exit(1);
    }

    if (msg_bools.a != msg_bools_ref.a) {
      printf("a mismatch!\n");
      exit(1);
    }
    for (int i = 0; i < 3; i++) {
      if (msg_bools.b[i] != msg_bools_ref.b[i]) {
        printf("b mismatch!\n");
        exit(1);
      }
    }

    if (msg_enums.single_enum != msg_enums_ref.single_enum) {
      printf("single_enum mismatch!\n");
      exit(1);
    }
    for (int i = 0; i < 3; i++) {
      if (msg_enums.enum_array[i] != msg_enums_ref.enum_array[i]) {
        printf("enum_array mismatch!\n");
        exit(1);
      }
    }

    printf("All messages match reference!\n");
    exit(0);
  }
}

static void pub_task(void* params) {
  while (1) {
    umsg_test_uints_publish(&msg_uints_ref);
    umsg_test_ints_publish(&msg_ints_ref);
    umsg_test_floats_publish(&msg_floats_ref);
    umsg_test_strings_publish(&msg_strings_ref);
    umsg_test_bools_publish(&msg_bools_ref);
    umsg_test_enums_publish(&msg_enums_ref);

    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
