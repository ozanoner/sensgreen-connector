/**
 * @file temperature_device.hpp
 * @brief Defines a temperature sensor device for testing purposes.
 * @version 0.1
 * @date 2025-06-13
 * @copyright Copyright (c) 2025
 */

#pragma once

#include "sensgreen.hpp"

namespace app
{

class TemperatureSensorBrandA : public sensgreen::SensorBase<sensgreen::TemperatureMetric>
{
   public:
    virtual int read() override
    {
        // first read temperature from the physical sensor
        // then update the metric value
        get<sensgreen::TemperatureMetric>().setValue(25.0);

        return 0;
    }
};

class MyTemperatureDevice : public sensgreen::Device<TemperatureSensorBrandA>
{
    using sensgreen::Device<TemperatureSensorBrandA>::Device;  // inherit constructors
};
}  // namespace app
