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

        fsParams.telemetryTab.lit: hmi.telemetry0
                                   || hmi.telemetry31
                                   || hmi.telemetry30
                                   || hmi.telemetry29
                                   || hmi.telemetry28
                                   || hmi.telemetry27
                                   || hmi.telemetry26
                                   || hmi.telemetry25
                                   || hmi.telemetry24
                                   || hmi.telemetry23
                                   || hmi.telemetry22
                                   || hmi.telemetry21
                                   || hmi.telemetry20
                                   || hmi.telemetry19
                                   || hmi.telemetry18
                                   || hmi.telemetry17
                                   || hmi.telemetry16
                                   || hmi.telemetry15
                                   || hmi.telemetry14
                                   || hmi.telemetry13
                                   || hmi.telemetry12
                                   || hmi.telemetry11
                                   || hmi.telemetry10
                                   || hmi.telemetry9
                                   || hmi.telemetry8
                                   || hmi.telemetry7
                                   || hmi.telemetry6
                                   || hmi.telemetry5
                                   || hmi.telemetry4
                                   || hmi.telemetry3
                                   || hmi.telemetry2
                                   || hmi.telemetry1

        fsParams.storageTab.lit: hmi.storage0
                                 || hmi.storage23
                                 || hmi.storage22
                                 || hmi.storage21
                                 || hmi.storage20
                                 || hmi.storage19
                                 || hmi.storage18
                                 || hmi.storage17
                                 || hmi.storage16
                                 || hmi.storage15
                                 || hmi.storage14
                                 || hmi.storage13
                                 || hmi.storage12
                                 || hmi.storage11
                                 || hmi.storage10
                                 || hmi.storage9
                                 || hmi.storage8
                                 || hmi.storage7
                                 || hmi.storage6
                                 || hmi.storage5
                                 || hmi.storage4
                                 || hmi.storage3
                                 || hmi.storage2
                                 || hmi.storage1

        fsParams.motorsBMSTab.lit: hmi.BMS0
                                   || hmi.BMS31
                                   || hmi.BMS30
                                   || hmi.BMS29
                                   || hmi.BMS28
                                   || hmi.BMS27
                                   || hmi.BMS26
                                   || hmi.BMS25
                                   || hmi.BMS24
                                   || hmi.BMS23
                                   || hmi.BMS22
                                   || hmi.BMS21
                                   || hmi.BMS20
                                   || hmi.BMS19
                                   || hmi.BMS18
                                   || hmi.BMS17
                                   || hmi.BMS16
                                   || hmi.BMS15
                                   || hmi.BMS14
                                   || hmi.BMS13
                                   || hmi.BMS12
                                   || hmi.BMS11
                                   || hmi.BMS10
                                   || hmi.BMS9
                                   || hmi.BMS8
                                   || hmi.BMS7
                                   || hmi.BMS6
                                   || hmi.BMS5
                                   || hmi.BMS4
                                   || hmi.BMS3
                                   || hmi.BMS2
                                   || hmi.BMS1
                                   || hmi.motor23
                                   || hmi.motor22
                                   || hmi.motor21
                                   || hmi.motor15
                                   || hmi.motor14
                                   || hmi.motor13
                                   || hmi.motor12
                                   || hmi.motor9
                                   || hmi.motor8
                                   || hmi.motor7
                                   || hmi.motor6
                                   || hmi.motor5
                                   || hmi.motor4
                                   || hmi.motor3
                                   || hmi.motor2
                                   || hmi.motor1
                                   || hmi.motor0
        fsParams.coreTab.lit: hmi.core0
                              || hmi.core1
                              || hmi.core2
                              || hmi.core3
                              || hmi.core4
        fsParams.radioLinkTab.lit: hmi.radiolink0
                                   || hmi.radiolink1
                                   || hmi.radiolink2
                                   || hmi.radiolink3
                                   || hmi.radiolink8
                                   || hmi.radiolink9

        fsParams.radioLinkTab.txtRadioLinkErrorCounter: hmi.FSRLErrorCounter

        fsParams.txtTimeStampRIO: timestampToUTCDate(hmi.TimeStampRIO)
        fsParams.txtLatitude: hmi.Latitude.toFixed(7)
        fsParams.txtLongitude: hmi.Longitude.toFixed(7)
        fsParams.txtGNSSAltitude: hmi.GNSSAltitude.toFixed(3)

        fsParams.homeTab.txtLatitude: hmi.Latitude.toFixed(7)
        fsParams.homeTab.txtLongitude: hmi.Longitude.toFixed(7)
        fsParams.homeTab.txtGNSSAltitude: hmi.GNSSAltitude.toFixed(3)

        fsParams.txtAirSpeed_UVector: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.txtAirSpeed_VVector: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.txtAirSpeed_WVector: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.homeTab.txtAirSpeed_UVector: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.homeTab.txtAirSpeed_VVector: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.homeTab.txtAirSpeed_WVector: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.txtAirTemperature: hmi.AirTemperature.toFixed(2)

        fsParams.txtAltitudeFromRadarAltimeter: hmi.AltitudeFromRadarAltimeter.toFixed(2)
        fsParams.payloadDrawer.param1.value:hmi.AltitudeFromPayloadAltimeter.toFixed(2)
        //fsParams.txtAltitudeFromPayloadAltimeter: hmi.AltitudeFromPayloadAltimeter.toFixed(2)

        fsParams.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.txtLinearVelocityVertical: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.homeTab.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.homeTab.txtLinearVelocityVertical: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.txtPositionAccuracy: hmi.PositionAccuracy.toFixed(2)
        fsParams.txtSpeedAccuracy:hmi.SpeedAccuracy.toFixed(2)

        fsParams.linearAccDrawer.param1.value: hmi.LinearAccelerationX.toFixed(2)
        fsParams.linearAccDrawer.param2.value: hmi.LinearAccelerationY.toFixed(2)
        fsParams.linearAccDrawer.param3.value: hmi.LinearAccelerationZ.toFixed(2)
        //        fsParams.txtLinearAccelerationX: hmi.LinearAccelerationX.toFixed(2)
        //        fsParams.txtLinearAccelerationY: hmi.LinearAccelerationY.toFixed(2)
        //        fsParams.txtLinearAccelerationZ: hmi.LinearAccelerationZ.toFixed(2)

        fsParams.txtECEFVectorPositionX: hmi.ECEFVectorPositionX.toFixed(2)
        fsParams.txtECEFVectorPositionY: hmi.ECEFVectorPositionY.toFixed(2)
        fsParams.txtECEFVectorPositionZ: hmi.ECEFVectorPositionZ.toFixed(2)

        fsParams.ecefVelocityDrawer.param1.value: hmi.ECEFVectorVelocityX.toFixed(2)
        fsParams.ecefVelocityDrawer.param2.value: hmi.ECEFVectorVelocityY.toFixed(2)
        fsParams.ecefVelocityDrawer.param3.value: hmi.ECEFVectorVelocityZ.toFixed(2)

