//
// Created by alexp on 9/6/2022.
//
#include <umsg.h>
#include <sensors.h>

static umsg_msg_metadata_t msg_sensor_imu = {.name = "sensor_imu"};
static umsg_msg_metadata_t msg_sensor_baro = {.name = "sensor_baro"};
static umsg_msg_metadata_t msg_sensor_mag = {.name = "sensor_mag"};

void * umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_sensor_imu, prescaler, sizeof(umsg_sensors_imu_t), length);
}

void umsg_sensors_imu_publish(umsg_sensors_imu_t* data)
{
    umsg_publish(&msg_sensor_imu, data);
}

uint8_t umsg_sensors_imu_receive(umsg_queue_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}

void umsg_sensors_imu_peek(umsg_sensors_imu_t* data)
{
    umsg_peek(&msg_sensor_imu, data, sizeof(umsg_sensors_imu_t));
}

void * umsg_sensors_baro_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_sensor_baro, prescaler, sizeof(umsg_sensors_baro_t), length);
}

void umsg_sensors_baro_publish(umsg_sensors_baro_t* data)
{
    umsg_publish(&msg_sensor_baro, data);
}

uint8_t umsg_sensors_baro_receive(umsg_queue_handle_t queue, umsg_sensors_baro_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}

void umsg_sensors_baro_peek(umsg_sensors_baro_t* data)
{
    umsg_peek(&msg_sensor_baro, data, sizeof(umsg_sensors_baro_t));
}

void * umsg_sensors_mag_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_sensor_mag, prescaler, sizeof(umsg_sensors_mag_t), length);
}

void umsg_sensors_mag_publish(umsg_sensors_mag_t* data)
{
    umsg_publish(&msg_sensor_mag, data);
}

uint8_t umsg_sensors_mag_receive(umsg_queue_handle_t queue, umsg_sensors_mag_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}

void umsg_sensors_mag_peek(umsg_sensors_mag_t* data)
{
    umsg_peek(&msg_sensor_mag, data, sizeof(umsg_sensors_mag_t));
}
