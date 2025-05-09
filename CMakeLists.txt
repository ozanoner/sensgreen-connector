idf_component_register(COMPONENT_NAME "sensgreen-connector"
                    SRCS "src/esp32_mqtt_connector.cpp"
                    INCLUDE_DIRS "include" "include/port/esp32"
                    REQUIRES "esp_event" "mqtt" "nlohmann-json")

target_compile_definitions(${COMPONENT_LIB} PUBLIC SENSGREEN_ESP32=1)
target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)

