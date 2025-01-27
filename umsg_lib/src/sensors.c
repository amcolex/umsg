// Generated with umsg_gen on 2024-08-07
#include <umsg.h>

#include <umsg_sensors.h>

// msg instances
static umsg_msg_metadata_t msg_sensors_imu  = {.name = "sensors_imu"};
static umsg_msg_metadata_t msg_sensors_baro = {.name = "sensors_baro"};

// msg api's
// sensors_imu
umsg_sub_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_sensors_imu, prescaler, sizeof(umsg_sensors_imu_t), length, 0);
}
umsg_sub_handle_t umsg_sensors_imu_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_sensors_imu, prescaler, sizeof(umsg_sensors_imu_t), length, channel);
}
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data) {
  umsg_publish(&msg_sensors_imu, data, 0);
}
void umsg_sensors_imu_publish_ch(umsg_sensors_imu_t* data, uint8_t channel) {
  umsg_publish(&msg_sensors_imu, data, channel);
}
uint8_t umsg_sensors_imu_receive(umsg_sub_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data) {
  return umsg_peek(&msg_sensors_imu, data, sizeof(umsg_sensors_imu_t));
}


uint32_t umsg_sensors_imu_serialize(umsg_sensors_imu_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_SENSORS;
  buffer[1]            = SENSORS_IMU;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_sensors_imu_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_sensors_imu_deserialize(umsg_sensors_imu_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_SENSORS || buffer[1] != SENSORS_IMU) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_sensors_imu_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
// sensors_baro
umsg_sub_handle_t umsg_sensors_baro_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_sensors_baro, prescaler, sizeof(umsg_sensors_baro_t), length, 0);
}
umsg_sub_handle_t umsg_sensors_baro_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_sensors_baro, prescaler, sizeof(umsg_sensors_baro_t), length, channel);
}
void umsg_sensors_baro_publish(umsg_sensors_baro_t* data) {
  umsg_publish(&msg_sensors_baro, data, 0);
}
void umsg_sensors_baro_publish_ch(umsg_sensors_baro_t* data, uint8_t channel) {
  umsg_publish(&msg_sensors_baro, data, channel);
}
uint8_t umsg_sensors_baro_receive(umsg_sub_handle_t queue, umsg_sensors_baro_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_sensors_baro_peek(umsg_sensors_baro_t* data) {
  return umsg_peek(&msg_sensors_baro, data, sizeof(umsg_sensors_baro_t));
}


uint32_t umsg_sensors_baro_serialize(umsg_sensors_baro_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_SENSORS;
  buffer[1]            = SENSORS_BARO;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_sensors_baro_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_sensors_baro_deserialize(umsg_sensors_baro_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_SENSORS || buffer[1] != SENSORS_BARO) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_sensors_baro_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
