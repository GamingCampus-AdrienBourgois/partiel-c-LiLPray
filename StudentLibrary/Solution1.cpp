#include "Solution1.h"
#include <cmath>  // Ajout pour la fonction std::round

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
            return std::round((_value * 9 / 5) + 32.0f);
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            return std::round(_value + 273.15f);
        }
        break;

    case TemperatureUnits::FAHRENHEIT:
        if (_to == TemperatureUnits::CELSIUS)
        {
            return std::round((_value - 32) * 5 / 9.0f);
        }
        else if (_to == TemperatureUnits::KELVIN)
        {
            return std::round((_value - 32) * 5 / 9.0f + 273.15f);
        }
        break;

    case TemperatureUnits::KELVIN:
        if (_to == TemperatureUnits::CELSIUS)
        {
            return std::round(_value - 273.15f);
        }
        else if (_to == TemperatureUnits::FAHRENHEIT)
        {
            return std::round((_value - 273.15f) * 9 / 5.0f + 32.0f);
        }
        break;
    }

    return -1.0f;
}

#endif
