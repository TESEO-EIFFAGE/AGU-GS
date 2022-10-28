#ifndef HMI_H
#define HMI_H
//#include "mavlinkprotocol.h"
#include <QObject>
#include <AGU_MAVLINK/mavlink.h>
#include <bitset>
#include "QQmlAutoPropertyHelpers.h"
#include<QTimer>

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);


    /* TELEMETRY */

    Q_PROPERTY(quint64 TimeStamp READ TimeStamp WRITE setTimeStamp NOTIFY TimeStampChanged)
    Q_PROPERTY(quint64 TimeStampRIO READ TimeStampRIO WRITE setTimeStampRIO NOTIFY TimeStampRIOChanged)
    Q_PROPERTY(qint32 Latitude READ Latitude WRITE setLatitude NOTIFY LatitudeChanged)
    Q_PROPERTY(qint32 Longitude READ Longitude WRITE setLongitude NOTIFY LongitudeChanged)
    Q_PROPERTY(quint32 GNSSAltitude READ GNSSAltitude WRITE setGNSSAltitude NOTIFY GNSSAltitudeChanged)
    Q_PROPERTY(qint16 AirSpeed_UVector READ AirSpeed_UVector WRITE setAirSpeed_UVector NOTIFY AirSpeed_UVectorChanged)
    Q_PROPERTY(qint16 AirSpeed_VVector READ AirSpeed_VVector WRITE setAirSpeed_VVector NOTIFY AirSpeed_VVectorChanged)
    Q_PROPERTY(qint16 AirSpeed_WVector READ AirSpeed_WVector WRITE setAirSpeed_WVector NOTIFY AirSpeed_WVectorChanged)
    Q_PROPERTY(qint16 AirTemperature READ AirTemperature WRITE setAirTemperature NOTIFY AirTemperatureChanged)
    Q_PROPERTY(qint32 AltitudeFromRadarAltimeter READ AltitudeFromRadarAltimeter WRITE setAltitudeFromRadarAltimeter NOTIFY AltitudeFromRadarAltimeterChanged)
    Q_PROPERTY(qint32 AltitudeFromPayloadAltimeter READ AltitudeFromPayloadAltimeter WRITE setAltitudeFromPayloadAltimeter NOTIFY AltitudeFromPayloadAltimeterChanged)
    Q_PROPERTY(quint16 LinearVelocityHorizontal READ LinearVelocityHorizontal WRITE setLinearVelocityHorizontal NOTIFY LinearVelocityHorizontalChanged)
    Q_PROPERTY(qint16 LinearVelocityVertical READ LinearVelocityVertical WRITE setLinearVelocityVertical NOTIFY LinearVelocityVerticalChanged)
    Q_PROPERTY(quint16 PositionAccuracy READ PositionAccuracy WRITE setPositionAccuracy NOTIFY PositionAccuracyChanged)
    Q_PROPERTY(quint16 SpeedAccuracy READ SpeedAccuracy WRITE setSpeedAccuracy NOTIFY SpeedAccuracyChanged)
    Q_PROPERTY(qint16 LinearAccelerationX READ LinearAccelerationX WRITE setLinearAccelerationX NOTIFY LinearAccelerationXChanged)
    Q_PROPERTY(qint16 LinearAccelerationY READ LinearAccelerationY WRITE setLinearAccelerationY NOTIFY LinearAccelerationYChanged)
    Q_PROPERTY(qint16 LinearAccelerationZ READ LinearAccelerationZ WRITE setLinearAccelerationZ NOTIFY LinearAccelerationZChanged)
    Q_PROPERTY(float ECEFVectorPositionX READ ECEFVectorPositionX WRITE setECEFVectorPositionX NOTIFY ECEFVectorPositionXChanged)
    Q_PROPERTY(float ECEFVectorPositionY READ ECEFVectorPositionY WRITE setECEFVectorPositionY NOTIFY ECEFVectorPositionYChanged)
    Q_PROPERTY(float ECEFVectorPositionZ READ ECEFVectorPositionZ WRITE setECEFVectorPositionZ NOTIFY ECEFVectorPositionZChanged)
    Q_PROPERTY(float ECEFVectorVelocityX READ ECEFVectorVelocityX WRITE setECEFVectorVelocityX NOTIFY ECEFVectorVelocityXChanged)
    Q_PROPERTY(float ECEFVectorVelocityY READ ECEFVectorVelocityY WRITE setECEFVectorVelocityY NOTIFY ECEFVectorVelocityYChanged)
    Q_PROPERTY(float ECEFVectorVelocityZ READ ECEFVectorVelocityZ WRITE setECEFVectorVelocityZ NOTIFY ECEFVectorVelocityZChanged)
    Q_PROPERTY(qint16 RollAngle READ RollAngle WRITE setRollAngle NOTIFY RollAngleChanged)
    Q_PROPERTY(qint16 PitchAngle READ PitchAngle WRITE setPitchAngle NOTIFY PitchAngleChanged)
    Q_PROPERTY(qint16 YawAngle READ YawAngle WRITE setYawAngle NOTIFY YawAngleChanged)
    Q_PROPERTY(qint16 AngularRateRoll READ AngularRateRoll WRITE setAngularRateRoll NOTIFY AngularRateRollChanged)
    Q_PROPERTY(qint16 AngularRatePitch READ AngularRatePitch WRITE setAngularRatePitch NOTIFY AngularRatePitchChanged)
    Q_PROPERTY(qint16 AngularRateYaw READ AngularRateYaw WRITE setAngularRateYaw NOTIFY AngularRateYawChanged)
    Q_PROPERTY(double Quaternion0 READ Quaternion0 WRITE setQuaternion0 NOTIFY Quaternion0Changed)
    Q_PROPERTY(double Quaternion1 READ Quaternion1 WRITE setQuaternion1 NOTIFY Quaternion1Changed)
    Q_PROPERTY(double Quaternion2 READ Quaternion2 WRITE setQuaternion2 NOTIFY Quaternion2Changed)
    Q_PROPERTY(double Quaternion3 READ Quaternion3 WRITE setQuaternion3 NOTIFY Quaternion3Changed)
    Q_PROPERTY(quint8 NumberOfGPSSatellite READ NumberOfGPSSatellite WRITE setNumberOfGPSSatellite NOTIFY NumberOfGPSSatelliteChanged)
    Q_PROPERTY(quint8 AnemCommErrorCounter READ AnemCommErrorCounter WRITE setAnemCommErrorCounter NOTIFY AnemCommErrorCounterChanged)
    Q_PROPERTY(quint8 RDAltCommErrorCounter READ RDAltCommErrorCounter WRITE setRDAltCommErrorCounter NOTIFY RDAltCommErrorCounterChanged)
    Q_PROPERTY(quint8 GNSSCommErrorCounter READ GNSSCommErrorCounter WRITE setGNSSCommErrorCounter NOTIFY GNSSCommErrorCounterChanged)
    Q_PROPERTY(quint8 PLAltCommErrorCounter READ PLAltCommErrorCounter WRITE setPLAltCommErrorCounter NOTIFY PLAltCommErrorCounterChanged)
    Q_PROPERTY(bool telemetry0 READ telemetry0 WRITE settelemetry0 NOTIFY telemetry0Changed)
    Q_PROPERTY(bool telemetry1 READ telemetry1 WRITE settelemetry1 NOTIFY telemetry1Changed)
    Q_PROPERTY(bool telemetry2 READ telemetry2 WRITE settelemetry2 NOTIFY telemetry2Changed)
    Q_PROPERTY(bool telemetry3 READ telemetry3 WRITE settelemetry3 NOTIFY telemetry3Changed)
    Q_PROPERTY(bool telemetry4 READ telemetry4 WRITE settelemetry4 NOTIFY telemetry4Changed)
    Q_PROPERTY(bool telemetry5 READ telemetry5 WRITE settelemetry5 NOTIFY telemetry5Changed)
    Q_PROPERTY(bool telemetry6 READ telemetry6 WRITE settelemetry6 NOTIFY telemetry6Changed)
    Q_PROPERTY(bool telemetry7 READ telemetry7 WRITE settelemetry7 NOTIFY telemetry7Changed)
    Q_PROPERTY(bool telemetry8 READ telemetry8 WRITE settelemetry8 NOTIFY telemetry8Changed)
    Q_PROPERTY(bool telemetry9 READ telemetry9 WRITE settelemetry9 NOTIFY telemetry9Changed)
    Q_PROPERTY(bool telemetry10 READ telemetry10 WRITE settelemetry10 NOTIFY telemetry10Changed)
    Q_PROPERTY(bool telemetry11 READ telemetry11 WRITE settelemetry11 NOTIFY telemetry11Changed)
    Q_PROPERTY(bool telemetry12 READ telemetry12 WRITE settelemetry12 NOTIFY telemetry12Changed)
    Q_PROPERTY(bool telemetry13 READ telemetry13 WRITE settelemetry13 NOTIFY telemetry13Changed)
    Q_PROPERTY(bool telemetry14 READ telemetry14 WRITE settelemetry14 NOTIFY telemetry14Changed)
    Q_PROPERTY(bool telemetry15 READ telemetry15 WRITE settelemetry15 NOTIFY telemetry15Changed)
    Q_PROPERTY(bool telemetry16 READ telemetry16 WRITE settelemetry16 NOTIFY telemetry16Changed)
    Q_PROPERTY(bool telemetry17 READ telemetry17 WRITE settelemetry17 NOTIFY telemetry17Changed)
    Q_PROPERTY(bool telemetry18 READ telemetry18 WRITE settelemetry18 NOTIFY telemetry18Changed)
    Q_PROPERTY(bool telemetry19 READ telemetry19 WRITE settelemetry19 NOTIFY telemetry19Changed)
    Q_PROPERTY(bool telemetry20 READ telemetry20 WRITE settelemetry20 NOTIFY telemetry20Changed)
    Q_PROPERTY(bool telemetry21 READ telemetry21 WRITE settelemetry21 NOTIFY telemetry21Changed)
    Q_PROPERTY(bool telemetry22 READ telemetry22 WRITE settelemetry22 NOTIFY telemetry22Changed)
    Q_PROPERTY(bool telemetry23 READ telemetry23 WRITE settelemetry23 NOTIFY telemetry23Changed)
    Q_PROPERTY(bool telemetry24 READ telemetry24 WRITE settelemetry24 NOTIFY telemetry24Changed)
    Q_PROPERTY(bool telemetry25 READ telemetry25 WRITE settelemetry25 NOTIFY telemetry25Changed)
    Q_PROPERTY(bool telemetry26 READ telemetry26 WRITE settelemetry26 NOTIFY telemetry26Changed)
    Q_PROPERTY(bool telemetry27 READ telemetry27 WRITE settelemetry27 NOTIFY telemetry27Changed)
    Q_PROPERTY(bool telemetry28 READ telemetry28 WRITE settelemetry28 NOTIFY telemetry28Changed)
    Q_PROPERTY(bool telemetry29 READ telemetry29 WRITE settelemetry29 NOTIFY telemetry29Changed)
    Q_PROPERTY(bool telemetry30 READ telemetry30 WRITE settelemetry30 NOTIFY telemetry30Changed)
    Q_PROPERTY(bool telemetry31 READ telemetry31 WRITE settelemetry31 NOTIFY telemetry31Changed)

    Q_PROPERTY(int telemetryMsgCounter READ telemetryMsgCounter WRITE settelemetryMsgCounter NOTIFY telemetryMsgCounterChanged)

    /* MOTOR */


    Q_PROPERTY(qint32 MotorARealPosition READ MotorARealPosition WRITE setMotorARealPosition NOTIFY MotorARealPositionChanged)
    Q_PROPERTY(qint32 MotorADemandPosition READ MotorADemandPosition WRITE setMotorADemandPosition NOTIFY MotorADemandPositionChanged)
    Q_PROPERTY(qint32 MotorATorque READ MotorATorque WRITE setMotorATorque NOTIFY MotorATorqueChanged)
    Q_PROPERTY(qint16 MotorATemp READ MotorATemp WRITE setMotorATemp NOTIFY MotorATempChanged)

    Q_PROPERTY(qint32 MotorBRealPosition READ MotorBRealPosition WRITE setMotorBRealPosition NOTIFY MotorBRealPositionChanged)
    Q_PROPERTY(qint32 MotorBDemandPosition READ MotorBDemandPosition WRITE setMotorBDemandPosition NOTIFY MotorBDemandPositionChanged)
    Q_PROPERTY(qint32 MotorBTorque READ MotorBTorque WRITE setMotorBTorque NOTIFY MotorBTorqueChanged)
    Q_PROPERTY(qint16 MotorBTemp READ MotorBTemp WRITE setMotorBTemp NOTIFY MotorBTempChanged)

    Q_PROPERTY(quint16 BMSVoltage READ BMSVoltage WRITE setBMSVoltage NOTIFY BMSVoltageChanged)
    Q_PROPERTY(qint16 BMSAbsorption READ BMSAbsorption WRITE setBMSAbsorption NOTIFY BMSAbsorptionChanged)
    Q_PROPERTY(qint16 BMSTemp READ BMSTemp WRITE setBMSTemp NOTIFY BMSTempChanged)

    Q_PROPERTY(quint32 MotorAFaultsMask READ MotorAFaultsMask WRITE setMotorAFaultsMask NOTIFY MotorAFaultsMaskChanged)
    Q_PROPERTY(quint32 MotorBFaultsMask READ MotorBFaultsMask WRITE setMotorBFaultsMask NOTIFY MotorBFaultsMaskChanged)
    Q_PROPERTY(quint32 BMSFaultsMask READ BMSFaultsMask WRITE setBMSFaultsMask NOTIFY BMSFaultsMaskChanged)

    Q_PROPERTY(quint8 ChargeValue READ ChargeValue WRITE setChargeValue NOTIFY ChargeValueChanged)

    Q_PROPERTY(bool motor0 READ motor0 WRITE setmotor0 NOTIFY motor0Changed)
    Q_PROPERTY(bool motor1 READ motor1 WRITE setmotor1 NOTIFY motor1Changed)
    Q_PROPERTY(bool motor2 READ motor2 WRITE setmotor2 NOTIFY motor2Changed)
    Q_PROPERTY(bool motor3 READ motor3 WRITE setmotor3 NOTIFY motor3Changed)
    Q_PROPERTY(bool motor4 READ motor4 WRITE setmotor4 NOTIFY motor4Changed)
    Q_PROPERTY(bool motor5 READ motor5 WRITE setmotor5 NOTIFY motor5Changed)
    Q_PROPERTY(bool motor6 READ motor6 WRITE setmotor6 NOTIFY motor6Changed)
    Q_PROPERTY(bool motor7 READ motor7 WRITE setmotor7 NOTIFY motor7Changed)
    Q_PROPERTY(bool motor8 READ motor8 WRITE setmotor8 NOTIFY motor8Changed)
    Q_PROPERTY(bool motor10 READ motor10 WRITE setmotor10 NOTIFY motor10Changed)
    Q_PROPERTY(bool motor11 READ motor11 WRITE setmotor11 NOTIFY motor11Changed)
    Q_PROPERTY(bool motor12 READ motor12 WRITE setmotor12 NOTIFY motor12Changed)
    Q_PROPERTY(bool motor13 READ motor13 WRITE setmotor13 NOTIFY motor13Changed)
    Q_PROPERTY(bool motor14 READ motor14 WRITE setmotor14 NOTIFY motor14Changed)
    Q_PROPERTY(bool motor15 READ motor15 WRITE setmotor15 NOTIFY motor15Changed)
    Q_PROPERTY(bool motor16 READ motor16 WRITE setmotor16 NOTIFY motor16Changed)
    Q_PROPERTY(bool motor17 READ motor17 WRITE setmotor17 NOTIFY motor17Changed)
    Q_PROPERTY(bool motor18 READ motor18 WRITE setmotor18 NOTIFY motor18Changed)
    Q_PROPERTY(bool motor19 READ motor19 WRITE setmotor19 NOTIFY motor19Changed)
    Q_PROPERTY(bool motor20 READ motor20 WRITE setmotor20 NOTIFY motor20Changed)
    Q_PROPERTY(bool motor21 READ motor21 WRITE setmotor21 NOTIFY motor21Changed)
    Q_PROPERTY(bool motor22 READ motor22 WRITE setmotor22 NOTIFY motor22Changed)
    Q_PROPERTY(bool motor23 READ motor23 WRITE setmotor23 NOTIFY motor23Changed)
    Q_PROPERTY(bool motor24 READ motor24 WRITE setmotor24 NOTIFY motor24Changed)

    Q_PROPERTY(bool motorAMask0 READ motorAMask0 WRITE setmotorAMask0 NOTIFY motorAMask0Changed);
    Q_PROPERTY(bool motorAMask1 READ motorAMask1 WRITE setmotorAMask1 NOTIFY motorAMask1Changed);
    Q_PROPERTY(bool motorAMask2 READ motorAMask2 WRITE setmotorAMask2 NOTIFY motorAMask2Changed);
    Q_PROPERTY(bool motorAMask3 READ motorAMask3 WRITE setmotorAMask3 NOTIFY motorAMask3Changed);
    Q_PROPERTY(bool motorAMask4 READ motorAMask4 WRITE setmotorAMask4 NOTIFY motorAMask4Changed);
    Q_PROPERTY(bool motorAMask5 READ motorAMask5 WRITE setmotorAMask5 NOTIFY motorAMask5Changed);
    Q_PROPERTY(bool motorAMask6 READ motorAMask6 WRITE setmotorAMask6 NOTIFY motorAMask6Changed);
    Q_PROPERTY(bool motorAMask7 READ motorAMask7 WRITE setmotorAMask7 NOTIFY motorAMask7Changed);
    Q_PROPERTY(bool motorAMask8 READ motorAMask8 WRITE setmotorAMask8 NOTIFY motorAMask8Changed);
    Q_PROPERTY(bool motorAMask9 READ motorAMask9 WRITE setmotorAMask9 NOTIFY motorAMask9Changed);
    Q_PROPERTY(bool motorAMask10 READ motorAMask10 WRITE setmotorAMask10 NOTIFY motorAMask10Changed);
    Q_PROPERTY(bool motorAMask11 READ motorAMask11 WRITE setmotorAMask11 NOTIFY motorAMask11Changed);
    Q_PROPERTY(bool motorAMask12 READ motorAMask12 WRITE setmotorAMask12 NOTIFY motorAMask12Changed);
    Q_PROPERTY(bool motorAMask13 READ motorAMask13 WRITE setmotorAMask13 NOTIFY motorAMask13Changed);
    Q_PROPERTY(bool motorAMask14 READ motorAMask14 WRITE setmotorAMask14 NOTIFY motorAMask14Changed);
    Q_PROPERTY(bool motorAMask15 READ motorAMask15 WRITE setmotorAMask15 NOTIFY motorAMask15Changed);
    Q_PROPERTY(bool motorAMask16 READ motorAMask16 WRITE setmotorAMask16 NOTIFY motorAMask16Changed);
    Q_PROPERTY(bool motorAMask17 READ motorAMask17 WRITE setmotorAMask17 NOTIFY motorAMask17Changed);
    Q_PROPERTY(bool motorAMask18 READ motorAMask18 WRITE setmotorAMask18 NOTIFY motorAMask18Changed);
    Q_PROPERTY(bool motorAMask19 READ motorAMask19 WRITE setmotorAMask19 NOTIFY motorAMask19Changed);
    Q_PROPERTY(bool motorAMask20 READ motorAMask20 WRITE setmotorAMask20 NOTIFY motorAMask20Changed);
    Q_PROPERTY(bool motorAMask21 READ motorAMask21 WRITE setmotorAMask21 NOTIFY motorAMask21Changed);
    Q_PROPERTY(bool motorAMask22 READ motorAMask22 WRITE setmotorAMask22 NOTIFY motorAMask22Changed);
    Q_PROPERTY(bool motorAMask23 READ motorAMask23 WRITE setmotorAMask23 NOTIFY motorAMask23Changed);
    Q_PROPERTY(bool motorAMask24 READ motorAMask24 WRITE setmotorAMask24 NOTIFY motorAMask24Changed);
    Q_PROPERTY(bool motorAMask25 READ motorAMask25 WRITE setmotorAMask25 NOTIFY motorAMask25Changed);
    Q_PROPERTY(bool motorAMask26 READ motorAMask26 WRITE setmotorAMask26 NOTIFY motorAMask26Changed);
    Q_PROPERTY(bool motorAMask27 READ motorAMask27 WRITE setmotorAMask27 NOTIFY motorAMask27Changed);
    Q_PROPERTY(bool motorAMask28 READ motorAMask28 WRITE setmotorAMask28 NOTIFY motorAMask28Changed);
    Q_PROPERTY(bool motorAMask29 READ motorAMask29 WRITE setmotorAMask29 NOTIFY motorAMask29Changed);
    Q_PROPERTY(bool motorAMask30 READ motorAMask30 WRITE setmotorAMask30 NOTIFY motorAMask30Changed);
    Q_PROPERTY(bool motorAMask31 READ motorAMask31 WRITE setmotorAMask31 NOTIFY motorAMask31Changed);

    Q_PROPERTY(bool motorBMask0 READ motorBMask0 WRITE setmotorBMask0 NOTIFY motorBMask0Changed);
    Q_PROPERTY(bool motorBMask1 READ motorBMask1 WRITE setmotorBMask1 NOTIFY motorBMask1Changed);
    Q_PROPERTY(bool motorBMask2 READ motorBMask2 WRITE setmotorBMask2 NOTIFY motorBMask2Changed);
    Q_PROPERTY(bool motorBMask3 READ motorBMask3 WRITE setmotorBMask3 NOTIFY motorBMask3Changed);
    Q_PROPERTY(bool motorBMask4 READ motorBMask4 WRITE setmotorBMask4 NOTIFY motorBMask4Changed);
    Q_PROPERTY(bool motorBMask5 READ motorBMask5 WRITE setmotorBMask5 NOTIFY motorBMask5Changed);
    Q_PROPERTY(bool motorBMask6 READ motorBMask6 WRITE setmotorBMask6 NOTIFY motorBMask6Changed);
    Q_PROPERTY(bool motorBMask7 READ motorBMask7 WRITE setmotorBMask7 NOTIFY motorBMask7Changed);
    Q_PROPERTY(bool motorBMask8 READ motorBMask8 WRITE setmotorBMask8 NOTIFY motorBMask8Changed);
    Q_PROPERTY(bool motorBMask9 READ motorBMask9 WRITE setmotorBMask9 NOTIFY motorBMask9Changed);
    Q_PROPERTY(bool motorBMask10 READ motorBMask10 WRITE setmotorBMask10 NOTIFY motorBMask10Changed);
    Q_PROPERTY(bool motorBMask11 READ motorBMask11 WRITE setmotorBMask11 NOTIFY motorBMask11Changed);
    Q_PROPERTY(bool motorBMask12 READ motorBMask12 WRITE setmotorBMask12 NOTIFY motorBMask12Changed);
    Q_PROPERTY(bool motorBMask13 READ motorBMask13 WRITE setmotorBMask13 NOTIFY motorBMask13Changed);
    Q_PROPERTY(bool motorBMask14 READ motorBMask14 WRITE setmotorBMask14 NOTIFY motorBMask14Changed);
    Q_PROPERTY(bool motorBMask15 READ motorBMask15 WRITE setmotorBMask15 NOTIFY motorBMask15Changed);
    Q_PROPERTY(bool motorBMask16 READ motorBMask16 WRITE setmotorBMask16 NOTIFY motorBMask16Changed);
    Q_PROPERTY(bool motorBMask17 READ motorBMask17 WRITE setmotorBMask17 NOTIFY motorBMask17Changed);
    Q_PROPERTY(bool motorBMask18 READ motorBMask18 WRITE setmotorBMask18 NOTIFY motorBMask18Changed);
    Q_PROPERTY(bool motorBMask19 READ motorBMask19 WRITE setmotorBMask19 NOTIFY motorBMask19Changed);
    Q_PROPERTY(bool motorBMask20 READ motorBMask20 WRITE setmotorBMask20 NOTIFY motorBMask20Changed);
    Q_PROPERTY(bool motorBMask21 READ motorBMask21 WRITE setmotorBMask21 NOTIFY motorBMask21Changed);
    Q_PROPERTY(bool motorBMask22 READ motorBMask22 WRITE setmotorBMask22 NOTIFY motorBMask22Changed);
    Q_PROPERTY(bool motorBMask23 READ motorBMask23 WRITE setmotorBMask23 NOTIFY motorBMask23Changed);
    Q_PROPERTY(bool motorBMask24 READ motorBMask24 WRITE setmotorBMask24 NOTIFY motorBMask24Changed);
    Q_PROPERTY(bool motorBMask25 READ motorBMask25 WRITE setmotorBMask25 NOTIFY motorBMask25Changed);
    Q_PROPERTY(bool motorBMask26 READ motorBMask26 WRITE setmotorBMask26 NOTIFY motorBMask26Changed);
    Q_PROPERTY(bool motorBMask27 READ motorBMask27 WRITE setmotorBMask27 NOTIFY motorBMask27Changed);
    Q_PROPERTY(bool motorBMask28 READ motorBMask28 WRITE setmotorBMask28 NOTIFY motorBMask28Changed);
    Q_PROPERTY(bool motorBMask29 READ motorBMask29 WRITE setmotorBMask29 NOTIFY motorBMask29Changed);
    Q_PROPERTY(bool motorBMask30 READ motorBMask30 WRITE setmotorBMask30 NOTIFY motorBMask30Changed);
    Q_PROPERTY(bool motorBMask31 READ motorBMask31 WRITE setmotorBMask31 NOTIFY motorBMask31Changed)

    Q_PROPERTY(bool BMS0 READ BMS0 WRITE setBMS0 NOTIFY BMS0Changed)
    Q_PROPERTY(bool BMS1 READ BMS1 WRITE setBMS1 NOTIFY BMS1Changed)
    Q_PROPERTY(bool BMS2 READ BMS2 WRITE setBMS2 NOTIFY BMS2Changed)
    Q_PROPERTY(bool BMS3 READ BMS3 WRITE setBMS3 NOTIFY BMS3Changed)
    Q_PROPERTY(bool BMS4 READ BMS4 WRITE setBMS4 NOTIFY BMS4Changed)
    Q_PROPERTY(bool BMS5 READ BMS5 WRITE setBMS5 NOTIFY BMS5Changed)
    Q_PROPERTY(bool BMS6 READ BMS6 WRITE setBMS6 NOTIFY BMS6Changed)
    Q_PROPERTY(bool BMS7 READ BMS7 WRITE setBMS7 NOTIFY BMS7Changed)
    Q_PROPERTY(bool BMS8 READ BMS8 WRITE setBMS8 NOTIFY BMS8Changed)
    Q_PROPERTY(bool BMS9 READ BMS9 WRITE setBMS9 NOTIFY BMS9Changed)
    Q_PROPERTY(bool BMS10 READ BMS10 WRITE setBMS10 NOTIFY BMS10Changed)
    Q_PROPERTY(bool BMS11 READ BMS11 WRITE setBMS11 NOTIFY BMS11Changed)
    Q_PROPERTY(bool BMS12 READ BMS12 WRITE setBMS12 NOTIFY BMS12Changed)
    Q_PROPERTY(bool BMS13 READ BMS13 WRITE setBMS13 NOTIFY BMS13Changed)
    Q_PROPERTY(bool BMS14 READ BMS14 WRITE setBMS14 NOTIFY BMS14Changed)
    Q_PROPERTY(bool BMS15 READ BMS15 WRITE setBMS15 NOTIFY BMS15Changed)
    Q_PROPERTY(bool BMS16 READ BMS16 WRITE setBMS16 NOTIFY BMS16Changed)
    Q_PROPERTY(bool BMS17 READ BMS17 WRITE setBMS17 NOTIFY BMS17Changed)
    Q_PROPERTY(bool BMS18 READ BMS18 WRITE setBMS18 NOTIFY BMS18Changed)
    Q_PROPERTY(bool BMS19 READ BMS19 WRITE setBMS19 NOTIFY BMS19Changed)
    Q_PROPERTY(bool BMS20 READ BMS20 WRITE setBMS20 NOTIFY BMS20Changed)
    Q_PROPERTY(bool BMS21 READ BMS21 WRITE setBMS21 NOTIFY BMS21Changed)
    Q_PROPERTY(bool BMS22 READ BMS22 WRITE setBMS22 NOTIFY BMS22Changed)
    Q_PROPERTY(bool BMS23 READ BMS23 WRITE setBMS23 NOTIFY BMS23Changed)
    Q_PROPERTY(bool BMS24 READ BMS24 WRITE setBMS24 NOTIFY BMS24Changed)
    Q_PROPERTY(bool BMS25 READ BMS25 WRITE setBMS25 NOTIFY BMS25Changed)
    Q_PROPERTY(bool BMS26 READ BMS26 WRITE setBMS26 NOTIFY BMS26Changed)
    Q_PROPERTY(bool BMS27 READ BMS27 WRITE setBMS27 NOTIFY BMS27Changed)
    Q_PROPERTY(bool BMS28 READ BMS28 WRITE setBMS28 NOTIFY BMS28Changed)
    Q_PROPERTY(bool BMS29 READ BMS29 WRITE setBMS29 NOTIFY BMS29Changed)
    Q_PROPERTY(bool BMS30 READ BMS30 WRITE setBMS30 NOTIFY BMS30Changed)
    Q_PROPERTY(bool BMS31 READ BMS31 WRITE setBMS31 NOTIFY BMS31Changed)

    Q_PROPERTY(int motorMsgCounter READ motorMsgCounter WRITE setmotorMsgCounter NOTIFY motorMsgCounterChanged)

    /* SYSTEM */

    Q_PROPERTY(quint8 FlightMode READ FlightMode WRITE setFlightMode NOTIFY FlightModeChanged)
    Q_PROPERTY(quint8 FlightPhase READ FlightPhase WRITE setFlightPhase NOTIFY FlightPhaseChanged)
    Q_PROPERTY(quint32 FlightPhaseExecutionTime READ FlightPhaseExecutionTime WRITE setFlightPhaseExecutionTime NOTIFY FlightPhaseExecutionTimeChanged)
    Q_PROPERTY(quint32 CoreModuleStatusMask READ CoreModuleStatusMask WRITE setCoreModuleStatusMask NOTIFY CoreModuleStatusMaskChanged)
    Q_PROPERTY(quint64 TelemetryModuleStatusMask READ TelemetryModuleStatusMask WRITE setTelemetryModuleStatusMask NOTIFY TelemetryModuleStatusMaskChanged)
    Q_PROPERTY(quint32 GuidanceModuleStatusMask READ GuidanceModuleStatusMask WRITE setGuidanceModuleStatusMask NOTIFY GuidanceModuleStatusMaskChanged)
    Q_PROPERTY(quint32 StorageModuleStatusMask READ StorageModuleStatusMask WRITE setStorageModuleStatusMask NOTIFY StorageModuleStatusMaskChanged)
    Q_PROPERTY(quint32 RadioLinkModuleStatusMask READ RadioLinkModuleStatusMask WRITE setRadioLinkModuleStatusMask NOTIFY RadioLinkModuleStatusMaskChanged)
    Q_PROPERTY(quint32 MotorControlStatusMask READ MotorControlStatusMask WRITE setMotorControlStatusMask NOTIFY MotorControlStatusMaskChanged)

    Q_PROPERTY(quint8 communicationErrorCounter READ communicationErrorCounter WRITE setcommunicationErrorCounter NOTIFY communicationErrorCounterChanged);
    Q_PROPERTY(bool systemCoreMask0 READ systemCoreMask0 WRITE setsystemCoreMask0 NOTIFY systemCoreMask0Changed);
    Q_PROPERTY(bool systemCoreMask1 READ systemCoreMask1 WRITE setsystemCoreMask1 NOTIFY systemCoreMask1Changed);
    Q_PROPERTY(bool systemCoreMask2 READ systemCoreMask2 WRITE setsystemCoreMask2 NOTIFY systemCoreMask2Changed);
    Q_PROPERTY(bool systemCoreMask3 READ systemCoreMask3 WRITE setsystemCoreMask3 NOTIFY systemCoreMask3Changed);
    Q_PROPERTY(bool systemCoreMask4 READ systemCoreMask4 WRITE setsystemCoreMask4 NOTIFY systemCoreMask4Changed);
    Q_PROPERTY(bool systemCoreMask5 READ systemCoreMask5 WRITE setsystemCoreMask5 NOTIFY systemCoreMask5Changed);
    Q_PROPERTY(bool systemCoreMask6 READ systemCoreMask6 WRITE setsystemCoreMask6 NOTIFY systemCoreMask6Changed);
    Q_PROPERTY(bool systemCoreMask7 READ systemCoreMask7 WRITE setsystemCoreMask7 NOTIFY systemCoreMask7Changed);
    Q_PROPERTY(bool systemCoreMask8 READ systemCoreMask8 WRITE setsystemCoreMask8 NOTIFY systemCoreMask8Changed);
    Q_PROPERTY(bool systemCoreMask9 READ systemCoreMask9 WRITE setsystemCoreMask9 NOTIFY systemCoreMask9Changed);
    Q_PROPERTY(bool systemCoreMask10 READ systemCoreMask10 WRITE setsystemCoreMask10 NOTIFY systemCoreMask10Changed);
    Q_PROPERTY(bool systemCoreMask11 READ systemCoreMask11 WRITE setsystemCoreMask11 NOTIFY systemCoreMask11Changed);
    Q_PROPERTY(bool systemCoreMask12 READ systemCoreMask12 WRITE setsystemCoreMask12 NOTIFY systemCoreMask12Changed);
    Q_PROPERTY(bool systemCoreMask13 READ systemCoreMask13 WRITE setsystemCoreMask13 NOTIFY systemCoreMask13Changed);
    Q_PROPERTY(bool systemCoreMask14 READ systemCoreMask14 WRITE setsystemCoreMask14 NOTIFY systemCoreMask14Changed);
    Q_PROPERTY(bool systemCoreMask15 READ systemCoreMask15 WRITE setsystemCoreMask15 NOTIFY systemCoreMask15Changed);
    Q_PROPERTY(bool systemCoreMask16 READ systemCoreMask16 WRITE setsystemCoreMask16 NOTIFY systemCoreMask16Changed);
    Q_PROPERTY(bool systemCoreMask17 READ systemCoreMask17 WRITE setsystemCoreMask17 NOTIFY systemCoreMask17Changed);
    Q_PROPERTY(bool systemCoreMask18 READ systemCoreMask18 WRITE setsystemCoreMask18 NOTIFY systemCoreMask18Changed);
    Q_PROPERTY(bool systemCoreMask19 READ systemCoreMask19 WRITE setsystemCoreMask19 NOTIFY systemCoreMask19Changed);
    Q_PROPERTY(bool systemCoreMask20 READ systemCoreMask20 WRITE setsystemCoreMask20 NOTIFY systemCoreMask20Changed);
    Q_PROPERTY(bool systemCoreMask21 READ systemCoreMask21 WRITE setsystemCoreMask21 NOTIFY systemCoreMask21Changed);
    Q_PROPERTY(bool systemCoreMask22 READ systemCoreMask22 WRITE setsystemCoreMask22 NOTIFY systemCoreMask22Changed);
    Q_PROPERTY(bool systemCoreMask23 READ systemCoreMask23 WRITE setsystemCoreMask23 NOTIFY systemCoreMask23Changed);
    Q_PROPERTY(bool systemCoreMask24 READ systemCoreMask24 WRITE setsystemCoreMask24 NOTIFY systemCoreMask24Changed);
    Q_PROPERTY(bool systemCoreMask25 READ systemCoreMask25 WRITE setsystemCoreMask25 NOTIFY systemCoreMask25Changed);
    Q_PROPERTY(bool systemCoreMask26 READ systemCoreMask26 WRITE setsystemCoreMask26 NOTIFY systemCoreMask26Changed);
    Q_PROPERTY(bool systemCoreMask27 READ systemCoreMask27 WRITE setsystemCoreMask27 NOTIFY systemCoreMask27Changed);
    Q_PROPERTY(bool systemCoreMask28 READ systemCoreMask28 WRITE setsystemCoreMask28 NOTIFY systemCoreMask28Changed);
    Q_PROPERTY(bool systemCoreMask29 READ systemCoreMask29 WRITE setsystemCoreMask29 NOTIFY systemCoreMask29Changed);
    Q_PROPERTY(bool systemCoreMask30 READ systemCoreMask30 WRITE setsystemCoreMask30 NOTIFY systemCoreMask30Changed);
    Q_PROPERTY(bool systemCoreMask31 READ systemCoreMask31 WRITE setsystemCoreMask31 NOTIFY systemCoreMask31Changed);

    Q_PROPERTY(bool systemStorageMask0 READ systemStorageMask0 WRITE setsystemStorageMask0 NOTIFY systemStorageMask0Changed);
    Q_PROPERTY(bool systemStorageMask1 READ systemStorageMask1 WRITE setsystemStorageMask1 NOTIFY systemStorageMask1Changed);
    Q_PROPERTY(bool systemStorageMask2 READ systemStorageMask2 WRITE setsystemStorageMask2 NOTIFY systemStorageMask2Changed);
    Q_PROPERTY(bool systemStorageMask3 READ systemStorageMask3 WRITE setsystemStorageMask3 NOTIFY systemStorageMask3Changed);
    Q_PROPERTY(bool systemStorageMask4 READ systemStorageMask4 WRITE setsystemStorageMask4 NOTIFY systemStorageMask4Changed);
    Q_PROPERTY(bool systemStorageMask5 READ systemStorageMask5 WRITE setsystemStorageMask5 NOTIFY systemStorageMask5Changed);
    Q_PROPERTY(bool systemStorageMask6 READ systemStorageMask6 WRITE setsystemStorageMask6 NOTIFY systemStorageMask6Changed);
    Q_PROPERTY(bool systemStorageMask7 READ systemStorageMask7 WRITE setsystemStorageMask7 NOTIFY systemStorageMask7Changed);
    Q_PROPERTY(bool systemStorageMask8 READ systemStorageMask8 WRITE setsystemStorageMask8 NOTIFY systemStorageMask8Changed);
    Q_PROPERTY(bool systemStorageMask9 READ systemStorageMask9 WRITE setsystemStorageMask9 NOTIFY systemStorageMask9Changed);
    Q_PROPERTY(bool systemStorageMask10 READ systemStorageMask10 WRITE setsystemStorageMask10 NOTIFY systemStorageMask10Changed);
    Q_PROPERTY(bool systemStorageMask11 READ systemStorageMask11 WRITE setsystemStorageMask11 NOTIFY systemStorageMask11Changed);
    Q_PROPERTY(bool systemStorageMask12 READ systemStorageMask12 WRITE setsystemStorageMask12 NOTIFY systemStorageMask12Changed);
    Q_PROPERTY(bool systemStorageMask13 READ systemStorageMask13 WRITE setsystemStorageMask13 NOTIFY systemStorageMask13Changed);
    Q_PROPERTY(bool systemStorageMask14 READ systemStorageMask14 WRITE setsystemStorageMask14 NOTIFY systemStorageMask14Changed);
    Q_PROPERTY(bool systemStorageMask15 READ systemStorageMask15 WRITE setsystemStorageMask15 NOTIFY systemStorageMask15Changed);
    Q_PROPERTY(bool systemStorageMask16 READ systemStorageMask16 WRITE setsystemStorageMask16 NOTIFY systemStorageMask16Changed);
    Q_PROPERTY(bool systemStorageMask17 READ systemStorageMask17 WRITE setsystemStorageMask17 NOTIFY systemStorageMask17Changed);
    Q_PROPERTY(bool systemStorageMask18 READ systemStorageMask18 WRITE setsystemStorageMask18 NOTIFY systemStorageMask18Changed);
    Q_PROPERTY(bool systemStorageMask19 READ systemStorageMask19 WRITE setsystemStorageMask19 NOTIFY systemStorageMask19Changed);
    Q_PROPERTY(bool systemStorageMask20 READ systemStorageMask20 WRITE setsystemStorageMask20 NOTIFY systemStorageMask20Changed);
    Q_PROPERTY(bool systemStorageMask21 READ systemStorageMask21 WRITE setsystemStorageMask21 NOTIFY systemStorageMask21Changed);
    Q_PROPERTY(bool systemStorageMask22 READ systemStorageMask22 WRITE setsystemStorageMask22 NOTIFY systemStorageMask22Changed);
    Q_PROPERTY(bool systemStorageMask23 READ systemStorageMask23 WRITE setsystemStorageMask23 NOTIFY systemStorageMask23Changed);
    Q_PROPERTY(bool systemStorageMask24 READ systemStorageMask24 WRITE setsystemStorageMask24 NOTIFY systemStorageMask24Changed);
    Q_PROPERTY(bool systemStorageMask25 READ systemStorageMask25 WRITE setsystemStorageMask25 NOTIFY systemStorageMask25Changed);
    Q_PROPERTY(bool systemStorageMask26 READ systemStorageMask26 WRITE setsystemStorageMask26 NOTIFY systemStorageMask26Changed);
    Q_PROPERTY(bool systemStorageMask27 READ systemStorageMask27 WRITE setsystemStorageMask27 NOTIFY systemStorageMask27Changed);
    Q_PROPERTY(bool systemStorageMask28 READ systemStorageMask28 WRITE setsystemStorageMask28 NOTIFY systemStorageMask28Changed);
    Q_PROPERTY(bool systemStorageMask29 READ systemStorageMask29 WRITE setsystemStorageMask29 NOTIFY systemStorageMask29Changed);
    Q_PROPERTY(bool systemStorageMask30 READ systemStorageMask30 WRITE setsystemStorageMask30 NOTIFY systemStorageMask30Changed);
    Q_PROPERTY(bool systemStorageMask31 READ systemStorageMask31 WRITE setsystemStorageMask31 NOTIFY systemStorageMask31Changed);

    Q_PROPERTY(bool systemGuidanceMask0 READ systemGuidanceMask0 WRITE setsystemGuidanceMask0 NOTIFY systemGuidanceMask0Changed);
    Q_PROPERTY(bool systemGuidanceMask1 READ systemGuidanceMask1 WRITE setsystemGuidanceMask1 NOTIFY systemGuidanceMask1Changed);
    Q_PROPERTY(bool systemGuidanceMask2 READ systemGuidanceMask2 WRITE setsystemGuidanceMask2 NOTIFY systemGuidanceMask2Changed);
    Q_PROPERTY(bool systemGuidanceMask3 READ systemGuidanceMask3 WRITE setsystemGuidanceMask3 NOTIFY systemGuidanceMask3Changed);
    Q_PROPERTY(bool systemGuidanceMask4 READ systemGuidanceMask4 WRITE setsystemGuidanceMask4 NOTIFY systemGuidanceMask4Changed);
    Q_PROPERTY(bool systemGuidanceMask5 READ systemGuidanceMask5 WRITE setsystemGuidanceMask5 NOTIFY systemGuidanceMask5Changed);
    Q_PROPERTY(bool systemGuidanceMask6 READ systemGuidanceMask6 WRITE setsystemGuidanceMask6 NOTIFY systemGuidanceMask6Changed);
    Q_PROPERTY(bool systemGuidanceMask7 READ systemGuidanceMask7 WRITE setsystemGuidanceMask7 NOTIFY systemGuidanceMask7Changed);
    Q_PROPERTY(bool systemGuidanceMask8 READ systemGuidanceMask8 WRITE setsystemGuidanceMask8 NOTIFY systemGuidanceMask8Changed);
    Q_PROPERTY(bool systemGuidanceMask9 READ systemGuidanceMask9 WRITE setsystemGuidanceMask9 NOTIFY systemGuidanceMask9Changed);
    Q_PROPERTY(bool systemGuidanceMask10 READ systemGuidanceMask10 WRITE setsystemGuidanceMask10 NOTIFY systemGuidanceMask10Changed);
    Q_PROPERTY(bool systemGuidanceMask11 READ systemGuidanceMask11 WRITE setsystemGuidanceMask11 NOTIFY systemGuidanceMask11Changed);
    Q_PROPERTY(bool systemGuidanceMask12 READ systemGuidanceMask12 WRITE setsystemGuidanceMask12 NOTIFY systemGuidanceMask12Changed);
    Q_PROPERTY(bool systemGuidanceMask13 READ systemGuidanceMask13 WRITE setsystemGuidanceMask13 NOTIFY systemGuidanceMask13Changed);
    Q_PROPERTY(bool systemGuidanceMask14 READ systemGuidanceMask14 WRITE setsystemGuidanceMask14 NOTIFY systemGuidanceMask14Changed);
    Q_PROPERTY(bool systemGuidanceMask15 READ systemGuidanceMask15 WRITE setsystemGuidanceMask15 NOTIFY systemGuidanceMask15Changed);
    Q_PROPERTY(bool systemGuidanceMask16 READ systemGuidanceMask16 WRITE setsystemGuidanceMask16 NOTIFY systemGuidanceMask16Changed);
    Q_PROPERTY(bool systemGuidanceMask17 READ systemGuidanceMask17 WRITE setsystemGuidanceMask17 NOTIFY systemGuidanceMask17Changed);
    Q_PROPERTY(bool systemGuidanceMask18 READ systemGuidanceMask18 WRITE setsystemGuidanceMask18 NOTIFY systemGuidanceMask18Changed);
    Q_PROPERTY(bool systemGuidanceMask19 READ systemGuidanceMask19 WRITE setsystemGuidanceMask19 NOTIFY systemGuidanceMask19Changed);
    Q_PROPERTY(bool systemGuidanceMask20 READ systemGuidanceMask20 WRITE setsystemGuidanceMask20 NOTIFY systemGuidanceMask20Changed);
    Q_PROPERTY(bool systemGuidanceMask21 READ systemGuidanceMask21 WRITE setsystemGuidanceMask21 NOTIFY systemGuidanceMask21Changed);
    Q_PROPERTY(bool systemGuidanceMask22 READ systemGuidanceMask22 WRITE setsystemGuidanceMask22 NOTIFY systemGuidanceMask22Changed);
    Q_PROPERTY(bool systemGuidanceMask23 READ systemGuidanceMask23 WRITE setsystemGuidanceMask23 NOTIFY systemGuidanceMask23Changed);
    Q_PROPERTY(bool systemGuidanceMask24 READ systemGuidanceMask24 WRITE setsystemGuidanceMask24 NOTIFY systemGuidanceMask24Changed);
    Q_PROPERTY(bool systemGuidanceMask25 READ systemGuidanceMask25 WRITE setsystemGuidanceMask25 NOTIFY systemGuidanceMask25Changed);
    Q_PROPERTY(bool systemGuidanceMask26 READ systemGuidanceMask26 WRITE setsystemGuidanceMask26 NOTIFY systemGuidanceMask26Changed);
    Q_PROPERTY(bool systemGuidanceMask27 READ systemGuidanceMask27 WRITE setsystemGuidanceMask27 NOTIFY systemGuidanceMask27Changed);
    Q_PROPERTY(bool systemGuidanceMask28 READ systemGuidanceMask28 WRITE setsystemGuidanceMask28 NOTIFY systemGuidanceMask28Changed);
    Q_PROPERTY(bool systemGuidanceMask29 READ systemGuidanceMask29 WRITE setsystemGuidanceMask29 NOTIFY systemGuidanceMask29Changed);
    Q_PROPERTY(bool systemGuidanceMask30 READ systemGuidanceMask30 WRITE setsystemGuidanceMask30 NOTIFY systemGuidanceMask30Changed);
    Q_PROPERTY(bool systemGuidanceMask31 READ systemGuidanceMask31 WRITE setsystemGuidanceMask31 NOTIFY systemGuidanceMask31Changed);

    Q_PROPERTY(bool systemMotorControlMask0 READ systemMotorControlMask0 WRITE setsystemMotorControlMask0 NOTIFY systemMotorControlMask0Changed);
    Q_PROPERTY(bool systemMotorControlMask1 READ systemMotorControlMask1 WRITE setsystemMotorControlMask1 NOTIFY systemMotorControlMask1Changed);
    Q_PROPERTY(bool systemMotorControlMask2 READ systemMotorControlMask2 WRITE setsystemMotorControlMask2 NOTIFY systemMotorControlMask2Changed);
    Q_PROPERTY(bool systemMotorControlMask3 READ systemMotorControlMask3 WRITE setsystemMotorControlMask3 NOTIFY systemMotorControlMask3Changed);
    Q_PROPERTY(bool systemMotorControlMask4 READ systemMotorControlMask4 WRITE setsystemMotorControlMask4 NOTIFY systemMotorControlMask4Changed);
    Q_PROPERTY(bool systemMotorControlMask5 READ systemMotorControlMask5 WRITE setsystemMotorControlMask5 NOTIFY systemMotorControlMask5Changed);
    Q_PROPERTY(bool systemMotorControlMask6 READ systemMotorControlMask6 WRITE setsystemMotorControlMask6 NOTIFY systemMotorControlMask6Changed);
    Q_PROPERTY(bool systemMotorControlMask7 READ systemMotorControlMask7 WRITE setsystemMotorControlMask7 NOTIFY systemMotorControlMask7Changed);
    Q_PROPERTY(bool systemMotorControlMask8 READ systemMotorControlMask8 WRITE setsystemMotorControlMask8 NOTIFY systemMotorControlMask8Changed);
    Q_PROPERTY(bool systemMotorControlMask9 READ systemMotorControlMask9 WRITE setsystemMotorControlMask9 NOTIFY systemMotorControlMask9Changed);
    Q_PROPERTY(bool systemMotorControlMask10 READ systemMotorControlMask10 WRITE setsystemMotorControlMask10 NOTIFY systemMotorControlMask10Changed);
    Q_PROPERTY(bool systemMotorControlMask11 READ systemMotorControlMask11 WRITE setsystemMotorControlMask11 NOTIFY systemMotorControlMask11Changed);
    Q_PROPERTY(bool systemMotorControlMask12 READ systemMotorControlMask12 WRITE setsystemMotorControlMask12 NOTIFY systemMotorControlMask12Changed);
    Q_PROPERTY(bool systemMotorControlMask13 READ systemMotorControlMask13 WRITE setsystemMotorControlMask13 NOTIFY systemMotorControlMask13Changed);
    Q_PROPERTY(bool systemMotorControlMask14 READ systemMotorControlMask14 WRITE setsystemMotorControlMask14 NOTIFY systemMotorControlMask14Changed);
    Q_PROPERTY(bool systemMotorControlMask15 READ systemMotorControlMask15 WRITE setsystemMotorControlMask15 NOTIFY systemMotorControlMask15Changed);
    Q_PROPERTY(bool systemMotorControlMask16 READ systemMotorControlMask16 WRITE setsystemMotorControlMask16 NOTIFY systemMotorControlMask16Changed);
    Q_PROPERTY(bool systemMotorControlMask17 READ systemMotorControlMask17 WRITE setsystemMotorControlMask17 NOTIFY systemMotorControlMask17Changed);
    Q_PROPERTY(bool systemMotorControlMask18 READ systemMotorControlMask18 WRITE setsystemMotorControlMask18 NOTIFY systemMotorControlMask18Changed);
    Q_PROPERTY(bool systemMotorControlMask19 READ systemMotorControlMask19 WRITE setsystemMotorControlMask19 NOTIFY systemMotorControlMask19Changed);
    Q_PROPERTY(bool systemMotorControlMask20 READ systemMotorControlMask20 WRITE setsystemMotorControlMask20 NOTIFY systemMotorControlMask20Changed);
    Q_PROPERTY(bool systemMotorControlMask21 READ systemMotorControlMask21 WRITE setsystemMotorControlMask21 NOTIFY systemMotorControlMask21Changed);
    Q_PROPERTY(bool systemMotorControlMask22 READ systemMotorControlMask22 WRITE setsystemMotorControlMask22 NOTIFY systemMotorControlMask22Changed);
    Q_PROPERTY(bool systemMotorControlMask23 READ systemMotorControlMask23 WRITE setsystemMotorControlMask23 NOTIFY systemMotorControlMask23Changed);
    Q_PROPERTY(bool systemMotorControlMask24 READ systemMotorControlMask24 WRITE setsystemMotorControlMask24 NOTIFY systemMotorControlMask24Changed);
    Q_PROPERTY(bool systemMotorControlMask25 READ systemMotorControlMask25 WRITE setsystemMotorControlMask25 NOTIFY systemMotorControlMask25Changed);
    Q_PROPERTY(bool systemMotorControlMask26 READ systemMotorControlMask26 WRITE setsystemMotorControlMask26 NOTIFY systemMotorControlMask26Changed);
    Q_PROPERTY(bool systemMotorControlMask27 READ systemMotorControlMask27 WRITE setsystemMotorControlMask27 NOTIFY systemMotorControlMask27Changed);
    Q_PROPERTY(bool systemMotorControlMask28 READ systemMotorControlMask28 WRITE setsystemMotorControlMask28 NOTIFY systemMotorControlMask28Changed);
    Q_PROPERTY(bool systemMotorControlMask29 READ systemMotorControlMask29 WRITE setsystemMotorControlMask29 NOTIFY systemMotorControlMask29Changed);
    Q_PROPERTY(bool systemMotorControlMask30 READ systemMotorControlMask30 WRITE setsystemMotorControlMask30 NOTIFY systemMotorControlMask30Changed);
    Q_PROPERTY(bool systemMotorControlMask31 READ systemMotorControlMask31 WRITE setsystemMotorControlMask31 NOTIFY systemMotorControlMask31Changed);


    Q_PROPERTY(bool systemTelemetryMask0 READ systemTelemetryMask0 WRITE setsystemTelemetryMask0 NOTIFY systemTelemetryMask0Changed);
    Q_PROPERTY(bool systemTelemetryMask1 READ systemTelemetryMask1 WRITE setsystemTelemetryMask1 NOTIFY systemTelemetryMask1Changed);
    Q_PROPERTY(bool systemTelemetryMask2 READ systemTelemetryMask2 WRITE setsystemTelemetryMask2 NOTIFY systemTelemetryMask2Changed);
    Q_PROPERTY(bool systemTelemetryMask3 READ systemTelemetryMask3 WRITE setsystemTelemetryMask3 NOTIFY systemTelemetryMask3Changed);
    Q_PROPERTY(bool systemTelemetryMask4 READ systemTelemetryMask4 WRITE setsystemTelemetryMask4 NOTIFY systemTelemetryMask4Changed);
    Q_PROPERTY(bool systemTelemetryMask5 READ systemTelemetryMask5 WRITE setsystemTelemetryMask5 NOTIFY systemTelemetryMask5Changed);
    Q_PROPERTY(bool systemTelemetryMask6 READ systemTelemetryMask6 WRITE setsystemTelemetryMask6 NOTIFY systemTelemetryMask6Changed);
    Q_PROPERTY(bool systemTelemetryMask7 READ systemTelemetryMask7 WRITE setsystemTelemetryMask7 NOTIFY systemTelemetryMask7Changed);
    Q_PROPERTY(bool systemTelemetryMask8 READ systemTelemetryMask8 WRITE setsystemTelemetryMask8 NOTIFY systemTelemetryMask8Changed);
    Q_PROPERTY(bool systemTelemetryMask9 READ systemTelemetryMask9 WRITE setsystemTelemetryMask9 NOTIFY systemTelemetryMask9Changed);
    Q_PROPERTY(bool systemTelemetryMask10 READ systemTelemetryMask10 WRITE setsystemTelemetryMask10 NOTIFY systemTelemetryMask10Changed);
    Q_PROPERTY(bool systemTelemetryMask11 READ systemTelemetryMask11 WRITE setsystemTelemetryMask11 NOTIFY systemTelemetryMask11Changed);
    Q_PROPERTY(bool systemTelemetryMask12 READ systemTelemetryMask12 WRITE setsystemTelemetryMask12 NOTIFY systemTelemetryMask12Changed);
    Q_PROPERTY(bool systemTelemetryMask13 READ systemTelemetryMask13 WRITE setsystemTelemetryMask13 NOTIFY systemTelemetryMask13Changed);
    Q_PROPERTY(bool systemTelemetryMask14 READ systemTelemetryMask14 WRITE setsystemTelemetryMask14 NOTIFY systemTelemetryMask14Changed);
    Q_PROPERTY(bool systemTelemetryMask15 READ systemTelemetryMask15 WRITE setsystemTelemetryMask15 NOTIFY systemTelemetryMask15Changed);
    Q_PROPERTY(bool systemTelemetryMask16 READ systemTelemetryMask16 WRITE setsystemTelemetryMask16 NOTIFY systemTelemetryMask16Changed);
    Q_PROPERTY(bool systemTelemetryMask17 READ systemTelemetryMask17 WRITE setsystemTelemetryMask17 NOTIFY systemTelemetryMask17Changed);
    Q_PROPERTY(bool systemTelemetryMask18 READ systemTelemetryMask18 WRITE setsystemTelemetryMask18 NOTIFY systemTelemetryMask18Changed);
    Q_PROPERTY(bool systemTelemetryMask19 READ systemTelemetryMask19 WRITE setsystemTelemetryMask19 NOTIFY systemTelemetryMask19Changed);
    Q_PROPERTY(bool systemTelemetryMask20 READ systemTelemetryMask20 WRITE setsystemTelemetryMask20 NOTIFY systemTelemetryMask20Changed);
    Q_PROPERTY(bool systemTelemetryMask21 READ systemTelemetryMask21 WRITE setsystemTelemetryMask21 NOTIFY systemTelemetryMask21Changed);
    Q_PROPERTY(bool systemTelemetryMask22 READ systemTelemetryMask22 WRITE setsystemTelemetryMask22 NOTIFY systemTelemetryMask22Changed);
    Q_PROPERTY(bool systemTelemetryMask23 READ systemTelemetryMask23 WRITE setsystemTelemetryMask23 NOTIFY systemTelemetryMask23Changed);
    Q_PROPERTY(bool systemTelemetryMask24 READ systemTelemetryMask24 WRITE setsystemTelemetryMask24 NOTIFY systemTelemetryMask24Changed);
    Q_PROPERTY(bool systemTelemetryMask25 READ systemTelemetryMask25 WRITE setsystemTelemetryMask25 NOTIFY systemTelemetryMask25Changed);
    Q_PROPERTY(bool systemTelemetryMask26 READ systemTelemetryMask26 WRITE setsystemTelemetryMask26 NOTIFY systemTelemetryMask26Changed);
    Q_PROPERTY(bool systemTelemetryMask27 READ systemTelemetryMask27 WRITE setsystemTelemetryMask27 NOTIFY systemTelemetryMask27Changed);
    Q_PROPERTY(bool systemTelemetryMask28 READ systemTelemetryMask28 WRITE setsystemTelemetryMask28 NOTIFY systemTelemetryMask28Changed);
    Q_PROPERTY(bool systemTelemetryMask29 READ systemTelemetryMask29 WRITE setsystemTelemetryMask29 NOTIFY systemTelemetryMask29Changed);
    Q_PROPERTY(bool systemTelemetryMask30 READ systemTelemetryMask30 WRITE setsystemTelemetryMask30 NOTIFY systemTelemetryMask30Changed);
    Q_PROPERTY(bool systemTelemetryMask31 READ systemTelemetryMask31 WRITE setsystemTelemetryMask31 NOTIFY systemTelemetryMask31Changed);
    Q_PROPERTY(bool systemTelemetryMask32 READ systemTelemetryMask32 WRITE setsystemTelemetryMask32 NOTIFY systemTelemetryMask32Changed);
    Q_PROPERTY(bool systemTelemetryMask33 READ systemTelemetryMask33 WRITE setsystemTelemetryMask33 NOTIFY systemTelemetryMask33Changed);
    Q_PROPERTY(bool systemTelemetryMask34 READ systemTelemetryMask34 WRITE setsystemTelemetryMask34 NOTIFY systemTelemetryMask34Changed);
    Q_PROPERTY(bool systemTelemetryMask35 READ systemTelemetryMask35 WRITE setsystemTelemetryMask35 NOTIFY systemTelemetryMask35Changed);
    Q_PROPERTY(bool systemTelemetryMask36 READ systemTelemetryMask36 WRITE setsystemTelemetryMask36 NOTIFY systemTelemetryMask36Changed);
    Q_PROPERTY(bool systemTelemetryMask37 READ systemTelemetryMask37 WRITE setsystemTelemetryMask37 NOTIFY systemTelemetryMask37Changed);
    Q_PROPERTY(bool systemTelemetryMask38 READ systemTelemetryMask38 WRITE setsystemTelemetryMask38 NOTIFY systemTelemetryMask38Changed);
    Q_PROPERTY(bool systemTelemetryMask39 READ systemTelemetryMask39 WRITE setsystemTelemetryMask39 NOTIFY systemTelemetryMask39Changed);
    Q_PROPERTY(bool systemTelemetryMask40 READ systemTelemetryMask40 WRITE setsystemTelemetryMask40 NOTIFY systemTelemetryMask40Changed);
    Q_PROPERTY(bool systemTelemetryMask41 READ systemTelemetryMask41 WRITE setsystemTelemetryMask41 NOTIFY systemTelemetryMask41Changed);
    Q_PROPERTY(bool systemTelemetryMask42 READ systemTelemetryMask42 WRITE setsystemTelemetryMask42 NOTIFY systemTelemetryMask42Changed);
    Q_PROPERTY(bool systemTelemetryMask43 READ systemTelemetryMask43 WRITE setsystemTelemetryMask43 NOTIFY systemTelemetryMask43Changed);
    Q_PROPERTY(bool systemTelemetryMask44 READ systemTelemetryMask44 WRITE setsystemTelemetryMask44 NOTIFY systemTelemetryMask44Changed);
    Q_PROPERTY(bool systemTelemetryMask45 READ systemTelemetryMask45 WRITE setsystemTelemetryMask45 NOTIFY systemTelemetryMask45Changed);
    Q_PROPERTY(bool systemTelemetryMask46 READ systemTelemetryMask46 WRITE setsystemTelemetryMask46 NOTIFY systemTelemetryMask46Changed);
    Q_PROPERTY(bool systemTelemetryMask47 READ systemTelemetryMask47 WRITE setsystemTelemetryMask47 NOTIFY systemTelemetryMask47Changed);
    Q_PROPERTY(bool systemTelemetryMask48 READ systemTelemetryMask48 WRITE setsystemTelemetryMask48 NOTIFY systemTelemetryMask48Changed);
    Q_PROPERTY(bool systemTelemetryMask49 READ systemTelemetryMask49 WRITE setsystemTelemetryMask49 NOTIFY systemTelemetryMask49Changed);
    Q_PROPERTY(bool systemTelemetryMask50 READ systemTelemetryMask50 WRITE setsystemTelemetryMask50 NOTIFY systemTelemetryMask50Changed);
    Q_PROPERTY(bool systemTelemetryMask51 READ systemTelemetryMask51 WRITE setsystemTelemetryMask51 NOTIFY systemTelemetryMask51Changed);
    Q_PROPERTY(bool systemTelemetryMask52 READ systemTelemetryMask52 WRITE setsystemTelemetryMask52 NOTIFY systemTelemetryMask52Changed);
    Q_PROPERTY(bool systemTelemetryMask53 READ systemTelemetryMask53 WRITE setsystemTelemetryMask53 NOTIFY systemTelemetryMask53Changed);
    Q_PROPERTY(bool systemTelemetryMask54 READ systemTelemetryMask54 WRITE setsystemTelemetryMask54 NOTIFY systemTelemetryMask54Changed);
    Q_PROPERTY(bool systemTelemetryMask55 READ systemTelemetryMask55 WRITE setsystemTelemetryMask55 NOTIFY systemTelemetryMask55Changed);
    Q_PROPERTY(bool systemTelemetryMask56 READ systemTelemetryMask56 WRITE setsystemTelemetryMask56 NOTIFY systemTelemetryMask56Changed);
    Q_PROPERTY(bool systemTelemetryMask57 READ systemTelemetryMask57 WRITE setsystemTelemetryMask57 NOTIFY systemTelemetryMask57Changed);
    Q_PROPERTY(bool systemTelemetryMask58 READ systemTelemetryMask58 WRITE setsystemTelemetryMask58 NOTIFY systemTelemetryMask58Changed);
    Q_PROPERTY(bool systemTelemetryMask59 READ systemTelemetryMask59 WRITE setsystemTelemetryMask59 NOTIFY systemTelemetryMask59Changed);
    Q_PROPERTY(bool systemTelemetryMask60 READ systemTelemetryMask60 WRITE setsystemTelemetryMask60 NOTIFY systemTelemetryMask60Changed);
    Q_PROPERTY(bool systemTelemetryMask61 READ systemTelemetryMask61 WRITE setsystemTelemetryMask61 NOTIFY systemTelemetryMask61Changed);
    Q_PROPERTY(bool systemTelemetryMask62 READ systemTelemetryMask62 WRITE setsystemTelemetryMask62 NOTIFY systemTelemetryMask62Changed);
    Q_PROPERTY(bool systemTelemetryMask63 READ systemTelemetryMask63 WRITE setsystemTelemetryMask63 NOTIFY systemTelemetryMask63Changed);

    Q_PROPERTY(bool emergencyBoardStatus0 READ emergencyBoardStatus0 WRITE setemergencyBoardStatus0 NOTIFY emergencyBoardStatus0Changed);
    Q_PROPERTY(bool emergencyBoardStatus1 READ emergencyBoardStatus1 WRITE setemergencyBoardStatus1 NOTIFY emergencyBoardStatus1Changed);
    Q_PROPERTY(bool emergencyBoardStatus2 READ emergencyBoardStatus2 WRITE setemergencyBoardStatus2 NOTIFY emergencyBoardStatus2Changed);
    Q_PROPERTY(bool emergencyBoardStatus3 READ emergencyBoardStatus3 WRITE setemergencyBoardStatus3 NOTIFY emergencyBoardStatus3Changed);
    Q_PROPERTY(bool emergencyBoardStatus4 READ emergencyBoardStatus4 WRITE setemergencyBoardStatus4 NOTIFY emergencyBoardStatus4Changed);
    Q_PROPERTY(bool emergencyBoardStatus5 READ emergencyBoardStatus5 WRITE setemergencyBoardStatus5 NOTIFY emergencyBoardStatus5Changed);
    Q_PROPERTY(bool emergencyBoardStatus6 READ emergencyBoardStatus6 WRITE setemergencyBoardStatus6 NOTIFY emergencyBoardStatus6Changed);
    Q_PROPERTY(bool emergencyBoardStatus7 READ emergencyBoardStatus7 WRITE setemergencyBoardStatus7 NOTIFY emergencyBoardStatus7Changed);
    Q_PROPERTY(bool emergencyBoardStatus8 READ emergencyBoardStatus8 WRITE setemergencyBoardStatus8 NOTIFY emergencyBoardStatus8Changed);
    Q_PROPERTY(bool emergencyBoardStatus9 READ emergencyBoardStatus9 WRITE setemergencyBoardStatus9 NOTIFY emergencyBoardStatus9Changed);
    Q_PROPERTY(bool emergencyBoardStatus10 READ emergencyBoardStatus10 WRITE setemergencyBoardStatus10 NOTIFY emergencyBoardStatus10Changed);
    Q_PROPERTY(bool emergencyBoardStatus11 READ emergencyBoardStatus11 WRITE setemergencyBoardStatus11 NOTIFY emergencyBoardStatus11Changed);
    Q_PROPERTY(bool emergencyBoardStatus12 READ emergencyBoardStatus12 WRITE setemergencyBoardStatus12 NOTIFY emergencyBoardStatus12Changed);
    Q_PROPERTY(bool emergencyBoardStatus13 READ emergencyBoardStatus13 WRITE setemergencyBoardStatus13 NOTIFY emergencyBoardStatus13Changed);
    Q_PROPERTY(bool emergencyBoardStatus14 READ emergencyBoardStatus14 WRITE setemergencyBoardStatus14 NOTIFY emergencyBoardStatus14Changed);
    Q_PROPERTY(bool emergencyBoardStatus15 READ emergencyBoardStatus15 WRITE setemergencyBoardStatus15 NOTIFY emergencyBoardStatus15Changed);

    Q_PROPERTY(bool PSUStatus0 READ PSUStatus0 WRITE setPSUStatus0 NOTIFY PSUStatus0Changed);
    Q_PROPERTY(bool PSUStatus1 READ PSUStatus1 WRITE setPSUStatus1 NOTIFY PSUStatus1Changed);
    Q_PROPERTY(bool PSUStatus2 READ PSUStatus2 WRITE setPSUStatus2 NOTIFY PSUStatus2Changed);
    Q_PROPERTY(bool PSUStatus3 READ PSUStatus3 WRITE setPSUStatus3 NOTIFY PSUStatus3Changed);
    Q_PROPERTY(bool PSUStatus4 READ PSUStatus4 WRITE setPSUStatus4 NOTIFY PSUStatus4Changed);
    Q_PROPERTY(bool PSUStatus5 READ PSUStatus5 WRITE setPSUStatus5 NOTIFY PSUStatus5Changed);
    Q_PROPERTY(bool PSUStatus6 READ PSUStatus6 WRITE setPSUStatus6 NOTIFY PSUStatus6Changed);
    Q_PROPERTY(bool PSUStatus7 READ PSUStatus7 WRITE setPSUStatus7 NOTIFY PSUStatus7Changed);
    Q_PROPERTY(bool PSUStatus8 READ PSUStatus8 WRITE setPSUStatus8 NOTIFY PSUStatus8Changed);
    Q_PROPERTY(bool PSUStatus9 READ PSUStatus9 WRITE setPSUStatus9 NOTIFY PSUStatus9Changed);
    Q_PROPERTY(bool PSUStatus10 READ PSUStatus10 WRITE setPSUStatus10 NOTIFY PSUStatus10Changed);
    Q_PROPERTY(bool PSUStatus11 READ PSUStatus11 WRITE setPSUStatus11 NOTIFY PSUStatus11Changed);
    Q_PROPERTY(bool PSUStatus12 READ PSUStatus12 WRITE setPSUStatus12 NOTIFY PSUStatus12Changed);
    Q_PROPERTY(bool PSUStatus13 READ PSUStatus13 WRITE setPSUStatus13 NOTIFY PSUStatus13Changed);
    Q_PROPERTY(bool PSUStatus14 READ PSUStatus14 WRITE setPSUStatus14 NOTIFY PSUStatus14Changed);
    Q_PROPERTY(bool PSUStatus15 READ PSUStatus15 WRITE setPSUStatus15 NOTIFY PSUStatus15Changed);

    Q_PROPERTY(bool emergencyRadioLinkStatus0 READ emergencyRadioLinkStatus0 WRITE setemergencyRadioLinkStatus0 NOTIFY emergencyRadioLinkStatus0Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus1 READ emergencyRadioLinkStatus1 WRITE setemergencyRadioLinkStatus1 NOTIFY emergencyRadioLinkStatus1Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus2 READ emergencyRadioLinkStatus2 WRITE setemergencyRadioLinkStatus2 NOTIFY emergencyRadioLinkStatus2Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus3 READ emergencyRadioLinkStatus3 WRITE setemergencyRadioLinkStatus3 NOTIFY emergencyRadioLinkStatus3Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus4 READ emergencyRadioLinkStatus4 WRITE setemergencyRadioLinkStatus4 NOTIFY emergencyRadioLinkStatus4Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus5 READ emergencyRadioLinkStatus5 WRITE setemergencyRadioLinkStatus5 NOTIFY emergencyRadioLinkStatus5Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus6 READ emergencyRadioLinkStatus6 WRITE setemergencyRadioLinkStatus6 NOTIFY emergencyRadioLinkStatus6Changed);
    Q_PROPERTY(bool emergencyRadioLinkStatus7 READ emergencyRadioLinkStatus7 WRITE setemergencyRadioLinkStatus7 NOTIFY emergencyRadioLinkStatus7Changed);

    Q_PROPERTY(int systemMsgCounter READ systemMsgCounter WRITE setsystemMsgCounter NOTIFY systemMsgCounterChanged)


    /* RADIOLINK */

    Q_PROPERTY(quint16 RSSI READ RSSI WRITE setRSSI NOTIFY RSSIChanged);
    Q_PROPERTY(quint8 radiolinkErrorCounter READ radiolinkErrorCounter WRITE setradiolinkErrorCounter NOTIFY radiolinkErrorCounterChanged);
    Q_PROPERTY(bool radiolinkMask0 READ radiolinkMask0 WRITE setradiolinkMask0 NOTIFY radiolinkMask0Changed);
    Q_PROPERTY(bool radiolinkMask1 READ radiolinkMask1 WRITE setradiolinkMask1 NOTIFY radiolinkMask1Changed);
    Q_PROPERTY(bool radiolinkMask2 READ radiolinkMask2 WRITE setradiolinkMask2 NOTIFY radiolinkMask2Changed);
    Q_PROPERTY(bool radiolinkMask3 READ radiolinkMask3 WRITE setradiolinkMask3 NOTIFY radiolinkMask3Changed);
    Q_PROPERTY(bool radiolinkMask4 READ radiolinkMask4 WRITE setradiolinkMask4 NOTIFY radiolinkMask4Changed);
    Q_PROPERTY(bool radiolinkMask5 READ radiolinkMask5 WRITE setradiolinkMask5 NOTIFY radiolinkMask5Changed);
    Q_PROPERTY(bool radiolinkMask6 READ radiolinkMask6 WRITE setradiolinkMask6 NOTIFY radiolinkMask6Changed);
    Q_PROPERTY(bool radiolinkMask7 READ radiolinkMask7 WRITE setradiolinkMask7 NOTIFY radiolinkMask7Changed);
    Q_PROPERTY(bool radiolinkMask8 READ radiolinkMask8 WRITE setradiolinkMask8 NOTIFY radiolinkMask8Changed);
    Q_PROPERTY(bool radiolinkMask9 READ radiolinkMask9 WRITE setradiolinkMask9 NOTIFY radiolinkMask9Changed);
    Q_PROPERTY(bool radiolinkMask10 READ radiolinkMask10 WRITE setradiolinkMask10 NOTIFY radiolinkMask10Changed);
    Q_PROPERTY(bool radiolinkMask11 READ radiolinkMask11 WRITE setradiolinkMask11 NOTIFY radiolinkMask11Changed);
    Q_PROPERTY(bool radiolinkMask12 READ radiolinkMask12 WRITE setradiolinkMask12 NOTIFY radiolinkMask12Changed);
    Q_PROPERTY(bool radiolinkMask13 READ radiolinkMask13 WRITE setradiolinkMask13 NOTIFY radiolinkMask13Changed);
    Q_PROPERTY(bool radiolinkMask14 READ radiolinkMask14 WRITE setradiolinkMask14 NOTIFY radiolinkMask14Changed);
    Q_PROPERTY(bool radiolinkMask15 READ radiolinkMask15 WRITE setradiolinkMask15 NOTIFY radiolinkMask15Changed);
    Q_PROPERTY(bool radiolinkMask16 READ radiolinkMask16 WRITE setradiolinkMask16 NOTIFY radiolinkMask16Changed);
    Q_PROPERTY(bool radiolinkMask17 READ radiolinkMask17 WRITE setradiolinkMask17 NOTIFY radiolinkMask17Changed);
    Q_PROPERTY(bool radiolinkMask18 READ radiolinkMask18 WRITE setradiolinkMask18 NOTIFY radiolinkMask18Changed);
    Q_PROPERTY(bool radiolinkMask19 READ radiolinkMask19 WRITE setradiolinkMask19 NOTIFY radiolinkMask19Changed);
    Q_PROPERTY(bool radiolinkMask20 READ radiolinkMask20 WRITE setradiolinkMask20 NOTIFY radiolinkMask20Changed);
    Q_PROPERTY(bool radiolinkMask21 READ radiolinkMask21 WRITE setradiolinkMask21 NOTIFY radiolinkMask21Changed);
    Q_PROPERTY(bool radiolinkMask22 READ radiolinkMask22 WRITE setradiolinkMask22 NOTIFY radiolinkMask22Changed);
    Q_PROPERTY(bool radiolinkMask23 READ radiolinkMask23 WRITE setradiolinkMask23 NOTIFY radiolinkMask23Changed);
    Q_PROPERTY(bool radiolinkMask24 READ radiolinkMask24 WRITE setradiolinkMask24 NOTIFY radiolinkMask24Changed);
    Q_PROPERTY(bool radiolinkMask25 READ radiolinkMask25 WRITE setradiolinkMask25 NOTIFY radiolinkMask25Changed);
    Q_PROPERTY(bool radiolinkMask26 READ radiolinkMask26 WRITE setradiolinkMask26 NOTIFY radiolinkMask26Changed);
    Q_PROPERTY(bool radiolinkMask27 READ radiolinkMask27 WRITE setradiolinkMask27 NOTIFY radiolinkMask27Changed);
    Q_PROPERTY(bool radiolinkMask28 READ radiolinkMask28 WRITE setradiolinkMask28 NOTIFY radiolinkMask28Changed);
    Q_PROPERTY(bool radiolinkMask29 READ radiolinkMask29 WRITE setradiolinkMask29 NOTIFY radiolinkMask29Changed);
    Q_PROPERTY(bool radiolinkMask30 READ radiolinkMask30 WRITE setradiolinkMask30 NOTIFY radiolinkMask30Changed);
    Q_PROPERTY(bool radiolinkMask31 READ radiolinkMask31 WRITE setradiolinkMask31 NOTIFY radiolinkMask31Changed);

    Q_PROPERTY(int radiolinkMsgCounter READ radiolinkMsgCounter WRITE setradiolinkMsgCounter NOTIFY radiolinkMsgCounterChanged)


    /* GUIDANCE */

    Q_PROPERTY(bool guidanceMask0 READ guidanceMask0 WRITE setguidanceMask0 NOTIFY guidanceMask0Changed);
    Q_PROPERTY(bool guidanceMask1 READ guidanceMask1 WRITE setguidanceMask1 NOTIFY guidanceMask1Changed);
    Q_PROPERTY(bool guidanceMask2 READ guidanceMask2 WRITE setguidanceMask2 NOTIFY guidanceMask2Changed);
    Q_PROPERTY(bool guidanceMask3 READ guidanceMask3 WRITE setguidanceMask3 NOTIFY guidanceMask3Changed);
    Q_PROPERTY(bool guidanceMask4 READ guidanceMask4 WRITE setguidanceMask4 NOTIFY guidanceMask4Changed);
    Q_PROPERTY(bool guidanceMask5 READ guidanceMask5 WRITE setguidanceMask5 NOTIFY guidanceMask5Changed);
    Q_PROPERTY(bool guidanceMask6 READ guidanceMask6 WRITE setguidanceMask6 NOTIFY guidanceMask6Changed);
    Q_PROPERTY(bool guidanceMask7 READ guidanceMask7 WRITE setguidanceMask7 NOTIFY guidanceMask7Changed);
    Q_PROPERTY(bool guidanceMask8 READ guidanceMask8 WRITE setguidanceMask8 NOTIFY guidanceMask8Changed);
    Q_PROPERTY(bool guidanceMask9 READ guidanceMask9 WRITE setguidanceMask9 NOTIFY guidanceMask9Changed);
    Q_PROPERTY(bool guidanceMask10 READ guidanceMask10 WRITE setguidanceMask10 NOTIFY guidanceMask10Changed);
    Q_PROPERTY(bool guidanceMask11 READ guidanceMask11 WRITE setguidanceMask11 NOTIFY guidanceMask11Changed);
    Q_PROPERTY(bool guidanceMask12 READ guidanceMask12 WRITE setguidanceMask12 NOTIFY guidanceMask12Changed);
    Q_PROPERTY(bool guidanceMask13 READ guidanceMask13 WRITE setguidanceMask13 NOTIFY guidanceMask13Changed);
    Q_PROPERTY(bool guidanceMask14 READ guidanceMask14 WRITE setguidanceMask14 NOTIFY guidanceMask14Changed);
    Q_PROPERTY(bool guidanceMask15 READ guidanceMask15 WRITE setguidanceMask15 NOTIFY guidanceMask15Changed);
    Q_PROPERTY(bool guidanceMask16 READ guidanceMask16 WRITE setguidanceMask16 NOTIFY guidanceMask16Changed);
    Q_PROPERTY(bool guidanceMask17 READ guidanceMask17 WRITE setguidanceMask17 NOTIFY guidanceMask17Changed);
    Q_PROPERTY(bool guidanceMask18 READ guidanceMask18 WRITE setguidanceMask18 NOTIFY guidanceMask18Changed);
    Q_PROPERTY(bool guidanceMask19 READ guidanceMask19 WRITE setguidanceMask19 NOTIFY guidanceMask19Changed);
    Q_PROPERTY(bool guidanceMask20 READ guidanceMask20 WRITE setguidanceMask20 NOTIFY guidanceMask20Changed);
    Q_PROPERTY(bool guidanceMask21 READ guidanceMask21 WRITE setguidanceMask21 NOTIFY guidanceMask21Changed);
    Q_PROPERTY(bool guidanceMask22 READ guidanceMask22 WRITE setguidanceMask22 NOTIFY guidanceMask22Changed);
    Q_PROPERTY(bool guidanceMask23 READ guidanceMask23 WRITE setguidanceMask23 NOTIFY guidanceMask23Changed);
    Q_PROPERTY(bool guidanceMask24 READ guidanceMask24 WRITE setguidanceMask24 NOTIFY guidanceMask24Changed);
    Q_PROPERTY(bool guidanceMask25 READ guidanceMask25 WRITE setguidanceMask25 NOTIFY guidanceMask25Changed);
    Q_PROPERTY(bool guidanceMask26 READ guidanceMask26 WRITE setguidanceMask26 NOTIFY guidanceMask26Changed);
    Q_PROPERTY(bool guidanceMask27 READ guidanceMask27 WRITE setguidanceMask27 NOTIFY guidanceMask27Changed);
    Q_PROPERTY(bool guidanceMask28 READ guidanceMask28 WRITE setguidanceMask28 NOTIFY guidanceMask28Changed);
    Q_PROPERTY(bool guidanceMask29 READ guidanceMask29 WRITE setguidanceMask29 NOTIFY guidanceMask29Changed);
    Q_PROPERTY(bool guidanceMask30 READ guidanceMask30 WRITE setguidanceMask30 NOTIFY guidanceMask30Changed);
    Q_PROPERTY(bool guidanceMask31 READ guidanceMask31 WRITE setguidanceMask31 NOTIFY guidanceMask31Changed);

    Q_PROPERTY(int guidanceMsgCounter READ guidanceMsgCounter WRITE setguidanceMsgCounter NOTIFY guidanceMsgCounterChanged)

    /* STORAGE */

    Q_PROPERTY(quint32 storageFreeDataSize READ storageFreeDataSize WRITE setstorageFreeDataSize NOTIFY storageFreeDataSizeChanged);
    Q_PROPERTY(bool storage0 READ storage0 WRITE setstorage0 NOTIFY storage0Changed)
    Q_PROPERTY(bool storage1 READ storage1 WRITE setstorage1 NOTIFY storage1Changed)
    Q_PROPERTY(bool storage2 READ storage2 WRITE setstorage2 NOTIFY storage2Changed)
    Q_PROPERTY(bool storage3 READ storage3 WRITE setstorage3 NOTIFY storage3Changed)
    Q_PROPERTY(bool storage4 READ storage4 WRITE setstorage4 NOTIFY storage4Changed)
    Q_PROPERTY(bool storage5 READ storage5 WRITE setstorage5 NOTIFY storage5Changed)
    Q_PROPERTY(bool storage6 READ storage6 WRITE setstorage6 NOTIFY storage6Changed)
    Q_PROPERTY(bool storage7 READ storage7 WRITE setstorage7 NOTIFY storage7Changed)
    Q_PROPERTY(bool storage8 READ storage8 WRITE setstorage8 NOTIFY storage8Changed)
    Q_PROPERTY(bool storage9 READ storage9 WRITE setstorage9 NOTIFY storage9Changed)
    Q_PROPERTY(bool storage10 READ storage10 WRITE setstorage10 NOTIFY storage10Changed)
    Q_PROPERTY(bool storage11 READ storage11 WRITE setstorage11 NOTIFY storage11Changed)
    Q_PROPERTY(bool storage12 READ storage12 WRITE setstorage12 NOTIFY storage12Changed)
    Q_PROPERTY(bool storage13 READ storage13 WRITE setstorage13 NOTIFY storage13Changed)
    Q_PROPERTY(bool storage14 READ storage14 WRITE setstorage14 NOTIFY storage14Changed)
    Q_PROPERTY(bool storage15 READ storage15 WRITE setstorage15 NOTIFY storage15Changed)
    Q_PROPERTY(bool storage16 READ storage16 WRITE setstorage16 NOTIFY storage16Changed)
    Q_PROPERTY(bool storage17 READ storage17 WRITE setstorage17 NOTIFY storage17Changed)
    Q_PROPERTY(bool storage18 READ storage18 WRITE setstorage18 NOTIFY storage18Changed)
    Q_PROPERTY(bool storage19 READ storage19 WRITE setstorage19 NOTIFY storage19Changed)
    Q_PROPERTY(bool storage20 READ storage20 WRITE setstorage20 NOTIFY storage20Changed)
    Q_PROPERTY(bool storage21 READ storage21 WRITE setstorage21 NOTIFY storage21Changed)
    Q_PROPERTY(bool storage22 READ storage22 WRITE setstorage22 NOTIFY storage22Changed)
    Q_PROPERTY(bool storage23 READ storage23 WRITE setstorage23 NOTIFY storage23Changed)
    Q_PROPERTY(bool storage24 READ storage24 WRITE setstorage24 NOTIFY storage24Changed)
    Q_PROPERTY(bool storage25 READ storage25 WRITE setstorage25 NOTIFY storage25Changed)
    Q_PROPERTY(bool storage26 READ storage26 WRITE setstorage26 NOTIFY storage26Changed)
    Q_PROPERTY(bool storage27 READ storage27 WRITE setstorage27 NOTIFY storage27Changed)
    Q_PROPERTY(bool storage28 READ storage28 WRITE setstorage28 NOTIFY storage28Changed)
    Q_PROPERTY(bool storage29 READ storage29 WRITE setstorage29 NOTIFY storage29Changed)
    Q_PROPERTY(bool storage30 READ storage30 WRITE setstorage30 NOTIFY storage30Changed)
    Q_PROPERTY(bool storage31 READ storage31 WRITE setstorage31 NOTIFY storage31Changed)

    Q_PROPERTY(int storageMsgCounter READ storageMsgCounter WRITE setstorageMsgCounter NOTIFY storageMsgCounterChanged)

    Q_PROPERTY(bool msgTelemetryOld READ msgTelemetryOld WRITE setmsgTelemetryOld NOTIFY msgTelemetryOldChanged)
    Q_PROPERTY(bool msgGuidanceOld READ msgGuidanceOld WRITE setmsgGuidanceOld NOTIFY msgGuidanceOldChanged)
    Q_PROPERTY(bool msgStorageOld READ msgStorageOld WRITE setmsgStorageOld NOTIFY msgStorageOldChanged)
    Q_PROPERTY(bool msgSystemOld READ msgSystemOld WRITE setmsgSystemOld NOTIFY msgSystemOldChanged)
    Q_PROPERTY(bool msgRadioLinkOld READ msgRadioLinkOld WRITE setmsgRadioLinkOld NOTIFY msgRadioLinkOldChanged)
    Q_PROPERTY(bool msgMotorOld READ msgMotorOld WRITE setmsgMotorOld NOTIFY msgMotorOldChanged)


    /* DESC */
    Q_PROPERTY(QString LatitudeDesc READ LatitudeDesc WRITE setLatitudeDesc NOTIFY LatitudeDescChanged)
    Q_PROPERTY(QString LongitudeDesc READ LongitudeDesc WRITE setLongitudeDesc NOTIFY LongitudeDescChanged)
    Q_PROPERTY(QString GNSSAltitudeDesc READ GNSSAltitudeDesc WRITE setGNSSAltitudeDesc NOTIFY GNSSAltitudeDescChanged)

    Q_PROPERTY(QString TimeStampDesc READ TimeStampDesc WRITE setTimeStampDesc NOTIFY TimeStampDescChanged)
    Q_PROPERTY(QString TimeStampRIODesc READ TimeStampRIODesc WRITE setTimeStampRIODesc NOTIFY TimeStampRIODescChanged)

    Q_PROPERTY(QString AirSpeed_UVectorDesc READ AirSpeed_UVectorDesc WRITE setAirSpeed_UVectorDesc NOTIFY AirSpeed_UVectorDescChanged)
    Q_PROPERTY(QString AirSpeed_VVectorDesc READ AirSpeed_VVectorDesc WRITE setAirSpeed_VVectorDesc NOTIFY AirSpeed_VVectorDescChanged)
    Q_PROPERTY(QString AirSpeed_WVectorDesc READ AirSpeed_WVectorDesc WRITE setAirSpeed_WVectorDesc NOTIFY AirSpeed_WVectorDescChanged)
    Q_PROPERTY(QString AirTemperatureDesc READ AirTemperatureDesc WRITE setAirTemperatureDesc NOTIFY AirTemperatureDescChanged)
    Q_PROPERTY(QString AltitudeFromRadarAltimeterDesc READ AltitudeFromRadarAltimeterDesc WRITE setAltitudeFromRadarAltimeterDesc NOTIFY AltitudeFromRadarAltimeterDescChanged)
    Q_PROPERTY(QString AltitudeFromPayloadAltimeterDesc READ AltitudeFromPayloadAltimeterDesc WRITE setAltitudeFromPayloadAltimeterDesc NOTIFY AltitudeFromPayloadAltimeterDescChanged)
    Q_PROPERTY(QString LinearVelocityHorizontalDesc READ LinearVelocityHorizontalDesc WRITE setLinearVelocityHorizontalDesc NOTIFY LinearVelocityHorizontalDescChanged)
    Q_PROPERTY(QString LinearVelocityVerticalDesc READ LinearVelocityVerticalDesc WRITE setLinearVelocityVerticalDesc NOTIFY LinearVelocityVerticalDescChanged)
    Q_PROPERTY(QString PositionAccuracyDesc READ PositionAccuracyDesc WRITE setPositionAccuracyDesc NOTIFY PositionAccuracyDescChanged)
    Q_PROPERTY(QString SpeedAccuracyDesc READ SpeedAccuracyDesc WRITE setSpeedAccuracyDesc NOTIFY SpeedAccuracyDescChanged)
    Q_PROPERTY(QString LinearAccelerationXDesc READ LinearAccelerationXDesc WRITE setLinearAccelerationXDesc NOTIFY LinearAccelerationXDescChanged)
    Q_PROPERTY(QString LinearAccelerationYDesc READ LinearAccelerationYDesc WRITE setLinearAccelerationYDesc NOTIFY LinearAccelerationYDescChanged)
    Q_PROPERTY(QString LinearAccelerationZDesc READ LinearAccelerationZDesc WRITE setLinearAccelerationZDesc NOTIFY LinearAccelerationZDescChanged)
    Q_PROPERTY(QString ECEFVectorPositionXDesc READ ECEFVectorPositionXDesc WRITE setECEFVectorPositionXDesc NOTIFY ECEFVectorPositionXDescChanged)
    Q_PROPERTY(QString ECEFVectorPositionYDesc READ ECEFVectorPositionYDesc WRITE setECEFVectorPositionYDesc NOTIFY ECEFVectorPositionYDescChanged)
    Q_PROPERTY(QString ECEFVectorPositionZDesc READ ECEFVectorPositionZDesc WRITE setECEFVectorPositionZDesc NOTIFY ECEFVectorPositionZDescChanged)
    Q_PROPERTY(QString ECEFVectorVelocityXDesc READ ECEFVectorVelocityXDesc WRITE setECEFVectorVelocityXDesc NOTIFY ECEFVectorVelocityXDescChanged)
    Q_PROPERTY(QString ECEFVectorVelocityYDesc READ ECEFVectorVelocityYDesc WRITE setECEFVectorVelocityYDesc NOTIFY ECEFVectorVelocityYDescChanged)
    Q_PROPERTY(QString ECEFVectorVelocityZDesc READ ECEFVectorVelocityZDesc WRITE setECEFVectorVelocityZDesc NOTIFY ECEFVectorVelocityZDescChanged)
    Q_PROPERTY(QString RollAngleDesc READ RollAngleDesc WRITE setRollAngleDesc NOTIFY RollAngleDescChanged)
    Q_PROPERTY(QString PitchAngleDesc READ PitchAngleDesc WRITE setPitchAngleDesc NOTIFY PitchAngleDescChanged)
    Q_PROPERTY(QString YawAngleDesc READ YawAngleDesc WRITE setYawAngleDesc NOTIFY YawAngleDescChanged)
    Q_PROPERTY(QString AngularRateRollDesc READ AngularRateRollDesc WRITE setAngularRateRollDesc NOTIFY AngularRateRollDescChanged)
    Q_PROPERTY(QString AngularRatePitchDesc READ AngularRatePitchDesc WRITE setAngularRatePitchDesc NOTIFY AngularRatePitchDescChanged)
    Q_PROPERTY(QString AngularRateYawDesc READ AngularRateYawDesc WRITE setAngularRateYawDesc NOTIFY AngularRateYawDescChanged)
    Q_PROPERTY(QString Quaternion0Desc READ Quaternion0Desc WRITE setQuaternion0Desc NOTIFY Quaternion0DescChanged)
    Q_PROPERTY(QString Quaternion1Desc READ Quaternion1Desc WRITE setQuaternion1Desc NOTIFY Quaternion1DescChanged)
    Q_PROPERTY(QString Quaternion2Desc READ Quaternion2Desc WRITE setQuaternion2Desc NOTIFY Quaternion2DescChanged)
    Q_PROPERTY(QString Quaternion3Desc READ Quaternion3Desc WRITE setQuaternion3Desc NOTIFY Quaternion3DescChanged)
    Q_PROPERTY(QString NumberOfGPSSatelliteDesc READ NumberOfGPSSatelliteDesc WRITE setNumberOfGPSSatelliteDesc NOTIFY NumberOfGPSSatelliteDescChanged)
    Q_PROPERTY(QString AnemCommErrorCounterDesc READ AnemCommErrorCounterDesc WRITE setAnemCommErrorCounterDesc NOTIFY AnemCommErrorCounterDescChanged)
    Q_PROPERTY(QString RDAltCommErrorCounterDesc READ RDAltCommErrorCounterDesc WRITE setRDAltCommErrorCounterDesc NOTIFY RDAltCommErrorCounterDescChanged)
    Q_PROPERTY(QString GNSSCommErrorCounterDesc READ GNSSCommErrorCounterDesc WRITE setGNSSCommErrorCounterDesc NOTIFY GNSSCommErrorCounterDescChanged)
    Q_PROPERTY(QString PLAltCommErrorCounterDesc READ PLAltCommErrorCounterDesc WRITE setPLAltCommErrorCounterDesc NOTIFY PLAltCommErrorCounterDescChanged)

    Q_PROPERTY(QString MotorARealPositionDesc READ MotorARealPositionDesc WRITE setMotorARealPositionDesc NOTIFY MotorARealPositionDescChanged)
    Q_PROPERTY(QString MotorADemandPositionDesc READ MotorADemandPositionDesc WRITE setMotorADemandPositionDesc NOTIFY MotorADemandPositionDescChanged)
    Q_PROPERTY(QString MotorATorqueDesc READ MotorATorqueDesc WRITE setMotorATorqueDesc NOTIFY MotorATorqueDescChanged)
    Q_PROPERTY(QString MotorATempDesc READ MotorATempDesc WRITE setMotorATempDesc NOTIFY MotorATempDescChanged)

    Q_PROPERTY(QString MotorBRealPositionDesc READ MotorBRealPositionDesc WRITE setMotorBRealPositionDesc NOTIFY MotorBRealPositionDescChanged)
    Q_PROPERTY(QString MotorBDemandPositionDesc READ MotorBDemandPositionDesc WRITE setMotorBDemandPositionDesc NOTIFY MotorBDemandPositionDescChanged)
    Q_PROPERTY(QString MotorBTorqueDesc READ MotorBTorqueDesc WRITE setMotorBTorqueDesc NOTIFY MotorBTorqueDescChanged)
    Q_PROPERTY(QString MotorBTempDesc READ MotorBTempDesc WRITE setMotorBTempDesc NOTIFY MotorBTempDescChanged)

    Q_PROPERTY(QString BMSVoltageDesc READ BMSVoltageDesc WRITE setBMSVoltageDesc NOTIFY BMSVoltageDescChanged)
    Q_PROPERTY(QString BMSAbsorptionDesc READ BMSAbsorptionDesc WRITE setBMSAbsorptionDesc NOTIFY BMSAbsorptionDescChanged)
    Q_PROPERTY(QString BMSTempDesc READ BMSTempDesc WRITE setBMSTempDesc NOTIFY BMSTempDescChanged)

    Q_PROPERTY(QString MotorAFaultsMaskDesc READ MotorAFaultsMaskDesc WRITE setMotorAFaultsMaskDesc NOTIFY MotorAFaultsMaskDescChanged)
    Q_PROPERTY(QString MotorBFaultsMaskDesc READ MotorBFaultsMaskDesc WRITE setMotorBFaultsMaskDesc NOTIFY MotorBFaultsMaskDescChanged)
    Q_PROPERTY(QString BMSFaultsMaskDesc READ BMSFaultsMaskDesc WRITE setBMSFaultsMaskDesc NOTIFY BMSFaultsMaskDescChanged)

    Q_PROPERTY(QString ChargeValueDesc READ ChargeValueDesc WRITE setChargeValueDesc NOTIFY ChargeValueDescChanged)

    Q_PROPERTY(QString FlightModeDesc READ FlightModeDesc WRITE setFlightModeDesc NOTIFY FlightModeDescChanged)
    Q_PROPERTY(QString FlightPhaseDesc READ FlightPhaseDesc WRITE setFlightPhaseDesc NOTIFY FlightPhaseDescChanged)
    Q_PROPERTY(QString FlightPhaseExecutionTimeDesc READ FlightPhaseExecutionTimeDesc WRITE setFlightPhaseExecutionTimeDesc NOTIFY FlightPhaseExecutionTimeDescChanged)

    Q_PROPERTY(QString communicationErrorCounterDesc READ communicationErrorCounterDesc WRITE setcommunicationErrorCounterDesc NOTIFY communicationErrorCounterDescChanged);

    Q_PROPERTY(QString RSSIDesc READ RSSIDesc WRITE setRSSIDesc NOTIFY RSSIDescChanged);

    Q_PROPERTY(QString storageFreeDataSizeDesc READ storageFreeDataSizeDesc WRITE setstorageFreeDataSizeDesc NOTIFY storageFreeDataSizeDescChanged);


    /* TBD */
    Q_PROPERTY(quint8 GSRLErrorCounter READ GSRLErrorCounter WRITE setGSRLErrorCounter NOTIFY GSRLErrorCounterChanged)
    Q_PROPERTY(quint8 FSRLErrorCounter READ FSRLErrorCounter WRITE setFSRLErrorCounter NOTIFY FSRLErrorCounterChanged)
    Q_PROPERTY(quint8 RLHeartbeatCounter READ RLHeartbeatCounter WRITE setRLHeartbeatCounter NOTIFY RLHeartbeatCounterChanged)
    Q_PROPERTY(bool gnssFound READ gnssFound WRITE setgnssFound NOTIFY gnssFoundChanged)
