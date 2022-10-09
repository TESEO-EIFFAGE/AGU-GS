#ifndef HMI_H
#define HMI_H
#include "mavlinkprotocol.h"
#include <QObject>
#include <AGU_MAVLINK/mavlink.h>
#include <bitset>

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);

    /* TELEMETRY */

    Q_PROPERTY(quint64 TimeStamp MEMBER m_TimeStamp NOTIFY TimeStampChanged)
    Q_PROPERTY(quint64 TimeStampRIO MEMBER m_TimeStampRIO NOTIFY TimeStampRIOChanged)
    Q_PROPERTY(qint32 Latitude MEMBER m_Latitude NOTIFY LatitudeChanged)
    Q_PROPERTY(qint32 Longitude MEMBER m_Longitude NOTIFY LongitudeChanged)
    Q_PROPERTY(quint32 GNSSAltitude MEMBER m_GNSSAltitude NOTIFY GNSSAltitudeChanged)
    Q_PROPERTY(qint16 AirSpeed_UVector MEMBER m_AirSpeed_UVector NOTIFY AirSpeed_UVectorChanged)
    Q_PROPERTY(qint16 AirSpeed_VVector MEMBER m_AirSpeed_VVector NOTIFY AirSpeed_VVectorChanged)
    Q_PROPERTY(qint16 AirSpeed_WVector MEMBER m_AirSpeed_WVector NOTIFY AirSpeed_WVectorChanged)
    Q_PROPERTY(qint16 AirTemperature MEMBER m_AirTemperature NOTIFY AirTemperatureChanged)
    Q_PROPERTY(qint32 AltitudeFromRadarAltimeter MEMBER m_AltitudeFromRadarAltimeter NOTIFY AltitudeFromRadarAltimeterChanged)
    Q_PROPERTY(qint32 AltitudeFromPayloadAltimeter MEMBER m_AltitudeFromPayloadAltimeter NOTIFY AltitudeFromPayloadAltimeterChanged)
    Q_PROPERTY(quint16 LinearVelocityHorizontal MEMBER m_LinearVelocityHorizontal NOTIFY LinearVelocityHorizontalChanged)
    Q_PROPERTY(qint16 LinearVelocityVertical MEMBER m_LinearVelocityVertical NOTIFY LinearVelocityVerticalChanged)
    Q_PROPERTY(quint16 PositionAccuracy MEMBER m_PositionAccuracy NOTIFY PositionAccuracyChanged)
    Q_PROPERTY(quint16 SpeedAccuracy MEMBER m_SpeedAccuracy NOTIFY SpeedAccuracyChanged)
    Q_PROPERTY(qint16 LinearAccelerationX MEMBER m_LinearAccelerationX NOTIFY LinearAccelerationXChanged)
    Q_PROPERTY(qint16 LinearAccelerationY MEMBER m_LinearAccelerationY NOTIFY LinearAccelerationYChanged)
    Q_PROPERTY(qint16 LinearAccelerationZ MEMBER m_LinearAccelerationZ NOTIFY LinearAccelerationZChanged)
    Q_PROPERTY(float ECEFVectorPositionX MEMBER m_ECEFVectorPositionX NOTIFY ECEFVectorPositionXChanged)
    Q_PROPERTY(float ECEFVectorPositionY MEMBER m_ECEFVectorPositionY NOTIFY ECEFVectorPositionYChanged)
    Q_PROPERTY(float ECEFVectorPositionZ MEMBER m_ECEFVectorPositionZ NOTIFY ECEFVectorPositionZChanged)
    Q_PROPERTY(float ECEFVectorVelocityX MEMBER m_ECEFVectorVelocityX NOTIFY ECEFVectorVelocityXChanged)
    Q_PROPERTY(float ECEFVectorVelocityY MEMBER m_ECEFVectorVelocityY NOTIFY ECEFVectorVelocityYChanged)
    Q_PROPERTY(float ECEFVectorVelocityZ MEMBER m_ECEFVectorVelocityZ NOTIFY ECEFVectorVelocityZChanged)
    Q_PROPERTY(qint16 RollAngle MEMBER m_RollAngle NOTIFY RollAngleChanged)
    Q_PROPERTY(qint16 PitchAngle MEMBER m_PitchAngle NOTIFY PitchAngleChanged)
    Q_PROPERTY(qint16 YawAngle MEMBER m_YawAngle NOTIFY YawAngleChanged)
    Q_PROPERTY(qint16 AngularRateRoll MEMBER m_AngularRateRoll NOTIFY AngularRateRollChanged)
    Q_PROPERTY(qint16 AngularRatePitch MEMBER m_AngularRatePitch NOTIFY AngularRatePitchChanged)
    Q_PROPERTY(qint16 AngularRateYaw MEMBER m_AngularRateYaw NOTIFY AngularRateYawChanged)
    //    Q_PROPERTY(double Quaternion0 MEMBER m_Quaternion0 NOTIFY Quaternion0Changed)
    //    Q_PROPERTY(double Quaternion1 MEMBER m_Quaternion1 NOTIFY Quaternion1Changed)
    //    Q_PROPERTY(double Quaternion2 MEMBER m_Quaternion2 NOTIFY Quaternion2Changed)
    //    Q_PROPERTY(double Quaternion3 MEMBER m_Quaternion3 NOTIFY Quaternion3Changed)
    Q_PROPERTY(quint8 NumberOfGPSSatellite MEMBER m_NumberOfGPSSatellite NOTIFY NumberOfGPSSatelliteChanged)
    Q_PROPERTY(quint8 AnemCommErrorCounter MEMBER m_AnemCommErrorCounter NOTIFY AnemCommErrorCounterChanged)
    Q_PROPERTY(quint8 RDAltCommErrorCounter MEMBER m_RDAltCommErrorCounter NOTIFY RDAltCommErrorCounterChanged)
    Q_PROPERTY(quint8 GNSSCommErrorCounter MEMBER m_GNSSCommErrorCounter NOTIFY GNSSCommErrorCounterChanged)
    Q_PROPERTY(quint8 PLAltCommErrorCounter MEMBER m_PLAltCommErrorCounter NOTIFY PLAltCommErrorCounterChanged)
    Q_PROPERTY(bool telemetry0 MEMBER m_telemetry0 NOTIFY telemetry0Changed)
    Q_PROPERTY(bool telemetry1 MEMBER m_telemetry1 NOTIFY telemetry1Changed)
    Q_PROPERTY(bool telemetry2 MEMBER m_telemetry2 NOTIFY telemetry2Changed)
    Q_PROPERTY(bool telemetry3 MEMBER m_telemetry3 NOTIFY telemetry3Changed)
    Q_PROPERTY(bool telemetry4 MEMBER m_telemetry4 NOTIFY telemetry4Changed)
    Q_PROPERTY(bool telemetry5 MEMBER m_telemetry5 NOTIFY telemetry5Changed)
    Q_PROPERTY(bool telemetry6 MEMBER m_telemetry6 NOTIFY telemetry6Changed)
    Q_PROPERTY(bool telemetry7 MEMBER m_telemetry7 NOTIFY telemetry7Changed)
    Q_PROPERTY(bool telemetry8 MEMBER m_telemetry8 NOTIFY telemetry8Changed)
    Q_PROPERTY(bool telemetry9 MEMBER m_telemetry9 NOTIFY telemetry9Changed)
    Q_PROPERTY(bool telemetry10 MEMBER m_telemetry10 NOTIFY telemetry10Changed)
    Q_PROPERTY(bool telemetry11 MEMBER m_telemetry11 NOTIFY telemetry11Changed)
    Q_PROPERTY(bool telemetry12 MEMBER m_telemetry12 NOTIFY telemetry12Changed)
    Q_PROPERTY(bool telemetry13 MEMBER m_telemetry13 NOTIFY telemetry13Changed)
    Q_PROPERTY(bool telemetry14 MEMBER m_telemetry14 NOTIFY telemetry14Changed)
    Q_PROPERTY(bool telemetry15 MEMBER m_telemetry15 NOTIFY telemetry15Changed)
    Q_PROPERTY(bool telemetry16 MEMBER m_telemetry16 NOTIFY telemetry16Changed)
    Q_PROPERTY(bool telemetry17 MEMBER m_telemetry17 NOTIFY telemetry17Changed)
    Q_PROPERTY(bool telemetry18 MEMBER m_telemetry18 NOTIFY telemetry18Changed)
    Q_PROPERTY(bool telemetry19 MEMBER m_telemetry19 NOTIFY telemetry19Changed)
    Q_PROPERTY(bool telemetry20 MEMBER m_telemetry20 NOTIFY telemetry20Changed)
    Q_PROPERTY(bool telemetry21 MEMBER m_telemetry21 NOTIFY telemetry21Changed)
    Q_PROPERTY(bool telemetry22 MEMBER m_telemetry22 NOTIFY telemetry22Changed)
    Q_PROPERTY(bool telemetry23 MEMBER m_telemetry23 NOTIFY telemetry23Changed)
    Q_PROPERTY(bool telemetry24 MEMBER m_telemetry24 NOTIFY telemetry24Changed)
    Q_PROPERTY(bool telemetry25 MEMBER m_telemetry25 NOTIFY telemetry25Changed)
    Q_PROPERTY(bool telemetry26 MEMBER m_telemetry26 NOTIFY telemetry26Changed)
    Q_PROPERTY(bool telemetry27 MEMBER m_telemetry27 NOTIFY telemetry27Changed)
    Q_PROPERTY(bool telemetry28 MEMBER m_telemetry28 NOTIFY telemetry28Changed)
    Q_PROPERTY(bool telemetry29 MEMBER m_telemetry29 NOTIFY telemetry29Changed)
    Q_PROPERTY(bool telemetry30 MEMBER m_telemetry30 NOTIFY telemetry30Changed)
    Q_PROPERTY(bool telemetry31 MEMBER m_telemetry31 NOTIFY telemetry31Changed)

    /* MOTOR */

    Q_PROPERTY(quint64 MotorTimestamp MEMBER m_MotorTimestamp NOTIFY MotorTimestampChanged)

    Q_PROPERTY(qint32 MotorARealPosition MEMBER m_MotorARealPosition NOTIFY MotorARealPositionChanged)
    Q_PROPERTY(qint32 MotorADemandPosition MEMBER m_MotorADemandPosition NOTIFY MotorADemandPositionChanged)
    Q_PROPERTY(qint32 MotorATorque MEMBER m_MotorATorque NOTIFY MotorATorqueChanged)
    Q_PROPERTY(qint16 MotorATemp MEMBER m_MotorATemp NOTIFY MotorATempChanged)

    Q_PROPERTY(qint32 MotorBRealPosition MEMBER m_MotorBRealPosition NOTIFY MotorBRealPositionChanged)
    Q_PROPERTY(qint32 MotorBDemandPosition MEMBER m_MotorBDemandPosition NOTIFY MotorBDemandPositionChanged)
    Q_PROPERTY(qint32 MotorBTorque MEMBER m_MotorBTorque NOTIFY MotorBTorqueChanged)
    Q_PROPERTY(qint16 MotorBTemp MEMBER m_MotorBTemp NOTIFY MotorBTempChanged)

    Q_PROPERTY(quint16 BMSVoltage MEMBER m_BMSVoltage NOTIFY BMSVoltageChanged)
    Q_PROPERTY(qint16 BMSAbsorption MEMBER m_BMSAbsorption NOTIFY BMSAbsorptionChanged)
    Q_PROPERTY(qint16 BMSTemp MEMBER m_BMSTemp NOTIFY BMSTempChanged)

    Q_PROPERTY(quint32 MotorAFaultsMask MEMBER m_MotorAFaultsMask NOTIFY MotorAFaultsMaskChanged)
    Q_PROPERTY(quint32 MotorBFaultsMask MEMBER m_MotorBFaultsMask NOTIFY MotorBFaultsMaskChanged)
    Q_PROPERTY(quint32 BMSFaultsMask MEMBER m_BMSFaultsMask NOTIFY BMSFaultsMaskChanged)

    Q_PROPERTY(bool motor0 MEMBER m_motor0 NOTIFY motor0Changed)
    Q_PROPERTY(bool motor1 MEMBER m_motor1 NOTIFY motor1Changed)
    Q_PROPERTY(bool motor2 MEMBER m_motor2 NOTIFY motor2Changed)
    Q_PROPERTY(bool motor3 MEMBER m_motor3 NOTIFY motor3Changed)
    Q_PROPERTY(bool motor4 MEMBER m_motor4 NOTIFY motor4Changed)
    Q_PROPERTY(bool motor5 MEMBER m_motor5 NOTIFY motor5Changed)
    Q_PROPERTY(bool motor6 MEMBER m_motor6 NOTIFY motor6Changed)
    Q_PROPERTY(bool motor7 MEMBER m_motor7 NOTIFY motor7Changed)
    Q_PROPERTY(bool motor8 MEMBER m_motor8 NOTIFY motor8Changed)
    Q_PROPERTY(bool motor10 MEMBER m_motor10 NOTIFY motor10Changed)
    Q_PROPERTY(bool motor11 MEMBER m_motor11 NOTIFY motor11Changed)
    Q_PROPERTY(bool motor12 MEMBER m_motor12 NOTIFY motor12Changed)
    Q_PROPERTY(bool motor13 MEMBER m_motor13 NOTIFY motor13Changed)
    Q_PROPERTY(bool motor14 MEMBER m_motor14 NOTIFY motor14Changed)
    Q_PROPERTY(bool motor15 MEMBER m_motor15 NOTIFY motor15Changed)
    Q_PROPERTY(bool motor16 MEMBER m_motor16 NOTIFY motor16Changed)
    Q_PROPERTY(bool motor17 MEMBER m_motor17 NOTIFY motor17Changed)
    Q_PROPERTY(bool motor18 MEMBER m_motor18 NOTIFY motor18Changed)
    Q_PROPERTY(bool motor19 MEMBER m_motor19 NOTIFY motor19Changed)
    Q_PROPERTY(bool motor20 MEMBER m_motor20 NOTIFY motor20Changed)
    Q_PROPERTY(bool motor21 MEMBER m_motor21 NOTIFY motor21Changed)
    Q_PROPERTY(bool motor22 MEMBER m_motor22 NOTIFY motor22Changed)
    Q_PROPERTY(bool motor23 MEMBER m_motor23 NOTIFY motor23Changed)
    Q_PROPERTY(bool motor24 MEMBER m_motor24 NOTIFY motor24Changed)

    Q_PROPERTY(bool BMS0 MEMBER m_BMS0 NOTIFY BMS0Changed)
    Q_PROPERTY(bool BMS1 MEMBER m_BMS1 NOTIFY BMS1Changed)
    Q_PROPERTY(bool BMS2 MEMBER m_BMS2 NOTIFY BMS2Changed)
    Q_PROPERTY(bool BMS3 MEMBER m_BMS3 NOTIFY BMS3Changed)
    Q_PROPERTY(bool BMS4 MEMBER m_BMS4 NOTIFY BMS4Changed)
    Q_PROPERTY(bool BMS5 MEMBER m_BMS5 NOTIFY BMS5Changed)
    Q_PROPERTY(bool BMS6 MEMBER m_BMS6 NOTIFY BMS6Changed)
    Q_PROPERTY(bool BMS7 MEMBER m_BMS7 NOTIFY BMS7Changed)
    Q_PROPERTY(bool BMS8 MEMBER m_BMS8 NOTIFY BMS8Changed)
    Q_PROPERTY(bool BMS9 MEMBER m_BMS9 NOTIFY BMS9Changed)
    Q_PROPERTY(bool BMS10 MEMBER m_BMS10 NOTIFY BMS10Changed)
    Q_PROPERTY(bool BMS11 MEMBER m_BMS11 NOTIFY BMS11Changed)
    Q_PROPERTY(bool BMS12 MEMBER m_BMS12 NOTIFY BMS12Changed)
    Q_PROPERTY(bool BMS13 MEMBER m_BMS13 NOTIFY BMS13Changed)
    Q_PROPERTY(bool BMS14 MEMBER m_BMS14 NOTIFY BMS14Changed)
    Q_PROPERTY(bool BMS15 MEMBER m_BMS15 NOTIFY BMS15Changed)
    Q_PROPERTY(bool BMS16 MEMBER m_BMS16 NOTIFY BMS16Changed)
    Q_PROPERTY(bool BMS17 MEMBER m_BMS17 NOTIFY BMS17Changed)
    Q_PROPERTY(bool BMS18 MEMBER m_BMS18 NOTIFY BMS18Changed)
    Q_PROPERTY(bool BMS19 MEMBER m_BMS19 NOTIFY BMS19Changed)
    Q_PROPERTY(bool BMS20 MEMBER m_BMS20 NOTIFY BMS20Changed)
    Q_PROPERTY(bool BMS21 MEMBER m_BMS21 NOTIFY BMS21Changed)
    Q_PROPERTY(bool BMS22 MEMBER m_BMS22 NOTIFY BMS22Changed)
    Q_PROPERTY(bool BMS23 MEMBER m_BMS23 NOTIFY BMS23Changed)
    Q_PROPERTY(bool BMS24 MEMBER m_BMS24 NOTIFY BMS24Changed)
    Q_PROPERTY(bool BMS25 MEMBER m_BMS25 NOTIFY BMS25Changed)
    Q_PROPERTY(bool BMS26 MEMBER m_BMS26 NOTIFY BMS26Changed)
    Q_PROPERTY(bool BMS27 MEMBER m_BMS27 NOTIFY BMS27Changed)
    Q_PROPERTY(bool BMS28 MEMBER m_BMS28 NOTIFY BMS28Changed)
    Q_PROPERTY(bool BMS29 MEMBER m_BMS29 NOTIFY BMS29Changed)
    Q_PROPERTY(bool BMS30 MEMBER m_BMS30 NOTIFY BMS30Changed)
    Q_PROPERTY(bool BMS31 MEMBER m_BMS31 NOTIFY BMS31Changed)

    /* SYSTEM */

    Q_PROPERTY(quint8 FlightMode MEMBER m_FlightMode NOTIFY FlightModeChanged)
    Q_PROPERTY(quint8 FlightPhase MEMBER m_FlightPhase NOTIFY FlightPhaseChanged)
    Q_PROPERTY(quint32 FlightPhaseExecutionTime MEMBER m_FlightPhaseExecutionTime NOTIFY FlightPhaseExecutionTimeChanged)
    Q_PROPERTY(quint32 CoreModuleStatusMask MEMBER m_CoreModuleStatusMask NOTIFY CoreModuleStatusMaskChanged)
    Q_PROPERTY(quint64 TelemetryModuleStatusMask MEMBER m_TelemetryModuleStatusMask NOTIFY TelemetryModuleStatusMaskChanged)
    Q_PROPERTY(quint32 GuidanceModuleStatusMask MEMBER m_GuidanceModuleStatusMask NOTIFY GuidanceModuleStatusMaskChanged)
    Q_PROPERTY(quint32 StorageModuleStatusMask MEMBER m_StorageModuleStatusMask NOTIFY StorageModuleStatusMaskChanged)
    Q_PROPERTY(quint32 RadioLinkModuleStatusMask MEMBER m_RadioLinkModuleStatusMask NOTIFY RadioLinkModuleStatusMaskChanged)
    Q_PROPERTY(quint32 MotorControlStatusMask MEMBER m_MotorControlStatusMask NOTIFY MotorControlStatusMaskChanged)

    /* TBD */

    Q_PROPERTY(quint8 GSRLErrorCounter MEMBER m_GSRLErrorCounter NOTIFY GSRLErrorCounterChanged)
    Q_PROPERTY(quint8 FSRLErrorCounter MEMBER m_FSRLErrorCounter NOTIFY FSRLErrorCounterChanged)
    Q_PROPERTY(quint8 RLHeartbeatCounter MEMBER m_RLHeartbeatCounter NOTIFY RLHeartbeatCounterChanged)

    Q_PROPERTY(bool storage0 MEMBER m_storage0 NOTIFY storage0Changed)
    Q_PROPERTY(bool storage1 MEMBER m_storage1 NOTIFY storage1Changed)
    Q_PROPERTY(bool storage2 MEMBER m_storage2 NOTIFY storage2Changed)
    Q_PROPERTY(bool storage3 MEMBER m_storage3 NOTIFY storage3Changed)
    Q_PROPERTY(bool storage4 MEMBER m_storage4 NOTIFY storage4Changed)
    Q_PROPERTY(bool storage5 MEMBER m_storage5 NOTIFY storage5Changed)
    Q_PROPERTY(bool storage6 MEMBER m_storage6 NOTIFY storage6Changed)
    Q_PROPERTY(bool storage7 MEMBER m_storage7 NOTIFY storage7Changed)
    Q_PROPERTY(bool storage8 MEMBER m_storage8 NOTIFY storage8Changed)
    Q_PROPERTY(bool storage10 MEMBER m_storage10 NOTIFY storage10Changed)
    Q_PROPERTY(bool storage11 MEMBER m_storage11 NOTIFY storage11Changed)
    Q_PROPERTY(bool storage12 MEMBER m_storage12 NOTIFY storage12Changed)
    Q_PROPERTY(bool storage13 MEMBER m_storage13 NOTIFY storage13Changed)
    Q_PROPERTY(bool storage14 MEMBER m_storage14 NOTIFY storage14Changed)
    Q_PROPERTY(bool storage15 MEMBER m_storage15 NOTIFY storage15Changed)
    Q_PROPERTY(bool storage16 MEMBER m_storage16 NOTIFY storage16Changed)
    Q_PROPERTY(bool storage17 MEMBER m_storage17 NOTIFY storage17Changed)
    Q_PROPERTY(bool storage18 MEMBER m_storage18 NOTIFY storage18Changed)
    Q_PROPERTY(bool storage19 MEMBER m_storage19 NOTIFY storage19Changed)
    Q_PROPERTY(bool storage20 MEMBER m_storage20 NOTIFY storage20Changed)
    Q_PROPERTY(bool storage21 MEMBER m_storage21 NOTIFY storage21Changed)
    Q_PROPERTY(bool storage22 MEMBER m_storage22 NOTIFY storage22Changed)
    Q_PROPERTY(bool storage23 MEMBER m_storage23 NOTIFY storage23Changed)

    Q_PROPERTY(bool core0 MEMBER m_core0 NOTIFY core0Changed)
    Q_PROPERTY(bool core1 MEMBER m_core1 NOTIFY core1Changed)
    Q_PROPERTY(bool core2 MEMBER m_core2 NOTIFY core2Changed)
    Q_PROPERTY(bool core3 MEMBER m_core3 NOTIFY core3Changed)
    Q_PROPERTY(bool core4 MEMBER m_core4 NOTIFY core4Changed)

    Q_PROPERTY(bool radiolink0 MEMBER m_radiolink0 NOTIFY radiolink0Changed)
    Q_PROPERTY(bool radiolink1 MEMBER m_radiolink1 NOTIFY radiolink1Changed)
    Q_PROPERTY(bool radiolink2 MEMBER m_radiolink2 NOTIFY radiolink2Changed)
    Q_PROPERTY(bool radiolink3 MEMBER m_radiolink3 NOTIFY radiolink3Changed)
    Q_PROPERTY(bool radiolink8 MEMBER m_radiolink8 NOTIFY radiolink8Changed)
    Q_PROPERTY(bool radiolink9 MEMBER m_radiolink9 NOTIFY radiolink9Changed)

    Q_PROPERTY(bool gnssFound MEMBER m_gnssFound NOTIFY gnssFoundChanged)

