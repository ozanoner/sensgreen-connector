/**
 * @file esp32_ex.cpp
 * @brief Tests the library with Wokwi
 * @version 0.1
 * @date 2025-05-12
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
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "protocol_examples_utils.h"
#include "sensgreen.hpp"
#include "temperature_device.hpp"

#define TAG (TAG_STR.data())

using sensgreen::common::mqtt::ConnConfig;
using sensgreen::device::DeviceConfig;
using sensgreen::port::mqtt::Esp32MqttConnector;

namespace
{
DeviceConfig               deviceConfig {DEVICE_UID, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC};
app::MyTemperatureDevice   device {deviceConfig};
constexpr std::string_view NTP_SERVER {"pool.ntp.org"};
constexpr std::string_view TAG_STR {"app"};

void wifiConnectedHandler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    ESP_LOGI(TAG, "WiFi connected");
}

void timeSynced(struct timeval* tv)
{
    ESP_LOGI(TAG, "Time synced");

    esp_err_t err = Esp32MqttConnector::instance().connect();

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "mqtt-client started");
    }
    else
    {
        ESP_LOGE(TAG, "mqtt-client failed to start (%s)", esp_err_to_name(err));
    }
}

}  // namespace

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "config:\nmqtt_host='%s'\nmqtt_port='%s'\nmqtt_user='%s'\nmqtt_pass='%s'\n", MQTT_HOST, MQTT_PORT,
             MQTT_USER, MQTT_PASS);

    ConnConfig config {MQTT_HOST, static_cast<int16_t>(std::stoi(MQTT_PORT)), MQTT_USER, MQTT_PASS};
    ESP_ERROR_CHECK(Esp32MqttConnector::instance().init(config));

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifiConnectedHandler, nullptr));

    esp_sntp_config_t sntpConfig          = ESP_NETIF_SNTP_DEFAULT_CONFIG(NTP_SERVER.data());
    sntpConfig.start                      = false;
    sntpConfig.server_from_dhcp           = true;
    sntpConfig.renew_servers_after_new_IP = true;
    sntpConfig.index_of_first_server      = 1;
    sntpConfig.ip_event_to_renew          = IP_EVENT_STA_GOT_IP;
    sntpConfig.sync_cb                    = timeSynced;
    ESP_ERROR_CHECK(esp_netif_sntp_init(&sntpConfig));

    ESP_ERROR_CHECK(example_connect());
    ESP_ERROR_CHECK(esp_netif_sntp_start());
}
