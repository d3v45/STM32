# STM32
A versatile collection of projects showcasing the power of STM32 microcontrollers. Explore communication protocols like USB, UART, SPI, and I2C, along with embedded systems applications, peripheral integration, and real-world examples. Perfect for learning, experimenting, and mastering STM32 development!

# STM32 Projects Repository

Welcome to the STM32 Projects repository! This folder contains two exciting projects designed for the **STM32 Blue Pill (STM32F103C8T6)** development board. The projects demonstrate UART and USB communication, perfect for getting hands-on with STM32 development.

## Projects

### 1. [UART Communication](./UART Communication)

This project demonstrates **UART communication** on the STM32 Blue Pill. It covers the steps to set up, develop, and flash the code, allowing you to use UART for serial communication between the STM32 board and a PC.

#### Features:
- STM32 UART communication setup.
- Simple code to communicate via UART.
- Includes step-by-step instructions to get started with STM32CubeIDE and STM32 ST-Link Utility.

---

### 2. [USB Communication](./usbcommunication)

This project demonstrates **USB CDC (Communication Device Class)** communication on the STM32 Blue Pill. It sends a "Hello World" message via USB every second and can be monitored using a serial terminal such as **PuTTY** or **Tera Term**.

#### Features:
- USB CDC communication via STM32.
- Sends "Hello World from USB CDC" every second.
- Compatible with serial terminal software (e.g., PuTTY, Tera Term).
- Configured using STM32CubeMX and STM32 HAL library.

---

## Resources

This folder also contains some useful resources to support your development process, including drivers, configuration files, and additional documentation to help you understand and expand your projects.

## How to Get Started

1. Choose either the **UART Communication** or **USB Communication** project.
2. Follow the instructions in each project's `README.md` to configure your project in STM32CubeIDE and flash it onto the STM32 Blue Pill.
3. Use the necessary software tools like **PuTTY**, **Tera Term**, or **STM32 ST-Link Utility** to monitor or communicate with the STM32 board.

## Contributing

Feel free to fork this repository, modify the projects, and contribute back with improvements or new features! If you encounter any issues or have suggestions, open an issue or pull request.

## License

This repository is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
