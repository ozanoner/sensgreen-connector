/**
 * @file multisensor_ex.cpp
 * @brief Multisensor example
 * @version 0.1
 * @date 2025-05-30
 * @copyright Copyright (c) 2025
 */

#include <string_view>

#include "esp_event.h"
#include "esp_log.h"
#include "esp_mqtt_client_config.hpp"
#include "esp_netif_sntp.h"
#include "esp_sntp.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "lwip/ip_addr.h"
#include "mqtt_connector.hpp"
#include "multisensor_device.hpp"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "protocol_examples_utils.h"
#include "sdkconfig.h"
#include "sensgreen.hpp"

using idf::mqtt::BrokerConfiguration;
using idf::mqtt::ClientCredentials;
using idf::mqtt::Configuration;
using sensgreen::DeviceConfig;

#define CONFIG_BROKER_URL (CONFIG_MQTT_HOST ":" CONFIG_MQTT_PORT)

namespace
{
constexpr auto TAG = "app";

DeviceConfig  deviceConfig {CONFIG_DEVICE_UID, CONFIG_MQTT_TOPIC, CONFIG_MQTT_TOPIC, CONFIG_MQTT_TOPIC,
                           CONFIG_MQTT_TOPIC};
app::MyDevice device {deviceConfig};

BrokerConfiguration broker {.address  = {idf::mqtt::URI {std::string {CONFIG_BROKER_URL}}},
                            .security = idf::mqtt::Insecure {}};
ClientCredentials  credentials {.username = CONFIG_MQTT_USER, .authentication = idf::mqtt::Password {CONFIG_MQTT_PASS}};
Configuration      config {};
app::MqttConnector connector {broker, credentials, config};

constexpr std::string_view NTP_SERVER {"pool.ntp.org"};

void timeSynced(struct timeval* tv)
{
    try
    {
        connector.start();
        PRINT_LOC("mqtt connected");
    }
    catch (...)
    {
        PRINT_LOC_E("mqtt-connect failed");
    }
}

void publishTask(void* pvParameters)
{
    constexpr uint32_t periodMs = CONFIG_MQTT_PUBLISH_PERIOD_MINUTES * 60ul * 1000;
    while (true)
    {
        device.readAllSensors();

        const auto report = device.report().dump();
        PRINT_LOC("%s", report.c_str());

        if (!connector.publish(deviceConfig.topicData, idf::mqtt::Message<std::string> {report}))
        {
            PRINT_LOC_E("publish failed");
        }

        vTaskDelay(pdMS_TO_TICKS(periodMs));  // Delay for a minute
    }
}

}  // namespace

extern "C" void app_main(void)
{
    // various initialisations
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // initialise SNTP
    esp_sntp_config_t sntpConfig          = ESP_NETIF_SNTP_DEFAULT_CONFIG(NTP_SERVER.data());
    sntpConfig.start                      = false;
    sntpConfig.server_from_dhcp           = true;
    sntpConfig.renew_servers_after_new_IP = true;
    sntpConfig.index_of_first_server      = 1;
    sntpConfig.ip_event_to_renew          = IP_EVENT_STA_GOT_IP;
    sntpConfig.sync_cb                    = timeSynced;
    ESP_ERROR_CHECK(esp_netif_sntp_init(&sntpConfig));

    // Start the publish task when MQTT is connected
    connector.registerPublishTask(publishTask);

    // initialise device
    ESP_ERROR_CHECK(device.init());

    // connect wifi
    ESP_ERROR_CHECK(example_connect());

    // start SNTP
    ESP_ERROR_CHECK(esp_netif_sntp_start());
}
