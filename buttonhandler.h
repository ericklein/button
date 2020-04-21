/*
  Project Name: buttonHandler
  Developer:  Eric Klein Jr. (temp2@ericklein.com)

  See README.md for target information, revision history, feature requests, etc.
*/

#ifndef buttonHandler_h
#define buttonHandler_h

#include "Arduino.h"

class ButtonHandler {
  public:
    ButtonHandler(int pin, long buttonDelay);
    void init();
    int handle();

  private:
    boolean     _buttonWasPressed;    // previous state
    long        _buttonPressCounter;  // press running duration
    const int   pin;                 // pin to which button is connected
    const long  buttonDelay;         // number of execution loops to distinguish short v. long press
};

#endif