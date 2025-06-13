# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS ../..)

if(EXISTS "${CMAKE_SOURCE_DIR}/build_secrets.cmake")
    include(${CMAKE_SOURCE_DIR}/build_secrets.cmake)
endif()

# Export as compile definitions
add_compile_definitions(
    MQTT_USER="${SECRETS_MQTT_USER}"
    MQTT_PASS="${SECRETS_MQTT_PASS}"
    MQTT_HOST="${SECRETS_MQTT_HOST}"
    MQTT_PORT="${SECRETS_MQTT_PORT}"
    MQTT_TOPIC="${SECRETS_MQTT_TOPIC}"
    DEVICE_UID="${SECRETS_DEVICE_UID}"
)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32_ex)
