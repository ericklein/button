/*
  Project Name : button
  Developer : Eric Klein Jr. (temp2@ericklein.com)
  Description : Example code to read multiple buttons
  Last Revision Date : 12/31/16

  Sources

  Target

 Revisions
 12/31/16
  - latest version in lightbar_lpd8806 copied to create this project
  
  Feature Requests

*/

// Library initialization

// Assign Arduino pins
#define pushButtonOnePin            9
#define pushButtonTwoPin            10

// Assign global variables
const byte longPressLength = 25;    // Min number of loops for a long press
const byte loopDelay = 20;          // Delay per main loop in ms

enum { EV_NONE = 0, EV_SHORTPRESS, EV_LONGPRESS };

// Class definition

class ButtonHandler {
  public:
    // Constructor
    ButtonHandler(int pin, int longpress_len = longPressLength);

    // Initialization done after construction, to permit static instances
    void init();

    // Handler, to be called in the loop()
    int handle();

  protected:
    boolean was_pressed;     // previous state
    int pressed_counter;     // press running duration
    const int pin;           // pin to which button is connected
    const int longpress_len; // longpress duration
};

ButtonHandler::ButtonHandler(int p, int lp)
  : pin(p), longpress_len(lp)
{
}

void ButtonHandler::init()
{
  pinMode(pin, INPUT_PULLUP);
  was_pressed = false;
  pressed_counter = 0;
}

int ButtonHandler::handle()
{
  int event;
  int now_pressed = !digitalRead(pin);

  if (!now_pressed && was_pressed) {
    // handle release event
    if (pressed_counter < longpress_len)
      event = EV_SHORTPRESS;
    else
      event = EV_LONGPRESS;
  }
  else
    event = EV_NONE;

  // update press running duration
  if (now_pressed)
    ++pressed_counter;
  else
    pressed_counter = 0;

  // remember state, and we're done
  was_pressed = now_pressed;
  return event;
}

// Instantiate button objects
ButtonHandler buttonOne(pushButtonOnePin);
ButtonHandler buttonTwo(pushButtonTwoPin);

void buttonEvent(const char* button_name, int event)
{
  //short press on buttonOne
  if ((button_name == "buttonOne") && (event == 1))
  {
      Serial.println("short press on button one");
  }
  //long press on buttonTwo
  if ((button_name == "buttonOne") && (event == 2))
  {
    Serial.println("long press on button one");
  }

  //short press on buttonTwo
  if ((button_name == "buttonTwo") && (event == 1))
  {
        Serial.println("short press on button two");
  }

  //long press on buttonTwo
  if ((button_name == "buttonTwo") && (event == 2))
  {
        Serial.println("long press on button two");
  }
    delay(loopDelay); //debounce
}

void setup() {
  Serial.begin(9600);
  // Setup push buttons
  buttonOne.init();
  buttonTwo.init();
}

void loop()
{
  // read buttons for events
  int event1 = buttonOne.handle();
  int event2 = buttonTwo.handle();

  // deal with button events
  buttonEvent("buttonOne", event1);
  buttonEvent("buttonTwo", event2);
}
