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
        fsParams.txtTelemetryStatusMask: hmi.TelemetryStatusMask
        fsParams.txtNumberOfGPSSatellite: hmi.NumberOfGPSSatellite

        gsParams.txtTimeStamp: hmi.TimeStamp

        gsParams.txtLatitudeGPSData:  gpsData.latitude.toFixed(7)
        gsParams.txtLongitudeGPSData: gpsData.longitude.toFixed(7)
        gsParams.txtAltitudeGPSData:  gpsData.altitude.toFixed(7)
        gsParams.txtHasFix:           gpsData.hasFix
        gsParams.txtHourGPSData:      gpsData.hour
        gsParams.txtminuteGPSData:    gpsData.minute
        gsParams.txtsecondGPSData:    gpsData.second


    }
}

