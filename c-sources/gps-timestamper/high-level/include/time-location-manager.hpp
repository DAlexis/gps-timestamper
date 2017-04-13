/*
 * time-location-manager.hpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_MANAGER_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_MANAGER_HPP_

#include <time-location-types.hpp>
#include "precision-timer.hpp"
#include "nmea-receiver.hpp"
#include "nmea-parser.hpp"
#include "os-wrappers.hpp"
#include "output-messages.hpp"

/**
 * This class always know curent round time and GPS location,
 * if avaliable
 */
class TimeLocationManager
{
public:
	TimeLocationManager(NMEAReceiver& nmea, PrecisionTimer& precTimer, IOutputMessagesReceiver& outputReceiver);

	void run();

	const DateTime& dt() const;
	const Position& pos() const;

private:
	void nmeaMonitoringLoop();
	void IRQPPS();

	bool m_wasPPS = false;

	DateTime m_dt;
	Position m_pos;

	NMEAReceiver& m_nmea;
	IOutputMessagesReceiver& m_outputReceiver;
	TaskOnce m_nmeaMonitoringTask;
};







#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_MANAGER_HPP_ */
