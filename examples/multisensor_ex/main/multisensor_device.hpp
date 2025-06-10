/**
 * @file multisensor_device.hpp
 * @brief Multisensor device definition
 * @version 0.1
 * @date 2025-05-30
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <cassert>
#include <string_view>

#include "bh1750.h"
#include "bme280.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_indicator.h"
#include "sensgreen.hpp"

namespace app
{

class Bme280
    : public sensgreen::device::SensorBase<sensgreen::device::TemperatureMetric, sensgreen::device::HumidityMetric,
                                           sensgreen::device::PressureMetric>
{
   private:
    bme280_handle_t       m_bme280;
    static constexpr auto TAG = "bme280";

   public:
    int init(void *param) override
    {
        i2c_bus_handle_t i2cBus = static_cast<i2c_bus_handle_t>(param);
        m_bme280                = bme280_create(i2cBus, BME280_I2C_ADDRESS_DEFAULT);
        assert(nullptr != m_bme280);

        esp_err_t err = bme280_default_init(m_bme280);
        RETURN_IF_ERR(err, "bme280 init failed");
        return (int)err;
    }

    int read() override
    {
        float     data = 0.0;
        esp_err_t err  = ESP_OK;

        vTaskDelay(pdMS_TO_TICKS(300));
        PRINT_LOC_D("before bme280_read_temperature");
        err = bme280_read_temperature(m_bme280, &data);
        RETURN_IF_ERR(err, "bme280 temp-read failed");
        get<sensgreen::device::TemperatureMetric>().setValue(data);

        PRINT_LOC_D("before bme280_read_humidity");
        err = bme280_read_humidity(m_bme280, &data);
        RETURN_IF_ERR(err, "bme280 humidity-read failed");
        get<sensgreen::device::HumidityMetric>().setValue(data);

        PRINT_LOC_D("before bme280_read_pressure");
        err = bme280_read_pressure(m_bme280, &data);
        RETURN_IF_ERR(err, "bme280 pressure-read failed");
        get<sensgreen::device::PressureMetric>().setValue(data);

        return (int)err;
    }
};

class Bh1750 : public sensgreen::device::SensorBase<sensgreen::device::LightLevelMetric>
{
   private:
    bh1750_handle_t       m_bh1750;
    static constexpr auto TAG = "bh1750";

   public:
    int init(void *param) override
    {
        i2c_bus_handle_t i2cBus = static_cast<i2c_bus_handle_t>(param);
        m_bh1750                = bh1750_create(i2cBus, BH1750_I2C_ADDRESS_DEFAULT);
        assert(nullptr != m_bh1750);
        return (int)ESP_OK;
    }

    int read() override
    {
        float     data = 0.0;
        esp_err_t err  = ESP_OK;

        PRINT_LOC_D("before bh1750_power_on");
        bh1750_power_on(m_bh1750);
        bh1750_set_measure_mode(m_bh1750, BH1750_ONETIME_4LX_RES);

        vTaskDelay(pdMS_TO_TICKS(30));
        PRINT_LOC_D("before bh1750_get_data");
        err = bh1750_get_data(m_bh1750, &data);
        RETURN_IF_ERR(err, "bh1750 read failed");

        get<sensgreen::device::LightLevelMetric>().setValue(data);

        return (int)err;
    }
};

class MyDevice : public sensgreen::device::esp32::Esp32Device<Bme280, Bh1750>
{
    using sensgreen::device::esp32::Esp32Device<Bme280, Bh1750>::Esp32Device;  // inherit constructors

   private:
    static constexpr auto TAG = "device";

    static constexpr int        DEVICE_LED_GPIO    = 8;
    static constexpr int        I2C_MASTER_SDA_IO  = 21;
    static constexpr int        I2C_MASTER_SCL_IO  = 22;
    static constexpr i2c_port_t I2C_MASTER_NUM     = I2C_NUM_0;
    static constexpr int        I2C_MASTER_FREQ_HZ = (100 * 1000);

    static constexpr led_indicator_strips_config_t DEVICE_LED_CONFIG {
        {DEVICE_LED_GPIO, 1, LED_PIXEL_FORMAT_GRB, LED_MODEL_WS2812, {false}},
        LED_STRIP_RMT,
        {RMT_CLK_SRC_DEFAULT, (10 * 1000 * 1000), 0, {false}}};

    led_indicator_config_t m_ledConfig;
    led_indicator_handle_t m_led;

    static constexpr i2c_config_t DEVICE_I2C_CONFIG {
        I2C_MODE_MASTER, I2C_MASTER_SDA_IO, I2C_MASTER_SCL_IO, true, true, {I2C_MASTER_FREQ_HZ}, 0};

    i2c_bus_handle_t m_i2cBus = NULL;

   public:
    int init(void *param = nullptr) override
    {
        esp_err_t err = ESP_OK;

        // LED initialisation
        m_ledConfig.mode                        = LED_STRIPS_MODE;
        m_ledConfig.led_indicator_strips_config = const_cast<led_indicator_strips_config_t *>(&DEVICE_LED_CONFIG);
        m_ledConfig.blink_lists                 = nullptr;  // define blinks later if needed
        m_ledConfig.blink_list_num              = 0;

        m_led = led_indicator_create(&m_ledConfig);
        assert(nullptr != m_led);
        err = led_indicator_set_on_off(m_led, false);
        RETURN_IF_ERR(err, "led init failed");

        m_i2cBus = i2c_bus_create(I2C_MASTER_NUM, &DEVICE_I2C_CONFIG);
        assert(nullptr != m_i2cBus);

        err = getSensor<Bh1750>().init(m_i2cBus);
        RETURN_IF_ERR2(err);

        err = getSensor<Bme280>().init(m_i2cBus);

        return (int)err;
    }
};
}  // namespace app
