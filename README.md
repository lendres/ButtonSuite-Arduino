# ButtonSuite

A library for using a simple mechanical push (momentary) button as a momentary button, a latching button, a counter, an enumerator, and more.  The library allows a mechanical momentary button to be used as a virtual button with different functionality.  The library implements the behavior of a momentary button, a latching button, a counter, an enumerator, and more.  It also makes it very easy to develop buttons with your own custom behavior.  The Bounce2 library is used to add debouncing functionality.

Note that because some input devices like optical sensors or limit switches are functionally equivilent to tactile buttons, they can also be used with this library.

## Types of Buttons
This library contains two categories of button types.  The first category is two state buttons; these are either on or off.  The second category provides incrementing buttons that can perform different types of counting.  These two categories of buttons are described here.  See "Software Design" below for information about how the source code implements these behaviors.

### Two State Buttons
These are binary state buttons and can only be on or off.

#### MomentaryButton
This is standard push (momentary) button.  It returns true when the button is pressed (held down) and false when it is not.

#### LatchingButton
Turns a push button (momentary button) into a toggle button (latching button).  Pressing the button alternates between on (true) and off (false).  This is a virtual latching switch controled by a mechanical momentary button.

#### PushEventButton
This button class captures each individual button press as discrete events.  It does not matter how long the button is pressed down or released.  Only the transition between pressed and released is captured.  It can capture either the press event or the release event.

#### AlwaysOnButton
Always returns that the button is on.  Useful if you want to temporarily disable user input.

#### AlwaysOffButton
Always returns that the button is off.  Useful if you want to temporarily disable user input.

### Incrementing Buttons
These buttons provide different types of counting behavior.

#### CountingButton
Turns a push button (momentary button) into a counter.  The counter is incremented each time the button is pushed.  The counter continues to increment until it is reset either by the user (with a long press) or programically.

#### CycleButton
Turns a push button (momentary button) into a button used to cycle through states (for example, an enumeration).  Pressing the button causes the value to increment.  Once the maximum value is reached, the value automatically resets to the initial value.  The value can also be reset to the initial value programmically or by the user (with a long press).


## Software Design
Visit the Wiki to learn how the software is designed.


## About the Library
### Github Page
https://github.com/lendres/ButtonSuite-Arduino

### Version 2
The purpose of Version 2 was to greatly simplify the interface as well as the internal structure of the software.  Some of the more esoteric functionality was removed and some functionality was separated into different classes.  This meant backwards compatibility could not be maintained, however, the benefit is a much cleaner and easier to understand library.

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