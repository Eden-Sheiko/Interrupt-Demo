# Interrupt Demo
This program demonstrates how to use interrupts on an AVR microcontroller to toggle LEDs based on switch input.

## Hardware Setup
The following hardware is required to run this program:

* AVR microcontroller (e.g. ATmega328P)
* Two momentary switches
* Two LEDs (green and red)
* Resistors (220 Ohm recommended)
The switches should be connected to input pins on the microcontroller, and the LEDs should be connected to output pins with current-limiting resistors.

* SW1 (switch 1) should be connected to PD3
* SW2 (switch 2) should be connected to PD2
* Green LED should be connected to PB5
* Red LED should be connected to PB4
## Interrupt Configuration
SW1 is configured to use "Logical Change Trigger". When an interrupt is received by SW1, it will toggle the green LED.

SW2 is configured to use "Rising Edge Trigger". When an interrupt is received by SW2, it will toggle the red LED.

## Code
The setup() function initializes the microcontroller and sets up the interrupt triggers. The loop() function is empty, as the LED state changes are handled by the interrupt service routines (ISRs).

## Building and Uploading
To build and upload this program to an AVR microcontroller using the AVR-GCC toolchain, follow these steps:

1. Install AVR-GCC and AVRDUDE (if not already installed)
2. Clone this repository to your local machine
3. Navigate to the project directory
4. Run make to build the program
5. Connect the AVR programmer to the microcontroller
6. Run make flash to upload the program to the microcontroller
## License
This code is released under the MIT License. See LICENSE for details.
