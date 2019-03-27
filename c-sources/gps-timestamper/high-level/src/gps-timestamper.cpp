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
    // Some debug code here for triangle ref signal generation
    float tmp = 1e-4f;
    float d = 1e-6f;
    m_leds.ledOn(1);
	for (;;)
    {
		m_precTimer.checkForGPSDisconnect();
        m_tresholdController.setCh0(tmp);
        tmp += d;
        if (tmp >= 1.0f)
        {
            d = -d;
            tmp += d;
            m_leds.ledToggle(0);
        }
        if (tmp <= 0.0f)
        {
            d = -d;
            tmp += d;
        }
	}
}

extern "C" void entryPoint(void)
{
	GPSTimestamper::instance().run();
}
