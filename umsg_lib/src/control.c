// Generated with umsg_gen on 2024-08-07
#include <umsg.h>
#include <umsg_control.h>

// msg instances
static umsg_msg_metadata_t msg_control_setpoints = {.name = "control_setpoints"};

// msg api's
// control_setpoints
umsg_sub_handle_t umsg_control_setpoints_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_control_setpoints, prescaler, sizeof(umsg_control_setpoints_t), length, 0);
}
umsg_sub_handle_t umsg_control_setpoints_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_control_setpoints, prescaler, sizeof(umsg_control_setpoints_t), length, channel);
}
void umsg_control_setpoints_publish(umsg_control_setpoints_t* data) {
  umsg_publish(&msg_control_setpoints, data, 0);
}
void umsg_control_setpoints_publish_ch(umsg_control_setpoints_t* data, uint8_t channel) {
  umsg_publish(&msg_control_setpoints, data, channel);
}
uint8_t umsg_control_setpoints_receive(umsg_sub_handle_t queue, umsg_control_setpoints_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_control_setpoints_peek(umsg_control_setpoints_t* data) {
  return umsg_peek(&msg_control_setpoints, data, sizeof(umsg_control_setpoints_t));
}


uint32_t umsg_control_setpoints_serialize(umsg_control_setpoints_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_CONTROL;
  buffer[1]            = CONTROL_SETPOINTS;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_control_setpoints_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_control_setpoints_deserialize(umsg_control_setpoints_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_CONTROL || buffer[1] != CONTROL_SETPOINTS) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_control_setpoints_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
