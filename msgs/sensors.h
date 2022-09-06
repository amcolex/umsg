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
} umsg_sensors_imu_t;

typedef struct
{
    float mag[3];
    float temp;
} umsg_sensors_mag_t;

typedef struct
{
    float pressure;
    float temp;
} umsg_sensors_baro_t;

void * umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length);
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data);
uint8_t umsg_sensors_imu_receive(umsg_queue_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout);
void * umsg_sensors_baro_subscribe(uint32_t prescaler, uint8_t length);
void umsg_sensors_baro_publish(umsg_sensors_baro_t* data);
uint8_t umsg_sensors_baro_receive(umsg_queue_handle_t queue, umsg_sensors_baro_t* data, uint32_t timeout);
void * umsg_sensors_mag_subscribe(uint32_t prescaler, uint8_t length);
void umsg_sensors_mag_publish(umsg_sensors_mag_t* data);
uint8_t umsg_sensors_mag_receive(umsg_queue_handle_t queue, umsg_sensors_mag_t* data, uint32_t timeout);


#endif //UMSG_SENSORS_H
