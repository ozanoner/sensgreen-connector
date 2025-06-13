/**
 * @file device.hpp
 * @brief Defines a device to accommodate a sensor data
 * @version 0.1
 * @date 2025-04-18
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <chrono>
#include <string_view>
#include <tuple>

#include "nlohmann/json.hpp"
#include "sensor_base.hpp"

namespace sensgreen
{

struct DeviceConfig
{
    std::string_view uid;
    std::string_view topicData;
    std::string_view topicCmd;
    std::string_view topicErr;
    std::string_view topicOta;
};

template <typename... Sensors>
class Device
{
   public:
    using SensorTuple = std::tuple<Sensors...>;

    explicit Device(const DeviceConfig& config) : m_config(config) { }

    // Non-copyable
    Device(const Device&)            = delete;
    Device& operator=(const Device&) = delete;

    const DeviceConfig& config() const { return m_config; }

    // initialize the device
    virtual int init(void* param) { return 0; }

    template <std::size_t Index>
    auto& getSensor()
    {
        static_assert(Index < sizeof...(Sensors), "Sensor index out of range");
        return std::get<Index>(m_sensors);
    }

    template <typename SensorType>
    SensorType& getSensor()
    {
        return std::get<SensorType>(m_sensors);
    }

    void readAllSensors()
    {
        std::apply([](auto&... sensor) { (sensor.read(), ...); }, m_sensors);
    }

    nlohmann::json report() const
    {
        nlohmann::json json;
        auto           millis =
            std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
                .count();

        json["deviceEui"] = m_config.uid;
        json["timestamp"] = static_cast<std::uint64_t>(millis);
        auto& data        = json["data"];  // reference to nested object
        data              = nlohmann::json::object();

        std::apply([&data](const auto&... sensor) { ((sensor.append(data)), ...); }, m_sensors);

        return json;
    }

   protected:
    DeviceConfig m_config;
    SensorTuple  m_sensors;
};

}  // namespace sensgreen
