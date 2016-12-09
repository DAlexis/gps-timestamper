/*
 * timestamp-queue.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_

#include "output-data.hpp"
#include "nmea-receiver.hpp"
#include "nmea-parser.hpp"
#include "precision-timer.hpp"
#include "os-wrappers.hpp"

class TimestampCollector
{
public:
	using DataReadyCallback = std::function<void(const OutputData& data)>;

	TimestampCollector(NMEAReceiver* nmea, PrecisionTimer* precisionTimer);

	void setDataReadyCallback(DataReadyCallback callback);

	void run();

private:
	void IRQSignalCaptureCallback(double time, uint32_t oneSecPeriod, uint32_t signalDelay);
	void IRQPpsCaptureCallback();

	void nmeaMonitoringLoop();
	void queueMonitorLoop();

	char m_reservedGPSString[NMEAReceiver::GPSstringMaxLen];
	NMEAReceiver* m_nmea;
	PrecisionTimer* m_precisionTimer;

	Queue<OutputData> m_queue{10};

	TaskOnce m_nmeaMonitoringTask;
	TaskOnce m_queueMonitoringTask;

	GPSData m_lastGPSData;
	GPSData m_actualGPSData;
	NMEAParser m_nmeaParser;

	DataReadyCallback m_dataReadyCallback;
};



#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIMESTAMP_COLLECTOR_HPP_ */