public:
    void showData(QVariant data);

signals:
    /* TELEMETRY */

    void TimeStampChanged();
    void TimeStampRIOChanged();
    void LatitudeChanged();
    void LongitudeChanged();
    void GNSSAltitudeChanged();
    void AirSpeed_UVectorChanged();
    void AirSpeed_VVectorChanged();
    void AirSpeed_WVectorChanged();
    void AirTemperatureChanged();
    void AltitudeFromRadarAltimeterChanged();
    void AltitudeFromPayloadAltimeterChanged();
    void LinearVelocityHorizontalChanged();
    void LinearVelocityVerticalChanged();
    void PositionAccuracyChanged();
    void SpeedAccuracyChanged();
    void LinearAccelerationXChanged();
    void LinearAccelerationYChanged();
    void LinearAccelerationZChanged();
    void ECEFVectorPositionXChanged();
    void ECEFVectorPositionYChanged();
    void ECEFVectorPositionZChanged();
    void ECEFVectorVelocityXChanged();
    void ECEFVectorVelocityYChanged();
    void ECEFVectorVelocityZChanged();
    void RollAngleChanged();
    void PitchAngleChanged();
    void YawAngleChanged();
    void AngularRateRollChanged();
    void AngularRatePitchChanged();
    void AngularRateYawChanged();
