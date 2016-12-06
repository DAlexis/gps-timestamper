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

extern UART_HandleTypeDef huart3;

SINGLETON_IN_CPP(GPSTimestamper)

GPSTimestamper::GPSTimestamper() :
	m_nmea(&huart3)
{
}

void GPSTimestamper::run()
{
	printf("DBG: Running GPS timestamper\n");
	NMEAParser parser;

	m_nmea.run();
	for (;;)
	{
		if (m_nmea.updatedString())
		{
			printf("DBG: GPS says: %s\n", m_nmea.getCurrentGPSString());
			parser.parse(m_nmea.getCurrentGPSString());
			if (parser.result())
			{
				printf("DBG: parsed: time=%s, lat=%s, lon=%s.\n",
						parser.result().time,
						parser.result().lat,
						parser.result().lon);
			}
		}
	}
}

extern "C" void entryPoint(void)
{
	GPSTimestamper::instance().run();
}
