/**
 * @file sensor_base.hpp
 * @brief Interface definition for sensors. Each sensor has a collection of metrics/
 *        Sensor is the common name for both sensors and actuators
 * @version 0.1
 * @date 2025-04-23
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <map>
#include <tuple>

#include "metric_base.hpp"

namespace sensgreen::device
{

template <typename... Metrics>
class SensorBase
{
   public:
    using MetricsTuple = std::tuple<Metrics...>;

    SensorBase()          = default;
    virtual ~SensorBase() = default;

    // Disable copy
    SensorBase(const SensorBase&)            = delete;
    SensorBase& operator=(const SensorBase&) = delete;

    // read the physical sensor and update the metrics
    virtual int read() = 0;

    template <typename MetricType>
    auto& get()
    {
        return std::get<MetricType>(m_metrics);
    }

    template <std::size_t Index>
    auto& get()
    {
        static_assert(Index < sizeof...(Metrics), "Metric index out of range");
        return std::get<Index>(m_metrics);
    }

    template <typename MetricType>
    auto& getValue()
    {
        return std::get<MetricType>(m_metrics).getValue();
    }

    template <std::size_t Index>
    auto& getValue()
    {
        static_assert(Index < sizeof...(Metrics), "Metric index out of range");
        return std::get<Index>(m_metrics).getValue();
    }

    void append(nlohmann::json& j) const
    {
        std::apply([&j](const auto&... metric) { ((j[metric.getName().data()] = metric.getValue()), ...); }, m_metrics);
    }

   protected:
    MetricsTuple m_metrics;
};

}  // namespace sensgreen::device