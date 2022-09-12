
# μMsg
[![Licence](https://img.shields.io/github/license/amcolex/umsg)](https://github.com/amcolex/umsg/blob/master/LICENSE)
[![Actions Status](https://github.com/amcolex/umsg/workflows/CMake/badge.svg?branch=master)](https://github.com/amcolex/umsg/actions)

A Lightweight pub-sub library written in C for embedded systems. 

- Generated library from json definitions
- Statically typed -> Compile time checking
- Multi-publisher with seperate channels
- Uses the RTOS queue API for performance
- Dead simple and efficient. (Core code less than 150 LoC!)
- Scalable. Builds a linked-list for infinite number of publisher and subscribers.
- Easily ported to other RTOS/OS (only needs to change core file)

# Quickstart

## Generate Library
The easiest is to install umsg generator python library with: 

```
pip install umsg-gen
```

Prepare your topic .json file (see [topic definition]#How-to-define-a-topic) with your messages. And save them in a seperate directory such as '\messages' 

Run:

```
umsg-gen -d '\messages' - o '\umsg_lib'
```

## Add to CMake Project

The generated libray contains a CMakeLists.txt. Select the port and add the library to your CMake project with:

```cmake
set(UMSG_PORT "FREERTOS")
add_subdirectory(umsg_lib)
```

A CMake uMsgLib shared library is created. Link your FreeRTOS library to the uMsgLib library

```cmake
target_link_libraries(uMsgLib freertos_kernel)
```

Finally, link uMsgLib to your main project target

```cmake
target_link_libraries(your_project uMsgLib)
```

## Add to IDE Project (Eclipse, STM32CubeIDE, etc)

In project settings:
- Add 'umsg_lib/src' and 'umsg_lib/core/src' to source paths.
- Add 'umsg_lib/inc' and 'umsg_lib/core/inc' to include paths.

Keep only one of the port_xxxx.c (i.e. port_freertos.c) in the 'umsg_lib/core/src', by excluding or deleting the others.


# uMsg Publish and Subscribe Overview

## Generated API

uMsg generates a seperated .h and .c file for each topic json file.

For example. given a sensors.json which contains an 'imu' message, the following API functions are generated:

```c
umsg_sub_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length);
```


umsg_sub_handle_t umsg_sensors_imu_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data);
void umsg_sensors_imu_publish_ch(umsg_sensors_imu_t* data, uint8_t channel);
uint8_t umsg_sensors_imu_receive(umsg_sub_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout);
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data);
```

There are two subscribe and publish functions. One is default is used when there is only 1 channel, with a single publisher. The other is used when there are multiple publishers, and each publisher is on a different channel.

Channels are used when there are multiple publisher for the same message type. For example, if there are two IMU sensors, they can publish to different channels.
## Defining messages

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

A field is any of these primitives, which can be defined as a scalar, array, or bitfield.

A message is a group of fields, which is generated as a ```typedef struct```
```c
example.json:

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

Generated output:

```c
typedef enum
{
    GREEN,
    BLUE,
    READ
} umsg_example_colors_t;

typedef struct
{
    umsg_example_colors_t chosen_color;
} umsg_example_color_selection_t;

typedef struct
{
    char name[10];
    uint8_t age;
    float height;
    uint8_t married : 1, has_children : 1, has_dog : 1;
} umsg_example_simple_msg_t;

```