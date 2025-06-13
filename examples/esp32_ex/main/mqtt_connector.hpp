/**
 * @file mqtt_connector.hpp
 * @brief Defines a custom MQTT connector for the application.
 * @version 0.1
 * @date 2025-06-13
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <functional>

#include "esp_mqtt.hpp"
#include "esp_mqtt_client_config.hpp"

namespace app
{

class MqttConnector final : public idf::mqtt::Client
{
   public:
    using idf::mqtt::Client::Client;  // constructors
    using ConnectedHandler_f = std::function<void(void)>;

    void registerConnectedHandler(ConnectedHandler_f handler) { m_connectedHandler = handler; }

   private:
    ConnectedHandler_f m_connectedHandler;

    void on_connected(esp_mqtt_event_handle_t const event) override
    {
        if (m_connectedHandler)
        {
            m_connectedHandler();
        }
    }
    void on_data(esp_mqtt_event_handle_t const event) override { }
};

}  // namespace app
