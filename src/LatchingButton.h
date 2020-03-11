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
	Pressing the button alternates between on (ISPRESSED) and off (NOTPRESSED).
	This effectively creates a virtual latching switch controled by a momentary button.
	The button can be reset to the base (known) state by the user (with a long press, if
	enabled) or programmically.
	
	After a button is press down, the first call to getStatus returns WASPRESSED.
	This allows a derived class to act on the button down press, if required.  Further
	calls to getStatus will then return either ISPRESSED or NOTPRESSED depending
	on the current value of _latched.

	When the button is released, the length of the button press is evaluated.  The behavior
	is then:
		Short Press - The value of _latched is switched and the new state returned (as ISPRESSED
			OR NOT PRESSED).

		Long Press - If reset is enabled, the value of _latched is set to the default state
			and the new state returned.  If reset is disabled, the behavior is the same as
			as short press.

	This button only returns the states, WASPRESSED, ISPRESSED or NOTPRESSED.  A short
	press and a long press are used to either toggle the state or reset the state,
	respectively.  Therefore, they are handled internally and there is no need to
	return them.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef LATCHINGBUTTON_H
#define LATCHINGBUTTON_H

#include <Arduino.h>
#include "ResetableButton.h"
#include "SimpleButton.h"

class LatchingButton : public SimpleButton, public ResetableButton
{
	public:
		LatchingButton(int pin);
		LatchingButton(int pin, int debounceInterval);
		~LatchingButton();

	public:
		// Set the default state.
		void setDefaultState(bool latched);

		void setLongPressInterval(int longPressInterval);

		// Checks the button and returns the current state (true for on or false for off).
		BUTTONSTATUS getStatus();

		// Return to default state.
		void reset();

	private:
		// Converts the latched/unlatched property into a BUTTONSTATUS value.
		BUTTONSTATUS convertStateToButtonStatus();

	private:
		bool		_latched;
		bool		_defaultState;
};

#endif