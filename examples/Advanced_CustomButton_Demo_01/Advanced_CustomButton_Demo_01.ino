/*
	Turns an LED on when the button is pressed and off when the button is released.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "CustomButton.h"

// Change these if your button or LED are on other pins.
int buttonPin	= 8;
int ledPin		= 9;

// The button will automatically configure the button pin.
CustomButton button(buttonPin);

// Used for timing.
unsigned long	intervalStartTime;
const int		fastBlinkInterval			= 100;
bool			timing;

void setup()
{
	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// Hold the button down to turn the LED on and release it to turn it off.
	switch (button.getBehavior())
	{
		case CustomButton::LIGHTOFF:
		{
			// Turn off the light and make sure timing is turned off.
			digitalWrite(ledPin, LOW);
			timing = false;
			break;
		}

		case CustomButton::BLINKONCE:
		{
			// Turn on the light for 1 second.  We won't bother with timing for this.
			digitalWrite(ledPin, HIGH);
			delay(1000);
			break;
		}

		case CustomButton::FASTBLINK:
		{
			// If we are not timing, then we start it.  That is, we have determine the button is being
			// held down and this is the first pass through the loop since the long press was activated.
			//
			// If we are already timing, we need to alternate the status of the light everytime the
			// timing interval is up.
			if (!timing)
			{
				// Turn on the light and start the timing.
				digitalWrite(ledPin, HIGH);
				intervalStartTime		= millis();
				timing					= true;
			}
			else
			{
				// Check if the timing interval is up.
				if (millis() - intervalStartTime > fastBlinkInterval)
				{
					// Swap the state of the LED light.  If it's off, turn it on and vice versa.
					// This is done by reading the current status of the pin, negating it and
					// passing it to the write function.
					digitalWrite(ledPin, !digitalRead(ledPin));

					// Restart the timing.
					intervalStartTime = millis();
				}
			}
			break;
		}
	}
}