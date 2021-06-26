/*
	Turns an LED on when the button is pressed and off when the button is released.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "MomentaryButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The button will automatically configure the button pin.
MomentaryButton button(buttonPin);

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Hold the button down to turn the LED on and release it to turn it off.
	if (button.pushed())
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}