# ButtonSuite

A library for adding functionality to push (momentary) buttons.  This library allows a simple momentary push button to be used as a momentary button, latching button, counter, or enumerator.  This library uses the Bounce2 library to add debouncing functionality.

## Types of Buttons
This library contains two categories of button types.  The first category is two state buttons; these are either on or off.  The second category provides incrementing buttons that can perform different types of counting.  These two categories of buttons are described here.  See "Software Design" below for information about how the source code implements these behaviors.

### Two State Buttons
These buttons are either on or off.

#### MomentaryButton
This is standard push (momentary) button.  It returns true when the button is pressed (held down) and false when it is not.

#### LatchingButton
Turns a push button (momentary button) into a toggle button (latching button).  Pressing the button alternates between on (true) and off (false).  This is a virtual latching switch controled by a real momentary button.  The toggle button can be reset to the base (known) state by the user (with a long press) or programmically.

#### AlwaysOnButton
Always returns true (on).  Useful if you want to temporarily disable user input.

#### AlwaysOffButton
Always returns false (off).  Useful if you want to temporarily disable user input.

### Incrementing Buttons
These buttons provide different types of counting behavior.

#### CountingButton
Turns a push button (momentary button) into a counter.  The counter is incremented each time the button is pushed.  The counter continues to increment until it is either reset by the user (with a long press) or reset programically.

#### CycleButton
Turns a push button (momentary button) into a button used to cycle through states (for example, an enum).  Pressing the button causes the value to increment.  Once the maximum value is reached, the value automatically resets to the initial value.  The value can also be reset to the initial value programmically or by the user (with a long press).

## Software Design
Some abstract base classes provided common functionality and interface design.  These cannot be instantiated.

#### ButtonBase
Abstract class that is the base class for every other class and implements common behavior.  If you want to understand the software, you should start here.

#### SimpleButton
Abstract base class that provides interface for a two state button (button that only has an on and off state).  You cannot instantiate (create an instance) of this class.

The purpose of this class is to allow software to switch behaviors during run time.  This also makes software development easier by not locking the developer into a specific button type.  By using different classes derived from SimpleButton, software can implement momentary, latching, always on, or always off behavior simply by instantiating the required derived class.

#### ResetableButton
Abstract class for button classes that use a long press to indicate they should reset themselves to some initial/base value.  Exposes the interface for setting the enable/disable of the long press and the duration of the interval.


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
