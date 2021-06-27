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
	TwoStateButton(pin),
	_latched(false),
	_defaultState(false)
{
}

LatchingButton::LatchingButton(int pin, int debounceInterval) :
	TwoStateButton(pin, debounceInterval),
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

bool LatchingButton::pushed()
{
	// Get the status.
	BUTTONSUITE::BUTTONSTATUS buttonStatus = update();

	switch (buttonStatus)
	{
		case BUTTONSUITE::WASSHORTPRESSED:
		case BUTTONSUITE::WASLONGPRESSED:
		{
			// Toggle state.
			_latched = !_latched;
			break;
		}

		default:
		{
			// Default doesn't do anything, it just catches all other values of the enumeration
			// so the compiler doesn't complain they are not handled.
			break;
		}
	}

	// This converts the latched state into a state the getStatus() function can return.
	return _latched;
}

void LatchingButton::reset()
{
	_latched = _defaultState;
}