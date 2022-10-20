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
    width: Constants.width
    height: Constants.height

    visible: true
    title: "GroundSegmentUI"


    Screen01 {
        id: mainScreen
        fsParams.onTelemetryTabClicked: {
            timer.counter=0
            timer.restart()
        }
        fsParams.onMotorsBMSTabClicked: {
            timer.counter=0
            timer.restart()
        }
        fsParams.onStorageTabClicked:{
            timer.counter=0
            timer.restart()
        }
        fsParams.onGuidanceTabClicked: {
            timer.counter=0
            timer.restart()
        }
        fsParams.onCoreTabClicked: {
            timer.counter=0
            timer.restart()
        }
        fsParams.onRadioLinkTabClicked: {
            timer.counter=0
            timer.restart()
        }
        anchors.fill:parent
        Timer{
            id:timer
            property int counter : 0
            running:true
            repeat: true
            interval:1200
            onTriggered: {
                counter += 1;
                if(counter==10){
                    mainScreen.tabIndex=0;
                    counter=0;

                }
                
            }

        }

        fsParams.telemetryTabLight.color: hmi.msgTelemetryOld ? "#b1b1b1" : (telemetryTab.lit ? "#ff0000" : "#00ff00")
        fsParams.storageTabLight.color: hmi.msgStorageOld ? "#b1b1b1" : (storageTab.lit ? "#ff0000" : "#00ff00")
        fsParams.motorsBMSTabLight.color: hmi.msgMotorOld ? "#b1b1b1" : (motorsBMSTab.lit ? "#ff0000" : "#00ff00")
        fsParams.coreTabLight.color: hmi.msgSystemOld ? "#b1b1b1" : (coreTab.lit ? "#ff0000" : "#00ff00")
        fsParams.radioLinkTabLight.color: hmi.msgRadioLinkOld ? "#b1b1b1" : (radioLinkTab.lit ? "#ff0000" : "#00ff00")
        fsParams.guidanceTabLight.color: hmi.msgGuidanceOld ? "#b1b1b1" : (guidanceTab.lit ? "#ff0000" : "#00ff00")

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
        fsParams.coreTab.lit: hmi.systemCoreMask0
                              || hmi.systemCoreMask1
                              || hmi.systemCoreMask2
                              || hmi.systemCoreMask3
                              || hmi.systemCoreMask4
                              || hmi.systemCoreMask15
                              || hmi.systemCoreMask14
                              || hmi.systemCoreMask13
                              || hmi.systemCoreMask12
                              || hmi.systemCoreMask11
                              || hmi.systemCoreMask10
                              || hmi.systemCoreMask9
                              || hmi.systemCoreMask8
                              || hmi.systemCoreMask7
                              || hmi.systemCoreMask6
                              || hmi.systemCoreMask5

        fsParams.radioLinkTab.lit: hmi.radiolinkMask0
                                   || hmi.radiolinkMask1
                                   || hmi.radiolinkMask2
                                   || hmi.radiolinkMask3
                                   || hmi.radiolinkMask8
                                   || hmi.radiolinkMask9


        fsParams.txtTelemetryMsgCounter: hmi.telemetryMsgCounter
        fsParams.txtStorageMsgCounter: hmi.storageMsgCounter
        fsParams.txtSystemMsgCounter: hmi.systemMsgCounter
        //fsParams.txtGuidanceMsgCounter: hmi.guidanceMsgCounter
        fsParams.txtRadioLinkMsgCounter: hmi.radiolinkMsgCounter
        fsParams.txtMotorMsgCounter: hmi.motorMsgCounter

        fsParams.txtTimeStampRIO: timestampToUTCDate(hmi.TimeStampRIO)
        fsParams.txtLatitude: hmi.Latitude.toFixed(2)
        fsParams.txtLongitude: hmi.Longitude.toFixed(2)
        fsParams.txtGNSSAltitude: hmi.GNSSAltitude.toFixed(3)

        fsParams.homeTab.txtLatitude: hmi.Latitude.toFixed(2)
        fsParams.homeTab.txtLongitude: hmi.Longitude.toFixed(2)
        fsParams.homeTab.txtGNSSAltitude: hmi.GNSSAltitude.toFixed(3)

        fsParams.txtAirSpeed_UVector: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.txtAirSpeed_VVector: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.txtAirSpeed_WVector: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.homeTab.txtAirSpeed_UVector: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.homeTab.txtAirSpeed_VVector: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.homeTab.txtAirSpeed_WVector: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.txtAirTemperature: hmi.AirTemperature.toFixed(2)

        fsParams.txtAltitudeFromRadarAltimeter: hmi.AltitudeFromRadarAltimeter.toFixed(2)
        fsParams.txtAltitudeFromPayloadAltimeter: hmi.AltitudeFromPayloadAltimeter.toFixed(2)

        fsParams.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.txtLinearVelocityVertical: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.homeTab.txtLinearVelocityHorizontal: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.homeTab.txtLinearVelocityVertical: hmi.LinearVelocityVertical.toFixed(2)

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

        fsParams.txtMotorARealPosition: hmi.MotorARealPosition.toFixed(3)
        fsParams.txtMotorADemandPosition: hmi.MotorADemandPosition.toFixed(3)
        fsParams.txtMotorATorque: hmi.MotorATorque.toFixed(2)
        fsParams.txtMotorATemp: hmi.MotorATemp.toFixed(2)

        fsParams.txtMotorBRealPosition: hmi.MotorBRealPosition.toFixed(3)
        fsParams.txtMotorBDemandPosition: hmi.MotorBDemandPosition.toFixed(3)
        fsParams.txtMotorBTorque: hmi.MotorBTorque.toFixed(2)
        fsParams.txtMotorBTemp: hmi.MotorBTemp.toFixed(2)

        fsParams.txtBMS1Voltage: hmi.BMSVoltage.toFixed(2)
        fsParams.txtBMS1Absorption: hmi.BMSAbsorption.toFixed(2)
        fsParams.txtBMS1Temp: hmi.BMSTemp.toFixed(2)
        fsParams.txtChargeValue: hmi.ChargeValue

        fsParams.telemetryLight0.state: hmi.msgTelemetryOld ? "" : hmi.telemetry0
        fsParams.telemetryLight31.state: hmi.msgTelemetryOld ? "" : hmi.telemetry31
        fsParams.telemetryLight30.state: hmi.msgTelemetryOld ? "" : hmi.telemetry30
        fsParams.telemetryLight29.state: hmi.msgTelemetryOld ? "" : hmi.telemetry29
        fsParams.telemetryLight28.state: hmi.msgTelemetryOld ? "" : hmi.telemetry28
        fsParams.telemetryLight27.state: hmi.msgTelemetryOld ? "" : hmi.telemetry27
        fsParams.telemetryLight26.state: hmi.msgTelemetryOld ? "" : hmi.telemetry26
        fsParams.telemetryLight25.state: hmi.msgTelemetryOld ? "" : hmi.telemetry25
        fsParams.telemetryLight24.state: hmi.msgTelemetryOld ? "" : hmi.telemetry24
        fsParams.telemetryLight23.state: hmi.msgTelemetryOld ? "" : hmi.telemetry23
        fsParams.telemetryLight22.state: hmi.msgTelemetryOld ? "" : hmi.telemetry22
        fsParams.telemetryLight21.state: hmi.msgTelemetryOld ? "" : hmi.telemetry21
        fsParams.telemetryLight20.state: hmi.msgTelemetryOld ? "" : hmi.telemetry20
        fsParams.telemetryLight19.state: hmi.msgTelemetryOld ? "" : hmi.telemetry19
        fsParams.telemetryLight18.state: hmi.msgTelemetryOld ? "" : hmi.telemetry18
        fsParams.telemetryLight17.state: hmi.msgTelemetryOld ? "" : hmi.telemetry17
        fsParams.telemetryLight16.state: hmi.msgTelemetryOld ? "" : hmi.telemetry16
        fsParams.telemetryLight15.state: hmi.msgTelemetryOld ? "" : hmi.telemetry15
        fsParams.telemetryLight14.state: hmi.msgTelemetryOld ? "" : hmi.telemetry14
        fsParams.telemetryLight13.state: hmi.msgTelemetryOld ? "" : hmi.telemetry13
        fsParams.telemetryLight12.state: hmi.msgTelemetryOld ? "" : hmi.telemetry12
        fsParams.telemetryLight11.state: hmi.msgTelemetryOld ? "" : hmi.telemetry11
        fsParams.telemetryLight10.state: hmi.msgTelemetryOld ? "" : hmi.telemetry10
        fsParams.telemetryLight9.state: hmi.msgTelemetryOld ? "" : hmi.telemetry9
        fsParams.telemetryLight8.state: hmi.msgTelemetryOld ? "" : hmi.telemetry8
        fsParams.telemetryLight7.state: hmi.msgTelemetryOld ? "" : hmi.telemetry7
        fsParams.telemetryLight6.state: hmi.msgTelemetryOld ? "" : hmi.telemetry6
        fsParams.telemetryLight5.state: hmi.msgTelemetryOld ? "" : hmi.telemetry5
        fsParams.telemetryLight4.state: hmi.msgTelemetryOld ? "" : hmi.telemetry4
        fsParams.telemetryLight3.state: hmi.msgTelemetryOld ? "" : hmi.telemetry3
        fsParams.telemetryLight2.state: hmi.msgTelemetryOld ? "" : hmi.telemetry2
        fsParams.telemetryLight1.state: hmi.msgTelemetryOld ? "" : hmi.telemetry1

        fsParams.storageLight0.state: hmi.msgStorageOld ? "" : hmi.storage0
        fsParams.storageLight23.state: hmi.msgStorageOld ? "" : hmi.storage23
        fsParams.storageLight22.state: hmi.msgStorageOld ? "" : hmi.storage22
        fsParams.storageLight21.state: hmi.msgStorageOld ? "" : hmi.storage21
        fsParams.storageLight20.state: hmi.msgStorageOld ? "" : hmi.storage20
        fsParams.storageLight19.state: hmi.msgStorageOld ? "" : hmi.storage19
        fsParams.storageLight18.state: hmi.msgStorageOld ? "" : hmi.storage18
        fsParams.storageLight17.state: hmi.msgStorageOld ? "" : hmi.storage17
        fsParams.storageLight16.state: hmi.msgStorageOld ? "" : hmi.storage16
        fsParams.storageLight15.state: hmi.msgStorageOld ? "" : hmi.storage15
        fsParams.storageLight14.state: hmi.msgStorageOld ? "" : hmi.storage14
        fsParams.storageLight13.state: hmi.msgStorageOld ? "" : hmi.storage13
        fsParams.storageLight12.state: hmi.msgStorageOld ? "" : hmi.storage12
        fsParams.storageLight11.state: hmi.msgStorageOld ? "" : hmi.storage11
        fsParams.storageLight10.state: hmi.msgStorageOld ? "" : hmi.storage10
        fsParams.storageLight9.state: hmi.msgStorageOld ? "" : hmi.storage9
        fsParams.storageLight8.state: hmi.msgStorageOld ? "" : hmi.storage8
        fsParams.storageLight7.state: hmi.msgStorageOld ? "" : hmi.storage7
        fsParams.storageLight6.state: hmi.msgStorageOld ? "" : hmi.storage6
        fsParams.storageLight5.state: hmi.msgStorageOld ? "" : hmi.storage5
        fsParams.storageLight4.state: hmi.msgStorageOld ? "" : hmi.storage4
        fsParams.storageLight3.state: hmi.msgStorageOld ? "" : hmi.storage3
        fsParams.storageLight2.state: hmi.msgStorageOld ? "" : hmi.storage2
        fsParams.storageLight1.state: hmi.msgStorageOld ? "" : hmi.storage1

        fsParams.coreLight15.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask15
        fsParams.coreLight14.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask14
        fsParams.coreLight13.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask13
        fsParams.coreLight12.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask12
        fsParams.coreLight11.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask11
        fsParams.coreLight10.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask10
        fsParams.coreLight8.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask8
        fsParams.coreLight9.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask9
        fsParams.coreLight7.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask7
        fsParams.coreLight6.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask6
        fsParams.coreLight5.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask5
        fsParams.coreLight4.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask4
        fsParams.coreLight3.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask3
        fsParams.coreLight2.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask2
        fsParams.coreLight1.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask1
        fsParams.coreLight0.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask0

        fsParams.bmsLight0.state: hmi.msgMotorOld ? "" : hmi.BMS0
        fsParams.bmsLight31.state: hmi.msgMotorOld ? "" : hmi.BMS31
        fsParams.bmsLight30.state: hmi.msgMotorOld ? "" : hmi.BMS30
        fsParams.bmsLight29.state: hmi.msgMotorOld ? "" : hmi.BMS29
        fsParams.bmsLight28.state: hmi.msgMotorOld ? "" : hmi.BMS28
        fsParams.bmsLight27.state: hmi.msgMotorOld ? "" : hmi.BMS27
        fsParams.bmsLight26.state: hmi.msgMotorOld ? "" : hmi.BMS26
        fsParams.bmsLight25.state: hmi.msgMotorOld ? "" : hmi.BMS25
        fsParams.bmsLight24.state: hmi.msgMotorOld ? "" : hmi.BMS24
        fsParams.bmsLight23.state: hmi.msgMotorOld ? "" : hmi.BMS23
        fsParams.bmsLight22.state: hmi.msgMotorOld ? "" : hmi.BMS22
        fsParams.bmsLight21.state: hmi.msgMotorOld ? "" : hmi.BMS21
        fsParams.bmsLight20.state: hmi.msgMotorOld ? "" : hmi.BMS20
        fsParams.bmsLight19.state: hmi.msgMotorOld ? "" : hmi.BMS19
        fsParams.bmsLight18.state: hmi.msgMotorOld ? "" : hmi.BMS18
        fsParams.bmsLight17.state: hmi.msgMotorOld ? "" : hmi.BMS17
        fsParams.bmsLight16.state: hmi.msgMotorOld ? "" : hmi.BMS16
        fsParams.bmsLight15.state: hmi.msgMotorOld ? "" : hmi.BMS15
        fsParams.bmsLight14.state: hmi.msgMotorOld ? "" : hmi.BMS14
        fsParams.bmsLight13.state: hmi.msgMotorOld ? "" : hmi.BMS13
        fsParams.bmsLight12.state: hmi.msgMotorOld ? "" : hmi.BMS12
        fsParams.bmsLight11.state: hmi.msgMotorOld ? "" : hmi.BMS11
        fsParams.bmsLight10.state: hmi.msgMotorOld ? "" : hmi.BMS10
        fsParams.bmsLight9.state: hmi.msgMotorOld ? "" : hmi.BMS9
        fsParams.bmsLight8.state: hmi.msgMotorOld ? "" : hmi.BMS8
        fsParams.bmsLight7.state: hmi.msgMotorOld ? "" : hmi.BMS7
        fsParams.bmsLight6.state: hmi.msgMotorOld ? "" : hmi.BMS6
        fsParams.bmsLight5.state: hmi.msgMotorOld ? "" : hmi.BMS5
        fsParams.bmsLight4.state: hmi.msgMotorOld ? "" : hmi.BMS4
        fsParams.bmsLight3.state: hmi.msgMotorOld ? "" : hmi.BMS3
        fsParams.bmsLight2.state: hmi.msgMotorOld ? "" : hmi.BMS2
        fsParams.bmsLight1.state: hmi.msgMotorOld ? "" : hmi.BMS1

        fsParams.motorLight0.state: hmi.msgMotorOld ? "" : hmi.motor0
        //fsParams.motorLight24.state: hmi.msgMotorOld ? "" : hmi.motor24
        fsParams.motorLight23.state: hmi.msgMotorOld ? "" : hmi.motor23
        fsParams.motorLight22.state: hmi.msgMotorOld ? "" : hmi.motor22
        fsParams.motorLight21.state: hmi.msgMotorOld ? "" : hmi.motor21
        fsParams.motorLight20.state: hmi.msgMotorOld ? "" : hmi.motor20

        fsParams.motorLight15.state: hmi.msgMotorOld ? "" : hmi.motor15
        fsParams.motorLight14.state: hmi.msgMotorOld ? "" : hmi.motor14
        fsParams.motorLight13.state: hmi.msgMotorOld ? "" : hmi.motor13
        fsParams.motorLight12.state: hmi.msgMotorOld ? "" : hmi.motor12

        fsParams.motorLight8.state: hmi.msgMotorOld ? "" : hmi.motor8
        fsParams.motorLight7.state: hmi.msgMotorOld ? "" : hmi.motor7
        fsParams.motorLight6.state: hmi.msgMotorOld ? "" : hmi.motor6
        fsParams.motorLight5.state: hmi.msgMotorOld ? "" : hmi.motor5
        fsParams.motorLight4.state: hmi.msgMotorOld ? "" : hmi.motor4
        fsParams.motorLight3.state: hmi.msgMotorOld ? "" : hmi.motor3
        fsParams.motorLight2.state: hmi.msgMotorOld ? "" : hmi.motor2
        fsParams.motorLight1.state: hmi.msgMotorOld ? "" : hmi.motor1

        fsParams.txtRadioLinkErrorCounter: hmi.radiolinkErrorCounter

        fsParams.radioLinkLight8.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask8
        fsParams.radioLinkLight9.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask9

        fsParams.radioLinkLight3.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask3
        fsParams.radioLinkLight2.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask2
        fsParams.radioLinkLight1.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask1
        fsParams.radioLinkLight0.up: hmi.msgRadioLinkOld ? undefined : hmi.radiolinkMask0

        map.latitude: hmi.Latitude
        map.longitude: hmi.Longitude

        //gsParams.gnssLight.up: hmi.gnssFound

        gsParams.txtTimeStamp: timestampToUTCDate(hmi.TimeStamp)

        gsParams.txtLatitudeGPSData:  gpsData.latitude.toFixed(2)
        gsParams.txtLongitudeGPSData: gpsData.longitude.toFixed(2)
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

