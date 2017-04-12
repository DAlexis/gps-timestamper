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
#include "timestamp-collector.hpp"
#include "output-maker.hpp"
#include "time-location-manager.hpp"

class GPSTimestamper
{
public:
	void run();

	SINGLETON_IN_CLASS(GPSTimestamper)

private:
	GPSTimestamper();
	NMEAReceiver m_nmea;
	PrecisionTimer m_precTimer;
	OutputMaker m_outputMaker;

	TimeLocationManager m_timeLocMgr{m_nmea, m_precTimer};
	TimestampCollector m_collector{m_timeLocMgr, &m_precTimer, m_outputMaker};
};

#endif /* HIGH_LEVEL_INCLUDE_GPS_TIMESTAMPER_HPP_ */
