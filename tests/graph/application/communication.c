// Pseudo code which contains uMsg api function calls to test graph generation

int main(void) {
  // single task which will publish messages and then read them back
  xTaskCreate(user_command_task, "user_command_task", 1000, NULL, 1, NULL);
  xTaskCreate(user_telemtry_task, "user_telemtry_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void user_command_task(void* params) {
  umsg_system_state_t      msg_system_state;
  umsg_usercmd_setpoints_t msg_usercmd_setpoints;
  umsg_servo_setpoint_t    msg_servo_setpoint;
  umsg_lighting_cmd_t      msg_lighting_cmd;
  while (1) {
    //  receive usart commands and parse them
    usart_parse_command();

    // send system state (ACTIVE/IDLE)
    umsg_system_state_publish(&msg_system_state);

    // send user setpoints
    umsg_usercmd_setpoints_publish(&msg_usercmd_setpoints);

    // send servo setpoints
    umsg_servo_setpoint_publish(&msg_servo_setpoint);

    // send lighting commands
    umsg_lighting_cmd_publish(&msg_lighting_cmd);
  }
}

static void telemetry_task(void* params) {
  umsg_motors_telemtry_t telem_msg;
  // subscrive to motor telemetry with a prescaler of 10
  umsg_sub_handle_t sub = umsg_motors_telemtry_subscribe(10, 1);
  while (1) {
    // wait for motor telemetry
    umsg_motors_telemtry_receive(sub, &telem_msg, 0);

    // send telemetry to user via usart communication

    vTaskDelay(100)
  }
}