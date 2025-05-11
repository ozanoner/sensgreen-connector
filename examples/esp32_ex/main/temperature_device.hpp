
#include "sensgreen.hpp"

namespace app
{

class TemperatureSensorBrandA : public sensgreen::device::SensorBase<sensgreen::device::TemperatureMetric>
{
    virtual int read() override
    {
        // first read temperature from the physical sensor
        // then update the metric value
        get<sensgreen::device::TemperatureMetric>().setValue(25.0);

        return 0;
    }
};

class MyTemperatureDevice : public sensgreen::device::DeviceBase<TemperatureSensorBrandA>
{
    using DeviceBase<TemperatureSensorBrandA>::DeviceBase;  // inherit constructors
};
}  // namespace app
