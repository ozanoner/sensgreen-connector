/**
 * @file metric_types.hpp
 * @brief Metric type definitions
 * @version 0.1
 * @date 2025-06-04
 * @copyright Copyright (c) 2025
 */

#pragma once

#include <string_view>

#include "metric_base.hpp"

namespace sensgreen::device
{

// ---------- Auto-generated metric tag definitions ----------

// 1. temperature (°C, real, false)
struct TemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using TemperatureMetric = MetricBase<float, TemperatureReadOnlyTag>;

// 2. humidity (% , percentage, false)
struct HumidityReadOnlyTag
{
    static constexpr std::string_view name           = "humidity";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using HumidityMetric = MetricBase<float, HumidityReadOnlyTag>;

// 3. pressure (Pa, positive, false)
struct PressureReadOnlyTag
{
    static constexpr std::string_view name           = "pressure";
    static constexpr std::string_view unit           = "Pa";
    static constexpr bool             isControllable = false;
};
using PressureMetric = MetricBase<float, PressureReadOnlyTag>;

// 4. co2 (ppm, positive, false)
struct Co2ReadOnlyTag
{
    static constexpr std::string_view name           = "co2";
    static constexpr std::string_view unit           = "ppm";
    static constexpr bool             isControllable = false;
};
using Co2Metric = MetricBase<float, Co2ReadOnlyTag>;

// 5. voc (mg/m³, positive, false)
struct VocReadOnlyTag
{
    static constexpr std::string_view name           = "voc";
    static constexpr std::string_view unit           = "mg/m³";
    static constexpr bool             isControllable = false;
};
using VocMetric = MetricBase<float, VocReadOnlyTag>;

// 6. pm1 (μg/m³, positive, false)
struct Pm1ReadOnlyTag
{
    static constexpr std::string_view name           = "pm1";
    static constexpr std::string_view unit           = "μg/m³";
    static constexpr bool             isControllable = false;
};
using Pm1Metric = MetricBase<float, Pm1ReadOnlyTag>;

// 7. pm25 (μg/m³, positive, false)
struct Pm25ReadOnlyTag
{
    static constexpr std::string_view name           = "pm25";
    static constexpr std::string_view unit           = "μg/m³";
    static constexpr bool             isControllable = false;
};
using Pm25Metric = MetricBase<float, Pm25ReadOnlyTag>;

// 8. pm4 (μg/m³, positive, false)
struct Pm4ReadOnlyTag
{
    static constexpr std::string_view name           = "pm4";
    static constexpr std::string_view unit           = "μg/m³";
    static constexpr bool             isControllable = false;
};
using Pm4Metric = MetricBase<float, Pm4ReadOnlyTag>;

// 9. pm10 (μg/m³, positive, false)
struct Pm10ReadOnlyTag
{
    static constexpr std::string_view name           = "pm10";
    static constexpr std::string_view unit           = "μg/m³";
    static constexpr bool             isControllable = false;
};
using Pm10Metric = MetricBase<float, Pm10ReadOnlyTag>;

// 10. dew_point (°C, real, false)
struct DewPointReadOnlyTag
{
    static constexpr std::string_view name           = "dew_point";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using DewPointMetric = MetricBase<float, DewPointReadOnlyTag>;

// 11. iaq ( , aqi, false)
struct IaqReadOnlyTag
{
    static constexpr std::string_view name           = "iaq";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using IaqMetric = MetricBase<float, IaqReadOnlyTag>;

// 12. p_size (μm, positive, false)
struct PSizeReadOnlyTag
{
    static constexpr std::string_view name           = "p_size";
    static constexpr std::string_view unit           = "μm";
    static constexpr bool             isControllable = false;
};
using PSizeMetric = MetricBase<float, PSizeReadOnlyTag>;

// 13. current (A, real, false)
struct CurrentReadOnlyTag
{
    static constexpr std::string_view name           = "current";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using CurrentMetric = MetricBase<float, CurrentReadOnlyTag>;

// 14. power (kWh, real, false)
struct PowerReadOnlyTag
{
    static constexpr std::string_view name           = "power";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using PowerMetric = MetricBase<float, PowerReadOnlyTag>;

// 15. occupancy ( , boolean, false)
struct OccupancyReadOnlyTag
{
    static constexpr std::string_view name           = "occupancy";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using OccupancyMetric = MetricBase<bool, OccupancyReadOnlyTag>;

// 16. opened ( , boolean, false)
struct OpenedReadOnlyTag
{
    static constexpr std::string_view name           = "opened";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using OpenedMetric = MetricBase<bool, OpenedReadOnlyTag>;

// 17. battery (V, positive, false)
struct BatteryReadOnlyTag
{
    static constexpr std::string_view name           = "battery";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using BatteryMetric = MetricBase<float, BatteryReadOnlyTag>;

// 18. mounted ( , boolean, false)
struct MountedReadOnlyTag
{
    static constexpr std::string_view name           = "mounted";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using MountedMetric = MetricBase<bool, MountedReadOnlyTag>;

// 19. peak_current (A, real, false)
struct PeakCurrentReadOnlyTag
{
    static constexpr std::string_view name           = "peak_current";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using PeakCurrentMetric = MetricBase<float, PeakCurrentReadOnlyTag>;

// 20. sound_level (dB, positive, false)
struct SoundLevelReadOnlyTag
{
    static constexpr std::string_view name           = "sound_level";
    static constexpr std::string_view unit           = "dB";
    static constexpr bool             isControllable = false;
};
using SoundLevelMetric = MetricBase<float, SoundLevelReadOnlyTag>;

// 21. people_count ( , real, false)
struct PeopleCountReadOnlyTag
{
    static constexpr std::string_view name           = "people_count";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PeopleCountMetric = MetricBase<float, PeopleCountReadOnlyTag>;

// 22. people_max ( , real, false)
struct PeopleMaxReadOnlyTag
{
    static constexpr std::string_view name           = "people_max";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PeopleMaxMetric = MetricBase<float, PeopleMaxReadOnlyTag>;

// 23. no2 (ppm, real, false)
struct No2ReadOnlyTag
{
    static constexpr std::string_view name           = "no2";
    static constexpr std::string_view unit           = "ppm";
    static constexpr bool             isControllable = false;
};
using No2Metric = MetricBase<float, No2ReadOnlyTag>;

// 24. co (ppm, real, false)
struct CoReadOnlyTag
{
    static constexpr std::string_view name           = "co";
    static constexpr std::string_view unit           = "ppm";
    static constexpr bool             isControllable = false;
};
using CoMetric = MetricBase<float, CoReadOnlyTag>;

// 25. o3 (ppm, real, false)
struct O3ReadOnlyTag
{
    static constexpr std::string_view name           = "o3";
    static constexpr std::string_view unit           = "ppm";
    static constexpr bool             isControllable = false;
};
using O3Metric = MetricBase<float, O3ReadOnlyTag>;

// 26. voltage_rms_1 (V, real, false)
struct VoltageRms1ReadOnlyTag
{
    static constexpr std::string_view name           = "voltage_rms_1";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using VoltageRms1Metric = MetricBase<float, VoltageRms1ReadOnlyTag>;

// 27. current_rms_1 (A, real, false)
struct CurrentRms1ReadOnlyTag
{
    static constexpr std::string_view name           = "current_rms_1";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using CurrentRms1Metric = MetricBase<float, CurrentRms1ReadOnlyTag>;

// 28. voltage_rms_2 (V, real, false)
struct VoltageRms2ReadOnlyTag
{
    static constexpr std::string_view name           = "voltage_rms_2";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using VoltageRms2Metric = MetricBase<float, VoltageRms2ReadOnlyTag>;

// 29. current_rms_2 (A, real, false)
struct CurrentRms2ReadOnlyTag
{
    static constexpr std::string_view name           = "current_rms_2";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using CurrentRms2Metric = MetricBase<float, CurrentRms2ReadOnlyTag>;

// 30. voltage_rms_3 (V, real, false)
struct VoltageRms3ReadOnlyTag
{
    static constexpr std::string_view name           = "voltage_rms_3";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using VoltageRms3Metric = MetricBase<float, VoltageRms3ReadOnlyTag>;

// 31. current_rms_3 (A, real, false)
struct CurrentRms3ReadOnlyTag
{
    static constexpr std::string_view name           = "current_rms_3";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using CurrentRms3Metric = MetricBase<float, CurrentRms3ReadOnlyTag>;

// 32. temperature_probe (°C, real, false)
struct TemperatureProbeReadOnlyTag
{
    static constexpr std::string_view name           = "temperature_probe";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using TemperatureProbeMetric = MetricBase<float, TemperatureProbeReadOnlyTag>;

// 33. power_factor_1 ( , real, false)
struct PowerFactor1ReadOnlyTag
{
    static constexpr std::string_view name           = "power_factor_1";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PowerFactor1Metric = MetricBase<float, PowerFactor1ReadOnlyTag>;

// 34. power_factor_2 ( , real, false)
struct PowerFactor2ReadOnlyTag
{
    static constexpr std::string_view name           = "power_factor_2";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PowerFactor2Metric = MetricBase<float, PowerFactor2ReadOnlyTag>;

// 35. power_factor_3 ( , real, false)
struct PowerFactor3ReadOnlyTag
{
    static constexpr std::string_view name           = "power_factor_3";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PowerFactor3Metric = MetricBase<float, PowerFactor3ReadOnlyTag>;

// 36. virus_index ( , positive, false)
struct VirusIndexReadOnlyTag
{
    static constexpr std::string_view name           = "virus_index";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using VirusIndexMetric = MetricBase<float, VirusIndexReadOnlyTag>;

// 37. water_leak ( , boolean, false)
struct WaterLeakReadOnlyTag
{
    static constexpr std::string_view name           = "water_leak";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using WaterLeakMetric = MetricBase<bool, WaterLeakReadOnlyTag>;

// 38. status ( , boolean, true)
struct StatusControlTag
{
    static constexpr std::string_view name           = "status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = true;
};
using StatusMetric = MetricBase<bool, StatusControlTag>;

// 39. power_factor ( , real, false)
struct PowerFactorReadOnlyTag
{
    static constexpr std::string_view name           = "power_factor";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PowerFactorMetric = MetricBase<float, PowerFactorReadOnlyTag>;

// 40. power_cut ( , boolean, false)
struct PowerCutReadOnlyTag
{
    static constexpr std::string_view name           = "power_cut";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PowerCutMetric = MetricBase<bool, PowerCutReadOnlyTag>;

// 41. voltage (V, real, false)
struct VoltageReadOnlyTag
{
    static constexpr std::string_view name           = "voltage";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using VoltageMetric = MetricBase<float, VoltageReadOnlyTag>;

// 42. watering_spikes ( , boolean, false)
struct WateringSpikesReadOnlyTag
{
    static constexpr std::string_view name           = "watering_spikes";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using WateringSpikesMetric = MetricBase<bool, WateringSpikesReadOnlyTag>;

// 43. water_level_percentage ( , percentage, false)
struct WaterLevelPercentageReadOnlyTag
{
    static constexpr std::string_view name           = "water_level_percentage";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using WaterLevelPercentageMetric = MetricBase<float, WaterLevelPercentageReadOnlyTag>;

// 44. water_level_millimeters ( , positive, false)
struct WaterLevelMillimetersReadOnlyTag
{
    static constexpr std::string_view name           = "water_level_millimeters";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using WaterLevelMillimetersMetric = MetricBase<float, WaterLevelMillimetersReadOnlyTag>;

// 45. daylight ( , boolean, false)
struct DaylightReadOnlyTag
{
    static constexpr std::string_view name           = "daylight";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using DaylightMetric = MetricBase<bool, DaylightReadOnlyTag>;

// 46. chn_1 through chn_16 ( , various, false)
// For channel metrics (chn_1 … chn_16), we need a single generic template or sixteen separate tags.
// Assuming each channel metric is a float and not controllable:
#define DEFINE_CHN_TAG(N)                                             \
    struct Chn##N##ReadOnlyTag                                        \
    {                                                                 \
        static constexpr std::string_view name           = "chn_" #N; \
        static constexpr std::string_view unit           = "";        \
        static constexpr bool             isControllable = false;     \
    };                                                                \
    using Chn##N##Metric = MetricBase<float, Chn##N##ReadOnlyTag>;

DEFINE_CHN_TAG(1)
DEFINE_CHN_TAG(2)
DEFINE_CHN_TAG(3)
DEFINE_CHN_TAG(4)
DEFINE_CHN_TAG(5)
DEFINE_CHN_TAG(6)
DEFINE_CHN_TAG(7)
DEFINE_CHN_TAG(8)
DEFINE_CHN_TAG(9)
DEFINE_CHN_TAG(10)
DEFINE_CHN_TAG(11)
DEFINE_CHN_TAG(12)
DEFINE_CHN_TAG(13)
DEFINE_CHN_TAG(14)
DEFINE_CHN_TAG(15)
DEFINE_CHN_TAG(16)
#undef DEFINE_CHN_TAG

// 47. RemoteWaterTemperature (°C, real, false)
struct RemoteWaterTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "RemoteWaterTemperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using RemoteWaterTemperatureMetric = MetricBase<float, RemoteWaterTemperatureReadOnlyTag>;

// 48. FlowBodyWaterTemperature (°C, real, false)
struct FlowBodyWaterTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "FlowBodyWaterTemperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using FlowBodyWaterTemperatureMetric = MetricBase<float, FlowBodyWaterTemperatureReadOnlyTag>;

// 49. AbsoluteWaterFlow (m³/h, real, false)
struct AbsoluteWaterFlowReadOnlyTag
{
    static constexpr std::string_view name           = "AbsoluteWaterFlow";
    static constexpr std::string_view unit           = "m³/h";
    static constexpr bool             isControllable = false;
};
using AbsoluteWaterFlowMetric = MetricBase<float, AbsoluteWaterFlowReadOnlyTag>;

// 50. DifferentialWaterTemperature (°C, real, false)
struct DifferentialWaterTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "DifferentialWaterTemperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using DifferentialWaterTemperatureMetric = MetricBase<float, DifferentialWaterTemperatureReadOnlyTag>;

// 51. periodic_counter_out ( , positive, false)
struct PeriodicCounterOutReadOnlyTag
{
    static constexpr std::string_view name           = "periodic_counter_out";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PeriodicCounterOutMetric = MetricBase<float, PeriodicCounterOutReadOnlyTag>;

// 52. total_counter_out ( , positive, false)
struct TotalCounterOutReadOnlyTag
{
    static constexpr std::string_view name           = "total_counter_out";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TotalCounterOutMetric = MetricBase<float, TotalCounterOutReadOnlyTag>;

// 53. total_counter_in ( , positive, false)
struct TotalCounterInReadOnlyTag
{
    static constexpr std::string_view name           = "total_counter_in";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TotalCounterInMetric = MetricBase<float, TotalCounterInReadOnlyTag>;

// 54. periodic_counter_in ( , positive, false)
struct PeriodicCounterInReadOnlyTag
{
    static constexpr std::string_view name           = "periodic_counter_in";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using PeriodicCounterInMetric = MetricBase<float, PeriodicCounterInReadOnlyTag>;

// 55. fan_level ( , positive, false)
struct FanLevelReadOnlyTag
{
    static constexpr std::string_view name           = "fan_level";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FanLevelMetric = MetricBase<float, FanLevelReadOnlyTag>;

// 56. target_temperature (°C, real, false)
struct TargetTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "target_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using TargetTemperatureMetric = MetricBase<float, TargetTemperatureReadOnlyTag>;

// 57. ac_mode ( , positive, false)
struct AcModeReadOnlyTag
{
    static constexpr std::string_view name           = "ac_mode";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using AcModeMetric = MetricBase<float, AcModeReadOnlyTag>;

// 58. switch_1_status through switch_8_status ( , boolean, false)
#define DEFINE_SWITCH_STATUS_TAG(N)                                                \
    struct Switch##N##StatusReadOnlyTag                                            \
    {                                                                              \
        static constexpr std::string_view name           = "switch_" #N "_status"; \
        static constexpr std::string_view unit           = "";                     \
        static constexpr bool             isControllable = false;                  \
    };                                                                             \
    using Switch##N##StatusMetric = MetricBase<bool, Switch##N##StatusReadOnlyTag>;

DEFINE_SWITCH_STATUS_TAG(1)
DEFINE_SWITCH_STATUS_TAG(2)
DEFINE_SWITCH_STATUS_TAG(3)
DEFINE_SWITCH_STATUS_TAG(4)
DEFINE_SWITCH_STATUS_TAG(5)
DEFINE_SWITCH_STATUS_TAG(6)
DEFINE_SWITCH_STATUS_TAG(7)
DEFINE_SWITCH_STATUS_TAG(8)
#undef DEFINE_SWITCH_STATUS_TAG

// 59. switch_1_change through switch_3_change ( , boolean, true)
#define DEFINE_SWITCH_CHANGE_TAG(N)                                                \
    struct Switch##N##ChangeControlTag                                             \
    {                                                                              \
        static constexpr std::string_view name           = "switch_" #N "_change"; \
        static constexpr std::string_view unit           = "";                     \
        static constexpr bool             isControllable = true;                   \
    };                                                                             \
    using Switch##N##ChangeMetric = MetricBase<bool, Switch##N##ChangeControlTag>;

DEFINE_SWITCH_CHANGE_TAG(1)
DEFINE_SWITCH_CHANGE_TAG(2)
DEFINE_SWITCH_CHANGE_TAG(3)
#undef DEFINE_SWITCH_CHANGE_TAG

// 60. distance (mm, positive, false)
struct DistanceReadOnlyTag
{
    static constexpr std::string_view name           = "distance";
    static constexpr std::string_view unit           = "mm";
    static constexpr bool             isControllable = false;
};
using DistanceMetric = MetricBase<float, DistanceReadOnlyTag>;

// 61. remaining (% , percentage, false)
struct RemainingReadOnlyTag
{
    static constexpr std::string_view name           = "remaining";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using RemainingMetric = MetricBase<float, RemainingReadOnlyTag>;

// 62. voltage_1 through voltage_3 (V, positive, false)
#define DEFINE_VOLTAGE_N_TAG(N)                                           \
    struct Voltage##N##ReadOnlyTag                                        \
    {                                                                     \
        static constexpr std::string_view name           = "voltage_" #N; \
        static constexpr std::string_view unit           = "V";           \
        static constexpr bool             isControllable = false;         \
    };                                                                    \
    using Voltage##N##Metric = MetricBase<float, Voltage##N##ReadOnlyTag>;

DEFINE_VOLTAGE_N_TAG(1)
DEFINE_VOLTAGE_N_TAG(2)
DEFINE_VOLTAGE_N_TAG(3)
#undef DEFINE_VOLTAGE_N_TAG

// 63. current_1 through current_3 (A, positive, false)
#define DEFINE_CURRENT_N_TAG(N)                                           \
    struct Current##N##ReadOnlyTag                                        \
    {                                                                     \
        static constexpr std::string_view name           = "current_" #N; \
        static constexpr std::string_view unit           = "A";           \
        static constexpr bool             isControllable = false;         \
    };                                                                    \
    using Current##N##Metric = MetricBase<float, Current##N##ReadOnlyTag>;

DEFINE_CURRENT_N_TAG(1)
DEFINE_CURRENT_N_TAG(2)
DEFINE_CURRENT_N_TAG(3)
#undef DEFINE_CURRENT_N_TAG

// 64. frequency (Hz, positive, false)
struct FrequencyReadOnlyTag
{
    static constexpr std::string_view name           = "frequency";
    static constexpr std::string_view unit           = "Hz";
    static constexpr bool             isControllable = false;
};
using FrequencyMetric = MetricBase<float, FrequencyReadOnlyTag>;

// 65. accumulated_current (Ah, real, false)
struct AccumulatedCurrentReadOnlyTag
{
    static constexpr std::string_view name           = "accumulated_current";
    static constexpr std::string_view unit           = "Ah";
    static constexpr bool             isControllable = false;
};
using AccumulatedCurrentMetric = MetricBase<float, AccumulatedCurrentReadOnlyTag>;

// 66. hcho (mg/m³, real, false)
struct HchoReadOnlyTag
{
    static constexpr std::string_view name           = "hcho";
    static constexpr std::string_view unit           = "mg/m³";
    static constexpr bool             isControllable = false;
};
using HchoMetric = MetricBase<float, HchoReadOnlyTag>;

// 67. light_level ( , real, false)
struct LightLevelReadOnlyTag
{
    static constexpr std::string_view name           = "light_level";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using LightLevelMetric = MetricBase<float, LightLevelReadOnlyTag>;

// 68. filter_dirty_status ( , boolean, false)
struct FilterDirtyStatusReadOnlyTag
{
    static constexpr std::string_view name           = "filter_dirty_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FilterDirtyStatusMetric = MetricBase<bool, FilterDirtyStatusReadOnlyTag>;

// 69. run_status ( , boolean, false)
struct RunStatusReadOnlyTag
{
    static constexpr std::string_view name           = "run_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using RunStatusMetric = MetricBase<bool, RunStatusReadOnlyTag>;

// 70. return_air_temperature (°C, real, false)
struct ReturnAirTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "return_air_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using ReturnAirTemperatureMetric = MetricBase<float, ReturnAirTemperatureReadOnlyTag>;

// 71. supply_fan_vfd_speed ( , real, false)
struct SupplyFanVfdSpeedReadOnlyTag
{
    static constexpr std::string_view name           = "supply_fan_vfd_speed";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SupplyFanVfdSpeedMetric = MetricBase<float, SupplyFanVfdSpeedReadOnlyTag>;

// 72. cooling_coil_valve_control ( , real, false)
struct CoolingCoilValveControlReadOnlyTag
{
    static constexpr std::string_view name           = "cooling_coil_valve_control";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using CoolingCoilValveControlMetric = MetricBase<float, CoolingCoilValveControlReadOnlyTag>;

// 73. return_air_temperature_setpoint ( , real, false)
struct ReturnAirTemperatureSetpointReadOnlyTag
{
    static constexpr std::string_view name           = "return_air_temperature_setpoint";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using ReturnAirTemperatureSetpointMetric = MetricBase<float, ReturnAirTemperatureSetpointReadOnlyTag>;

// 74. run_command ( , boolean, false)
struct RunCommandReadOnlyTag
{
    static constexpr std::string_view name           = "run_command";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using RunCommandMetric = MetricBase<bool, RunCommandReadOnlyTag>;

// 75. run_command_sp ( , boolean, false)
struct RunCommandSpReadOnlyTag
{
    static constexpr std::string_view name           = "run_command_sp";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using RunCommandSpMetric = MetricBase<bool, RunCommandSpReadOnlyTag>;

// 76. override ( , boolean, false)
struct OverrideReadOnlyTag
{
    static constexpr std::string_view name           = "override";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using OverrideMetric = MetricBase<bool, OverrideReadOnlyTag>;

// 77. schedular ( , boolean, false)
struct SchedularReadOnlyTag
{
    static constexpr std::string_view name           = "schedular";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SchedularMetric = MetricBase<bool, SchedularReadOnlyTag>;

// 78. supply_air_pressure_setpoint ( , real, false)
struct SupplyAirPressureSetpointReadOnlyTag
{
    static constexpr std::string_view name           = "supply_air_pressure_setpoint";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SupplyAirPressureSetpointMetric = MetricBase<float, SupplyAirPressureSetpointReadOnlyTag>;

// 79. cooling_coil_valve_feedback ( , real, false)
struct CoolingCoilValveFeedbackReadOnlyTag
{
    static constexpr std::string_view name           = "cooling_coil_valve_feedback";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using CoolingCoilValveFeedbackMetric = MetricBase<float, CoolingCoilValveFeedbackReadOnlyTag>;

// 80. auto_manual_status ( , boolean, false)
struct AutoManualStatusReadOnlyTag
{
    static constexpr std::string_view name           = "auto_manual_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using AutoManualStatusMetric = MetricBase<bool, AutoManualStatusReadOnlyTag>;

// 81. ra_fire_damper_1_status through ra_fire_damper_3_status ( , boolean, false)
#define DEFINE_RA_FIRE_DAMPER_STATUS_TAG(N)                                                \
    struct RaFireDamper##N##StatusReadOnlyTag                                              \
    {                                                                                      \
        static constexpr std::string_view name           = "ra_fire_damper_" #N "_status"; \
        static constexpr std::string_view unit           = "";                             \
        static constexpr bool             isControllable = false;                          \
    };                                                                                     \
    using RaFireDamper##N##StatusMetric = MetricBase<bool, RaFireDamper##N##StatusReadOnlyTag>;

DEFINE_RA_FIRE_DAMPER_STATUS_TAG(1)
DEFINE_RA_FIRE_DAMPER_STATUS_TAG(2)
DEFINE_RA_FIRE_DAMPER_STATUS_TAG(3)
#undef DEFINE_RA_FIRE_DAMPER_STATUS_TAG

// 82. sa_fire_damper_1_status through sa_fire_damper_2_status ( , boolean, false)
#define DEFINE_SA_FIRE_DAMPER_STATUS_TAG(N)                                                \
    struct SaFireDamper##N##StatusReadOnlyTag                                              \
    {                                                                                      \
        static constexpr std::string_view name           = "sa_fire_damper_" #N "_status"; \
        static constexpr std::string_view unit           = "";                             \
        static constexpr bool             isControllable = false;                          \
    };                                                                                     \
    using SaFireDamper##N##StatusMetric = MetricBase<bool, SaFireDamper##N##StatusReadOnlyTag>;

DEFINE_SA_FIRE_DAMPER_STATUS_TAG(1)
DEFINE_SA_FIRE_DAMPER_STATUS_TAG(2)
#undef DEFINE_SA_FIRE_DAMPER_STATUS_TAG

// 83. trip_status ( , boolean, false)
struct TripStatusReadOnlyTag
{
    static constexpr std::string_view name           = "trip_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TripStatusMetric = MetricBase<bool, TripStatusReadOnlyTag>;

// 84. vfd_on_off_status ( , boolean, false)
struct VfdOnOffStatusReadOnlyTag
{
    static constexpr std::string_view name           = "vfd_on_off_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using VfdOnOffStatusMetric = MetricBase<bool, VfdOnOffStatusReadOnlyTag>;

// 85. supply_air_pressure ( , real, false)
struct SupplyAirPressureReadOnlyTag
{
    static constexpr std::string_view name           = "supply_air_pressure";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SupplyAirPressureMetric = MetricBase<float, SupplyAirPressureReadOnlyTag>;

// 86. vfd_frequency_feedback ( , real, false)
struct VfdFrequencyFeedbackReadOnlyTag
{
    static constexpr std::string_view name           = "vfd_frequency_feedback";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using VfdFrequencyFeedbackMetric = MetricBase<float, VfdFrequencyFeedbackReadOnlyTag>;

// 87. active_energy (kWh, real, false)
struct ActiveEnergyReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyMetric = MetricBase<float, ActiveEnergyReadOnlyTag>;

// 88. outlet_temperature (°C, real, false)
struct OutletTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "outlet_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using OutletTemperatureMetric = MetricBase<float, OutletTemperatureReadOnlyTag>;

// 89. volume_flow_meter (m³, real, false)
struct VolumeFlowMeterReadOnlyTag
{
    static constexpr std::string_view name           = "volume_flow_meter";
    static constexpr std::string_view unit           = "m³";
    static constexpr bool             isControllable = false;
};
using VolumeFlowMeterMetric = MetricBase<float, VolumeFlowMeterReadOnlyTag>;

// 90. short_press ( , boolean, false)
struct ShortPressReadOnlyTag
{
    static constexpr std::string_view name           = "short_press";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using ShortPressMetric = MetricBase<bool, ShortPressReadOnlyTag>;

// 91. double_click ( , boolean, false)
struct DoubleClickReadOnlyTag
{
    static constexpr std::string_view name           = "double_click";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using DoubleClickMetric = MetricBase<bool, DoubleClickReadOnlyTag>;

// 92. multi_click ( , boolean, false)
struct MultiClickReadOnlyTag
{
    static constexpr std::string_view name           = "multi_click";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using MultiClickMetric = MetricBase<bool, MultiClickReadOnlyTag>;

// 93. click_number ( , positive, false)
struct ClickNumberReadOnlyTag
{
    static constexpr std::string_view name           = "click_number";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using ClickNumberMetric = MetricBase<float, ClickNumberReadOnlyTag>;

// 94. long_press ( , boolean, false)
struct LongPressReadOnlyTag
{
    static constexpr std::string_view name           = "long_press";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using LongPressMetric = MetricBase<bool, LongPressReadOnlyTag>;

// 95. fire_status ( , boolean, false)
struct FireStatusReadOnlyTag
{
    static constexpr std::string_view name           = "fire_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FireStatusMetric = MetricBase<bool, FireStatusReadOnlyTag>;

// 96. supply_air_pressure_2 ( , real, false)
struct SupplyAirPressure2ReadOnlyTag
{
    static constexpr std::string_view name           = "supply_air_pressure_2";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SupplyAirPressure2Metric = MetricBase<float, SupplyAirPressure2ReadOnlyTag>;

// 97. return_air_temperature_sp (°C, real, false)
struct ReturnAirTemperatureSpReadOnlyTag
{
    static constexpr std::string_view name           = "return_air_temperature_sp";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using ReturnAirTemperatureSpMetric = MetricBase<float, ReturnAirTemperatureSpReadOnlyTag>;

// 98. chw_valve_feedback ( , real, false)
struct ChwValveFeedbackReadOnlyTag
{
    static constexpr std::string_view name           = "chw_valve_feedback";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using ChwValveFeedbackMetric = MetricBase<float, ChwValveFeedbackReadOnlyTag>;

// 99. chilled_water_entering_temperature (°C, real, false)
struct ChilledWaterEnteringTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "chilled_water_entering_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using ChilledWaterEnteringTemperatureMetric = MetricBase<float, ChilledWaterEnteringTemperatureReadOnlyTag>;

// 100. chilled_water_leaving_temperature (°C, real, false)
struct ChilledWaterLeavingTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "chilled_water_leaving_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using ChilledWaterLeavingTemperatureMetric = MetricBase<float, ChilledWaterLeavingTemperatureReadOnlyTag>;

// 101. chw_valve_control ( , boolean, false)
struct ChwValveControlReadOnlyTag
{
    static constexpr std::string_view name           = "chw_valve_control";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using ChwValveControlMetric = MetricBase<bool, ChwValveControlReadOnlyTag>;

// 102. setpoint (°C, real, false)
struct SetpointReadOnlyTag
{
    static constexpr std::string_view name           = "setpoint";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using SetpointMetric = MetricBase<float, SetpointReadOnlyTag>;

// 103. space_temperature (°C, real, false)
struct SpaceTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "space_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using SpaceTemperatureMetric = MetricBase<float, SpaceTemperatureReadOnlyTag>;

// 104. damper_position ( , real, false)
struct DamperPositionReadOnlyTag
{
    static constexpr std::string_view name           = "damper_position";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using DamperPositionMetric = MetricBase<float, DamperPositionReadOnlyTag>;

// 105. airflow ( , real, false)
struct AirflowReadOnlyTag
{
    static constexpr std::string_view name           = "airflow";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using AirflowMetric = MetricBase<float, AirflowReadOnlyTag>;

// 106. active_power (kW, real, false)
struct ActivePowerReadOnlyTag
{
    static constexpr std::string_view name           = "active_power";
    static constexpr std::string_view unit           = "kW";
    static constexpr bool             isControllable = false;
};
using ActivePowerMetric = MetricBase<float, ActivePowerReadOnlyTag>;

// 107. apparent_power (kVA, real, false)
struct ApparentPowerReadOnlyTag
{
    static constexpr std::string_view name           = "apparent_power";
    static constexpr std::string_view unit           = "kVA";
    static constexpr bool             isControllable = false;
};
using ApparentPowerMetric = MetricBase<float, ApparentPowerReadOnlyTag>;

// 108. energy_reading (kWH, real, false)
struct EnergyReadingReadOnlyTag
{
    static constexpr std::string_view name           = "energy_reading";
    static constexpr std::string_view unit           = "kWH";
    static constexpr bool             isControllable = false;
};
using EnergyReadingMetric = MetricBase<float, EnergyReadingReadOnlyTag>;

// 109. line_current_b through line_current_y (kA, real, false)
// line_current_b, line_current_c, … line_current_y: define tags B through Y:
#define DEFINE_LINE_CURRENT_TAG(letter)                                             \
    struct LineCurrent##letter##ReadOnlyTag                                         \
    {                                                                               \
        static constexpr std::string_view name           = "line_current_" #letter; \
        static constexpr std::string_view unit           = "kA";                    \
        static constexpr bool             isControllable = false;                   \
    };                                                                              \
    using LineCurrent##letter##Metric = MetricBase<float, LineCurrent##letter##ReadOnlyTag>;

DEFINE_LINE_CURRENT_TAG(b)
DEFINE_LINE_CURRENT_TAG(c)
DEFINE_LINE_CURRENT_TAG(d)
DEFINE_LINE_CURRENT_TAG(e)
DEFINE_LINE_CURRENT_TAG(f)
DEFINE_LINE_CURRENT_TAG(g)
DEFINE_LINE_CURRENT_TAG(h)
DEFINE_LINE_CURRENT_TAG(i)
DEFINE_LINE_CURRENT_TAG(j)
DEFINE_LINE_CURRENT_TAG(k)
DEFINE_LINE_CURRENT_TAG(l)
DEFINE_LINE_CURRENT_TAG(m)
DEFINE_LINE_CURRENT_TAG(n)
DEFINE_LINE_CURRENT_TAG(o)
DEFINE_LINE_CURRENT_TAG(p)
DEFINE_LINE_CURRENT_TAG(q)
DEFINE_LINE_CURRENT_TAG(r)
DEFINE_LINE_CURRENT_TAG(s)
DEFINE_LINE_CURRENT_TAG(t)
DEFINE_LINE_CURRENT_TAG(u)
DEFINE_LINE_CURRENT_TAG(v)
DEFINE_LINE_CURRENT_TAG(w)
DEFINE_LINE_CURRENT_TAG(x)
DEFINE_LINE_CURRENT_TAG(y)
#undef DEFINE_LINE_CURRENT_TAG

// 110. line_voltage_b through line_voltage_y (kV, real, false)
#define DEFINE_LINE_VOLTAGE_TAG(letter)                                             \
    struct LineVoltage##letter##ReadOnlyTag                                         \
    {                                                                               \
        static constexpr std::string_view name           = "line_voltage_" #letter; \
        static constexpr std::string_view unit           = "kV";                    \
        static constexpr bool             isControllable = false;                   \
    };                                                                              \
    using LineVoltage##letter##Metric = MetricBase<float, LineVoltage##letter##ReadOnlyTag>;

DEFINE_LINE_VOLTAGE_TAG(b)
DEFINE_LINE_VOLTAGE_TAG(c)
DEFINE_LINE_VOLTAGE_TAG(d)
DEFINE_LINE_VOLTAGE_TAG(e)
DEFINE_LINE_VOLTAGE_TAG(f)
DEFINE_LINE_VOLTAGE_TAG(g)
DEFINE_LINE_VOLTAGE_TAG(h)
DEFINE_LINE_VOLTAGE_TAG(i)
DEFINE_LINE_VOLTAGE_TAG(j)
DEFINE_LINE_VOLTAGE_TAG(k)
DEFINE_LINE_VOLTAGE_TAG(l)
DEFINE_LINE_VOLTAGE_TAG(m)
DEFINE_LINE_VOLTAGE_TAG(n)
DEFINE_LINE_VOLTAGE_TAG(o)
DEFINE_LINE_VOLTAGE_TAG(p)
DEFINE_LINE_VOLTAGE_TAG(q)
DEFINE_LINE_VOLTAGE_TAG(r)
DEFINE_LINE_VOLTAGE_TAG(s)
DEFINE_LINE_VOLTAGE_TAG(t)
DEFINE_LINE_VOLTAGE_TAG(u)
DEFINE_LINE_VOLTAGE_TAG(v)
DEFINE_LINE_VOLTAGE_TAG(w)
DEFINE_LINE_VOLTAGE_TAG(x)
DEFINE_LINE_VOLTAGE_TAG(y)
#undef DEFINE_LINE_VOLTAGE_TAG

// 111. phase_voltage_b through phase_voltage_y (kV, real, false)
#define DEFINE_PHASE_VOLTAGE_TAG(letter)                                             \
    struct PhaseVoltage##letter##ReadOnlyTag                                         \
    {                                                                                \
        static constexpr std::string_view name           = "phase_voltage_" #letter; \
        static constexpr std::string_view unit           = "kV";                     \
        static constexpr bool             isControllable = false;                    \
    };                                                                               \
    using PhaseVoltage##letter##Metric = MetricBase<float, PhaseVoltage##letter##ReadOnlyTag>;

DEFINE_PHASE_VOLTAGE_TAG(b)
DEFINE_PHASE_VOLTAGE_TAG(c)
DEFINE_PHASE_VOLTAGE_TAG(d)
DEFINE_PHASE_VOLTAGE_TAG(e)
DEFINE_PHASE_VOLTAGE_TAG(f)
DEFINE_PHASE_VOLTAGE_TAG(g)
DEFINE_PHASE_VOLTAGE_TAG(h)
DEFINE_PHASE_VOLTAGE_TAG(i)
DEFINE_PHASE_VOLTAGE_TAG(j)
DEFINE_PHASE_VOLTAGE_TAG(k)
DEFINE_PHASE_VOLTAGE_TAG(l)
DEFINE_PHASE_VOLTAGE_TAG(m)
DEFINE_PHASE_VOLTAGE_TAG(n)
DEFINE_PHASE_VOLTAGE_TAG(o)
DEFINE_PHASE_VOLTAGE_TAG(p)
DEFINE_PHASE_VOLTAGE_TAG(q)
DEFINE_PHASE_VOLTAGE_TAG(r)
DEFINE_PHASE_VOLTAGE_TAG(s)
DEFINE_PHASE_VOLTAGE_TAG(t)
DEFINE_PHASE_VOLTAGE_TAG(u)
DEFINE_PHASE_VOLTAGE_TAG(v)
DEFINE_PHASE_VOLTAGE_TAG(w)
DEFINE_PHASE_VOLTAGE_TAG(x)
DEFINE_PHASE_VOLTAGE_TAG(y)
#undef DEFINE_PHASE_VOLTAGE_TAG

// 112. fan_run_status ( , boolean, false)
struct FanRunStatusReadOnlyTag
{
    static constexpr std::string_view name           = "fan_run_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FanRunStatusMetric = MetricBase<bool, FanRunStatusReadOnlyTag>;

// 113. room_temperature (°C, real, false)
struct RoomTemperatureReadOnlyTag
{
    static constexpr std::string_view name           = "room_temperature";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using RoomTemperatureMetric = MetricBase<float, RoomTemperatureReadOnlyTag>;

// 114. room_humidity (% , real, false)
struct RoomHumidityReadOnlyTag
{
    static constexpr std::string_view name           = "room_humidity";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using RoomHumidityMetric = MetricBase<float, RoomHumidityReadOnlyTag>;

// 115. supply_louver_status ( , boolean, false)
struct SupplyLouverStatusReadOnlyTag
{
    static constexpr std::string_view name           = "supply_louver_status";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SupplyLouverStatusMetric = MetricBase<bool, SupplyLouverStatusReadOnlyTag>;

// 116. common_alarm ( , boolean, false)
struct CommonAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "common_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using CommonAlarmMetric = MetricBase<bool, CommonAlarmReadOnlyTag>;

// 117. temperature_high_alarm ( , boolean, false)
struct TemperatureHighAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "temperature_high_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TemperatureHighAlarmMetric = MetricBase<bool, TemperatureHighAlarmReadOnlyTag>;

// 118. temperature_low_alarm ( , boolean, false)
struct TemperatureLowAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "temperature_low_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TemperatureLowAlarmMetric = MetricBase<bool, TemperatureLowAlarmReadOnlyTag>;

// 119. humidity_high_alarm ( , boolean, false)
struct HumidityHighAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "humidity_high_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using HumidityHighAlarmMetric = MetricBase<bool, HumidityHighAlarmReadOnlyTag>;

// 120. humidity_low_alarm ( , boolean, false)
struct HumidityLowAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "humidity_low_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using HumidityLowAlarmMetric = MetricBase<bool, HumidityLowAlarmReadOnlyTag>;

// 121. filter_alarm ( , boolean, false)
struct FilterAlarmReadOnlyTag
{
    static constexpr std::string_view name           = "filter_alarm";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FilterAlarmMetric = MetricBase<bool, FilterAlarmReadOnlyTag>;

// 122. room_humidity_sp (% , real, false)
struct RoomHumiditySpReadOnlyTag
{
    static constexpr std::string_view name           = "room_humidity_sp";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using RoomHumiditySpMetric = MetricBase<float, RoomHumiditySpReadOnlyTag>;

// 123. fan_speed ( , real, false)
struct FanSpeedReadOnlyTag
{
    static constexpr std::string_view name           = "fan_speed";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using FanSpeedMetric = MetricBase<float, FanSpeedReadOnlyTag>;

// 124. frequency_input (Hz, real, false)
struct FrequencyInputReadOnlyTag
{
    static constexpr std::string_view name           = "frequency_input";
    static constexpr std::string_view unit           = "Hz";
    static constexpr bool             isControllable = false;
};
using FrequencyInputMetric = MetricBase<float, FrequencyInputReadOnlyTag>;

// 125. frequency_output (Hz, real, false)
struct FrequencyOutputReadOnlyTag
{
    static constexpr std::string_view name           = "frequency_output";
    static constexpr std::string_view unit           = "Hz";
    static constexpr bool             isControllable = false;
};
using FrequencyOutputMetric = MetricBase<float, FrequencyOutputReadOnlyTag>;

// 126. battery_voltage (V, real, false)
struct BatteryVoltageReadOnlyTag
{
    static constexpr std::string_view name           = "battery_voltage";
    static constexpr std::string_view unit           = "V";
    static constexpr bool             isControllable = false;
};
using BatteryVoltageMetric = MetricBase<float, BatteryVoltageReadOnlyTag>;

// 127. battery_current (A, real, false)
struct BatteryCurrentReadOnlyTag
{
    static constexpr std::string_view name           = "battery_current";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using BatteryCurrentMetric = MetricBase<float, BatteryCurrentReadOnlyTag>;

// 128. battery_power (kW, real, false)
struct BatteryPowerReadOnlyTag
{
    static constexpr std::string_view name           = "battery_power";
    static constexpr std::string_view unit           = "kW";
    static constexpr bool             isControllable = false;
};
using BatteryPowerMetric = MetricBase<float, BatteryPowerReadOnlyTag>;

// 129. ups_power_rating ( , real, false)
struct UpsPowerRatingReadOnlyTag
{
    static constexpr std::string_view name           = "ups_power_rating";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using UpsPowerRatingMetric = MetricBase<float, UpsPowerRatingReadOnlyTag>;

// 130. total_output_percent_load ( , real, false)
struct TotalOutputPercentLoadReadOnlyTag
{
    static constexpr std::string_view name           = "total_output_percent_load";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using TotalOutputPercentLoadMetric = MetricBase<float, TotalOutputPercentLoadReadOnlyTag>;

// 131. voltage_l1_2_input through voltage_l3_1_input (V, real, false)
// We'll define tags for l1_2, l1_3, l2_1, l2_2, l2_3, l3_1:
#define DEFINE_VOLTAGE_INPUT_TAG(a, b)                                                    \
    struct Voltage##a##_##b##ReadOnlyTag                                                  \
    {                                                                                     \
        static constexpr std::string_view name           = "voltage_" #a "_" #b "_input"; \
        static constexpr std::string_view unit           = "V";                           \
        static constexpr bool             isControllable = false;                         \
    };                                                                                    \
    using Voltage##a##_##b##InputMetric = MetricBase<float, Voltage##a##_##b##ReadOnlyTag>;

DEFINE_VOLTAGE_INPUT_TAG(l1, 2)
DEFINE_VOLTAGE_INPUT_TAG(l1, 3)
DEFINE_VOLTAGE_INPUT_TAG(l2, 1)
DEFINE_VOLTAGE_INPUT_TAG(l2, 2)
DEFINE_VOLTAGE_INPUT_TAG(l2, 3)
DEFINE_VOLTAGE_INPUT_TAG(l3, 1)
#undef DEFINE_VOLTAGE_INPUT_TAG

// 132. current_l1_input through current_l3_input (A, real, false)
#define DEFINE_CURRENT_INPUT_TAG(a)                                                \
    struct Current##a##InputReadOnlyTag                                            \
    {                                                                              \
        static constexpr std::string_view name           = "current_" #a "_input"; \
        static constexpr std::string_view unit           = "A";                    \
        static constexpr bool             isControllable = false;                  \
    };                                                                             \
    using Current##a##InputMetric = MetricBase<float, Current##a##InputReadOnlyTag>;

DEFINE_CURRENT_INPUT_TAG(l1)
DEFINE_CURRENT_INPUT_TAG(l2)
DEFINE_CURRENT_INPUT_TAG(l3)
#undef DEFINE_CURRENT_INPUT_TAG

// 133. power_factor_l1_input through power_factor_l3_input ( , real, false)
#define DEFINE_PF_INPUT_TAG(a)                                                          \
    struct PowerFactor##a##InputReadOnlyTag                                             \
    {                                                                                   \
        static constexpr std::string_view name           = "power_factor_" #a "_input"; \
        static constexpr std::string_view unit           = "";                          \
        static constexpr bool             isControllable = false;                       \
    };                                                                                  \
    using PowerFactor##a##InputMetric = MetricBase<float, PowerFactor##a##InputReadOnlyTag>;

DEFINE_PF_INPUT_TAG(l1)
DEFINE_PF_INPUT_TAG(l2)
DEFINE_PF_INPUT_TAG(l3)
#undef DEFINE_PF_INPUT_TAG

// 134. voltage_l1_2_output through voltage_l3_1_output (V, real, false)
#define DEFINE_VOLTAGE_OUTPUT_TAG(a, b)                                                    \
    struct Voltage##a##_##b##OutputReadOnlyTag                                             \
    {                                                                                      \
        static constexpr std::string_view name           = "voltage_" #a "_" #b "_output"; \
        static constexpr std::string_view unit           = "V";                            \
        static constexpr bool             isControllable = false;                          \
    };                                                                                     \
    using Voltage##a##_##b##OutputMetric = MetricBase<float, Voltage##a##_##b##OutputReadOnlyTag>;

DEFINE_VOLTAGE_OUTPUT_TAG(l1, 2)
DEFINE_VOLTAGE_OUTPUT_TAG(l1, 3)
DEFINE_VOLTAGE_OUTPUT_TAG(l2, 1)
DEFINE_VOLTAGE_OUTPUT_TAG(l2, 2)
DEFINE_VOLTAGE_OUTPUT_TAG(l2, 3)
DEFINE_VOLTAGE_OUTPUT_TAG(l3, 1)
#undef DEFINE_VOLTAGE_OUTPUT_TAG

// 135. current_l1_output through current_l3_output (A, real, false)
#define DEFINE_CURRENT_OUTPUT_TAG(a)                                                \
    struct Current##a##OutputReadOnlyTag                                            \
    {                                                                               \
        static constexpr std::string_view name           = "current_" #a "_output"; \
        static constexpr std::string_view unit           = "A";                     \
        static constexpr bool             isControllable = false;                   \
    };                                                                              \
    using Current##a##OutputMetric = MetricBase<float, Current##a##OutputReadOnlyTag>;

DEFINE_CURRENT_OUTPUT_TAG(l1)
DEFINE_CURRENT_OUTPUT_TAG(l2)
DEFINE_CURRENT_OUTPUT_TAG(l3)
#undef DEFINE_CURRENT_OUTPUT_TAG

// 136. power_factor_l1_output through power_factor_l3_output ( , real, false)
#define DEFINE_PF_OUTPUT_TAG(a)                                                          \
    struct PowerFactor##a##OutputReadOnlyTag                                             \
    {                                                                                    \
        static constexpr std::string_view name           = "power_factor_" #a "_output"; \
        static constexpr std::string_view unit           = "";                           \
        static constexpr bool             isControllable = false;                        \
    };                                                                                   \
    using PowerFactor##a##OutputMetric = MetricBase<float, PowerFactor##a##OutputReadOnlyTag>;

DEFINE_PF_OUTPUT_TAG(l1)
DEFINE_PF_OUTPUT_TAG(l2)
DEFINE_PF_OUTPUT_TAG(l3)
#undef DEFINE_PF_OUTPUT_TAG

// 137. efficiency ( , real, false)
struct EfficiencyReadOnlyTag
{
    static constexpr std::string_view name           = "efficiency";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using EfficiencyMetric = MetricBase<float, EfficiencyReadOnlyTag>;

// 138. active_power_1 through active_power_3 (kW, real, false)
#define DEFINE_ACTIVE_POWER_N_TAG(N)                                           \
    struct ActivePower##N##ReadOnlyTag                                         \
    {                                                                          \
        static constexpr std::string_view name           = "active_power_" #N; \
        static constexpr std::string_view unit           = "kW";               \
        static constexpr bool             isControllable = false;              \
    };                                                                         \
    using ActivePower##N##Metric = MetricBase<float, ActivePower##N##ReadOnlyTag>;

DEFINE_ACTIVE_POWER_N_TAG(1)
DEFINE_ACTIVE_POWER_N_TAG(2)
DEFINE_ACTIVE_POWER_N_TAG(3)
#undef DEFINE_ACTIVE_POWER_N_TAG

// 139. valve_position (%, percentage, true)
struct ValvePositionControlTag
{
    static constexpr std::string_view name           = "valve_position";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = true;
};
using ValvePositionMetric = MetricBase<float, ValvePositionControlTag>;

// 140. smoke ( , boolean, false)
struct SmokeReadOnlyTag
{
    static constexpr std::string_view name           = "smoke";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using SmokeMetric = MetricBase<bool, SmokeReadOnlyTag>;

// 141. luminosity (Lux, real, false)
struct LuminosityReadOnlyTag
{
    static constexpr std::string_view name           = "luminosity";
    static constexpr std::string_view unit           = "Lux";
    static constexpr bool             isControllable = false;
};
using LuminosityMetric = MetricBase<float, LuminosityReadOnlyTag>;

// 142. reactive_power (kVA, real, false)
struct ReactivePowerReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_power";
    static constexpr std::string_view unit           = "kVA";
    static constexpr bool             isControllable = false;
};
using ReactivePowerMetric = MetricBase<float, ReactivePowerReadOnlyTag>;

// 143. reactive_power_1 through reactive_power_3 (kVA, real, false)
#define DEFINE_REACTIVE_POWER_N_TAG(N)                                           \
    struct ReactivePower##N##ReadOnlyTag                                         \
    {                                                                            \
        static constexpr std::string_view name           = "reactive_power_" #N; \
        static constexpr std::string_view unit           = "kVA";                \
        static constexpr bool             isControllable = false;                \
    };                                                                           \
    using ReactivePower##N##Metric = MetricBase<float, ReactivePower##N##ReadOnlyTag>;

DEFINE_REACTIVE_POWER_N_TAG(1)
DEFINE_REACTIVE_POWER_N_TAG(2)
DEFINE_REACTIVE_POWER_N_TAG(3)
#undef DEFINE_REACTIVE_POWER_N_TAG

// 144. risk_index ( , aqi, false)
struct RiskIndexReadOnlyTag
{
    static constexpr std::string_view name           = "risk_index";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using RiskIndexMetric = MetricBase<float, RiskIndexReadOnlyTag>;

// 145. active_energy_1 through active_energy_3 (kWh, real, false)
#define DEFINE_ACTIVE_ENERGY_N_TAG(N)                                           \
    struct ActiveEnergy##N##ReadOnlyTag                                         \
    {                                                                           \
        static constexpr std::string_view name           = "active_energy_" #N; \
        static constexpr std::string_view unit           = "kWh";               \
        static constexpr bool             isControllable = false;               \
    };                                                                          \
    using ActiveEnergy##N##Metric = MetricBase<float, ActiveEnergy##N##ReadOnlyTag>;

DEFINE_ACTIVE_ENERGY_N_TAG(1)
DEFINE_ACTIVE_ENERGY_N_TAG(2)
DEFINE_ACTIVE_ENERGY_N_TAG(3)
#undef DEFINE_ACTIVE_ENERGY_N_TAG

// 146. reactive_energy (kVArh, real, false)
struct ReactiveEnergyReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_energy";
    static constexpr std::string_view unit           = "kVArh";
    static constexpr bool             isControllable = false;
};
using ReactiveEnergyMetric = MetricBase<float, ReactiveEnergyReadOnlyTag>;

// 147. reactive_energy_1 through reactive_energy_3 (kVArh, real, false)
#define DEFINE_REACTIVE_ENERGY_N_TAG(N)                                           \
    struct ReactiveEnergy##N##ReadOnlyTag                                         \
    {                                                                             \
        static constexpr std::string_view name           = "reactive_energy_" #N; \
        static constexpr std::string_view unit           = "kVArh";               \
        static constexpr bool             isControllable = false;                 \
    };                                                                            \
    using ReactiveEnergy##N##Metric = MetricBase<float, ReactiveEnergy##N##ReadOnlyTag>;

DEFINE_REACTIVE_ENERGY_N_TAG(1)
DEFINE_REACTIVE_ENERGY_N_TAG(2)
DEFINE_REACTIVE_ENERGY_N_TAG(3)
#undef DEFINE_REACTIVE_ENERGY_N_TAG

// 148. peak_current_1 through peak_current_3 (A, real, false)
#define DEFINE_PEAK_CURRENT_N_TAG(N)                                           \
    struct PeakCurrent##N##ReadOnlyTag                                         \
    {                                                                          \
        static constexpr std::string_view name           = "peak_current_" #N; \
        static constexpr std::string_view unit           = "A";                \
        static constexpr bool             isControllable = false;              \
    };                                                                         \
    using PeakCurrent##N##Metric = MetricBase<float, PeakCurrent##N##ReadOnlyTag>;

DEFINE_PEAK_CURRENT_N_TAG(1)
DEFINE_PEAK_CURRENT_N_TAG(2)
DEFINE_PEAK_CURRENT_N_TAG(3)
#undef DEFINE_PEAK_CURRENT_N_TAG

// 149. average_current (A, positive, false)
struct AverageCurrentReadOnlyTag
{
    static constexpr std::string_view name           = "average_current";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using AverageCurrentMetric = MetricBase<float, AverageCurrentReadOnlyTag>;

// 150. max_current_deviation (A, positive, false)
struct MaxCurrentDeviationReadOnlyTag
{
    static constexpr std::string_view name           = "max_current_deviation";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using MaxCurrentDeviationMetric = MetricBase<float, MaxCurrentDeviationReadOnlyTag>;

// 151. current_unbalance (% , positive, false)
struct CurrentUnbalanceReadOnlyTag
{
    static constexpr std::string_view name           = "current_unbalance";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using CurrentUnbalanceMetric = MetricBase<float, CurrentUnbalanceReadOnlyTag>;

// 152. power_consumption (Wh, real, false)
struct PowerConsumptionReadOnlyTag
{
    static constexpr std::string_view name           = "power_consumption";
    static constexpr std::string_view unit           = "Wh";
    static constexpr bool             isControllable = false;
};
using PowerConsumptionMetric = MetricBase<float, PowerConsumptionReadOnlyTag>;

// 153. light ( , real, true)
struct LightControlTag
{
    static constexpr std::string_view name           = "light";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = true;
};
using LightMetric = MetricBase<float, LightControlTag>;

// 154. design_delta_dew_point (°C, real, false)
struct DesignDeltaDewPointReadOnlyTag
{
    static constexpr std::string_view name           = "design_delta_dew_point";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using DesignDeltaDewPointMetric = MetricBase<float, DesignDeltaDewPointReadOnlyTag>;

// 155. comfort_delta_dew_point (°C, real, false)
struct ComfortDeltaDewPointReadOnlyTag
{
    static constexpr std::string_view name           = "comfort_delta_dew_point";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using ComfortDeltaDewPointMetric = MetricBase<float, ComfortDeltaDewPointReadOnlyTag>;

// 156. accumulated_current_1 through accumulated_current_3 (Ah, real, false)
#define DEFINE_ACCUMULATED_CURRENT_N_TAG(N)                                           \
    struct AccumulatedCurrent##N##ReadOnlyTag                                         \
    {                                                                                 \
        static constexpr std::string_view name           = "accumulated_current_" #N; \
        static constexpr std::string_view unit           = "Ah";                      \
        static constexpr bool             isControllable = false;                     \
    };                                                                                \
    using AccumulatedCurrent##N##Metric = MetricBase<float, AccumulatedCurrent##N##ReadOnlyTag>;

DEFINE_ACCUMULATED_CURRENT_N_TAG(1)
DEFINE_ACCUMULATED_CURRENT_N_TAG(2)
DEFINE_ACCUMULATED_CURRENT_N_TAG(3)
#undef DEFINE_ACCUMULATED_CURRENT_N_TAG

// 157. voltage_ab through voltage_ca (V, real, false)
// We'll define tags for ab, bc, ca:
#define DEFINE_VOLTAGE_PHASE_TAG(a, b)                                           \
    struct Voltage##a##_##b##ReadOnlyTag                                         \
    {                                                                            \
        static constexpr std::string_view name           = "voltage_" #a "_" #b; \
        static constexpr std::string_view unit           = "V";                  \
        static constexpr bool             isControllable = false;                \
    };                                                                           \
    using Voltage##a##_##b##Metric = MetricBase<float, Voltage##a##_##b##ReadOnlyTag>;

DEFINE_VOLTAGE_PHASE_TAG(a, b)
DEFINE_VOLTAGE_PHASE_TAG(b, c)
DEFINE_VOLTAGE_PHASE_TAG(c, a)
#undef DEFINE_VOLTAGE_PHASE_TAG

// 158. active_power_total (kW, real, false)
struct ActivePowerTotalReadOnlyTag
{
    static constexpr std::string_view name           = "active_power_total";
    static constexpr std::string_view unit           = "kW";
    static constexpr bool             isControllable = false;
};
using ActivePowerTotalMetric = MetricBase<float, ActivePowerTotalReadOnlyTag>;

// 159. reactive_power_total (kvar, real, false)
struct ReactivePowerTotalReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_power_total";
    static constexpr std::string_view unit           = "kvar";
    static constexpr bool             isControllable = false;
};
using ReactivePowerTotalMetric = MetricBase<float, ReactivePowerTotalReadOnlyTag>;

// 160. apparent_power_1 through apparent_power_3 (kVA, real, false)
#define DEFINE_APPARENT_POWER_N_TAG(N)                                           \
    struct ApparentPower##N##ReadOnlyTag                                         \
    {                                                                            \
        static constexpr std::string_view name           = "apparent_power_" #N; \
        static constexpr std::string_view unit           = "kVA";                \
        static constexpr bool             isControllable = false;                \
    };                                                                           \
    using ApparentPower##N##Metric = MetricBase<float, ApparentPower##N##ReadOnlyTag>;

DEFINE_APPARENT_POWER_N_TAG(1)
DEFINE_APPARENT_POWER_N_TAG(2)
DEFINE_APPARENT_POWER_N_TAG(3)
#undef DEFINE_APPARENT_POWER_N_TAG

// 161. apparent_power_total (kVA, real, false)
struct ApparentPowerTotalReadOnlyTag
{
    static constexpr std::string_view name           = "apparent_power_total";
    static constexpr std::string_view unit           = "kVA";
    static constexpr bool             isControllable = false;
};
using ApparentPowerTotalMetric = MetricBase<float, ApparentPowerTotalReadOnlyTag>;

// 162. signal_strength (dBm, real, false)
struct SignalStrengthReadOnlyTag
{
    static constexpr std::string_view name           = "signal_strength";
    static constexpr std::string_view unit           = "dBm";
    static constexpr bool             isControllable = false;
};
using SignalStrengthMetric = MetricBase<float, SignalStrengthReadOnlyTag>;

// 163. active_energy_positive (kWh, real, false)
struct ActiveEnergyPositiveReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_positive";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyPositiveMetric = MetricBase<float, ActiveEnergyPositiveReadOnlyTag>;

// 164. active_energy_reverse (kWh, real, false)
struct ActiveEnergyReverseReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_reverse";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyReverseMetric = MetricBase<float, ActiveEnergyReverseReadOnlyTag>;

// 165. reactive_energy_positive (kvarh, real, false)
struct ReactiveEnergyPositiveReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_energy_positive";
    static constexpr std::string_view unit           = "kvarh";
    static constexpr bool             isControllable = false;
};
using ReactiveEnergyPositiveMetric = MetricBase<float, ReactiveEnergyPositiveReadOnlyTag>;

// 166. reactive_energy_reverse (kvarh, real, false)
struct ReactiveEnergyReverseReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_energy_reverse";
    static constexpr std::string_view unit           = "kvarh";
    static constexpr bool             isControllable = false;
};
using ReactiveEnergyReverseMetric = MetricBase<float, ReactiveEnergyReverseReadOnlyTag>;

// 167. active_demand_current (kW, real, false)
struct ActiveDemandCurrentReadOnlyTag
{
    static constexpr std::string_view name           = "active_demand_current";
    static constexpr std::string_view unit           = "kW";
    static constexpr bool             isControllable = false;
};
using ActiveDemandCurrentMetric = MetricBase<float, ActiveDemandCurrentReadOnlyTag>;

// 168. voltage_ratio ( , real, false)
struct VoltageRatioReadOnlyTag
{
    static constexpr std::string_view name           = "voltage_ratio";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using VoltageRatioMetric = MetricBase<float, VoltageRatioReadOnlyTag>;

// 169. current_ratio ( , real, false)
struct CurrentRatioReadOnlyTag
{
    static constexpr std::string_view name           = "current_ratio";
    static constexpr std::string_view unit           = "";
    static constexpr bool             isControllable = false;
};
using CurrentRatioMetric = MetricBase<float, CurrentRatioReadOnlyTag>;

// 170. temperature_1 through temperature_3, temperature_n (°C, real, false)
// Here we define temperature_1, temperature_2, temperature_3, and a generic "temperature_n" can be done separately
#define DEFINE_TEMPERATURE_N_TAG(N)                                           \
    struct Temperature##N##ReadOnlyTag                                        \
    {                                                                         \
        static constexpr std::string_view name           = "temperature_" #N; \
        static constexpr std::string_view unit           = "°C";              \
        static constexpr bool             isControllable = false;             \
    };                                                                        \
    using Temperature##N##Metric = MetricBase<float, Temperature##N##ReadOnlyTag>;

// Individual numbered versions:
DEFINE_TEMPERATURE_N_TAG(1)
DEFINE_TEMPERATURE_N_TAG(2)
DEFINE_TEMPERATURE_N_TAG(3)
#undef DEFINE_TEMPERATURE_N_TAG

// If you need a generic "temperature_n" metric, you can alias TempNMetric:
struct TemperatureNReadOnlyTag
{
    static constexpr std::string_view name           = "temperature_n";
    static constexpr std::string_view unit           = "°C";
    static constexpr bool             isControllable = false;
};
using TemperatureNMetric = MetricBase<float, TemperatureNReadOnlyTag>;

// 171. current_leakage (A, real, false)
struct CurrentLeakageReadOnlyTag
{
    static constexpr std::string_view name           = "current_leakage";
    static constexpr std::string_view unit           = "A";
    static constexpr bool             isControllable = false;
};
using CurrentLeakageMetric = MetricBase<float, CurrentLeakageReadOnlyTag>;

// 172. active_energy_positive_1 through active_energy_positive_3 (kWh, real, false)
#define DEFINE_ACTIVE_ENERGY_POSITIVE_N_TAG(N)                                           \
    struct ActiveEnergyPositive##N##ReadOnlyTag                                          \
    {                                                                                    \
        static constexpr std::string_view name           = "active_energy_positive_" #N; \
        static constexpr std::string_view unit           = "kWh";                        \
        static constexpr bool             isControllable = false;                        \
    };                                                                                   \
    using ActiveEnergyPositive##N##Metric = MetricBase<float, ActiveEnergyPositive##N##ReadOnlyTag>;

DEFINE_ACTIVE_ENERGY_POSITIVE_N_TAG(1)
DEFINE_ACTIVE_ENERGY_POSITIVE_N_TAG(2)
DEFINE_ACTIVE_ENERGY_POSITIVE_N_TAG(3)
#undef DEFINE_ACTIVE_ENERGY_POSITIVE_N_TAG

// 173. active_energy_reverse_1 through active_energy_reverse_3 (kWh, real, false)
#define DEFINE_ACTIVE_ENERGY_REVERSE_N_TAG(N)                                           \
    struct ActiveEnergyReverse##N##ReadOnlyTag                                          \
    {                                                                                   \
        static constexpr std::string_view name           = "active_energy_reverse_" #N; \
        static constexpr std::string_view unit           = "kWh";                       \
        static constexpr bool             isControllable = false;                       \
    };                                                                                  \
    using ActiveEnergyReverse##N##Metric = MetricBase<float, ActiveEnergyReverse##N##ReadOnlyTag>;

DEFINE_ACTIVE_ENERGY_REVERSE_N_TAG(1)
DEFINE_ACTIVE_ENERGY_REVERSE_N_TAG(2)
DEFINE_ACTIVE_ENERGY_REVERSE_N_TAG(3)
#undef DEFINE_ACTIVE_ENERGY_REVERSE_N_TAG

// 174. reactive_energy_positive_1 through reactive_energy_positive_3 (kvarh, real, false)
#define DEFINE_REACTIVE_ENERGY_POSITIVE_N_TAG(N)                                           \
    struct ReactiveEnergyPositive##N##ReadOnlyTag                                          \
    {                                                                                      \
        static constexpr std::string_view name           = "reactive_energy_positive_" #N; \
        static constexpr std::string_view unit           = "kvarh";                        \
        static constexpr bool             isControllable = false;                          \
    };                                                                                     \
    using ReactiveEnergyPositive##N##Metric = MetricBase<float, ReactiveEnergyPositive##N##ReadOnlyTag>;

DEFINE_REACTIVE_ENERGY_POSITIVE_N_TAG(1)
DEFINE_REACTIVE_ENERGY_POSITIVE_N_TAG(2)
DEFINE_REACTIVE_ENERGY_POSITIVE_N_TAG(3)
#undef DEFINE_REACTIVE_ENERGY_POSITIVE_N_TAG

// 175. reactive_energy_reverse_1 through reactive_energy_reverse_3 (kvarh, real, false)
#define DEFINE_REACTIVE_ENERGY_REVERSE_N_TAG(N)                                           \
    struct ReactiveEnergyReverse##N##ReadOnlyTag                                          \
    {                                                                                     \
        static constexpr std::string_view name           = "reactive_energy_reverse_" #N; \
        static constexpr std::string_view unit           = "kvarh";                       \
        static constexpr bool             isControllable = false;                         \
    };                                                                                    \
    using ReactiveEnergyReverse##N##Metric = MetricBase<float, ReactiveEnergyReverse##N##ReadOnlyTag>;

DEFINE_REACTIVE_ENERGY_REVERSE_N_TAG(1)
DEFINE_REACTIVE_ENERGY_REVERSE_N_TAG(2)
DEFINE_REACTIVE_ENERGY_REVERSE_N_TAG(3)
#undef DEFINE_REACTIVE_ENERGY_REVERSE_N_TAG

// 176. voltage_thd_1 through voltage_thd_3 (% , percentage, false)
#define DEFINE_VOLTAGE_THD_N_TAG(N)                                           \
    struct VoltageThd##N##ReadOnlyTag                                         \
    {                                                                         \
        static constexpr std::string_view name           = "voltage_thd_" #N; \
        static constexpr std::string_view unit           = "%";               \
        static constexpr bool             isControllable = false;             \
    };                                                                        \
    using VoltageThd##N##Metric = MetricBase<float, VoltageThd##N##ReadOnlyTag>;

DEFINE_VOLTAGE_THD_N_TAG(1)
DEFINE_VOLTAGE_THD_N_TAG(2)
DEFINE_VOLTAGE_THD_N_TAG(3)
#undef DEFINE_VOLTAGE_THD_N_TAG

// 177. current_thd_1 through current_thd_3 (% , percentage, false)
#define DEFINE_CURRENT_THD_N_TAG(N)                                           \
    struct CurrentThd##N##ReadOnlyTag                                         \
    {                                                                         \
        static constexpr std::string_view name           = "current_thd_" #N; \
        static constexpr std::string_view unit           = "%";               \
        static constexpr bool             isControllable = false;             \
    };                                                                        \
    using CurrentThd##N##Metric = MetricBase<float, CurrentThd##N##ReadOnlyTag>;

DEFINE_CURRENT_THD_N_TAG(1)
DEFINE_CURRENT_THD_N_TAG(2)
DEFINE_CURRENT_THD_N_TAG(3)
#undef DEFINE_CURRENT_THD_N_TAG

// 178. active_demand_reverse (kW, real, false)
struct ActiveDemandReverseReadOnlyTag
{
    static constexpr std::string_view name           = "active_demand_reverse";
    static constexpr std::string_view unit           = "kW";
    static constexpr bool             isControllable = false;
};
using ActiveDemandReverseMetric = MetricBase<float, ActiveDemandReverseReadOnlyTag>;

// 179. reactive_demand_positive (kvar, real, false)
struct ReactiveDemandPositiveReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_demand_positive";
    static constexpr std::string_view unit           = "kvar";
    static constexpr bool             isControllable = false;
};
using ReactiveDemandPositiveMetric = MetricBase<float, ReactiveDemandPositiveReadOnlyTag>;

// 180. reactive_demand_reverse (kvar, real, false)
struct ReactiveDemandReverseReadOnlyTag
{
    static constexpr std::string_view name           = "reactive_demand_reverse";
    static constexpr std::string_view unit           = "kvar";
    static constexpr bool             isControllable = false;
};
using ReactiveDemandReverseMetric = MetricBase<float, ReactiveDemandReverseReadOnlyTag>;

// 181. voltage_unbalance (% , percentage, false)
struct VoltageUnbalanceReadOnlyTag
{
    static constexpr std::string_view name           = "voltage_unbalance";
    static constexpr std::string_view unit           = "%";
    static constexpr bool             isControllable = false;
};
using VoltageUnbalanceMetric = MetricBase<float, VoltageUnbalanceReadOnlyTag>;

// 182. active_energy_spike (kWh, real, false)
struct ActiveEnergySpikeReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_spike";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergySpikeMetric = MetricBase<float, ActiveEnergySpikeReadOnlyTag>;

// 183. active_energy_peak (kWh, real, false)
struct ActiveEnergyPeakReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_peak";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyPeakMetric = MetricBase<float, ActiveEnergyPeakReadOnlyTag>;

// 184. active_energy_flat (kWh, real, false)
struct ActiveEnergyFlatReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_flat";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyFlatMetric = MetricBase<float, ActiveEnergyFlatReadOnlyTag>;

// 185. active_energy_valley (kWh, real, false)
struct ActiveEnergyValleyReadOnlyTag
{
    static constexpr std::string_view name           = "active_energy_valley";
    static constexpr std::string_view unit           = "kWh";
    static constexpr bool             isControllable = false;
};
using ActiveEnergyValleyMetric = MetricBase<float, ActiveEnergyValleyReadOnlyTag>;

// 186. reactive_energy_q1 through reactive_energy_q4 (kvarh, real, false)
#define DEFINE_REACTIVE_ENERGY_Q_N_TAG(N)                                          \
    struct ReactiveEnergyQ##N##ReadOnlyTag                                         \
    {                                                                              \
        static constexpr std::string_view name           = "reactive_energy_q" #N; \
        static constexpr std::string_view unit           = "kvarh";                \
        static constexpr bool             isControllable = false;                  \
    };                                                                             \
    using ReactiveEnergyQ##N##Metric = MetricBase<float, ReactiveEnergyQ##N##ReadOnlyTag>;

DEFINE_REACTIVE_ENERGY_Q_N_TAG(1)
DEFINE_REACTIVE_ENERGY_Q_N_TAG(2)
DEFINE_REACTIVE_ENERGY_Q_N_TAG(3)
DEFINE_REACTIVE_ENERGY_Q_N_TAG(4)
#undef DEFINE_REACTIVE_ENERGY_Q_N_TAG

}  // namespace sensgreen::device
