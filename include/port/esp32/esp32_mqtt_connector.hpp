/**
 * @file esp32_mqtt_connector.hpp
 * @brief
 * @version 0.1
 * @date 2025-04-28
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <unordered_map>
#include <vector>

#include "esp_event.h"
#include "mqtt_client.h"
#include "sensgreen/mqtt_connector.hpp"

namespace sensgreen::mqtt::esp32
{

class Esp32MqttConnector : public sensgreen::mqtt::Connector
{
   public:
    static Esp32MqttConnector& instance();
    ~Esp32MqttConnector() override;

    int init(const sensgreen::mqtt::ConnConfig& config) override;
    int connect(void) override;
    int publish(std::string_view topic, std::string_view payload, int qos = 1, bool retain = false) override;
    int subscribe(std::string_view topic, sensgreen::mqtt::DataHandler handler) override;

   private:
    static constexpr auto TAG = "mqtt";

    Esp32MqttConnector() = default;

    esp_mqtt_client_handle_t m_client = nullptr;
    static void handleMqttEvent(void* handlerArgs, esp_event_base_t base, int32_t eventId, void* eventData);
};

}  // namespace sensgreen::mqtt::esp32
