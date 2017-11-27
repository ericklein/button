/*
  Project Name:	buttonHandler.h
  Developer:	Eric Klein Jr. (temp2@ericklein.com)
  Description:	Library for detection of short and long presses for simple buttons
*/

#ifndef buttonHandler_h
#define buttonHandler_h

#include "Arduino.h"

class ButtonHandler {
  public:
    ButtonHandler(int pin);
    void init();
    int handle();

  protected:
    boolean was_pressed;     // previous state
    int pressed_counter;     // press running duration
    const int pin;           // pin to which button is connected
};

#endif