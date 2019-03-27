/*
 * timestamp-collector.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "timestamp-collector.hpp"
#include "string-utils.hpp"

#include <sstream>

TimestampCollector::TimestampCollector(
		const TimeLocationManager& tlm,
		PrecisionTimer* precisionTimer,
		IOutputMessagesReceiver& outputReceiver
) :
	m_tlm(tlm), m_precisionTimer(precisionTimer), m_outputReceiver(outputReceiver)
{
	m_precisionTimer->setCaptureCallback(
        [this] (bool hasTiming, uint32_t oneSecPeriod, uint32_t signalDelay) {
            IRQSignalCaptureCallback(hasTiming, oneSecPeriod, signalDelay);
		}
	);
}

void TimestampCollector::IRQSignalCaptureCallback(bool hasTiming, uint32_t oneSecPeriod, uint32_t signalDelay)
{
	OutputRegisteredImpulse* msg = new OutputRegisteredImpulse(
        hasTiming,
		m_tlm.pos(),
		m_tlm.dt(),
		oneSecPeriod,
		signalDelay
	);

	m_outputReceiver.receiveFromISR(msg);
}

void TimestampCollector::run()
{
}

OutputRegisteredImpulse::OutputRegisteredImpulse(
    bool hasTiming,
    const Position& pos,
    const DateTime& dt,
    uint32_t lastSecondPeriod,
    uint32_t signalDelay
) :
    m_pos(pos),
    m_dt(dt),
    m_hasTiming(hasTiming),
    m_lastSecondPeriod(lastSecondPeriod),
    m_signalDelay(signalDelay)
{

}

std::string OutputRegisteredImpulse::str() const
{
    std::ostringstream oss;
    oss << "{event: \"pulse\", "
            << "pos: " << m_pos.str()
            << ", has_timing: " << toString(m_hasTiming)
            << ", time_round: " << m_dt.str()
            << ", time_frac: " << toString(double(m_signalDelay) / m_lastSecondPeriod)
            << ", last_second: " << m_lastSecondPeriod
            << "}";
    return oss.str();
}
