/*
  Project Name:   buttonExample
  Developer:      Eric Klein Jr. (temp2@ericklein.com)
  Description:    example code for buttonhandler library
*/

// Library initialization
#include "buttonhandler.h"

// Assign Arduino pins
#define pushButtonOne 8
#define pushButtonTwo 9

#define buttonLongPressDelay 3000

enum { notPressed = 0, shortPress, longPress };

// instantiate buttons
ButtonHandler buttonOne(pushButtonOne, buttonLongPressDelay);
ButtonHandler buttonTwo(pushButtonTwo, buttonLongPressDelay);

void setup()
{
  Serial.begin(115200);
  while (!Serial) ;

  Serial.print("Button example started, long press delay is ");
  Serial.print(buttonLongPressDelay);
  Serial.println(" ms");
  // Setup buttons
  buttonOne.init();
  buttonTwo.init();
}

void loop()
{
  switch (buttonOne.handle())
  {
    case shortPress:
      Serial.print("Button on pin ");
      Serial.print(pushButtonOne);
      Serial.println(" short press");
      break;
    case longPress:
      Serial.print("Button on pin ");
      Serial.print(pushButtonOne);
      Serial.println(" long press");
      break;
  }
  switch (buttonTwo.handle()) 
  { 
    case shortPress:
      Serial.print("Button on pin ");
      Serial.print(pushButtonTwo);
      Serial.println(" short press");
      break;
    case longPress:
      Serial.print("Button on pin ");
      Serial.print(pushButtonTwo);
      Serial.println(" long press");
      break;
  }
}