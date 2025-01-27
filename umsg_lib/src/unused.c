// Generated with umsg_gen on 2024-08-07
#include <umsg.h>
#include <umsg_unused.h>

// msg instances
static umsg_msg_metadata_t msg_unused_used_var   = {.name = "unused_used_var"};
static umsg_msg_metadata_t msg_unused_unused_var = {.name = "unused_unused_var"};

// msg api's
// unused_used_var
umsg_sub_handle_t umsg_unused_used_var_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_unused_used_var, prescaler, sizeof(umsg_unused_used_var_t), length, 0);
}
umsg_sub_handle_t umsg_unused_used_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_unused_used_var, prescaler, sizeof(umsg_unused_used_var_t), length, channel);
}
void umsg_unused_used_var_publish(umsg_unused_used_var_t* data) {
  umsg_publish(&msg_unused_used_var, data, 0);
}
void umsg_unused_used_var_publish_ch(umsg_unused_used_var_t* data, uint8_t channel) {
  umsg_publish(&msg_unused_used_var, data, channel);
}
uint8_t umsg_unused_used_var_receive(umsg_sub_handle_t queue, umsg_unused_used_var_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_unused_used_var_peek(umsg_unused_used_var_t* data) {
  return umsg_peek(&msg_unused_used_var, data, sizeof(umsg_unused_used_var_t));
}


uint32_t umsg_unused_used_var_serialize(umsg_unused_used_var_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_UNUSED;
  buffer[1]            = UNUSED_USED_VAR;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_unused_used_var_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_unused_used_var_deserialize(umsg_unused_used_var_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_UNUSED || buffer[1] != UNUSED_USED_VAR) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_unused_used_var_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
// unused_unused_var
umsg_sub_handle_t umsg_unused_unused_var_subscribe(uint32_t prescaler, uint8_t length) {
  return umsg_subscribe(&msg_unused_unused_var, prescaler, sizeof(umsg_unused_unused_var_t), length, 0);
}
umsg_sub_handle_t umsg_unused_unused_var_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel) {
  return umsg_subscribe(&msg_unused_unused_var, prescaler, sizeof(umsg_unused_unused_var_t), length, channel);
}
void umsg_unused_unused_var_publish(umsg_unused_unused_var_t* data) {
  umsg_publish(&msg_unused_unused_var, data, 0);
}
void umsg_unused_unused_var_publish_ch(umsg_unused_unused_var_t* data, uint8_t channel) {
  umsg_publish(&msg_unused_unused_var, data, channel);
}
uint8_t umsg_unused_unused_var_receive(umsg_sub_handle_t queue, umsg_unused_unused_var_t* data, uint32_t timeout) {
  return umsg_receive(queue, data, timeout);
}
uint8_t umsg_unused_unused_var_peek(umsg_unused_unused_var_t* data) {
  return umsg_peek(&msg_unused_unused_var, data, sizeof(umsg_unused_unused_var_t));
}


uint32_t umsg_unused_unused_var_serialize(umsg_unused_unused_var_t* data, uint8_t* buffer) {
  uint32_t len         = 2;
  buffer[0]            = UMSG_UNUSED;
  buffer[1]            = UNUSED_UNUSED_VAR;
  char* flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_unused_unused_var_t); i++) {
    buffer[len] = flattened_data[i];
    len++;
  }
  return len;
}


// for now lets assume that there are less than 255 message classes and 255 message types per class, this has to be fixed in the future
uint8_t umsg_unused_unused_var_deserialize(umsg_unused_unused_var_t* data, uint8_t* buffer) {
  if (buffer[0] != UMSG_UNUSED || buffer[1] != UNUSED_UNUSED_VAR) {
    return 0;
  }

  uint32_t offset         = 2;
  char*    flattened_data = (char*)data;
  for (uint32_t i = 0; i < sizeof(umsg_unused_unused_var_t); i++) {
    flattened_data[i] = buffer[offset];
    offset++;
  }

  return 1;
}
