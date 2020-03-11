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

#include "LatchingButton.h"

// Constructors.
LatchingButton::LatchingButton(int pin) :
	SimpleButton(pin),
	_latched(false),
	_defaultState(false)
{
}

LatchingButton::LatchingButton(int pin, int debounceInterval) :
	SimpleButton(pin, debounceInterval),
	_latched(false),
	_defaultState(false)
{
}

// Destructor.
LatchingButton::~LatchingButton()
{
}

void LatchingButton::setDefaultState(bool latched)
{
	_defaultState = latched;
}

void LatchingButton::setLongPressInterval(int longPressInterval)
{
  _longPressInterval = longPressInterval;
}

BUTTONSTATUS LatchingButton::getStatus()
{
	// Catch transitions from HIGH to LOW.
	switch (update())
	{
		case WASPRESSED:
			// Capture the event of the button press.  Some classes may require this to act on it.
			return WASPRESSED;

		case WASSHORTPRESSED:
			// Toggle state.
			_latched = !_latched;
			return convertStateToButtonStatus();

		case WASLONGPRESSED:
			if (_resetOnLongPress)
			{
				reset();
			}
			else
			{
				_latched = !_latched;
			}
			return convertStateToButtonStatus();

		case ISPRESSED:
		case NOTPRESSED:
		default:
			// Nothing happened so we return based on the state.
			return convertStateToButtonStatus();
	}
}

void LatchingButton::reset()
{
	_latched = _defaultState;
}

BUTTONSTATUS LatchingButton::convertStateToButtonStatus()
{
	if (_latched)
	{
		return ISPRESSED;
	}
	else
	{
		return NOTPRESSED;
	}
}