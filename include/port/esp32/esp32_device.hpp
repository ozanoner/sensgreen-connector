
#pragma once

#include <sys/time.h>

#include "sensgreen/device.hpp"

namespace sensgreen::device::esp32
{

template <typename... Sensors>
class Esp32Device : public sensgreen::device::DeviceBase<Sensors...>
{
   public:
    using sensgreen::device::DeviceBase<Sensors...>::DeviceBase;  // Inherit all constructors

    // Add overload or extensions
    nlohmann::json report() const
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);
        std::uint64_t timestamp =
            static_cast<std::uint64_t>(tv.tv_sec) * 1000ULL + static_cast<std::uint64_t>(tv.tv_usec) / 1000ULL;
        return sensgreen::device::DeviceBase<Sensors...>::report(timestamp);
    }
};

}  // namespace sensgreen::device::esp32
