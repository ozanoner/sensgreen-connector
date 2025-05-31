/**
 * @file metric_types.hpp
 * @brief Metric types
 * @version 0.1
 * @date 2025-04-22
 * @copyright Copyright (c) 2025
 */

#include <string_view>

#include "metric_base.hpp"

namespace sensgreen::device
{

struct TemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};

using TemperatureMetric = MetricBase<float, TemperatureReadOnlyTag>;

struct HumidityReadOnlyTag
{
    static constexpr std::string_view name           = "humidity";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};

using HumidityMetric = MetricBase<float, HumidityReadOnlyTag>;

struct PressureReadOnlyTag
{
    static constexpr std::string_view name           = "pressure";
    static constexpr std::string_view unit           = "hPa";
    static constexpr bool             isControllable = false;
};

using PressureMetric = MetricBase<float, PressureReadOnlyTag>;

struct LightReadOnlyTag
{
    static constexpr std::string_view name           = "light";
    static constexpr std::string_view unit           = "lux";
    static constexpr bool             isControllable = false;
};

using LightMetric = MetricBase<float, LightReadOnlyTag>;

// TODO: add other types

}  // namespace sensgreen::device