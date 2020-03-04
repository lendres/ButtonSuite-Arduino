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
  Abstract class for button classes that use a long press to indicate they should
  reset themselves to some initial/base value.
*/

#ifndef RESETABLEBUTTON_H
#define RESETABLEBUTTON_H

#include <Arduino.h>
#include "ButtonBase.h"

class ResetableButton : public ButtonBase
{
  protected:
    ResetableButton(int pin);
    ResetableButton(int pin, int debounceInterval);
    ~ResetableButton();

  public:
    // If true, a long press resets to the initial state.  Enabled by default.
    void setLongPressReset(bool enabled);
    void setLongPressInterval(int longPressInterval);

    // Return to default state.
    virtual void reset() = 0;

  protected:
    bool              _resetOnLongPress;
};

#endif
