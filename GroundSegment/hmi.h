#ifndef HMI_H
#define HMI_H
#include "mavlinkprotocol.h"
#include <QObject>

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);
    Q_PROPERTY(int TimeStamp MEMBER m_TimeStamp NOTIFY TimeStampChanged)
    Q_PROPERTY(int TimeStampRIO MEMBER m_TimeStampRIO NOTIFY TimeStampRIOChanged)
    Q_PROPERTY(int Latitude MEMBER m_Latitude NOTIFY LatitudeChanged)
    Q_PROPERTY(int Longitude MEMBER m_Longitude NOTIFY LongitudeChanged)
    Q_PROPERTY(int GNSSAltitude MEMBER m_GNSSAltitude NOTIFY GNSSAltitudeChanged)
    Q_PROPERTY(int AirSpeed_UVector MEMBER m_AirSpeed_UVector NOTIFY AirSpeed_UVectorChanged)
    Q_PROPERTY(int AirSpeed_VVector MEMBER m_AirSpeed_VVector NOTIFY AirSpeed_VVectorChanged)
    Q_PROPERTY(int AirSpeed_WVector MEMBER m_AirSpeed_WVector NOTIFY AirSpeed_WVectorChanged)
    Q_PROPERTY(int AirTemperature MEMBER m_AirTemperature NOTIFY AirTemperatureChanged)
    Q_PROPERTY(int AltitudeFromRadarAltimeter MEMBER m_AltitudeFromRadarAltimeter NOTIFY AltitudeFromRadarAltimeterChanged)
    Q_PROPERTY(int AltitudeFromPayloadAltimeter MEMBER m_AltitudeFromPayloadAltimeter NOTIFY AltitudeFromPayloadAltimeterChanged)
    Q_PROPERTY(int LinearVelocityHorizontal MEMBER m_LinearVelocityHorizontal NOTIFY LinearVelocityHorizontalChanged)
    Q_PROPERTY(int LinearVelocityVertical MEMBER m_LinearVelocityVertical NOTIFY LinearVelocityVerticalChanged)
    Q_PROPERTY(int PositionAccuracy MEMBER m_PositionAccuracy NOTIFY PositionAccuracyChanged)
    Q_PROPERTY(int SpeedAccuracy MEMBER m_SpeedAccuracy NOTIFY SpeedAccuracyChanged)
    Q_PROPERTY(int LinearAccelerationX MEMBER m_LinearAccelerationX NOTIFY LinearAccelerationXChanged)
    Q_PROPERTY(int LinearAccelerationY MEMBER m_LinearAccelerationY NOTIFY LinearAccelerationYChanged)
    Q_PROPERTY(int LinearAccelerationZ MEMBER m_LinearAccelerationZ NOTIFY LinearAccelerationZChanged)
    Q_PROPERTY(int ECEFVectorPositionX MEMBER m_ECEFVectorPositionX NOTIFY ECEFVectorPositionXChanged)
    Q_PROPERTY(int ECEFVectorPositionY MEMBER m_ECEFVectorPositionY NOTIFY ECEFVectorPositionYChanged)
    Q_PROPERTY(int ECEFVectorPositionZ MEMBER m_ECEFVectorPositionZ NOTIFY ECEFVectorPositionZChanged)
    Q_PROPERTY(int ECEFVectorVelocityX MEMBER m_ECEFVectorVelocityX NOTIFY ECEFVectorVelocityXChanged)
    Q_PROPERTY(int ECEFVectorVelocityY MEMBER m_ECEFVectorVelocityY NOTIFY ECEFVectorVelocityYChanged)
    Q_PROPERTY(int ECEFVectorVelocityZ MEMBER m_ECEFVectorVelocityZ NOTIFY ECEFVectorVelocityZChanged)
    Q_PROPERTY(int RollAngle MEMBER m_RollAngle NOTIFY RollAngleChanged)
    Q_PROPERTY(int PitchAngle MEMBER m_PitchAngle NOTIFY PitchAngleChanged)
    Q_PROPERTY(int YawAngle MEMBER m_YawAngle NOTIFY YawAngleChanged)
    Q_PROPERTY(int AngularRateRoll MEMBER m_AngularRateRoll NOTIFY AngularRateRollChanged)
    Q_PROPERTY(int AngularRatePitch MEMBER m_AngularRatePitch NOTIFY AngularRatePitchChanged)
    Q_PROPERTY(int AngularRateYaw MEMBER m_AngularRateYaw NOTIFY AngularRateYawChanged)
    Q_PROPERTY(double Quaternion0 MEMBER m_Quaternion0 NOTIFY Quaternion0Changed)
    Q_PROPERTY(double Quaternion1 MEMBER m_Quaternion1 NOTIFY Quaternion1Changed)
    Q_PROPERTY(double Quaternion2 MEMBER m_Quaternion2 NOTIFY Quaternion2Changed)
    Q_PROPERTY(double Quaternion3 MEMBER m_Quaternion3 NOTIFY Quaternion3Changed)
    Q_PROPERTY(int NumberOfGPSSatellite MEMBER m_NumberOfGPSSatellite NOTIFY NumberOfGPSSatelliteChanged)

    Q_PROPERTY(int AnemCommErrorCounter MEMBER m_AnemCommErrorCounter NOTIFY AnemCommErrorCounterChanged)
    Q_PROPERTY(int RDAltCommErrorCounter MEMBER m_RDAltCommErrorCounter NOTIFY RDAltCommErrorCounterChanged)
    Q_PROPERTY(int GNSSCommErrorCounter MEMBER m_GNSSCommErrorCounter NOTIFY GNSSCommErrorCounterChanged)
    Q_PROPERTY(int PLAltCommErrorCounter MEMBER m_PLAltCommErrorCounter NOTIFY PLAltCommErrorCounterChanged)


    Q_PROPERTY(int MotorARealPosition MEMBER m_MotorARealPosition NOTIFY MotorARealPositionChanged)
    Q_PROPERTY(int MotorADemandPosition MEMBER m_MotorADemandPosition NOTIFY MotorADemandPositionChanged)
    Q_PROPERTY(int MotorATorque MEMBER m_MotorATorque NOTIFY MotorATorqueChanged)
    Q_PROPERTY(int MotorATemp MEMBER m_MotorATemp NOTIFY MotorATempChanged)

    Q_PROPERTY(int MotorBRealPosition MEMBER m_MotorBRealPosition NOTIFY MotorBRealPositionChanged)
    Q_PROPERTY(int MotorBDemandPosition MEMBER m_MotorBDemandPosition NOTIFY MotorBDemandPositionChanged)
    Q_PROPERTY(int MotorBTorque MEMBER m_MotorBTorque NOTIFY MotorBTorqueChanged)
    Q_PROPERTY(int MotorBTemp MEMBER m_MotorBTemp NOTIFY MotorBTempChanged)

    Q_PROPERTY(int BMS1Voltage MEMBER m_BMS1Voltage NOTIFY BMS1VoltageChanged)
    Q_PROPERTY(int BMS1Absorption MEMBER m_BMS1Absorption NOTIFY BMS1AbsorptionChanged)
    Q_PROPERTY(int BMS1Temp MEMBER m_BMS1Temp NOTIFY BMS1TempChanged)
    Q_PROPERTY(int MotorTimestamp MEMBER m_MotorTimestamp NOTIFY MotorTimestampChanged)
    Q_PROPERTY(int ChargeValue MEMBER m_ChargeValue NOTIFY ChargeValueChanged)


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
    Q_PROPERTY(bool motor25 MEMBER m_motor25 NOTIFY motor25Changed)

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


