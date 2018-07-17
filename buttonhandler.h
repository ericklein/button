/*
  Project Name: buttonHandler.h
  Developer:  Eric Klein Jr. (temp2@ericklein.com)
  Description:  Library for detection of short and long presses for simple buttons
*/

#ifndef buttonHandler_h
#define buttonHandler_h

#include "Arduino.h"

class ButtonHandler {
  public:
    ButtonHandler(int pin, int buttonDelay);
    void init();
    int handle();

  private:
    boolean   _buttonWasPressed;    // previous state
    int       _buttonPressCounter;  // press running duration
    const int pin;                 // pin to which button is connected
    const  int buttonDelay;         // number of execution loops to distinguish short v. long press
};

#endif