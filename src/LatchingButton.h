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
	Turns a push button (momentary button) into a toggle button (latching button).
	Pressing the button alternates between on and off.

	This effectively creates a virtual latching switch controled by a momentary button.
	The button can be reset to the base (known) state by the user (with a long press, if
	enabled) or programmically.

	There are two ways to use the button.  The easiest way is to use the "isLatched" function
	which returns true if the button is latched (on) and false if it is not (off).
	
	The "getStatus" function is not as easy to use, but provides more information.  See the
	"ButtonEnums.h" for descriptions of what the returned values mean.

	When the button is released, the length of the button press is evaluated.  The behavior
	is then:
		Short Press - The value of _latched is toggled.

		Long Press - If reset is enabled, the value of _latched is set to the default state.
		  If reset is disabled, the value of _latched is toggled.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef LATCHINGBUTTON_H
#define LATCHINGBUTTON_H

#include <Arduino.h>
#include "TwoStateButton.h"

class LatchingButton : public TwoStateButton
{
	public:
		LatchingButton(int pin);
		LatchingButton(int pin, int debounceInterval);

		~LatchingButton();

	// Set up functions.  Normally, these would be called in the "setup" function of your sketch.
	public:
		// Set the default state.
		void setDefaultState(bool latched);

	// Status access functions.  Call one of these in the "loop" to get the status of the button.
	public:
		// Returns true if the button is latched (locked in the pressed/on state) or false if it is 
		// not (off state).
		bool pushed();

	// Other control functions.
	public:
		// Return to default state.
		void reset();

	private:
		bool		_latched;
		bool		_defaultState;
};

#endif