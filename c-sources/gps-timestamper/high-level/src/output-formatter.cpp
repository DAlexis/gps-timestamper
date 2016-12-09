/*
 * output-formatter.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "output-formatter.hpp"
#include "stdio.h"
#include "string-utils.h"

void OutputFormatter::parse(const OutputData& data)
{
	double2str(m_bufferForDouble, data.fractionSeconds, 9, bufferForDoubleSize);
	sprintf(m_result,
			"{lat: %s, lon: %s, time_round: %s, time_fractional: %s}",
			data.gps.lat,
			data.gps.lon,
			data.gps.time,
			m_bufferForDouble);
}

const char* OutputFormatter::result() const
{
	return m_result;
}
