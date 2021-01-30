#pragma once
#include "Thermometer.g.h"

namespace winrt::ThermometerWRC::implementation
{
    struct Thermometer : ThermometerT<Thermometer>
    {
        Thermometer() = default;
        Thermometer(float startPoint);

        void AdjustTemperature(float deltaFahrenheit);
        winrt::event_token TemperatureIsBelowFreezing(Windows::Foundation::EventHandler<float> const& handler);
        void TemperatureIsBelowFreezing(winrt::event_token const& token) noexcept;

        private:
            winrt::event<Windows::Foundation::EventHandler<float>> m_temperatureIsBelowFreezingEvent;
            float m_temperatureFahrenheit{ 40.f };
    };
}
namespace winrt::ThermometerWRC::factory_implementation
{
    struct Thermometer : ThermometerT<Thermometer, implementation::Thermometer>
    {
    };
}
