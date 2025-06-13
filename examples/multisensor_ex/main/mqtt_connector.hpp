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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace app
{

class MqttConnector final : public idf::mqtt::Client
{
   public:
    using idf::mqtt::Client::Client;  // constructors
    using PublishTask_f = void (*)(void*);

    void registerPublishTask(PublishTask_f task) { m_publishTask = task; }

   private:
    PublishTask_f m_publishTask;
    TaskHandle_t  m_publishTaskHandle {nullptr};

    void on_connected(esp_mqtt_event_handle_t const event) override
    {
        if (nullptr == m_publishTaskHandle)
        {  // Create the FreeRTOS task
            xTaskCreate(m_publishTask, "publish-task", 2048, nullptr, tskIDLE_PRIORITY + 1, &m_publishTaskHandle);
        }
        else
        {
            vTaskResume(m_publishTaskHandle);
        }
    }

    void on_disconnected(const esp_mqtt_event_handle_t event) override
    {
        if (nullptr != m_publishTaskHandle)
        {
            vTaskSuspend(m_publishTaskHandle);
        }
    }

    void on_data(esp_mqtt_event_handle_t const event) override { }
};

}  // namespace app