//        fsParams.txtECEFVectorVelocityX: hmi.ECEFVectorVelocityX.toFixed(2)
//        fsParams.txtECEFVectorVelocityY: hmi.ECEFVectorVelocityY.toFixed(2)
//        fsParams.txtECEFVectorVelocityZ: hmi.ECEFVectorVelocityZ.toFixed(2)

        fsParams.txtRollAngle: hmi.RollAngle.toFixed(2)
        fsParams.txtPitchAngle: hmi.PitchAngle.toFixed(2)
        fsParams.txtYawAngle: hmi.YawAngle.toFixed(2)

        fsParams.homeTab.txtRollAngle: hmi.RollAngle.toFixed(2)
        fsParams.homeTab.txtPitchAngle: hmi.PitchAngle.toFixed(2)
        fsParams.homeTab.txtYawAngle: hmi.YawAngle.toFixed(2)

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
        fsParams.txtMotorTimestamp: timestampToUTCDate(hmi.MotorTimestamp)
        fsParams.txtChargeValue: hmi.ChargeValue




        fsParams.telemetryLight0.up: hmi.telemetry0
        fsParams.telemetryStatusDrawer.light27.up: hmi.telemetry31
        fsParams.telemetryStatusDrawer.light26.up: hmi.telemetry30
        fsParams.telemetryStatusDrawer.light25.up: hmi.telemetry29
        fsParams.telemetryStatusDrawer.light24.up: hmi.telemetry28
        fsParams.telemetryStatusDrawer.light23.up: hmi.telemetry27
        fsParams.telemetryStatusDrawer.light22.up: hmi.telemetry26
        fsParams.telemetryStatusDrawer.light21.up: hmi.telemetry25
        fsParams.telemetryStatusDrawer.light20.up: hmi.telemetry24
        fsParams.telemetryStatusDrawer.light19.up: hmi.telemetry23
        fsParams.telemetryStatusDrawer.light18.up: hmi.telemetry22
        fsParams.telemetryStatusDrawer.light17.up: hmi.telemetry21
        fsParams.telemetryStatusDrawer.light16.up: hmi.telemetry20
        fsParams.telemetryStatusDrawer.light15.up: hmi.telemetry19
        fsParams.telemetryStatusDrawer.light14.up: hmi.telemetry18
        fsParams.telemetryStatusDrawer.light13.up: hmi.telemetry17
        fsParams.telemetryStatusDrawer.light12.up: hmi.telemetry16
        fsParams.telemetryStatusDrawer.light11.up: hmi.telemetry15
        fsParams.telemetryStatusDrawer.light10.up: hmi.telemetry14
        fsParams.telemetryStatusDrawer.light9.up: hmi.telemetry13
        fsParams.telemetryStatusDrawer.light8.up: hmi.telemetry12
        fsParams.telemetryStatusDrawer.light7.up: hmi.telemetry11
        fsParams.telemetryStatusDrawer.light6.up: hmi.telemetry10
        fsParams.telemetryStatusDrawer.light5.up: hmi.telemetry9
        fsParams.telemetryStatusDrawer.light4.up: hmi.telemetry8
        fsParams.telemetryStatusDrawer.light3.up: hmi.telemetry7
        fsParams.telemetryStatusDrawer.light2.up: hmi.telemetry6
        fsParams.telemetryStatusDrawer.light1.up: hmi.telemetry5
        fsParams.telemetryStatusDrawer.light0.up: hmi.telemetry4
        fsParams.telemetryLight3.up: hmi.telemetry3
        fsParams.telemetryLight2.up: hmi.telemetry2
        fsParams.telemetryLight1.up: hmi.telemetry1

        fsParams.storageDrawer.light0.up: hmi.storage0
        fsParams.storageDrawer.light23.up: hmi.storage23
        fsParams.storageDrawer.light22.up: hmi.storage22
        fsParams.storageDrawer.light21.up: hmi.storage21
        fsParams.storageDrawer.light20.up: hmi.storage20
        fsParams.storageDrawer.light19.up: hmi.storage19
        fsParams.storageDrawer.light18.up: hmi.storage18
        fsParams.storageDrawer.light17.up: hmi.storage17
        fsParams.storageDrawer.light16.up: hmi.storage16
        fsParams.storageDrawer.light15.up: hmi.storage15
        fsParams.storageDrawer.light14.up: hmi.storage14
        fsParams.storageDrawer.light13.up: hmi.storage13
        fsParams.storageDrawer.light12.up: hmi.storage12
        fsParams.storageDrawer.light11.up: hmi.storage11
        fsParams.storageDrawer.light10.up: hmi.storage10

        fsParams.storageDrawer.light8.up: hmi.storage8
        fsParams.storageDrawer.light7.up: hmi.storage7
        fsParams.storageDrawer.light6.up: hmi.storage6
        fsParams.storageDrawer.light5.up: hmi.storage5
        fsParams.storageDrawer.light4.up: hmi.storage4
        fsParams.storageDrawer.light3.up: hmi.storage3
        fsParams.storageDrawer.light2.up: hmi.storage2
        fsParams.storageDrawer.light1.up: hmi.storage1

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


        fsParams.motorLight23.up: hmi.motor23
        fsParams.motorLight22.up: hmi.motor22
        fsParams.motorLight21.up: hmi.motor21

        fsParams.motorLight15.up: hmi.motor15
        fsParams.motorLight14.up: hmi.motor14
        fsParams.motorLight13.up: hmi.motor13
        fsParams.motorLight12.up: hmi.motor12
        fsParams.generalMotorDrawer.light8.up: hmi.motor8
        fsParams.generalMotorDrawer.light7.up: hmi.motor7
        fsParams.generalMotorDrawer.light6.up: hmi.motor6
        fsParams.motorLight5.up: hmi.motor5
        fsParams.motorLight4.up: hmi.motor4
        fsParams.generalMotorDrawer.light3.up: hmi.motor3
        fsParams.generalMotorDrawer.light2.up: hmi.motor2
        fsParams.generalMotorDrawer.light1.up: hmi.motor1
        fsParams.generalMotorDrawer.light0.up: hmi.motor0
        map.latitude: gsParams.latitude
        map.longitude: gsParams.longitude

        //gsParams.gnssLight.up: hmi.gnssFound

        gsParams.txtTimeStamp: timestampToUTCDate(hmi.TimeStamp)

        gsParams.txtLatitudeGPSData:  gpsData.latitude.toFixed(7)
        gsParams.txtLongitudeGPSData: gpsData.longitude.toFixed(7)
        gsParams.txtAltitudeGPSData:  gpsData.altitude.toFixed(3)
        gsParams.txtHasFix:           gpsData.hasFix
        gsParams.txtHourGPSData:      gpsData.hour
        gsParams.txtminuteGPSData:    gpsData.minute
        gsParams.txtsecondGPSData:    gpsData.second

        gsParams.txtRLHeartbeatCounter: hmi.RLHeartbeatCounter
        gsParams.txtRadioLinkErrorCounter: hmi.GSRLErrorCounter


    }

    function timestampToUTCDate(number){
        var date = new Date(number);
        return date.toISOString();
    }
}

