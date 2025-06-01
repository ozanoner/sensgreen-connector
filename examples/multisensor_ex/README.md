# Multi-sensor Example

This project demonstrates the use of multiple sensors integrated into a single device using an ESP32-C6 microcontroller. The sensors included in this example are a light sensor (BH1750) and a pressure sensor (BME280).

## Prerequisites

- ESP32-C6 development kit
- ESP-IDF environment set up
- Required hardware components: BH1750 light sensor, BME280 pressure sensor

## Getting Started

### Hardware Setup

- **BH1750 Light Sensor**: Measures ambient light levels.
- **BME280 Pressure Sensor**: Measures atmospheric pressure, temperature, and humidity.

| ESP32-C6 | BME280 | BH1750 |
|----------| -------|--------|
| 3.3V     | VCC    | VCC    |
| GND      | GND    | GND    |
| GPIO21   | SDA    | SDA    |
| GPIO22   | SCL    | SCL    |
| GND      | SDO    |        |

### Software Setup

1. Clone the repository containing this example.
2. Navigate to the `examples/multisensor_ex` directory.
3. Update the submodule(s).

   ```bash
   git submodule update --init --recursive
   ```

4. Add `build_secrets.cmake` in the project root and set the values for your device:

   ```file
    set(SECRETS_MQTT_USER     "sensgreen-mqtt-user"         CACHE INTERNAL "")
    set(SECRETS_MQTT_PASS     "sensgreen-mqtt-password"     CACHE INTERNAL "")
    set(SECRETS_MQTT_HOST     "sensgreen-broker-address"    CACHE INTERNAL "")
    set(SECRETS_MQTT_PORT     "mqtt port"                   CACHE INTERNAL "")
    set(SECRETS_MQTT_TOPIC    "sensgreen-mqtt-topic"        CACHE INTERNAL "")
    set(SECRETS_DEVICE_UID    "sensgreen-device-id"         CACHE INTERNAL "")
   ```

5. Set the WiFi SSID and password in `(Top) → Example Connection Configuration` by running menuconfig:

   ```bash
   idf.py menuconfig
   ```

6. Monitor the serial output to view the sensor readings:

   ```bash
   idf.py flash monitor --print-filter="app MQTT" -p /dev/ttyACM0
   ```

7. You should observe a similar output to the following on the serial console:
   ```output
   --- esp-idf-monitor 1.6.0 on /dev/ttyACM0 115200
   --- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
   --- Print filter: "app MQTT"
   I (12218) app: [timeSynced,48] mqtt-client started
   I (12698) app: [publishTask,59] {"data":{"humidity":53.419921875,"light":63.33333206176758,"pressure":1010.489990234375,"temperature":25.489999771118164},"deviceEui":"1231231234","timestamp":1748820388730}
   I (12708) MQTT: publishing to topic 'sensor/data/925878', data '{"data":{"humidity":53.419921875,"light":63.33333206176758,"pressure":1010.489990234375,"temperature":25.489999771118164},"deviceEui":"1231231234","timestamp":1748820388730}'
   I (12748) MQTT: msg_id=15511
   ```


## License

This project is licensed under the MIT License. See the `LICENSE` file for details.


## References
- Devkit: https://www.waveshare.com/wiki/ESP32-C6-Zero
- BH1750: https://esphome.io/components/sensor/bh1750.html
- BME280 (I2C): https://esphome.io/components/sensor/bme280.html