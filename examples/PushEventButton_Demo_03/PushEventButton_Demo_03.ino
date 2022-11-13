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
// Because the "CAPTUREBOTH" option is used, both the down push
// and the release are captured and used to flash the LED.
PushEventButton button(buttonPin, PushEventButton::CAPTUREBOTH);

void setup()
{
	Serial.begin(9600);
	Serial.println("*** Push Event Button Counter Demo 03 ***");

	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// This will return true once for the button push and once for the button release.
	// This example is triggered on the transition of the button.  The LED will flash briefly on the button
	// push and briefly on the button release.  It is recommended to hold the button down momentarily in order
	// to be able to distinquish between the push and the release events.
	bool buttonPushed = button.pushed();

	// Set the LED to the state of the button press.
	digitalWrite(ledPin, buttonPushed);

	if (buttonPushed)
	{
		// We need a brief delay to make sure the LED is on long enough to be seen.
		delay(100);
	}
}
