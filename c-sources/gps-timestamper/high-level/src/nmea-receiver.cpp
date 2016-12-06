/*
 * nmea-receiver.cpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#include "nmea-receiver.hpp"
#include <stdio.h>
#include <string.h>

NMEAReceiver* receiverConnectedToInterrupt = nullptr;

NMEAReceiver::NMEAReceiver(UART_HandleTypeDef* huart)
{
	m_huart = huart;
}

const char* NMEAReceiver::getCurrentGPSString()
{
	return m_result;
}

bool NMEAReceiver::updatedString()
{
	bool tmp = m_updatedString;
	m_updatedString = false;
	return tmp;
}

void NMEAReceiver::run()
{
	printf("DBG: NMEA receiver run\n");
	receiverConnectedToInterrupt = this;
	HAL_UART_Receive_IT(m_huart, reinterpret_cast<uint8_t*>(targetByte), 1);
}

void NMEAReceiver::uartRXCallback()
{
	// If new line
	if (*targetByte == '\n')
	{
		if (!m_bufferOverflow) // If data is consisted
			parseMsg();        // then parse

		targetByte = m_buffer;
		m_bufferOverflow = false; // Now we are go from clear list and data is consisted by default
	} else if (targetByte - m_buffer == buffersize-1)
		m_bufferOverflow = true;
	else
		targetByte++;

	if (m_bufferOverflow)
		targetByte = m_buffer;

	HAL_UART_Receive_IT(m_huart, reinterpret_cast<uint8_t*>(targetByte), 1);
}

void NMEAReceiver::parseMsg()
{
	*targetByte = '\0';
	strcpy(m_result, m_buffer);
	m_updatedString = true;
}

extern "C" {
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
	{
		UNUSED(huart);
		if (receiverConnectedToInterrupt)
			receiverConnectedToInterrupt->uartRXCallback();
	}
}
