#include <treshold-controller.hpp>

extern DAC_HandleTypeDef hdac;

ThresholdController::ThresholdController(DAC_HandleTypeDef* dac) :
    m_dac(dac)
{
    HAL_DAC_Start(m_dac, DAC_CHANNEL_1);
    HAL_DAC_Start(m_dac, DAC_CHANNEL_2);
    setCh0(0.5);
    setCh1(0.5);
}

void ThresholdController::setCh0(float treshold)
{
    HAL_DAC_SetValue(m_dac, DAC_CHANNEL_1, DAC_ALIGN_8B_R, int(255*treshold));
}

void ThresholdController::setCh1(float treshold)
{
    HAL_DAC_SetValue(m_dac, DAC_CHANNEL_2, DAC_ALIGN_8B_R, int(255*treshold));
}
