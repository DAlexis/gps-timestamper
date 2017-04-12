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

extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim2;

SINGLETON_IN_CPP(GPSTimestamper)

GPSTimestamper::GPSTimestamper() :
	m_nmea(&huart3),
	m_precTimer(&htim2)
{
	//m_collector.setDataReadyCallback([this] (const OutputData& data) { m_outputMaker.makeOutputSync(data); });

}

void GPSTimestamper::run()
{
	printf("DBG: Running GPS timestamper\n");

	DateTime d;
	d.set(2017, 11, 1, 0, 0, 0);
	printf("DateTime test = %s\n", d.str().c_str());

	Position p;
	p.set(12.34, 'S', 14.32, 'E');
	printf("Position test = %s\n", p.str().c_str());

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
