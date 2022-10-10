// MESSAGE EFI_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief EFI_STATUS message
 *
 * EFI Status Output
 */
struct EFI_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 225;
    static constexpr size_t LENGTH = 53;
    static constexpr size_t MIN_LENGTH = 53;
    static constexpr uint8_t CRC_EXTRA = 142;
    static constexpr auto NAME = "EFI_STATUS";


    uint8_t health; /*<  EFI Health status */
    float ecu_index; /*<  ECU Index */
    float rpm; /*<  RPM */
    float fuel_consumed; /*< [g] Fuel Consumed (grams) */
    float fuel_flow; /*< [g/min] Fuel Flow Rate (g/min) */
    float engine_load; /*< [%] Engine Load (%) */
    float throttle_position; /*< [%] Throttle Position (%) */
    float spark_dwell_time; /*< [ms] Spark Dwell Time (ms) */
    float barometric_pressure; /*< [kPa] Barometric Pressure (kPa) */
    float intake_manifold_pressure; /*< [kPa] Intake Manifold Pressure (kPa)( */
    float intake_manifold_temperature; /*< [degC] Intake Manifold Temperature (degC) */
    float cylinder_head_temperature; /*< [degC] cylinder_head_temperature (degC) */
    float ignition_timing; /*< [deg] Ignition timing for cylinder i (Crank Angle degrees) */
    float injection_time; /*< [ms] Injection time for injector i (ms) */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  health: " << +health << std::endl;
        ss << "  ecu_index: " << ecu_index << std::endl;
        ss << "  rpm: " << rpm << std::endl;
        ss << "  fuel_consumed: " << fuel_consumed << std::endl;
        ss << "  fuel_flow: " << fuel_flow << std::endl;
        ss << "  engine_load: " << engine_load << std::endl;
        ss << "  throttle_position: " << throttle_position << std::endl;
        ss << "  spark_dwell_time: " << spark_dwell_time << std::endl;
        ss << "  barometric_pressure: " << barometric_pressure << std::endl;
        ss << "  intake_manifold_pressure: " << intake_manifold_pressure << std::endl;
        ss << "  intake_manifold_temperature: " << intake_manifold_temperature << std::endl;
        ss << "  cylinder_head_temperature: " << cylinder_head_temperature << std::endl;
        ss << "  ignition_timing: " << ignition_timing << std::endl;
        ss << "  injection_time: " << injection_time << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ecu_index;                     // offset: 0
        map << rpm;                           // offset: 4
        map << fuel_consumed;                 // offset: 8
        map << fuel_flow;                     // offset: 12
        map << engine_load;                   // offset: 16
        map << throttle_position;             // offset: 20
        map << spark_dwell_time;              // offset: 24
        map << barometric_pressure;           // offset: 28
        map << intake_manifold_pressure;      // offset: 32
        map << intake_manifold_temperature;   // offset: 36
        map << cylinder_head_temperature;     // offset: 40
        map << ignition_timing;               // offset: 44
        map << injection_time;                // offset: 48
        map << health;                        // offset: 52
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ecu_index;                     // offset: 0
        map >> rpm;                           // offset: 4
        map >> fuel_consumed;                 // offset: 8
        map >> fuel_flow;                     // offset: 12
        map >> engine_load;                   // offset: 16
        map >> throttle_position;             // offset: 20
        map >> spark_dwell_time;              // offset: 24
        map >> barometric_pressure;           // offset: 28
        map >> intake_manifold_pressure;      // offset: 32
        map >> intake_manifold_temperature;   // offset: 36
        map >> cylinder_head_temperature;     // offset: 40
        map >> ignition_timing;               // offset: 44
        map >> injection_time;                // offset: 48
        map >> health;                        // offset: 52
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
