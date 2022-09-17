// Pseudo code which contains uMsg api function calls to test graph generation

int main( void )
{
    // single task which will publish messages and then read them back
    xTaskCreate(control_task, "control_task", 1000, NULL, 1, NULL);
    vTaskStartScheduler();

    return 0;
}

static void control_task(void* params)
{
    umsg_usercmd_setpoints_t msg_usercmd_setpoints;
    umsg_system_state_t msg_system_state;
    umsg_estimation_attitude_t msg_att;
    umsg_motors_speedsetpoint_t msg_sp;

    // subscribe state estimate and sonar messages
    umsg_sub_handle_t sub_att =  umsg_estimation_attitude_subscribe(1,1);
    umsg_sub_handle_t sub_sonar =  umsg_sensors_sonar_subscribe(1,1);


    while(1) 
    {
        //  synchronize on state estimate and sonar messages
        umsg_estimation_attitude_receive(sub_att, &msg_att, portMAX_DELAY);

        // peek at sonar message (async)
        umsg_sensors_sonar_peek(&msg_sonar);

        // peek at system state message (async)
        umsg_system_state_peek(&msg_system_state);

        // peek at user setpoints message (async)
        umsg_usercmd_setpoints_peek(&msg_usercmd_setpoints);

        if(msg_system_state == ACTIVE)
        {
            // do control loop math
        }
        else
        {
            // set motor speed setpoints to 0

        }

        // publish motor speed setpoints
        umsg_motors_speedsetpoint_publish(&msg_sp);
      
    }
}

static void telemetry_task(void* params)
{
    umsg_motors_telemtry_t telem_msg;
    while(1) 
    {
        // get motor telemetry via usart (RPM, current, temperature
        usart_get_telem(&telem_msg)
        // publish umsg
        umsg_motors_telemtry_publish(&telem_msg);
      
    }
}

