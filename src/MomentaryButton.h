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
	This is standard momentary button.  It returns true when the button is pressed
	and false when it is not.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef MOMENTARYBUTTON_H
#define MOMENTARYBUTTON_H

#include "Arduino.h"
#include "SimpleButton.h"

class MomentaryButton : public SimpleButton
{
	public:
		MomentaryButton(int pin);
		MomentaryButton(int pin, int debounceInterval);
		~MomentaryButton();

	public:
		// Returns true if the button is currently pressed.
		BUTTONSTATUS getStatus();
};

#endif