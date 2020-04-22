/*
  Project Name: buttonHandler
  Developer:  Eric Klein Jr. (temp2@ericklein.com)

  See README.md for target information, revision history, feature requests, etc.
*/

#include "Arduino.h"
#include "buttonhandler.h"

//#define DEBUG

ButtonHandler::ButtonHandler(int p, long b)
  : pin(p), buttonLongPressDelay(b)
{
}

void ButtonHandler::init() {
  buttonWasPressed = false;
  buttonPressStartTime = 0;
  pinMode(pin, INPUT_PULLUP);
  if (buttonLongPressDelay<1000 || buttonLongPressDelay>5000)
  {
    #ifdef DEBUG
      Serial.println("Library: Button long press definition outside expected parameters");
    #endif
    buttonLongPressDelay = 2500; // simple error correction for bad buttonLongPressDelay parameter
  }
}

int ButtonHandler::handle()
{
  int event;

  // button is pressed as INPUTPULLUP keeps pin high normally
  bool buttonNowPressed = !(digitalRead(pin));

  if (!buttonNowPressed && buttonWasPressed)
  // button press has ended, return short or long button event
  {
    #ifdef DEBUG
      Serial.print("button pin ");
      Serial.print(pin);
      Serial.print(" pressed, starting at ");
      Serial.print(buttonPressStartTime);
      Serial.print(" and ending at ");
      Serial.print(millis());
      Serial.print(" ms, for a duration of ");
      Serial.print(millis() - buttonPressStartTime);
      Serial.println(" ms");
    #endif
    // return short or long button press event
    if ((millis() - buttonPressStartTime) < buttonLongPressDelay)
    {
      event = 1; //short press
    }
    else
    {
      event = 2; //long press
    }
    buttonPressStartTime = 0;
    #ifdef DEBUG
      Serial.println("Resetting button press start time");
    #endif
  }
  else
    // no press or press is still occuring, nothing to act on
    event = 0;

  if (buttonNowPressed && (buttonPressStartTime == 0))
  // start tracking how long the button has been pressed
  {
    #ifdef DEBUG
      Serial.println("Resetting button press start time");
    #endif
    buttonPressStartTime = millis();
  }
  // buffer previous button state
  buttonWasPressed = buttonNowPressed;
  return event;
}