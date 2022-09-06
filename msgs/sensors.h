//
// Created by A.Pabouctsidis on 9/6/2022.
//

#ifndef UMSG_SENSORS_H
#define UMSG_SENSORS_H

typedef struct
{
    float gyro[3];
    float accel[3];
    float temp;
} msg_sensors_imu_t;

inline void* umsg_sensor_imu_subscribe(uint32_t prescaler)
{
    return subscribe(&umsg_msg_instance.sensor_imu, prescaler);
}

inline void umsg_sensor_imu_publish(msg_sensors_imu_t* data)
{
    publish(&umsg_msg_instance.sensor_imu, data);
}
#endif //UMSG_SENSORS_H
