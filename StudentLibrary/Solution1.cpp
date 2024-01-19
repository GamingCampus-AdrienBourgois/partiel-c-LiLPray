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
            return (_value * 9 / 5) + 32;
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            return _value + 273;
        }
        break;

    case TemperatureUnits::FAHRENHEIT:
        if (_to == TemperatureUnits::CELSIUS)
        {
            return (_value - 32) * 5 / 9;
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            return (_value - 32) * 5 / 9 + 273;
        }
        break;

    case TemperatureUnits::KELVIN:
        if (_to == TemperatureUnits::CELSIUS)
        {
            return _value - 273;
        }
        else if (_to == TemperatureUnits::FAHRENHEIT)
        {
            return (_value - 273) * 9 / 5 + 32;
        }
        break;
    }

}

#endif
