#ifndef TRESHOLDCONTROLLER_HPP
#define TRESHOLDCONTROLLER_HPP

#include "stm32f4xx_hal.h"

class ThresholdController
{
public:
    ThresholdController(DAC_HandleTypeDef* dac);

    void setCh0(float treshold);
    void setCh1(float treshold);

private:
    DAC_HandleTypeDef* m_dac;
};

#endif // TRESHOLDCONTROLLER_HPP
