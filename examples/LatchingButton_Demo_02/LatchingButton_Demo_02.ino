/*
	Toggles an LED when a button is pressed and released.  The LED is set to
	the current state of the button.  If the button is latched, the LED is on,
	if the button is not latched, the LED is off.  This example uses the "getStatus"
	function to determine the current state of the button.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "LatchingButton.h"

// Uncomment for additional debugging messages from the library.
//#define BUTTONDEBUG

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The LatchingButton will automatically configure the button pin.
LatchingButton button(buttonPin);

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Press the button once to turn it on, and again to turn it off.
	if (button.getStatus() == ISPRESSED)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}