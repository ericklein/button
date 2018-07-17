/*
  Project Name:   buttonExample
  Developer:      Eric Klein Jr. (temp2@ericklein.com)
  Description:    example code for buttonhandler library
  
  See README.md for target information, revision history, feature requests, etc.
*/

// Library initialization
#include "buttonhandler.h"

// Assign Arduino pins
#define pushButtonOne 12
#define pushButtonTwo 11

enum { BTN_NOPRESS = 0, BTN_SHORTPRESS, BTN_LONGPRESS };

// instantiate button object
ButtonHandler buttonOne(pushButtonOne);
ButtonHandler buttonTwo(pushButtonTwo);

void setup() {
  Serial.begin(115200);
  Serial.println("Button example started");
  // Setup push buttons
  buttonOne.init();
  buttonTwo.init();
}

void loop()
{
switch (buttonOne.handle()) {
  case BTN_SHORTPRESS:
    Serial.println("buttonOne short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("buttonOne long press"); //debug text
    break;
  }
  switch (buttonTwo.handle()) {
  case BTN_SHORTPRESS:
    Serial.println("buttonTwo short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("buttonTwo long press"); //debug text
    break;
  }
}
