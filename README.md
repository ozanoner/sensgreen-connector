![Build and Test](https://github.com/ozanoner/sensgreen-connector/actions/workflows/ci.yml/badge.svg)


# Sensgreen connector for ESP32
Enables ESP32 devices to connect to the Sensgreen IoT platform.   
    
See the examples directory for the library usage.

## Sensgreen platform
Platform login: https://platform.sensgreen.com/   
Help: https://intercom.help/sensgreen-support/en/


# Compatibility

| ESP32 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 | ESP32-P4 |
| --- | --- | --- | --- | --- | --- | --- |
| ✔️ | ✔️ | ✔️ |  | ✔️ | ✔️ |  |

IDF versions: v5.2, v5.3, v5.4

# Basic usage

## Preparing the IDF project
You can prepare your project as the following:

1. Create a new IDF project and add this component
    ```
    $ idf.py create-project my_sensgreen_device
    $ cd my_sensgreen_device
    $ idf.py add-dependency "ozanoner/sensgreen-connector"
    $ idf.py reconfigure
    ```

2.  Rename the source code file to cpp and update the cmake script.
    ```
    $ mv main/my_sensgreen_device.c main/my_sensgreen_device.cpp
    $ vi main/CMakeLists.txt # renaming the source code file name here
    $ cat main/CMakeLists.txt
    idf_component_register(SRCS "my_sensgreen_device.cpp" INCLUDE_DIRS ".")

    ```

## Developing a Sensgreen device
The class hierarchy of in the component is:   
- A Sensgreen device (derived from ```sensgreen::Device```) can have 1 or more sensors (derived from ```sensgreen::SensorBase```)
- A sensor can measure 1 or more metrics (Defined in managed_components/sensgreen-connector/include/sensgreen/metric_types.hpp)

Sensor is the generic name in the IDF component. It can be actually an actuator as well. Similarly, a metric can be read-only or mutable. Therefore, an actuator can change a metric. 


Here is the basic steps to develop a new Sensgreen device:

1. Define a Sensgreen device on the platform and generate MQTT credentials for it to be used in the IDF project as explained here: https://intercom.help/sensgreen-support/en/articles/8516692-connect-a-device-to-sensgreen.

2. Include the header.
    ```
    #include "sensgreen.hpp"
    ```

3. Develop a class for the sensor that your device has (or several sensor classes as many as you need).
    ```
    class TemperatureSensorBrandA : public sensgreen::SensorBase<sensgreen::TemperatureMetric>
    {
    public:
        int read() override
        {
            // read temperature from the physical sensor
            float temperatureValue = 25.0;
            // then update the metric value
            get<sensgreen::TemperatureMetric>().setValue(temperatureValue);
            return 0;
        }
    };
    ```

4. Develop a class for your device.
    ```
    class MyTemperatureDevice : public sensgreen::Device<TemperatureSensorBrandA>
    {
        using sensgreen::Device<TemperatureSensorBrandA>::Device;  // inherit constructors
    };
    ```

5. You can use this device definition in the main app now. Create an instance of your device class.
    ```
    DeviceConfig deviceConfig {DEVICE_UID, MQTT_TOPIC};
    MyTemperatureDevice device {deviceConfig};
    ```

6. Define the Sensgreen platform connection.
    ```
    // class MqttConnector final : public idf::mqtt::Client

    BrokerConfiguration broker {.address  = {idf::mqtt::URI {std::string {CONFIG_BROKER_URL}}},
                                .security = idf::mqtt::Insecure {}};
    ClientCredentials   credentials {.username = MQTT_USER, .authentication = idf::mqtt::Password {MQTT_PASS}};
    Configuration       config {};
    app::MqttConnector  connector {broker, credentials, config};
    ```

7. Register a function to publish device data to the Sensgreen platform when connected.
    ```
    connector.registerConnectedHandler(
        []()
        {
            const auto& report = device.report().dump();

            if (auto messId = connector.publish(deviceConfig.topicData, idf::mqtt::Message<std::string> {report}))
            {
                ESP_LOGI(TAG, "publish success, message ID: %d", static_cast<int>(*messId));
            }
        });
    ```

8. You can observe the device data on the Sensgreen platform.

You can see the example projects that come with the IDF component for more (managed_components/sensgreen-connector/examples). 

# Credits

    
# Contributing

All contributions are welcome!

Style guide: https://github.com/QuantumLeaps/embedded-coding-style/blob/main/README.md

Quick style reference:
- Header files extension is hpp
- Source files extension is cpp
- File names in snake notation (my_class.hpp)
- Type names in Pascal notation (MyClass)
- Functions/vars in camel notation (myVar)
- Some prefixes
    - m_ for class/struct member vars (m_deviceName)