
/*
  Project Name: buttonHandler.h
  Developer:  Eric Klein Jr. (temp2@ericklein.com)
  Description:  Library for detection of short and long presses for simple buttons
*/

#include "Arduino.h"
#include "buttonhandler.h"

ButtonHandler::ButtonHandler(int p)
  : pin(p)
{
}

void ButtonHandler::init() {
  pinMode(pin, INPUT_PULLUP);
  was_pressed = false;
  pressed_counter = 0;
}

int ButtonHandler::handle(){
  int event;
  int now_pressed = !digitalRead(pin);

  if (!now_pressed && was_pressed) {
    // handle release event
    if (pressed_counter < 25)  //long press duration expressed in loop iterations
      event = 1;
    else
      event = 2;
  }
  else
    event = 0;

  // update press running duration
  if (now_pressed)
    ++pressed_counter;
  else
    pressed_counter = 0;

  // remember state, and we're done
  was_pressed = now_pressed;
  delay(20); // button debounce delay expressed in ms
  return event;
}