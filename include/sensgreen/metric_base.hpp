/**
 * @file metric.hpp
 * @brief Interface definition for metric
 * @version 0.1
 * @date 2025-04-22
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <string_view>

namespace sensgreen::device
{

template <typename T>
class MetricBase
{
   public:
    static constexpr std::string_view name           = "unknown";
    static constexpr std::string_view unit           = "unknown";
    static constexpr bool             isControllable = false;

    explicit MetricBase(const T value = {}) : m_value(value) { }

    T getValue(void) const { return m_value; }

    void setValue(const T value)
    {
        if constexpr (isControllable)
        {
            m_value = value;
        }
        else
        {
            static_assert(isControllable, "Metric is not controllable");
        }
    }

   protected:
    T m_value;
};

}  // namespace sensgreen::device