/*
  Project Name: buttonHandler.h
  Developer:  Eric Klein Jr. (temp2@ericklein.com)
  Description:  Library for detection of short and long presses for simple buttons
*/

#include "Arduino.h"
#include "buttonhandler.h"

ButtonHandler::ButtonHandler(int p, int b)
  : pin(p), buttonDelay(b)
{
}

void ButtonHandler::init() {
  _buttonWasPressed = false;
  _buttonPressCounter = 0;
}

int ButtonHandler::handle(){
  int event;
  int buttonNowPressed = digitalRead(pin);

  if (!buttonNowPressed && _buttonWasPressed) {
    // Debug code
    // Serial.print("button pin ");
    // Serial.print(pin);
    // Serial.print(" loop count is ");
    // Serial.println(_buttonPressCounter);
    // handle release event
    if (_buttonPressCounter < buttonDelay)  //long press duration expressed in loop iterations
      {
        event = 1;
      }
    else
      event = 2;
  }
  else
    event = 0;

  // update press running duration
  if (buttonNowPressed)
    ++_buttonPressCounter;
  else
    _buttonPressCounter = 0;

  // remember state, and we're done
  _buttonWasPressed = buttonNowPressed;
  return event;
}