/*
 * timestamp-collector.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "timestamp-collector.hpp"

TimestampCollector::TimestampCollector(
		const TimeLocationManager& tlm,
		PrecisionTimer* precisionTimer,
		IOutputMessagesReceiver& outputReceiver
) :
	m_tlm(tlm), m_precisionTimer(precisionTimer), m_outputReceiver(outputReceiver)
{
	m_precisionTimer->setCaptureCallback(
		[this] (double time, uint32_t oneSecPeriod, uint32_t signalDelay) {
			IRQSignalCaptureCallback(time, oneSecPeriod, signalDelay);
		}
	);
}

void TimestampCollector::IRQSignalCaptureCallback(double time, uint32_t oneSecPeriod, uint32_t signalDelay)
{
	UNUSED(time);
	OutputRegisteredImpulse* msg = new OutputRegisteredImpulse(
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
