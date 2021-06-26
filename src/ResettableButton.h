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
	Abstract class for button classes that use a long press to indicate they should
	reset themselves to some initial/base value.  Exposes the interface for setting
	the enable/disable of the long press and the duration of the interval.

	The ButtonBase holds the long press interval duration because it needs it to
	differentiate a short versus a long press.
*/

#ifndef RESETABLEBUTTON_H
#define RESETABLEBUTTON_H

#include <Arduino.h>
#include "ButtonBase.h"

class ResettableButton : public ButtonBase
{
	protected:
		// This is an abstract class and is only instantiated by derived classes.
		// Therefore, all the constructors should be protected.
		ResettableButton(int pin);
		ResettableButton(int pin, int debounceInterval);

		virtual ~ResettableButton();

	// Set up functions.  Normally, these would be called in the "setup" function of your sketch.
	public:
		// If true, a long press resets to the initial state.  Enabled by default.
		void setResetOnLongPress(bool enabled);

		// Sets the length of time required for a press to be considered a long press.
		void setLongPressInterval(int longPressInterval);

	// Other control functions.
	public:
		// Return to default state.
		virtual void reset() = 0;

	protected:
		bool              _resetOnLongPress;
};

#endif