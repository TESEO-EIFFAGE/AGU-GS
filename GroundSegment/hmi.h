#ifndef HMI_H
#define HMI_H
//#include "mainwindow.h"
#include "mavlinkprotocol.h"
//#include "ui_mainwindow.h"
#include <QObject>
//#include "topdialog.h"

class HMI : public QObject
{
    Q_OBJECT
public:
    explicit HMI(QObject *parent = nullptr);
    //HMI(Ui::MainWindow *ui);
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
    Q_PROPERTY(int TelemetryStatusMask MEMBER m_TelemetryStatusMask NOTIFY TelemetryStatusMaskChanged)
    Q_PROPERTY(int NumberOfGPSSatellite MEMBER m_NumberOfGPSSatellite NOTIFY NumberOfGPSSatelliteChanged)

    //Ui::MainWindow myui;
    //TopDialog TopDialogWindow;

public slots:
    void showData(/*Telemetry *t*/);
    void showDataSystemStatus (SystemStatusPack *s);

//signals:
//    void clicked_HMI();
//private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

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

    void TelemetryStatusMaskChanged();

    void NumberOfGPSSatelliteChanged();

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
    uint64_t m_TelemetryStatusMask{};
    uint8_t m_NumberOfGPSSatellite{};
};

#endif // HMI_H
