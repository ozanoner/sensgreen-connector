/**
 * @file sensgreen.hpp
 * @brief Header file for the sensgreen library. Include this in the main app.
 * @version 0.1
 * @date 2025-04-17
 * @copyright Copyright (c) 2025
 */

#pragma once

#include "nlohmann/json.hpp"
#include "sensgreen/device.hpp"
#include "sensgreen/metric_types.hpp"
#include "sensgreen/mqtt_connector.hpp"

#ifdef SENSGREEN_ESP32
#include "port/esp32/component_utils.hpp"
#include "port/esp32/esp32_device.hpp"
#include "port/esp32/esp32_mqtt_connector.hpp"
#endif