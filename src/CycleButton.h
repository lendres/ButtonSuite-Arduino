/*
  The MIT License (MIT)
  
  Copyright (c) 2019 Lance A. Endres
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of
  this software and associated documentation files (the "Software"), to deal in
  the Software without restriction, including without limitation the rights to
  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
  Turns a push button (momentary button) into a button used to cycle through states.
  Pressing the button causes the value to increment.  Once the maximum value
  is reached, the value resets to the initial value.

  The work of debouncing, catching the falling event (HIGH to LOW), and filtering
  out the rising event (LOW to HIGH) is done by the Bounce2 library.  This wrapper
  adds a memory so it can remember if the virtual button is on or off.
*/

#ifndef CYCLEBUTTON_H
#define CYCLEBUTTON_H

#include <Arduino.h>
#include "ResetableButton.h"

class CycleButton : ResetableButton
{
  // Enums.
  public:
    // Specifies the base number to count from.  It's the number that will be returned if no button
    // pushes have been detected.  The default is zero.  
    enum CYCLEBASE
    {
      ZEROBASED,
      ONEBASED
    };
    
  public:
    CycleButton(int pin);
    CycleButton(int pin, int maxValue);
    CycleButton(int pin, CYCLEBASE minValue, int maxValue);
    CycleButton(int pin, int maxValue, int debounceInterval);
    CycleButton(int pin, CYCLEBASE minValue, int maxValue, int debounceInterval);
    ~CycleButton();

    // Set the starting value.
    void setMinimum(CYCLEBASE base);

    // Set the maximum value.
    void setMaximum(unsigned int maxValue);

    // Checks the button and returns the current state (toggled on or off).
    int getValue();

    // Return to default state.
    void reset();

  private:
    unsigned int       _minValue;
    unsigned int       _maxValue;
    unsigned int 		   _value;
};

#endif
