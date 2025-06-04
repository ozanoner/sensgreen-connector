/**
 * @file esp32_mqtt_connector.cpp
 * @brief
 * @version 0.1
 * @date 2025-04-28
 * @copyright Copyright (c) 2025
 */

#include "esp32_mqtt_connector.hpp"

#include "component_utils.hpp"
#include "esp_event.h"

#define RETURN_IF_NOT_READY()             \
    do                                    \
    {                                     \
        if (!m_ready)                     \
        {                                 \
            return ESP_ERR_INVALID_STATE; \
        }                                 \
    } while (0)

namespace sensgreen::mqtt::esp32
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

int Esp32MqttConnector::init(const sensgreen::mqtt::ConnConfig& config)
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
                                                   handleMqttEvent, this);

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

    PRINT_LOC_D("topic: '%.*s'", topic.size(), topic.data());
    int msg_id = esp_mqtt_client_publish(m_client, topic.data(), payload.data(), static_cast<int>(payload.size()), qos,
                                         retain ? 1 : 0);
    PRINT_LOC_D("msg_id: %d", msg_id);
    return (msg_id >= 0) ? 0 : ESP_FAIL;
}

int Esp32MqttConnector::subscribe(std::string_view topic, sensgreen::mqtt::DataHandler handler)
{
    RETURN_IF_NOT_READY();

    int msg_id = esp_mqtt_client_subscribe(m_client, topic.data(), 1);
    if (msg_id < 0)
    {
        return ESP_FAIL;
    }

    registerDataHandler(topic, std::move(handler));  // store handler for dispatch
    return ESP_OK;
}

void Esp32MqttConnector::handleMqttEvent(void* handlerArgs, esp_event_base_t base, int32_t eventId, void* eventData)
{
    auto*               event     = static_cast<esp_mqtt_event_handle_t>(eventData);
    Esp32MqttConnector& connector = *static_cast<Esp32MqttConnector*>(handlerArgs);

    switch (eventId)
    {
        case MQTT_EVENT_CONNECTED:
            connector.handleEvent(MqttEvent::CONNECTED, nullptr);
            break;

        case MQTT_EVENT_DISCONNECTED:
            // TODO: auto-reconnect
            connector.handleEvent(MqttEvent::DISCONNECTED, nullptr);
            break;

        case MQTT_EVENT_DATA:
        {
            std::string_view topic {event->topic, (size_t)event->topic_len};
            std::string_view payload {event->data, (size_t)event->data_len};

            connector.dispatchData(topic, payload);
            break;
        }

        case MQTT_EVENT_ERROR:
            connector.handleEvent(MqttEvent::ERROR, eventData);
            break;

        default:
            break;
    }
}

}  // namespace sensgreen::mqtt::esp32
