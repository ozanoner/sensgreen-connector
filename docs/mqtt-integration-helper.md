[![Sensgreen](https://sensgreen.com/wp-content/uploads/2017/07/Sensgreen-Logo.png)](https://sensgreen.com)

# How to integrate your any sensor using MQTT

1. Add your devices to [platform.sensgreen.com](http://platform.sensgreen.com)
2. Generate MQTT integration details to forward your data.

| parameter | value |
| --- | --- |
| host | _[ankara.sensgreen.com](mqtt://ankara.sensgreen.com)_|
| port | _1881_ |
| username | _auto-generated_ |
| password | _auto-generated_ |
| topic | _auto-generated_ |
| error-topic | _auto-generated_ |
3. Modify your message as in the below format. _deviceEUI_, _timestamp_ & _data_ can not be empty. An error message publishes to the error topic in that case.

```json
{
   "deviceEui": "string //device identifier that is registered on the platform",
   "timestamp": "timestamp //unix timestamp in milliseconds in UTC (GMT)",
   "data":
   {
   "data_title1": "value1 //instead of data_title, write down your metric such as temperature, humidity",
   "data_title2": "value2 //be sure that metrics you are using exist on the metric table below"
   }
}
```

A JSON sample in correct format:

```json
{
   "deviceEui":"0004a3fb00fb3134",
   "timestamp":1669206315467,
   "data":{
      "temperature":23.6,
      "humidity":61.5,
      "co2":527,
      "voc":3.45,
      "iaq":"74.81",
      "pressure":101350,
      "pm25":26,
      "pm10":27
   }
}
```

### Checklist

- [ ] Add your devices to the platform
- [ ] Format your sensor data JSON
- [ ] Generate your MQTT credentials
- [ ] Publish messages
- [ ] See your data on the platform

### Metric Table

| metric_name | desired unit | metric_type | is_controllable |
| --- | --- | --- | --- |
| temperature | °C | real | false |
| humidity | % | percentage | false |
| pressure | Pa | positive | false |
| co2 | ppm | positive | false |
| voc | mg/m³ | positive | false |
| pm1 | μg/m³ | positive | false |
| pm25 | μg/m³ | positive | false |
| pm4 | μg/m³ | positive | false |
| pm10 | μg/m³ | positive | false |
| dew_point | °C | real | false |
| iaq | | aqi | false |
| p_size | μm | positive | false |
| current | A | real | false |
| power | kWh | real | false |
| occupancy | | boolean | false |
| opened | | boolean | false |
| battery | V | positive | false |
| mounted | | boolean | false |
| peak_current | A | real | false |
| sound_level | dB | positive | false |
| people_count | | real | false |
| people_max | | real | false |
| no2 | ppm | real | false |
| co | ppm | real | false |
| o3 | ppm | real | false |
| voltage_rms_1 | V | real | false |
| current_rms_1 | A | real | false |
| voltage_rms_2 | V | real | false |
| current_rms_2 | A | real | false |
| voltage_rms_3 | V | real | false |
| current_rms_3 | A | real | false |
| temperature_probe | °C | real | false |
| power_factor_1 | | real | false |
| power_factor_2 | | real | false |
| power_factor_3 | | real | false |
| virus_index | | positive | false |
| water_leak | | boolean | false |
| status | | boolean | true |
| power_factor | | real | false |
| power_cut | | boolean | false |
| voltage | V | real | false |
| watering_spikes | | boolean | false |
| water_level_percentage | | percentage | false |
| water_level_millimeters | | positive | false |
| daylight | | boolean | false |
| chn_1 through chn_16 | | various | false |
| RemoteWaterTemperature | °C | real | false |
| FlowBodyWaterTemperature | °C | real | false |
| AbsoluteWaterFlow | m³/h | real | false |
| DifferentialWaterTemperature | °C | real | false |
| periodic_counter_out | | positive | false |
| total_counter_out | | positive | false |
| total_counter_in | | positive | false |
| periodic_counter_in | | positive | false |
| fan_level | | positive | false |
| target_temperature | °C | real | false |
| ac_mode | | positive | false |
| switch_1_status through switch_8_status | | boolean | false |
| switch_1_change through switch_3_change | | boolean | true |
| distance | mm | positive | false |
| remaining | % | percentage | false |
| voltage_1 through voltage_3 | V | positive | false |
| current_1 through current_3 | A | positive | false |
| frequency | Hz | positive | false |
| accumulated_current | Ah | real | false |
| hcho | mg/m³ | real | false |
| light_level | | real | false |
| filter_dirty_status | | boolean | false |
| run_status | | boolean | false |
| return_air_temperature | °C | real | false |
| supply_fan_vfd_speed | | real | false |
| cooling_coil_valve_control | | real | false |
| return_air_temperature_setpoint | | real | false |
| run_command | | boolean | false |
| run_command_sp | | boolean | false |
| override | | boolean | false |
| schedular | | boolean | false |
| supply_air_pressure_setpoint | | real | false |
| cooling_coil_valve_feedback | | real | false |
| auto_manual_status | | boolean | false |
| ra_fire_damper_1_status through ra_fire_damper_3_status | | boolean | false |
| sa_fire_damper_1_status through sa_fire_damper_2_status | | boolean | false |
| trip_status | | boolean | false |
| vfd_on_off_status | | boolean | false |
| supply_air_pressure | | real | false |
| vfd_frequency_feedback | | real | false |
| active_energy | kWh | real | false |
| outlet_temperature | °C | real | false |
| volume_flow_meter | m³ | real | false |
| short_press | | boolean | false |
| double_click | | boolean | false |
| multi_click | | boolean | false |
| click_number | | positive | false |
| long_press | | boolean | false |
| fire_status | | boolean | false |
| supply_air_pressure_2 | | real | false |
| return_air_temperature_sp | °C | real | false |
| chw_valve_feedback | | real | false |
| chilled_water_entering_temperature | °C | real | false |
| chilled_water_leaving_temperature | °C | real | false |
| chw_valve_control | | boolean | false |
| setpoint | °C | real | false |
| space_temperature | °C | real | false |
| damper_position | | real | false |
| airflow | | real | false |
| active_power | kW | real | false |
| apparent_power | kVA | real | false |
| energy_reading | kWH | real | false |
| line_current_b through line_current_y | kA | real | false |
| line_voltage_b through line_voltage_y | kV | real | false |
| phase_voltage_b through phase_voltage_y | kV | real | false |
| fan_run_status | | boolean | false |
| room_temperature | °C | real | false |
| room_humidity | % | real | false |
| supply_louver_status | | boolean | false |
| common_alarm | | boolean | false |
| temperature_high_alarm | | boolean | false |
| temperature_low_alarm | | boolean | false |
| humidity_high_alarm | | boolean | false |
| humidity_low_alarm | | boolean | false |
| filter_alarm | | boolean | false |
| room_humidity_sp | % | real | false |
| fan_speed | | real | false |
| frequency_input | Hz | real | false |
| frequency_output | Hz | real | false |
| battery_voltage | V | real | false |
| battery_current | A | real | false |
| battery_power | kW | real | false |
| ups_power_rating | | real | false |
| total_output_percent_load | | real | false |
| voltage_l1_2_input through voltage_l3_1_input | V | real | false |
| current_l1_input through current_l3_input | A | real | false |
| power_factor_l1_input through power_factor_l3_input | | real | false |
| voltage_l1_2_output through voltage_l3_1_output | V | real | false |
| current_l1_output through current_l3_output | A | real | false |
| power_factor_l1_output through power_factor_l3_output | | real | false |
| efficiency | | real | false |
| active_power_1 through active_power_3 | kW | real | false |
| valve_position | % | percentage | true |
| smoke | | boolean | false |
| luminosity | Lux | real | false |
| reactive_power | kVA | real | false |
| reactive_power_1 through reactive_power_3 | kVA | real | false |
| risk_index | | aqi | false |
| active_energy_1 through active_energy_3 | kWh | real | false |
| reactive_energy | kVArh | real | false |
| reactive_energy_1 through reactive_energy_3 | kVArh | real | false |
| peak_current_1 through peak_current_3 | A | real | false |
| average_current | A | positive | false |
| max_current_deviation | A | positive | false |
| current_unbalance | % | positive | false |
| power_consumption | Wh | real | false |
| light | | real | true |
| design_delta_dew_point | °C | real | false |
| comfort_delta_dew_point | °C | real | false |
| accumulated_current_1 through accumulated_current_3 | Ah | real | false |
| voltage_ab through voltage_ca | V | real | false |
| active_power_total | kW | real | false |
| reactive_power_total | kvar | real | false |
| apparent_power_1 through apparent_power_3 | kVA | real | false |
| apparent_power_total | kVA | real | false |
| signal_strength | dBm | real | false |
| active_energy_positive | kWh | real | false |
| active_energy_reverse | kWh | real | false |
| reactive_energy_positive | kvarh | real | false |
| reactive_energy_reverse | kvarh | real | false |
| active_demand_current | kW | real | false |
| voltage_ratio | | real | false |
| current_ratio | | real | false |
| temperature_1 through temperature_3, temperature_n | °C | real | false |
| current_leakage | A | real | false |
| active_energy_positive_1 through active_energy_positive_3 | kWh | real | false |
| active_energy_reverse_1 through active_energy_reverse_3 | kWh | real | false |
| reactive_energy_positive_1 through reactive_energy_positive_3 | kvarh | real | false |
| reactive_energy_reverse_1 through reactive_energy_reverse_3 | kvarh | real | false |
| voltage_thd_1 through voltage_thd_3 | % | percentage | false |
| current_thd_1 through current_thd_3 | % | percentage | false |
| active_demand_reverse | kW | real | false |
| reactive_demand_positive | kvar | real | false |
| reactive_demand_reverse | kvar | real | false |
| voltage_unbalance | % | percentage | false |
| active_energy_spike | kWh | real | false |
| active_energy_peak | kWh | real | false |
| active_energy_flat | kWh | real | false |
| active_energy_valley | kWh | real | false |
| reactive_energy_q1 through reactive_energy_q4 | kvarh | real | false |

_*contact us from info@sensgreen.com if the metrics that you'd like to see are not included the list_