/**
 * @file device.hpp
 * @brief Defines a device to accommodate a sensor data
 * @version 0.1
 * @date 2025-04-18
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <string_view>
#include <tuple>

#include "sensor_base.hpp"

namespace sensgreen::device
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
class DeviceBase
{
   public:
    using SensorTuple = std::tuple<Sensors...>;

    explicit DeviceBase(const DeviceConfig& config) : m_config(config) { }

    // Non-copyable
    DeviceBase(const DeviceBase&)            = delete;
    DeviceBase& operator=(const DeviceBase&) = delete;

    const DeviceConfig& config() const { return m_config; }

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

    nlohmann::json report(std::uint64_t timestamp) const
    {
        nlohmann::json json;

        json["deviceEui"] = m_config.uid;
        json["timestamp"] = timestamp;
        auto& data        = json["data"];  // reference to nested object
        data              = nlohmann::json::object();

        std::apply([&data](const auto&... sensor) { ((sensor.append(data)), ...); }, m_sensors);

        return json;
    }

   protected:
    DeviceConfig m_config;
    SensorTuple  m_sensors;
};

}  // namespace sensgreen::device
