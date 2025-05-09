#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "protocol_examples_utils.h"
#include "sensgreen.hpp"
#include "temperature_device.hpp"

using sensgreen::common::mqtt::ConnConfig;
using sensgreen::device::DeviceConfig;
using sensgreen::port::mqtt::Esp32MqttConnector;

namespace
{
DeviceConfig             deviceConfig {DEVICE_UID, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC, MQTT_TOPIC};
app::MyTemperatureDevice device {deviceConfig};

static void wifiConnectedHandler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    ESP_LOGI("MQTT", "WiFi connected");

    esp_err_t err = Esp32MqttConnector::instance().connect();

    if (err == ESP_OK)
    {
        ESP_LOGI("MQTT", "mqtt-client started");
    }
    else
    {
        ESP_LOGE("MQTT", "mqtt-client failed to start (%s)", esp_err_to_name(err));
    }
}

}  // namespace

extern "C" void app_main(void)
{
    ESP_LOGI("main", "config:\nmqtt_host='%s'\nmqtt_port='%s'\nmqtt_user='%s'\nmqtt_pass='%s'\n", MQTT_HOST, MQTT_PORT,
             MQTT_USER, MQTT_PASS);

    ConnConfig config {MQTT_HOST, static_cast<int16_t>(std::stoi(MQTT_PORT)), MQTT_USER, MQTT_PASS};
    ESP_ERROR_CHECK(Esp32MqttConnector::instance().init(config));

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifiConnectedHandler, nullptr));

    ESP_ERROR_CHECK(example_connect());
    // ESP_LOGI("main", "any web server online");
}
