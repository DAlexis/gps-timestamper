/*
 * timestamp-collector.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "timestamp-collector.hpp"

TimestampCollector::TimestampCollector(NMEAReceiver* nmea, PrecisionTimer* precisionTimer) :
	m_nmea(nmea), m_precisionTimer(precisionTimer)
{
	m_precisionTimer->setCaptureCallback(
		[this] (double time, uint32_t oneSecPeriod, uint32_t signalDelay) {
			IRQSignalCaptureCallback(time, oneSecPeriod, signalDelay);
		}
	);
	m_precisionTimer->setPPSCaptureCallback(
		[this] () {
			IRQPpsCaptureCallback();
		}
	);
}

void TimestampCollector::setDataReadyCallback(DataReadyCallback callback)
{
	m_dataReadyCallback = callback;
}


void TimestampCollector::IRQSignalCaptureCallback(double time, uint32_t oneSecPeriod, uint32_t signalDelay)
{
	// We should check
	OutputData data;
	data.gps = m_actualGPSData;
	data.fractionSeconds = time;
	data.lastSecondPeriod = oneSecPeriod;
	data.signalDelay = signalDelay;
	m_queue.pushBackFromISR(data);
}

void TimestampCollector::IRQPpsCaptureCallback()
{
	m_actualGPSData = m_lastGPSData;
}

void TimestampCollector::run()
{
	m_nmeaMonitoringTask.setStackSize(512);
	m_nmeaMonitoringTask.setTask([this](){ nmeaMonitoringLoop(); });
	m_nmeaMonitoringTask.run();

	m_queueMonitoringTask.setStackSize(512);
	m_queueMonitoringTask.setTask([this](){ queueMonitorLoop(); });
	m_queueMonitoringTask.run();
}

void TimestampCollector::nmeaMonitoringLoop()
{
	for (;;)
	{
		if (m_nmea->updatedString())
		{
			m_nmeaParser.parse(m_nmea->getCurrentGPSString());
			if (m_nmeaParser.result())
			{
				taskENTER_CRITICAL();
					m_lastGPSData = m_nmeaParser.result();
				taskEXIT_CRITICAL();
			}
		}
	}
}


void TimestampCollector::queueMonitorLoop()
{
	OutputData outputData;
	for (;;)
	{
		m_queue.popFront(outputData);
		if (m_dataReadyCallback)
			m_dataReadyCallback(outputData);
	}
}
