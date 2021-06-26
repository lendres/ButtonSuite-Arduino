/*
	Displays the current value of the CycleButton to the serial monitor.  When
	the value is greater than a set value, an LED is turned on.

	The value is incremented each time the button is pushed.  If the value is
	higher than the maximum value, it resets to the minimum value.  Holding
	the button down longer than the long press time will also reset the counter.

	The button should be wired such that when pressed, the "buttonPin" is
	connected to ground.

	The LED should be wired with the "ledPin" to the positive lead and the
	negative lead should be connected to ground.  A current limiting resistor
	should be used.
*/

#include "CycleButton.h"

// Uncomment for additional debugging messages from the library.
//#define BUTTONDEBUG

// Change these if your button or LED are on other pins.
int buttonPin   = 8;
int ledPin      = 9;

// The button will automatically configure the button pin.
// The second number is the maximum value of the counter.
CycleButton button(buttonPin, 6);

void setup()
{
	Serial.begin(9600);
	Serial.println("*** Cycle Button Demo 01 ***");

	// Setup the output LED.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	// During each loop, the number of times the button is pressed is retrieved
	// from the button.
	int value = button.getValue();

	Serial.print("Cycle button value: ");
	Serial.println(value);
  
	// If the count is above a specified value, turn the LED on, otherwise turn
	// if off.  Once the button's max value is reached, it will reset to the first
	// value and the LED is turned off.  The button can also be manually reset.
	if (value > 2)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}