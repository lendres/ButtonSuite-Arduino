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

#include "ButtonBase.h"

// Constructors.
ButtonBase::ButtonBase() :
	_longPressInterval(0)
{
}

ButtonBase::ButtonBase(int pin) :
	_longPressInterval(1000)
{
	_debouncer.attach(pin, INPUT_PULLUP);
	_debouncer.interval(5);
}

ButtonBase::ButtonBase(int pin, int debounceInterval) :
	_longPressInterval(1000)
{
	// By using "INPUT_PULLUP" the debouncer will also set the pin to
	// both INPUT mode and use the internal pull up resistors.
	_debouncer.attach(pin, INPUT_PULLUP);
	_debouncer.interval(debounceInterval);
}

// Destructor.
ButtonBase::~ButtonBase()
{
}

void ButtonBase::setDebounceInterval(int debounceInterval)
{
	_debouncer.interval(debounceInterval);
}

BUTTONSUITE::BUTTONSTATUS ButtonBase::update()
{
	// See ButtonEnums.h for the definitions of the different button states.

	// Have the debouncer update.  This does most of the work of handling the button state.
	// The debouncer determines the current state, if the state changed since the last time
	// "update" was called, what the time between state changes was, and so on.
	_debouncer.update();

	// Catch transitions from HIGH to LOW.  This 
	if (_debouncer.fell())
	{
		#ifdef BUTTONSUITEDEBUG
			Serial.println("ButtonBase::update: JUSTPRESSED");
		#endif
		return BUTTONSUITE::JUSTPRESSED;
	}

	// Look to see if the button is currently pressed.
	// The "Bounce.read()" function returns true if the pin is reading high.  In
	// our case, the button is pressed if the pin is low.  So the button is pressed
	// if "read" returns false.
	if (!_debouncer.read())
	{
		if (_debouncer.currentDuration() < _longPressInterval)
		{
			#ifdef BUTTONSUITEDEBUG
				Serial.println("ButtonBase::update: ISSHORTPRESSED");
			#endif
			return BUTTONSUITE::ISSHORTPRESSED;
		}
		else
		{
			#ifdef BUTTONSUITEDEBUG
				Serial.println("ButtonBase::update: ISLONGPRESSED");
			#endif
			return BUTTONSUITE::ISLONGPRESSED;			
		}
	} 

	// Catch transitions from LOW to HIGH.  This is the button release.  If the
	// button is released, we then check to see if the press duration makes is a
	// short or long press.
	if (_debouncer.rose())
	{
		// Button was pushed so remember the last press type.
		if (_debouncer.previousDuration() < _longPressInterval)
		{
			#ifdef BUTTONSUITEDEBUG
				Serial.println("ButtonBase::update: WASSHORTPRESSED");
			#endif
			return BUTTONSUITE::WASSHORTPRESSED;
		}
		else
		{
			#ifdef BUTTONSUITEDEBUG
				Serial.println("ButtonBase::update: WASLONGPRESSED");
			#endif
			return BUTTONSUITE::WASLONGPRESSED;
		}
	}
	
	// Button is still in unpushed state and did not just get released.  In
	// this case, the button is considered idle (nothing happened).
	#ifdef BUTTONSUITEDEBUG
		Serial.println("ButtonBase::update: NOTPRESSED");
	#endif
	return BUTTONSUITE::NOTPRESSED;
}