// Pseudo code which contains uMsg api function calls to test graph generation

int main(void) {
  // single task which will publish messages and then read them back
  xTaskCreate(dummy_task, "dummy_task", 1000, NULL, 1, NULL);
  vTaskStartScheduler();

  return 0;
}

static void dummy_task(void* params) {
  umsg_sensor_imu_t          imu_msg;
  umsg_estimation_attitude_t att_msg;
  umsg_sub_handle_t          sub = umsg_sensor_imu_subscribe(1, 1);
  while (1) {
    // wait for imu data
    umsg_sensor_imu_receive(sub, &msg, portMAX_DELAY);

    // filter imu data

    // run kalman filter

    // publish attitude
    umsg_estimation_attitude_publish(&att_msg);
  }
}
