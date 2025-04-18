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

// the namespace common is shared across ports
namespace sensgreen::common::mqtt
{
using MessageHandler = std::function<void(const std::string_view topic, const std::string_view payload)>;

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
    std::unordered_map<std::string, std::vector<MessageHandler>> m_topicHandlers;

    /**
     * @brief registers a handler for a topic. call it after a successful subscription
     * @param topic MQTT topic
     * @param handler message handler
     */
    void registerHandler(std::string_view topic, MessageHandler handler)
    {
        m_topicHandlers[std::string(topic)].emplace_back(std::move(handler));
    }

    void dispatchMessage(std::string_view topic, std::string_view payload)
    {
        for (auto& handler : m_topicHandlers[std::string(topic)])
        {
            handler(topic, payload);
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
    virtual int publish(std::string_view topic, std::string_view payload, int qos = 1, bool retain = false) = 0;
    virtual int subscribe(std::string_view topic, MessageHandler handler)                                   = 0;
};

}  // namespace sensgreen::common::mqtt
