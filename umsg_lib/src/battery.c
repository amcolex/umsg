// Generated with umsg_gen on 2024-08-07
#include <umsg.h>
#include <umsg_battery.h>

// msg instances
static umsg_msg_metadata_t msg_battery_state = {.name = "battery_state"};

// msg api's
// battery_state
umsg_sub_handle_t umsg_battery_state_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_battery_state, prescaler, sizeof(umsg_battery_state_t), length, 0);
}
umsg_sub_handle_t umsg_battery_state_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_battery_state, prescaler, sizeof(umsg_battery_state_t), length, channel);
}
void umsg_battery_state_publish(umsg_battery_state_t* data) {
  umsg_publish(&msg_battery_state, data, 0);
}
void umsg_battery_state_publish_ch(umsg_battery_state_t* data, uint8_t channel) {
  umsg_publish(&msg_battery_state, data, channel);
}
uint8_t umsg_battery_state_receive(umsg_sub_handle_t queue, umsg_battery_state_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_battery_state_peek(umsg_battery_state_t* data) {
  return umsg_peek(&msg_battery_state, data, sizeof(umsg_battery_state_t));
}


uint32_t umsg_battery_state_serialize(umsg_battery_state_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_BATTERY;
  buffer[1]            = BATTERY_STATE;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_battery_state_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_battery_state_deserialize(umsg_battery_state_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_BATTERY || buffer[1] != BATTERY_STATE) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_battery_state_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
