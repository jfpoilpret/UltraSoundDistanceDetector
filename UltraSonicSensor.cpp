// - improve distance sensor class to make it interrupt-based:
//    - send the trigger signal
//    - get an interrupt handler called when echo received
//	- according to specsheet, time between trigger and echo start is sound duration

#include "UltraSonicSensor.h"

#include "Arduino.h"

#define TRIGGER_PULSE_MS 10
#define SOUND_SPEED_M_S 343L

#define cm_to_us(cm) ((unsigned long) cm * 100L * 100L * 2L / SOUND_SPEED_M_S)
#define us_to_cm(us) ((unsigned int)(us * SOUND_SPEED_M_S / (100L * 2L * 100L)))

UltraSonicSensor::UltraSonicSensor(unsigned int triggerPin, unsigned int echoPin, unsigned int maxDistance)
	:_triggerPin(triggerPin), _echoPin(echoPin), _maxPulseDuration(cm_to_us(maxDistance))
{
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

unsigned long UltraSonicSensor::getEchoTimeInUs()
{
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(TRIGGER_PULSE_MS);
	digitalWrite(_triggerPin, LOW);
	return pulseIn(_echoPin, HIGH, _maxPulseDuration);
}

unsigned int UltraSonicSensor::getDistanceInCm()
{
	return us_to_cm(getEchoTimeInUs());
}
