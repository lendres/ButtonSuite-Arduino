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
	Pressing the button alternates between on (true) and off (false).  If the
	button is pushed once to turn in on (true) it will continue to return on
	(true) until the button is pushed again.  This effectively creates a
	virtual latching switch controled by a momentary button.  The toggle button
	can be reset to the base (known) state by the user (with a long press, if
	enabled) or programmically.
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
#include "TwoStateButton.h"

class LatchingButton : public TwoStateButton, public ResetableButton
{
	public:
		LatchingButton(int pin);
		LatchingButton(int pin, int debounceInterval);
		~LatchingButton();

	public:
		// Set the default state.
		void setDefaultState(bool state);

		void setLongPressInterval(int longPressInterval);

		// Checks the button and returns the current state (true for on or false for off).
		bool getState();

		// Return to default state.
		void reset();

	private:
		bool		_state;
		bool		_defaultState;
};

#endif