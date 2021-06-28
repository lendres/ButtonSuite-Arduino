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
	This file contains enumerations used by the ButtonSuite.
*/

#ifndef BUTTONENUMS_H
#define BUTTONENUMS_H

namespace BUTTONSUITE
{
	// Button status.
	enum BUTTONSTATUS
	{
		// Was just pressed down (first call to "update" after the button was pressed).
		JUSTPRESSED				=   1,
		
		// The button is being pressed and has been held lown shorter than the long press duration.
		ISSHORTPRESSED			=   2,

		// The button was just released and the duration held down was considered short (less than long press duration).
		WASSHORTPRESSED			=   4,

		// The button is being pressed and has been held down longer than the long press duration.
		ISLONGPRESSED			=   8,

		// The button was just released and the duration held down was considered long (more than long press duration).
		WASLONGPRESSED			=  16,

		// Button is not pressed/on.
		NOTPRESSED				=  32
	};
}

#endif