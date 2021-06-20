/*
	Toggles an LED when a button is pressed and released.  The LED is set to
	the current state of the button.  If the button is latched, the LED is on,
	if the button is not latched, the LED is off.  This button uses the "isLatched"
	function to determine the buttons state.

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

#include "LatchingButton.h"

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
	if (button.isLatched())
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}
