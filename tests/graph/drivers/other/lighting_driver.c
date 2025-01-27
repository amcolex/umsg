// Pseudo code which contains uMsg api function calls to test graph generation

int main(void) {
  // single task which will publish messages and then read them back
  xTaskCreate(main_task, "main_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void main_task(void* params) {
  umsg_lighting_cmd_t msg;
  // subscribe to speed setpoint message
  umsg_sub_handle_t sub = umsg_lighting_cmd_subscribe(1, 1);

  while (1) {
    //  get latest lighting commands
    umsg_lighting_cmd_receive(sub, &msg, 0);

    // get lighting temperature

    // control loop to make sure led's dont over heat

    // set timer PWM
    timer_set_duty(led_power);

    vTaskDelay(100)
  }
}