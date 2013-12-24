/*
 *    UltraSonicSensor.h - A library for measuring distance through
 *    an ultrasonic module type HC-SR04 (other sensors may work
 *    but have not been tested).
 *
 *    Copyright (c) 2013 Jean-François Poilprêt
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

#ifndef UltraSonicSensor_h
#define UltraSonicSensor_h

#define DEFAULT_MAX_DISTANCE_CM 400

/*
 * Each instance of this class can handle one sensor, connected to Arduino
 * through 2 pins.
 */
class UltraSonicSensor
{
public:
	/*
	 * Create a sensor controller for one HC-SR04 connected to Arduino.
	 * This can then be used any time to get sensor distance.
	 *
	 * Params:
	 * triggerPin		pin on the arduino that will trigger an ultrasound
	 * 					wave on the sensor
	 * echoPin			pin on the arduino that will receive the ultrasound
	 * 					echo from the sensor
	 * maxDistance		the maximum distance, in centimeters, that should be
	 * 					detected by the sensor; this allows shorter calls to
	 * 					get a distance.
	 * 					If not provided, it defaults to 400 cm.
	 */
	UltraSonicSensor(
			unsigned int triggerPin,
			unsigned int echoPin,
			unsigned int maxDistance = DEFAULT_MAX_DISTANCE_CM);

	/*
	 * Let the sensor send an ultrasound wave and wait until the echo is
	 * received, then returns the duration of the echo in microseconds.
	 * The returned duration is for the complete roundtrip of the wave,
	 * hence it must be divided by 2 to compute a distance to an obstacle.
	 */
	unsigned long getEchoTimeInUs();

	/*
	 * Let the sensor send an ultrasound wave and wait until the echo is
	 * received, then returns the distance to an obstacle in centimeters,
	 * based on the duration of the echo.
	 * If no obstacle is found within the maximum distance, 0 will be returned.
	 */
	unsigned int getDistanceInCm();

private:
	const unsigned int _triggerPin;
	const unsigned int _echoPin;
	const unsigned long _maxPulseDuration;
};

#endif // UltraSonicSensor_h
