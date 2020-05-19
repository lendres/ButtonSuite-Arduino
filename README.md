# ButtonSuite

A class for adding functionality to push (momentary) buttons.  Includes debouncing.  This library contains two categories of class, two state buttons and incrementing buttons.

### Two State Buttons
These buttons are either on or off.

#### SimpleButton
Abstract base class that provides interface for a two state button (button that only has an on and off state).  You cannot instantiate (create an instance) of this class.

The purpose of this class is to provide automatic implimentation of different behaviors.  By using different classes derived from SimpleButton, a class can automatically implement momentary, latching, always on, or always off behavior.  This makes it easy to implement different behaviors or even switch behaviors during run time.

#### MomentaryButton
This is standard push (momentary) button.  It returns true when the button is pressed (held down) and false when it is not.

#### LatchingButton
Turns a push button (momentary button) into a toggle button (latching button).  Pressing the button alternates between on (true) and off (false).  This is a virtual latching switch controled by a real momentary button.  The toggle button can be reset to the base (known) state by the user (with a long press) or programmically.

#### AlwaysOnButton
Always returns true (on).

#### AlwaysOffButton
Always returns false (off).

### Incrementing Buttons
These buttons have multiple states.

#### CountingButton
Turns a push button (momentary button) into a counter.  The counter is incremented each time the button is pushed.  The counter continues to increment until it is either reset by the user (with a long press) or reset programically.

#### CycleButton
Turns a push button (momentary button) into a button used to cycle through states (for example, an enum).  Pressing the button causes the value to increment.  Once the maximum value is reached, the value automatically resets to the initial value.  The value can also be reset to the initial value programmically or by the user (with a long press).


## About the Library
### Github Page

https://github.com/lendres/ButtonSuite-Arduino


### Prerequisites

This library requires the following librarys to run:

* [Bounce2](https://github.com/thomasfredericks/Bounce2) - Debouncer for Arduino


### Installing

For information on installing Arduino libaries, see: [Arduino Libraries](http://www.arduino.cc/en/Guide/Libraries)


## Versioning

We use [SemVer](http://semver.org/) for versioning.

## Authors

* **Lance A. Endres** - [lendres](https://github.com/lendres)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
