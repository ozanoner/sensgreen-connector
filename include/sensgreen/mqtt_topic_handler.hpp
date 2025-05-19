
#pragma once

#include <string_view>

#include "mqtt_topic_buffer.hpp"

// NOTE: update when wildcard topic is implemented https://github.com/ozanoner/sensgreen-connector/issues/10

namespace sensgreen::mqtt
{

template <typename BufferT>
class MqttTopicHandler
{
   public:
    MqttTopicHandler(std::string_view topic, BufferT& buffer)
        : m_topic(topic), m_lastMessageId(-1), m_totalDataLen(0), m_receivedData(0), m_buffer(buffer)
    {
    }
    virtual ~MqttTopicHandler() = default;

    // Disable copy
    MqttTopicHandler(const MqttTopicHandler&)            = delete;
    MqttTopicHandler& operator=(const MqttTopicHandler&) = delete;

    /**
     * @brief handles an incoming MQTT message, buffering the data
     * @param topic the MQTT topic
     * @param payload the message payload
     * @param messageId the message ID
     * @param currentDataOffset the offset of the message in the MQTT message
     * @param totalDataLen the total length of the MQTT message
     * @return
     *  0 if the message is incomplete,
     * -1 if the message length changed,
     * -2 if the message ID is the same as the last one,
     *  or the result of finish() when the message is complete
     *  or the result of m_buffer.save()
     */
    int handleData(std::string_view topic, std::string_view payload, int messageId, size_t currentDataOffset,
                   size_t totalDataLen)
    {
        if (messageId == m_lastMessageId)
        {
            if (m_totalDataLen != totalDataLen)
            {
                // data length changed in the middle
                return -1;
            }

            if (m_receivedData == m_totalDataLen)
            {
                // data already received, messageId should be a new one
                return -2;
            }
        }
        else
        {
            // reset for new incoming data
            m_lastMessageId = messageId;
            m_totalDataLen  = totalDataLen;
            m_receivedData  = 0;
            m_buffer.reset();
        }

        int ret = m_buffer.save(payload, (int)currentDataOffset);

        if (ret == 0)
        {
            m_receivedData += payload.size();

            if (m_receivedData == m_totalDataLen)
            {
                return finish();
            }
        }

        return ret;
    }

    virtual int finish(void) = 0;

   protected:
    std::string_view m_topic;
    int              m_lastMessageId;
    size_t           m_totalDataLen;
    size_t           m_receivedData;

    BufferT& m_buffer;
};
}  // namespace sensgreen::mqtt