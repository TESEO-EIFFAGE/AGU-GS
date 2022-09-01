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

        fsParams.txtQuaternion0: hmi.Quaternion0
        fsParams.txtQuaternion1: hmi.Quaternion1
        fsParams.txtQuaternion2: hmi.Quaternion2
        fsParams.txtQuaternion3: hmi.Quaternion3
        fsParams.txtNumberOfGPSSatellite: hmi.NumberOfGPSSatellite

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
        fsParams.storageLight9.up: hmi.storage9
        fsParams.storageLight8.up: hmi.storage8
        fsParams.storageLight7.up: hmi.storage7
        fsParams.storageLight6.up: hmi.storage6
        fsParams.storageLight5.up: hmi.storage5
        fsParams.storageLight4.up: hmi.storage4
        fsParams.storageLight3.up: hmi.storage3
        fsParams.storageLight2.up: hmi.storage2
        fsParams.storageLight1.up: hmi.storage1


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

