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
	
	This class also acts as a base class for other button related classes.

	The work of debouncing and catching the state changes (LOW to HIGH or HIGH to LOW)
	is done by the Bounce2 library.

	See also: PushButton, ToggleButton, PushButtonCounter, CycleButton
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

#ifndef BUTTONENUMS_H
#define BUTTONENUMS_H

// Button status.
enum BUTTONSTATUS
{
	// Was just pressed down (first call to "update" after the button was pressed).
	WASPRESSED,
	
	// Is still pressed down.
	ISPRESSED,

	// The button was just released and the duration held down was considered short (less than long press duration).
	WASSHORTPRESSED,

	// The button was just released and the duration held down was considered long (more than long press duration).
	WASLONGPRESSED,

	// Button is not pressed/on.
	NOTPRESSED
};

#endif