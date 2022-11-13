/*
	This example demonstrates how the PushEventButton captures each individual
	button press as discrete events.  It does not matter how long the button is
	pressed down or released.  Only the transition between pressed and released
	is captured.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "PushEventButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The button will automatically configure the button pin.
// Because the "CAPTURERELASE" option is used, the event is only triggered after
// the button is released.
PushEventButton button(buttonPin, PushEventButton::CAPTURERELEASE);

void setup()
{
	Serial.begin(9600);
	Serial.println("*** Push Event Button Counter Demo 01 ***");
	
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// This will return true only once for each button push.
	// This example is triggered on the release of the button.  If you push the button down
	// and hold it, nothing happens.  Only after releasing the button does this return true.
	bool buttonPushed = button.pushed();

	// Set the LED to the state of the button press.
	digitalWrite(ledPin, buttonPushed);

	if (buttonPushed)
	{
		// We need a brief delay to make sure the LED is on long enough to be seen.
		delay(100);
	}
}
