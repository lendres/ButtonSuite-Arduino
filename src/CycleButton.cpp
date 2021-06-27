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

#include "CycleButton.h"

// Constructors.
CycleButton::CycleButton(int pin) :
	ResettableButton(pin),
	_minValue(ZEROBASED),
	_maxValue(2),
	_value(0)
{
}

CycleButton::CycleButton(int pin, int maxValue) :
	ResettableButton(pin),
	_minValue(ZEROBASED),
	_maxValue(maxValue),
	_value(0)
{
}

CycleButton::CycleButton(int pin, CYCLEBASE minValue, int maxValue) :
	ResettableButton(pin),
	_minValue(minValue),
	_maxValue(maxValue),
	_value(0)
{
}

CycleButton::CycleButton(int pin, int maxValue, int debounceInterval) :
	ResettableButton(pin, debounceInterval),
	_minValue(ZEROBASED),
	_maxValue(maxValue),
	_value(0)
{
}

CycleButton::CycleButton(int pin, CYCLEBASE minValue, int maxValue, int debounceInterval) :
	ResettableButton(pin, debounceInterval),
	_minValue(minValue),
	_maxValue(maxValue),
	_value(0)
{
}

// Destructor.
CycleButton::~CycleButton()
{
}

// Set the starting value.
void CycleButton::setMinimum(CYCLEBASE base)
{
	_minValue = base;
}

// Set the maximum value.
void CycleButton::setMaximum(unsigned int maxValue)
{
	_maxValue = maxValue;
}

int CycleButton::getValue()
{
	// Catch transitions from HIGH to LOW.
	switch (update())
	{
		case BUTTONSUITE::WASSHORTPRESSED:
		{
			incrementValue();
			break;
		}

		case BUTTONSUITE::WASLONGPRESSED:
		{
			// If the reset on long press mode is enabled, we reset, otherwise we treat
			// this as a regular buttom push.
			if (_resetOnLongPress)
			{
				reset();
			}
			else
			{
				incrementValue();
			}
			break;
		}

		default:
		{
			// Default is not doing anything, it is just here to stop the compiler from complaining that
			// not all the cases have been handled.
			break;
		}
	}

	 return _value;
}

void CycleButton::reset()
{
	_value = _minValue;
}

void CycleButton::incrementValue()
{
	// Button was pushed, so increment counter.
	_value++;

	// If we go over the max value, reset.
	if (_value > _maxValue)
	{
		reset();
	}
}