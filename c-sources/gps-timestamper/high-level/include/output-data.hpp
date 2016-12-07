/*
 * output-data.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_DATA_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_DATA_HPP_

#include "gps-data.hpp"

#include <stdint.h>

struct OutputData
{
	GPSData gps;
	double fractionSeconds;
	uint32_t lastSecondPeriod;
	uint32_t signalDelay;
};


#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_DATA_HPP_ */
