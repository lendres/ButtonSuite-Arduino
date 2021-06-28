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

#include "PushEventButton.h"

// Constructors.
PushEventButton::PushEventButton(int pin) :
	TwoStateButton(pin),
	_captureType(CAPTURERELEASE)
{
}
PushEventButton::PushEventButton(int pin, CAPTURETYPE captureType) :
	TwoStateButton(pin),
	_captureType(captureType)
{
}

PushEventButton::PushEventButton(int pin, int debounceInterval) :
	TwoStateButton(pin, debounceInterval),
	_captureType(CAPTURERELEASE)
{
}

// Destructor.
PushEventButton::~PushEventButton()
{
}

void PushEventButton::setCaptureType(CAPTURETYPE captureType)
{
	_captureType = captureType;
}

bool PushEventButton::pushed()
{
	BUTTONSUITE::BUTTONSTATUS status = update();

	switch (_captureType)
	{
		case CAPTUREPUSH:
		{
			if (status & BUTTONSUITE::JUSTPRESSED)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		case CAPTURERELEASE:
		{
			if (status & (BUTTONSUITE::WASSHORTPRESSED | BUTTONSUITE::WASLONGPRESSED))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		case CAPTUREBOTH:
		{
			if (status & (BUTTONSUITE::JUSTPRESSED | BUTTONSUITE::WASSHORTPRESSED | BUTTONSUITE::WASLONGPRESSED))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		default:
		{
			return false;
		}
	}
}