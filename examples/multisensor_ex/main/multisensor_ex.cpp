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
#include "sensgreen.hpp"

#define TAG (TAG_STR.data())

using sensgreen::device::DeviceConfig;
using sensgreen::mqtt::ConnConfig;
using sensgreen::mqtt::MqttEvent;
using sensgreen::mqtt::esp32::Esp32MqttConnector;

namespace
{
DeviceConfig  deviceConfig {DEVICE_UID, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC};
app::MyDevice device {deviceConfig};
auto&         connector = Esp32MqttConnector::instance();
TaskHandle_t  publishTaskHandle {nullptr};

constexpr std::string_view NTP_SERVER {"pool.ntp.org"};
constexpr std::string_view TAG_STR {"app"};

void timeSynced(struct timeval* tv)
{
    ESP_LOGI(TAG, "Time synced");

    esp_err_t err = connector.connect();

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "mqtt-client started");
    }
    else
    {
        ESP_LOGE(TAG, "mqtt-client failed to start (%s)", esp_err_to_name(err));
    }
}

void publishTask(void* pvParameters)
{
    while (true)
    {
        device.readAllSensors();

        const auto& report = device.report();
        ESP_LOGI(TAG, "%s", report.dump().c_str());

        esp_err_t err = (esp_err_t)connector.publish(deviceConfig.topicData, report.dump());
        if (ESP_OK != err)
        {
            ESP_LOGE(TAG, "publish failed (%s)", esp_err_to_name(err));
        }

        vTaskDelay(pdMS_TO_TICKS(60000));  // Delay for a minute
    }
}

}  // namespace

extern "C" void app_main(void)
{
    // ESP_LOGI(TAG, "config:\nmqtt_host='%s'\nmqtt_port='%s'\nmqtt_user='%s'\nmqtt_pass='%s'\n", MQTT_HOST, MQTT_PORT,
    //          MQTT_USER, MQTT_PASS);

    // Initialise MQTT connector
    ConnConfig config {MQTT_HOST, static_cast<int16_t>(std::stoi(MQTT_PORT)), MQTT_USER, MQTT_PASS};
    ESP_ERROR_CHECK(connector.init(config));

    // register a connected handler. the wokwi test is here.
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

    connector.registerEventHandler(MqttEvent::DISCONNECTED,
                                   [](const void*)
                                   {
                                       if (nullptr != publishTaskHandle)
                                       {
                                           vTaskSuspend(publishTaskHandle);
                                       }
                                   });

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

    // initialise device
    ESP_ERROR_CHECK(device.boardInit());

    // connect wifi
    ESP_ERROR_CHECK(example_connect());

    // start SNTP
    ESP_ERROR_CHECK(esp_netif_sntp_start());
}
