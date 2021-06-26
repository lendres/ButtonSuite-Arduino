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
	Turns a push button (momentary button) into a counter.  The counter is
	incremented each time the button is pushed.  The counter continues to
	increment until it is reset by either the user (with a long press, if enabled)
	or programically reset.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef COUNTINGBUTTON_H
#define COUNTINGBUTTON_H

#include <Arduino.h>
#include "ResettableButton.h"

class CountingButton : public ResettableButton
{
	public:
		CountingButton(int pin);
		CountingButton(int pin, int debounceInterval);

		~CountingButton();

	// Set up functions.  Normally, these would be called in the "setup" function of your sketch.
	public:

	// Status access functions.  Call in the "loop" to get the status of the button.
	public:
		// Checks the button and returns the current count.
		int getCount();

	// Other control functions.
	public:
		// Return to zero.
		void reset();

	private:
		int 		  _count;
};

#endif