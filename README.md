# button
## What is button? 
Library for to handle short and long press of buttons

### Contributors


### Software Dependencies

### BOM
  - simple button

### Pinouts
  - Assumes 10K resistor inline before ground, no use of Arduino board pullup (see diagram)


### Information Sources
  - https://www.teachmemicro.com/create-arduino-library/

### Issues

### Questions
  - 04/21/20 - Do Adafruit ARM boards have pin pullup?

### Learnings
  - 04/21/20 - Agree that button within rotary encoder should be handled by this library, not embedded button handler in rotaryencoder library. Not all rotary encoders have a button embedded, this creates duplicate code.

### Feature Requests
  - 05/14/19
    - error handling; can we determine if the button is initialized/reading properly
    - add library.properties; see Information Sources for howto
  - 06/02/19
    - code is completely timing dependent?! I have to tweak the short press/long press differentiator on every MCU
    - error handling; bad parameters
 
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
    [FR 07/16/18] can I inherit a conditional compile from the compiling project to toggle the debug code?
      - NO, macros don't pass between project files
  - 04/21/20
      [FR 05/14/19] the library subdirectory and code directory do not have same file modification dates? -> github source only deployed to /libraries
      - aligned variable types between .h and .cpp