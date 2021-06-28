/*
	The MIT License (MIT)
	
	Copyright (c) 2021 Lance A. Endres
	
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

#include "CustomButton.h"

// Constructors.
CustomButton::CustomButton(int pin) :
	ButtonBase(pin)
{
}

CustomButton::CustomButton(int pin, int debounceInterval) :
	ButtonBase(pin, debounceInterval)
{
}

// Destructor.
CustomButton::~CustomButton()
{
}

CustomButton::LIGHTBEHAVIOR CustomButton::getBehavior()
{
	switch (update())
	{
		// We want to blink the light for 1 second when the button is pressed and released.
		// In the ButtonSuite, this event returns the WASSHORTPRESSED.  
		case BUTTONSUITE::WASSHORTPRESSED:
		{
			return BLINKONCE;
		}

		// We want to blink the light fastly as long as the button has been held down long
		// enough to be considered a long press and still is being held down.
		case BUTTONSUITE::ISLONGPRESSED:
		{
			return FASTBLINK;
		}

		// If neither of the above two things are true, we turn the light off.
		default:
		{
			return LIGHTOFF;
		}
	}
}