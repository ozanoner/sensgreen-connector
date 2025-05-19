/**
 * @file mqtt_topic_buffer.hpp
 * @author your name (you@domain.com)
 * @brief MqttTopicBuffer to alloc memory from internal/external RAM, or NVS
 * @version 0.1
 * @date 2025-05-19
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <cstddef>
#include <string_view>

namespace sensgreen::mqtt
{
class MqttTopicBuffer
{
   public:
    virtual ~MqttTopicBuffer() = default;

    // reset buffer before use
    virtual size_t reset() = 0;
    // return error code
    virtual int save(const std::string_view data, int pos = -1) = 0;
    // return capacity
    virtual size_t size() const = 0;

   protected:
};
}  // namespace sensgreen::mqtt