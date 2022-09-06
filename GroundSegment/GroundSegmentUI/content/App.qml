/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Studio Components.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.15
import QtQuick.Window 2.15
import GroundSegmentUI 1.0

Window {
    //property
    width: Constants.width
    height: Constants.height

    visible: true
    title: "GroundSegmentUI"

    Screen01 {
        id: mainScreen
        anchors.fill:parent

        fsParams.txtTimeStampRIO: hmi.TimeStampRIO
        fsParams.txtLatitude: hmi.Latitude.toFixed(7)
        fsParams.txtLongitude: hmi.Longitude.toFixed(7)
        fsParams.txtGNSSAltitude: hmi.GNSSAltitude.toFixed(3)

        fsParams.txtAirSpeed_UVector: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.txtAirSpeed_VVector: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.txtAirSpeed_WVector: hmi.AirSpeed_WVector.toFixed(2)
        fsParams.txtAirTemperature: hmi.AirTemperature.toFixed(2)

        fsParams.txtAltitudeFromRadarAltimeter: hmi.AltitudeFromRadarAltimeter.toFixed(2)
        fsParams.txtAltitudeFromPayloadAltimeter: hmi.AltitudeFromPayloadAltimeter.toFixed(2)

        fsParams.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.txtLinearVelocityVertical: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.txtPositionAccuracy: hmi.PositionAccuracy.toFixed(2)
        fsParams.txtSpeedAccuracy:hmi.SpeedAccuracy.toFixed(2)

        fsParams.txtLinearAccelerationX: hmi.LinearAccelerationX.toFixed(2)
        fsParams.txtLinearAccelerationY: hmi.LinearAccelerationY.toFixed(2)
        fsParams.txtLinearAccelerationZ: hmi.LinearAccelerationZ.toFixed(2)

        fsParams.txtECEFVectorPositionX: hmi.ECEFVectorPositionX.toFixed(2)
        fsParams.txtECEFVectorPositionY: hmi.ECEFVectorPositionY.toFixed(2)
        fsParams.txtECEFVectorPositionZ: hmi.ECEFVectorPositionZ.toFixed(2)
        fsParams.txtECEFVectorVelocityX: hmi.ECEFVectorVelocityX.toFixed(2)
        fsParams.txtECEFVectorVelocityY: hmi.ECEFVectorVelocityY.toFixed(2)
        fsParams.txtECEFVectorVelocityZ: hmi.ECEFVectorVelocityZ.toFixed(2)

        fsParams.txtRollAngle: hmi.RollAngle.toFixed(2)
        fsParams.txtPitchAngle: hmi.PitchAngle.toFixed(2)
        fsParams.txtYawAngle: hmi.YawAngle.toFixed(2)
        fsParams.txtAngularRateRoll: hmi.AngularRateRoll.toFixed(2)
        fsParams.txtAngularRatePitch: hmi.AngularRatePitch.toFixed(2)
        fsParams.txtAngularRateYaw: hmi.AngularRateYaw.toFixed(2)

        fsParams.txtNumberOfGPSSatellite: hmi.NumberOfGPSSatellite

        fsParams.txtAnemCommErrorCounter: hmi.AnemCommErrorCounter
        fsParams.txtRDAltCommErrorCounter: hmi.RDAltCommErrorCounter
        fsParams.txtGNSSCommErrorCounter: hmi.GNSSCommErrorCounter
        fsParams.txtPLAltCommErrorCounter: hmi.PLAltCommErrorCounter

        fsParams.txtMotorARealPosition: hmi.MotorARealPosition
        fsParams.txtMotorADemandPosition: hmi.MotorADemandPosition
        fsParams.txtMotorATorque: hmi.MotorATorque
        fsParams.txtMotorATemp: hmi.MotorATemp


        fsParams.txtMotorBRealPosition: hmi.MotorBRealPosition
        fsParams.txtMotorBDemandPosition: hmi.MotorBDemandPosition
        fsParams.txtMotorBTorque: hmi.MotorBTorque
        fsParams.txtMotorBTemp: hmi.MotorBTemp


        fsParams.txtBMS1Voltage: hmi.BMS1Voltage
        fsParams.txtBMS1Absorption: hmi.BMS1Absorption
        fsParams.txtBMS1Temp: hmi.BMS1Temp
        fsParams.txtMotorTimestamp: hmi.MotorTimestamp
        fsParams.txtChargeValue: hmi.ChargeValue




        fsParams.telemetryLight0.up: hmi.telemetry0
        fsParams.telemetryLight31.up: hmi.telemetry31
        fsParams.telemetryLight30.up: hmi.telemetry30
        fsParams.telemetryLight29.up: hmi.telemetry29
        fsParams.telemetryLight28.up: hmi.telemetry28
        fsParams.telemetryLight27.up: hmi.telemetry27
        fsParams.telemetryLight26.up: hmi.telemetry26
        fsParams.telemetryLight25.up: hmi.telemetry25
        fsParams.telemetryLight24.up: hmi.telemetry24
        fsParams.telemetryLight23.up: hmi.telemetry23
        fsParams.telemetryLight22.up: hmi.telemetry22
        fsParams.telemetryLight21.up: hmi.telemetry21
        fsParams.telemetryLight20.up: hmi.telemetry20
        fsParams.telemetryLight19.up: hmi.telemetry19
        fsParams.telemetryLight18.up: hmi.telemetry18
        fsParams.telemetryLight17.up: hmi.telemetry17
        fsParams.telemetryLight16.up: hmi.telemetry16
        fsParams.telemetryLight15.up: hmi.telemetry15
        fsParams.telemetryLight14.up: hmi.telemetry14
        fsParams.telemetryLight13.up: hmi.telemetry13
        fsParams.telemetryLight12.up: hmi.telemetry12
        fsParams.telemetryLight11.up: hmi.telemetry11
        fsParams.telemetryLight10.up: hmi.telemetry10
        fsParams.telemetryLight9.up: hmi.telemetry9
        fsParams.telemetryLight8.up: hmi.telemetry8
        fsParams.telemetryLight7.up: hmi.telemetry7
        fsParams.telemetryLight6.up: hmi.telemetry6
        fsParams.telemetryLight5.up: hmi.telemetry5
        fsParams.telemetryLight4.up: hmi.telemetry4
        fsParams.telemetryLight3.up: hmi.telemetry3
        fsParams.telemetryLight2.up: hmi.telemetry2
        fsParams.telemetryLight1.up: hmi.telemetry1

        fsParams.storageLight0.up: hmi.storage0
        fsParams.storageLight23.up: hmi.storage23
        fsParams.storageLight22.up: hmi.storage22
        fsParams.storageLight21.up: hmi.storage21
        fsParams.storageLight20.up: hmi.storage20
        fsParams.storageLight19.up: hmi.storage19
        fsParams.storageLight18.up: hmi.storage18
        fsParams.storageLight17.up: hmi.storage17
        fsParams.storageLight16.up: hmi.storage16
        fsParams.storageLight15.up: hmi.storage15
        fsParams.storageLight14.up: hmi.storage14
        fsParams.storageLight13.up: hmi.storage13
        fsParams.storageLight12.up: hmi.storage12
        fsParams.storageLight11.up: hmi.storage11
        fsParams.storageLight10.up: hmi.storage10
        fsParams.storageLight8.up: hmi.storage8
        fsParams.storageLight7.up: hmi.storage7
        fsParams.storageLight6.up: hmi.storage6
        fsParams.storageLight5.up: hmi.storage5
        fsParams.storageLight4.up: hmi.storage4
        fsParams.storageLight3.up: hmi.storage3
        fsParams.storageLight2.up: hmi.storage2
        fsParams.storageLight1.up: hmi.storage1

        fsParams.bmsLight0.up: hmi.BMS0
        fsParams.bmsLight31.up: hmi.BMS31
        fsParams.bmsLight30.up: hmi.BMS30
        fsParams.bmsLight29.up: hmi.BMS29
        fsParams.bmsLight28.up: hmi.BMS28
        fsParams.bmsLight27.up: hmi.BMS27
        fsParams.bmsLight26.up: hmi.BMS26
        fsParams.bmsLight25.up: hmi.BMS25
        fsParams.bmsLight24.up: hmi.BMS24
        fsParams.bmsLight23.up: hmi.BMS23
        fsParams.bmsLight22.up: hmi.BMS22
        fsParams.bmsLight21.up: hmi.BMS21
        fsParams.bmsLight20.up: hmi.BMS20
        fsParams.bmsLight19.up: hmi.BMS19
        fsParams.bmsLight18.up: hmi.BMS18
        fsParams.bmsLight17.up: hmi.BMS17
        fsParams.bmsLight16.up: hmi.BMS16
        fsParams.bmsLight15.up: hmi.BMS15
        fsParams.bmsLight14.up: hmi.BMS14
        fsParams.bmsLight13.up: hmi.BMS13
        fsParams.bmsLight12.up: hmi.BMS12
        fsParams.bmsLight11.up: hmi.BMS11
        fsParams.bmsLight10.up: hmi.BMS10
        fsParams.bmsLight9.up: hmi.BMS9
        fsParams.bmsLight8.up: hmi.BMS8
        fsParams.bmsLight7.up: hmi.BMS7
        fsParams.bmsLight6.up: hmi.BMS6
        fsParams.bmsLight5.up: hmi.BMS5
        fsParams.bmsLight4.up: hmi.BMS4
        fsParams.bmsLight3.up: hmi.BMS3
        fsParams.bmsLight2.up: hmi.BMS2
        fsParams.bmsLight1.up: hmi.BMS1

        fsParams.motorLight0.up: hmi.motor0
        fsParams.motorLight25.up: hmi.motor25
        fsParams.motorLight24.up: hmi.motor24
        fsParams.motorLight23.up: hmi.motor23
        fsParams.motorLight22.up: hmi.motor22
        fsParams.motorLight21.up: hmi.motor21
        fsParams.motorLight20.up: hmi.motor20
        fsParams.motorLight19.up: hmi.motor19
        fsParams.motorLight18.up: hmi.motor18
        fsParams.motorLight17.up: hmi.motor17
        fsParams.motorLight16.up: hmi.motor16
        fsParams.motorLight15.up: hmi.motor15
        fsParams.motorLight14.up: hmi.motor14
        fsParams.motorLight13.up: hmi.motor13
        fsParams.motorLight12.up: hmi.motor12
        fsParams.motorLight11.up: hmi.motor11
        fsParams.motorLight10.up: hmi.motor10
        fsParams.motorLight8.up: hmi.motor8
        fsParams.motorLight7.up: hmi.motor7
        fsParams.motorLight6.up: hmi.motor6
        fsParams.motorLight5.up: hmi.motor5
        fsParams.motorLight4.up: hmi.motor4
        fsParams.motorLight3.up: hmi.motor3
        fsParams.motorLight2.up: hmi.motor2
        fsParams.motorLight1.up: hmi.motor1

        gsParams.gnssLight: hmi.gnssFound

        gsParams.txtTimeStamp: hmi.TimeStamp

        gsParams.txtLatitudeGPSData:  gpsData.latitude.toFixed(7)
        gsParams.txtLongitudeGPSData: gpsData.longitude.toFixed(7)
        gsParams.txtAltitudeGPSData:  gpsData.altitude.toFixed(3)
        gsParams.txtHasFix:           gpsData.hasFix
        gsParams.txtHourGPSData:      gpsData.hour
        gsParams.txtminuteGPSData:    gpsData.minute
        gsParams.txtsecondGPSData:    gpsData.second


    }
}

