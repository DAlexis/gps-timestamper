/*
 * timestamp-queue.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_

#include "output-messages.hpp"
#include "time-location-types.hpp"
#include "nmea-receiver.hpp"
#include "nmea-parser.hpp"
#include "precision-timer.hpp"
#include "os-wrappers.hpp"
#include "time-location-manager.hpp"


class TimestampCollector
{
public:
	TimestampCollector(
			const TimeLocationManager& tlm,
			PrecisionTimer* precisionTimer,
			IOutputMessagesReceiver& outputReceiver
	);

	void run();

private:
    void IRQSignalCaptureCallback(bool hasTiming, uint32_t oneSecPeriod, uint32_t signalDelay);

	const TimeLocationManager& m_tlm;
	PrecisionTimer* m_precisionTimer;
	IOutputMessagesReceiver& m_outputReceiver;
};


class OutputRegisteredImpulse : public IOutputMessage
{
public:
    OutputRegisteredImpulse(
            bool hasTiming,
            const Position& pos,
            const DateTime& dt,
            uint32_t lastSecondPeriod,
            uint32_t signalDelay);
    std::string str() const override;

private:
    const Position m_pos;
    const DateTime m_dt;
    bool m_hasTiming;
    uint32_t m_lastSecondPeriod;
    uint32_t m_signalDelay;
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_ */
