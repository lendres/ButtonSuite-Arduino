/*
	The MIT License (MIT)
	
	Copyright (c) 2021 Lance A. Endres
	
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
	This class is used to demonstrate how to derive your own custom behavior for
	a button.  While there are many examples of button classes in the library, they
	are largely inherited from intermediate classes.  However, many custom buttons
	will likely find it better to inherit direction from the ButtonBase class.
*/

/*
	To use a button with this library, the button should be wired with one side
	connected to the Arduino pin and the other side connected to ground such that
	when the button is pressed, the pin is brought to ground (LOW).
*/

#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "Arduino.h"
#include "ButtonBase.h"

class CustomButton : public ButtonBase
{
	public:
		enum LIGHTBEHAVIOR
		{
			LIGHTOFF,
			BLINKONCE,
			FASTBLINK		
		};

	public:
		CustomButton(int pin);
		CustomButton(int pin, int debounceInterval);

		~CustomButton();

	// Status access functions.  Call in the "loop" to get the status of the button.
	public:
		// Returns a value to that states what the light should do.
		LIGHTBEHAVIOR getBehavior();
};

#endif