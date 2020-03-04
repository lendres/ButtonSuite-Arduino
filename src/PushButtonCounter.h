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
  Turns a push button (momentary button) into a counter.  The counter is
  incremented each time the button is pushed.
  
  The work of debouncing, catching the falling event (HIGH to LOW), and filtering
  out the rising event (LOW to HIGH) is done by the Bounce2 library.  This wrapper
  adds a memory so it can remember if the virtual button is on or off.
*/

#ifndef PUSHBUTTONCOUNTER_H
#define PUSHBUTTONCOUNTER_H

#include <Arduino.h>
#include "ResetableButton.h"

class PushButtonCounter : public ResetableButton
{
public:
    PushButtonCounter(int pin);
    PushButtonCounter(int pin, int debounceInterval);
    ~PushButtonCounter();

    // Checks the button and returns the current count.
    int getCount();

    // Return to zero.
    void reset();

private:
    int 		  _count;
};

#endif
