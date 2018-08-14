# button
Library for simple buttons

Description:  Library for detection of short and long presses for simple buttons

Target
  - Assumes 10K resistor inline before ground, no use of Arduino board pullup (see diagram)

Revisions
  10/17/14
    - added multiple button support, will be augmented/replaced by rotary encoder in future version
  12/31/16
    - latest version in lightbar_lpd8806 copied to create this project
  11/24/17
    - enhancements for readability
    - [11/20/17 - lightbar] button globals probably don't need to be global
    - simplified code
    - [12/29/16 - lightbar] buttons to class/library/file separated functions
    - example code added
  07/08/18
    - critical bug fix; library was previously broken
    - button schematic image added
  07/16/18
    - debug information added
    - # of loops needed to distinguish short from long press passed into class
  08/01/18
    - update example file

Feature Requests
  07/16/18
    - can I inherit a conditional compile from the compiling project to toggle the debug code?