# ESP32 Example Application

This example demonstrates the use of the Sensgreen connector library with an ESP32 device. The primary goal is to test the library functionality using Wokwi, a virtual hardware simulator.

## Features

- Connects an ESP32 device to the Sensgreen IoT platform.
- Publishes sensor data to the platform using MQTT.
- Simulates sensor data reading in a virtual environment (Wokwi).

## Prerequisites

- [Wokwi](https://wokwi.com) account
- Sensgreen platform account with generated MQTT credentials

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/ozanoner/sensgreen-connector.git
    cd sensgreen-connector/examples/esp32_ex
    ```

2. **Configure the Project:**

    You can update the configuration by running this:
    ```bash
    idf.py menuconfig
    ```
    
    `sdkconfig.defaults` has the following:

    ```plaintext
    CONFIG_EXAMPLE_WIFI_SSID="Wokwi-GUEST"
    CONFIG_EXAMPLE_WIFI_PASSWORD=""
    CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT=y
    CONFIG_LWIP_DHCP_GET_NTP_SRV=y
    ```

3. **Build the Project:**

    Use the ESP-IDF build system to compile the project.

    ```bash
    idf.py build
    ```

4. **Run on Wokwi:**

    Click on the `diagram.json` file. The Wokwi extension will start.

5. **Observe Outputs:**

    - The device will attempt to connect to Wi-Fi with the specified SSID.
    - Once connected, it will publish data to the Sensgreen platform using MQTT.
    - Check the Wokwi serial monitor for logs and the Sensgreen platform for published data.

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.

## Contributing

All contributions are welcome! Please follow the project's [style guide](https://github.com/QuantumLeaps/embedded-coding-style/blob/main/README.md) for consistency.

For any issues, please create an issue on our [GitHub page](https://github.com/ozanoner/sensgreen-connector/issues).
