/*
 * Sample sketch that displays distances calculated by an ultrasound sensor
 * (HC-SR04) onto a 4 digits 7 segments LED display, driven by a MAX7219.
 *
 * In order to prepare the Arduino circuit, you need to:
 * 1. Connect Arduino pins 2,3&4 to 3 pins (DIN, CLK, LOAD) of the display driver.
 * 2. Connect the Display Driver GND and V+ pins to those of Arduino
 * 3. Connect Arduino pins 8&9 to the TRIGGER & ECHO pins of the HC-SR04
 * 4. Connect the HC-SR04 GND and V+ pins to those of Arduino
 * 5. Plug the Arduino to a power supply
 *
 * This sketch was created with eclipse and the arduino plugin:
 * 	http://www.baeyens.it/eclipse/
 *
 * That means it cannot be used directly with the Arduino IDE (no .ino sketch).
 * If you want to use it with Arduino IDE, then you must:
 *
 * 1. change UltraSoundDistanceDetector.cpp (this file) into UltraSoundDistanceDetector.ino
 * 2. remove the line #include "UltraSoundDistanceDetector.h" below
 */

// Do not remove the include below
#include "UltraSoundDistanceDetector.h"

#include "DisplayDriver.h"
#include "UltraSonicSensor.h"

// Arduino pins connected to the display driver
#define MUX_DISP_DIN 4
#define MUX_DISP_CLK 3
#define MUX_DISP_LOAD 2

// Arduino pins connected to the HC-SR04
#define ECHO 9
#define TRIGGER 8

// Wait time in milliseconds between 2 distance reads
#define LOOP_DELAY_MS 200

// Controller for the display driver (must be declared global)
DisplayDriver display(MUX_DISP_DIN, MUX_DISP_CLK, MUX_DISP_LOAD);
// Controller for the HC-SR04 (must be declared global)
UltraSonicSensor sensor(TRIGGER, ECHO);

// The setup function is called once at startup of the sketch
void setup()
{
	// Nothing to do here: all initialization has already been performed when
	// instantiating DisplayDriver and UltraSonicSensor.
}


// The loop function is called in an endless loop
void loop()
{
	// We update the display only if there is a value change between 2 reads
	// Hence we keep the last distance read from the sensor
	static unsigned int last_dist = 0;
	// Read and calculate distance from sensor
	unsigned int dist = sensor.getDistanceInCm();
	if (last_dist != dist) {
		last_dist = dist;
		display.displayValue(dist);
	}
	// Wait for a few milliseconds
	delay(LOOP_DELAY_MS);
}
