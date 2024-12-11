# STM32 Blue Pill USB CDC Project

## Overview

This project demonstrates USB CDC (Communication Device Class) communication on the **STM32F103C8T6** microcontroller (Blue Pill board). The application sends a "Hello World" message via USB every second. The communication can be monitored using a serial terminal such as **PuTTY** or **Tera Term**.

## Features

- USB CDC communication using the **Blue Pill** board.
- Sends a "Hello World from USB CDC" message over USB every second.
- Fully compatible with serial terminal software (e.g., PuTTY, Tera Term).
- Uses STM32CubeMX and HAL library to configure USB device and UART peripherals.

## Hardware Requirements

- **Blue Pill STM32F103C8T6** development board.
- **USB cable** (for data transfer, not just charging).
- A **Windows, Linux, or macOS** PC with **STM32 Virtual COM Port Driver** installed.

## Software Requirements

- **STM32CubeMX** for project configuration.
- **STM32CubeIDE** or **Keil MDK** for code compilation.
- **PuTTY** or **Tera Term** for serial communication.

## Setup Instructions

### 1. Install Required Drivers

Ensure that the **STM32 Virtual COM Port Driver** is installed to allow your PC to communicate with the Blue Pill board via USB. You can download the driver from [STMicroelectronics website](https://www.st.com/en/development-tools/stsw-stm32102.html).

### 2. Configure the Project in STM32CubeMX

1. **Select STM32F103C8T6** as the target MCU.
2. Enable the **USB device** middleware and configure it for **CDC (Communication Device Class)**.
3. Enable **USART2** for debugging if needed (although USB CDC should not need it for this project).
4. Configure the necessary **GPIO** pins for the board (e.g., **User LED** pin for error indication).
5. Generate the initialization code.

### 3. Flash the Firmware

1. Open the project in **STM32CubeIDE** or your preferred IDE.
2. Compile the project to generate the binary.
3. Flash the firmware to the **Blue Pill** board using a compatible **ST-Link** programmer or a **USB-to-serial adapter**.

### 4. Monitor the Output

1. Open **PuTTY** or **Tera Term** and select the corresponding **COM port** for the Blue Pill board.
2. Set the following serial parameters:
   - Baud Rate: **115200** (or **9600** if you modify the code)
   - Data Bits: **8**
   - Stop Bits: **1**
   - Parity: **None**
   - Flow Control: **None**

### 5. Expected Output

After flashing the firmware, open the serial terminal. You should see the following message printed every second:


## Code Explanation

1. **`main.c`**:
   - The program initializes the **USB CDC** and starts transmitting the "Hello World" message every second via **USB**.
   - It uses **CDC_Transmit_FS** function to send data to the connected PC.

2. **USB Initialization**:
   - The **USB device middleware** is initialized in **MX_USB_DEVICE_Init** to configure the board for USB communication.

3. **USART2**:
   - USART2 is configured for debugging (optional), but the communication is handled through USB CDC.

4. **GPIO**:
   - Optional **LED toggling** is used to indicate errors or issues during USB transmission.

## Troubleshooting

- If you don't see output in the serial terminal:
  - Ensure the correct **COM port** is selected.
  - Confirm that the **STM32 Virtual COM Port Driver** is installed.
  - Double-check your **USB cable** (ensure it's a data cable, not just a charging cable).
  - Check if the device appears in **Device Manager** as a **COM port**.
  - Ensure the baud rate and other serial parameters are set correctly in the terminal software.

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
