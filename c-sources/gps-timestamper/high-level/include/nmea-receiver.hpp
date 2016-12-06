/*
 * nmea-receiver.hpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef HIGH_LEVEL_INCLUDE_NMEA_RECEIVER_HPP_
#define HIGH_LEVEL_INCLUDE_NMEA_RECEIVER_HPP_

#include "stm32f4xx_hal.h"
#include <stdint.h>

class NMEAReceiver
{
public:
	NMEAReceiver(UART_HandleTypeDef* huart);
	const char* getCurrentGPSString();
	bool updatedString();
	bool updatedGPS();
	void run();
	void uartRXCallback();

private:
	constexpr static int buffersize = 200;
	constexpr static int resetDelay = 500; //ms
	enum class State
	{
	};

	void parseMsg();

	char m_buffer[buffersize];
	char* targetByte = m_buffer;
	char m_result[buffersize] = "";

	bool m_updatedString = false;

	uint32_t m_lastMsgTime = 0;
	bool m_bufferOverflow = false;
	UART_HandleTypeDef* m_huart;
};





#endif /* HIGH_LEVEL_INCLUDE_NMEA_RECEIVER_HPP_ */
