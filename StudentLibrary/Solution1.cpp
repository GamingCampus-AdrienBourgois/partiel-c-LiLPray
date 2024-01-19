#include "Solution1.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
    if (_from == _to)
    {
        return _value;
    }

    switch (_from)
    {
    case TemperatureUnits::CELSIUS:
        if (_to == TemperatureUnits::FAHRENHEIT)
        {
            // Celsius to Fahrenheit °F = 9/5 (°C) + 32
            return (_value * 9 / 5) + 32;
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            // Celsius to Kelvin K = °C + 273
            return _value + 273;
        }
        break;

    case TemperatureUnits::FAHRENHEIT:
        if (_to == TemperatureUnits::CELSIUS)
        {
            // Fahrenheit to Celsius °C = 5/9 (°F - 32)
            return (_value - 32) * 5 / 9;
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            // Fahrenheit to Kelvin K = 5/9 (°F - 32) + 273
            return (_value - 32) * 5 / 9 + 273;
        }
        break;

    case TemperatureUnits::KELVIN:
        if (_to == TemperatureUnits::CELSIUS)
        {
            // Kelvin to Celsius °C = K - 273
            return _value - 273;
        }
        else if (_to == TemperatureUnits::FAHRENHEIT)
        {
            // Kelvin to Fahrenheit °F = 9/5 (K - 273) + 32
            return (_value - 273) * 9 / 5 + 32;
        }
        break;
    }

    return -1.0f;
}

#endif
