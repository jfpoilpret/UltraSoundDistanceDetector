/*
 *    DisplayDriver.h - A library for controlling a Display Driver
 *    circuit, made of 4 7-segments LED digits and based on MAX7219.
 *    Diagram and circuit can be found here (TODO).
 *
 *    Copyright (c) 2013 Jean-François Poilprêt
 *
 *    This library is based on LedControl library by Eberhard Fahle
 *    http://playground.arduino.cc/uploads/Main/LedControl.zip
 *
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 *
 *    This permission notice shall be included in all copies or
 *    substantial portions of the Software.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DisplayDriver_h
#define DisplayDriver_h

#include <LedControl.h>

/*
 * Each instance of this class can handle one display driver circuit,
 * connected to Arduino by 3 pins.
 * It should be instantiated at setup() time (or as a global variable).
 *
 * Once created, it allows sending information for display from your sketch.
 */
class DisplayDriver
{
private:
	LedControl controller;

public:
	/*
	 * Create a new controller to a DisplayDriver that must be connected to
	 * the Arduino on 3 pins.
	 * It initializes the display by clearing it first.
	 *
	 * Params:
	 * dataPin		pin on the Arduino where data gets shifted out
	 * clockPin		pin for the clock durign data transmission
	 * loadPin		pin for selecting the device for data transmission
	 */
	DisplayDriver(unsigned int dinPin, unsigned int clockPin, unsigned int loadPin);

	/*
	 * Finalize this DisplayDriver controller by putting the circuit into
	 * shutdown mode.
	 */
	~DisplayDriver();

	/*
	 * Display the given value to the display circuit.
	 * The value must be less than 10,000 (as the circuit only has 4 digits).
	 *
	 * Params:
	 * value		value to be displayed
	 */
	void displayValue(unsigned int value);

	/*
	 * Display the given value to the display circuit, along with as many
	 * decimals as possible, based on 4 digits limitation.
	 * NOT YET IMPLEMENTED.
	 */
	void displayValue(float value);
};

#endif // DisplayDriver_h
