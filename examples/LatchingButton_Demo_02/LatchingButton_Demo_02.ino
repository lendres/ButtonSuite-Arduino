/*
	Toggles an LED on when the button is held down and off when the button
	is released.

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
	Serial.begin(9600);
	Serial.println("*** Latching Button Demo 02 ***");

	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Press the button once to turn it on, and again to turn it off.
	bool buttonState = button.getState();
	
	Serial.print("Button state: ");
	Serial.println(buttonState);
	
	if (buttonState)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}