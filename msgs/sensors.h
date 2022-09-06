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
#endif //UMSG_SENSORS_H
