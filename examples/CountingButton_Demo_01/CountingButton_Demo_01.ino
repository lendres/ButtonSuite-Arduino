/*
	This example counts and displays the number of times a button is pressed.
	Once the specified count is reached, an LED is turned on.  A long press
	will reset the counter and turn the LED off.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "CountingButton.h"

// Uncomment for additional debugging messages from the library.
//#define BUTTONDEBUG

// Change these if your button or LED are on other pins.
int buttonPin   = 8;
int ledPin      = 9;

// The button will automatically configure the button pin.
CountingButton button(buttonPin);

void setup()
{
	Serial.begin(9600);
	Serial.println("*** Counting Button Counter Demo 01 ***");

	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// During each loop, the number of times the button is pressed is retrieved
	// from the button.
	int count = button.getCount();
	
	// Display the button count on the serial monitor.
	Serial.print("Button press count: ");
	Serial.println(count);
	
	// If the count is above a specified value, turn the LED on, otherwise turn
	// if off.  If the button is reset with a long press, the counter is reset
	// and the LED is turned off.
	if (count > 4)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}