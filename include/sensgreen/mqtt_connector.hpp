/**
 * @file mqtt_connector.hpp
 * @brief Interface definition for MQTT connector. Implementations are under port
 * @version 0.1
 * @date 2025-04-17
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <cinttypes>
#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace sensgreen::mqtt
{

enum class MqttEvent
{
    CONNECTED,
    DISCONNECTED,
    ERROR
};

using DataHandler  = std::function<void(const std::string_view topic, const std::string_view payload)>;
using EventHandler = std::function<void(const void* eventData)>;

struct ConnConfig
{
    std::string_view host;
    std::int16_t     port;
    std::string_view username;
    std::string_view password;
};

class Connector
{
   protected:
    ConnConfig m_config;
    bool       m_ready = false;

    // exact match
    // TODO: wildcard
    std::unordered_map<std::string, std::vector<DataHandler>> m_dataHandlers;

    std::unordered_map<MqttEvent, std::vector<EventHandler>> m_eventHandlers;

    /**
     * @brief registers a handler for a topic. call it after a successful subscription
     * @param topic MQTT topic
     * @param handler message handler
     */
    void registerDataHandler(std::string_view topic, DataHandler handler)
    {
        m_dataHandlers[std::string(topic)].emplace_back(std::move(handler));
    }

    void dispatchData(std::string_view topic, std::string_view payload)
    {
        for (auto& handler : m_dataHandlers[std::string(topic)])
        {
            handler(topic, payload);
        }
    }

    void handleEvent(MqttEvent event, const void* eventData)
    {
        switch (event)
        {
            case MqttEvent::CONNECTED:
                m_ready = true;
                break;
            case MqttEvent::DISCONNECTED:
                m_ready = false;
                break;
            case MqttEvent::ERROR:
                m_ready = false;
                break;

            default:
                break;
        }

        for (auto& handler : m_eventHandlers[event])
        {
            handler(eventData);
        }
    }

   public:
    Connector()          = default;
    virtual ~Connector() = default;

    // non-copyable
    Connector(const Connector&)            = delete;
    Connector& operator=(const Connector&) = delete;

    virtual int init(const ConnConfig& config)
    {
        m_config = config;
        return 0;
    }

    bool ready() const { return m_ready; }

    virtual int connect(void)                                                                               = 0;
    virtual int publish(std::string_view topic, std::string_view payload, int qos = 0, bool retain = false) = 0;
    virtual int subscribe(std::string_view topic, DataHandler handler)                                      = 0;

    void registerEventHandler(MqttEvent event, EventHandler handler)
    {
        m_eventHandlers[event].emplace_back(std::move(handler));
    }
};

}  // namespace sensgreen::mqtt
