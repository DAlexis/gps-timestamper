/*
 * precision-timer.cpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#include "precision-timer.hpp"

PrecisionTimer *precisionTimerConnectedToInterrupt = nullptr;

PrecisionTimer::PrecisionTimer(TIM_HandleTypeDef* htim, IOutputMessagesReceiver& outputReceiver) :
	m_htim(htim),
	m_outputReceiver(outputReceiver)
{

}

void PrecisionTimer::run()
{
	precisionTimerConnectedToInterrupt = this;
	HAL_TIM_IC_Start_IT(m_htim, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(m_htim, TIM_CHANNEL_2);

}

void PrecisionTimer::checkForGPSDisconnect()
{
	// If we have no signal for now
	if (m_gpsCount == 0)
		return;

	// Ticks since last GPS signal
	uint32_t delay = m_htim->Instance->CNT - m_lastGPS;
	constexpr uint32_t timeout = 80000000; // This value should be corrected
	if (delay > timeout)
	{
		m_gpsCount = 0;
		m_outputReceiver.receive(new OutputGPSDisconnect());
	}
}

uint32_t PrecisionTimer::getValue()
{
	return m_htim->Instance->CNT;
}

void PrecisionTimer::setCaptureCallback(IRQSignalCaptureCallback callback)
{
	m_signalCallback = callback;
}

void PrecisionTimer::setPPSCaptureCallback(IRQPPSCaptureCallback callback)
{
	m_ppsCallback = callback;
}

void PrecisionTimer::captureIRQHandler(CaptureSource source, uint32_t value)
{

	switch(source)
	{
    case CaptureSource::PPS:
        m_prevGPS = m_lastGPS;
		m_lastGPS = value;
		m_gpsCount++;
		if (m_ppsCallback)
            m_ppsCallback();
        break;
	case CaptureSource::signal:
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
        if (m_gpsCount < 2)
            if (m_signalCallback)
                m_signalCallback(false, 0, 0);
			break;

		// We have unsigned arithmetics so we will get always valid positive numbers below
		uint32_t gpsPeriod   = m_lastGPS - m_prevGPS;
		uint32_t signalDelay = value - m_lastGPS;
        //double fractionalSeconds = ( (double) signalDelay) / ( (double) gpsPeriod);
        if (signalDelay <= gpsPeriod)
		{
			// We have valid time
			if (m_signalCallback)
                m_signalCallback(true, gpsPeriod, signalDelay);
		} else {
			// We had no GPS pulses for a time > 1 sec
			m_gpsCount = 0;
            if (m_signalCallback)
                m_signalCallback(false, 0, 0);
        }
		break;
	}
}

const TIM_HandleTypeDef* PrecisionTimer::timerHandler()
{
	return m_htim;
}

extern "C" {
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{
		if (precisionTimerConnectedToInterrupt && precisionTimerConnectedToInterrupt->timerHandler() == htim)
		{
			if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
				precisionTimerConnectedToInterrupt->captureIRQHandler(PrecisionTimer::CaptureSource::signal, htim->Instance->CCR1);
			else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
                precisionTimerConnectedToInterrupt->captureIRQHandler(PrecisionTimer::CaptureSource::PPS, htim->Instance->CCR2);
		}
	}
}

std::string OutputGPSDisconnect::str() const
{
    return std::string("{event: \"PPS disconnect\"}");
}
