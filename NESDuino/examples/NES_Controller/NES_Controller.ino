#include "nes.h"

//Defined constants that correspond with the keys in the controller class
#define BTN_A 0
#define BTN_B 1
#define BTN_SELECT 2
#define BTN_START 3
#define BTN_UP 4
#define BTN_DOWN 5
#define BTN_LEFT 6
#define BTN_RIGHT 7

//Define key codes with HID keyboard codes, HID Keyboard codes can be found at http://www.freebsddiary.org/APC/usb_hid_usages.php, section 7.
#define KEY_UP 0x1A
#define KEY_DOWN 0x16
#define KEY_LEFT 0x04
#define KEY_RIGHT 0x07
#define KEY_A 0x1B
#define KEY_B 0x1C
#define KEY_START 0x10
#define KEY_SELECT 0x11

const int pulse = 3;
const int latch = 5;
const int data = 4;

Controller controller(latch, pulse, data);

void setup() {
  Serial.begin(9600);
  while(!Serial) {}
}

void loop() {
  controller.latch();

  //HID data. HID reports are 7 bytes long, the first byte being the modifier (shift, alt, etc.), the rest being the triggered keys.
  uint8_t buf[8] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
  };
  
  if(controller.pressed(BTN_A))
    buf[2] = KEY_A;

  if(controller.pressed(BTN_B))
    buf[3] = KEY_B;

  if(controller.pressed(BTN_START))
    buf[4] = KEY_START;

  if(controller.pressed(BTN_SELECT))
    buf[5] = KEY_SELECT;

  if(controller.pressed(BTN_UP)) {
    buf[6] = KEY_UP;
  }else if(controller.pressed(BTN_DOWN)) {
    buf[6] = KEY_DOWN;
  }else if(controller.pressed(BTN_LEFT)) {
    buf[6] = KEY_LEFT;
  }else if(controller.pressed(BTN_RIGHT)) {
    buf[6] = KEY_RIGHT;
  }

  Serial.write(buf, 8);
}
