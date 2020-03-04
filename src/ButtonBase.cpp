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

#include "ButtonBase.h"

// Constructors.
ButtonBase::ButtonBase(int pin) :
  _longPressInterval(1000)
{
  _debouncer.attach(pin, INPUT_PULLUP);
  _debouncer.interval(5);
}

ButtonBase::ButtonBase(int pin, int debounceInterval) :
  _longPressInterval(1000)
{
  // By using "INPUT_PULLUP" the debouncer will also set the pin to
  // both INPUT mode and use the internal pull up resistors.
  _debouncer.attach(pin, INPUT_PULLUP);
  _debouncer.interval(debounceInterval);
}

// Destructor.
ButtonBase::~ButtonBase()
{
}

void ButtonBase::setDebounceInterval(int debounceInterval)
{
  _debouncer.interval(debounceInterval);
}

BUTTONSTATUS ButtonBase::update()
{
  // Have the debouncer update.
  _debouncer.update();

  // Read returns true if the pin is reading high.  In our case, if the pin is low, the
  // button is pressed.
  if (!_debouncer.read())
  {
    #ifdef BUTTONDEBUG
      Serial.println("ButtonBase::update: ISPRESSED");
    #endif
    return ISPRESSED;
  } 

  // Catch transitions from LOW to HIGH.
  if (_debouncer.rose())
  {
    // Button was pushed so remember the last press type.
    if (_debouncer.previousDuration() < _longPressInterval)
    {
      #ifdef BUTTONDEBUG
        Serial.println("ButtonBase::update: WASSHORTPRESSED");
      #endif
      return WASSHORTPRESSED;
    }
    else
    {
      #ifdef BUTTONDEBUG
        Serial.println("ButtonBase::update: WASLONGPRESSED");
      #endif
      return WASLONGPRESSED;
    }
  }
  else
  {
    // Button is still in unpushed state.
    #ifdef BUTTONDEBUG
      Serial.println("ButtonBase::update: IDLE");
    #endif
    return ISIDLE;
  }
}
