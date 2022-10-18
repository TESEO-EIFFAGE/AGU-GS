#ifndef HMI_H
#define HMI_H
//#include "mavlinkprotocol.h"
#include <QObject>
#include <AGU_MAVLINK/mavlink.h>
#include <bitset>
#include "QQmlAutoPropertyHelpers.h"

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);


    /* TELEMETRY */

    QML_READONLY_AUTO_PROPERTY(quint64,TimeStamp)
    QML_READONLY_AUTO_PROPERTY(quint64,TimeStampRIO)
    QML_READONLY_AUTO_PROPERTY(qint32,Latitude)
    QML_READONLY_AUTO_PROPERTY(qint32,Longitude)
    QML_READONLY_AUTO_PROPERTY(quint32,GNSSAltitude)
    QML_READONLY_AUTO_PROPERTY(qint16,AirSpeed_UVector)
    QML_READONLY_AUTO_PROPERTY(qint16,AirSpeed_VVector)
    QML_READONLY_AUTO_PROPERTY(qint16,AirSpeed_WVector)
    QML_READONLY_AUTO_PROPERTY(qint16,AirTemperature)
    QML_READONLY_AUTO_PROPERTY(qint32,AltitudeFromRadarAltimeter)
    QML_READONLY_AUTO_PROPERTY(qint32,AltitudeFromPayloadAltimeter)
    QML_READONLY_AUTO_PROPERTY(quint16,LinearVelocityHorizontal)
    QML_READONLY_AUTO_PROPERTY(qint16,LinearVelocityVertical)
    QML_READONLY_AUTO_PROPERTY(quint16,PositionAccuracy)
    QML_READONLY_AUTO_PROPERTY(quint16,SpeedAccuracy)
    QML_READONLY_AUTO_PROPERTY(qint16,LinearAccelerationX)
    QML_READONLY_AUTO_PROPERTY(qint16,LinearAccelerationY)
    QML_READONLY_AUTO_PROPERTY(qint16,LinearAccelerationZ)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorPositionX)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorPositionY)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorPositionZ)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorVelocityX)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorVelocityY)
    QML_READONLY_AUTO_PROPERTY(float,ECEFVectorVelocityZ)
    QML_READONLY_AUTO_PROPERTY(qint16,RollAngle)
    QML_READONLY_AUTO_PROPERTY(qint16,PitchAngle)
    QML_READONLY_AUTO_PROPERTY(qint16,YawAngle)
    QML_READONLY_AUTO_PROPERTY(qint16,AngularRateRoll)
    QML_READONLY_AUTO_PROPERTY(qint16,AngularRatePitch)
    QML_READONLY_AUTO_PROPERTY(qint16,AngularRateYaw)
    QML_READONLY_AUTO_PROPERTY(double,Quaternion0)
    QML_READONLY_AUTO_PROPERTY(double,Quaternion1)
    QML_READONLY_AUTO_PROPERTY(double,Quaternion2)
    QML_READONLY_AUTO_PROPERTY(double,Quaternion3)
    QML_READONLY_AUTO_PROPERTY(quint8,NumberOfGPSSatellite)
    QML_READONLY_AUTO_PROPERTY(quint8,AnemCommErrorCounter)
    QML_READONLY_AUTO_PROPERTY(quint8,RDAltCommErrorCounter)
    QML_READONLY_AUTO_PROPERTY(quint8,GNSSCommErrorCounter)
    QML_READONLY_AUTO_PROPERTY(quint8,PLAltCommErrorCounter)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry0)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry1)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry2)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry3)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry4)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry5)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry6)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry7)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry8)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry9)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry10)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry11)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry12)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry13)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry14)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry15)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry16)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry17)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry18)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry19)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry20)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry21)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry22)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry23)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry24)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry25)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry26)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry27)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry28)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry29)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry30)
    QML_READONLY_AUTO_PROPERTY(bool,telemetry31)

    QML_READONLY_AUTO_PROPERTY(int,telemetryMsgCounter)

    /* MOTOR */


    QML_READONLY_AUTO_PROPERTY(qint32,MotorARealPosition)
    QML_READONLY_AUTO_PROPERTY(qint32,MotorADemandPosition)
    QML_READONLY_AUTO_PROPERTY(qint32,MotorATorque)
    QML_READONLY_AUTO_PROPERTY(qint16,MotorATemp)

    QML_READONLY_AUTO_PROPERTY(qint32,MotorBRealPosition)
    QML_READONLY_AUTO_PROPERTY(qint32,MotorBDemandPosition)
    QML_READONLY_AUTO_PROPERTY(qint32,MotorBTorque)
    QML_READONLY_AUTO_PROPERTY(qint16,MotorBTemp)

    QML_READONLY_AUTO_PROPERTY(quint16,BMSVoltage)
    QML_READONLY_AUTO_PROPERTY(qint16,BMSAbsorption)
    QML_READONLY_AUTO_PROPERTY(qint16,BMSTemp)

    QML_READONLY_AUTO_PROPERTY(quint32,MotorAFaultsMask)
    QML_READONLY_AUTO_PROPERTY(quint32,MotorBFaultsMask)
    QML_READONLY_AUTO_PROPERTY(quint32,BMSFaultsMask)

    QML_READONLY_AUTO_PROPERTY(quint8,ChargeValue)

    QML_READONLY_AUTO_PROPERTY(bool,motor0)
    QML_READONLY_AUTO_PROPERTY(bool,motor1)
    QML_READONLY_AUTO_PROPERTY(bool,motor2)
    QML_READONLY_AUTO_PROPERTY(bool,motor3)
    QML_READONLY_AUTO_PROPERTY(bool,motor4)
    QML_READONLY_AUTO_PROPERTY(bool,motor5)
    QML_READONLY_AUTO_PROPERTY(bool,motor6)
    QML_READONLY_AUTO_PROPERTY(bool,motor7)
    QML_READONLY_AUTO_PROPERTY(bool,motor8)
    QML_READONLY_AUTO_PROPERTY(bool,motor10)
    QML_READONLY_AUTO_PROPERTY(bool,motor11)
    QML_READONLY_AUTO_PROPERTY(bool,motor12)
    QML_READONLY_AUTO_PROPERTY(bool,motor13)
    QML_READONLY_AUTO_PROPERTY(bool,motor14)
    QML_READONLY_AUTO_PROPERTY(bool,motor15)
    QML_READONLY_AUTO_PROPERTY(bool,motor16)
    QML_READONLY_AUTO_PROPERTY(bool,motor17)
    QML_READONLY_AUTO_PROPERTY(bool,motor18)
    QML_READONLY_AUTO_PROPERTY(bool,motor19)
    QML_READONLY_AUTO_PROPERTY(bool,motor20)
    QML_READONLY_AUTO_PROPERTY(bool,motor21)
    QML_READONLY_AUTO_PROPERTY(bool,motor22)
    QML_READONLY_AUTO_PROPERTY(bool,motor23)
    QML_READONLY_AUTO_PROPERTY(bool,motor24)

    QML_READONLY_AUTO_PROPERTY(bool,motorAMask0);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask1);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask2);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask3);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask4);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask5);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask6);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask7);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask8);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask9);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask10);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask11);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask12);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask13);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask14);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask15);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask16);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask17);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask18);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask19);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask20);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask21);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask22);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask23);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask24);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask25);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask26);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask27);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask28);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask29);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask30);
    QML_READONLY_AUTO_PROPERTY(bool,motorAMask31);

    QML_READONLY_AUTO_PROPERTY(bool,motorBMask0);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask1);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask2);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask3);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask4);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask5);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask6);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask7);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask8);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask9);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask10);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask11);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask12);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask13);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask14);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask15);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask16);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask17);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask18);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask19);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask20);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask21);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask22);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask23);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask24);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask25);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask26);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask27);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask28);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask29);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask30);
    QML_READONLY_AUTO_PROPERTY(bool,motorBMask31)

    QML_READONLY_AUTO_PROPERTY(bool,BMS0)
    QML_READONLY_AUTO_PROPERTY(bool,BMS1)
    QML_READONLY_AUTO_PROPERTY(bool,BMS2)
    QML_READONLY_AUTO_PROPERTY(bool,BMS3)
    QML_READONLY_AUTO_PROPERTY(bool,BMS4)
    QML_READONLY_AUTO_PROPERTY(bool,BMS5)
    QML_READONLY_AUTO_PROPERTY(bool,BMS6)
    QML_READONLY_AUTO_PROPERTY(bool,BMS7)
    QML_READONLY_AUTO_PROPERTY(bool,BMS8)
    QML_READONLY_AUTO_PROPERTY(bool,BMS9)
    QML_READONLY_AUTO_PROPERTY(bool,BMS10)
    QML_READONLY_AUTO_PROPERTY(bool,BMS11)
    QML_READONLY_AUTO_PROPERTY(bool,BMS12)
    QML_READONLY_AUTO_PROPERTY(bool,BMS13)
    QML_READONLY_AUTO_PROPERTY(bool,BMS14)
    QML_READONLY_AUTO_PROPERTY(bool,BMS15)
    QML_READONLY_AUTO_PROPERTY(bool,BMS16)
    QML_READONLY_AUTO_PROPERTY(bool,BMS17)
    QML_READONLY_AUTO_PROPERTY(bool,BMS18)
    QML_READONLY_AUTO_PROPERTY(bool,BMS19)
    QML_READONLY_AUTO_PROPERTY(bool,BMS20)
    QML_READONLY_AUTO_PROPERTY(bool,BMS21)
    QML_READONLY_AUTO_PROPERTY(bool,BMS22)
    QML_READONLY_AUTO_PROPERTY(bool,BMS23)
    QML_READONLY_AUTO_PROPERTY(bool,BMS24)
    QML_READONLY_AUTO_PROPERTY(bool,BMS25)
    QML_READONLY_AUTO_PROPERTY(bool,BMS26)
    QML_READONLY_AUTO_PROPERTY(bool,BMS27)
    QML_READONLY_AUTO_PROPERTY(bool,BMS28)
    QML_READONLY_AUTO_PROPERTY(bool,BMS29)
    QML_READONLY_AUTO_PROPERTY(bool,BMS30)
    QML_READONLY_AUTO_PROPERTY(bool,BMS31)

    QML_READONLY_AUTO_PROPERTY(int,motorMsgCounter)

    /* SYSTEM */

    QML_READONLY_AUTO_PROPERTY(quint8,FlightMode)
    QML_READONLY_AUTO_PROPERTY(quint8,FlightPhase)
    QML_READONLY_AUTO_PROPERTY(quint32,FlightPhaseExecutionTime)
    QML_READONLY_AUTO_PROPERTY(quint32,CoreModuleStatusMask)
    QML_READONLY_AUTO_PROPERTY(quint64,TelemetryModuleStatusMask)
    QML_READONLY_AUTO_PROPERTY(quint32,GuidanceModuleStatusMask)
    QML_READONLY_AUTO_PROPERTY(quint32,StorageModuleStatusMask)
    QML_READONLY_AUTO_PROPERTY(quint32,RadioLinkModuleStatusMask)
    QML_READONLY_AUTO_PROPERTY(quint32,MotorControlStatusMask)

    QML_READONLY_AUTO_PROPERTY(quint8,communicationErrorCounter);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask0);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask1);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask2);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask3);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask4);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask5);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask6);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask7);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask8);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask9);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask10);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask11);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask12);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask13);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask14);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask15);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask16);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask17);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask18);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask19);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask20);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask21);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask22);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask23);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask24);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask25);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask26);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask27);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask28);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask29);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask30);
    QML_READONLY_AUTO_PROPERTY(bool,systemCoreMask31);

    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask0);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask1);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask2);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask3);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask4);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask5);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask6);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask7);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask8);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask9);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask10);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask11);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask12);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask13);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask14);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask15);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask16);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask17);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask18);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask19);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask20);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask21);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask22);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask23);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask24);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask25);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask26);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask27);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask28);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask29);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask30);
    QML_READONLY_AUTO_PROPERTY(bool,systemStorageMask31);

    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask0);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask1);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask2);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask3);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask4);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask5);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask6);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask7);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask8);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask9);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask10);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask11);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask12);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask13);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask14);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask15);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask16);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask17);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask18);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask19);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask20);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask21);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask22);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask23);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask24);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask25);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask26);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask27);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask28);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask29);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask30);
    QML_READONLY_AUTO_PROPERTY(bool,systemGuidanceMask31);

    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask0);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask1);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask2);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask3);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask4);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask5);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask6);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask7);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask8);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask9);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask10);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask11);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask12);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask13);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask14);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask15);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask16);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask17);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask18);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask19);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask20);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask21);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask22);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask23);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask24);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask25);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask26);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask27);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask28);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask29);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask30);
    QML_READONLY_AUTO_PROPERTY(bool,systemMotorControlMask31);


    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask0);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask1);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask2);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask3);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask4);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask5);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask6);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask7);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask8);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask9);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask10);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask11);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask12);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask13);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask14);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask15);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask16);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask17);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask18);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask19);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask20);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask21);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask22);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask23);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask24);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask25);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask26);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask27);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask28);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask29);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask30);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask31);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask32);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask33);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask34);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask35);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask36);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask37);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask38);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask39);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask40);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask41);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask42);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask43);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask44);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask45);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask46);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask47);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask48);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask49);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask50);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask51);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask52);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask53);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask54);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask55);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask56);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask57);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask58);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask59);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask60);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask61);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask62);
    QML_READONLY_AUTO_PROPERTY(bool,systemTelemetryMask63);

    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus0);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus1);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus2);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus3);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus4);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus5);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus6);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus7);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus8);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus9);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus10);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus11);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus12);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus13);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus14);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyBoardStatus15);

    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus0);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus1);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus2);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus3);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus4);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus5);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus6);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus7);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus8);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus9);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus10);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus11);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus12);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus13);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus14);
    QML_READONLY_AUTO_PROPERTY(bool,PSUStatus15);

    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus0);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus1);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus2);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus3);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus4);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus5);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus6);
    QML_READONLY_AUTO_PROPERTY(bool,emergencyRadioLinkStatus7);

    QML_READONLY_AUTO_PROPERTY(int,systemMsgCounter)


    /* RADIOLINK */

    QML_READONLY_AUTO_PROPERTY(quint16,RSSI);
    QML_READONLY_AUTO_PROPERTY(quint8,radiolinkErrorCounter);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask0);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask1);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask2);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask3);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask4);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask5);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask6);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask7);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask8);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask9);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask10);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask11);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask12);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask13);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask14);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask15);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask16);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask17);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask18);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask19);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask20);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask21);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask22);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask23);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask24);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask25);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask26);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask27);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask28);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask29);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask30);
    QML_READONLY_AUTO_PROPERTY(bool,radiolinkMask31);

    QML_READONLY_AUTO_PROPERTY(int,radiolinkMsgCounter)


    /* GUIDANCE */

    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask0);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask1);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask2);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask3);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask4);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask5);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask6);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask7);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask8);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask9);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask10);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask11);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask12);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask13);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask14);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask15);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask16);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask17);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask18);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask19);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask20);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask21);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask22);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask23);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask24);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask25);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask26);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask27);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask28);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask29);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask30);
    QML_READONLY_AUTO_PROPERTY(bool,guidanceMask31);

    QML_READONLY_AUTO_PROPERTY(int,guidanceMsgCounter)

    /* STORAGE */

    QML_READONLY_AUTO_PROPERTY(quint32,storageFreeDataSize);
    QML_READONLY_AUTO_PROPERTY(bool,storage0)
    QML_READONLY_AUTO_PROPERTY(bool,storage1)
    QML_READONLY_AUTO_PROPERTY(bool,storage2)
    QML_READONLY_AUTO_PROPERTY(bool,storage3)
    QML_READONLY_AUTO_PROPERTY(bool,storage4)
    QML_READONLY_AUTO_PROPERTY(bool,storage5)
    QML_READONLY_AUTO_PROPERTY(bool,storage6)
    QML_READONLY_AUTO_PROPERTY(bool,storage7)
    QML_READONLY_AUTO_PROPERTY(bool,storage8)
    QML_READONLY_AUTO_PROPERTY(bool,storage9)
    QML_READONLY_AUTO_PROPERTY(bool,storage10)
    QML_READONLY_AUTO_PROPERTY(bool,storage11)
    QML_READONLY_AUTO_PROPERTY(bool,storage12)
    QML_READONLY_AUTO_PROPERTY(bool,storage13)
    QML_READONLY_AUTO_PROPERTY(bool,storage14)
    QML_READONLY_AUTO_PROPERTY(bool,storage15)
    QML_READONLY_AUTO_PROPERTY(bool,storage16)
    QML_READONLY_AUTO_PROPERTY(bool,storage17)
    QML_READONLY_AUTO_PROPERTY(bool,storage18)
    QML_READONLY_AUTO_PROPERTY(bool,storage19)
    QML_READONLY_AUTO_PROPERTY(bool,storage20)
    QML_READONLY_AUTO_PROPERTY(bool,storage21)
    QML_READONLY_AUTO_PROPERTY(bool,storage22)
    QML_READONLY_AUTO_PROPERTY(bool,storage23)
    QML_READONLY_AUTO_PROPERTY(bool,storage24)
    QML_READONLY_AUTO_PROPERTY(bool,storage25)
    QML_READONLY_AUTO_PROPERTY(bool,storage26)
    QML_READONLY_AUTO_PROPERTY(bool,storage27)
    QML_READONLY_AUTO_PROPERTY(bool,storage28)
    QML_READONLY_AUTO_PROPERTY(bool,storage29)
    QML_READONLY_AUTO_PROPERTY(bool,storage30)
    QML_READONLY_AUTO_PROPERTY(bool,storage31)

    QML_READONLY_AUTO_PROPERTY(int,storageMsgCounter)

    /* TBD */

    QML_READONLY_AUTO_PROPERTY(quint8,GSRLErrorCounter)
    QML_READONLY_AUTO_PROPERTY(quint8,FSRLErrorCounter)
    QML_READONLY_AUTO_PROPERTY(quint8,RLHeartbeatCounter)
    QML_READONLY_AUTO_PROPERTY(bool,gnssFound)

public:

    void showData(QVariant data);

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

};

#endif // HMI_H
