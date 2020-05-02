/*
  Project Name: buttonHandler
  Developer:  Eric Klein Jr. (temp2@ericklein.com)

  See README.md for target information, revision history, feature requests, etc.
*/

#ifndef buttonHandler_h
#define buttonHandler_h

#include "Arduino.h"

//#define DEBUG

class ButtonHandler
{
  public:
    ButtonHandler(int pin, long buttonLongPressDelay);
    void init();
    int handle();

  private:
    bool            buttonWasPressed;
    unsigned long   buttonPressStartTime;  
    const int       pin;
    long            buttonLongPressDelay;
};
#endif