//    void Quaternion0Changed();
//    void Quaternion1Changed();
//    void Quaternion2Changed();
//    void Quaternion3Changed();
    void NumberOfGPSSatelliteChanged();

    void telemetry0Changed();
    void telemetry1Changed();
    void telemetry2Changed();
    void telemetry3Changed();
    void telemetry4Changed();
    void telemetry5Changed();
    void telemetry6Changed();
    void telemetry7Changed();
    void telemetry8Changed();
    void telemetry9Changed();
    void telemetry10Changed();
    void telemetry11Changed();
    void telemetry12Changed();
    void telemetry13Changed();
    void telemetry14Changed();
    void telemetry15Changed();
    void telemetry16Changed();
    void telemetry17Changed();
    void telemetry18Changed();
    void telemetry19Changed();
    void telemetry20Changed();
    void telemetry21Changed();
    void telemetry22Changed();
    void telemetry23Changed();
    void telemetry24Changed();
    void telemetry25Changed();
    void telemetry26Changed();
    void telemetry27Changed();
    void telemetry28Changed();
    void telemetry29Changed();
    void telemetry30Changed();
    void telemetry31Changed();

    void AnemCommErrorCounterChanged();
    void RDAltCommErrorCounterChanged();
    void GNSSCommErrorCounterChanged();
    void PLAltCommErrorCounterChanged();

    /* MOTOR */

    void MotorARealPositionChanged();
    void MotorADemandPositionChanged();
    void MotorATorqueChanged();
    void MotorATempChanged();

    void MotorBRealPositionChanged();
    void MotorBDemandPositionChanged();
    void MotorBTorqueChanged();
    void MotorBTempChanged();

    void BMSVoltageChanged();
    void BMSAbsorptionChanged();
    void BMSTempChanged();

    void MotorControlStatusMaskChanged();
    void MotorAFaultsMaskChanged();
    void MotorBFaultsMaskChanged();
    void BMSFaultsMaskChanged();

    void MotorTimestampChanged();

    void ChargeValueChanged();

    void motor0Changed();
    void motor1Changed();
    void motor2Changed();
    void motor3Changed();
    void motor4Changed();
    void motor5Changed();
    void motor6Changed();
    void motor7Changed();
    void motor8Changed();
    void motor10Changed();
    void motor11Changed();
    void motor12Changed();
    void motor13Changed();
    void motor14Changed();
    void motor15Changed();
    void motor16Changed();
    void motor17Changed();
    void motor18Changed();
    void motor19Changed();
    void motor20Changed();
    void motor21Changed();
    void motor22Changed();
    void motor23Changed();
    void motor24Changed();

    void BMS0Changed();
    void BMS1Changed();
    void BMS2Changed();
    void BMS3Changed();
    void BMS4Changed();
    void BMS5Changed();
    void BMS6Changed();
    void BMS7Changed();
    void BMS8Changed();
    void BMS9Changed();
    void BMS10Changed();
    void BMS11Changed();
    void BMS12Changed();
    void BMS13Changed();
    void BMS14Changed();
    void BMS15Changed();
    void BMS16Changed();
    void BMS17Changed();
    void BMS18Changed();
    void BMS19Changed();
    void BMS20Changed();
    void BMS21Changed();
    void BMS22Changed();
    void BMS23Changed();
    void BMS24Changed();
    void BMS25Changed();
    void BMS26Changed();
    void BMS27Changed();
    void BMS28Changed();
    void BMS29Changed();
    void BMS30Changed();
    void BMS31Changed();

    /* STATUS */

    void StatusFlightPhaseChanged();
    void RadioLinkModuleStatusMaskChanged();
    void StorageModuleStatusMaskChanged();
    void GuidanceModuleStatusMaskChanged();
    void TelemetryModuleStatusMaskChanged();
    void CoreModuleStatusMaskChanged();
    void FlightPhaseExecutionTimeChanged();
    void FlightPhaseChanged();
    void FlightModeChanged();

    /* ETC */

    void gnssFoundChanged();
    void GSRLErrorCounterChanged();
    void RLHeartbeatCounterChanged();
    void FSRLErrorCounterChanged();

    void core0Changed();
    void core1Changed();
    void core2Changed();
    void core3Changed();
    void core4Changed();

    void radiolink0Changed();
    void radiolink1Changed();
    void radiolink2Changed();
    void radiolink3Changed();
    void radiolink8Changed();
    void radiolink9Changed();

    void storage0Changed();
    void storage1Changed();
    void storage2Changed();
    void storage3Changed();
    void storage4Changed();
    void storage5Changed();
    void storage6Changed();
    void storage7Changed();
    void storage8Changed();
    void storage10Changed();
    void storage11Changed();
    void storage12Changed();
    void storage13Changed();
    void storage14Changed();
    void storage15Changed();
    void storage16Changed();
    void storage17Changed();
    void storage18Changed();
    void storage19Changed();
    void storage20Changed();
    void storage21Changed();
    void storage22Changed();
    void storage23Changed();