public:

    void showData(QVariant data);



    quint64 TimeStamp() const;
    void setTimeStamp(quint64 newTimeStamp);

    quint64 TimeStampRIO() const;
    void setTimeStampRIO(quint64 newTimeStampRIO);

    qint32 Latitude() const;
    void setLatitude(qint32 newLatitude);



    const qint32& Longitude() const {return m_Longitude;};
    const quint32& GNSSAltitude() const {return m_GNSSAltitude;};
    const qint16& AirSpeed_UVector() const {return m_AirSpeed_UVector;};
    const qint16& AirSpeed_VVector() const {return m_AirSpeed_VVector;};
    const qint16& AirSpeed_WVector() const {return m_AirSpeed_WVector;};
    const qint16& AirTemperature() const {return m_AirTemperature;};
    const qint32& AltitudeFromRadarAltimeter() const {return m_AltitudeFromRadarAltimeter;};
    const qint32& AltitudeFromPayloadAltimeter() const {return m_AltitudeFromPayloadAltimeter;};
    const quint16& LinearVelocityHorizontal() const {return m_LinearVelocityHorizontal;};
    const qint16& LinearVelocityVertical() const {return m_LinearVelocityVertical;};
    const quint16& PositionAccuracy() const {return m_PositionAccuracy;};
    const quint16& SpeedAccuracy() const {return m_SpeedAccuracy;};
    const qint16& LinearAccelerationX() const {return m_LinearAccelerationX;};
    const qint16& LinearAccelerationY() const {return m_LinearAccelerationY;};
    const qint16& LinearAccelerationZ() const {return m_LinearAccelerationZ;};
    const float& ECEFVectorPositionX() const {return m_ECEFVectorPositionX;};
    const float& ECEFVectorPositionY() const {return m_ECEFVectorPositionY;};
    const float& ECEFVectorPositionZ() const {return m_ECEFVectorPositionZ;};
    const float& ECEFVectorVelocityX() const {return m_ECEFVectorVelocityX;};
    const float& ECEFVectorVelocityY() const {return m_ECEFVectorVelocityY;};
    const float& ECEFVectorVelocityZ() const {return m_ECEFVectorVelocityZ;};
    const qint16& RollAngle() const {return m_RollAngle;};
    const qint16& PitchAngle() const {return m_PitchAngle;};
    const qint16& YawAngle() const {return m_YawAngle;};
    const qint16& AngularRateRoll() const {return m_AngularRateRoll;};
    const qint16& AngularRatePitch() const {return m_AngularRatePitch;};
    const qint16& AngularRateYaw() const {return m_AngularRateYaw;};
    const double& Quaternion0() const {return m_Quaternion0;};
    const double& Quaternion1() const {return m_Quaternion1;};
    const double& Quaternion2() const {return m_Quaternion2;};
    const double& Quaternion3() const {return m_Quaternion3;};
    const quint8& NumberOfGPSSatellite() const {return m_NumberOfGPSSatellite;};
    const quint8& AnemCommErrorCounter() const {return m_AnemCommErrorCounter;};
    const quint8& RDAltCommErrorCounter() const {return m_RDAltCommErrorCounter;};
    const quint8& GNSSCommErrorCounter() const {return m_GNSSCommErrorCounter;};
    const quint8& PLAltCommErrorCounter() const {return m_PLAltCommErrorCounter;};
    const bool& telemetry0() const {return m_telemetry0;};
    const bool& telemetry1() const {return m_telemetry1;};
    const bool& telemetry2() const {return m_telemetry2;};
    const bool& telemetry3() const {return m_telemetry3;};
    const bool& telemetry4() const {return m_telemetry4;};
    const bool& telemetry5() const {return m_telemetry5;};
    const bool& telemetry6() const {return m_telemetry6;};
    const bool& telemetry7() const {return m_telemetry7;};
    const bool& telemetry8() const {return m_telemetry8;};
    const bool& telemetry9() const {return m_telemetry9;};
    const bool& telemetry10() const {return m_telemetry10;};
    const bool& telemetry11() const {return m_telemetry11;};
    const bool& telemetry12() const {return m_telemetry12;};
    const bool& telemetry13() const {return m_telemetry13;};
    const bool& telemetry14() const {return m_telemetry14;};
    const bool& telemetry15() const {return m_telemetry15;};
    const bool& telemetry16() const {return m_telemetry16;};
    const bool& telemetry17() const {return m_telemetry17;};
    const bool& telemetry18() const {return m_telemetry18;};
    const bool& telemetry19() const {return m_telemetry19;};
    const bool& telemetry20() const {return m_telemetry20;};
    const bool& telemetry21() const {return m_telemetry21;};
    const bool& telemetry22() const {return m_telemetry22;};
    const bool& telemetry23() const {return m_telemetry23;};
    const bool& telemetry24() const {return m_telemetry24;};
    const bool& telemetry25() const {return m_telemetry25;};
    const bool& telemetry26() const {return m_telemetry26;};
    const bool& telemetry27() const {return m_telemetry27;};
    const bool& telemetry28() const {return m_telemetry28;};
    const bool& telemetry29() const {return m_telemetry29;};
    const bool& telemetry30() const {return m_telemetry30;};
    const bool& telemetry31() const {return m_telemetry31;};

    const int& telemetryMsgCounter() const {return m_telemetryMsgCounter;};

    /* MOTOR */


    const qint32& MotorARealPosition() const {return m_MotorARealPosition;};
    const qint32& MotorADemandPosition() const {return m_MotorADemandPosition;};
    const qint32& MotorATorque() const {return m_MotorATorque;};
    const qint16& MotorATemp() const {return m_MotorATemp;};

    const qint32& MotorBRealPosition() const {return m_MotorBRealPosition;};
    const qint32& MotorBDemandPosition() const {return m_MotorBDemandPosition;};
    const qint32& MotorBTorque() const {return m_MotorBTorque;};
    const qint16& MotorBTemp() const {return m_MotorBTemp;};

    const quint16& BMSVoltage() const {return m_BMSVoltage;};
    const qint16& BMSAbsorption() const {return m_BMSAbsorption;};
    const qint16& BMSTemp() const {return m_BMSTemp;};

    const quint32& MotorAFaultsMask() const {return m_MotorAFaultsMask;};
    const quint32& MotorBFaultsMask() const {return m_MotorBFaultsMask;};
    const quint32& BMSFaultsMask() const {return m_BMSFaultsMask;};

    const quint8& ChargeValue() const {return m_ChargeValue;};

    const bool& motor0() const {return m_motor0;};
    const bool& motor1() const {return m_motor1;};
    const bool& motor2() const {return m_motor2;};
    const bool& motor3() const {return m_motor3;};
    const bool& motor4() const {return m_motor4;};
    const bool& motor5() const {return m_motor5;};
    const bool& motor6() const {return m_motor6;};
    const bool& motor7() const {return m_motor7;};
    const bool& motor8() const {return m_motor8;};
    const bool& motor10() const {return m_motor10;};
    const bool& motor11() const {return m_motor11;};
    const bool& motor12() const {return m_motor12;};
    const bool& motor13() const {return m_motor13;};
    const bool& motor14() const {return m_motor14;};
    const bool& motor15() const {return m_motor15;};
    const bool& motor16() const {return m_motor16;};
    const bool& motor17() const {return m_motor17;};
    const bool& motor18() const {return m_motor18;};
    const bool& motor19() const {return m_motor19;};
    const bool& motor20() const {return m_motor20;};
    const bool& motor21() const {return m_motor21;};
    const bool& motor22() const {return m_motor22;};
    const bool& motor23() const {return m_motor23;};
    const bool& motor24() const {return m_motor24;};

    const bool& motorAMask0() const {return m_motorAMask0;};
    const bool& motorAMask1() const {return m_motorAMask1;};
    const bool& motorAMask2() const {return m_motorAMask2;};
    const bool& motorAMask3() const {return m_motorAMask3;};
    const bool& motorAMask4() const {return m_motorAMask4;};
    const bool& motorAMask5() const {return m_motorAMask5;};
    const bool& motorAMask6() const {return m_motorAMask6;};
    const bool& motorAMask7() const {return m_motorAMask7;};
    const bool& motorAMask8() const {return m_motorAMask8;};
    const bool& motorAMask9() const {return m_motorAMask9;};
    const bool& motorAMask10() const {return m_motorAMask10;};
    const bool& motorAMask11() const {return m_motorAMask11;};
    const bool& motorAMask12() const {return m_motorAMask12;};
    const bool& motorAMask13() const {return m_motorAMask13;};
    const bool& motorAMask14() const {return m_motorAMask14;};
    const bool& motorAMask15() const {return m_motorAMask15;};
    const bool& motorAMask16() const {return m_motorAMask16;};
    const bool& motorAMask17() const {return m_motorAMask17;};
    const bool& motorAMask18() const {return m_motorAMask18;};
    const bool& motorAMask19() const {return m_motorAMask19;};
    const bool& motorAMask20() const {return m_motorAMask20;};
    const bool& motorAMask21() const {return m_motorAMask21;};
    const bool& motorAMask22() const {return m_motorAMask22;};
    const bool& motorAMask23() const {return m_motorAMask23;};
    const bool& motorAMask24() const {return m_motorAMask24;};
    const bool& motorAMask25() const {return m_motorAMask25;};
    const bool& motorAMask26() const {return m_motorAMask26;};
    const bool& motorAMask27() const {return m_motorAMask27;};
    const bool& motorAMask28() const {return m_motorAMask28;};
    const bool& motorAMask29() const {return m_motorAMask29;};
    const bool& motorAMask30() const {return m_motorAMask30;};
    const bool& motorAMask31() const {return m_motorAMask31;};

    const bool& motorBMask0() const {return m_motorBMask0;};
    const bool& motorBMask1() const {return m_motorBMask1;};
    const bool& motorBMask2() const {return m_motorBMask2;};
    const bool& motorBMask3() const {return m_motorBMask3;};
    const bool& motorBMask4() const {return m_motorBMask4;};
    const bool& motorBMask5() const {return m_motorBMask5;};
    const bool& motorBMask6() const {return m_motorBMask6;};
    const bool& motorBMask7() const {return m_motorBMask7;};
    const bool& motorBMask8() const {return m_motorBMask8;};
    const bool& motorBMask9() const {return m_motorBMask9;};
    const bool& motorBMask10() const {return m_motorBMask10;};
    const bool& motorBMask11() const {return m_motorBMask11;};
    const bool& motorBMask12() const {return m_motorBMask12;};
    const bool& motorBMask13() const {return m_motorBMask13;};
    const bool& motorBMask14() const {return m_motorBMask14;};
    const bool& motorBMask15() const {return m_motorBMask15;};
    const bool& motorBMask16() const {return m_motorBMask16;};
    const bool& motorBMask17() const {return m_motorBMask17;};
    const bool& motorBMask18() const {return m_motorBMask18;};
    const bool& motorBMask19() const {return m_motorBMask19;};
    const bool& motorBMask20() const {return m_motorBMask20;};
    const bool& motorBMask21() const {return m_motorBMask21;};
    const bool& motorBMask22() const {return m_motorBMask22;};
    const bool& motorBMask23() const {return m_motorBMask23;};
    const bool& motorBMask24() const {return m_motorBMask24;};
    const bool& motorBMask25() const {return m_motorBMask25;};
    const bool& motorBMask26() const {return m_motorBMask26;};
    const bool& motorBMask27() const {return m_motorBMask27;};
    const bool& motorBMask28() const {return m_motorBMask28;};
    const bool& motorBMask29() const {return m_motorBMask29;};
    const bool& motorBMask30() const {return m_motorBMask30;};
    const bool& motorBMask31() const {return m_motorBMask31;};

    const bool& BMS0() const {return m_BMS0;};
    const bool& BMS1() const {return m_BMS1;};
    const bool& BMS2() const {return m_BMS2;};
    const bool& BMS3() const {return m_BMS3;};
    const bool& BMS4() const {return m_BMS4;};
    const bool& BMS5() const {return m_BMS5;};
    const bool& BMS6() const {return m_BMS6;};
    const bool& BMS7() const {return m_BMS7;};
    const bool& BMS8() const {return m_BMS8;};
    const bool& BMS9() const {return m_BMS9;};
    const bool& BMS10() const {return m_BMS10;};
    const bool& BMS11() const {return m_BMS11;};
    const bool& BMS12() const {return m_BMS12;};
    const bool& BMS13() const {return m_BMS13;};
    const bool& BMS14() const {return m_BMS14;};
    const bool& BMS15() const {return m_BMS15;};
    const bool& BMS16() const {return m_BMS16;};
    const bool& BMS17() const {return m_BMS17;};
    const bool& BMS18() const {return m_BMS18;};
    const bool& BMS19() const {return m_BMS19;};
    const bool& BMS20() const {return m_BMS20;};
    const bool& BMS21() const {return m_BMS21;};
    const bool& BMS22() const {return m_BMS22;};
    const bool& BMS23() const {return m_BMS23;};
    const bool& BMS24() const {return m_BMS24;};
    const bool& BMS25() const {return m_BMS25;};
    const bool& BMS26() const {return m_BMS26;};
    const bool& BMS27() const {return m_BMS27;};
    const bool& BMS28() const {return m_BMS28;};
    const bool& BMS29() const {return m_BMS29;};
    const bool& BMS30() const {return m_BMS30;};
    const bool& BMS31() const {return m_BMS31;};

    const int& motorMsgCounter() const {return m_motorMsgCounter;};

    /* SYSTEM */

    const quint8& FlightMode() const {return m_FlightMode;};
    const quint8& FlightPhase() const {return m_FlightPhase;};
    const quint32& FlightPhaseExecutionTime() const {return m_FlightPhaseExecutionTime;};
    const quint32& CoreModuleStatusMask() const {return m_CoreModuleStatusMask;};
    const quint64& TelemetryModuleStatusMask() const {return m_TelemetryModuleStatusMask;};
    const quint32& GuidanceModuleStatusMask() const {return m_GuidanceModuleStatusMask;};
    const quint32& StorageModuleStatusMask() const {return m_StorageModuleStatusMask;};
    const quint32& RadioLinkModuleStatusMask() const {return m_RadioLinkModuleStatusMask;};
    const quint32& MotorControlStatusMask() const {return m_MotorControlStatusMask;};

    const quint8& communicationErrorCounter() const {return m_communicationErrorCounter;};
    const bool& systemCoreMask0() const {return m_systemCoreMask0;};
    const bool& systemCoreMask1() const {return m_systemCoreMask1;};
    const bool& systemCoreMask2() const {return m_systemCoreMask2;};
    const bool& systemCoreMask3() const {return m_systemCoreMask3;};
    const bool& systemCoreMask4() const {return m_systemCoreMask4;};
    const bool& systemCoreMask5() const {return m_systemCoreMask5;};
    const bool& systemCoreMask6() const {return m_systemCoreMask6;};
    const bool& systemCoreMask7() const {return m_systemCoreMask7;};
    const bool& systemCoreMask8() const {return m_systemCoreMask8;};
    const bool& systemCoreMask9() const {return m_systemCoreMask9;};
    const bool& systemCoreMask10() const {return m_systemCoreMask10;};
    const bool& systemCoreMask11() const {return m_systemCoreMask11;};
    const bool& systemCoreMask12() const {return m_systemCoreMask12;};
    const bool& systemCoreMask13() const {return m_systemCoreMask13;};
    const bool& systemCoreMask14() const {return m_systemCoreMask14;};
    const bool& systemCoreMask15() const {return m_systemCoreMask15;};
    const bool& systemCoreMask16() const {return m_systemCoreMask16;};
    const bool& systemCoreMask17() const {return m_systemCoreMask17;};
    const bool& systemCoreMask18() const {return m_systemCoreMask18;};
    const bool& systemCoreMask19() const {return m_systemCoreMask19;};
    const bool& systemCoreMask20() const {return m_systemCoreMask20;};
    const bool& systemCoreMask21() const {return m_systemCoreMask21;};
    const bool& systemCoreMask22() const {return m_systemCoreMask22;};
    const bool& systemCoreMask23() const {return m_systemCoreMask23;};
    const bool& systemCoreMask24() const {return m_systemCoreMask24;};
    const bool& systemCoreMask25() const {return m_systemCoreMask25;};
    const bool& systemCoreMask26() const {return m_systemCoreMask26;};
    const bool& systemCoreMask27() const {return m_systemCoreMask27;};
    const bool& systemCoreMask28() const {return m_systemCoreMask28;};
    const bool& systemCoreMask29() const {return m_systemCoreMask29;};
    const bool& systemCoreMask30() const {return m_systemCoreMask30;};
    const bool& systemCoreMask31() const {return m_systemCoreMask31;};

    const bool& systemStorageMask0() const {return m_systemStorageMask0;};
    const bool& systemStorageMask1() const {return m_systemStorageMask1;};
    const bool& systemStorageMask2() const {return m_systemStorageMask2;};
    const bool& systemStorageMask3() const {return m_systemStorageMask3;};
    const bool& systemStorageMask4() const {return m_systemStorageMask4;};
    const bool& systemStorageMask5() const {return m_systemStorageMask5;};
    const bool& systemStorageMask6() const {return m_systemStorageMask6;};
    const bool& systemStorageMask7() const {return m_systemStorageMask7;};
    const bool& systemStorageMask8() const {return m_systemStorageMask8;};
    const bool& systemStorageMask9() const {return m_systemStorageMask9;};
    const bool& systemStorageMask10() const {return m_systemStorageMask10;};
    const bool& systemStorageMask11() const {return m_systemStorageMask11;};
    const bool& systemStorageMask12() const {return m_systemStorageMask12;};
    const bool& systemStorageMask13() const {return m_systemStorageMask13;};
    const bool& systemStorageMask14() const {return m_systemStorageMask14;};
    const bool& systemStorageMask15() const {return m_systemStorageMask15;};
    const bool& systemStorageMask16() const {return m_systemStorageMask16;};
    const bool& systemStorageMask17() const {return m_systemStorageMask17;};
    const bool& systemStorageMask18() const {return m_systemStorageMask18;};
    const bool& systemStorageMask19() const {return m_systemStorageMask19;};
    const bool& systemStorageMask20() const {return m_systemStorageMask20;};
    const bool& systemStorageMask21() const {return m_systemStorageMask21;};
    const bool& systemStorageMask22() const {return m_systemStorageMask22;};
    const bool& systemStorageMask23() const {return m_systemStorageMask23;};
    const bool& systemStorageMask24() const {return m_systemStorageMask24;};
    const bool& systemStorageMask25() const {return m_systemStorageMask25;};
    const bool& systemStorageMask26() const {return m_systemStorageMask26;};
    const bool& systemStorageMask27() const {return m_systemStorageMask27;};
    const bool& systemStorageMask28() const {return m_systemStorageMask28;};
    const bool& systemStorageMask29() const {return m_systemStorageMask29;};
    const bool& systemStorageMask30() const {return m_systemStorageMask30;};
    const bool& systemStorageMask31() const {return m_systemStorageMask31;};

    const bool& systemGuidanceMask0() const {return m_systemGuidanceMask0;};
    const bool& systemGuidanceMask1() const {return m_systemGuidanceMask1;};
    const bool& systemGuidanceMask2() const {return m_systemGuidanceMask2;};
    const bool& systemGuidanceMask3() const {return m_systemGuidanceMask3;};
    const bool& systemGuidanceMask4() const {return m_systemGuidanceMask4;};
    const bool& systemGuidanceMask5() const {return m_systemGuidanceMask5;};
    const bool& systemGuidanceMask6() const {return m_systemGuidanceMask6;};
    const bool& systemGuidanceMask7() const {return m_systemGuidanceMask7;};
    const bool& systemGuidanceMask8() const {return m_systemGuidanceMask8;};
    const bool& systemGuidanceMask9() const {return m_systemGuidanceMask9;};
    const bool& systemGuidanceMask10() const {return m_systemGuidanceMask10;};
    const bool& systemGuidanceMask11() const {return m_systemGuidanceMask11;};
    const bool& systemGuidanceMask12() const {return m_systemGuidanceMask12;};
    const bool& systemGuidanceMask13() const {return m_systemGuidanceMask13;};
    const bool& systemGuidanceMask14() const {return m_systemGuidanceMask14;};
    const bool& systemGuidanceMask15() const {return m_systemGuidanceMask15;};
    const bool& systemGuidanceMask16() const {return m_systemGuidanceMask16;};
    const bool& systemGuidanceMask17() const {return m_systemGuidanceMask17;};
    const bool& systemGuidanceMask18() const {return m_systemGuidanceMask18;};
    const bool& systemGuidanceMask19() const {return m_systemGuidanceMask19;};
    const bool& systemGuidanceMask20() const {return m_systemGuidanceMask20;};
    const bool& systemGuidanceMask21() const {return m_systemGuidanceMask21;};
    const bool& systemGuidanceMask22() const {return m_systemGuidanceMask22;};
    const bool& systemGuidanceMask23() const {return m_systemGuidanceMask23;};
    const bool& systemGuidanceMask24() const {return m_systemGuidanceMask24;};
    const bool& systemGuidanceMask25() const {return m_systemGuidanceMask25;};
    const bool& systemGuidanceMask26() const {return m_systemGuidanceMask26;};
    const bool& systemGuidanceMask27() const {return m_systemGuidanceMask27;};
    const bool& systemGuidanceMask28() const {return m_systemGuidanceMask28;};
    const bool& systemGuidanceMask29() const {return m_systemGuidanceMask29;};
    const bool& systemGuidanceMask30() const {return m_systemGuidanceMask30;};
    const bool& systemGuidanceMask31() const {return m_systemGuidanceMask31;};

    const bool& systemMotorControlMask0() const {return m_systemMotorControlMask0;};
    const bool& systemMotorControlMask1() const {return m_systemMotorControlMask1;};
    const bool& systemMotorControlMask2() const {return m_systemMotorControlMask2;};
    const bool& systemMotorControlMask3() const {return m_systemMotorControlMask3;};
    const bool& systemMotorControlMask4() const {return m_systemMotorControlMask4;};
    const bool& systemMotorControlMask5() const {return m_systemMotorControlMask5;};
    const bool& systemMotorControlMask6() const {return m_systemMotorControlMask6;};
    const bool& systemMotorControlMask7() const {return m_systemMotorControlMask7;};
    const bool& systemMotorControlMask8() const {return m_systemMotorControlMask8;};
    const bool& systemMotorControlMask9() const {return m_systemMotorControlMask9;};
    const bool& systemMotorControlMask10() const {return m_systemMotorControlMask10;};
    const bool& systemMotorControlMask11() const {return m_systemMotorControlMask11;};
    const bool& systemMotorControlMask12() const {return m_systemMotorControlMask12;};
    const bool& systemMotorControlMask13() const {return m_systemMotorControlMask13;};
    const bool& systemMotorControlMask14() const {return m_systemMotorControlMask14;};
    const bool& systemMotorControlMask15() const {return m_systemMotorControlMask15;};
    const bool& systemMotorControlMask16() const {return m_systemMotorControlMask16;};
    const bool& systemMotorControlMask17() const {return m_systemMotorControlMask17;};
    const bool& systemMotorControlMask18() const {return m_systemMotorControlMask18;};
    const bool& systemMotorControlMask19() const {return m_systemMotorControlMask19;};
    const bool& systemMotorControlMask20() const {return m_systemMotorControlMask20;};
    const bool& systemMotorControlMask21() const {return m_systemMotorControlMask21;};
    const bool& systemMotorControlMask22() const {return m_systemMotorControlMask22;};
    const bool& systemMotorControlMask23() const {return m_systemMotorControlMask23;};
    const bool& systemMotorControlMask24() const {return m_systemMotorControlMask24;};
    const bool& systemMotorControlMask25() const {return m_systemMotorControlMask25;};
    const bool& systemMotorControlMask26() const {return m_systemMotorControlMask26;};
    const bool& systemMotorControlMask27() const {return m_systemMotorControlMask27;};
    const bool& systemMotorControlMask28() const {return m_systemMotorControlMask28;};
    const bool& systemMotorControlMask29() const {return m_systemMotorControlMask29;};
    const bool& systemMotorControlMask30() const {return m_systemMotorControlMask30;};
    const bool& systemMotorControlMask31() const {return m_systemMotorControlMask31;};


    const bool& systemTelemetryMask0() const {return m_systemTelemetryMask0;};
    const bool& systemTelemetryMask1() const {return m_systemTelemetryMask1;};
    const bool& systemTelemetryMask2() const {return m_systemTelemetryMask2;};
    const bool& systemTelemetryMask3() const {return m_systemTelemetryMask3;};
    const bool& systemTelemetryMask4() const {return m_systemTelemetryMask4;};
    const bool& systemTelemetryMask5() const {return m_systemTelemetryMask5;};
    const bool& systemTelemetryMask6() const {return m_systemTelemetryMask6;};
    const bool& systemTelemetryMask7() const {return m_systemTelemetryMask7;};
    const bool& systemTelemetryMask8() const {return m_systemTelemetryMask8;};
    const bool& systemTelemetryMask9() const {return m_systemTelemetryMask9;};
    const bool& systemTelemetryMask10() const {return m_systemTelemetryMask10;};
    const bool& systemTelemetryMask11() const {return m_systemTelemetryMask11;};
    const bool& systemTelemetryMask12() const {return m_systemTelemetryMask12;};
    const bool& systemTelemetryMask13() const {return m_systemTelemetryMask13;};
    const bool& systemTelemetryMask14() const {return m_systemTelemetryMask14;};
    const bool& systemTelemetryMask15() const {return m_systemTelemetryMask15;};
    const bool& systemTelemetryMask16() const {return m_systemTelemetryMask16;};
    const bool& systemTelemetryMask17() const {return m_systemTelemetryMask17;};
    const bool& systemTelemetryMask18() const {return m_systemTelemetryMask18;};
    const bool& systemTelemetryMask19() const {return m_systemTelemetryMask19;};
    const bool& systemTelemetryMask20() const {return m_systemTelemetryMask20;};
    const bool& systemTelemetryMask21() const {return m_systemTelemetryMask21;};
    const bool& systemTelemetryMask22() const {return m_systemTelemetryMask22;};
    const bool& systemTelemetryMask23() const {return m_systemTelemetryMask23;};
    const bool& systemTelemetryMask24() const {return m_systemTelemetryMask24;};
    const bool& systemTelemetryMask25() const {return m_systemTelemetryMask25;};
    const bool& systemTelemetryMask26() const {return m_systemTelemetryMask26;};
    const bool& systemTelemetryMask27() const {return m_systemTelemetryMask27;};
    const bool& systemTelemetryMask28() const {return m_systemTelemetryMask28;};
    const bool& systemTelemetryMask29() const {return m_systemTelemetryMask29;};
    const bool& systemTelemetryMask30() const {return m_systemTelemetryMask30;};
    const bool& systemTelemetryMask31() const {return m_systemTelemetryMask31;};
    const bool& systemTelemetryMask32() const {return m_systemTelemetryMask32;};
    const bool& systemTelemetryMask33() const {return m_systemTelemetryMask33;};
    const bool& systemTelemetryMask34() const {return m_systemTelemetryMask34;};
    const bool& systemTelemetryMask35() const {return m_systemTelemetryMask35;};
    const bool& systemTelemetryMask36() const {return m_systemTelemetryMask36;};
    const bool& systemTelemetryMask37() const {return m_systemTelemetryMask37;};
    const bool& systemTelemetryMask38() const {return m_systemTelemetryMask38;};
    const bool& systemTelemetryMask39() const {return m_systemTelemetryMask39;};
    const bool& systemTelemetryMask40() const {return m_systemTelemetryMask40;};
    const bool& systemTelemetryMask41() const {return m_systemTelemetryMask41;};
    const bool& systemTelemetryMask42() const {return m_systemTelemetryMask42;};
    const bool& systemTelemetryMask43() const {return m_systemTelemetryMask43;};
    const bool& systemTelemetryMask44() const {return m_systemTelemetryMask44;};
    const bool& systemTelemetryMask45() const {return m_systemTelemetryMask45;};
    const bool& systemTelemetryMask46() const {return m_systemTelemetryMask46;};
    const bool& systemTelemetryMask47() const {return m_systemTelemetryMask47;};
    const bool& systemTelemetryMask48() const {return m_systemTelemetryMask48;};
    const bool& systemTelemetryMask49() const {return m_systemTelemetryMask49;};
    const bool& systemTelemetryMask50() const {return m_systemTelemetryMask50;};
    const bool& systemTelemetryMask51() const {return m_systemTelemetryMask51;};
    const bool& systemTelemetryMask52() const {return m_systemTelemetryMask52;};
    const bool& systemTelemetryMask53() const {return m_systemTelemetryMask53;};
    const bool& systemTelemetryMask54() const {return m_systemTelemetryMask54;};
    const bool& systemTelemetryMask55() const {return m_systemTelemetryMask55;};
    const bool& systemTelemetryMask56() const {return m_systemTelemetryMask56;};
    const bool& systemTelemetryMask57() const {return m_systemTelemetryMask57;};
    const bool& systemTelemetryMask58() const {return m_systemTelemetryMask58;};
    const bool& systemTelemetryMask59() const {return m_systemTelemetryMask59;};
    const bool& systemTelemetryMask60() const {return m_systemTelemetryMask60;};
    const bool& systemTelemetryMask61() const {return m_systemTelemetryMask61;};
    const bool& systemTelemetryMask62() const {return m_systemTelemetryMask62;};
    const bool& systemTelemetryMask63() const {return m_systemTelemetryMask63;};

    const bool& emergencyBoardStatus0() const {return m_emergencyBoardStatus0;};
    const bool& emergencyBoardStatus1() const {return m_emergencyBoardStatus1;};
    const bool& emergencyBoardStatus2() const {return m_emergencyBoardStatus2;};
    const bool& emergencyBoardStatus3() const {return m_emergencyBoardStatus3;};
    const bool& emergencyBoardStatus4() const {return m_emergencyBoardStatus4;};
    const bool& emergencyBoardStatus5() const {return m_emergencyBoardStatus5;};
    const bool& emergencyBoardStatus6() const {return m_emergencyBoardStatus6;};
    const bool& emergencyBoardStatus7() const {return m_emergencyBoardStatus7;};
    const bool& emergencyBoardStatus8() const {return m_emergencyBoardStatus8;};
    const bool& emergencyBoardStatus9() const {return m_emergencyBoardStatus9;};
    const bool& emergencyBoardStatus10() const {return m_emergencyBoardStatus10;};
    const bool& emergencyBoardStatus11() const {return m_emergencyBoardStatus11;};
    const bool& emergencyBoardStatus12() const {return m_emergencyBoardStatus12;};
    const bool& emergencyBoardStatus13() const {return m_emergencyBoardStatus13;};
    const bool& emergencyBoardStatus14() const {return m_emergencyBoardStatus14;};
    const bool& emergencyBoardStatus15() const {return m_emergencyBoardStatus15;};

    const bool& PSUStatus0() const {return m_PSUStatus0;};
    const bool& PSUStatus1() const {return m_PSUStatus1;};
    const bool& PSUStatus2() const {return m_PSUStatus2;};
    const bool& PSUStatus3() const {return m_PSUStatus3;};
    const bool& PSUStatus4() const {return m_PSUStatus4;};
    const bool& PSUStatus5() const {return m_PSUStatus5;};
    const bool& PSUStatus6() const {return m_PSUStatus6;};
    const bool& PSUStatus7() const {return m_PSUStatus7;};
    const bool& PSUStatus8() const {return m_PSUStatus8;};
    const bool& PSUStatus9() const {return m_PSUStatus9;};
    const bool& PSUStatus10() const {return m_PSUStatus10;};
    const bool& PSUStatus11() const {return m_PSUStatus11;};
    const bool& PSUStatus12() const {return m_PSUStatus12;};
    const bool& PSUStatus13() const {return m_PSUStatus13;};
    const bool& PSUStatus14() const {return m_PSUStatus14;};
    const bool& PSUStatus15() const {return m_PSUStatus15;};

    const bool& emergencyRadioLinkStatus0() const {return m_emergencyRadioLinkStatus0;};
    const bool& emergencyRadioLinkStatus1() const {return m_emergencyRadioLinkStatus1;};
    const bool& emergencyRadioLinkStatus2() const {return m_emergencyRadioLinkStatus2;};
    const bool& emergencyRadioLinkStatus3() const {return m_emergencyRadioLinkStatus3;};
    const bool& emergencyRadioLinkStatus4() const {return m_emergencyRadioLinkStatus4;};
    const bool& emergencyRadioLinkStatus5() const {return m_emergencyRadioLinkStatus5;};
    const bool& emergencyRadioLinkStatus6() const {return m_emergencyRadioLinkStatus6;};
    const bool& emergencyRadioLinkStatus7() const {return m_emergencyRadioLinkStatus7;};

    const int& systemMsgCounter() const {return m_systemMsgCounter;};


    /* RADIOLINK */

    const quint16& RSSI() const {return m_RSSI;};
    const quint8& radiolinkErrorCounter() const {return m_radiolinkErrorCounter;};
    const bool& radiolinkMask0() const {return m_radiolinkMask0;};
    const bool& radiolinkMask1() const {return m_radiolinkMask1;};
    const bool& radiolinkMask2() const {return m_radiolinkMask2;};
    const bool& radiolinkMask3() const {return m_radiolinkMask3;};
    const bool& radiolinkMask4() const {return m_radiolinkMask4;};
    const bool& radiolinkMask5() const {return m_radiolinkMask5;};
    const bool& radiolinkMask6() const {return m_radiolinkMask6;};
    const bool& radiolinkMask7() const {return m_radiolinkMask7;};
    const bool& radiolinkMask8() const {return m_radiolinkMask8;};
    const bool& radiolinkMask9() const {return m_radiolinkMask9;};
    const bool& radiolinkMask10() const {return m_radiolinkMask10;};
    const bool& radiolinkMask11() const {return m_radiolinkMask11;};
    const bool& radiolinkMask12() const {return m_radiolinkMask12;};
    const bool& radiolinkMask13() const {return m_radiolinkMask13;};
    const bool& radiolinkMask14() const {return m_radiolinkMask14;};
    const bool& radiolinkMask15() const {return m_radiolinkMask15;};
    const bool& radiolinkMask16() const {return m_radiolinkMask16;};
    const bool& radiolinkMask17() const {return m_radiolinkMask17;};
    const bool& radiolinkMask18() const {return m_radiolinkMask18;};
    const bool& radiolinkMask19() const {return m_radiolinkMask19;};
    const bool& radiolinkMask20() const {return m_radiolinkMask20;};
    const bool& radiolinkMask21() const {return m_radiolinkMask21;};
    const bool& radiolinkMask22() const {return m_radiolinkMask22;};
    const bool& radiolinkMask23() const {return m_radiolinkMask23;};
    const bool& radiolinkMask24() const {return m_radiolinkMask24;};
    const bool& radiolinkMask25() const {return m_radiolinkMask25;};
    const bool& radiolinkMask26() const {return m_radiolinkMask26;};
    const bool& radiolinkMask27() const {return m_radiolinkMask27;};
    const bool& radiolinkMask28() const {return m_radiolinkMask28;};
    const bool& radiolinkMask29() const {return m_radiolinkMask29;};
    const bool& radiolinkMask30() const {return m_radiolinkMask30;};
    const bool& radiolinkMask31() const {return m_radiolinkMask31;};

    const int& radiolinkMsgCounter() const {return m_radiolinkMsgCounter;};


    /* GUIDANCE */

    const bool& guidanceMask0() const {return m_guidanceMask0;};
    const bool& guidanceMask1() const {return m_guidanceMask1;};
    const bool& guidanceMask2() const {return m_guidanceMask2;};
    const bool& guidanceMask3() const {return m_guidanceMask3;};
    const bool& guidanceMask4() const {return m_guidanceMask4;};
    const bool& guidanceMask5() const {return m_guidanceMask5;};
    const bool& guidanceMask6() const {return m_guidanceMask6;};
    const bool& guidanceMask7() const {return m_guidanceMask7;};
    const bool& guidanceMask8() const {return m_guidanceMask8;};
    const bool& guidanceMask9() const {return m_guidanceMask9;};
    const bool& guidanceMask10() const {return m_guidanceMask10;};
    const bool& guidanceMask11() const {return m_guidanceMask11;};
    const bool& guidanceMask12() const {return m_guidanceMask12;};
    const bool& guidanceMask13() const {return m_guidanceMask13;};
    const bool& guidanceMask14() const {return m_guidanceMask14;};
    const bool& guidanceMask15() const {return m_guidanceMask15;};
    const bool& guidanceMask16() const {return m_guidanceMask16;};
    const bool& guidanceMask17() const {return m_guidanceMask17;};
    const bool& guidanceMask18() const {return m_guidanceMask18;};
    const bool& guidanceMask19() const {return m_guidanceMask19;};
    const bool& guidanceMask20() const {return m_guidanceMask20;};
    const bool& guidanceMask21() const {return m_guidanceMask21;};
    const bool& guidanceMask22() const {return m_guidanceMask22;};
    const bool& guidanceMask23() const {return m_guidanceMask23;};
    const bool& guidanceMask24() const {return m_guidanceMask24;};
    const bool& guidanceMask25() const {return m_guidanceMask25;};
    const bool& guidanceMask26() const {return m_guidanceMask26;};
    const bool& guidanceMask27() const {return m_guidanceMask27;};
    const bool& guidanceMask28() const {return m_guidanceMask28;};
    const bool& guidanceMask29() const {return m_guidanceMask29;};
    const bool& guidanceMask30() const {return m_guidanceMask30;};
    const bool& guidanceMask31() const {return m_guidanceMask31;};

    const int& guidanceMsgCounter() const {return m_guidanceMsgCounter;};

    /* STORAGE */

    const quint32& storageFreeDataSize() const {return m_storageFreeDataSize;};
    const bool& storage0() const {return m_storage0;};
    const bool& storage1() const {return m_storage1;};
    const bool& storage2() const {return m_storage2;};
    const bool& storage3() const {return m_storage3;};
    const bool& storage4() const {return m_storage4;};
    const bool& storage5() const {return m_storage5;};
    const bool& storage6() const {return m_storage6;};
    const bool& storage7() const {return m_storage7;};
    const bool& storage8() const {return m_storage8;};
    const bool& storage9() const {return m_storage9;};
    const bool& storage10() const {return m_storage10;};
    const bool& storage11() const {return m_storage11;};
    const bool& storage12() const {return m_storage12;};
    const bool& storage13() const {return m_storage13;};
    const bool& storage14() const {return m_storage14;};
    const bool& storage15() const {return m_storage15;};
    const bool& storage16() const {return m_storage16;};
    const bool& storage17() const {return m_storage17;};
    const bool& storage18() const {return m_storage18;};
    const bool& storage19() const {return m_storage19;};
    const bool& storage20() const {return m_storage20;};
    const bool& storage21() const {return m_storage21;};
    const bool& storage22() const {return m_storage22;};
    const bool& storage23() const {return m_storage23;};
    const bool& storage24() const {return m_storage24;};
    const bool& storage25() const {return m_storage25;};
    const bool& storage26() const {return m_storage26;};
    const bool& storage27() const {return m_storage27;};
    const bool& storage28() const {return m_storage28;};
    const bool& storage29() const {return m_storage29;};
    const bool& storage30() const {return m_storage30;};
    const bool& storage31() const {return m_storage31;};

    const int& storageMsgCounter() const {return m_storageMsgCounter;};

    const bool& msgTelemetryOld() const {return m_msgTelemetryOld;};
    const bool& msgGuidanceOld() const {return m_msgGuidanceOld;};
    const bool& msgStorageOld() const {return m_msgStorageOld;};
    const bool& msgSystemOld() const {return m_msgSystemOld;};
    const bool& msgRadioLinkOld() const {return m_msgRadioLinkOld;};
    const bool& msgMotorOld() const {return m_msgMotorOld;};


    /* DESC */
    const QString& LatitudeDesc() const {return m_LatitudeDesc;};
    const QString& LongitudeDesc() const {return m_LongitudeDesc;};
    const QString& GNSSAltitudeDesc() const {return m_GNSSAltitudeDesc;};

    const QString& TimeStampDesc() const {return m_TimeStampDesc;};
    const QString& TimeStampRIODesc() const {return m_TimeStampRIODesc;};

    const QString& AirSpeed_UVectorDesc() const {return m_AirSpeed_UVectorDesc;};
    const QString& AirSpeed_VVectorDesc() const {return m_AirSpeed_VVectorDesc;};
    const QString& AirSpeed_WVectorDesc() const {return m_AirSpeed_WVectorDesc;};
    const QString& AirTemperatureDesc() const {return m_AirTemperatureDesc;};
    const QString& AltitudeFromRadarAltimeterDesc() const {return m_AltitudeFromRadarAltimeterDesc;};
    const QString& AltitudeFromPayloadAltimeterDesc() const {return m_AltitudeFromPayloadAltimeterDesc;};
    const QString& LinearVelocityHorizontalDesc() const {return m_LinearVelocityHorizontalDesc;};
    const QString& LinearVelocityVerticalDesc() const {return m_LinearVelocityVerticalDesc;};
    const QString& PositionAccuracyDesc() const {return m_PositionAccuracyDesc;};
    const QString& SpeedAccuracyDesc() const {return m_SpeedAccuracyDesc;};
    const QString& LinearAccelerationXDesc() const {return m_LinearAccelerationXDesc;};
    const QString& LinearAccelerationYDesc() const {return m_LinearAccelerationYDesc;};
    const QString& LinearAccelerationZDesc() const {return m_LinearAccelerationZDesc;};
    const QString& ECEFVectorPositionXDesc() const {return m_ECEFVectorPositionXDesc;};
    const QString& ECEFVectorPositionYDesc() const {return m_ECEFVectorPositionYDesc;};
    const QString& ECEFVectorPositionZDesc() const {return m_ECEFVectorPositionZDesc;};
    const QString& ECEFVectorVelocityXDesc() const {return m_ECEFVectorVelocityXDesc;};
    const QString& ECEFVectorVelocityYDesc() const {return m_ECEFVectorVelocityYDesc;};
    const QString& ECEFVectorVelocityZDesc() const {return m_ECEFVectorVelocityZDesc;};
    const QString& RollAngleDesc() const {return m_RollAngleDesc;};
    const QString& PitchAngleDesc() const {return m_PitchAngleDesc;};
    const QString& YawAngleDesc() const {return m_YawAngleDesc;};
    const QString& AngularRateRollDesc() const {return m_AngularRateRollDesc;};
    const QString& AngularRatePitchDesc() const {return m_AngularRatePitchDesc;};
    const QString& AngularRateYawDesc() const {return m_AngularRateYawDesc;};
    const QString& Quaternion0Desc() const {return m_Quaternion0Desc;};
    const QString& Quaternion1Desc() const {return m_Quaternion1Desc;};
    const QString& Quaternion2Desc() const {return m_Quaternion2Desc;};
    const QString& Quaternion3Desc() const {return m_Quaternion3Desc;};
    const QString& NumberOfGPSSatelliteDesc() const {return m_NumberOfGPSSatelliteDesc;};
    const QString& AnemCommErrorCounterDesc() const {return m_AnemCommErrorCounterDesc;};
    const QString& RDAltCommErrorCounterDesc() const {return m_RDAltCommErrorCounterDesc;};
    const QString& GNSSCommErrorCounterDesc() const {return m_GNSSCommErrorCounterDesc;};
    const QString& PLAltCommErrorCounterDesc() const {return m_PLAltCommErrorCounterDesc;};

    const QString& MotorARealPositionDesc() const {return m_MotorARealPositionDesc;};
    const QString& MotorADemandPositionDesc() const {return m_MotorADemandPositionDesc;};
    const QString& MotorATorqueDesc() const {return m_MotorATorqueDesc;};
    const QString& MotorATempDesc() const {return m_MotorATempDesc;};

    const QString& MotorBRealPositionDesc() const {return m_MotorBRealPositionDesc;};
    const QString& MotorBDemandPositionDesc() const {return m_MotorBDemandPositionDesc;};
    const QString& MotorBTorqueDesc() const {return m_MotorBTorqueDesc;};
    const QString& MotorBTempDesc() const {return m_MotorBTempDesc;};

    const QString& BMSVoltageDesc() const {return m_BMSVoltageDesc;};
    const QString& BMSAbsorptionDesc() const {return m_BMSAbsorptionDesc;};
    const QString& BMSTempDesc() const {return m_BMSTempDesc;};

    const QString& MotorAFaultsMaskDesc() const {return m_MotorAFaultsMaskDesc;};
    const QString& MotorBFaultsMaskDesc() const {return m_MotorBFaultsMaskDesc;};
    const QString& BMSFaultsMaskDesc() const {return m_BMSFaultsMaskDesc;};

    const QString& ChargeValueDesc() const {return m_ChargeValueDesc;};

    const QString& FlightModeDesc() const {return m_FlightModeDesc;};
    const QString& FlightPhaseDesc() const {return m_FlightPhaseDesc;};
    const QString& FlightPhaseExecutionTimeDesc() const {return m_FlightPhaseExecutionTimeDesc;};

    const QString& communicationErrorCounterDesc() const {return m_communicationErrorCounterDesc;};

    const QString& RSSIDesc() const {return m_RSSIDesc;};

    const QString& storageFreeDataSizeDesc() const {return m_storageFreeDataSizeDesc;};


    /* TBD */
    const quint8& GSRLErrorCounter() const {return m_GSRLErrorCounter;};
    const quint8& FSRLErrorCounter() const {return m_FSRLErrorCounter;};
    const quint8& RLHeartbeatCounter() const {return m_RLHeartbeatCounter;};
    const bool& gnssFound() const {return m_gnssFound;};



