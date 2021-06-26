/*
	Demonstrates how to switch behavior of a button at run time.  This example uses
	two alternating time frames.  During the first, the button will turn the LED on
	and off.  During the second, the LED will remain on and the button will have no
	effect.  The two modes are toggled back and forth every few seconds.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "MomentaryButton.h"
#include "AlwaysOnButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// We will access the button through a pointer.  That way we can change the button
// behavior by changing what type of button is being pointed to.
TwoStateButton	*button;

// The button will automatically configure the button pin.
MomentaryButton momentaryButton(buttonPin);

// Always on button.
AlwaysOnButton	onButton;

// Used for timing and switching between the two states.
unsigned long	intervalStartTime;
const int		intervalLength			= 5000;
int				currentState;

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);

	// Set our initial state as using the momentary button.
	button			= &momentaryButton;
	currentState	= 0;

	// Capture the start time to be used to calculate the time ellapsed.
	intervalStartTime = millis();

	// Allow printing to the serial monitor.  Provides additional information and debugging.
	Serial.begin(9600);
	Serial.println("Serial monitor initialized.");
}

void loop()
{
	if (millis() - intervalStartTime > intervalLength)
	{
		// Toggle between the two states.  In state 0, the button can turn the LED
		// on or off.  In state 1, the LED is always on.
		if (currentState == 0)
		{
			// We're in state 0, so switch to state 1.
			button 			= &onButton;
			currentState	= 1;
			Serial.println("Current state: ALWAYS ON");
		}
		else
		{
			// We're in state 1, so switch to state 0.
			button			= &momentaryButton;
			currentState	= 0;
			Serial.println("Current state: ACTIVATED BY BUTTON");
		}

		// Reset the start time.
		intervalStartTime = millis();
	}

	// If the button is pressed, turn the LED light on.  In state 0 (responding to the button),
	// the actual state of the button is returned.  In state 1, on (true), is always returned.
	if (button->pushed())
	{
		// Turns on LED.
		digitalWrite(ledPin, HIGH);

	}
	else
	{
		// Turns off LED.
		digitalWrite(ledPin, LOW);
	}
}