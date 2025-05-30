/**
 * @file multisensor_device.hpp
 * @brief Multisensor device definition
 * @version 0.1
 * @date 2025-05-30
 * @copyright Copyright (c) 2025
 */

#include "esp_err.h"
#include "led_strip.h"
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

class MyDevice : public sensgreen::device::esp32::Esp32Device<TemperatureSensorBrandA>
{
    using sensgreen::device::esp32::Esp32Device<TemperatureSensorBrandA>::Esp32Device;  // inherit constructors

   private:
    static constexpr int LED_GPIO = 8;

    led_strip_handle_t m_led;

   public:
    esp_err_t boardInit()
    {
        led_strip_config_t ledConfig {};
        ledConfig.strip_gpio_num = LED_GPIO;
        ledConfig.max_leds       = 1;  // at least one LED on board

        led_strip_rmt_config_t rmtConfig {};
        rmtConfig.resolution_hz  = 10 * 1000 * 1000;  // 10MHz
        rmtConfig.flags.with_dma = false;

        esp_err_t err = led_strip_new_rmt_device(&ledConfig, &rmtConfig, &m_led);
        if (ESP_OK != err)
        {
            return err;
        }

        err = led_strip_clear(m_led);
        if (ESP_OK != err)
        {
            return err;
        }

        return err;
    }
};
}  // namespace app
