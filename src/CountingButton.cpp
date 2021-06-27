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

#include "CountingButton.h"

// Constructors.
CountingButton::CountingButton(int pin) :
	ResettableButton(pin),
	_count(0)
{
}

CountingButton::CountingButton(int pin, int debounceInterval) :
	ResettableButton(pin, debounceInterval),
	_count(0)
{
}

// Destructor.
CountingButton::~CountingButton()
{
}

int CountingButton::getCount()
{
	// Catch transitions from HIGH to LOW.
	switch (update())
	{
		case BUTTONSUITE::WASSHORTPRESSED:
		{
			// Button was pushed, so increment counter.
			_count++;
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
				_count++;
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
	
	 return _count;
}

void CountingButton::reset()
{
	_count = 0;
}