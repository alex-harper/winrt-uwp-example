#include "pch.h"
#include "Thermometer.h"
#include "Thermometer.g.cpp"

namespace winrt::ThermometerWRC::implementation
{
    Thermometer::Thermometer(float startPoint)
    {
        m_temperatureFahrenheit = startPoint;
    }
    void Thermometer::AdjustTemperature(float deltaFahrenheit)
    {
        m_temperatureFahrenheit += deltaFahrenheit;
        if (m_temperatureFahrenheit < 0.f) m_temperatureIsBelowFreezingEvent(*this, m_temperatureFahrenheit);
    }
    winrt::event_token Thermometer::TemperatureIsBelowFreezing(Windows::Foundation::EventHandler<float> const& handler)
    {
        return m_temperatureIsBelowFreezingEvent.add(handler);
    }
    void Thermometer::TemperatureIsBelowFreezing(winrt::event_token const& token) noexcept
    {
        m_temperatureIsBelowFreezingEvent.remove(token);
    }
}