# ButtonSuite

A class for adding functionality to momentary buttons.  Includes debouncing.  This library includes the following types of buttons:

PushButton - This is standard momentary button.  It returns true when the button is pressed and false when it is not.

ToggleButton -  Turns a push button (momentary button) into a toggle button (latching button).  Pressing the button alternates between on true) and off (false).  If the button is pushed once to turn in on (true) it will continue to return on (true) until the button is pushed again.

PushButtonCounter - Turns a push button (momentary button) into a counter.  The counter is incremented each time the button is pushed.  The counter continues to increment until it is reset.

CycleButton - Turns a push button (momentary button) into a button used to cycle through states.  Pressing the button causes the value to increment.  Once the maximum value is reached, the value automatically resets to the initial value.


## Github Page

https://github.com/lendres/ButtonSuite-Arduino


### Prerequisites

This library requires the following librarys to run:

```
Bounce2
```

* [Bounce2](https://github.com/thomasfredericks/Bounce2) - Debouncer for Arduino


### Installing

For information on installing Arduino libaries, see:

```
http://www.arduino.cc/en/Guide/Libraries
```

## Versioning

We use [SemVer](http://semver.org/) for versioning.

## Authors

* **Lance A. Endres** - [lendres](https://github.com/lendres)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details