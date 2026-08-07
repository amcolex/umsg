#include "FreeRTOS.h"
#include "task.h"
#include "umsg.h"
#include "umsg_battery.h"

static void battery_tx_task(void *pvParameters);
static void battery_rx_task(void *pvParameters);

int main(void)
{
    /* Start FreeRTOS tasks */
    xTaskCreate(battery_tx_task, "BatteryTX", 256, NULL, 2, NULL);
    xTaskCreate(battery_rx_task, "BatteryRX", 256, NULL, 1, NULL);

    /* Start the scheduler */
    vTaskStartScheduler();

    /* Should never reach here */
    while (1) {
        // NOP
    }
}

static void battery_tx_task(void *pvParameters)
{
    umsg_battery_state_t battery_msg;

    while (1) {
        battery_msg.state = BATTERY_OK;
        battery_msg.low_battery = 0;
        battery_msg.critical_battery = 0;
        battery_msg.charging = 1;
        battery_msg.full = 0;
        battery_msg.not_present = 0;

        umsg_battery_state_publish(&battery_msg);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void battery_rx_task(void *pvParameters)
{
    umsg_sub_handle_t subscription;
    umsg_battery_state_t battery_msg;

    /* Subscribe to battery state updates */
    subscription = umsg_battery_state_subscribe(1, 1);

    while (1) {
        /* Wait for a message */
        if (umsg_battery_state_receive(subscription, &battery_msg, pdMS_TO_TICKS(100)) == pdTRUE) {
            /* Process battery state update */
        }
    }
}
