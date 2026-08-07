# STM32 Discovery Board Example

This directory contains a basic example project demonstrating how to use μMsg on an STM32 Discovery board with STM32CubeIDE.

## Setup Instructions

1. Open STM32CubeIDE and create a new STM32 Project targeting your Discovery board.
2. Configure your peripherals and enable FreeRTOS in the Middleware settings.
3. Generate the initialization code.
4. Copy the contents of `umsg_lib` into your project.
5. Add `main.c` from this example to your project.
6. Ensure `port_freertos.c` is included in `umsg_lib/core/src`.
7. Build and run.

## Usage

This example creates two FreeRTOS tasks:
- `BatteryTX`: Publishes battery state updates every second.
- `BatteryRX`: Subscribes to battery state updates and processes them.
