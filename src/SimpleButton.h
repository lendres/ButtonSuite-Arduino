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
	Abstract class that provides interface for a two state button (button that only has
	an on and off state).

	The purpose of this class is to provide automatic implimentation of different behaviors.
	By using different classes derived from SimpleButton, a class can automatically implement
	momentary, latching, always on, or always off behavior.  This makes it easy to implement
	different behaviors or even	switch behaviors during run time.
*/

#ifndef TWOSTATEBUTTON_H
#define TWOSTATEBUTTON_H

#include "Arduino.h"
#include "ButtonBase.h"

class SimpleButton : public ButtonBase
{
	public:
		SimpleButton(int pin);
		SimpleButton(int pin, int debounceInterval);
		~SimpleButton();

	public:
		// Returns true if the button is currently pressed.
		virtual BUTTONSTATUS getStatus() = 0;
};

#endif