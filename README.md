# Protogen

This is my repository for storing the code I am making for my protogen suit. I will start the project with creating the code in Arduino C, then I will recreate it in pure C or C++.

## What you will need to recreate this

- 14x AdaFruit 1.2" 8x8 I2C matrix in whichever color you prefer. I used [these](https://www.adafruit.com/product/1052).
- 1x Microcontroller with at least 2x I2C like STM32F407G-DISC1 (sigle I2C-microcontrollers can be used as well, like an ESP32 or Arduino board)
- If you are using a single board, you will need a multiplexer, such as the PCA9548A.
- Plenty of wires and breadboards for prototyping
- A battery pack or a powerbank
- The kaiborg studios protogen set
- For the STM32F407G-DISC1, you must also have STM Studio. For the ESP32/Arduino boards, you must have Arduino IDE.
- For ESP32/Arduino you will also require Adafruit LED Backpack and Adafruit GFX plus other library dependencies. More information [here](https://learn.adafruit.com/adafruit-led-backpack/1-2-8x8-arduino-wiring-and-setup).

## My to-do list

- I will first start making the more neutral animations before diving into the more expressive emotions for the protogen.
- I will create a PCB for easy project assembly.
