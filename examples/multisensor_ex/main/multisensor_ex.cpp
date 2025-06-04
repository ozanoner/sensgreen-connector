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
#include "esp_netif_sntp.h"
#include "esp_sntp.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "lwip/ip_addr.h"
#include "multisensor_device.hpp"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "protocol_examples_utils.h"
#include "sdkconfig.h"
#include "sensgreen.hpp"

using sensgreen::device::DeviceConfig;
using sensgreen::mqtt::ConnConfig;
using sensgreen::mqtt::MqttEvent;
using sensgreen::mqtt::esp32::Esp32MqttConnector;

namespace
{
constexpr auto TAG = "app";

DeviceConfig  deviceConfig {CONFIG_DEVICE_UID, CONFIG_MQTT_TOPIC, CONFIG_MQTT_TOPIC, CONFIG_MQTT_TOPIC,
                           CONFIG_MQTT_TOPIC};
app::MyDevice device {deviceConfig};
auto&         connector = Esp32MqttConnector::instance();
TaskHandle_t  publishTaskHandle {nullptr};

constexpr std::string_view NTP_SERVER {"pool.ntp.org"};

void timeSynced(struct timeval* tv)
{
    esp_err_t err = connector.connect();
    PRINT_IF_ERR(err, "mqtt-connect failed");
    PRINT_IF_SUCC(err, "mqtt-client started");
}

void publishTask(void* pvParameters)
{
    uint32_t periodMs = CONFIG_MQTT_PUBLISH_PERIOD_MINUTES * 60ul * 1000;
    while (true)
    {
        device.readAllSensors();

        const auto& report = device.report();
        auto        jstr   = report.dump();
        PRINT_LOC(jstr.c_str());

        esp_err_t err = (esp_err_t)connector.publish(deviceConfig.topicData, jstr);
        PRINT_IF_ERR(err, "publish failed");

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

    // Initialise MQTT connector
    ConnConfig config {CONFIG_MQTT_HOST, static_cast<int16_t>(std::stoi(CONFIG_MQTT_PORT)), CONFIG_MQTT_USER,
                       CONFIG_MQTT_PASS};
    ESP_ERROR_CHECK(connector.init(config));

    // Start the publish task when MQTT is connected
    connector.registerEventHandler(MqttEvent::CONNECTED,
                                   [](const void*)
                                   {
                                       if (nullptr == publishTaskHandle)
                                       {  // Create the FreeRTOS task
                                           xTaskCreate(publishTask, "publish-task", 2048, nullptr, tskIDLE_PRIORITY + 1,
                                                       &publishTaskHandle);
                                       }
                                       else
                                       {
                                           vTaskResume(publishTaskHandle);
                                       }
                                   });

    // Stop the publish task when MQTT is disconnected
    connector.registerEventHandler(MqttEvent::DISCONNECTED,
                                   [](const void*)
                                   {
                                       if (nullptr != publishTaskHandle)
                                       {
                                           vTaskSuspend(publishTaskHandle);
                                       }
                                   });

    // initialise device
    ESP_ERROR_CHECK(device.init());

    // connect wifi
    ESP_ERROR_CHECK(example_connect());

    // start SNTP
    ESP_ERROR_CHECK(esp_netif_sntp_start());
}
