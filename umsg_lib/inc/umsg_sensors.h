// Generated with umsg_gen on 2024-08-06
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <umsg_types.h>

// msg structure typedefs

//enumeration of topics
typedef enum
{
    SENSORS_IMU, 
    SENSORS_BARO
} umsg_enum_sensors_t;



typedef struct
{
    float gyro[3];
    float accel[3];
    float temperature;
} umsg_sensors_imu_t;

typedef struct
{
    float pressure;
    float temperature;
} umsg_sensors_baro_t;

// api function headers
umsg_sub_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_sensors_imu_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data);
void umsg_sensors_imu_publish_ch(umsg_sensors_imu_t* data, uint8_t channel);
uint8_t umsg_sensors_imu_receive(umsg_sub_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout);
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data);

umsg_sub_handle_t umsg_sensors_baro_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_sensors_baro_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_sensors_baro_publish(umsg_sensors_baro_t* data);
void umsg_sensors_baro_publish_ch(umsg_sensors_baro_t* data, uint8_t channel);
uint8_t umsg_sensors_baro_receive(umsg_sub_handle_t queue, umsg_sensors_baro_t* data, uint32_t timeout);
uint8_t umsg_sensors_baro_peek(umsg_sensors_baro_t* data);


#ifdef __cplusplus
}
#endif

