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
	ButtonBase(pin),
	_count(0)
{
}

CountingButton::CountingButton(int pin, int debounceInterval) :
	ButtonBase(pin, debounceInterval),
	_count(0)
{
}

// Destructor.
CountingButton::~CountingButton()
{
}

void CountingButton::setLongPressInterval(int longPressInterval)
{
  _longPressInterval = longPressInterval;
}

int CountingButton::getCount()
{
	// Catch transitions from HIGH to LOW.
	switch (update())
	{
		case WASSHORTPRESSED:
			// Button was pushed, so increment counter.
			_count++;
			break;

		case WASLONGPRESSED:
			if (_resetOnLongPress)
			{
				reset();
			}
			break;

		default:
			break;
	}
	
	 return _count;
}

void CountingButton::reset()
{
	_count = 0;
}