// Pseudo code which contains uMsg api function calls to test graph generation

int main(void) {
  // single task which will publish messages and then read them back
  xTaskCreate(control_task, "control_task", 1000, NULL, 1, NULL);
  xTaskCreate(telemetry_task, "control_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void control_task(void* params) {
  umsg_motors_speedsetpoint_t msg;
  // subscribe to speed setpoint message
  umsg_sub_handle_t sub = umsg_motors_speedsetpoint_subscribe(1, 1);

  while (1) {
    //  wait for setpoints
    umsg_motors_speedsetpoint_receive(sub, &msg, portMAX_DELAY);

    // set timer PWM
    timer_set_duty(msg);
  }
}

static void telemetry_task(void* params) {
  umsg_motors_telemtry_t telem_msg;
  while (1) {
    // get motor telemetry via usart (RPM, current, temperature
    usart_get_telem(&telem_msg)
        // publish umsg
        umsg_motors_telemtry_publish(&telem_msg);
  }
}
