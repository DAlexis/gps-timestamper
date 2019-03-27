#include "leds.hpp"

#include "main.h"

void Leds::ledOn(int n, bool state)
{
    PortPin pp = getPortPin(n);
    HAL_GPIO_WritePin(pp.port, pp.pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void Leds::ledToggle(int n)
{
    PortPin pp = getPortPin(n);
    HAL_GPIO_TogglePin(pp.port, pp.pin);
}

Leds::PortPin Leds::getPortPin(int n)
{
    PortPin result;
    if (n < 2)
    {
        result.port = GPIOE;
    } else {
        result.port = GPIOD;
    }
    switch (n)
    {
        case 0: result.pin = GPIO_PIN_0; break;
        case 1: result.pin = GPIO_PIN_1; break;
        case 2: result.pin = GPIO_PIN_12; break;
        case 3: result.pin = GPIO_PIN_13; break;
        case 4: result.pin = GPIO_PIN_14; break;
    }
    return result;
}
