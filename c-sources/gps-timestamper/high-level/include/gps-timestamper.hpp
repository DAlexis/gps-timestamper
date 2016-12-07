/*
 * gps-timestamper.hpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef HIGH_LEVEL_INCLUDE_GPS_TIMESTAMPER_HPP_
#define HIGH_LEVEL_INCLUDE_GPS_TIMESTAMPER_HPP_

#include "macro.hpp"
#include "nmea-receiver.hpp"
#include "precision-timer.hpp"

class GPSTimestamper
{
public:
	void run();

	SINGLETON_IN_CLASS(GPSTimestamper)

private:
	GPSTimestamper();
	NMEAReceiver m_nmea;
	PrecisionTimer m_precTimer;
};

#endif /* HIGH_LEVEL_INCLUDE_GPS_TIMESTAMPER_HPP_ */
