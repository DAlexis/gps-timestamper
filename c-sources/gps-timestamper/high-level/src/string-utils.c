/*
 * string-utils.c
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#include "string-utils.h"
#include <stdint.h>

int double2str(char* buffer, double value, unsigned int precision, unsigned int maxBufferLen)
{

	char negative = 0;
	if (value < 0)
	{
		value = -value;
		negative = 1;
	}

	if (precision + 1 + negative > maxBufferLen - 1)
	{
		buffer[0] = '\0';
		return 2;
	}

	char roundInversed[20];
	char fractional[20];
	int roundCount = 0;
	uint32_t roundPart = (uint32_t) value;
	double fractionPart = value - roundPart;
	for (; roundPart != 0; roundCount++)
	{
		roundInversed[roundCount] = roundPart % 10 + '0';
		roundPart /= 10;
	}

	if (roundCount > maxBufferLen-1)
	{
		buffer[0] = '#'; buffer[1] = '\0';
		return 1;
	}

	int fracCount = 0;
	for (; (fracCount + 1 + roundCount + negative) < maxBufferLen-1 && fracCount < precision; fracCount++)
	{
		fractionPart *= 10;
		uint8_t digit = fractionPart;
		fractional[fracCount] = digit + '0';
		fractionPart -= digit;
	}

	if (negative)
		buffer[0] = '-';

	for (int i=0; i<roundCount; i++)
	{
		buffer[i+negative] = roundInversed[roundCount-i-1];
	}

	buffer[roundCount+negative] = '.';
	for (int i=0; i<fracCount; i++)
	{
		buffer[roundCount+1+i+negative] = fractional[i];
	}
	buffer[roundCount+1+fracCount+negative] = '\0';
	return 0;

}
