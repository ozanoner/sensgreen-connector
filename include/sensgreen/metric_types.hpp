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

class Temperature : public MetricBase<float>
{
   public:
    static constexpr std::string_view name           = "temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};

class Humidity : public MetricBase<float>
{
   public:
    static constexpr std::string_view name           = "humidity";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};

class Pressure : public MetricBase<float>
{
   public:
    static constexpr std::string_view name           = "pressure";
    static constexpr std::string_view unit           = "hPa";
    static constexpr bool             isControllable = false;
};

// TODO: add other types

}  // namespace sensgreen