
# Collect all .cpp files under src/esp32 (non-recursive)
file(GLOB_RECURSE SENSGREEN_SRCS
     "${CMAKE_CURRENT_LIST_DIR}/src/esp32/*.cpp"
)

idf_component_register(COMPONENT_NAME "sensgreen-connector"
                    SRCS "${SENSGREEN_SRCS}"
                    INCLUDE_DIRS "include" "include/port/esp32"
                    REQUIRES "esp_event" "mqtt" "nlohmann-json")

target_compile_definitions(${COMPONENT_LIB} PUBLIC SENSGREEN_ESP32=1)
target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)

