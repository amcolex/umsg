
# μMsg
[![Licence](https://img.shields.io/github/license/amcolex/umsg)](https://github.com/amcolex/umsg/blob/master/LICENSE)
[![Actions Status](https://github.com/amcolex/umsg/workflows/CMake/badge.svg?branch=master)](https://github.com/amcolex/umsg/actions)

A Lightweight pub-sub library written in C for embedded systems. 

- Generated library from json definitions
- Statically typed -> Compile time checking
- Multi-publisher with separate channels
- Uses the RTOS queue API for performance
- Dead simple and efficient. (Core code less than 150 LoC!)
- Scalable. Builds a linked-list for an infinite number of publishers and subscribers.
- Easily ported to other RTOS/OS (only needs to change one core file)

Analyze your source code with umsg-graph, and generate a communication flow chart, such as:

![image](https://raw.githubusercontent.com/Amcolex/umsg/master/graph/umsg_graph.svg)

# Quickstart

## Generate Library
The easiest is to install umsg generator python library with: 

```
pip install umsg-gen
```

Prepare your topic .json file (see [topic definition]#Defining-messages) with your messages. And save them in a separate directory such as '\messages' 

Run:

```
umsg-gen -d '\messages' -o '\umsg_lib' -l
```

## Add to CMake Project

The generated library contains a CMakeLists.txt. Select the port and add the library to your CMake project with:

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

Keep only **one** of the port_xxxx.c (i.e. port_freertos.c) in the 'umsg_lib/core/src', by excluding or deleting the others.


# uMsg Publish and Subscribe Overview

## Generated API

uMsg generates a seperated .h and .c file for each topic json file.

For example. given a sensors.json which contains an 'imu' message, the following API functions are generated:

```c
umsg_sub_handle_t umsg_sensors_imu_subscribe(uint32_t prescaler, uint8_t length);
```

- Called from Subscriber task and returns a subscription handle. 

- Prescaler sets output rate division. 

- Length defines the queue length. If length == 1, the queue will always contain the latest value ('Queue Overwrite' on the publisher side)

- if Length > 1, then the queue will hold the first N values ('Queue send to back' on the publisher side)

```c
void umsg_sensors_imu_publish(umsg_sensors_imu_t* data);
```

Publish data. Data will be sent to the message queue of all subscribers (adapted by the prescaler)

```c
uint8_t umsg_sensors_imu_receive(umsg_sub_handle_t queue, umsg_sensors_imu_t* data, uint32_t timeout);
```

Receive function used by subscribers. Timeout is given in [ms]. For infinite timeout use the RTOS defines, such as portMAX_DELAY

```c
uint8_t umsg_sensors_imu_peek(umsg_sensors_imu_t* data);
```
Reads the latest which were published, bypassing the queues. return 0 if no values were ever published.
### Multi-Channel API functions

Both the subscribe and publish API functions have multi-channel variants, with the '_ch' suffix.

```c
umsg_sub_handle_t umsg_sensors_imu_subscribe_ch(uint32_t prescaler, uint8_t length, uint8_t channel);

void umsg_sensors_imu_publish_ch(umsg_sensors_imu_t* data, uint8_t channel);
```

Often there are multiple publishers for the same message type. For example, two imu drivers can be running and each publishes their respective data.

The channel API allows each driver to send to a different channel number, and for the subscribers to decide which channel to listen to.

It's up to the application code to allocate and keep track of the channel numbers.

# Defining messages

A topic is a dedicated .json file that contains a list of messages and enums (optional).

Example.json:
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

Generated Typedefs:

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

**list of primitives:**
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

Field members can be any of the above primitives - as a scalar, array, or bitfield.

They can also be an enum as long as it's declared in the enum section of the file.

The generated code follows this naming template:

```c
typedef struct {
   ...
} umsg_FILENAME_MESSAGENAME_t 
```

All of the topic.json files should be grouped in a single directory. which are then passed to the umsg-gen generator.

# Logging support
The library has a logging support that can be enabled by -l, if you use this, you will get two new types of functions:

```c
uint32_t umsg_sensors_imu_serialize(umsg_sensors_imu_t* data, uint8_t* buffer);
```
This function will put the message into a buffer and will tell you how many bytes from the buffer were used, so you can log in onto an SD card or some other storage system.
The message will be stored as (message class enum, message type enum, message). eg. (UMSG_SENSORS, SENSORS_IMU, struct umsg_sensors_imu_t). The endianity if dependent on the processor for now.

```c
uint8_t umsg_sensors_imu_deserialize(umsg_sensors_imu_t* data,uint8_t* buffer);
```
This function will put the message from a buffer back into struct and it will check if the message class and message type are correct for this type of message, it will also be indicated by the return value of the function.

For now, it is assumed that there are no more than 256 message classes and no more than 256 types of message in a class, this constaint will be fixed in the future.

This option also generated log_parser folder that contains cpp code and CMakeLists that when compiled is able to read the stored messages and write them to .csv files, the structure of the generated files is given as:

```
logfilename/message_class/message_type.csv;
```


# uMsg-Graph
(Work in Progress)


