#ifndef NES_H
#define NES_H

/**
 * NES Controller Library for Arduino
 * Created by Daniel Fanara <fanardat16@gmail.com> 2016.
 * 
 * NES Documentation: http://www.mit.edu/~tarvizo/nes-controller.html
 * 
 * Button Mapping:
 * 0 = a
 * 1 = b
 * 2 = select
 * 3 = start
 * 4 = up
 * 5 = down
 * 6 = left
 * 7 = right
 * 
 * pulse pin must be on an interruptable pin (pins 2 or 3 on UNO)
 */

class Controller {
  public:
    Controller(int latch, int pulse, int data);
    void latch(); 
    bool pressed(int button);
    bool isLatched();
  private:
    void readState(int state);
    int _latch;
    int _pulse;
    int _data;
    bool _latched;
    bool _a;
    bool _b;
    bool _start;
    bool _select;
    bool _up;
    bool _down;
    bool _left;
    bool _right;   
};

#endif
