/**
 * @file metric_base.hpp
 * @brief Interface definition for metric
 * @version 0.1
 * @date 2025-04-22
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <string_view>

namespace sensgreen
{

template <typename T, typename Tag>
class MetricBase
{
   public:
    static constexpr std::string_view name           = Tag::name;
    static constexpr std::string_view unit           = Tag::unit;
    static constexpr bool             isControllable = Tag::isControllable;

    explicit MetricBase(const T value = {}) : m_value(value) { }

    T getValue() const { return m_value; }

    void setValue(const T value) { m_value = value; }

    // helpers to return metric tag information
    auto getName() const { return name; }
    auto getUnit() const { return unit; }
    auto isControllableMetric() const { return MetricBase<T, Tag>::isControllable; }

   protected:
    T m_value;
};

}  // namespace sensgreen