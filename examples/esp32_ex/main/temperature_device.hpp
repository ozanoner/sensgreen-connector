
#include "sensgreen.hpp"

namespace app
{

class TemperatureSensorBrandA : public sensgreen::device::SensorBase<sensgreen::device::TemperatureMetric>
{
   public:
    virtual int read() override
    {
        // first read temperature from the physical sensor
        // then update the metric value
        get<sensgreen::device::TemperatureMetric>().setValue(25.0);

        return 0;
    }
};

class MyTemperatureDevice : public sensgreen::device::esp32::Esp32Device<TemperatureSensorBrandA>
{
    using sensgreen::device::esp32::Esp32Device<TemperatureSensorBrandA>::Esp32Device;  // inherit constructors
};
}  // namespace app
