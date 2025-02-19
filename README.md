# ESP32 Firmware AAS Interpreter

## Overview

This repository contains the firmware for the AAS interpreter developed for the ESP32 S3 microprocessor. The firmware is designed to interpret AAS data and interact with various components and protocols.

For more detailed information, please refer to the bachelor's thesis.

## Software Implementation

This chapter describes the software implementation for the AAS interpreter. First, we describe the development software used during development, including the development environment (IDE) and framework. Then, we describe the main program used for interpretation. Finally, we describe the libraries used, both those developed by us and those obtained from external sources. At the end of this chapter, we describe the development of a test OPC UA server, which was subsequently used to test the overall functionality of the AAS interpreter.

### Development Software

#### Development Environment

For the development of the AAS interpreter, we used the open-source IDE **Visual Studio Code** from Microsoft Corporation. The environment is provided for free and is available for Windows, macOS, and Linux. It supports a wide range of programming languages and offers extensive configuration and personalization options. The integrated extension browser makes it very easy to install extensions.

#### Framework Used

To program for the ESP32 S3, we used the **ESP-IDF framework version 5.1.1**. ESP-IDF is the official development framework that provides extensive APIs for programming the ESP32 family of microprocessors. It includes integrated functions for firmware configuration, building, and uploading software. The framework also provides debugging capabilities via JTAG using OpenOCD software, allowing direct access to memory and hardware functions.

### Main Program

The main program consists of the main function `app_main`, which runs immediately after the microprocessor starts, and two tasks, `Is_Card_On_Reader` and `State_Machine`, which run in an infinite loop. The main program is illustrated in the flowchart in Figure 6.1.

#### Function `app_main`

This function is responsible for the basic setup of all the main components used and subsequently calls the tasks `Is_Card_On_Reader` and `State_Machine`, which handle additional program functionality. The flowchart is shown in Figure 6.2.

### Libraries Used

To improve code readability and simplify working with components and protocols, libraries are used. The main advantage of libraries is the ability to test them in parts and maintain the code.

#### Custom Libraries

Since there were no libraries available for the required functions, we developed our own to provide the desired functionality.

- **NFC_reader**: Simplifies working with the `pn532` library.
- **NFC_handler**: Ensures data integrity between the NFC device and the microprocessor.
- **OPC_client**: Manages the Ethernet chip W5500 and applies OPC UA methods.
- **NFC_recipes**: Manages recipes stored in the microprocessor's memory.

#### External Libraries

For various firmware functions, we found ready-made functions on the internet, so it was unnecessary to program them from scratch.

- **pn532**: Manages low-level operations with the PN532 NFC chip.
- **open62541**: An open-source implementation of OPC UA.
- **neopixel**: Controls addressable RGB LEDs.
- **mdns**: Allows the use of multicast Domain Name System.
- **libtelnet**: Implements the Telnet protocol for monitoring the behavior of AAS interpreters over the network.

## Testing

A test OPC UA server was developed to test the overall functionality of the AAS interpreter.

## License

This project is licensed under the MIT License - see the LICENSE file for details.