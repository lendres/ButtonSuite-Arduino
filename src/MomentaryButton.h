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
	This is standard momentary button, however, there are a few ways to use it.  Typically,
	only one of the methods will be used depending on the required functionality.  Two functions
	allow quick use for common scenarios.  The third allows for getting more detailed information.
	
	The "isPressed" function can be used to determine if the button is currently pressed or not.  This
	is useful for when you only want to know to current state of the button.  For example, turning on
	an LED when the button is held down and turning it off when the button is released.
	
	The "wasPressed" function can be used to determine when individual button actuation events (a press
	and a release) occur.  For example, you want an event to occur after the release of a button press.

	The "getStatus" function returns the exact status.  See the "ButtonEnums.h" for descriptions of what
	the returned values mean.
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

	// Status access functions.  Call one of these in the "loop" to get the status of the button.
	public:
		// Returns true if the button is currently pressed down.  Use this if when you only want to know if the
		// button is currently pressed down or not.
		bool isPressed();

		// Returns true if the button was pressed and released.  Use this to capture individual button presses.
		bool wasPressed();

		// Returns the exact status of the button.  This is the most detailed option as it will return
		// specific state of the button.  It is also used to remain compatible with the other two-state
		// buttons.  If you need to make your code compatible with multiple button types you need to use
		// this function.
		BUTTONSTATUS getStatus();
};

#endif