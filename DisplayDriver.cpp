#include "DisplayDriver.h"

#define INTENSITY_OK 8

DisplayDriver::DisplayDriver(unsigned int dinPin, unsigned int clockPin, unsigned int loadPin)
	:controller(dinPin, clockPin, loadPin)
{
	// Initialize Display Controller
	controller.shutdown(0, false);
	controller.setScanLimit(0, 4);
	controller.setIntensity(0, INTENSITY_OK);
	controller.clearDisplay(0);
}

DisplayDriver::~DisplayDriver()
{
	controller.clearDisplay(0);
	controller.shutdown(0, true);
}

//TODO  setScanLimit() based on number of digits displayed?
void DisplayDriver::displayValue(unsigned int value)
{
	controller.clearDisplay(0);
	// Manage too large values
	if (value >= 10000)
	{
		for (int i = 0; i < 4; i++)
		{
			controller.setChar(0, i, '-', false);
		}
	}
	else if (value == 0)
	{
		controller.setDigit(0, 0, 0, false);
	}
	else
	{
		byte digits[4];
		for (int i = 0; i < 4; i++)
		{
			digits[i] = (byte) (value % 10);
			value /= 10;
		}
		boolean hasNonNullDigit = false;
		for (int i = 3; i >= 0; i--)
		{
			if (digits[i] != 0 || hasNonNullDigit)
			{
				hasNonNullDigit = true;
				controller.setDigit(0, i, digits[i], false);
			}
		}
	}
}

void DisplayDriver::displayValue(float value)
{
	//TODO
}
