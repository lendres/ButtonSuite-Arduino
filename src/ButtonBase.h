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
	This is a base class used for adding behavior to push buttons (momentary buttons).
	It uses a debouncer to prevent accidental double readings.  It separates the button
	behavior into currently pressed, short press, long press, or idle (nothing
	happening).
	
	This class is a base class for all other button classes.

	The work of debouncing and catching the state changes (LOW to HIGH or HIGH to LOW)
	is done by the Bounce2 library.

	See also: TwoStateButton, ResettableButton
*/

/*
  You must have the following libraries to run this software.

  Bounce2 by Thomas Ouellet Fredericks, et al.
    - Can be installed from Arduino IDE Library Manager.
    - https://github.com/thomasfredericks/Bounce2
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground.
*/

/*
	If you want debugging messages printed to the serial monitor, enable the serial monitor and
	use the following line in your file:
	
	#define BUTTONSUITEDEBUG
*/

#ifndef BUTTONBASE_H
#define BUTTONBASE_H

#include "Arduino.h"
#include "Bounce2.h"
#include "ButtonEnums.h"

class ButtonBase
{
	// This is an abstract class and is only instantiated by derived classes.
	// Therefore, all the constructors should be protected.
	protected:
		// Constructor for when debouncing and pin reading is not used.  If a derived class uses this constructor
		// they must not call the "update" function.
		ButtonBase();

		// Constructor for setting up and using debouncing.
		ButtonBase(int pin);

		// Constructor for setting up and using debouncing.  Allows specifying the debounce interval.
		ButtonBase(int pin, int debounceInterval);

	public:
		virtual ~ButtonBase();

	// Set up functions.  Normally, these would be called in the "setup" function of your sketch.
	public:
		void setDebounceInterval(int debounceInterval);

	protected:
		// Checks the button and returns the status/state.  This does the work of categorizing the state
		// of the button.  It is up to the derived class to determine behavior based on the returned value.
		BUTTONSUITE::BUTTONSTATUS update();

	private:
		Bounce 		        _debouncer;

	protected:
		// This class needs to have the long press interval so it can determine if
		// a button press was short or long.  However, not all classes derived from
		// this class use a long press.  Therefore, another class exposes the setting
		// of the long press interval.  If a derived class does not use a long press,
		// then that class to determine how a long press is handled (like a short press,
		// ignore it, et cetera).
		unsigned long     _longPressInterval;
};

#endif