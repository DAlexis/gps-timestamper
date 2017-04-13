#include "time-location-manager.hpp"

TimeLocationManager::TimeLocationManager(
		NMEAReceiver& nmea,
		PrecisionTimer& precTimer,
		IOutputMessagesReceiver& outputReceiver) :
	m_nmea(nmea),
	m_outputReceiver(outputReceiver)
{
	m_nmeaMonitoringTask.setStackSize(512);
	m_nmeaMonitoringTask.setTask([this]{ nmeaMonitoringLoop(); });
	precTimer.setPPSCaptureCallback([this] { IRQPPS(); });
}

void TimeLocationManager::run()
{
	m_nmeaMonitoringTask.run();
}

const DateTime& TimeLocationManager::dt() const
{
	return m_dt;
}

const Position& TimeLocationManager::pos() const
{
	return m_pos;
}

void TimeLocationManager::nmeaMonitoringLoop()
{
	for (;;)
	{
		if (m_wasPPS)
		{
			m_wasPPS = false;
			m_outputReceiver.receive(new OutputPPS(m_pos, m_dt));
			// @todo Add pps output
		}
		if (!m_nmea.updatedString())
		{
			continue;
		}
		NMEAParser::parse(m_nmea.getCurrentGPSString(), m_pos, m_dt);
	}
}

void TimeLocationManager::IRQPPS()
{
	m_dt++;
	m_wasPPS = true;
}