public slots:


    void setLongitude(const qint32& Longitude) {m_Longitude=Longitude;emit LongitudeChanged();};
    void setGNSSAltitude(const quint32& GNSSAltitude) {m_GNSSAltitude=GNSSAltitude;emit GNSSAltitudeChanged();};
    void setAirSpeed_UVector(const qint16& AirSpeed_UVector) {m_AirSpeed_UVector=AirSpeed_UVector;emit AirSpeed_UVectorChanged();};
    void setAirSpeed_VVector(const qint16& AirSpeed_VVector) {m_AirSpeed_VVector=AirSpeed_VVector;emit AirSpeed_VVectorChanged();};
    void setAirSpeed_WVector(const qint16& AirSpeed_WVector) {m_AirSpeed_WVector=AirSpeed_WVector;emit AirSpeed_WVectorChanged();};
    void setAirTemperature(const qint16& AirTemperature) {m_AirTemperature=AirTemperature;emit AirTemperatureChanged();};
    void setAltitudeFromRadarAltimeter(const qint32& AltitudeFromRadarAltimeter) {m_AltitudeFromRadarAltimeter=AltitudeFromRadarAltimeter;emit AltitudeFromRadarAltimeterChanged();};
    void setAltitudeFromPayloadAltimeter(const qint32& AltitudeFromPayloadAltimeter) {m_AltitudeFromPayloadAltimeter=AltitudeFromPayloadAltimeter;emit AltitudeFromPayloadAltimeterChanged();};
    void setLinearVelocityHorizontal(const quint16& LinearVelocityHorizontal) {m_LinearVelocityHorizontal=LinearVelocityHorizontal;emit LinearVelocityHorizontalChanged();};
    void setLinearVelocityVertical(const qint16& LinearVelocityVertical) {m_LinearVelocityVertical=LinearVelocityVertical;emit LinearVelocityVerticalChanged();};
    void setPositionAccuracy(const quint16& PositionAccuracy) {m_PositionAccuracy=PositionAccuracy;emit PositionAccuracyChanged();};
    void setSpeedAccuracy(const quint16& SpeedAccuracy) {m_SpeedAccuracy=SpeedAccuracy;emit SpeedAccuracyChanged();};
    void setLinearAccelerationX(const qint16& LinearAccelerationX) {m_LinearAccelerationX=LinearAccelerationX;emit LinearAccelerationXChanged();};
    void setLinearAccelerationY(const qint16& LinearAccelerationY) {m_LinearAccelerationY=LinearAccelerationY;emit LinearAccelerationYChanged();};
    void setLinearAccelerationZ(const qint16& LinearAccelerationZ) {m_LinearAccelerationZ=LinearAccelerationZ;emit LinearAccelerationZChanged();};
    void setECEFVectorPositionX(const float& ECEFVectorPositionX) {m_ECEFVectorPositionX=ECEFVectorPositionX;emit ECEFVectorPositionXChanged();};
    void setECEFVectorPositionY(const float& ECEFVectorPositionY) {m_ECEFVectorPositionY=ECEFVectorPositionY;emit ECEFVectorPositionYChanged();};
    void setECEFVectorPositionZ(const float& ECEFVectorPositionZ) {m_ECEFVectorPositionZ=ECEFVectorPositionZ;emit ECEFVectorPositionZChanged();};
    void setECEFVectorVelocityX(const float& ECEFVectorVelocityX) {m_ECEFVectorVelocityX=ECEFVectorVelocityX;emit ECEFVectorVelocityXChanged();};
    void setECEFVectorVelocityY(const float& ECEFVectorVelocityY) {m_ECEFVectorVelocityY=ECEFVectorVelocityY;emit ECEFVectorVelocityYChanged();};
    void setECEFVectorVelocityZ(const float& ECEFVectorVelocityZ) {m_ECEFVectorVelocityZ=ECEFVectorVelocityZ;emit ECEFVectorVelocityZChanged();};
    void setRollAngle(const qint16& RollAngle) {m_RollAngle=RollAngle;emit RollAngleChanged();};
    void setPitchAngle(const qint16& PitchAngle) {m_PitchAngle=PitchAngle;emit PitchAngleChanged();};
    void setYawAngle(const qint16& YawAngle) {m_YawAngle=YawAngle;emit YawAngleChanged();};
    void setAngularRateRoll(const qint16& AngularRateRoll) {m_AngularRateRoll=AngularRateRoll;emit AngularRateRollChanged();};
    void setAngularRatePitch(const qint16& AngularRatePitch) {m_AngularRatePitch=AngularRatePitch;emit AngularRatePitchChanged();};
    void setAngularRateYaw(const qint16& AngularRateYaw) {m_AngularRateYaw=AngularRateYaw;emit AngularRateYawChanged();};
    void setQuaternion0(const double& Quaternion0) {m_Quaternion0=Quaternion0;emit Quaternion0Changed();};
    void setQuaternion1(const double& Quaternion1) {m_Quaternion1=Quaternion1;emit Quaternion1Changed();};
    void setQuaternion2(const double& Quaternion2) {m_Quaternion2=Quaternion2;emit Quaternion2Changed();};
    void setQuaternion3(const double& Quaternion3) {m_Quaternion3=Quaternion3;emit Quaternion3Changed();};
    void setNumberOfGPSSatellite(const quint8& NumberOfGPSSatellite) {m_NumberOfGPSSatellite=NumberOfGPSSatellite;emit NumberOfGPSSatelliteChanged();};
    void setAnemCommErrorCounter(const quint8& AnemCommErrorCounter) {m_AnemCommErrorCounter=AnemCommErrorCounter;emit AnemCommErrorCounterChanged();};
    void setRDAltCommErrorCounter(const quint8& RDAltCommErrorCounter) {m_RDAltCommErrorCounter=RDAltCommErrorCounter;emit RDAltCommErrorCounterChanged();};
    void setGNSSCommErrorCounter(const quint8& GNSSCommErrorCounter) {m_GNSSCommErrorCounter=GNSSCommErrorCounter;emit GNSSCommErrorCounterChanged();};
    void setPLAltCommErrorCounter(const quint8& PLAltCommErrorCounter) {m_PLAltCommErrorCounter=PLAltCommErrorCounter;emit PLAltCommErrorCounterChanged();};
    void settelemetry0(const bool& telemetry0) {m_telemetry0=telemetry0;emit telemetry0Changed();};
    void settelemetry1(const bool& telemetry1) {m_telemetry1=telemetry1;emit telemetry1Changed();};
    void settelemetry2(const bool& telemetry2) {m_telemetry2=telemetry2;emit telemetry2Changed();};
    void settelemetry3(const bool& telemetry3) {m_telemetry3=telemetry3;emit telemetry3Changed();};
    void settelemetry4(const bool& telemetry4) {m_telemetry4=telemetry4;emit telemetry4Changed();};
    void settelemetry5(const bool& telemetry5) {m_telemetry5=telemetry5;emit telemetry5Changed();};
    void settelemetry6(const bool& telemetry6) {m_telemetry6=telemetry6;emit telemetry6Changed();};
    void settelemetry7(const bool& telemetry7) {m_telemetry7=telemetry7;emit telemetry7Changed();};
    void settelemetry8(const bool& telemetry8) {m_telemetry8=telemetry8;emit telemetry8Changed();};
    void settelemetry9(const bool& telemetry9) {m_telemetry9=telemetry9;emit telemetry9Changed();};
    void settelemetry10(const bool& telemetry10) {m_telemetry10=telemetry10;emit telemetry10Changed();};
    void settelemetry11(const bool& telemetry11) {m_telemetry11=telemetry11;emit telemetry11Changed();};
    void settelemetry12(const bool& telemetry12) {m_telemetry12=telemetry12;emit telemetry12Changed();};
    void settelemetry13(const bool& telemetry13) {m_telemetry13=telemetry13;emit telemetry13Changed();};
    void settelemetry14(const bool& telemetry14) {m_telemetry14=telemetry14;emit telemetry14Changed();};
    void settelemetry15(const bool& telemetry15) {m_telemetry15=telemetry15;emit telemetry15Changed();};
    void settelemetry16(const bool& telemetry16) {m_telemetry16=telemetry16;emit telemetry16Changed();};
    void settelemetry17(const bool& telemetry17) {m_telemetry17=telemetry17;emit telemetry17Changed();};
    void settelemetry18(const bool& telemetry18) {m_telemetry18=telemetry18;emit telemetry18Changed();};
    void settelemetry19(const bool& telemetry19) {m_telemetry19=telemetry19;emit telemetry19Changed();};
    void settelemetry20(const bool& telemetry20) {m_telemetry20=telemetry20;emit telemetry20Changed();};
    void settelemetry21(const bool& telemetry21) {m_telemetry21=telemetry21;emit telemetry21Changed();};
    void settelemetry22(const bool& telemetry22) {m_telemetry22=telemetry22;emit telemetry22Changed();};
    void settelemetry23(const bool& telemetry23) {m_telemetry23=telemetry23;emit telemetry23Changed();};
    void settelemetry24(const bool& telemetry24) {m_telemetry24=telemetry24;emit telemetry24Changed();};
    void settelemetry25(const bool& telemetry25) {m_telemetry25=telemetry25;emit telemetry25Changed();};
    void settelemetry26(const bool& telemetry26) {m_telemetry26=telemetry26;emit telemetry26Changed();};
    void settelemetry27(const bool& telemetry27) {m_telemetry27=telemetry27;emit telemetry27Changed();};
    void settelemetry28(const bool& telemetry28) {m_telemetry28=telemetry28;emit telemetry28Changed();};
    void settelemetry29(const bool& telemetry29) {m_telemetry29=telemetry29;emit telemetry29Changed();};
    void settelemetry30(const bool& telemetry30) {m_telemetry30=telemetry30;emit telemetry30Changed();};
    void settelemetry31(const bool& telemetry31) {m_telemetry31=telemetry31;emit telemetry31Changed();};

    void settelemetryMsgCounter(const int& telemetryMsgCounter) {m_telemetryMsgCounter=telemetryMsgCounter;emit telemetryMsgCounterChanged();};

    /* MOTOR */


    void setMotorARealPosition(const qint32& MotorARealPosition) {m_MotorARealPosition=MotorARealPosition;emit MotorARealPositionChanged();};
    void setMotorADemandPosition(const qint32& MotorADemandPosition) {m_MotorADemandPosition=MotorADemandPosition;emit MotorADemandPositionChanged();};
    void setMotorATorque(const qint32& MotorATorque) {m_MotorATorque=MotorATorque;emit MotorATorqueChanged();};
    void setMotorATemp(const qint16& MotorATemp) {m_MotorATemp=MotorATemp;emit MotorATempChanged();};

    void setMotorBRealPosition(const qint32& MotorBRealPosition) {m_MotorBRealPosition=MotorBRealPosition;emit MotorBRealPositionChanged();};
    void setMotorBDemandPosition(const qint32& MotorBDemandPosition) {m_MotorBDemandPosition=MotorBDemandPosition;emit MotorBDemandPositionChanged();};
    void setMotorBTorque(const qint32& MotorBTorque) {m_MotorBTorque=MotorBTorque;emit MotorBTorqueChanged();};
    void setMotorBTemp(const qint16& MotorBTemp) {m_MotorBTemp=MotorBTemp;emit MotorBTempChanged();};

    void setBMSVoltage(const quint16& BMSVoltage) {m_BMSVoltage=BMSVoltage;emit BMSVoltageChanged();};
    void setBMSAbsorption(const qint16& BMSAbsorption) {m_BMSAbsorption=BMSAbsorption;emit BMSAbsorptionChanged();};
    void setBMSTemp(const qint16& BMSTemp) {m_BMSTemp=BMSTemp;emit BMSTempChanged();};

    void setMotorAFaultsMask(const quint32& MotorAFaultsMask) {m_MotorAFaultsMask=MotorAFaultsMask;emit MotorAFaultsMaskChanged();};
    void setMotorBFaultsMask(const quint32& MotorBFaultsMask) {m_MotorBFaultsMask=MotorBFaultsMask;emit MotorBFaultsMaskChanged();};
    void setBMSFaultsMask(const quint32& BMSFaultsMask) {m_BMSFaultsMask=BMSFaultsMask;emit BMSFaultsMaskChanged();};

    void setChargeValue(const quint8& ChargeValue) {m_ChargeValue=ChargeValue;emit ChargeValueChanged();};

    void setmotor0(const bool& motor0) {m_motor0=motor0;emit motor0Changed();};
    void setmotor1(const bool& motor1) {m_motor1=motor1;emit motor1Changed();};
    void setmotor2(const bool& motor2) {m_motor2=motor2;emit motor2Changed();};
    void setmotor3(const bool& motor3) {m_motor3=motor3;emit motor3Changed();};
    void setmotor4(const bool& motor4) {m_motor4=motor4;emit motor4Changed();};
    void setmotor5(const bool& motor5) {m_motor5=motor5;emit motor5Changed();};
    void setmotor6(const bool& motor6) {m_motor6=motor6;emit motor6Changed();};
    void setmotor7(const bool& motor7) {m_motor7=motor7;emit motor7Changed();};
    void setmotor8(const bool& motor8) {m_motor8=motor8;emit motor8Changed();};
    void setmotor10(const bool& motor10) {m_motor10=motor10;emit motor10Changed();};
    void setmotor11(const bool& motor11) {m_motor11=motor11;emit motor11Changed();};
    void setmotor12(const bool& motor12) {m_motor12=motor12;emit motor12Changed();};
    void setmotor13(const bool& motor13) {m_motor13=motor13;emit motor13Changed();};
    void setmotor14(const bool& motor14) {m_motor14=motor14;emit motor14Changed();};
    void setmotor15(const bool& motor15) {m_motor15=motor15;emit motor15Changed();};
    void setmotor16(const bool& motor16) {m_motor16=motor16;emit motor16Changed();};
    void setmotor17(const bool& motor17) {m_motor17=motor17;emit motor17Changed();};
    void setmotor18(const bool& motor18) {m_motor18=motor18;emit motor18Changed();};
    void setmotor19(const bool& motor19) {m_motor19=motor19;emit motor19Changed();};
    void setmotor20(const bool& motor20) {m_motor20=motor20;emit motor20Changed();};
    void setmotor21(const bool& motor21) {m_motor21=motor21;emit motor21Changed();};
    void setmotor22(const bool& motor22) {m_motor22=motor22;emit motor22Changed();};
    void setmotor23(const bool& motor23) {m_motor23=motor23;emit motor23Changed();};
    void setmotor24(const bool& motor24) {m_motor24=motor24;emit motor24Changed();};

    void setmotorAMask0(const bool& motorAMask0) {m_motorAMask0=motorAMask0;emit motorAMask0Changed();};
    void setmotorAMask1(const bool& motorAMask1) {m_motorAMask1=motorAMask1;emit motorAMask1Changed();};
    void setmotorAMask2(const bool& motorAMask2) {m_motorAMask2=motorAMask2;emit motorAMask2Changed();};
    void setmotorAMask3(const bool& motorAMask3) {m_motorAMask3=motorAMask3;emit motorAMask3Changed();};
    void setmotorAMask4(const bool& motorAMask4) {m_motorAMask4=motorAMask4;emit motorAMask4Changed();};
    void setmotorAMask5(const bool& motorAMask5) {m_motorAMask5=motorAMask5;emit motorAMask5Changed();};
    void setmotorAMask6(const bool& motorAMask6) {m_motorAMask6=motorAMask6;emit motorAMask6Changed();};
    void setmotorAMask7(const bool& motorAMask7) {m_motorAMask7=motorAMask7;emit motorAMask7Changed();};
    void setmotorAMask8(const bool& motorAMask8) {m_motorAMask8=motorAMask8;emit motorAMask8Changed();};
    void setmotorAMask9(const bool& motorAMask9) {m_motorAMask9=motorAMask9;emit motorAMask9Changed();};
    void setmotorAMask10(const bool& motorAMask10) {m_motorAMask10=motorAMask10;emit motorAMask10Changed();};
    void setmotorAMask11(const bool& motorAMask11) {m_motorAMask11=motorAMask11;emit motorAMask11Changed();};
    void setmotorAMask12(const bool& motorAMask12) {m_motorAMask12=motorAMask12;emit motorAMask12Changed();};
    void setmotorAMask13(const bool& motorAMask13) {m_motorAMask13=motorAMask13;emit motorAMask13Changed();};
    void setmotorAMask14(const bool& motorAMask14) {m_motorAMask14=motorAMask14;emit motorAMask14Changed();};
    void setmotorAMask15(const bool& motorAMask15) {m_motorAMask15=motorAMask15;emit motorAMask15Changed();};
    void setmotorAMask16(const bool& motorAMask16) {m_motorAMask16=motorAMask16;emit motorAMask16Changed();};
    void setmotorAMask17(const bool& motorAMask17) {m_motorAMask17=motorAMask17;emit motorAMask17Changed();};
    void setmotorAMask18(const bool& motorAMask18) {m_motorAMask18=motorAMask18;emit motorAMask18Changed();};
    void setmotorAMask19(const bool& motorAMask19) {m_motorAMask19=motorAMask19;emit motorAMask19Changed();};
    void setmotorAMask20(const bool& motorAMask20) {m_motorAMask20=motorAMask20;emit motorAMask20Changed();};
    void setmotorAMask21(const bool& motorAMask21) {m_motorAMask21=motorAMask21;emit motorAMask21Changed();};
    void setmotorAMask22(const bool& motorAMask22) {m_motorAMask22=motorAMask22;emit motorAMask22Changed();};
    void setmotorAMask23(const bool& motorAMask23) {m_motorAMask23=motorAMask23;emit motorAMask23Changed();};
    void setmotorAMask24(const bool& motorAMask24) {m_motorAMask24=motorAMask24;emit motorAMask24Changed();};
    void setmotorAMask25(const bool& motorAMask25) {m_motorAMask25=motorAMask25;emit motorAMask25Changed();};
    void setmotorAMask26(const bool& motorAMask26) {m_motorAMask26=motorAMask26;emit motorAMask26Changed();};
    void setmotorAMask27(const bool& motorAMask27) {m_motorAMask27=motorAMask27;emit motorAMask27Changed();};
    void setmotorAMask28(const bool& motorAMask28) {m_motorAMask28=motorAMask28;emit motorAMask28Changed();};
    void setmotorAMask29(const bool& motorAMask29) {m_motorAMask29=motorAMask29;emit motorAMask29Changed();};
    void setmotorAMask30(const bool& motorAMask30) {m_motorAMask30=motorAMask30;emit motorAMask30Changed();};
    void setmotorAMask31(const bool& motorAMask31) {m_motorAMask31=motorAMask31;emit motorAMask31Changed();};

    void setmotorBMask0(const bool& motorBMask0) {m_motorBMask0=motorBMask0;emit motorBMask0Changed();};
    void setmotorBMask1(const bool& motorBMask1) {m_motorBMask1=motorBMask1;emit motorBMask1Changed();};
    void setmotorBMask2(const bool& motorBMask2) {m_motorBMask2=motorBMask2;emit motorBMask2Changed();};
    void setmotorBMask3(const bool& motorBMask3) {m_motorBMask3=motorBMask3;emit motorBMask3Changed();};
    void setmotorBMask4(const bool& motorBMask4) {m_motorBMask4=motorBMask4;emit motorBMask4Changed();};
    void setmotorBMask5(const bool& motorBMask5) {m_motorBMask5=motorBMask5;emit motorBMask5Changed();};
    void setmotorBMask6(const bool& motorBMask6) {m_motorBMask6=motorBMask6;emit motorBMask6Changed();};
    void setmotorBMask7(const bool& motorBMask7) {m_motorBMask7=motorBMask7;emit motorBMask7Changed();};
    void setmotorBMask8(const bool& motorBMask8) {m_motorBMask8=motorBMask8;emit motorBMask8Changed();};
    void setmotorBMask9(const bool& motorBMask9) {m_motorBMask9=motorBMask9;emit motorBMask9Changed();};
    void setmotorBMask10(const bool& motorBMask10) {m_motorBMask10=motorBMask10;emit motorBMask10Changed();};
    void setmotorBMask11(const bool& motorBMask11) {m_motorBMask11=motorBMask11;emit motorBMask11Changed();};
    void setmotorBMask12(const bool& motorBMask12) {m_motorBMask12=motorBMask12;emit motorBMask12Changed();};
    void setmotorBMask13(const bool& motorBMask13) {m_motorBMask13=motorBMask13;emit motorBMask13Changed();};
    void setmotorBMask14(const bool& motorBMask14) {m_motorBMask14=motorBMask14;emit motorBMask14Changed();};
    void setmotorBMask15(const bool& motorBMask15) {m_motorBMask15=motorBMask15;emit motorBMask15Changed();};
    void setmotorBMask16(const bool& motorBMask16) {m_motorBMask16=motorBMask16;emit motorBMask16Changed();};
    void setmotorBMask17(const bool& motorBMask17) {m_motorBMask17=motorBMask17;emit motorBMask17Changed();};
    void setmotorBMask18(const bool& motorBMask18) {m_motorBMask18=motorBMask18;emit motorBMask18Changed();};
    void setmotorBMask19(const bool& motorBMask19) {m_motorBMask19=motorBMask19;emit motorBMask19Changed();};
    void setmotorBMask20(const bool& motorBMask20) {m_motorBMask20=motorBMask20;emit motorBMask20Changed();};
    void setmotorBMask21(const bool& motorBMask21) {m_motorBMask21=motorBMask21;emit motorBMask21Changed();};
    void setmotorBMask22(const bool& motorBMask22) {m_motorBMask22=motorBMask22;emit motorBMask22Changed();};
    void setmotorBMask23(const bool& motorBMask23) {m_motorBMask23=motorBMask23;emit motorBMask23Changed();};
    void setmotorBMask24(const bool& motorBMask24) {m_motorBMask24=motorBMask24;emit motorBMask24Changed();};
    void setmotorBMask25(const bool& motorBMask25) {m_motorBMask25=motorBMask25;emit motorBMask25Changed();};
    void setmotorBMask26(const bool& motorBMask26) {m_motorBMask26=motorBMask26;emit motorBMask26Changed();};
    void setmotorBMask27(const bool& motorBMask27) {m_motorBMask27=motorBMask27;emit motorBMask27Changed();};
    void setmotorBMask28(const bool& motorBMask28) {m_motorBMask28=motorBMask28;emit motorBMask28Changed();};
    void setmotorBMask29(const bool& motorBMask29) {m_motorBMask29=motorBMask29;emit motorBMask29Changed();};
    void setmotorBMask30(const bool& motorBMask30) {m_motorBMask30=motorBMask30;emit motorBMask30Changed();};
    void setmotorBMask31(const bool& motorBMask31) {m_motorBMask31=motorBMask31;emit motorBMask31Changed();};

    void setBMS0(const bool& BMS0) {m_BMS0=BMS0;emit BMS0Changed();};
    void setBMS1(const bool& BMS1) {m_BMS1=BMS1;emit BMS1Changed();};
    void setBMS2(const bool& BMS2) {m_BMS2=BMS2;emit BMS2Changed();};
    void setBMS3(const bool& BMS3) {m_BMS3=BMS3;emit BMS3Changed();};
    void setBMS4(const bool& BMS4) {m_BMS4=BMS4;emit BMS4Changed();};
    void setBMS5(const bool& BMS5) {m_BMS5=BMS5;emit BMS5Changed();};
    void setBMS6(const bool& BMS6) {m_BMS6=BMS6;emit BMS6Changed();};
    void setBMS7(const bool& BMS7) {m_BMS7=BMS7;emit BMS7Changed();};
    void setBMS8(const bool& BMS8) {m_BMS8=BMS8;emit BMS8Changed();};
    void setBMS9(const bool& BMS9) {m_BMS9=BMS9;emit BMS9Changed();};
    void setBMS10(const bool& BMS10) {m_BMS10=BMS10;emit BMS10Changed();};
    void setBMS11(const bool& BMS11) {m_BMS11=BMS11;emit BMS11Changed();};
    void setBMS12(const bool& BMS12) {m_BMS12=BMS12;emit BMS12Changed();};
    void setBMS13(const bool& BMS13) {m_BMS13=BMS13;emit BMS13Changed();};
    void setBMS14(const bool& BMS14) {m_BMS14=BMS14;emit BMS14Changed();};
    void setBMS15(const bool& BMS15) {m_BMS15=BMS15;emit BMS15Changed();};
    void setBMS16(const bool& BMS16) {m_BMS16=BMS16;emit BMS16Changed();};
    void setBMS17(const bool& BMS17) {m_BMS17=BMS17;emit BMS17Changed();};
    void setBMS18(const bool& BMS18) {m_BMS18=BMS18;emit BMS18Changed();};
    void setBMS19(const bool& BMS19) {m_BMS19=BMS19;emit BMS19Changed();};
    void setBMS20(const bool& BMS20) {m_BMS20=BMS20;emit BMS20Changed();};
    void setBMS21(const bool& BMS21) {m_BMS21=BMS21;emit BMS21Changed();};
    void setBMS22(const bool& BMS22) {m_BMS22=BMS22;emit BMS22Changed();};
    void setBMS23(const bool& BMS23) {m_BMS23=BMS23;emit BMS23Changed();};
    void setBMS24(const bool& BMS24) {m_BMS24=BMS24;emit BMS24Changed();};
    void setBMS25(const bool& BMS25) {m_BMS25=BMS25;emit BMS25Changed();};
    void setBMS26(const bool& BMS26) {m_BMS26=BMS26;emit BMS26Changed();};
    void setBMS27(const bool& BMS27) {m_BMS27=BMS27;emit BMS27Changed();};
    void setBMS28(const bool& BMS28) {m_BMS28=BMS28;emit BMS28Changed();};
    void setBMS29(const bool& BMS29) {m_BMS29=BMS29;emit BMS29Changed();};
    void setBMS30(const bool& BMS30) {m_BMS30=BMS30;emit BMS30Changed();};
    void setBMS31(const bool& BMS31) {m_BMS31=BMS31;emit BMS31Changed();};

    void setmotorMsgCounter(const int& motorMsgCounter) {m_motorMsgCounter=motorMsgCounter;emit motorMsgCounterChanged();};

    /* SYSTEM */

    void setFlightMode(const quint8& FlightMode) {m_FlightMode=FlightMode;emit FlightModeChanged();};
    void setFlightPhase(const quint8& FlightPhase) {m_FlightPhase=FlightPhase;emit FlightPhaseChanged();};
    void setFlightPhaseExecutionTime(const quint32& FlightPhaseExecutionTime) {m_FlightPhaseExecutionTime=FlightPhaseExecutionTime;emit FlightPhaseExecutionTimeChanged();};
    void setCoreModuleStatusMask(const quint32& CoreModuleStatusMask) {m_CoreModuleStatusMask=CoreModuleStatusMask;emit CoreModuleStatusMaskChanged();};
    void setTelemetryModuleStatusMask(const quint64& TelemetryModuleStatusMask) {m_TelemetryModuleStatusMask=TelemetryModuleStatusMask;emit TelemetryModuleStatusMaskChanged();};
    void setGuidanceModuleStatusMask(const quint32& GuidanceModuleStatusMask) {m_GuidanceModuleStatusMask=GuidanceModuleStatusMask;emit GuidanceModuleStatusMaskChanged();};
    void setStorageModuleStatusMask(const quint32& StorageModuleStatusMask) {m_StorageModuleStatusMask=StorageModuleStatusMask;emit StorageModuleStatusMaskChanged();};
    void setRadioLinkModuleStatusMask(const quint32& RadioLinkModuleStatusMask) {m_RadioLinkModuleStatusMask=RadioLinkModuleStatusMask;emit RadioLinkModuleStatusMaskChanged();};
    void setMotorControlStatusMask(const quint32& MotorControlStatusMask) {m_MotorControlStatusMask=MotorControlStatusMask;emit MotorControlStatusMaskChanged();};

    void setcommunicationErrorCounter(const quint8& communicationErrorCounter) {m_communicationErrorCounter=communicationErrorCounter;emit communicationErrorCounterChanged();};
    void setsystemCoreMask0(const bool& systemCoreMask0) {m_systemCoreMask0=systemCoreMask0;emit systemCoreMask0Changed();};
    void setsystemCoreMask1(const bool& systemCoreMask1) {m_systemCoreMask1=systemCoreMask1;emit systemCoreMask1Changed();};
    void setsystemCoreMask2(const bool& systemCoreMask2) {m_systemCoreMask2=systemCoreMask2;emit systemCoreMask2Changed();};
    void setsystemCoreMask3(const bool& systemCoreMask3) {m_systemCoreMask3=systemCoreMask3;emit systemCoreMask3Changed();};
    void setsystemCoreMask4(const bool& systemCoreMask4) {m_systemCoreMask4=systemCoreMask4;emit systemCoreMask4Changed();};
    void setsystemCoreMask5(const bool& systemCoreMask5) {m_systemCoreMask5=systemCoreMask5;emit systemCoreMask5Changed();};
    void setsystemCoreMask6(const bool& systemCoreMask6) {m_systemCoreMask6=systemCoreMask6;emit systemCoreMask6Changed();};
    void setsystemCoreMask7(const bool& systemCoreMask7) {m_systemCoreMask7=systemCoreMask7;emit systemCoreMask7Changed();};
    void setsystemCoreMask8(const bool& systemCoreMask8) {m_systemCoreMask8=systemCoreMask8;emit systemCoreMask8Changed();};
    void setsystemCoreMask9(const bool& systemCoreMask9) {m_systemCoreMask9=systemCoreMask9;emit systemCoreMask9Changed();};
    void setsystemCoreMask10(const bool& systemCoreMask10) {m_systemCoreMask10=systemCoreMask10;emit systemCoreMask10Changed();};
    void setsystemCoreMask11(const bool& systemCoreMask11) {m_systemCoreMask11=systemCoreMask11;emit systemCoreMask11Changed();};
    void setsystemCoreMask12(const bool& systemCoreMask12) {m_systemCoreMask12=systemCoreMask12;emit systemCoreMask12Changed();};
    void setsystemCoreMask13(const bool& systemCoreMask13) {m_systemCoreMask13=systemCoreMask13;emit systemCoreMask13Changed();};
    void setsystemCoreMask14(const bool& systemCoreMask14) {m_systemCoreMask14=systemCoreMask14;emit systemCoreMask14Changed();};
    void setsystemCoreMask15(const bool& systemCoreMask15) {m_systemCoreMask15=systemCoreMask15;emit systemCoreMask15Changed();};
    void setsystemCoreMask16(const bool& systemCoreMask16) {m_systemCoreMask16=systemCoreMask16;emit systemCoreMask16Changed();};
    void setsystemCoreMask17(const bool& systemCoreMask17) {m_systemCoreMask17=systemCoreMask17;emit systemCoreMask17Changed();};
    void setsystemCoreMask18(const bool& systemCoreMask18) {m_systemCoreMask18=systemCoreMask18;emit systemCoreMask18Changed();};
    void setsystemCoreMask19(const bool& systemCoreMask19) {m_systemCoreMask19=systemCoreMask19;emit systemCoreMask19Changed();};
    void setsystemCoreMask20(const bool& systemCoreMask20) {m_systemCoreMask20=systemCoreMask20;emit systemCoreMask20Changed();};
    void setsystemCoreMask21(const bool& systemCoreMask21) {m_systemCoreMask21=systemCoreMask21;emit systemCoreMask21Changed();};
    void setsystemCoreMask22(const bool& systemCoreMask22) {m_systemCoreMask22=systemCoreMask22;emit systemCoreMask22Changed();};
    void setsystemCoreMask23(const bool& systemCoreMask23) {m_systemCoreMask23=systemCoreMask23;emit systemCoreMask23Changed();};
    void setsystemCoreMask24(const bool& systemCoreMask24) {m_systemCoreMask24=systemCoreMask24;emit systemCoreMask24Changed();};
    void setsystemCoreMask25(const bool& systemCoreMask25) {m_systemCoreMask25=systemCoreMask25;emit systemCoreMask25Changed();};
    void setsystemCoreMask26(const bool& systemCoreMask26) {m_systemCoreMask26=systemCoreMask26;emit systemCoreMask26Changed();};
    void setsystemCoreMask27(const bool& systemCoreMask27) {m_systemCoreMask27=systemCoreMask27;emit systemCoreMask27Changed();};
    void setsystemCoreMask28(const bool& systemCoreMask28) {m_systemCoreMask28=systemCoreMask28;emit systemCoreMask28Changed();};
    void setsystemCoreMask29(const bool& systemCoreMask29) {m_systemCoreMask29=systemCoreMask29;emit systemCoreMask29Changed();};
    void setsystemCoreMask30(const bool& systemCoreMask30) {m_systemCoreMask30=systemCoreMask30;emit systemCoreMask30Changed();};
    void setsystemCoreMask31(const bool& systemCoreMask31) {m_systemCoreMask31=systemCoreMask31;emit systemCoreMask31Changed();};

    void setsystemStorageMask0(const bool& systemStorageMask0) {m_systemStorageMask0=systemStorageMask0;emit systemStorageMask0Changed();};
    void setsystemStorageMask1(const bool& systemStorageMask1) {m_systemStorageMask1=systemStorageMask1;emit systemStorageMask1Changed();};
    void setsystemStorageMask2(const bool& systemStorageMask2) {m_systemStorageMask2=systemStorageMask2;emit systemStorageMask2Changed();};
    void setsystemStorageMask3(const bool& systemStorageMask3) {m_systemStorageMask3=systemStorageMask3;emit systemStorageMask3Changed();};
    void setsystemStorageMask4(const bool& systemStorageMask4) {m_systemStorageMask4=systemStorageMask4;emit systemStorageMask4Changed();};
    void setsystemStorageMask5(const bool& systemStorageMask5) {m_systemStorageMask5=systemStorageMask5;emit systemStorageMask5Changed();};
    void setsystemStorageMask6(const bool& systemStorageMask6) {m_systemStorageMask6=systemStorageMask6;emit systemStorageMask6Changed();};
    void setsystemStorageMask7(const bool& systemStorageMask7) {m_systemStorageMask7=systemStorageMask7;emit systemStorageMask7Changed();};
    void setsystemStorageMask8(const bool& systemStorageMask8) {m_systemStorageMask8=systemStorageMask8;emit systemStorageMask8Changed();};
    void setsystemStorageMask9(const bool& systemStorageMask9) {m_systemStorageMask9=systemStorageMask9;emit systemStorageMask9Changed();};
    void setsystemStorageMask10(const bool& systemStorageMask10) {m_systemStorageMask10=systemStorageMask10;emit systemStorageMask10Changed();};
    void setsystemStorageMask11(const bool& systemStorageMask11) {m_systemStorageMask11=systemStorageMask11;emit systemStorageMask11Changed();};
    void setsystemStorageMask12(const bool& systemStorageMask12) {m_systemStorageMask12=systemStorageMask12;emit systemStorageMask12Changed();};
    void setsystemStorageMask13(const bool& systemStorageMask13) {m_systemStorageMask13=systemStorageMask13;emit systemStorageMask13Changed();};
    void setsystemStorageMask14(const bool& systemStorageMask14) {m_systemStorageMask14=systemStorageMask14;emit systemStorageMask14Changed();};
    void setsystemStorageMask15(const bool& systemStorageMask15) {m_systemStorageMask15=systemStorageMask15;emit systemStorageMask15Changed();};
    void setsystemStorageMask16(const bool& systemStorageMask16) {m_systemStorageMask16=systemStorageMask16;emit systemStorageMask16Changed();};
    void setsystemStorageMask17(const bool& systemStorageMask17) {m_systemStorageMask17=systemStorageMask17;emit systemStorageMask17Changed();};
    void setsystemStorageMask18(const bool& systemStorageMask18) {m_systemStorageMask18=systemStorageMask18;emit systemStorageMask18Changed();};
    void setsystemStorageMask19(const bool& systemStorageMask19) {m_systemStorageMask19=systemStorageMask19;emit systemStorageMask19Changed();};
    void setsystemStorageMask20(const bool& systemStorageMask20) {m_systemStorageMask20=systemStorageMask20;emit systemStorageMask20Changed();};
    void setsystemStorageMask21(const bool& systemStorageMask21) {m_systemStorageMask21=systemStorageMask21;emit systemStorageMask21Changed();};
    void setsystemStorageMask22(const bool& systemStorageMask22) {m_systemStorageMask22=systemStorageMask22;emit systemStorageMask22Changed();};
    void setsystemStorageMask23(const bool& systemStorageMask23) {m_systemStorageMask23=systemStorageMask23;emit systemStorageMask23Changed();};
    void setsystemStorageMask24(const bool& systemStorageMask24) {m_systemStorageMask24=systemStorageMask24;emit systemStorageMask24Changed();};
    void setsystemStorageMask25(const bool& systemStorageMask25) {m_systemStorageMask25=systemStorageMask25;emit systemStorageMask25Changed();};
    void setsystemStorageMask26(const bool& systemStorageMask26) {m_systemStorageMask26=systemStorageMask26;emit systemStorageMask26Changed();};
    void setsystemStorageMask27(const bool& systemStorageMask27) {m_systemStorageMask27=systemStorageMask27;emit systemStorageMask27Changed();};
    void setsystemStorageMask28(const bool& systemStorageMask28) {m_systemStorageMask28=systemStorageMask28;emit systemStorageMask28Changed();};
    void setsystemStorageMask29(const bool& systemStorageMask29) {m_systemStorageMask29=systemStorageMask29;emit systemStorageMask29Changed();};
    void setsystemStorageMask30(const bool& systemStorageMask30) {m_systemStorageMask30=systemStorageMask30;emit systemStorageMask30Changed();};
    void setsystemStorageMask31(const bool& systemStorageMask31) {m_systemStorageMask31=systemStorageMask31;emit systemStorageMask31Changed();};

    void setsystemGuidanceMask0(const bool& systemGuidanceMask0) {m_systemGuidanceMask0=systemGuidanceMask0;emit systemGuidanceMask0Changed();};
    void setsystemGuidanceMask1(const bool& systemGuidanceMask1) {m_systemGuidanceMask1=systemGuidanceMask1;emit systemGuidanceMask1Changed();};
    void setsystemGuidanceMask2(const bool& systemGuidanceMask2) {m_systemGuidanceMask2=systemGuidanceMask2;emit systemGuidanceMask2Changed();};
    void setsystemGuidanceMask3(const bool& systemGuidanceMask3) {m_systemGuidanceMask3=systemGuidanceMask3;emit systemGuidanceMask3Changed();};
    void setsystemGuidanceMask4(const bool& systemGuidanceMask4) {m_systemGuidanceMask4=systemGuidanceMask4;emit systemGuidanceMask4Changed();};
    void setsystemGuidanceMask5(const bool& systemGuidanceMask5) {m_systemGuidanceMask5=systemGuidanceMask5;emit systemGuidanceMask5Changed();};
    void setsystemGuidanceMask6(const bool& systemGuidanceMask6) {m_systemGuidanceMask6=systemGuidanceMask6;emit systemGuidanceMask6Changed();};
    void setsystemGuidanceMask7(const bool& systemGuidanceMask7) {m_systemGuidanceMask7=systemGuidanceMask7;emit systemGuidanceMask7Changed();};
    void setsystemGuidanceMask8(const bool& systemGuidanceMask8) {m_systemGuidanceMask8=systemGuidanceMask8;emit systemGuidanceMask8Changed();};
    void setsystemGuidanceMask9(const bool& systemGuidanceMask9) {m_systemGuidanceMask9=systemGuidanceMask9;emit systemGuidanceMask9Changed();};
    void setsystemGuidanceMask10(const bool& systemGuidanceMask10) {m_systemGuidanceMask10=systemGuidanceMask10;emit systemGuidanceMask10Changed();};
    void setsystemGuidanceMask11(const bool& systemGuidanceMask11) {m_systemGuidanceMask11=systemGuidanceMask11;emit systemGuidanceMask11Changed();};
    void setsystemGuidanceMask12(const bool& systemGuidanceMask12) {m_systemGuidanceMask12=systemGuidanceMask12;emit systemGuidanceMask12Changed();};
    void setsystemGuidanceMask13(const bool& systemGuidanceMask13) {m_systemGuidanceMask13=systemGuidanceMask13;emit systemGuidanceMask13Changed();};
    void setsystemGuidanceMask14(const bool& systemGuidanceMask14) {m_systemGuidanceMask14=systemGuidanceMask14;emit systemGuidanceMask14Changed();};
    void setsystemGuidanceMask15(const bool& systemGuidanceMask15) {m_systemGuidanceMask15=systemGuidanceMask15;emit systemGuidanceMask15Changed();};
    void setsystemGuidanceMask16(const bool& systemGuidanceMask16) {m_systemGuidanceMask16=systemGuidanceMask16;emit systemGuidanceMask16Changed();};
    void setsystemGuidanceMask17(const bool& systemGuidanceMask17) {m_systemGuidanceMask17=systemGuidanceMask17;emit systemGuidanceMask17Changed();};
    void setsystemGuidanceMask18(const bool& systemGuidanceMask18) {m_systemGuidanceMask18=systemGuidanceMask18;emit systemGuidanceMask18Changed();};
    void setsystemGuidanceMask19(const bool& systemGuidanceMask19) {m_systemGuidanceMask19=systemGuidanceMask19;emit systemGuidanceMask19Changed();};
    void setsystemGuidanceMask20(const bool& systemGuidanceMask20) {m_systemGuidanceMask20=systemGuidanceMask20;emit systemGuidanceMask20Changed();};
    void setsystemGuidanceMask21(const bool& systemGuidanceMask21) {m_systemGuidanceMask21=systemGuidanceMask21;emit systemGuidanceMask21Changed();};
    void setsystemGuidanceMask22(const bool& systemGuidanceMask22) {m_systemGuidanceMask22=systemGuidanceMask22;emit systemGuidanceMask22Changed();};
    void setsystemGuidanceMask23(const bool& systemGuidanceMask23) {m_systemGuidanceMask23=systemGuidanceMask23;emit systemGuidanceMask23Changed();};
    void setsystemGuidanceMask24(const bool& systemGuidanceMask24) {m_systemGuidanceMask24=systemGuidanceMask24;emit systemGuidanceMask24Changed();};
    void setsystemGuidanceMask25(const bool& systemGuidanceMask25) {m_systemGuidanceMask25=systemGuidanceMask25;emit systemGuidanceMask25Changed();};
    void setsystemGuidanceMask26(const bool& systemGuidanceMask26) {m_systemGuidanceMask26=systemGuidanceMask26;emit systemGuidanceMask26Changed();};
    void setsystemGuidanceMask27(const bool& systemGuidanceMask27) {m_systemGuidanceMask27=systemGuidanceMask27;emit systemGuidanceMask27Changed();};
    void setsystemGuidanceMask28(const bool& systemGuidanceMask28) {m_systemGuidanceMask28=systemGuidanceMask28;emit systemGuidanceMask28Changed();};
    void setsystemGuidanceMask29(const bool& systemGuidanceMask29) {m_systemGuidanceMask29=systemGuidanceMask29;emit systemGuidanceMask29Changed();};
    void setsystemGuidanceMask30(const bool& systemGuidanceMask30) {m_systemGuidanceMask30=systemGuidanceMask30;emit systemGuidanceMask30Changed();};
    void setsystemGuidanceMask31(const bool& systemGuidanceMask31) {m_systemGuidanceMask31=systemGuidanceMask31;emit systemGuidanceMask31Changed();};

    void setsystemMotorControlMask0(const bool& systemMotorControlMask0) {m_systemMotorControlMask0=systemMotorControlMask0;emit systemMotorControlMask0Changed();};
    void setsystemMotorControlMask1(const bool& systemMotorControlMask1) {m_systemMotorControlMask1=systemMotorControlMask1;emit systemMotorControlMask1Changed();};
    void setsystemMotorControlMask2(const bool& systemMotorControlMask2) {m_systemMotorControlMask2=systemMotorControlMask2;emit systemMotorControlMask2Changed();};
    void setsystemMotorControlMask3(const bool& systemMotorControlMask3) {m_systemMotorControlMask3=systemMotorControlMask3;emit systemMotorControlMask3Changed();};
    void setsystemMotorControlMask4(const bool& systemMotorControlMask4) {m_systemMotorControlMask4=systemMotorControlMask4;emit systemMotorControlMask4Changed();};
    void setsystemMotorControlMask5(const bool& systemMotorControlMask5) {m_systemMotorControlMask5=systemMotorControlMask5;emit systemMotorControlMask5Changed();};
    void setsystemMotorControlMask6(const bool& systemMotorControlMask6) {m_systemMotorControlMask6=systemMotorControlMask6;emit systemMotorControlMask6Changed();};
    void setsystemMotorControlMask7(const bool& systemMotorControlMask7) {m_systemMotorControlMask7=systemMotorControlMask7;emit systemMotorControlMask7Changed();};
    void setsystemMotorControlMask8(const bool& systemMotorControlMask8) {m_systemMotorControlMask8=systemMotorControlMask8;emit systemMotorControlMask8Changed();};
    void setsystemMotorControlMask9(const bool& systemMotorControlMask9) {m_systemMotorControlMask9=systemMotorControlMask9;emit systemMotorControlMask9Changed();};
    void setsystemMotorControlMask10(const bool& systemMotorControlMask10) {m_systemMotorControlMask10=systemMotorControlMask10;emit systemMotorControlMask10Changed();};
    void setsystemMotorControlMask11(const bool& systemMotorControlMask11) {m_systemMotorControlMask11=systemMotorControlMask11;emit systemMotorControlMask11Changed();};
    void setsystemMotorControlMask12(const bool& systemMotorControlMask12) {m_systemMotorControlMask12=systemMotorControlMask12;emit systemMotorControlMask12Changed();};
    void setsystemMotorControlMask13(const bool& systemMotorControlMask13) {m_systemMotorControlMask13=systemMotorControlMask13;emit systemMotorControlMask13Changed();};
    void setsystemMotorControlMask14(const bool& systemMotorControlMask14) {m_systemMotorControlMask14=systemMotorControlMask14;emit systemMotorControlMask14Changed();};
    void setsystemMotorControlMask15(const bool& systemMotorControlMask15) {m_systemMotorControlMask15=systemMotorControlMask15;emit systemMotorControlMask15Changed();};
    void setsystemMotorControlMask16(const bool& systemMotorControlMask16) {m_systemMotorControlMask16=systemMotorControlMask16;emit systemMotorControlMask16Changed();};
    void setsystemMotorControlMask17(const bool& systemMotorControlMask17) {m_systemMotorControlMask17=systemMotorControlMask17;emit systemMotorControlMask17Changed();};
    void setsystemMotorControlMask18(const bool& systemMotorControlMask18) {m_systemMotorControlMask18=systemMotorControlMask18;emit systemMotorControlMask18Changed();};
    void setsystemMotorControlMask19(const bool& systemMotorControlMask19) {m_systemMotorControlMask19=systemMotorControlMask19;emit systemMotorControlMask19Changed();};
    void setsystemMotorControlMask20(const bool& systemMotorControlMask20) {m_systemMotorControlMask20=systemMotorControlMask20;emit systemMotorControlMask20Changed();};
    void setsystemMotorControlMask21(const bool& systemMotorControlMask21) {m_systemMotorControlMask21=systemMotorControlMask21;emit systemMotorControlMask21Changed();};
    void setsystemMotorControlMask22(const bool& systemMotorControlMask22) {m_systemMotorControlMask22=systemMotorControlMask22;emit systemMotorControlMask22Changed();};
    void setsystemMotorControlMask23(const bool& systemMotorControlMask23) {m_systemMotorControlMask23=systemMotorControlMask23;emit systemMotorControlMask23Changed();};
    void setsystemMotorControlMask24(const bool& systemMotorControlMask24) {m_systemMotorControlMask24=systemMotorControlMask24;emit systemMotorControlMask24Changed();};
    void setsystemMotorControlMask25(const bool& systemMotorControlMask25) {m_systemMotorControlMask25=systemMotorControlMask25;emit systemMotorControlMask25Changed();};
    void setsystemMotorControlMask26(const bool& systemMotorControlMask26) {m_systemMotorControlMask26=systemMotorControlMask26;emit systemMotorControlMask26Changed();};
    void setsystemMotorControlMask27(const bool& systemMotorControlMask27) {m_systemMotorControlMask27=systemMotorControlMask27;emit systemMotorControlMask27Changed();};
    void setsystemMotorControlMask28(const bool& systemMotorControlMask28) {m_systemMotorControlMask28=systemMotorControlMask28;emit systemMotorControlMask28Changed();};
    void setsystemMotorControlMask29(const bool& systemMotorControlMask29) {m_systemMotorControlMask29=systemMotorControlMask29;emit systemMotorControlMask29Changed();};
    void setsystemMotorControlMask30(const bool& systemMotorControlMask30) {m_systemMotorControlMask30=systemMotorControlMask30;emit systemMotorControlMask30Changed();};
    void setsystemMotorControlMask31(const bool& systemMotorControlMask31) {m_systemMotorControlMask31=systemMotorControlMask31;emit systemMotorControlMask31Changed();};


    void setsystemTelemetryMask0(const bool& systemTelemetryMask0) {m_systemTelemetryMask0=systemTelemetryMask0;emit systemTelemetryMask0Changed();};
    void setsystemTelemetryMask1(const bool& systemTelemetryMask1) {m_systemTelemetryMask1=systemTelemetryMask1;emit systemTelemetryMask1Changed();};
    void setsystemTelemetryMask2(const bool& systemTelemetryMask2) {m_systemTelemetryMask2=systemTelemetryMask2;emit systemTelemetryMask2Changed();};
    void setsystemTelemetryMask3(const bool& systemTelemetryMask3) {m_systemTelemetryMask3=systemTelemetryMask3;emit systemTelemetryMask3Changed();};
    void setsystemTelemetryMask4(const bool& systemTelemetryMask4) {m_systemTelemetryMask4=systemTelemetryMask4;emit systemTelemetryMask4Changed();};
    void setsystemTelemetryMask5(const bool& systemTelemetryMask5) {m_systemTelemetryMask5=systemTelemetryMask5;emit systemTelemetryMask5Changed();};
    void setsystemTelemetryMask6(const bool& systemTelemetryMask6) {m_systemTelemetryMask6=systemTelemetryMask6;emit systemTelemetryMask6Changed();};
    void setsystemTelemetryMask7(const bool& systemTelemetryMask7) {m_systemTelemetryMask7=systemTelemetryMask7;emit systemTelemetryMask7Changed();};
    void setsystemTelemetryMask8(const bool& systemTelemetryMask8) {m_systemTelemetryMask8=systemTelemetryMask8;emit systemTelemetryMask8Changed();};
    void setsystemTelemetryMask9(const bool& systemTelemetryMask9) {m_systemTelemetryMask9=systemTelemetryMask9;emit systemTelemetryMask9Changed();};
    void setsystemTelemetryMask10(const bool& systemTelemetryMask10) {m_systemTelemetryMask10=systemTelemetryMask10;emit systemTelemetryMask10Changed();};
    void setsystemTelemetryMask11(const bool& systemTelemetryMask11) {m_systemTelemetryMask11=systemTelemetryMask11;emit systemTelemetryMask11Changed();};
    void setsystemTelemetryMask12(const bool& systemTelemetryMask12) {m_systemTelemetryMask12=systemTelemetryMask12;emit systemTelemetryMask12Changed();};
    void setsystemTelemetryMask13(const bool& systemTelemetryMask13) {m_systemTelemetryMask13=systemTelemetryMask13;emit systemTelemetryMask13Changed();};
    void setsystemTelemetryMask14(const bool& systemTelemetryMask14) {m_systemTelemetryMask14=systemTelemetryMask14;emit systemTelemetryMask14Changed();};
    void setsystemTelemetryMask15(const bool& systemTelemetryMask15) {m_systemTelemetryMask15=systemTelemetryMask15;emit systemTelemetryMask15Changed();};
    void setsystemTelemetryMask16(const bool& systemTelemetryMask16) {m_systemTelemetryMask16=systemTelemetryMask16;emit systemTelemetryMask16Changed();};
    void setsystemTelemetryMask17(const bool& systemTelemetryMask17) {m_systemTelemetryMask17=systemTelemetryMask17;emit systemTelemetryMask17Changed();};
    void setsystemTelemetryMask18(const bool& systemTelemetryMask18) {m_systemTelemetryMask18=systemTelemetryMask18;emit systemTelemetryMask18Changed();};
    void setsystemTelemetryMask19(const bool& systemTelemetryMask19) {m_systemTelemetryMask19=systemTelemetryMask19;emit systemTelemetryMask19Changed();};
    void setsystemTelemetryMask20(const bool& systemTelemetryMask20) {m_systemTelemetryMask20=systemTelemetryMask20;emit systemTelemetryMask20Changed();};
    void setsystemTelemetryMask21(const bool& systemTelemetryMask21) {m_systemTelemetryMask21=systemTelemetryMask21;emit systemTelemetryMask21Changed();};
    void setsystemTelemetryMask22(const bool& systemTelemetryMask22) {m_systemTelemetryMask22=systemTelemetryMask22;emit systemTelemetryMask22Changed();};
    void setsystemTelemetryMask23(const bool& systemTelemetryMask23) {m_systemTelemetryMask23=systemTelemetryMask23;emit systemTelemetryMask23Changed();};
    void setsystemTelemetryMask24(const bool& systemTelemetryMask24) {m_systemTelemetryMask24=systemTelemetryMask24;emit systemTelemetryMask24Changed();};
    void setsystemTelemetryMask25(const bool& systemTelemetryMask25) {m_systemTelemetryMask25=systemTelemetryMask25;emit systemTelemetryMask25Changed();};
    void setsystemTelemetryMask26(const bool& systemTelemetryMask26) {m_systemTelemetryMask26=systemTelemetryMask26;emit systemTelemetryMask26Changed();};
    void setsystemTelemetryMask27(const bool& systemTelemetryMask27) {m_systemTelemetryMask27=systemTelemetryMask27;emit systemTelemetryMask27Changed();};
    void setsystemTelemetryMask28(const bool& systemTelemetryMask28) {m_systemTelemetryMask28=systemTelemetryMask28;emit systemTelemetryMask28Changed();};
    void setsystemTelemetryMask29(const bool& systemTelemetryMask29) {m_systemTelemetryMask29=systemTelemetryMask29;emit systemTelemetryMask29Changed();};
    void setsystemTelemetryMask30(const bool& systemTelemetryMask30) {m_systemTelemetryMask30=systemTelemetryMask30;emit systemTelemetryMask30Changed();};
    void setsystemTelemetryMask31(const bool& systemTelemetryMask31) {m_systemTelemetryMask31=systemTelemetryMask31;emit systemTelemetryMask31Changed();};
    void setsystemTelemetryMask32(const bool& systemTelemetryMask32) {m_systemTelemetryMask32=systemTelemetryMask32;emit systemTelemetryMask32Changed();};
    void setsystemTelemetryMask33(const bool& systemTelemetryMask33) {m_systemTelemetryMask33=systemTelemetryMask33;emit systemTelemetryMask33Changed();};
    void setsystemTelemetryMask34(const bool& systemTelemetryMask34) {m_systemTelemetryMask34=systemTelemetryMask34;emit systemTelemetryMask34Changed();};
    void setsystemTelemetryMask35(const bool& systemTelemetryMask35) {m_systemTelemetryMask35=systemTelemetryMask35;emit systemTelemetryMask35Changed();};
    void setsystemTelemetryMask36(const bool& systemTelemetryMask36) {m_systemTelemetryMask36=systemTelemetryMask36;emit systemTelemetryMask36Changed();};
    void setsystemTelemetryMask37(const bool& systemTelemetryMask37) {m_systemTelemetryMask37=systemTelemetryMask37;emit systemTelemetryMask37Changed();};
    void setsystemTelemetryMask38(const bool& systemTelemetryMask38) {m_systemTelemetryMask38=systemTelemetryMask38;emit systemTelemetryMask38Changed();};
    void setsystemTelemetryMask39(const bool& systemTelemetryMask39) {m_systemTelemetryMask39=systemTelemetryMask39;emit systemTelemetryMask39Changed();};
    void setsystemTelemetryMask40(const bool& systemTelemetryMask40) {m_systemTelemetryMask40=systemTelemetryMask40;emit systemTelemetryMask40Changed();};
    void setsystemTelemetryMask41(const bool& systemTelemetryMask41) {m_systemTelemetryMask41=systemTelemetryMask41;emit systemTelemetryMask41Changed();};
    void setsystemTelemetryMask42(const bool& systemTelemetryMask42) {m_systemTelemetryMask42=systemTelemetryMask42;emit systemTelemetryMask42Changed();};
    void setsystemTelemetryMask43(const bool& systemTelemetryMask43) {m_systemTelemetryMask43=systemTelemetryMask43;emit systemTelemetryMask43Changed();};
    void setsystemTelemetryMask44(const bool& systemTelemetryMask44) {m_systemTelemetryMask44=systemTelemetryMask44;emit systemTelemetryMask44Changed();};
    void setsystemTelemetryMask45(const bool& systemTelemetryMask45) {m_systemTelemetryMask45=systemTelemetryMask45;emit systemTelemetryMask45Changed();};
    void setsystemTelemetryMask46(const bool& systemTelemetryMask46) {m_systemTelemetryMask46=systemTelemetryMask46;emit systemTelemetryMask46Changed();};
    void setsystemTelemetryMask47(const bool& systemTelemetryMask47) {m_systemTelemetryMask47=systemTelemetryMask47;emit systemTelemetryMask47Changed();};
    void setsystemTelemetryMask48(const bool& systemTelemetryMask48) {m_systemTelemetryMask48=systemTelemetryMask48;emit systemTelemetryMask48Changed();};
    void setsystemTelemetryMask49(const bool& systemTelemetryMask49) {m_systemTelemetryMask49=systemTelemetryMask49;emit systemTelemetryMask49Changed();};
    void setsystemTelemetryMask50(const bool& systemTelemetryMask50) {m_systemTelemetryMask50=systemTelemetryMask50;emit systemTelemetryMask50Changed();};
    void setsystemTelemetryMask51(const bool& systemTelemetryMask51) {m_systemTelemetryMask51=systemTelemetryMask51;emit systemTelemetryMask51Changed();};
    void setsystemTelemetryMask52(const bool& systemTelemetryMask52) {m_systemTelemetryMask52=systemTelemetryMask52;emit systemTelemetryMask52Changed();};
    void setsystemTelemetryMask53(const bool& systemTelemetryMask53) {m_systemTelemetryMask53=systemTelemetryMask53;emit systemTelemetryMask53Changed();};
    void setsystemTelemetryMask54(const bool& systemTelemetryMask54) {m_systemTelemetryMask54=systemTelemetryMask54;emit systemTelemetryMask54Changed();};
    void setsystemTelemetryMask55(const bool& systemTelemetryMask55) {m_systemTelemetryMask55=systemTelemetryMask55;emit systemTelemetryMask55Changed();};
    void setsystemTelemetryMask56(const bool& systemTelemetryMask56) {m_systemTelemetryMask56=systemTelemetryMask56;emit systemTelemetryMask56Changed();};
    void setsystemTelemetryMask57(const bool& systemTelemetryMask57) {m_systemTelemetryMask57=systemTelemetryMask57;emit systemTelemetryMask57Changed();};
    void setsystemTelemetryMask58(const bool& systemTelemetryMask58) {m_systemTelemetryMask58=systemTelemetryMask58;emit systemTelemetryMask58Changed();};
    void setsystemTelemetryMask59(const bool& systemTelemetryMask59) {m_systemTelemetryMask59=systemTelemetryMask59;emit systemTelemetryMask59Changed();};
    void setsystemTelemetryMask60(const bool& systemTelemetryMask60) {m_systemTelemetryMask60=systemTelemetryMask60;emit systemTelemetryMask60Changed();};
    void setsystemTelemetryMask61(const bool& systemTelemetryMask61) {m_systemTelemetryMask61=systemTelemetryMask61;emit systemTelemetryMask61Changed();};
    void setsystemTelemetryMask62(const bool& systemTelemetryMask62) {m_systemTelemetryMask62=systemTelemetryMask62;emit systemTelemetryMask62Changed();};
    void setsystemTelemetryMask63(const bool& systemTelemetryMask63) {m_systemTelemetryMask63=systemTelemetryMask63;emit systemTelemetryMask63Changed();};

    void setemergencyBoardStatus0(const bool& emergencyBoardStatus0) {m_emergencyBoardStatus0=emergencyBoardStatus0;emit emergencyBoardStatus0Changed();};
    void setemergencyBoardStatus1(const bool& emergencyBoardStatus1) {m_emergencyBoardStatus1=emergencyBoardStatus1;emit emergencyBoardStatus1Changed();};
    void setemergencyBoardStatus2(const bool& emergencyBoardStatus2) {m_emergencyBoardStatus2=emergencyBoardStatus2;emit emergencyBoardStatus2Changed();};
    void setemergencyBoardStatus3(const bool& emergencyBoardStatus3) {m_emergencyBoardStatus3=emergencyBoardStatus3;emit emergencyBoardStatus3Changed();};
    void setemergencyBoardStatus4(const bool& emergencyBoardStatus4) {m_emergencyBoardStatus4=emergencyBoardStatus4;emit emergencyBoardStatus4Changed();};
    void setemergencyBoardStatus5(const bool& emergencyBoardStatus5) {m_emergencyBoardStatus5=emergencyBoardStatus5;emit emergencyBoardStatus5Changed();};
    void setemergencyBoardStatus6(const bool& emergencyBoardStatus6) {m_emergencyBoardStatus6=emergencyBoardStatus6;emit emergencyBoardStatus6Changed();};
    void setemergencyBoardStatus7(const bool& emergencyBoardStatus7) {m_emergencyBoardStatus7=emergencyBoardStatus7;emit emergencyBoardStatus7Changed();};
    void setemergencyBoardStatus8(const bool& emergencyBoardStatus8) {m_emergencyBoardStatus8=emergencyBoardStatus8;emit emergencyBoardStatus8Changed();};
    void setemergencyBoardStatus9(const bool& emergencyBoardStatus9) {m_emergencyBoardStatus9=emergencyBoardStatus9;emit emergencyBoardStatus9Changed();};
    void setemergencyBoardStatus10(const bool& emergencyBoardStatus10) {m_emergencyBoardStatus10=emergencyBoardStatus10;emit emergencyBoardStatus10Changed();};
    void setemergencyBoardStatus11(const bool& emergencyBoardStatus11) {m_emergencyBoardStatus11=emergencyBoardStatus11;emit emergencyBoardStatus11Changed();};
    void setemergencyBoardStatus12(const bool& emergencyBoardStatus12) {m_emergencyBoardStatus12=emergencyBoardStatus12;emit emergencyBoardStatus12Changed();};
    void setemergencyBoardStatus13(const bool& emergencyBoardStatus13) {m_emergencyBoardStatus13=emergencyBoardStatus13;emit emergencyBoardStatus13Changed();};
    void setemergencyBoardStatus14(const bool& emergencyBoardStatus14) {m_emergencyBoardStatus14=emergencyBoardStatus14;emit emergencyBoardStatus14Changed();};
    void setemergencyBoardStatus15(const bool& emergencyBoardStatus15) {m_emergencyBoardStatus15=emergencyBoardStatus15;emit emergencyBoardStatus15Changed();};

    void setPSUStatus0(const bool& PSUStatus0) {m_PSUStatus0=PSUStatus0;emit PSUStatus0Changed();};
    void setPSUStatus1(const bool& PSUStatus1) {m_PSUStatus1=PSUStatus1;emit PSUStatus1Changed();};
    void setPSUStatus2(const bool& PSUStatus2) {m_PSUStatus2=PSUStatus2;emit PSUStatus2Changed();};
    void setPSUStatus3(const bool& PSUStatus3) {m_PSUStatus3=PSUStatus3;emit PSUStatus3Changed();};
    void setPSUStatus4(const bool& PSUStatus4) {m_PSUStatus4=PSUStatus4;emit PSUStatus4Changed();};
    void setPSUStatus5(const bool& PSUStatus5) {m_PSUStatus5=PSUStatus5;emit PSUStatus5Changed();};
    void setPSUStatus6(const bool& PSUStatus6) {m_PSUStatus6=PSUStatus6;emit PSUStatus6Changed();};
    void setPSUStatus7(const bool& PSUStatus7) {m_PSUStatus7=PSUStatus7;emit PSUStatus7Changed();};
    void setPSUStatus8(const bool& PSUStatus8) {m_PSUStatus8=PSUStatus8;emit PSUStatus8Changed();};
    void setPSUStatus9(const bool& PSUStatus9) {m_PSUStatus9=PSUStatus9;emit PSUStatus9Changed();};
    void setPSUStatus10(const bool& PSUStatus10) {m_PSUStatus10=PSUStatus10;emit PSUStatus10Changed();};
    void setPSUStatus11(const bool& PSUStatus11) {m_PSUStatus11=PSUStatus11;emit PSUStatus11Changed();};
    void setPSUStatus12(const bool& PSUStatus12) {m_PSUStatus12=PSUStatus12;emit PSUStatus12Changed();};
    void setPSUStatus13(const bool& PSUStatus13) {m_PSUStatus13=PSUStatus13;emit PSUStatus13Changed();};
    void setPSUStatus14(const bool& PSUStatus14) {m_PSUStatus14=PSUStatus14;emit PSUStatus14Changed();};
    void setPSUStatus15(const bool& PSUStatus15) {m_PSUStatus15=PSUStatus15;emit PSUStatus15Changed();};

    void setemergencyRadioLinkStatus0(const bool& emergencyRadioLinkStatus0) {m_emergencyRadioLinkStatus0=emergencyRadioLinkStatus0;emit emergencyRadioLinkStatus0Changed();};
    void setemergencyRadioLinkStatus1(const bool& emergencyRadioLinkStatus1) {m_emergencyRadioLinkStatus1=emergencyRadioLinkStatus1;emit emergencyRadioLinkStatus1Changed();};
    void setemergencyRadioLinkStatus2(const bool& emergencyRadioLinkStatus2) {m_emergencyRadioLinkStatus2=emergencyRadioLinkStatus2;emit emergencyRadioLinkStatus2Changed();};
    void setemergencyRadioLinkStatus3(const bool& emergencyRadioLinkStatus3) {m_emergencyRadioLinkStatus3=emergencyRadioLinkStatus3;emit emergencyRadioLinkStatus3Changed();};
    void setemergencyRadioLinkStatus4(const bool& emergencyRadioLinkStatus4) {m_emergencyRadioLinkStatus4=emergencyRadioLinkStatus4;emit emergencyRadioLinkStatus4Changed();};
    void setemergencyRadioLinkStatus5(const bool& emergencyRadioLinkStatus5) {m_emergencyRadioLinkStatus5=emergencyRadioLinkStatus5;emit emergencyRadioLinkStatus5Changed();};
    void setemergencyRadioLinkStatus6(const bool& emergencyRadioLinkStatus6) {m_emergencyRadioLinkStatus6=emergencyRadioLinkStatus6;emit emergencyRadioLinkStatus6Changed();};
    void setemergencyRadioLinkStatus7(const bool& emergencyRadioLinkStatus7) {m_emergencyRadioLinkStatus7=emergencyRadioLinkStatus7;emit emergencyRadioLinkStatus7Changed();};

    void setsystemMsgCounter(const int& systemMsgCounter) {m_systemMsgCounter=systemMsgCounter;emit systemMsgCounterChanged();};


    /* RADIOLINK */

    void setRSSI(const quint16& RSSI) {m_RSSI=RSSI;emit RSSIChanged();};
    void setradiolinkErrorCounter(const quint8& radiolinkErrorCounter) {m_radiolinkErrorCounter=radiolinkErrorCounter;emit radiolinkErrorCounterChanged();};
    void setradiolinkMask0(const bool& radiolinkMask0) {m_radiolinkMask0=radiolinkMask0;emit radiolinkMask0Changed();};
    void setradiolinkMask1(const bool& radiolinkMask1) {m_radiolinkMask1=radiolinkMask1;emit radiolinkMask1Changed();};
    void setradiolinkMask2(const bool& radiolinkMask2) {m_radiolinkMask2=radiolinkMask2;emit radiolinkMask2Changed();};
    void setradiolinkMask3(const bool& radiolinkMask3) {m_radiolinkMask3=radiolinkMask3;emit radiolinkMask3Changed();};
    void setradiolinkMask4(const bool& radiolinkMask4) {m_radiolinkMask4=radiolinkMask4;emit radiolinkMask4Changed();};
    void setradiolinkMask5(const bool& radiolinkMask5) {m_radiolinkMask5=radiolinkMask5;emit radiolinkMask5Changed();};
    void setradiolinkMask6(const bool& radiolinkMask6) {m_radiolinkMask6=radiolinkMask6;emit radiolinkMask6Changed();};
    void setradiolinkMask7(const bool& radiolinkMask7) {m_radiolinkMask7=radiolinkMask7;emit radiolinkMask7Changed();};
    void setradiolinkMask8(const bool& radiolinkMask8) {m_radiolinkMask8=radiolinkMask8;emit radiolinkMask8Changed();};
    void setradiolinkMask9(const bool& radiolinkMask9) {m_radiolinkMask9=radiolinkMask9;emit radiolinkMask9Changed();};
    void setradiolinkMask10(const bool& radiolinkMask10) {m_radiolinkMask10=radiolinkMask10;emit radiolinkMask10Changed();};
    void setradiolinkMask11(const bool& radiolinkMask11) {m_radiolinkMask11=radiolinkMask11;emit radiolinkMask11Changed();};
    void setradiolinkMask12(const bool& radiolinkMask12) {m_radiolinkMask12=radiolinkMask12;emit radiolinkMask12Changed();};
    void setradiolinkMask13(const bool& radiolinkMask13) {m_radiolinkMask13=radiolinkMask13;emit radiolinkMask13Changed();};
    void setradiolinkMask14(const bool& radiolinkMask14) {m_radiolinkMask14=radiolinkMask14;emit radiolinkMask14Changed();};
    void setradiolinkMask15(const bool& radiolinkMask15) {m_radiolinkMask15=radiolinkMask15;emit radiolinkMask15Changed();};
    void setradiolinkMask16(const bool& radiolinkMask16) {m_radiolinkMask16=radiolinkMask16;emit radiolinkMask16Changed();};
    void setradiolinkMask17(const bool& radiolinkMask17) {m_radiolinkMask17=radiolinkMask17;emit radiolinkMask17Changed();};
    void setradiolinkMask18(const bool& radiolinkMask18) {m_radiolinkMask18=radiolinkMask18;emit radiolinkMask18Changed();};
    void setradiolinkMask19(const bool& radiolinkMask19) {m_radiolinkMask19=radiolinkMask19;emit radiolinkMask19Changed();};
    void setradiolinkMask20(const bool& radiolinkMask20) {m_radiolinkMask20=radiolinkMask20;emit radiolinkMask20Changed();};
    void setradiolinkMask21(const bool& radiolinkMask21) {m_radiolinkMask21=radiolinkMask21;emit radiolinkMask21Changed();};
    void setradiolinkMask22(const bool& radiolinkMask22) {m_radiolinkMask22=radiolinkMask22;emit radiolinkMask22Changed();};
    void setradiolinkMask23(const bool& radiolinkMask23) {m_radiolinkMask23=radiolinkMask23;emit radiolinkMask23Changed();};
    void setradiolinkMask24(const bool& radiolinkMask24) {m_radiolinkMask24=radiolinkMask24;emit radiolinkMask24Changed();};
    void setradiolinkMask25(const bool& radiolinkMask25) {m_radiolinkMask25=radiolinkMask25;emit radiolinkMask25Changed();};
    void setradiolinkMask26(const bool& radiolinkMask26) {m_radiolinkMask26=radiolinkMask26;emit radiolinkMask26Changed();};
    void setradiolinkMask27(const bool& radiolinkMask27) {m_radiolinkMask27=radiolinkMask27;emit radiolinkMask27Changed();};
    void setradiolinkMask28(const bool& radiolinkMask28) {m_radiolinkMask28=radiolinkMask28;emit radiolinkMask28Changed();};
    void setradiolinkMask29(const bool& radiolinkMask29) {m_radiolinkMask29=radiolinkMask29;emit radiolinkMask29Changed();};
    void setradiolinkMask30(const bool& radiolinkMask30) {m_radiolinkMask30=radiolinkMask30;emit radiolinkMask30Changed();};
    void setradiolinkMask31(const bool& radiolinkMask31) {m_radiolinkMask31=radiolinkMask31;emit radiolinkMask31Changed();};

    void setradiolinkMsgCounter(const int& radiolinkMsgCounter) {m_radiolinkMsgCounter=radiolinkMsgCounter;emit radiolinkMsgCounterChanged();};


    /* GUIDANCE */

    void setguidanceMask0(const bool& guidanceMask0) {m_guidanceMask0=guidanceMask0;emit guidanceMask0Changed();};
    void setguidanceMask1(const bool& guidanceMask1) {m_guidanceMask1=guidanceMask1;emit guidanceMask1Changed();};
    void setguidanceMask2(const bool& guidanceMask2) {m_guidanceMask2=guidanceMask2;emit guidanceMask2Changed();};
    void setguidanceMask3(const bool& guidanceMask3) {m_guidanceMask3=guidanceMask3;emit guidanceMask3Changed();};
    void setguidanceMask4(const bool& guidanceMask4) {m_guidanceMask4=guidanceMask4;emit guidanceMask4Changed();};
    void setguidanceMask5(const bool& guidanceMask5) {m_guidanceMask5=guidanceMask5;emit guidanceMask5Changed();};
    void setguidanceMask6(const bool& guidanceMask6) {m_guidanceMask6=guidanceMask6;emit guidanceMask6Changed();};
    void setguidanceMask7(const bool& guidanceMask7) {m_guidanceMask7=guidanceMask7;emit guidanceMask7Changed();};
    void setguidanceMask8(const bool& guidanceMask8) {m_guidanceMask8=guidanceMask8;emit guidanceMask8Changed();};
    void setguidanceMask9(const bool& guidanceMask9) {m_guidanceMask9=guidanceMask9;emit guidanceMask9Changed();};
    void setguidanceMask10(const bool& guidanceMask10) {m_guidanceMask10=guidanceMask10;emit guidanceMask10Changed();};
    void setguidanceMask11(const bool& guidanceMask11) {m_guidanceMask11=guidanceMask11;emit guidanceMask11Changed();};
    void setguidanceMask12(const bool& guidanceMask12) {m_guidanceMask12=guidanceMask12;emit guidanceMask12Changed();};
    void setguidanceMask13(const bool& guidanceMask13) {m_guidanceMask13=guidanceMask13;emit guidanceMask13Changed();};
    void setguidanceMask14(const bool& guidanceMask14) {m_guidanceMask14=guidanceMask14;emit guidanceMask14Changed();};
    void setguidanceMask15(const bool& guidanceMask15) {m_guidanceMask15=guidanceMask15;emit guidanceMask15Changed();};
    void setguidanceMask16(const bool& guidanceMask16) {m_guidanceMask16=guidanceMask16;emit guidanceMask16Changed();};
    void setguidanceMask17(const bool& guidanceMask17) {m_guidanceMask17=guidanceMask17;emit guidanceMask17Changed();};
    void setguidanceMask18(const bool& guidanceMask18) {m_guidanceMask18=guidanceMask18;emit guidanceMask18Changed();};
    void setguidanceMask19(const bool& guidanceMask19) {m_guidanceMask19=guidanceMask19;emit guidanceMask19Changed();};
    void setguidanceMask20(const bool& guidanceMask20) {m_guidanceMask20=guidanceMask20;emit guidanceMask20Changed();};
    void setguidanceMask21(const bool& guidanceMask21) {m_guidanceMask21=guidanceMask21;emit guidanceMask21Changed();};
    void setguidanceMask22(const bool& guidanceMask22) {m_guidanceMask22=guidanceMask22;emit guidanceMask22Changed();};
    void setguidanceMask23(const bool& guidanceMask23) {m_guidanceMask23=guidanceMask23;emit guidanceMask23Changed();};
    void setguidanceMask24(const bool& guidanceMask24) {m_guidanceMask24=guidanceMask24;emit guidanceMask24Changed();};
    void setguidanceMask25(const bool& guidanceMask25) {m_guidanceMask25=guidanceMask25;emit guidanceMask25Changed();};
    void setguidanceMask26(const bool& guidanceMask26) {m_guidanceMask26=guidanceMask26;emit guidanceMask26Changed();};
    void setguidanceMask27(const bool& guidanceMask27) {m_guidanceMask27=guidanceMask27;emit guidanceMask27Changed();};
    void setguidanceMask28(const bool& guidanceMask28) {m_guidanceMask28=guidanceMask28;emit guidanceMask28Changed();};
    void setguidanceMask29(const bool& guidanceMask29) {m_guidanceMask29=guidanceMask29;emit guidanceMask29Changed();};
    void setguidanceMask30(const bool& guidanceMask30) {m_guidanceMask30=guidanceMask30;emit guidanceMask30Changed();};
    void setguidanceMask31(const bool& guidanceMask31) {m_guidanceMask31=guidanceMask31;emit guidanceMask31Changed();};

    void setguidanceMsgCounter(const int& guidanceMsgCounter) {m_guidanceMsgCounter=guidanceMsgCounter;emit guidanceMsgCounterChanged();};

    /* STORAGE */

    void setstorageFreeDataSize(const quint32& storageFreeDataSize) {m_storageFreeDataSize=storageFreeDataSize;emit storageFreeDataSizeChanged();};
    void setstorage0(const bool& storage0) {m_storage0=storage0;emit storage0Changed();};
    void setstorage1(const bool& storage1) {m_storage1=storage1;emit storage1Changed();};
    void setstorage2(const bool& storage2) {m_storage2=storage2;emit storage2Changed();};
    void setstorage3(const bool& storage3) {m_storage3=storage3;emit storage3Changed();};
    void setstorage4(const bool& storage4) {m_storage4=storage4;emit storage4Changed();};
    void setstorage5(const bool& storage5) {m_storage5=storage5;emit storage5Changed();};
    void setstorage6(const bool& storage6) {m_storage6=storage6;emit storage6Changed();};
    void setstorage7(const bool& storage7) {m_storage7=storage7;emit storage7Changed();};
    void setstorage8(const bool& storage8) {m_storage8=storage8;emit storage8Changed();};
    void setstorage9(const bool& storage9) {m_storage9=storage9;emit storage9Changed();};
    void setstorage10(const bool& storage10) {m_storage10=storage10;emit storage10Changed();};
    void setstorage11(const bool& storage11) {m_storage11=storage11;emit storage11Changed();};
    void setstorage12(const bool& storage12) {m_storage12=storage12;emit storage12Changed();};
    void setstorage13(const bool& storage13) {m_storage13=storage13;emit storage13Changed();};
    void setstorage14(const bool& storage14) {m_storage14=storage14;emit storage14Changed();};
    void setstorage15(const bool& storage15) {m_storage15=storage15;emit storage15Changed();};
    void setstorage16(const bool& storage16) {m_storage16=storage16;emit storage16Changed();};
    void setstorage17(const bool& storage17) {m_storage17=storage17;emit storage17Changed();};
    void setstorage18(const bool& storage18) {m_storage18=storage18;emit storage18Changed();};
    void setstorage19(const bool& storage19) {m_storage19=storage19;emit storage19Changed();};
    void setstorage20(const bool& storage20) {m_storage20=storage20;emit storage20Changed();};
    void setstorage21(const bool& storage21) {m_storage21=storage21;emit storage21Changed();};
    void setstorage22(const bool& storage22) {m_storage22=storage22;emit storage22Changed();};
    void setstorage23(const bool& storage23) {m_storage23=storage23;emit storage23Changed();};
    void setstorage24(const bool& storage24) {m_storage24=storage24;emit storage24Changed();};
    void setstorage25(const bool& storage25) {m_storage25=storage25;emit storage25Changed();};
    void setstorage26(const bool& storage26) {m_storage26=storage26;emit storage26Changed();};
    void setstorage27(const bool& storage27) {m_storage27=storage27;emit storage27Changed();};
    void setstorage28(const bool& storage28) {m_storage28=storage28;emit storage28Changed();};
    void setstorage29(const bool& storage29) {m_storage29=storage29;emit storage29Changed();};
    void setstorage30(const bool& storage30) {m_storage30=storage30;emit storage30Changed();};
    void setstorage31(const bool& storage31) {m_storage31=storage31;emit storage31Changed();};

    void setstorageMsgCounter(const int& storageMsgCounter) {m_storageMsgCounter=storageMsgCounter;emit storageMsgCounterChanged();};

    void setmsgTelemetryOld(const bool& msgTelemetryOld) {m_msgTelemetryOld=msgTelemetryOld;emit msgTelemetryOldChanged();};
    void setmsgGuidanceOld(const bool& msgGuidanceOld) {m_msgGuidanceOld=msgGuidanceOld;emit msgGuidanceOldChanged();};
    void setmsgStorageOld(const bool& msgStorageOld) {m_msgStorageOld=msgStorageOld;emit msgStorageOldChanged();};
    void setmsgSystemOld(const bool& msgSystemOld) {m_msgSystemOld=msgSystemOld;emit msgSystemOldChanged();};
    void setmsgRadioLinkOld(const bool& msgRadioLinkOld) {m_msgRadioLinkOld=msgRadioLinkOld;emit msgRadioLinkOldChanged();};
    void setmsgMotorOld(const bool& msgMotorOld) {m_msgMotorOld=msgMotorOld;emit msgMotorOldChanged();};


    /* DESC */
    void setLatitudeDesc(const QString& LatitudeDesc) {m_LatitudeDesc=LatitudeDesc;emit LatitudeDescChanged();};
    void setLongitudeDesc(const QString& LongitudeDesc) {m_LongitudeDesc=LongitudeDesc;emit LongitudeDescChanged();};
    void setGNSSAltitudeDesc(const QString& GNSSAltitudeDesc) {m_GNSSAltitudeDesc=GNSSAltitudeDesc;emit GNSSAltitudeDescChanged();};

    void setTimeStampDesc(const QString& TimeStampDesc) {m_TimeStampDesc=TimeStampDesc;emit TimeStampDescChanged();};
    void setTimeStampRIODesc(const QString& TimeStampRIODesc) {m_TimeStampRIODesc=TimeStampRIODesc;emit TimeStampRIODescChanged();};

    void setAirSpeed_UVectorDesc(const QString& AirSpeed_UVectorDesc) {m_AirSpeed_UVectorDesc=AirSpeed_UVectorDesc;emit AirSpeed_UVectorDescChanged();};
    void setAirSpeed_VVectorDesc(const QString& AirSpeed_VVectorDesc) {m_AirSpeed_VVectorDesc=AirSpeed_VVectorDesc;emit AirSpeed_VVectorDescChanged();};
    void setAirSpeed_WVectorDesc(const QString& AirSpeed_WVectorDesc) {m_AirSpeed_WVectorDesc=AirSpeed_WVectorDesc;emit AirSpeed_WVectorDescChanged();};
    void setAirTemperatureDesc(const QString& AirTemperatureDesc) {m_AirTemperatureDesc=AirTemperatureDesc;emit AirTemperatureDescChanged();};
    void setAltitudeFromRadarAltimeterDesc(const QString& AltitudeFromRadarAltimeterDesc) {m_AltitudeFromRadarAltimeterDesc=AltitudeFromRadarAltimeterDesc;emit AltitudeFromRadarAltimeterDescChanged();};
    void setAltitudeFromPayloadAltimeterDesc(const QString& AltitudeFromPayloadAltimeterDesc) {m_AltitudeFromPayloadAltimeterDesc=AltitudeFromPayloadAltimeterDesc;emit AltitudeFromPayloadAltimeterDescChanged();};
    void setLinearVelocityHorizontalDesc(const QString& LinearVelocityHorizontalDesc) {m_LinearVelocityHorizontalDesc=LinearVelocityHorizontalDesc;emit LinearVelocityHorizontalDescChanged();};
    void setLinearVelocityVerticalDesc(const QString& LinearVelocityVerticalDesc) {m_LinearVelocityVerticalDesc=LinearVelocityVerticalDesc;emit LinearVelocityVerticalDescChanged();};
    void setPositionAccuracyDesc(const QString& PositionAccuracyDesc) {m_PositionAccuracyDesc=PositionAccuracyDesc;emit PositionAccuracyDescChanged();};
    void setSpeedAccuracyDesc(const QString& SpeedAccuracyDesc) {m_SpeedAccuracyDesc=SpeedAccuracyDesc;emit SpeedAccuracyDescChanged();};
    void setLinearAccelerationXDesc(const QString& LinearAccelerationXDesc) {m_LinearAccelerationXDesc=LinearAccelerationXDesc;emit LinearAccelerationXDescChanged();};
    void setLinearAccelerationYDesc(const QString& LinearAccelerationYDesc) {m_LinearAccelerationYDesc=LinearAccelerationYDesc;emit LinearAccelerationYDescChanged();};
    void setLinearAccelerationZDesc(const QString& LinearAccelerationZDesc) {m_LinearAccelerationZDesc=LinearAccelerationZDesc;emit LinearAccelerationZDescChanged();};
    void setECEFVectorPositionXDesc(const QString& ECEFVectorPositionXDesc) {m_ECEFVectorPositionXDesc=ECEFVectorPositionXDesc;emit ECEFVectorPositionXDescChanged();};
    void setECEFVectorPositionYDesc(const QString& ECEFVectorPositionYDesc) {m_ECEFVectorPositionYDesc=ECEFVectorPositionYDesc;emit ECEFVectorPositionYDescChanged();};
    void setECEFVectorPositionZDesc(const QString& ECEFVectorPositionZDesc) {m_ECEFVectorPositionZDesc=ECEFVectorPositionZDesc;emit ECEFVectorPositionZDescChanged();};
    void setECEFVectorVelocityXDesc(const QString& ECEFVectorVelocityXDesc) {m_ECEFVectorVelocityXDesc=ECEFVectorVelocityXDesc;emit ECEFVectorVelocityXDescChanged();};
    void setECEFVectorVelocityYDesc(const QString& ECEFVectorVelocityYDesc) {m_ECEFVectorVelocityYDesc=ECEFVectorVelocityYDesc;emit ECEFVectorVelocityYDescChanged();};
    void setECEFVectorVelocityZDesc(const QString& ECEFVectorVelocityZDesc) {m_ECEFVectorVelocityZDesc=ECEFVectorVelocityZDesc;emit ECEFVectorVelocityZDescChanged();};
    void setRollAngleDesc(const QString& RollAngleDesc) {m_RollAngleDesc=RollAngleDesc;emit RollAngleDescChanged();};
    void setPitchAngleDesc(const QString& PitchAngleDesc) {m_PitchAngleDesc=PitchAngleDesc;emit PitchAngleDescChanged();};
    void setYawAngleDesc(const QString& YawAngleDesc) {m_YawAngleDesc=YawAngleDesc;emit YawAngleDescChanged();};
    void setAngularRateRollDesc(const QString& AngularRateRollDesc) {m_AngularRateRollDesc=AngularRateRollDesc;emit AngularRateRollDescChanged();};
    void setAngularRatePitchDesc(const QString& AngularRatePitchDesc) {m_AngularRatePitchDesc=AngularRatePitchDesc;emit AngularRatePitchDescChanged();};
    void setAngularRateYawDesc(const QString& AngularRateYawDesc) {m_AngularRateYawDesc=AngularRateYawDesc;emit AngularRateYawDescChanged();};
    void setQuaternion0Desc(const QString& Quaternion0Desc) {m_Quaternion0Desc=Quaternion0Desc;emit Quaternion0DescChanged();};
    void setQuaternion1Desc(const QString& Quaternion1Desc) {m_Quaternion1Desc=Quaternion1Desc;emit Quaternion1DescChanged();};
    void setQuaternion2Desc(const QString& Quaternion2Desc) {m_Quaternion2Desc=Quaternion2Desc;emit Quaternion2DescChanged();};
    void setQuaternion3Desc(const QString& Quaternion3Desc) {m_Quaternion3Desc=Quaternion3Desc;emit Quaternion3DescChanged();};
    void setNumberOfGPSSatelliteDesc(const QString& NumberOfGPSSatelliteDesc) {m_NumberOfGPSSatelliteDesc=NumberOfGPSSatelliteDesc;emit NumberOfGPSSatelliteDescChanged();};
    void setAnemCommErrorCounterDesc(const QString& AnemCommErrorCounterDesc) {m_AnemCommErrorCounterDesc=AnemCommErrorCounterDesc;emit AnemCommErrorCounterDescChanged();};
    void setRDAltCommErrorCounterDesc(const QString& RDAltCommErrorCounterDesc) {m_RDAltCommErrorCounterDesc=RDAltCommErrorCounterDesc;emit RDAltCommErrorCounterDescChanged();};
    void setGNSSCommErrorCounterDesc(const QString& GNSSCommErrorCounterDesc) {m_GNSSCommErrorCounterDesc=GNSSCommErrorCounterDesc;emit GNSSCommErrorCounterDescChanged();};
    void setPLAltCommErrorCounterDesc(const QString& PLAltCommErrorCounterDesc) {m_PLAltCommErrorCounterDesc=PLAltCommErrorCounterDesc;emit PLAltCommErrorCounterDescChanged();};

    void setMotorARealPositionDesc(const QString& MotorARealPositionDesc) {m_MotorARealPositionDesc=MotorARealPositionDesc;emit MotorARealPositionDescChanged();};
    void setMotorADemandPositionDesc(const QString& MotorADemandPositionDesc) {m_MotorADemandPositionDesc=MotorADemandPositionDesc;emit MotorADemandPositionDescChanged();};
    void setMotorATorqueDesc(const QString& MotorATorqueDesc) {m_MotorATorqueDesc=MotorATorqueDesc;emit MotorATorqueDescChanged();};
    void setMotorATempDesc(const QString& MotorATempDesc) {m_MotorATempDesc=MotorATempDesc;emit MotorATempDescChanged();};

    void setMotorBRealPositionDesc(const QString& MotorBRealPositionDesc) {m_MotorBRealPositionDesc=MotorBRealPositionDesc;emit MotorBRealPositionDescChanged();};
    void setMotorBDemandPositionDesc(const QString& MotorBDemandPositionDesc) {m_MotorBDemandPositionDesc=MotorBDemandPositionDesc;emit MotorBDemandPositionDescChanged();};
    void setMotorBTorqueDesc(const QString& MotorBTorqueDesc) {m_MotorBTorqueDesc=MotorBTorqueDesc;emit MotorBTorqueDescChanged();};
    void setMotorBTempDesc(const QString& MotorBTempDesc) {m_MotorBTempDesc=MotorBTempDesc;emit MotorBTempDescChanged();};

    void setBMSVoltageDesc(const QString& BMSVoltageDesc) {m_BMSVoltageDesc=BMSVoltageDesc;emit BMSVoltageDescChanged();};
    void setBMSAbsorptionDesc(const QString& BMSAbsorptionDesc) {m_BMSAbsorptionDesc=BMSAbsorptionDesc;emit BMSAbsorptionDescChanged();};
    void setBMSTempDesc(const QString& BMSTempDesc) {m_BMSTempDesc=BMSTempDesc;emit BMSTempDescChanged();};

    void setMotorAFaultsMaskDesc(const QString& MotorAFaultsMaskDesc) {m_MotorAFaultsMaskDesc=MotorAFaultsMaskDesc;emit MotorAFaultsMaskDescChanged();};
    void setMotorBFaultsMaskDesc(const QString& MotorBFaultsMaskDesc) {m_MotorBFaultsMaskDesc=MotorBFaultsMaskDesc;emit MotorBFaultsMaskDescChanged();};
    void setBMSFaultsMaskDesc(const QString& BMSFaultsMaskDesc) {m_BMSFaultsMaskDesc=BMSFaultsMaskDesc;emit BMSFaultsMaskDescChanged();};

    void setChargeValueDesc(const QString& ChargeValueDesc) {m_ChargeValueDesc=ChargeValueDesc;emit ChargeValueDescChanged();};

    void setFlightModeDesc(const QString& FlightModeDesc) {m_FlightModeDesc=FlightModeDesc;emit FlightModeDescChanged();};
    void setFlightPhaseDesc(const QString& FlightPhaseDesc) {m_FlightPhaseDesc=FlightPhaseDesc;emit FlightPhaseDescChanged();};
    void setFlightPhaseExecutionTimeDesc(const QString& FlightPhaseExecutionTimeDesc) {m_FlightPhaseExecutionTimeDesc=FlightPhaseExecutionTimeDesc;emit FlightPhaseExecutionTimeDescChanged();};

    void setcommunicationErrorCounterDesc(const QString& communicationErrorCounterDesc) {m_communicationErrorCounterDesc=communicationErrorCounterDesc;emit communicationErrorCounterDescChanged();};

    void setRSSIDesc(const QString& RSSIDesc) {m_RSSIDesc=RSSIDesc;emit RSSIDescChanged();};

    void setstorageFreeDataSizeDesc(const QString& storageFreeDataSizeDesc) {m_storageFreeDataSizeDesc=storageFreeDataSizeDesc;emit storageFreeDataSizeDescChanged();};


    /* TBD */
    void setGSRLErrorCounter(const quint8& GSRLErrorCounter) {m_GSRLErrorCounter=GSRLErrorCounter;emit GSRLErrorCounterChanged();};
    void setFSRLErrorCounter(const quint8& FSRLErrorCounter) {m_FSRLErrorCounter=FSRLErrorCounter;emit FSRLErrorCounterChanged();};
    void setRLHeartbeatCounter(const quint8& RLHeartbeatCounter) {m_RLHeartbeatCounter=RLHeartbeatCounter;emit RLHeartbeatCounterChanged();};
    void setgnssFound(const bool& gnssFound) {m_gnssFound=gnssFound;emit gnssFoundChanged();};






