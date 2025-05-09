/**
 * @file esp32_mqtt_connector.cpp
 * @brief
 * @version 0.1
 * @date 2025-04-28
 * @copyright Copyright (c) 2025
 */

#include "esp32_mqtt_connector.hpp"

#include "esp_event.h"
#include "esp_log.h"

#define RETURN_IF_NOT_READY()             \
    do                                    \
    {                                     \
        if (!m_ready)                     \
        {                                 \
            return ESP_ERR_INVALID_STATE; \
        }                                 \
    } while (0)

namespace sensgreen::port::mqtt
{

Esp32MqttConnector& Esp32MqttConnector::instance()
{
    static Esp32MqttConnector singleton;
    return singleton;
}

Esp32MqttConnector::~Esp32MqttConnector()
{
    if (m_client)
    {
        esp_mqtt_client_stop(m_client);
        esp_mqtt_client_destroy(m_client);

        m_client = nullptr;
        m_ready  = false;
    }
}

int Esp32MqttConnector::init(const sensgreen::common::mqtt::ConnConfig& config)
{
    if (m_client)
    {
        return ESP_ERR_NOT_ALLOWED;
    }

    Connector::init(config);  // Sets m_config

    // TODO: secure MQTT
    esp_mqtt_client_config_t mqtt_cfg {};

    mqtt_cfg.broker.address.uri                  = m_config.host.data();
    mqtt_cfg.broker.address.port                 = static_cast<uint16_t>(m_config.port);
    mqtt_cfg.credentials.username                = m_config.username.data();
    mqtt_cfg.credentials.authentication.password = m_config.password.data();

    m_client = esp_mqtt_client_init(&mqtt_cfg);
    if (!m_client)
    {
        return ESP_ERR_NO_MEM;
    }

    esp_err_t err = esp_mqtt_client_register_event(m_client, static_cast<esp_mqtt_event_id_t>(ESP_EVENT_ANY_ID),
                                                   handleMqttEvent, m_client);

    m_ready = (err == ESP_OK);

    return err;
}

int Esp32MqttConnector::connect()
{
    RETURN_IF_NOT_READY();

    esp_err_t err = esp_mqtt_client_start(m_client);
    m_ready       = (err == ESP_OK);

    return err;
}

int Esp32MqttConnector::publish(std::string_view topic, std::string_view payload, int qos, bool retain)
{
    RETURN_IF_NOT_READY();

    int msg_id = esp_mqtt_client_publish(m_client, topic.data(), payload.data(), static_cast<int>(payload.size()), qos,
                                         retain ? 1 : 0);

    return (msg_id >= 0) ? 0 : ESP_FAIL;
}

int Esp32MqttConnector::subscribe(std::string_view topic, sensgreen::common::mqtt::MessageHandler handler)
{
    RETURN_IF_NOT_READY();

    int msg_id = esp_mqtt_client_subscribe(m_client, topic.data(), 1);
    if (msg_id < 0)
    {
        return ESP_FAIL;
    }

    registerHandler(topic, std::move(handler));  // store handler for dispatch
    return ESP_OK;
}

void Esp32MqttConnector::handleMqttEvent(void* handler_args, esp_event_base_t base, int32_t event_id, void* event_data)
{
    auto* event     = static_cast<esp_mqtt_event_handle_t>(event_data);
    auto& connector = Esp32MqttConnector::instance();

    switch (event_id)
    {
        case MQTT_EVENT_CONNECTED:
            // TODO: add external event handling callback
            ESP_LOGI("MQTT", "Connected to broker");
            connector.m_ready = true;
            break;

        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGD("MQTT", "Disconnected from broker");
            // TODO: auto-reconnect
            connector.m_ready = false;
            break;

        case MQTT_EVENT_DATA:
        {
            std::string_view topic(event->topic, event->topic_len);
            std::string_view payload(event->data, event->data_len);

            ESP_LOGD("MQTT", "Incoming message on topic %.*s", static_cast<int>(topic.size()), topic.data());

            instance().dispatchMessage(topic, payload);
            break;
        }

        case MQTT_EVENT_ERROR:
            // TODO: add external error handling callback
            ESP_LOGE("MQTT", "MQTT error occurred");
            connector.m_ready = false;
            break;

        default:
            break;
    }
}

}  // namespace sensgreen::port::mqtt