private:
    uint8_t extractBits64(const std::bitset<64> the_bitset, size_t start_bit, size_t end_bit);
    void showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry);
    void showDataSystemStatus(const mavlink_system_status_pack_t msg_system_status);
    void showDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status);
    void showDataRLStatus(const mavlink_radio_status_t /*msg_radio_status*/){};
    void showDataStorageStatus(const mavlink_storage_information_t /*msg_storage_info*/){};

    quint64 m_TimeStamp{};
    quint64 m_TimeStampRIO{};
    qint32 m_Latitude{};
    qint32 m_Longitude{};
    quint32 m_GNSSAltitude{};
    qint16 m_AirSpeed_UVector{};
    qint16 m_AirSpeed_VVector{};
    qint16 m_AirSpeed_WVector{};
    qint16 m_AirTemperature{};
    qint32 m_AltitudeFromRadarAltimeter{};
    qint32 m_AltitudeFromPayloadAltimeter{};
    quint16 m_LinearVelocityHorizontal{};
    qint16 m_LinearVelocityVertical{};
    quint16 m_PositionAccuracy{};
    quint16 m_SpeedAccuracy{};
    qint16 m_LinearAccelerationX{};
    qint16 m_LinearAccelerationY{};
    qint16 m_LinearAccelerationZ{};
    float m_ECEFVectorPositionX{};
    float m_ECEFVectorPositionY{};
    float m_ECEFVectorPositionZ{};
    float m_ECEFVectorVelocityX{};
    float m_ECEFVectorVelocityY{};
    float m_ECEFVectorVelocityZ{};
    qint16 m_RollAngle{};
    qint16 m_PitchAngle{};
    qint16 m_YawAngle{};
    qint16 m_AngularRateRoll{};
    qint16 m_AngularRatePitch{};
    qint16 m_AngularRateYaw{};
