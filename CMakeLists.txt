
# Collect all .cpp files under src
file(GLOB_RECURSE PRJ_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

idf_component_register(COMPONENT_NAME "sensgreen-connector"
                    SRCS "${PRJ_SOURCES}"
                    INCLUDE_DIRS "include" "include/port/esp32"
                    REQUIRES "nlohmann-json")

target_compile_definitions(${COMPONENT_LIB} PUBLIC SENSGREEN_ESP32=1)
target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)

