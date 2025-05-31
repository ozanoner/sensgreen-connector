/**
 * @file multisensor_device.hpp
 * @brief Multisensor device definition
 * @version 0.1
 * @date 2025-05-30
 * @copyright Copyright (c) 2025
 */

#include <cassert>

#include "bh1750.h"
#include "bme280.h"
#include "esp_err.h"
#include "led_indicator.h"
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
    static constexpr int        DEVICE_LED_GPIO    = 8;
    static constexpr int        I2C_MASTER_SCL_IO  = 22;
    static constexpr int        I2C_MASTER_SDA_IO  = 21;
    static constexpr i2c_port_t I2C_MASTER_NUM     = I2C_NUM_0;
    static constexpr int        I2C_MASTER_FREQ_HZ = (100 * 1000);

    static constexpr led_indicator_strips_config_t DEVICE_LED_CONFIG {
        {DEVICE_LED_GPIO, 1, LED_PIXEL_FORMAT_GRB, LED_MODEL_WS2812, {false}},
        LED_STRIP_RMT,
        {RMT_CLK_SRC_DEFAULT, (10 * 1000 * 1000), 0, {false}}};

    led_indicator_config_t m_ledIndconfig;
    led_indicator_handle_t m_led;

    static constexpr i2c_config_t DEVICE_I2C_CONFIG {
        I2C_MODE_MASTER, I2C_MASTER_SDA_IO, I2C_MASTER_SCL_IO, true, true, {I2C_MASTER_FREQ_HZ}, 0};

    i2c_bus_handle_t m_i2cBus = NULL;
    bh1750_handle_t  m_bh1750 = NULL;
    bme280_handle_t  m_bme280 = NULL;

   public:
    esp_err_t boardInit()
    {
        esp_err_t err = ESP_OK;

        // LED initialisation
        m_ledIndconfig.mode                        = LED_STRIPS_MODE;
        m_ledIndconfig.led_indicator_strips_config = const_cast<led_indicator_strips_config_t*>(&DEVICE_LED_CONFIG);
        m_ledIndconfig.blink_lists                 = nullptr;  // define blinks later if needed
        m_ledIndconfig.blink_list_num              = 0;

        m_led = led_indicator_create(&m_ledIndconfig);
        assert(nullptr != m_led);
        err = led_indicator_set_on_off(m_led, false);

        m_i2cBus = i2c_bus_create(I2C_MASTER_NUM, &DEVICE_I2C_CONFIG);
        assert(nullptr != m_i2cBus);
        m_bh1750 = bh1750_create(m_i2cBus, BH1750_I2C_ADDRESS_DEFAULT);
        assert(nullptr != m_bh1750);
        m_bme280 = bme280_create(m_i2cBus, BME280_I2C_ADDRESS_DEFAULT);
        assert(nullptr != m_bme280);

        return err;
    }
};
}  // namespace app
