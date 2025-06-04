# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# set(IDF_TARGET "esp32c6")
set(EXTRA_COMPONENT_DIRS 
    ../.. 
    $ENV{IDF_PATH}/examples/common_components/protocol_examples_common
    ./extra_components/esp-iot-solution/components/sensors/light_sensor/bh1750
    ./extra_components/esp-iot-solution/components/sensors/pressure/bme280
    ./extra_components/esp-iot-solution/components/led/led_indicator)

set(SDKCONFIG_DEFAULTS "sdkconfig.defaults;sdkconfig.user")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(multisensor_ex)

