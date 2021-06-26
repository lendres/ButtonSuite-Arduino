/*
	Toggles an LED when a button is pressed and released.  The LED is set to
	the current state of the button.  If the button is latched, the LED is on,
	if the button is not latched, the LED is off.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "LatchingButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The button will automatically configure the button pin.
LatchingButton button(buttonPin);

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Press the button once to turn it on, and again to turn it off.  Here, the "pushed" function
	// returns the internal latched state of the button.  It does not return whether the button is
	// physically being pressed or not.
	if (button.pushed())
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}