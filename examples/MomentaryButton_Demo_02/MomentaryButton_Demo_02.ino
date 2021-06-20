/*
	Toggles an LED between on and off each time the button is pressed and released.
	This example demonstrates the "wasPressed" function.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

/*
	Please note the difference between the examples MomentaryButton_Demo_02 and 
	LatchingButton_Demo_01.  Both examples toggle an LED on and off but one uses
	a MomentaryButton and one uses the LatchingButton.  While the behavior is the
	same for these simple examples, there is an important difference.  In the case
	of the MomentaryButton, the state of the LED (on or off) is not known.  For the
	LatchingButton, it is known what state the button (and therefore LED) is in.
*/

#include "MomentaryButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The MomentaryButton will automatically configure the button pin.
MomentaryButton button(buttonPin);

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Press the button once to turn the LED on and again it to turn it off.  This only captures button release
	// events, i.e., nothing happens when the button is pressed down, only after the release.
	if (button.wasPressed())
	{
		// The button was pressed, so toggle the LED state.  To toggle it, the current value is read (digitalRead)
		// and negated.  The result is written back to the pin to change its state.
		digitalWrite(ledPin, !digitalRead(ledPin));
	}
}
