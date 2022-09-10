#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <umsg_test.h>

static umsg_test_uints_t msg_uints_ref = {
    .u8 = 1,
    .u16 = 2,
    .u32 = 3,
    .u64 = 4,
    .u8array = {5,6,7},
    .u16array = {8,9,10},
    .u32array = {11,12,13},
    .u64array = {14,15,16}
};
static umsg_test_floats_t msg_floats_ref = {
    .single = 1.1f,
    .double_var = 2.2,
    .single_array = {3.3f,4.4f,5.5f},
    .double_array = {6.6,7.7,8.8}
};
static umsg_test_strings_t msg_strings_ref = {
    .single = 'a',
    .array = "Hello World!"
};
static umsg_test_bools_t msg_bools_ref = {
    .a = true,
    .b = {false, true, false}
};


static void pub_task(void* params);
static void sub_task(void* params);

int main( void )
{

    xTaskCreate(pub_task, "pub_task", 1000, NULL, 1, NULL);
    xTaskCreate(sub_task, "sub_task", 1000, NULL, 1, NULL);
    vTaskStartScheduler();

    return 0;
}

static void sub_task(void* params)
{
    umsg_sub_handle_t sub_ints = umsg_test_uints_subscribe(1,1);
    umsg_sub_handle_t sub_floats = umsg_test_floats_subscribe(1,1);
    umsg_sub_handle_t sub_strings = umsg_test_strings_subscribe(1,1);
    umsg_sub_handle_t sub_bools = umsg_test_bools_subscribe(1,1);

    umsg_test_uints_t msg_ints;
    umsg_test_floats_t msg_floats;
    umsg_test_strings_t msg_strings;
    umsg_test_bools_t msg_bools;

    while(1) {
        umsg_test_uints_receive(sub_ints,&msg_ints,portMAX_DELAY);
        umsg_test_floats_receive(sub_floats,&msg_floats,portMAX_DELAY);
        umsg_test_strings_receive(sub_strings,&msg_strings,portMAX_DELAY);
        umsg_test_bools_receive(sub_bools,&msg_bools,portMAX_DELAY);
        printf("Received all messages!\n");

        // check messages match reference
        if (msg_ints.u8 != msg_uints_ref.u8) {
            printf("u8 mismatch!");
            exit(1);
        }
        if (msg_ints.u16 != msg_uints_ref.u16) {
            printf("u16 mismatch!");
            exit(1);
        }
        if (msg_ints.u32 != msg_uints_ref.u32) {
            printf("u32 mismatch!");
            exit(1);
        }
        if (msg_ints.u64 != msg_uints_ref.u64) {
            printf("u64 mismatch!");
            exit(1);
        }
        for (int i = 0; i < 3; i++) {
            if (msg_ints.u8array[i] != msg_uints_ref.u8array[i]) {
                printf("u8array mismatch!");
                exit(1);
            }
            if (msg_ints.u16array[i] != msg_uints_ref.u16array[i]) {
                printf("u16array mismatch!");
                exit(1);
            }
            if (msg_ints.u32array[i] != msg_uints_ref.u32array[i]) {
                printf("u32array mismatch!");
                exit(1);
            }
            if (msg_ints.u64array[i] != msg_uints_ref.u64array[i]) {
                printf("u64array mismatch!");
                exit(1);
            }
        }

        if (msg_floats.single != msg_floats_ref.single) {
            printf("single mismatch!");
            exit(1);
        }
        if (msg_floats.double_var != msg_floats_ref.double_var) {
            printf("double mismatch!");
            exit(1);
        }
        for (int i = 0; i < 3; i++) {
            if (msg_floats.single_array[i] != msg_floats_ref.single_array[i]) {
                printf("single_array mismatch!");
                exit(1);
            }
            if (msg_floats.double_array[i] != msg_floats_ref.double_array[i]) {
                printf("double_array mismatch!");
                exit(1);
            }
        }

        if (msg_strings.single != msg_strings_ref.single) {
            printf("single mismatch!");
            exit(1);
        }
        if (strcmp(msg_strings.array,msg_strings_ref.array) != 0) {
            printf("array mismatch!");
            exit(1);
        }

        if (msg_bools.a != msg_bools_ref.a) {
            printf("a mismatch!");
            exit(1);
        }
        for (int i = 0; i < 3; i++) {
            if (msg_bools.b[i] != msg_bools_ref.b[i]) {
                printf("b mismatch!");
                exit(1);
            }
        }

        printf("All messages match reference!\n");
        exit(0);
    }
}

static void pub_task(void* params)
{
    while(1)
    {
        umsg_test_uints_publish(&msg_uints_ref);
        umsg_test_floats_publish(&msg_floats_ref);
        umsg_test_strings_publish(&msg_strings_ref);
        umsg_test_bools_publish(&msg_bools_ref);

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
    while(1);
}