public slots:
    void showData(/*Telemetry *t*/);
    void showDataSystemStatus (SystemStatusPack *s);

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

    void AnemCommErrorCounterChanged();

    void RDAltCommErrorCounterChanged();

    void GNSSCommErrorCounterChanged();

    void PLAltCommErrorCounterChanged();

    void motor25Changed();

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

    void MotorARealPositionChanged();

    void MotorADemandPositionChanged();

    void MotorATorqueChanged();

    void MotorATempChanged();

    void MotorBRealPositionChanged();

    void MotorBDemandPositionChanged();

    void MotorBTorqueChanged();

    void MotorBTempChanged();

    void BMS1VoltageChanged();

    void BMS1AbsorptionChanged();

    void BMS1TempChanged();

    void MotorTimestampChanged();

    void ChargeValueChanged();

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

private:

    uint64_t m_TimeStamp{};
    uint64_t m_TimeStampRIO{};
    uint32_t m_Latitude{};
    uint32_t m_Longitude{};
    uint32_t m_GNSSAltitude{};
    uint16_t m_AirSpeed_UVector{};
    uint16_t m_AirSpeed_VVector{};
    uint16_t m_AirSpeed_WVector{};
    uint16_t m_AirTemperature{};
    uint32_t m_AltitudeFromRadarAltimeter{};
    uint32_t m_AltitudeFromPayloadAltimeter{};
    uint16_t m_LinearVelocityHorizontal{};
    uint16_t m_LinearVelocityVertical{};
    uint16_t m_PositionAccuracy{};
    uint16_t m_SpeedAccuracy{};
    uint16_t m_LinearAccelerationX{};
    uint16_t m_LinearAccelerationY{};
    uint16_t m_LinearAccelerationZ{};
    uint32_t m_ECEFVectorPositionX{};
    uint32_t m_ECEFVectorPositionY{};
    uint32_t m_ECEFVectorPositionZ{};
    uint32_t m_ECEFVectorVelocityX{};
    uint32_t m_ECEFVectorVelocityY{};
    uint32_t m_ECEFVectorVelocityZ{};
    uint16_t m_RollAngle{};
    uint16_t m_PitchAngle{};
    uint16_t m_YawAngle{};
    uint16_t m_AngularRateRoll{};
    uint16_t m_AngularRatePitch{};
    uint16_t m_AngularRateYaw{};
    float m_Quaternion0{};
    float m_Quaternion1{};
    float m_Quaternion2{};
    float m_Quaternion3{};
    uint8_t m_NumberOfGPSSatellite{};

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

    int m_AnemCommErrorCounter;
    int m_RDAltCommErrorCounter;
    int m_GNSSCommErrorCounter;
    int m_PLAltCommErrorCounter;

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
    bool m_motor25;

    int m_MotorARealPosition;
    int m_MotorADemandPosition;
    int m_MotorATorque;
    int m_MotorATemp;
    int m_MotorBRealPosition;
    int m_MotorBDemandPosition;
    int m_MotorBTorque;
    int m_MotorBTemp;
    int m_BMS1Voltage;
    int m_BMS1Absorption;
    int m_BMS1Temp;
    int m_MotorTimestamp;
    int m_ChargeValue;

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
};

#endif // HMI_H
