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
        fsParams.txtLatitude: hmi.Latitude
        fsParams.txtLongitude: hmi.Longitude
        fsParams.txtGNSSAltitude: hmi.GNSSAltitude
        fsParams.txtAirSpeed_UVector: hmi.AirSpeed_UVector

        fsParams.txtAirSpeed_VVector: hmi.AirSpeed_VVector
        fsParams.txtAirSpeed_WVector: hmi.AirSpeed_WVector
        fsParams.txtAirTemperature: hmi.AirTemperature
        fsParams.txtAltitudeFromRadarAltimeter: hmi.AltitudeFromRadarAltimeter
        fsParams.txtAltitudeFromPayloadAltimeter: hmi.AltitudeFromPayloadAltimeter
        fsParams.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal

        fsParams.txtLinearVelocityVertical: hmi.LinearVelocityVertical
        fsParams.txtPositionAccuracy: hmi.PositionAccuracy
        fsParams.txtSpeedAccuracy:hmi.SpeedAccuracy
        fsParams.txtLinearAccelerationX: hmi.LinearAccelerationX
        fsParams.txtLinearAccelerationY: hmi.LinearAccelerationY
        fsParams.txtLinearAccelerationZ: hmi.LinearAccelerationZ

        fsParams.txtECEFVectorPositionX: hmi.ECEFVectorPositionX
        fsParams.txtECEFVectorPositionY: hmi.ECEFVectorPositionY
        fsParams.txtECEFVectorPositionZ: hmi.ECEFVectorPositionZ
        fsParams.txtECEFVectorVelocityX: hmi.ECEFVectorVelocityX
        fsParams.txtECEFVectorVelocityY: hmi.ECEFVectorVelocityY
        fsParams.txtECEFVectorVelocityZ: hmi.ECEFVectorVelocityZ

        fsParams.txtRollAngle: hmi.RollAngle
        fsParams.txtPitchAngle: hmi.PitchAngle
        fsParams.txtYawAngle: hmi.YawAngle
        fsParams.txtAngularRateRoll: hmi.AngularRateRoll
        fsParams.txtAngularRatePitch: hmi.AngularRatePitch
        fsParams.txtAngularRateYaw: hmi.AngularRateYaw

        fsParams.txtQuaternion0: hmi.Quaternion0
        fsParams.txtQuaternion1: hmi.Quaternion1
        fsParams.txtQuaternion2: hmi.Quaternion2
        fsParams.txtQuaternion3: hmi.Quaternion3
        fsParams.txtTelemetryStatusMask: hmi.TelemetryStatusMask
        fsParams.txtNumberOfGPSSatellite: hmi.NumberOfGPSSatellite

        gsParams.txtTimeStamp: hmi.TimeStamp

        gsParams.txtLatitudeGPSData:  gpsData.latitude
        gsParams.txtLongitudeGPSData: gpsData.longitude
        gsParams.txtAltitudeGPSData:  gpsData.altitude
        gsParams.txtHasFix:           gpsData.hasFix
        gsParams.txtHourGPSData:      gpsData.hour
        gsParams.txtminuteGPSData:    gpsData.minute
        gsParams.txtsecondGPSData:    gpsData.second


    }
}

