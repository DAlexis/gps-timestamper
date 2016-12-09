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
extern TIM_HandleTypeDef htim2;

SINGLETON_IN_CPP(GPSTimestamper)

GPSTimestamper::GPSTimestamper() :
	m_nmea(&huart3),
	m_precTimer(&htim2),
	m_collector(&m_nmea, &m_precTimer)
{
	m_collector.setDataReadyCallback([this] (const OutputData& data) { m_outputMaker.makeOutputSync(data); });

}

void GPSTimestamper::run()
{
	printf("DBG: Running GPS timestamper\n");
	NMEAParser parser;

	m_nmea.run();
	m_precTimer.run();
	m_collector.run();
	for (;;)
	{
		m_precTimer.checkForGPSDisconnect();
		//osDelay(100);
		//printf("CCR1: %d, CCR2: %d\n", (int) htim2.Instance->CCR1, (int) htim2.Instance->CCR2);
		/*
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
			printf("Timer: %d\n", (int) m_precTimer.getValue());
			printf("Timer capture reg: %d\n", (int) htim2.Instance->CCR1);
			printf("Timer capture reg: %d\n", (int) __HAL_TIM_GetCompare (&htim2, TIM_CHANNEL_1));
		}*/
	}
}

extern "C" void entryPoint(void)
{
	GPSTimestamper::instance().run();
}
