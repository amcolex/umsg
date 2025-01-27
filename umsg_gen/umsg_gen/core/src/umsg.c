//
// Created by A.Pabouctsidis on 9/6/2022.
//

#include <umsg.h>
#include <umsg_port.h>
#include <string.h>

static uint8_t CRCresults[256];

const uint8_t  remainder_len = 8;
const uint16_t POLYNOMIAL    = 0x2F;  // this is a CRC8 polynomial

umsg_sub_handle_t umsg_subscribe(umsg_msg_metadata_t* msg, uint16_t prescaler, uint32_t size, uint8_t length, uint8_t ch_id) {
  if (msg->sub_list == NULL) {
    msg->msg_value = umsg_port_malloc(size);

    msg->sub_list             = umsg_port_malloc(sizeof(umsg_sub_t));
    msg->sub_list->sub_handle = umsg_port_create(size, length);
    msg->sub_list->prescaler  = prescaler;
    msg->sub_list->length     = length;
    msg->sub_list->channel    = ch_id;
    msg->sub_list->next_sub   = NULL;
    return msg->sub_list->sub_handle;
  } else {
    umsg_sub_t* sub = msg->sub_list;
    while (sub->next_sub != NULL) {
      sub = sub->next_sub;
    }
    sub->next_sub   = umsg_port_malloc(sizeof(umsg_sub_t));
    sub             = sub->next_sub;
    sub->sub_handle = umsg_port_create(size, length);
    sub->prescaler  = prescaler;
    sub->length     = length;
    sub->channel    = ch_id;
    sub->next_sub   = NULL;
    return sub->sub_handle;
  }
}

void umsg_publish(umsg_msg_metadata_t* msg, void* data, uint8_t ch_id) {
  msg->msg_value = data;
  msg->counter++;
  umsg_sub_t* sub = msg->sub_list;
  while (sub != NULL) {
    if (msg->counter % sub->prescaler == 0 && sub->channel == ch_id) {
      umsg_port_send(sub, data);
    }
    sub = sub->next_sub;
  }
}

uint8_t umsg_receive(umsg_sub_handle_t queue, void* data, uint32_t timeout) {
  return umsg_port_receive(queue, data, timeout);
}

uint8_t umsg_peek(umsg_msg_metadata_t* msg, void* data, uint32_t size) {
  if (msg->counter > 0) {
    memcpy(data, msg->msg_value, size);
    return 1;
  }
  return 0;
}


void umsg_CRCInit() {

  uint8_t top_bit   = (1 << (remainder_len - 1));
  uint8_t remainder = 0;
  for (int i = 0; i < 256; i++) {
    remainder = i;
    for (uint8_t bit = 8; bit > 0; --bit) {
      /*
       * Try to divide the current data bit.
       */
      if (remainder & top_bit) {
        remainder = (remainder << 1) ^ POLYNOMIAL;
      } else {
        remainder = (remainder << 1);
      }
    }
    CRCresults[i] = remainder;
  }
}


uint8_t umsg_checkCRC(uint8_t* buffer, uint32_t len) {
  uint8_t remainder = umsg_calcCRC(buffer, len);
  if (remainder == 0)
    return 0;
  return 1;
}


uint8_t umsg_calcCRC(uint8_t* buffer, uint32_t len) {
  uint8_t data;
  uint8_t remainder = 0;

  /*
   * Divide the message by the polynomial, a byte at a time.
   */
  for (int byte = 0; byte < len; ++byte) {
    data      = buffer[byte] ^ (remainder);
    remainder = CRCresults[data] ^ (remainder << 8);
  }
  return remainder;
}
