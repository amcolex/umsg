// Generated with umsg_gen on 2022-09-07
#include <umsg.h>
#include <umsg_sensors.h>

// msg instances
static umsg_msg_metadata_t msg_sensors_imu = {.name = "sensors_imu"};
static umsg_msg_metadata_t msg_sensors_baro = {.name = "sensors_baro"};

// msg api's
// sensors_imu
umsg_queue_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_sensors_imu, prescaler, sizeof(umsg_sensors_imu_t), length);
}
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data)
{
    umsg_publish(&msg_sensors_imu, data);
}
uint8_t umsg_sensors_imu_receive(umsg_queue_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data)
{
    return umsg_peek(&msg_sensors_imu, data, sizeof(umsg_sensors_imu_t));
}

// sensors_baro
umsg_queue_handle_t umsg_sensors_baro_subscribe(uint32_t prescaler, uint8_t length)
{
    return umsg_subscribe(&msg_sensors_baro, prescaler, sizeof(umsg_sensors_baro_t), length);
}
void umsg_sensors_baro_publish(umsg_sensors_baro_t* data)
{
    umsg_publish(&msg_sensors_baro, data);
}
uint8_t umsg_sensors_baro_receive(umsg_queue_handle_t queue, umsg_sensors_baro_t* data, uint32_t timeout)
{
    return umsg_receive(queue, data, timeout);
}
uint8_t umsg_sensors_baro_peek(umsg_sensors_baro_t* data)
{
    return umsg_peek(&msg_sensors_baro, data, sizeof(umsg_sensors_baro_t));
}

