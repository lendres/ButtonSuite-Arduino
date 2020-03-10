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
	This button always returns true.  The purpose of this class is to provide automatic
	implimentation of an always on state for libraries or classes the take TwoStateButtons
	as an argument.  By using a TwoStateButton, as class can automatically implement
	momentary, latching, or always on behavior depending on which class derived from
	the TwoStateButton class is used.  This makes it easy to switch behaviors as needed.
*/

#ifndef ALWAYSONBUTTON_H
#define ALWAYSONBUTTON_H

#include "Arduino.h"
#include "SimpleButton.h"

class AlwaysOnButton : public SimpleButton
{
	public:
		AlwaysOnButton(int pin);
		AlwaysOnButton(int pin, int debounceInterval);
		~AlwaysOnButton();

	public:
		// Returns true if the button is currently pressed.
		BUTTONSTATUS getStatus();
};

#endif