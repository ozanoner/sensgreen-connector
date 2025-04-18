idf_component_register(SRCS "src/esp32_mqtt_connector.cpp"
                    INCLUDE_DIRS "include" "include/port/esp32" "components/json/single_include"
                    REQUIRES mqtt)

target_compile_definitions(${COMPONENT_LIB} PRIVATE SENSGREEN_ESP32=1)
target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)