//    double m_Quaternion0{};
//    double m_Quaternion1{};
//    double m_Quaternion2{};
//    double m_Quaternion3{};
    quint8 m_NumberOfGPSSatellite{};
    quint8 m_AnemCommErrorCounter;
    quint8 m_RDAltCommErrorCounter;
    quint8 m_GNSSCommErrorCounter;
    quint8 m_PLAltCommErrorCounter;

    bool m_telemetry0;
    bool m_telemetry1;
    bool m_telemetry2;
    bool m_telemetry3;
    bool m_telemetry4;
    bool m_telemetry5;
    bool m_telemetry6;
    bool m_telemetry7;
    bool m_telemetry8;
    bool m_telemetry9;
    bool m_telemetry10;
    bool m_telemetry11;
    bool m_telemetry12;
    bool m_telemetry13;
    bool m_telemetry14;
    bool m_telemetry15;
    bool m_telemetry16;
    bool m_telemetry17;
    bool m_telemetry18;
    bool m_telemetry19;
    bool m_telemetry20;
    bool m_telemetry21;
    bool m_telemetry22;
    bool m_telemetry23;
    bool m_telemetry24;
    bool m_telemetry25;
    bool m_telemetry26;
    bool m_telemetry27;
    bool m_telemetry28;
    bool m_telemetry29;
    bool m_telemetry30;
    bool m_telemetry31;

    bool m_storage0;
    bool m_storage1;
    bool m_storage2;
    bool m_storage3;
    bool m_storage4;
    bool m_storage5;
    bool m_storage6;
    bool m_storage7;
    bool m_storage8;
    bool m_storage10;
    bool m_storage11;
    bool m_storage12;
    bool m_storage13;
    bool m_storage14;
    bool m_storage15;
    bool m_storage16;
    bool m_storage17;
    bool m_storage18;
    bool m_storage19;
    bool m_storage20;
    bool m_storage21;
    bool m_storage22;
    bool m_storage23;

    bool m_motor0;
    bool m_motor1;
    bool m_motor2;
    bool m_motor3;
    bool m_motor4;
    bool m_motor5;
    bool m_motor6;
    bool m_motor7;
    bool m_motor8;
    bool m_motor10;
    bool m_motor11;
    bool m_motor12;
    bool m_motor13;
    bool m_motor14;
    bool m_motor15;
    bool m_motor16;
    bool m_motor17;
    bool m_motor18;
    bool m_motor19;
    bool m_motor20;
    bool m_motor21;
    bool m_motor22;
    bool m_motor23;
    bool m_motor24;

    quint64 m_MotorTimestamp;

    qint32 m_MotorARealPosition;
    qint32 m_MotorADemandPosition;
    qint32 m_MotorATorque;
    qint16 m_MotorATemp;

    qint32 m_MotorBRealPosition;
    qint32 m_MotorBDemandPosition;
    qint32 m_MotorBTorque;
    qint16 m_MotorBTemp;

    quint16 m_BMSVoltage;
    qint16 m_BMSAbsorption;
    qint16 m_BMSTemp;

    int m_ChargeValue;

    quint32 m_MotorAFaultsMask;
    quint32 m_MotorBFaultsMask;
    quint32 m_BMSFaultsMask;

    bool m_BMS0;
    bool m_BMS1;
    bool m_BMS2;
    bool m_BMS3;
    bool m_BMS4;
    bool m_BMS5;
    bool m_BMS6;
    bool m_BMS7;
    bool m_BMS8;
    bool m_BMS9;
    bool m_BMS10;
    bool m_BMS11;
    bool m_BMS12;
    bool m_BMS13;
    bool m_BMS14;
    bool m_BMS15;
    bool m_BMS16;
    bool m_BMS17;
    bool m_BMS18;
    bool m_BMS19;
    bool m_BMS20;
    bool m_BMS21;
    bool m_BMS22;
    bool m_BMS23;
    bool m_BMS24;
    bool m_BMS25;
    bool m_BMS26;
    bool m_BMS27;
    bool m_BMS28;
    bool m_BMS29;
    bool m_BMS30;
    bool m_BMS31;
    bool m_gnssFound;
    int m_GSRLErrorCounter;
    int m_RLHeartbeatCounter;
    int m_FSRLErrorCounter;
    bool m_core0;
    bool m_core1;
    bool m_core2;
    bool m_core3;
    bool m_core4;
    bool m_radiolink0;
    bool m_radiolink1;
    bool m_radiolink2;
    bool m_radiolink3;
    bool m_radiolink8;
    bool m_radiolink9;
    quint32 m_RadioLinkModuleStatusMask;
    quint32 m_StorageModuleStatusMask;
    quint32 m_GuidanceModuleStatusMask;
    quint64 m_TelemetryModuleStatusMask;
    quint32 m_CoreModuleStatusMask;
    qint32 m_FlightPhaseExecutionTime;
    quint8 m_FlightPhase;
    quint8 m_FlightMode;
    quint32 m_MotorControlStatusMask;
};

#endif // HMI_H