signals:

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
    void Quaternion0Changed();
    void Quaternion1Changed();
    void Quaternion2Changed();
    void Quaternion3Changed();
    void NumberOfGPSSatelliteChanged();
    void AnemCommErrorCounterChanged();
    void RDAltCommErrorCounterChanged();
    void GNSSCommErrorCounterChanged();
    void PLAltCommErrorCounterChanged();
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

    void telemetryMsgCounterChanged();

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

    void MotorAFaultsMaskChanged();
    void MotorBFaultsMaskChanged();
    void BMSFaultsMaskChanged();

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

    void motorAMask0Changed();
    void motorAMask1Changed();
    void motorAMask2Changed();
    void motorAMask3Changed();
    void motorAMask4Changed();
    void motorAMask5Changed();
    void motorAMask6Changed();
    void motorAMask7Changed();
    void motorAMask8Changed();
    void motorAMask9Changed();
    void motorAMask10Changed();
    void motorAMask11Changed();
    void motorAMask12Changed();
    void motorAMask13Changed();
    void motorAMask14Changed();
    void motorAMask15Changed();
    void motorAMask16Changed();
    void motorAMask17Changed();
    void motorAMask18Changed();
    void motorAMask19Changed();
    void motorAMask20Changed();
    void motorAMask21Changed();
    void motorAMask22Changed();
    void motorAMask23Changed();
    void motorAMask24Changed();
    void motorAMask25Changed();
    void motorAMask26Changed();
    void motorAMask27Changed();
    void motorAMask28Changed();
    void motorAMask29Changed();
    void motorAMask30Changed();
    void motorAMask31Changed();

    void motorBMask0Changed();
    void motorBMask1Changed();
    void motorBMask2Changed();
    void motorBMask3Changed();
    void motorBMask4Changed();
    void motorBMask5Changed();
    void motorBMask6Changed();
    void motorBMask7Changed();
    void motorBMask8Changed();
    void motorBMask9Changed();
    void motorBMask10Changed();
    void motorBMask11Changed();
    void motorBMask12Changed();
    void motorBMask13Changed();
    void motorBMask14Changed();
    void motorBMask15Changed();
    void motorBMask16Changed();
    void motorBMask17Changed();
    void motorBMask18Changed();
    void motorBMask19Changed();
    void motorBMask20Changed();
    void motorBMask21Changed();
    void motorBMask22Changed();
    void motorBMask23Changed();
    void motorBMask24Changed();
    void motorBMask25Changed();
    void motorBMask26Changed();
    void motorBMask27Changed();
    void motorBMask28Changed();
    void motorBMask29Changed();
    void motorBMask30Changed();
    void motorBMask31Changed();

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

    void motorMsgCounterChanged();

    /* SYSTEM */

    void FlightModeChanged();
    void FlightPhaseChanged();
    void FlightPhaseExecutionTimeChanged();
    void CoreModuleStatusMaskChanged();
    void TelemetryModuleStatusMaskChanged();
    void GuidanceModuleStatusMaskChanged();
    void StorageModuleStatusMaskChanged();
    void RadioLinkModuleStatusMaskChanged();
    void MotorControlStatusMaskChanged();

    void communicationErrorCounterChanged();
    void systemCoreMask0Changed();
    void systemCoreMask1Changed();
    void systemCoreMask2Changed();
    void systemCoreMask3Changed();
    void systemCoreMask4Changed();
    void systemCoreMask5Changed();
    void systemCoreMask6Changed();
    void systemCoreMask7Changed();
    void systemCoreMask8Changed();
    void systemCoreMask9Changed();
    void systemCoreMask10Changed();
    void systemCoreMask11Changed();
    void systemCoreMask12Changed();
    void systemCoreMask13Changed();
    void systemCoreMask14Changed();
    void systemCoreMask15Changed();
    void systemCoreMask16Changed();
    void systemCoreMask17Changed();
    void systemCoreMask18Changed();
    void systemCoreMask19Changed();
    void systemCoreMask20Changed();
    void systemCoreMask21Changed();
    void systemCoreMask22Changed();
    void systemCoreMask23Changed();
    void systemCoreMask24Changed();
    void systemCoreMask25Changed();
    void systemCoreMask26Changed();
    void systemCoreMask27Changed();
    void systemCoreMask28Changed();
    void systemCoreMask29Changed();
    void systemCoreMask30Changed();
    void systemCoreMask31Changed();

    void systemStorageMask0Changed();
    void systemStorageMask1Changed();
    void systemStorageMask2Changed();
    void systemStorageMask3Changed();
    void systemStorageMask4Changed();
    void systemStorageMask5Changed();
    void systemStorageMask6Changed();
    void systemStorageMask7Changed();
    void systemStorageMask8Changed();
    void systemStorageMask9Changed();
    void systemStorageMask10Changed();
    void systemStorageMask11Changed();
    void systemStorageMask12Changed();
    void systemStorageMask13Changed();
    void systemStorageMask14Changed();
    void systemStorageMask15Changed();
    void systemStorageMask16Changed();
    void systemStorageMask17Changed();
    void systemStorageMask18Changed();
    void systemStorageMask19Changed();
    void systemStorageMask20Changed();
    void systemStorageMask21Changed();
    void systemStorageMask22Changed();
    void systemStorageMask23Changed();
    void systemStorageMask24Changed();
    void systemStorageMask25Changed();
    void systemStorageMask26Changed();
    void systemStorageMask27Changed();
    void systemStorageMask28Changed();
    void systemStorageMask29Changed();
    void systemStorageMask30Changed();
    void systemStorageMask31Changed();

    void systemGuidanceMask0Changed();
    void systemGuidanceMask1Changed();
    void systemGuidanceMask2Changed();
    void systemGuidanceMask3Changed();
    void systemGuidanceMask4Changed();
    void systemGuidanceMask5Changed();
    void systemGuidanceMask6Changed();
    void systemGuidanceMask7Changed();
    void systemGuidanceMask8Changed();
    void systemGuidanceMask9Changed();
    void systemGuidanceMask10Changed();
    void systemGuidanceMask11Changed();
    void systemGuidanceMask12Changed();
    void systemGuidanceMask13Changed();
    void systemGuidanceMask14Changed();
    void systemGuidanceMask15Changed();
    void systemGuidanceMask16Changed();
    void systemGuidanceMask17Changed();
    void systemGuidanceMask18Changed();
    void systemGuidanceMask19Changed();
    void systemGuidanceMask20Changed();
    void systemGuidanceMask21Changed();
    void systemGuidanceMask22Changed();
    void systemGuidanceMask23Changed();
    void systemGuidanceMask24Changed();
    void systemGuidanceMask25Changed();
    void systemGuidanceMask26Changed();
    void systemGuidanceMask27Changed();
    void systemGuidanceMask28Changed();
    void systemGuidanceMask29Changed();
    void systemGuidanceMask30Changed();
    void systemGuidanceMask31Changed();

    void systemMotorControlMask0Changed();
    void systemMotorControlMask1Changed();
    void systemMotorControlMask2Changed();
    void systemMotorControlMask3Changed();
    void systemMotorControlMask4Changed();
    void systemMotorControlMask5Changed();
    void systemMotorControlMask6Changed();
    void systemMotorControlMask7Changed();
    void systemMotorControlMask8Changed();
    void systemMotorControlMask9Changed();
    void systemMotorControlMask10Changed();
    void systemMotorControlMask11Changed();
    void systemMotorControlMask12Changed();
    void systemMotorControlMask13Changed();
    void systemMotorControlMask14Changed();
    void systemMotorControlMask15Changed();
    void systemMotorControlMask16Changed();
    void systemMotorControlMask17Changed();
    void systemMotorControlMask18Changed();
    void systemMotorControlMask19Changed();
    void systemMotorControlMask20Changed();
    void systemMotorControlMask21Changed();
    void systemMotorControlMask22Changed();
    void systemMotorControlMask23Changed();
    void systemMotorControlMask24Changed();
    void systemMotorControlMask25Changed();
    void systemMotorControlMask26Changed();
    void systemMotorControlMask27Changed();
    void systemMotorControlMask28Changed();
    void systemMotorControlMask29Changed();
    void systemMotorControlMask30Changed();
    void systemMotorControlMask31Changed();


    void systemTelemetryMask0Changed();
    void systemTelemetryMask1Changed();
    void systemTelemetryMask2Changed();
    void systemTelemetryMask3Changed();
    void systemTelemetryMask4Changed();
    void systemTelemetryMask5Changed();
    void systemTelemetryMask6Changed();
    void systemTelemetryMask7Changed();
    void systemTelemetryMask8Changed();
    void systemTelemetryMask9Changed();
    void systemTelemetryMask10Changed();
    void systemTelemetryMask11Changed();
    void systemTelemetryMask12Changed();
    void systemTelemetryMask13Changed();
    void systemTelemetryMask14Changed();
    void systemTelemetryMask15Changed();
    void systemTelemetryMask16Changed();
    void systemTelemetryMask17Changed();
    void systemTelemetryMask18Changed();
    void systemTelemetryMask19Changed();
    void systemTelemetryMask20Changed();
    void systemTelemetryMask21Changed();
    void systemTelemetryMask22Changed();
    void systemTelemetryMask23Changed();
    void systemTelemetryMask24Changed();
    void systemTelemetryMask25Changed();
    void systemTelemetryMask26Changed();
    void systemTelemetryMask27Changed();
    void systemTelemetryMask28Changed();
    void systemTelemetryMask29Changed();
    void systemTelemetryMask30Changed();
    void systemTelemetryMask31Changed();
    void systemTelemetryMask32Changed();
    void systemTelemetryMask33Changed();
    void systemTelemetryMask34Changed();
    void systemTelemetryMask35Changed();
    void systemTelemetryMask36Changed();
    void systemTelemetryMask37Changed();
    void systemTelemetryMask38Changed();
    void systemTelemetryMask39Changed();
    void systemTelemetryMask40Changed();
    void systemTelemetryMask41Changed();
    void systemTelemetryMask42Changed();
    void systemTelemetryMask43Changed();
    void systemTelemetryMask44Changed();
    void systemTelemetryMask45Changed();
    void systemTelemetryMask46Changed();
    void systemTelemetryMask47Changed();
    void systemTelemetryMask48Changed();
    void systemTelemetryMask49Changed();
    void systemTelemetryMask50Changed();
    void systemTelemetryMask51Changed();
    void systemTelemetryMask52Changed();
    void systemTelemetryMask53Changed();
    void systemTelemetryMask54Changed();
    void systemTelemetryMask55Changed();
    void systemTelemetryMask56Changed();
    void systemTelemetryMask57Changed();
    void systemTelemetryMask58Changed();
    void systemTelemetryMask59Changed();
    void systemTelemetryMask60Changed();
    void systemTelemetryMask61Changed();
    void systemTelemetryMask62Changed();
    void systemTelemetryMask63Changed();

    void emergencyBoardStatus0Changed();
    void emergencyBoardStatus1Changed();
    void emergencyBoardStatus2Changed();
    void emergencyBoardStatus3Changed();
    void emergencyBoardStatus4Changed();
    void emergencyBoardStatus5Changed();
    void emergencyBoardStatus6Changed();
    void emergencyBoardStatus7Changed();
    void emergencyBoardStatus8Changed();
    void emergencyBoardStatus9Changed();
    void emergencyBoardStatus10Changed();
    void emergencyBoardStatus11Changed();
    void emergencyBoardStatus12Changed();
    void emergencyBoardStatus13Changed();
    void emergencyBoardStatus14Changed();
    void emergencyBoardStatus15Changed();

    void PSUStatus0Changed();
    void PSUStatus1Changed();
    void PSUStatus2Changed();
    void PSUStatus3Changed();
    void PSUStatus4Changed();
    void PSUStatus5Changed();
    void PSUStatus6Changed();
    void PSUStatus7Changed();
    void PSUStatus8Changed();
    void PSUStatus9Changed();
    void PSUStatus10Changed();
    void PSUStatus11Changed();
    void PSUStatus12Changed();
    void PSUStatus13Changed();
    void PSUStatus14Changed();
    void PSUStatus15Changed();

    void emergencyRadioLinkStatus0Changed();
    void emergencyRadioLinkStatus1Changed();
    void emergencyRadioLinkStatus2Changed();
    void emergencyRadioLinkStatus3Changed();
    void emergencyRadioLinkStatus4Changed();
    void emergencyRadioLinkStatus5Changed();
    void emergencyRadioLinkStatus6Changed();
    void emergencyRadioLinkStatus7Changed();

    void systemMsgCounterChanged();


    /* RADIOLINK */

    void RSSIChanged();
    void radiolinkErrorCounterChanged();
    void radiolinkMask0Changed();
    void radiolinkMask1Changed();
    void radiolinkMask2Changed();
    void radiolinkMask3Changed();
    void radiolinkMask4Changed();
    void radiolinkMask5Changed();
    void radiolinkMask6Changed();
    void radiolinkMask7Changed();
    void radiolinkMask8Changed();
    void radiolinkMask9Changed();
    void radiolinkMask10Changed();
    void radiolinkMask11Changed();
    void radiolinkMask12Changed();
    void radiolinkMask13Changed();
    void radiolinkMask14Changed();
    void radiolinkMask15Changed();
    void radiolinkMask16Changed();
    void radiolinkMask17Changed();
    void radiolinkMask18Changed();
    void radiolinkMask19Changed();
    void radiolinkMask20Changed();
    void radiolinkMask21Changed();
    void radiolinkMask22Changed();
    void radiolinkMask23Changed();
    void radiolinkMask24Changed();
    void radiolinkMask25Changed();
    void radiolinkMask26Changed();
    void radiolinkMask27Changed();
    void radiolinkMask28Changed();
    void radiolinkMask29Changed();
    void radiolinkMask30Changed();
    void radiolinkMask31Changed();

    void radiolinkMsgCounterChanged();


    /* GUIDANCE */

    void guidanceMask0Changed();
    void guidanceMask1Changed();
    void guidanceMask2Changed();
    void guidanceMask3Changed();
    void guidanceMask4Changed();
    void guidanceMask5Changed();
    void guidanceMask6Changed();
    void guidanceMask7Changed();
    void guidanceMask8Changed();
    void guidanceMask9Changed();
    void guidanceMask10Changed();
    void guidanceMask11Changed();
    void guidanceMask12Changed();
    void guidanceMask13Changed();
    void guidanceMask14Changed();
    void guidanceMask15Changed();
    void guidanceMask16Changed();
    void guidanceMask17Changed();
    void guidanceMask18Changed();
    void guidanceMask19Changed();
    void guidanceMask20Changed();
    void guidanceMask21Changed();
    void guidanceMask22Changed();
    void guidanceMask23Changed();
    void guidanceMask24Changed();
    void guidanceMask25Changed();
    void guidanceMask26Changed();
    void guidanceMask27Changed();
    void guidanceMask28Changed();
    void guidanceMask29Changed();
    void guidanceMask30Changed();
    void guidanceMask31Changed();

    void guidanceMsgCounterChanged();

    /* STORAGE */

    void storageFreeDataSizeChanged();
    void storage0Changed();
    void storage1Changed();
    void storage2Changed();
    void storage3Changed();
    void storage4Changed();
    void storage5Changed();
    void storage6Changed();
    void storage7Changed();
    void storage8Changed();
    void storage9Changed();
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
    void storage24Changed();
    void storage25Changed();
    void storage26Changed();
    void storage27Changed();
    void storage28Changed();
    void storage29Changed();
    void storage30Changed();
    void storage31Changed();

    void storageMsgCounterChanged();

    void msgTelemetryOldChanged();
    void msgGuidanceOldChanged();
    void msgStorageOldChanged();
    void msgSystemOldChanged();
    void msgRadioLinkOldChanged();
    void msgMotorOldChanged();


    /* DESC */
    void LatitudeDescChanged();
    void LongitudeDescChanged();
    void GNSSAltitudeDescChanged();

    void TimeStampDescChanged();
    void TimeStampRIODescChanged();

    void AirSpeed_UVectorDescChanged();
    void AirSpeed_VVectorDescChanged();
    void AirSpeed_WVectorDescChanged();
    void AirTemperatureDescChanged();
    void AltitudeFromRadarAltimeterDescChanged();
    void AltitudeFromPayloadAltimeterDescChanged();
    void LinearVelocityHorizontalDescChanged();
    void LinearVelocityVerticalDescChanged();
    void PositionAccuracyDescChanged();
    void SpeedAccuracyDescChanged();
    void LinearAccelerationXDescChanged();
    void LinearAccelerationYDescChanged();
    void LinearAccelerationZDescChanged();
    void ECEFVectorPositionXDescChanged();
    void ECEFVectorPositionYDescChanged();
    void ECEFVectorPositionZDescChanged();
    void ECEFVectorVelocityXDescChanged();
    void ECEFVectorVelocityYDescChanged();
    void ECEFVectorVelocityZDescChanged();
    void RollAngleDescChanged();
    void PitchAngleDescChanged();
    void YawAngleDescChanged();
    void AngularRateRollDescChanged();
    void AngularRatePitchDescChanged();
    void AngularRateYawDescChanged();
    void Quaternion0DescChanged();
    void Quaternion1DescChanged();
    void Quaternion2DescChanged();
    void Quaternion3DescChanged();
    void NumberOfGPSSatelliteDescChanged();
    void AnemCommErrorCounterDescChanged();
    void RDAltCommErrorCounterDescChanged();
    void GNSSCommErrorCounterDescChanged();
    void PLAltCommErrorCounterDescChanged();

    void MotorARealPositionDescChanged();
    void MotorADemandPositionDescChanged();
    void MotorATorqueDescChanged();
    void MotorATempDescChanged();

    void MotorBRealPositionDescChanged();
    void MotorBDemandPositionDescChanged();
    void MotorBTorqueDescChanged();
    void MotorBTempDescChanged();

    void BMSVoltageDescChanged();
    void BMSAbsorptionDescChanged();
    void BMSTempDescChanged();

    void MotorAFaultsMaskDescChanged();
    void MotorBFaultsMaskDescChanged();
    void BMSFaultsMaskDescChanged();

    void ChargeValueDescChanged();

    void FlightModeDescChanged();
    void FlightPhaseDescChanged();
    void FlightPhaseExecutionTimeDescChanged();

    void communicationErrorCounterDescChanged();

    void RSSIDescChanged();

    void storageFreeDataSizeDescChanged();


    /* TBD */
    void GSRLErrorCounterChanged();
    void FSRLErrorCounterChanged();
    void RLHeartbeatCounterChanged();
    void gnssFoundChanged();

