#ifndef LEDS_HPP
#define LEDS_HPP

#include "stm32f4xx_hal.h"

class Leds
{
public:
    void ledOn(int n, bool state = true);
    void ledToggle(int n);

private:
    struct PortPin
    {
        GPIO_TypeDef* port = nullptr;
        uint16_t pin = 0;
    };

    static PortPin getPortPin(int n);
};

#endif // LEDS_HPP
