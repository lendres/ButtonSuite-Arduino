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

#include "ToggleButton.h"

// Constructors.
ToggleButton::ToggleButton(int pin) :
	ResetableButton(pin),
	_state(false),
	_defaultState(false)
{
}

ToggleButton::ToggleButton(int pin, int debounceInterval) :
	ResetableButton(pin, debounceInterval),
	_state(false),
	_defaultState(false)
{
}

// Destructor.
ToggleButton::~ToggleButton()
{
}

void ToggleButton::setDefaultState(bool state)
{
	_defaultState = state;
}

bool ToggleButton::getState()
{
	// Catch transitions from HIGH to LOW.
	switch (update())
	{
		case WASSHORTPRESSED:
		{
			// Toggle state.
			_state = !_state;
			break;
		}

		case WASLONGPRESSED:
		{
			if (_resetOnLongPress)
			{
				reset();
			}
			break;
		}

		default:
		{
			break;
		}
	}

	 return _state;
}

void ToggleButton::reset()
{
	_state = _defaultState;
}