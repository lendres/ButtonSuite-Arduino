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
	The PushEventButton captures each individual button press as discrete events.  It
	does not matter how long the button is pressed down or released.  Only the transition
	between pressed and released is captured.

	Either the push or the release event can be detected.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef PUSHEVENTBUTTON_H
#define PUSHEVENTBUTTON_H

#include "Arduino.h"
#include "TwoStateButton.h"

class PushEventButton : public TwoStateButton
{
	// Enums.
	public:
		// Specifies the base number to count from.  It's the number that will be returned if no button
		// pushes have been detected.  The default is zero.
		enum CAPTURETYPE
		{
			CAPTUREPUSH,
			CAPTURERELEASE,
			CAPTUREBOTH
		};

	public:
		PushEventButton(int pin);
		PushEventButton(int pin, CAPTURETYPE captureType);
		PushEventButton(int pin, int debounceInterval);

		~PushEventButton();

	// Set up functions.  Normally, these would be called in the "setup" function of your sketch.
	public:
		// Set the starting value.  It can be a zero based or one based counter.
		void setCaptureType(CAPTURETYPE captureType);

	// Status access functions.  Call in the "loop" to get the status of the button.
	public:
		// Returns true on the first call after a button press and false otherwise.
		bool pushed();

	private:
		CAPTURETYPE 		        _captureType;
};

#endif