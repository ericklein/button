/*
  Project Name:   buttonExample
  Developer:      Eric Klein Jr. (temp2@ericklein.com)
  Description:    example code for buttonhandler library
  
  See README.md for target information, revision history, feature requests, etc.
*/

// Library initialization
#include "buttonhandler.h"

// Assign Arduino pins
#define pushButtonPin 10

enum { BTN_NOPRESS = 0, BTN_SHORTPRESS, BTN_LONGPRESS };

// instantiate button object
ButtonHandler buttonTest(pushButtonPin);

void setup() {
  Serial.begin(57600);
  // Setup push buttons
  buttonTest.init();
}

void loop()
{
switch (buttonTest.handle()) {
  case BTN_SHORTPRESS:
    Serial.println("buttonTest short press"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("buttonTest long press"); //debug text
    break;
  }
}
