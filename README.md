# button
## What is button? 
Library for to handle short and long press of buttons

### Contributors

### Software Dependencies
  - none

### BOM
  - 2 pin button
  - 2 wires

### Pinouts
  - one button pin to board ground
  - one button pin to board digital pin with INPUT_PULLUP for resistance

### Information Sources
  - https://www.teachmemicro.com/create-arduino-library/
  - https://my.eng.utah.edu/~cs5780/debouncing.pdf
  - http://www.ganssle.com/debouncing-pt2.htm

### Questions
  - 04/21/20 - Do all (Adafruit) ARM boards have pin pullup? If not, use resistor, remove pinMode from .cpp, flip digitalRead values back

### Learnings
  - 04/21/20 - Agree that button within rotary encoder should be handled by this library, not embedded button handler in rotaryencoder library. Not all rotary encoders have a button embedded, this creates duplicate code.
  - 05/01/20 - Debouncer is helping with noisy Allen Bradley button, but results get better with #DEBUG on? slowing down sample rate? if so, we could implement fix sampling rate to reduce timing dependency?

### Feature Requests
  - 05/14/19
    - add library.properties; see Information Sources for howto
  - 05/01/20
    - Can I refactor code to remove int event and have endpoints handled with a direct return statement?
    - debounce input
 
### Revisions
  - 10/17/14
    - added multiple button support, will be augmented/replaced by rotary encoder in future version
  - 12/31/16
    - latest version in lightbar_lpd8806 copied to create this project
  - 11/24/17
    - enhancements for readability
    - [11/20/17 - lightbar] button globals probably don't need to be global
    - simplified code
    - [12/29/16 - lightbar] buttons to class/library/file separated functions
    - example code added
  - 07/08/18
    - critical bug fix; library was previously broken
    - button schematic image added
  - 07/16/18
    - debug information added
    - # of loops needed to distinguish short from long press passed into class
  - 08/01/18
    - update example file
  - 06/02/19
      [FR 07/16/18] can I inherit a conditional compile from the compiling project to toggle the debug code? -> NO, macros don't pass between project files
  - 04/21/20
    - significant code refactoring
    [FR 05/14/19] the library subdirectory and code directory do not have same file modification dates? -> github source only deployed to /libraries
    - aligned variable types between .h and .cpp
    - example code highlights what button (pin) is sending feedback
    - conditional debug code in .cpp
    [FR 05/14/19] error handling; can we determine if the button is initialized/reading properly -> CLOSED
    [FR 06/02/19] error handling for bad parameters -> checking for out of range buttonLongPressDelay
    [FR 06/02/19] code is completely timing dependent?! I have to tweak the short press/long press differentiator on every MCU -> moved to millis() time difference for button press duration
