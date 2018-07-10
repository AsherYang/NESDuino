# NESDuino

Despite the terrible name, NESDuino is quite a useful arduino library for any individual looking to interface a Nintendo Entertainment System controller with an Arduino Uno (or other Arduino variant)

NESDuino supports getting the button state of every button on an NES Controller. The arduino is used to power the controller as well. 

### To Get Started, You Will Need
 * An Arduino Uno (Other variants will work, but the tutorial is made for an Uno)
 * A Nintendo Entertainment System Controller
 * Female NES Controller Socket (Can be purchased online or stripped from a broken console)
 * Basic tools for working with electronics such as a soldering iron, wire strippers, etc.

### Let's Get Started
This tutorial will setup your Arduino Uno as a Human Interface Device in order to emulate the Keypresses of a Keyboard without any extra software running on your computer. 

First off, we will need two different sets of firmware for the Arduino, [Arduino HID Firmware](http://dl.dropbox.com/u/1816557/Arduino-keyboard-0.3.hex) and [Arduino USB Serial Firmware](https://raw.githubusercontent.com/arduino/Arduino/master/hardware/arduino/avr/firmwares/atmegaxxu2/UNO-dfu_and_usbserial_combined.hex). The `Arduino USB Serial Firmware` come preinstalled on Arduino UNO chips where the Arduino Boot Loader is already installed, and allows the Arduino to communicate over USB as a Serial interface (allowing you to send information back and forth between the computer and Arduino directly.) The `Arduino HID Firmware` allows us to modify the Arduino to interact as a keyboard, allowing us to simulate keypresses.

For instructions on how to install the firmware on the Arduino, follow the instructions on the [Official Arduino Documentation](https://www.arduino.cc/en/Hacking/DFUProgramming8U2). First, you will need to flash the `Arduino USB Serial Firmware` to the arduino. It is likely that this is already installed on the Arduino, but it is useful to know that the latest version is installed.

After we install the `Arduino HID Firmware`, we will not be able to flash new programs to the Arduino unless we revert the firmware back to the `Arduino USB Serial Firmware`. This is because the Arduino is not accepting Serial connections from the computer, so it cannot accept new programs. If we need to install new programs on the Arduino after we flash the `Arduino HID Firmware`, it is very easy to revert back to the old firmware.

Next, before installing the `Arduino HID Firmware`, flash the program onto the Arduino using the Arduino IDE. Download the `NESDuino` directory from this repository, and open it using the Arduino IDE. Then, upload the sketch to the Arduino as you normally would. Now the latest version of the NESDuino software should be installed on the Arduino.

Now that we have installed the sketch to the Arduino before installing the `Arduino HID Firmware`, we can go ahead and flash the new firmware to the Arduino. This can be done by using the software you installed by following the official Arduino documentation. Simply select the `Arduino HID Firmware.hex` file, and write it to the Arduino.

Now the firmware and sketch should be installed to the arduino, and we can begin to interface the NES hardware with the microcontroller.

### Wiring it all together.
This [NES Controller Pinout](http://www.mit.edu/~tarvizo/nes-controller.html) was extremely useful when wiring up my NES Controller Socket. Simply follow the diagram and attach lead wires from the Power, Ground, Pulse, Latch, and Data pins. 

Next, we need to connect the pins of the controller socket to the pins on the Arduino. By default the pulse pin is mapped to Arduino pin 3, the latch pin to Arduino pin 5, and the data pin to Arduino pin 4. The pin mappings can be changed in the sketch file before uploading it to the Arduino. 

After the NES Socket pins are connected to the Arduino, connect the power pin to the 5v pin on the Arduino, and the Ground pin to the ground pins on the Arduino.

Now when you connect the Arduino to your computer via USB, and plug the NES Controller into the Arduino, you can see characters appear on the screen as you press the buttons. You can change the keys that each NES Button triggers by mapping the definitions in the sketch file to the propper HID Keyboard equivalent. You can find a list of appropriate values for each key in section 7 of [this site](http://www.freebsddiary.org/APC/usb_hid_usages.php). Note: If you change the sketch and want to reupload it to the Arduino after writing the `Arduino HID Firmware`, you will have to revert back to the old firmware before doing so, then update back to the new firmware.

### The Aftermath
Again, just to reitterate. If you intend to use your Arduino for other projects after this one, you will need to revert your firmware back to the `Arduino USB Serial Firmware` before uploading new sketches. This process is simple to do, and is well documented on the official Arduino documentation. 

To make using your new USB NES Controller more convenient, you can embed an Arduino inside of the casing of the NES Controller, and simply exchange the NES cord comming out of the controller for a USB A cord that can plug directly into your computer.

### Contibutors
Thank you to those who have contributed to make this project even better.
* [Daniel Fanara](http://github.com/dfanara) (Author)
* [per1234](http://github.com/per1234) (Examples Update)
