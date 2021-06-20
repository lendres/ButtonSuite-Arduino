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

bool LatchingButton::isLatched()
{
	getStatus();
	return _latched;
}

BUTTONSTATUS LatchingButton::getStatus()
{
	// Get the status.
	BUTTONSTATUS buttonStatus = update();

	switch (buttonStatus)
	{
		case JUSTPRESSED:
		{
			// Capture the event of the button press.  Some classes may require this to act on it.
			return JUSTPRESSED;
		}

		case WASSHORTPRESSED:
		{
			// Toggle state.
			_latched = !_latched;
			return WASSHORTPRESSED;
		}

		case WASLONGPRESSED:
		{
			if (_resetOnLongPress)
			{
				reset();
			}
			else
			{
				_latched = !_latched;
			}
			return WASLONGPRESSED;
		}

		case ISPRESSED:
		case NOTPRESSED:
		default:
		{
			// Nothing changed with the button, so we return a value based on the latched state.
			// This means that it does not matter if the button is currently pressed or not pressed,
			// it returns pressed when latched and not pressed when not latched.
			return convertStateToButtonStatus();
		}
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