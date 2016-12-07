/*
 * precision-timer.hpp
 *
 *  Created on: 6 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_PRECISION_TIMER_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_PRECISION_TIMER_HPP_

#include "stm32f4xx_hal.h"

#include <functional>
#include <stdint.h>

class PrecisionTimer
{
public:
	using IRQSignalCaptureCallback = std::function<void(double time, uint32_t oneSecPeriod, uint32_t signalDelay)>;
	using IRQPPSCaptureCallback = std::function<void()>;

	enum class CaptureSource {
		GPS, signal
	};

	PrecisionTimer(TIM_HandleTypeDef* htim);
	void run();
	/// This function should be called regulary to ensure that we have valid last GPS records
	void checkForGPSDisconnect();
	uint32_t getValue();
	void setCaptureCallback(IRQSignalCaptureCallback callback);
	void setPPSCaptureCallback(IRQPPSCaptureCallback callback);

	void captureIRQHandler(CaptureSource source, uint32_t value);
	const TIM_HandleTypeDef* timerHandler();


private:
	TIM_HandleTypeDef* m_htim;
	uint32_t m_prevGPS = 0;
	uint32_t m_lastGPS = 0;
	uint32_t m_gpsCount = 0;

	IRQSignalCaptureCallback m_signalCallback = nullptr;
	IRQPPSCaptureCallback m_ppsCallback = nullptr;
};


#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_PRECISION_TIMER_HPP_ */
