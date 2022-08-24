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
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "GroundSegmentUI"

    Screen01 {
        id: mainScreen
        anchors.fill:parent

        params.txtTimeStamp: hmi.TimeStamp
        params.txtTimeStampRIO: hmi.TimeStampRIO
        params.txtLatitude: hmi.Latitude
        params.txtLongitude: hmi.Longitude
        params.txtGNSSAltitude: hmi.GNSSAltitude
        params.txtAirSpeed_UVector: hmi.AirSpeed_UVector

        params.txtAirSpeed_VVector: hmi.AirSpeed_VVector
        params.txtAirSpeed_WVector: hmi.AirSpeed_WVector
        params.txtAirTemperature: hmi.AirTemperature
        params.txtAltitudeFromRadarAltimeter: hmi.AltitudeFromRadarAltimeter
        params.txtAltitudeFromPayloadAltimeter: hmi.AltitudeFromPayloadAltimeter
        params.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal

        params.txtLinearVelocityVertical: hmi.LinearVelocityVertical
        params.txtPositionAccuracy: hmi.PositionAccuracy
        params.txtSpeedAccuracy:hmi.SpeedAccuracy
        params.txtLinearAccelerationX: hmi.LinearAccelerationX
        params.txtLinearAccelerationY: hmi.LinearAccelerationY
        params.txtLinearAccelerationZ: hmi.LinearAccelerationZ

        params.txtECEFVectorPositionX: hmi.ECEFVectorPositionX
        params.txtECEFVectorPositionY: hmi.ECEFVectorPositionY
        params.txtECEFVectorPositionZ: hmi.ECEFVectorPositionZ
        params.txtECEFVectorVelocityX: hmi.ECEFVectorVelocityX
        params.txtECEFVectorVelocityY: hmi.ECEFVectorVelocityY
        params.txtECEFVectorVelocityZ: hmi.ECEFVectorVelocityZ

        params.txtRollAngle: hmi.RollAngle
        params.txtPitchAngle: hmi.PitchAngle
        params.txtYawAngle: hmi.YawAngle
        params.txtAngularRateRoll: hmi.AngularRateRoll
        params.txtAngularRatePitch: hmi.AngularRatePitch
        params.txtAngularRateYaw: hmi.AngularRateYaw

        params.txtQuaternion0: hmi.Quaternion0
        params.txtQuaternion1: hmi.Quaternion1
        params.txtQuaternion2: hmi.Quaternion2
        params.txtQuaternion3: hmi.Quaternion3
        params.txtTelemetryStatusMask: hmi.TelemetryStatusMask
        params.txtNumberOfGPSSatellite: hmi.NumberOfGPSSatellite

        params.txtLatitudeGPSData:  gpsData.Latitude
        params.txtLongitudeGPSData: gpsData.Longitude
        params.txtAltitudeGPSData:  gpsData.Altitude
        params.txtHasFix:           gpsData.hasFix
        params.txtHourGPSData:      gpsData.hour
        params.txtminuteGPSData:    gpsData.minute
        params.txtsecondGPSData:    gpsData.second


    }
}

