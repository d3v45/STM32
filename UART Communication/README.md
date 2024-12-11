# STM32 Blue Pill (STM32F103C8T6) Getting Started Guide

This guide will help you set up and flash your STM32 Blue Pill (STM32F103C8T6) board using **STM32CubeIDE** and **STM32 ST-Link Utility**. Whether you're new to STM32 or just need a quick refresher, this guide will make the process easy to follow.

## Prerequisites

Before we begin, make sure you have the following:

1. **STM32CubeIDE**: The official software for developing with STM32.
2. **STM32 ST-Link Utility**: A tool used to flash the code to the STM32 Blue Pill.
3. **STM32 Blue Pill (STM32F103C8T6)**: The microcontroller board you will work with.

## Steps to Develop and Flash Your Code

### Step 1: Open STM32CubeIDE

Start by opening **STM32CubeIDE**. This is where we will create and configure our project.

### Step 2: Create a New Project

- Go to **File > New > STM32 Project**.
- Choose the **STM32 Blue Pill (STM32F103C8T6)** board as your target.
- Set the configuration options based on your project needs.

### Step 3: Configure the Clock

In the **Clock Configuration** tab, adjust the clock settings as required for your project. This step ensures your board runs at the right speed.

### Step 4: Generate the Code

Once you're happy with the setup, click on **Project > Generate Code** to create the code for your project.

### Step 5: Edit the Code in `main.c`

Open the `main.c` file located in the **Src** folder. Make any changes or additions to the code based on your project requirements. Once done, save the file.

### Step 6: Compile the Code

Now, click on **Project > Build Project** to compile your code. This step will generate a `.bin` file that you can flash onto your STM32 Blue Pill board.

### Step 7: Flash the Code and Switch to Run Mode

- Open **STM32 ST-Link Utility** and connect your STM32 Blue Pill in **flash mode**.
- Load the `.bin` file you just compiled and click to flash it onto the board.
- After the flashing process is complete, switch the board to **normal mode** (also known as **Run Mode**) so your code can start running.

---

That’s it! Your STM32 Blue Pill is now ready to run your code. Feel free to modify or expand on this project as needed. Happy coding!
