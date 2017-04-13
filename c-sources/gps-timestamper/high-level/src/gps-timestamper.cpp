/*
 * gps-timestamper.cpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#include "gps-timestamper.hpp"
#include "gps-timestamper-entry-point.h"
#include "nmea-parser.hpp"

#include "cmsis_os.h"

#include <string.h>

SINGLETON_IN_CPP(GPSTimestamper)

GPSTimestamper::GPSTimestamper()
{

}

void GPSTimestamper::run()
{
	m_outputMaker.receive(new OutputDebug("Running GPS timestamper"));

	m_nmea.run();
	m_precTimer.run();
	m_timeLocMgr.run();
	m_outputMaker.run();
	//m_collector.run();
	for (;;)
	{
		m_precTimer.checkForGPSDisconnect();
	}
}

extern "C" void entryPoint(void)
{
	GPSTimestamper::instance().run();
}
