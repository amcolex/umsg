
# μMsg
[![Licence](https://img.shields.io/github/license/amcolex/umsg)](https://github.com/amcolex/umsg/blob/master/LICENSE)
[![Actions Status](https://github.com/amcolex/umsg/workflows/CMake/badge.svg?branch=master)](https://github.com/amcolex/umsg/actions)

A Lightweight pub-sub library written in C for embedded systems.

## uMsg Publish and Subscribe Overview

### Generated API

example for sensors.json topic, 'imu' message:

```c
umsg_sub_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length);
umsg_sub_handle_t umsg_sensors_imu_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data);
void umsg_sensors_imu_publish_ch(umsg_sensors_imu_t* data, uint8_t channel);
uint8_t umsg_sensors_imu_receive(umsg_sub_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout);
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data);
```

There are two subscribe and publish functions. One is default is used when there is only 1 channel, with a single publisher. The other is used when there are multiple publishers, and each publisher is on a different channel.

Channels are used when there are multiple publisher for the same message type. For example, if there are two IMU sensors, they can publish to different channels.
### How to define a topic and messages

A topic is a dedicated .json file that contains a list of messages and enums (optional).

list of primitives:
- uint8
- int8
- uint16
- int16
- uint32
- int32
- uint64
- int64
- float
- double
- char
- bool


```c
{
   "enums":[                    // array of enum declarations (optional)
      {
         "name":"colors",       // enum name
         "enumerators":[        // string array of enumerators
            "green",
            "blue",
            "read"
         ]
      }
   ],
   "msgs":[                                 // array of message declarations
      {
         "name":"color_selection",          // message name
         "fields":[                         // array of fields
            {
               "name":"chosen_color",       // field name
               "type":"colors"              // field type (from list of primitives or enum)
            }
         ]
      },
      {
         "name":"simple_msg",               // message name
         "fields":[                         // array of fields
            {
               "name":"name",               // field name
               "type":"char",               // field type
               "length":10                  // field length (array)
            },
            {
               "name":"age",                // field name
               "type":"uint8"               // field type
            },
            {
               "name":"height",             // field name
               "type":"float"               // field type
            },
            {
               "name":"attributes",         // field name
               "type":"uint8",              // field type
               "bitfield":[                 // declare as bitfield
                  {
                     "name":"married",      // bitfield name
                     "bits":1               // bitfield length
                  },
                  {
                     "name":"has_children",
                     "bits":1
                  },
                  {
                     "name":"has_dog",
                     "bits":1
                  }
               ]
            }
         ]
      }
   ]
}
```

## Data types



## How to use