private:
    uint8_t extractBits64(const std::bitset<64> the_bitset, size_t start_bit, size_t end_bit);
    uint8_t extractBits32(const std::bitset<32> the_bitset, size_t start_bit, size_t end_bit);
    uint8_t extractBits16(const std::bitset<16> the_bitset, size_t start_bit, size_t end_bit);
    uint8_t extractBits8(const std::bitset<8> the_bitset, size_t start_bit, size_t end_bit);

    void showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry);
    void showDataSystemStatus(const mavlink_system_status_pack_t msg_system_status);
    void showDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status);
    void showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status);
    void showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status);
    void showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status);

    void initValues();
    QString initDesc(const QString& str);
    void checkTelemetry();
    void checkGuidance();
    void checkSystem();
    void checkStorage();
    void checkMotor();
    void checkRadioLink();

    bool telemetryCheck {0};

    QTimer *timerTelemetry;
    QTimer *timerMotor;
    QTimer *timerGuidance;
    QTimer *timerRadioLink;
    QTimer *timerStorage;
    QTimer *timerSystem;

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
    double m_Quaternion0{};
    double m_Quaternion1{};
    double m_Quaternion2{};
    double m_Quaternion3{};
    quint8 m_NumberOfGPSSatellite{};
    quint8 m_AnemCommErrorCounter{};
    quint8 m_RDAltCommErrorCounter{};
    quint8 m_GNSSCommErrorCounter{};
    quint8 m_PLAltCommErrorCounter{};
    bool m_telemetry0{};
    bool m_telemetry1{};
    bool m_telemetry2{};
    bool m_telemetry3{};
    bool m_telemetry4{};
    bool m_telemetry5{};
    bool m_telemetry6{};
    bool m_telemetry7{};
    bool m_telemetry8{};
    bool m_telemetry9{};
    bool m_telemetry10{};
    bool m_telemetry11{};
    bool m_telemetry12{};
    bool m_telemetry13{};
    bool m_telemetry14{};
    bool m_telemetry15{};
    bool m_telemetry16{};
    bool m_telemetry17{};
    bool m_telemetry18{};
    bool m_telemetry19{};
    bool m_telemetry20{};
    bool m_telemetry21{};
    bool m_telemetry22{};
    bool m_telemetry23{};
    bool m_telemetry24{};
    bool m_telemetry25{};
    bool m_telemetry26{};
    bool m_telemetry27{};
    bool m_telemetry28{};
    bool m_telemetry29{};
    bool m_telemetry30{};
    bool m_telemetry31{};

    int m_telemetryMsgCounter{};

    /* MOTOR */


    qint32 m_MotorARealPosition{};
    qint32 m_MotorADemandPosition{};
    qint32 m_MotorATorque{};
    qint16 m_MotorATemp{};

    qint32 m_MotorBRealPosition{};
    qint32 m_MotorBDemandPosition{};
    qint32 m_MotorBTorque{};
    qint16 m_MotorBTemp{};

    quint16 m_BMSVoltage{};
    qint16 m_BMSAbsorption{};
    qint16 m_BMSTemp{};

    quint32 m_MotorAFaultsMask{};
    quint32 m_MotorBFaultsMask{};
    quint32 m_BMSFaultsMask{};

    quint8 m_ChargeValue{};

    bool m_motor0{};
    bool m_motor1{};
    bool m_motor2{};
    bool m_motor3{};
    bool m_motor4{};
    bool m_motor5{};
    bool m_motor6{};
    bool m_motor7{};
    bool m_motor8{};
    bool m_motor10{};
    bool m_motor11{};
    bool m_motor12{};
    bool m_motor13{};
    bool m_motor14{};
    bool m_motor15{};
    bool m_motor16{};
    bool m_motor17{};
    bool m_motor18{};
    bool m_motor19{};
    bool m_motor20{};
    bool m_motor21{};
    bool m_motor22{};
    bool m_motor23{};
    bool m_motor24{};

    bool m_motorAMask0{};
    bool m_motorAMask1{};
    bool m_motorAMask2{};
    bool m_motorAMask3{};
    bool m_motorAMask4{};
    bool m_motorAMask5{};
    bool m_motorAMask6{};
    bool m_motorAMask7{};
    bool m_motorAMask8{};
    bool m_motorAMask9{};
    bool m_motorAMask10{};
    bool m_motorAMask11{};
    bool m_motorAMask12{};
    bool m_motorAMask13{};
    bool m_motorAMask14{};
    bool m_motorAMask15{};
    bool m_motorAMask16{};
    bool m_motorAMask17{};
    bool m_motorAMask18{};
    bool m_motorAMask19{};
    bool m_motorAMask20{};
    bool m_motorAMask21{};
    bool m_motorAMask22{};
    bool m_motorAMask23{};
    bool m_motorAMask24{};
    bool m_motorAMask25{};
    bool m_motorAMask26{};
    bool m_motorAMask27{};
    bool m_motorAMask28{};
    bool m_motorAMask29{};
    bool m_motorAMask30{};
    bool m_motorAMask31{};

    bool m_motorBMask0{};
    bool m_motorBMask1{};
    bool m_motorBMask2{};
    bool m_motorBMask3{};
    bool m_motorBMask4{};
    bool m_motorBMask5{};
    bool m_motorBMask6{};
    bool m_motorBMask7{};
    bool m_motorBMask8{};
    bool m_motorBMask9{};
    bool m_motorBMask10{};
    bool m_motorBMask11{};
    bool m_motorBMask12{};
    bool m_motorBMask13{};
    bool m_motorBMask14{};
    bool m_motorBMask15{};
    bool m_motorBMask16{};
    bool m_motorBMask17{};
    bool m_motorBMask18{};
    bool m_motorBMask19{};
    bool m_motorBMask20{};
    bool m_motorBMask21{};
    bool m_motorBMask22{};
    bool m_motorBMask23{};
    bool m_motorBMask24{};
    bool m_motorBMask25{};
    bool m_motorBMask26{};
    bool m_motorBMask27{};
    bool m_motorBMask28{};
    bool m_motorBMask29{};
    bool m_motorBMask30{};
    bool m_motorBMask31{};

    bool m_BMS0{};
    bool m_BMS1{};
    bool m_BMS2{};
    bool m_BMS3{};
    bool m_BMS4{};
    bool m_BMS5{};
    bool m_BMS6{};
    bool m_BMS7{};
    bool m_BMS8{};
    bool m_BMS9{};
    bool m_BMS10{};
    bool m_BMS11{};
    bool m_BMS12{};
    bool m_BMS13{};
    bool m_BMS14{};
    bool m_BMS15{};
    bool m_BMS16{};
    bool m_BMS17{};
    bool m_BMS18{};
    bool m_BMS19{};
    bool m_BMS20{};
    bool m_BMS21{};
    bool m_BMS22{};
    bool m_BMS23{};
    bool m_BMS24{};
    bool m_BMS25{};
    bool m_BMS26{};
    bool m_BMS27{};
    bool m_BMS28{};
    bool m_BMS29{};
    bool m_BMS30{};
    bool m_BMS31{};

    int m_motorMsgCounter{};

    /* SYSTEM */

    quint8 m_FlightMode{};
    quint8 m_FlightPhase{};
    quint32 m_FlightPhaseExecutionTime{};
    quint32 m_CoreModuleStatusMask{};
    quint64 m_TelemetryModuleStatusMask{};
    quint32 m_GuidanceModuleStatusMask{};
    quint32 m_StorageModuleStatusMask{};
    quint32 m_RadioLinkModuleStatusMask{};
    quint32 m_MotorControlStatusMask{};

    quint8 m_communicationErrorCounter{};
    bool m_systemCoreMask0{};
    bool m_systemCoreMask1{};
    bool m_systemCoreMask2{};
    bool m_systemCoreMask3{};
    bool m_systemCoreMask4{};
    bool m_systemCoreMask5{};
    bool m_systemCoreMask6{};
    bool m_systemCoreMask7{};
    bool m_systemCoreMask8{};
    bool m_systemCoreMask9{};
    bool m_systemCoreMask10{};
    bool m_systemCoreMask11{};
    bool m_systemCoreMask12{};
    bool m_systemCoreMask13{};
    bool m_systemCoreMask14{};
    bool m_systemCoreMask15{};
    bool m_systemCoreMask16{};
    bool m_systemCoreMask17{};
    bool m_systemCoreMask18{};
    bool m_systemCoreMask19{};
    bool m_systemCoreMask20{};
    bool m_systemCoreMask21{};
    bool m_systemCoreMask22{};
    bool m_systemCoreMask23{};
    bool m_systemCoreMask24{};
    bool m_systemCoreMask25{};
    bool m_systemCoreMask26{};
    bool m_systemCoreMask27{};
    bool m_systemCoreMask28{};
    bool m_systemCoreMask29{};
    bool m_systemCoreMask30{};
    bool m_systemCoreMask31{};

    bool m_systemStorageMask0{};
    bool m_systemStorageMask1{};
    bool m_systemStorageMask2{};
    bool m_systemStorageMask3{};
    bool m_systemStorageMask4{};
    bool m_systemStorageMask5{};
    bool m_systemStorageMask6{};
    bool m_systemStorageMask7{};
    bool m_systemStorageMask8{};
    bool m_systemStorageMask9{};
    bool m_systemStorageMask10{};
    bool m_systemStorageMask11{};
    bool m_systemStorageMask12{};
    bool m_systemStorageMask13{};
    bool m_systemStorageMask14{};
    bool m_systemStorageMask15{};
    bool m_systemStorageMask16{};
    bool m_systemStorageMask17{};
    bool m_systemStorageMask18{};
    bool m_systemStorageMask19{};
    bool m_systemStorageMask20{};
    bool m_systemStorageMask21{};
    bool m_systemStorageMask22{};
    bool m_systemStorageMask23{};
    bool m_systemStorageMask24{};
    bool m_systemStorageMask25{};
    bool m_systemStorageMask26{};
    bool m_systemStorageMask27{};
    bool m_systemStorageMask28{};
    bool m_systemStorageMask29{};
    bool m_systemStorageMask30{};
    bool m_systemStorageMask31{};

    bool m_systemGuidanceMask0{};
    bool m_systemGuidanceMask1{};
    bool m_systemGuidanceMask2{};
    bool m_systemGuidanceMask3{};
    bool m_systemGuidanceMask4{};
    bool m_systemGuidanceMask5{};
    bool m_systemGuidanceMask6{};
    bool m_systemGuidanceMask7{};
    bool m_systemGuidanceMask8{};
    bool m_systemGuidanceMask9{};
    bool m_systemGuidanceMask10{};
    bool m_systemGuidanceMask11{};
    bool m_systemGuidanceMask12{};
    bool m_systemGuidanceMask13{};
    bool m_systemGuidanceMask14{};
    bool m_systemGuidanceMask15{};
    bool m_systemGuidanceMask16{};
    bool m_systemGuidanceMask17{};
    bool m_systemGuidanceMask18{};
    bool m_systemGuidanceMask19{};
    bool m_systemGuidanceMask20{};
    bool m_systemGuidanceMask21{};
    bool m_systemGuidanceMask22{};
    bool m_systemGuidanceMask23{};
    bool m_systemGuidanceMask24{};
    bool m_systemGuidanceMask25{};
    bool m_systemGuidanceMask26{};
    bool m_systemGuidanceMask27{};
    bool m_systemGuidanceMask28{};
    bool m_systemGuidanceMask29{};
    bool m_systemGuidanceMask30{};
    bool m_systemGuidanceMask31{};

    bool m_systemMotorControlMask0{};
    bool m_systemMotorControlMask1{};
    bool m_systemMotorControlMask2{};
    bool m_systemMotorControlMask3{};
    bool m_systemMotorControlMask4{};
    bool m_systemMotorControlMask5{};
    bool m_systemMotorControlMask6{};
    bool m_systemMotorControlMask7{};
    bool m_systemMotorControlMask8{};
    bool m_systemMotorControlMask9{};
    bool m_systemMotorControlMask10{};
    bool m_systemMotorControlMask11{};
    bool m_systemMotorControlMask12{};
    bool m_systemMotorControlMask13{};
    bool m_systemMotorControlMask14{};
    bool m_systemMotorControlMask15{};
    bool m_systemMotorControlMask16{};
    bool m_systemMotorControlMask17{};
    bool m_systemMotorControlMask18{};
    bool m_systemMotorControlMask19{};
    bool m_systemMotorControlMask20{};
    bool m_systemMotorControlMask21{};
    bool m_systemMotorControlMask22{};
    bool m_systemMotorControlMask23{};
    bool m_systemMotorControlMask24{};
    bool m_systemMotorControlMask25{};
    bool m_systemMotorControlMask26{};
    bool m_systemMotorControlMask27{};
    bool m_systemMotorControlMask28{};
    bool m_systemMotorControlMask29{};
    bool m_systemMotorControlMask30{};
    bool m_systemMotorControlMask31{};


    bool m_systemTelemetryMask0{};
    bool m_systemTelemetryMask1{};
    bool m_systemTelemetryMask2{};
    bool m_systemTelemetryMask3{};
    bool m_systemTelemetryMask4{};
    bool m_systemTelemetryMask5{};
    bool m_systemTelemetryMask6{};
    bool m_systemTelemetryMask7{};
    bool m_systemTelemetryMask8{};
    bool m_systemTelemetryMask9{};
    bool m_systemTelemetryMask10{};
    bool m_systemTelemetryMask11{};
    bool m_systemTelemetryMask12{};
    bool m_systemTelemetryMask13{};
    bool m_systemTelemetryMask14{};
    bool m_systemTelemetryMask15{};
    bool m_systemTelemetryMask16{};
    bool m_systemTelemetryMask17{};
    bool m_systemTelemetryMask18{};
    bool m_systemTelemetryMask19{};
    bool m_systemTelemetryMask20{};
    bool m_systemTelemetryMask21{};
    bool m_systemTelemetryMask22{};
    bool m_systemTelemetryMask23{};
    bool m_systemTelemetryMask24{};
    bool m_systemTelemetryMask25{};
    bool m_systemTelemetryMask26{};
    bool m_systemTelemetryMask27{};
    bool m_systemTelemetryMask28{};
    bool m_systemTelemetryMask29{};
    bool m_systemTelemetryMask30{};
    bool m_systemTelemetryMask31{};
    bool m_systemTelemetryMask32{};
    bool m_systemTelemetryMask33{};
    bool m_systemTelemetryMask34{};
    bool m_systemTelemetryMask35{};
    bool m_systemTelemetryMask36{};
    bool m_systemTelemetryMask37{};
    bool m_systemTelemetryMask38{};
    bool m_systemTelemetryMask39{};
    bool m_systemTelemetryMask40{};
    bool m_systemTelemetryMask41{};
    bool m_systemTelemetryMask42{};
    bool m_systemTelemetryMask43{};
    bool m_systemTelemetryMask44{};
    bool m_systemTelemetryMask45{};
    bool m_systemTelemetryMask46{};
    bool m_systemTelemetryMask47{};
    bool m_systemTelemetryMask48{};
    bool m_systemTelemetryMask49{};
    bool m_systemTelemetryMask50{};
    bool m_systemTelemetryMask51{};
    bool m_systemTelemetryMask52{};
    bool m_systemTelemetryMask53{};
    bool m_systemTelemetryMask54{};
    bool m_systemTelemetryMask55{};
    bool m_systemTelemetryMask56{};
    bool m_systemTelemetryMask57{};
    bool m_systemTelemetryMask58{};
    bool m_systemTelemetryMask59{};
    bool m_systemTelemetryMask60{};
    bool m_systemTelemetryMask61{};
    bool m_systemTelemetryMask62{};
    bool m_systemTelemetryMask63{};

    bool m_emergencyBoardStatus0{};
    bool m_emergencyBoardStatus1{};
    bool m_emergencyBoardStatus2{};
    bool m_emergencyBoardStatus3{};
    bool m_emergencyBoardStatus4{};
    bool m_emergencyBoardStatus5{};
    bool m_emergencyBoardStatus6{};
    bool m_emergencyBoardStatus7{};
    bool m_emergencyBoardStatus8{};
    bool m_emergencyBoardStatus9{};
    bool m_emergencyBoardStatus10{};
    bool m_emergencyBoardStatus11{};
    bool m_emergencyBoardStatus12{};
    bool m_emergencyBoardStatus13{};
    bool m_emergencyBoardStatus14{};
    bool m_emergencyBoardStatus15{};

    bool m_PSUStatus0{};
    bool m_PSUStatus1{};
    bool m_PSUStatus2{};
    bool m_PSUStatus3{};
    bool m_PSUStatus4{};
    bool m_PSUStatus5{};
    bool m_PSUStatus6{};
    bool m_PSUStatus7{};
    bool m_PSUStatus8{};
    bool m_PSUStatus9{};
    bool m_PSUStatus10{};
    bool m_PSUStatus11{};
    bool m_PSUStatus12{};
    bool m_PSUStatus13{};
    bool m_PSUStatus14{};
    bool m_PSUStatus15{};

    bool m_emergencyRadioLinkStatus0{};
    bool m_emergencyRadioLinkStatus1{};
    bool m_emergencyRadioLinkStatus2{};
    bool m_emergencyRadioLinkStatus3{};
    bool m_emergencyRadioLinkStatus4{};
    bool m_emergencyRadioLinkStatus5{};
    bool m_emergencyRadioLinkStatus6{};
    bool m_emergencyRadioLinkStatus7{};

    int m_systemMsgCounter{};


    /* RADIOLINK */

    quint16 m_RSSI{};
    quint8 m_radiolinkErrorCounter{};
    bool m_radiolinkMask0{};
    bool m_radiolinkMask1{};
    bool m_radiolinkMask2{};
    bool m_radiolinkMask3{};
    bool m_radiolinkMask4{};
    bool m_radiolinkMask5{};
    bool m_radiolinkMask6{};
    bool m_radiolinkMask7{};
    bool m_radiolinkMask8{};
    bool m_radiolinkMask9{};
    bool m_radiolinkMask10{};
    bool m_radiolinkMask11{};
    bool m_radiolinkMask12{};
    bool m_radiolinkMask13{};
    bool m_radiolinkMask14{};
    bool m_radiolinkMask15{};
    bool m_radiolinkMask16{};
    bool m_radiolinkMask17{};
    bool m_radiolinkMask18{};
    bool m_radiolinkMask19{};
    bool m_radiolinkMask20{};
    bool m_radiolinkMask21{};
    bool m_radiolinkMask22{};
    bool m_radiolinkMask23{};
    bool m_radiolinkMask24{};
    bool m_radiolinkMask25{};
    bool m_radiolinkMask26{};
    bool m_radiolinkMask27{};
    bool m_radiolinkMask28{};
    bool m_radiolinkMask29{};
    bool m_radiolinkMask30{};
    bool m_radiolinkMask31{};

    int m_radiolinkMsgCounter{};


    /* GUIDANCE */

    bool m_guidanceMask0{};
    bool m_guidanceMask1{};
    bool m_guidanceMask2{};
    bool m_guidanceMask3{};
    bool m_guidanceMask4{};
    bool m_guidanceMask5{};
    bool m_guidanceMask6{};
    bool m_guidanceMask7{};
    bool m_guidanceMask8{};
    bool m_guidanceMask9{};
    bool m_guidanceMask10{};
    bool m_guidanceMask11{};
    bool m_guidanceMask12{};
    bool m_guidanceMask13{};
    bool m_guidanceMask14{};
    bool m_guidanceMask15{};
    bool m_guidanceMask16{};
    bool m_guidanceMask17{};
    bool m_guidanceMask18{};
    bool m_guidanceMask19{};
    bool m_guidanceMask20{};
    bool m_guidanceMask21{};
    bool m_guidanceMask22{};
    bool m_guidanceMask23{};
    bool m_guidanceMask24{};
    bool m_guidanceMask25{};
    bool m_guidanceMask26{};
    bool m_guidanceMask27{};
    bool m_guidanceMask28{};
    bool m_guidanceMask29{};
    bool m_guidanceMask30{};
    bool m_guidanceMask31{};

    int m_guidanceMsgCounter{};

    /* STORAGE */

    quint32 m_storageFreeDataSize{};
    bool m_storage0{};
    bool m_storage1{};
    bool m_storage2{};
    bool m_storage3{};
    bool m_storage4{};
    bool m_storage5{};
    bool m_storage6{};
    bool m_storage7{};
    bool m_storage8{};
    bool m_storage9{};
    bool m_storage10{};
    bool m_storage11{};
    bool m_storage12{};
    bool m_storage13{};
    bool m_storage14{};
    bool m_storage15{};
    bool m_storage16{};
    bool m_storage17{};
    bool m_storage18{};
    bool m_storage19{};
    bool m_storage20{};
    bool m_storage21{};
    bool m_storage22{};
    bool m_storage23{};
    bool m_storage24{};
    bool m_storage25{};
    bool m_storage26{};
    bool m_storage27{};
    bool m_storage28{};
    bool m_storage29{};
    bool m_storage30{};
    bool m_storage31{};

    int m_storageMsgCounter{};

    bool m_msgTelemetryOld{};
    bool m_msgGuidanceOld{};
    bool m_msgStorageOld{};
    bool m_msgSystemOld{};
    bool m_msgRadioLinkOld{};
    bool m_msgMotorOld{};


    /* DESC */
    QString m_LatitudeDesc{};
    QString m_LongitudeDesc{};
    QString m_GNSSAltitudeDesc{};

    QString m_TimeStampDesc{};
    QString m_TimeStampRIODesc{};

    QString m_AirSpeed_UVectorDesc{};
    QString m_AirSpeed_VVectorDesc{};
    QString m_AirSpeed_WVectorDesc{};
    QString m_AirTemperatureDesc{};
    QString m_AltitudeFromRadarAltimeterDesc{};
    QString m_AltitudeFromPayloadAltimeterDesc{};
    QString m_LinearVelocityHorizontalDesc{};
    QString m_LinearVelocityVerticalDesc{};
    QString m_PositionAccuracyDesc{};
    QString m_SpeedAccuracyDesc{};
    QString m_LinearAccelerationXDesc{};
    QString m_LinearAccelerationYDesc{};
    QString m_LinearAccelerationZDesc{};
    QString m_ECEFVectorPositionXDesc{};
    QString m_ECEFVectorPositionYDesc{};
    QString m_ECEFVectorPositionZDesc{};
    QString m_ECEFVectorVelocityXDesc{};
    QString m_ECEFVectorVelocityYDesc{};
    QString m_ECEFVectorVelocityZDesc{};
    QString m_RollAngleDesc{};
    QString m_PitchAngleDesc{};
    QString m_YawAngleDesc{};
    QString m_AngularRateRollDesc{};
    QString m_AngularRatePitchDesc{};
    QString m_AngularRateYawDesc{};
    QString m_Quaternion0Desc{};
    QString m_Quaternion1Desc{};
    QString m_Quaternion2Desc{};
    QString m_Quaternion3Desc{};
    QString m_NumberOfGPSSatelliteDesc{};
    QString m_AnemCommErrorCounterDesc{};
    QString m_RDAltCommErrorCounterDesc{};
    QString m_GNSSCommErrorCounterDesc{};
    QString m_PLAltCommErrorCounterDesc{};

    QString m_MotorARealPositionDesc{};
    QString m_MotorADemandPositionDesc{};
    QString m_MotorATorqueDesc{};
    QString m_MotorATempDesc{};

    QString m_MotorBRealPositionDesc{};
    QString m_MotorBDemandPositionDesc{};
    QString m_MotorBTorqueDesc{};
    QString m_MotorBTempDesc{};

    QString m_BMSVoltageDesc{};
    QString m_BMSAbsorptionDesc{};
    QString m_BMSTempDesc{};

    QString m_MotorAFaultsMaskDesc{};
    QString m_MotorBFaultsMaskDesc{};
    QString m_BMSFaultsMaskDesc{};

    QString m_ChargeValueDesc{};

    QString m_FlightModeDesc{};
    QString m_FlightPhaseDesc{};
    QString m_FlightPhaseExecutionTimeDesc{};

    QString m_communicationErrorCounterDesc{};

    QString m_RSSIDesc{};

    QString m_storageFreeDataSizeDesc{};


    /* TBD */
    quint8 m_GSRLErrorCounter{};
    quint8 m_FSRLErrorCounter{};
    quint8 m_RLHeartbeatCounter{};
    bool m_gnssFound{};
};

#endif // HMI_H
