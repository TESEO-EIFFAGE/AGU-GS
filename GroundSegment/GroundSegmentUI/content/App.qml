import QtQuick 2.15
import QtQuick.Window 2.15
import GroundSegmentUI 1.0
import QtPositioning 5.6

Window {
    width: Constants.width
    height: Constants.height

    visible: true
    title: "GroundSegmentUI"


    Screen01 {
        id: mainScreen
        fsParams.onTelemetryTabClicked: timer.restart()
        fsParams.onMotorsBMSTabClicked: timer.restart()
        fsParams.onStorageTabClicked: timer.restart()
        fsParams.onGuidanceTabClicked: timer.restart()
        fsParams.onCoreTabClicked: timer.restart()
        fsParams.onRadioLinkTabClicked: timer.restart()
        anchors.fill:parent
        Timer{
            id:timer
            running:true
            repeat: true
            interval:12000
            onTriggered: mainScreen.tabIndex=0
        }

        mapBoundaries.topLeft: QtPositioning.coordinate(hmi.LatTopLeft,hmi.LongTopLeft)
        mapBoundaries.bottomRight: QtPositioning.coordinate(hmi.LatBotRight,hmi.LongBotRight)

        gsParams.customLatField.onEditingFinished: map.latitude = parseInt(gsParams.customLatField.text)
        gsParams.customLonField.onEditingFinished: map.longitude = parseInt(gsParams.customLonField.text)

        fsParams.telemetryTab.enabled: !hmi.msgTelemetryOld
        fsParams.storageTab.enabled: !hmi.msgStorageOld
        fsParams.motorsBMSTab.enabled: !hmi.msgMotorOld
        fsParams.coreTab.enabled: !hmi.msgSystemOld
        fsParams.radioLinkTab.enabled: !hmi.msgRadioLinkOld
        fsParams.guidanceTab.enabled: !hmi.msgGuidanceOld

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


        fsParams.txtTelemetryMsgCounter.value: hmi.telemetryMsgCounter
        fsParams.txtStorageMsgCounter: hmi.storageMsgCounter
        fsParams.txtSystemMsgCounter: hmi.systemMsgCounter
        //fsParams.txtGuidanceMsgCounter: hmi.guidanceMsgCounter
        fsParams.txtRadioLinkMsgCounter: hmi.radiolinkMsgCounter
        fsParams.txtMotorMsgCounter: hmi.motorMsgCounter

        fsParams.txtTimeStampRIO: timestampToUTCDate(hmi.TimeStampRIO)
        fsParams.txtLatitude.value: hmi.Latitude.toFixed(2)
        fsParams.txtLongitude.value: hmi.Longitude.toFixed(2)
        fsParams.txtGNSSAltitude.value: hmi.GNSSAltitude.toFixed(3)

        fsParams.txtLatitude.desc: hmi.LatitudeDesc
        fsParams.txtLongitude.desc: hmi.LongitudeDesc
        fsParams.txtGNSSAltitude.desc: hmi.GNSSAltitudeDesc

        fsParams.txtLatitudeHome.value: hmi.Latitude.toFixed(7)
        fsParams.txtLongitudeHome.value: hmi.Longitude.toFixed(7)
        fsParams.txtGNSSAltitudeHome.value: hmi.GNSSAltitude.toFixed(3)

        fsParams.txtLatitudeHome.desc: hmi.LatitudeDesc
        fsParams.txtLongitudeHome.desc: hmi.LongitudeDesc
        fsParams.txtGNSSAltitudeHome.desc: hmi.GNSSAltitudeDesc

        fsParams.txtAirSpeed_UVector.value: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.txtAirSpeed_VVector.value: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.txtAirSpeed_WVector.value: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.txtAirSpeed_UVector.desc: hmi.AirSpeed_UVectorDesc
        fsParams.txtAirSpeed_VVector.desc: hmi.AirSpeed_VVectorDesc
        fsParams.txtAirSpeed_WVector.desc: hmi.AirSpeed_WVectorDesc

        fsParams.txtAirSpeed_UVectorHome.value: hmi.AirSpeed_UVector.toFixed(2)
        fsParams.txtAirSpeed_VVectorHome.value: hmi.AirSpeed_VVector.toFixed(2)
        fsParams.txtAirSpeed_WVectorHome.value: hmi.AirSpeed_WVector.toFixed(2)

        fsParams.txtAirSpeed_UVectorHome.desc: hmi.AirSpeed_UVectorDesc
        fsParams.txtAirSpeed_VVectorHome.desc: hmi.AirSpeed_VVectorDesc
        fsParams.txtAirSpeed_WVectorHome.desc: hmi.AirSpeed_WVectorDesc

        fsParams.txtAirTemperature.value: hmi.AirTemperature.toFixed(2)

        fsParams.radarDrawer.param1.value: hmi.AltitudeFromRadarAltimeter.toFixed(2)
        fsParams.payloadDrawer.param1.value:hmi.AltitudeFromPayloadAltimeter.toFixed(2)

        fsParams.txtLinearVelocityHorizontal.value: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.txtLinearVelocityVertical.value: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.txtAirTemperature.desc: hmi.AirTemperatureDesc

        fsParams.radarDrawer.param1.desc: hmi.AltitudeFromRadarAltimeterDesc
        fsParams.payloadDrawer.param1.desc:hmi.AltitudeFromPayloadAltimeterDesc

        fsParams.txtLinearVelocityHorizontal.desc: hmi.LinearVelocityHorizontalDesc
        fsParams.txtLinearVelocityVertical.desc: hmi.LinearVelocityVerticalDesc

        fsParams.txtLinearVelocityHorizontalHome.value: hmi.LinearVelocityHorizontal.toFixed(2)
        fsParams.txtLinearVelocityVerticalHome.value: hmi.LinearVelocityVertical.toFixed(2)

        fsParams.txtLinearVelocityHorizontalHome.desc: hmi.LinearVelocityHorizontalDesc
        fsParams.txtLinearVelocityVerticalHome.desc: hmi.LinearVelocityVerticalDesc

        fsParams.txtPositionAccuracy.value: hmi.PositionAccuracy.toFixed(2)
        fsParams.txtSpeedAccuracy.value:hmi.SpeedAccuracy.toFixed(2)

        fsParams.txtPositionAccuracy.desc: hmi.PositionAccuracyDesc
        fsParams.txtSpeedAccuracy.desc:hmi.SpeedAccuracyDesc

        fsParams.linearAccDrawer.param1.value: hmi.LinearAccelerationX.toFixed(2)
        fsParams.linearAccDrawer.param2.value: hmi.LinearAccelerationY.toFixed(2)
        fsParams.linearAccDrawer.param3.value: hmi.LinearAccelerationZ.toFixed(2)

        fsParams.linearAccDrawer.param1.desc: hmi.LinearAccelerationXDesc
        fsParams.linearAccDrawer.param2.desc: hmi.LinearAccelerationYDesc
        fsParams.linearAccDrawer.param3.desc: hmi.LinearAccelerationZDesc

        fsParams.txtECEFVectorPositionX.value: hmi.ECEFVectorPositionX.toFixed(2)
        fsParams.txtECEFVectorPositionY.value: hmi.ECEFVectorPositionY.toFixed(2)
        fsParams.txtECEFVectorPositionZ.value: hmi.ECEFVectorPositionZ.toFixed(2)

        fsParams.txtECEFVectorPositionX.desc: hmi.ECEFVectorPositionXDesc
        fsParams.txtECEFVectorPositionY.desc: hmi.ECEFVectorPositionYDesc
        fsParams.txtECEFVectorPositionZ.desc: hmi.ECEFVectorPositionZDesc

        fsParams.ecefVelocityDrawer.param1.value: hmi.ECEFVectorVelocityX.toFixed(2)
        fsParams.ecefVelocityDrawer.param2.value: hmi.ECEFVectorVelocityY.toFixed(2)
        fsParams.ecefVelocityDrawer.param3.value: hmi.ECEFVectorVelocityZ.toFixed(2)

        fsParams.ecefVelocityDrawer.param1.desc: hmi.ECEFVectorVelocityXDesc
        fsParams.ecefVelocityDrawer.param2.desc: hmi.ECEFVectorVelocityYDesc
        fsParams.ecefVelocityDrawer.param3.desc: hmi.ECEFVectorVelocityZDesc

        fsParams.txtRollAngle.value: hmi.RollAngle.toFixed(2)
        fsParams.txtPitchAngle.value: hmi.PitchAngle.toFixed(2)
        fsParams.txtYawAngle.value: hmi.YawAngle.toFixed(2)

        fsParams.txtRollAngle.desc: hmi.RollAngleDesc
        fsParams.txtPitchAngle.desc: hmi.PitchAngleDesc
        fsParams.txtYawAngle.desc: hmi.YawAngleDesc

        fsParams.txtRollAngleHome.value: hmi.RollAngle.toFixed(2)
        fsParams.txtPitchAngleHome.value: hmi.PitchAngle.toFixed(2)
        fsParams.txtYawAngleHome.value: hmi.YawAngle.toFixed(2)

        fsParams.txtRollAngleHome.desc: hmi.RollAngleDesc
        fsParams.txtPitchAngleHome.desc: hmi.PitchAngleDesc
        fsParams.txtYawAngleHome.desc: hmi.YawAngleDesc

        fsParams.txtAngularRateRoll.value: hmi.AngularRateRoll.toFixed(2)
        fsParams.txtAngularRatePitch.value: hmi.AngularRatePitch.toFixed(2)
        fsParams.txtAngularRateYaw.value: hmi.AngularRateYaw.toFixed(2)

        fsParams.txtNumberOfGPSSatellite.value: hmi.NumberOfGPSSatellite

        fsParams.txtAnemCommErrorCounter.value: hmi.AnemCommErrorCounter
        fsParams.txtRDAltCommErrorCounter.value: hmi.RDAltCommErrorCounter
        fsParams.txtGNSSCommErrorCounter.value: hmi.GNSSCommErrorCounter
        fsParams.txtPLAltCommErrorCounter.value: hmi.PLAltCommErrorCounter

        fsParams.txtAngularRateRoll.desc: hmi.AngularRateRollDesc
        fsParams.txtAngularRatePitch.desc: hmi.AngularRatePitchDesc
        fsParams.txtAngularRateYaw.desc: hmi.AngularRateYawDesc

        fsParams.txtNumberOfGPSSatellite.desc: hmi.NumberOfGPSSatelliteDesc

        fsParams.txtAnemCommErrorCounter.desc: hmi.AnemCommErrorCounterDesc
        fsParams.txtRDAltCommErrorCounter.desc: hmi.RDAltCommErrorCounterDesc
        fsParams.txtGNSSCommErrorCounter.desc: hmi.GNSSCommErrorCounterDesc
        fsParams.txtPLAltCommErrorCounter.desc: hmi.PLAltCommErrorCounterDesc

        fsParams.txtMotorARealPosition.value: hmi.MotorARealPosition.toFixed(3)
        fsParams.txtMotorADemandPosition.value: hmi.MotorADemandPosition.toFixed(3)
        fsParams.txtMotorATorque.value: hmi.MotorATorque.toFixed(2)
        fsParams.txtMotorATemp.value: hmi.MotorATemp.toFixed(2)

        fsParams.txtMotorBRealPosition.value: hmi.MotorBRealPosition.toFixed(3)
        fsParams.txtMotorBDemandPosition.value: hmi.MotorBDemandPosition.toFixed(3)
        fsParams.txtMotorBTorque.value: hmi.MotorBTorque.toFixed(2)
        fsParams.txtMotorBTemp.value: hmi.MotorBTemp.toFixed(2)

        fsParams.txtBMS1Voltage.value: hmi.BMSVoltage.toFixed(2)
        fsParams.txtBMS1Absorption.value: hmi.BMSAbsorption.toFixed(2)
        fsParams.txtBMS1Temp.value: hmi.BMSTemp.toFixed(2)
        fsParams.txtChargeValue.value: hmi.ChargeValue

        fsParams.txtMotorARealPosition.desc: hmi.MotorARealPositionDesc
        fsParams.txtMotorADemandPosition.desc: hmi.MotorADemandPositionDesc
        fsParams.txtMotorATorque.desc: hmi.MotorATorqueDesc
        fsParams.txtMotorATemp.desc: hmi.MotorATempDesc

        fsParams.txtMotorBRealPosition.desc: hmi.MotorBRealPositionDesc
        fsParams.txtMotorBDemandPosition.desc: hmi.MotorBDemandPositionDesc
        fsParams.txtMotorBTorque.desc: hmi.MotorBTorqueDesc
        fsParams.txtMotorBTemp.desc: hmi.MotorBTempDesc

        fsParams.txtBMS1Voltage.desc: hmi.BMSVoltageDesc
        fsParams.txtBMS1Absorption.desc: hmi.BMSAbsorptionDesc
        fsParams.txtBMS1Temp.desc: hmi.BMSTempDesc
        fsParams.txtChargeValue.desc: hmi.ChargeValueDesc

        fsParams.txtFreeDataStorageSize.value: hmi.storageFreeDataSize
        fsParams.txtFreeDataStorageSize.desc: hmi.storageFreeDataSizeDesc

        fsParams.telemetryStatusDrawer.light31.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry31
        fsParams.telemetryStatusDrawer.light30.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry30
        fsParams.telemetryStatusDrawer.light29.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry29
        fsParams.telemetryStatusDrawer.light28.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry28
        fsParams.telemetryStatusDrawer.light27.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry27
        fsParams.telemetryStatusDrawer.light26.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry26
        fsParams.telemetryStatusDrawer.light25.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry25
        fsParams.telemetryStatusDrawer.light24.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry24
        fsParams.telemetryStatusDrawer.light23.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry23
        fsParams.telemetryStatusDrawer.light22.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry22
        fsParams.telemetryStatusDrawer.light21.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry21
        fsParams.telemetryStatusDrawer.light20.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry20
        fsParams.telemetryStatusDrawer.light19.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry19
        fsParams.telemetryStatusDrawer.light18.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry18
        fsParams.telemetryStatusDrawer.light17.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry17
        fsParams.telemetryStatusDrawer.light16.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry16
        fsParams.telemetryStatusDrawer.light15.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry15
        fsParams.telemetryStatusDrawer.light14.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry14
        fsParams.telemetryStatusDrawer.light13.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry13
        fsParams.telemetryStatusDrawer.light12.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry12
        fsParams.telemetryStatusDrawer.light11.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry11
        fsParams.telemetryStatusDrawer.light10.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry10
        fsParams.telemetryStatusDrawer.light9.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry9
        fsParams.telemetryStatusDrawer.light8.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry8
        fsParams.telemetryStatusDrawer.light7.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry7
        fsParams.telemetryStatusDrawer.light6.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry6
        fsParams.telemetryStatusDrawer.light5.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry5
        fsParams.telemetryStatusDrawer.light4.state: hmi.msgTelemetryOld ? "" :  hmi.telemetry4
        fsParams.telemetryStatusDrawer.light3.state: hmi.msgTelemetryOld ? "" : hmi.telemetry3
        fsParams.telemetryStatusDrawer.light2.state: hmi.msgTelemetryOld ? "" : hmi.telemetry2
        fsParams.telemetryStatusDrawer.light1.state: hmi.msgTelemetryOld ? "" : hmi.telemetry1
        fsParams.telemetryStatusDrawer.light0.state: hmi.msgTelemetryOld ? "" : hmi.telemetry0

        fsParams.storageDrawer.light23.state: hmi.msgStorageOld ? "" : hmi.storage23
        fsParams.storageDrawer.light22.state: hmi.msgStorageOld ? "" : hmi.storage22
        fsParams.storageDrawer.light21.state: hmi.msgStorageOld ? "" : hmi.storage21
        fsParams.storageDrawer.light20.state: hmi.msgStorageOld ? "" : hmi.storage20
        fsParams.storageDrawer.light19.state: hmi.msgStorageOld ? "" : hmi.storage19
        fsParams.storageDrawer.light18.state: hmi.msgStorageOld ? "" : hmi.storage18
        fsParams.storageDrawer.light17.state: hmi.msgStorageOld ? "" : hmi.storage17
        fsParams.storageDrawer.light16.state: hmi.msgStorageOld ? "" : hmi.storage16
        fsParams.storageDrawer.light15.state: hmi.msgStorageOld ? "" : hmi.storage15
        fsParams.storageDrawer.light14.state: hmi.msgStorageOld ? "" : hmi.storage14
        fsParams.storageDrawer.light13.state: hmi.msgStorageOld ? "" : hmi.storage13
        fsParams.storageDrawer.light12.state: hmi.msgStorageOld ? "" : hmi.storage12
        fsParams.storageDrawer.light11.state: hmi.msgStorageOld ? "" : hmi.storage11
        fsParams.storageDrawer.light10.state: hmi.msgStorageOld ? "" : hmi.storage10
        fsParams.storageDrawer.light9.state: hmi.msgStorageOld ? "" : hmi.storage9
        fsParams.storageDrawer.light8.state: hmi.msgStorageOld ? "" : hmi.storage8
        fsParams.storageDrawer.light7.state: hmi.msgStorageOld ? "" : hmi.storage7
        fsParams.storageDrawer.light6.state: hmi.msgStorageOld ? "" : hmi.storage6
        fsParams.storageDrawer.light5.state: hmi.msgStorageOld ? "" : hmi.storage5
        fsParams.storageDrawer.light4.state: hmi.msgStorageOld ? "" : hmi.storage4
        fsParams.storageDrawer.light3.state: hmi.msgStorageOld ? "" : hmi.storage3
        fsParams.storageDrawer.light2.state: hmi.msgStorageOld ? "" : hmi.storage2
        fsParams.storageDrawer.light1.state: hmi.msgStorageOld ? "" : hmi.storage1
        fsParams.storageDrawer.light0.state: hmi.msgStorageOld ? "" : hmi.storage0

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

        fsParams.homeTab.coreLight4.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask9
        fsParams.homeTab.coreLight3.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask10
        fsParams.homeTab.coreLight2.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask8
        fsParams.homeTab.coreLight1.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask11
        fsParams.homeTab.coreLight0.state: hmi.msgSystemOld ? "" : hmi.systemCoreMask7

        fsParams.bmsDrawer.light31.state: hmi.msgMotorOld ? "" : hmi.BMS31
        fsParams.bmsDrawer.light30.state: hmi.msgMotorOld ? "" : hmi.BMS30
        fsParams.bmsDrawer.light29.state: hmi.msgMotorOld ? "" : hmi.BMS29
        fsParams.bmsDrawer.light28.state: hmi.msgMotorOld ? "" : hmi.BMS28
        fsParams.bmsDrawer.light27.state: hmi.msgMotorOld ? "" : hmi.BMS27
        fsParams.bmsDrawer.light26.state: hmi.msgMotorOld ? "" : hmi.BMS26
        fsParams.bmsDrawer.light25.state: hmi.msgMotorOld ? "" : hmi.BMS25
        fsParams.bmsDrawer.light24.state: hmi.msgMotorOld ? "" : hmi.BMS24
        fsParams.bmsDrawer.light23.state: hmi.msgMotorOld ? "" : hmi.BMS23
        fsParams.bmsDrawer.light22.state: hmi.msgMotorOld ? "" : hmi.BMS22
        fsParams.bmsDrawer.light21.state: hmi.msgMotorOld ? "" : hmi.BMS21
        fsParams.bmsDrawer.light20.state: hmi.msgMotorOld ? "" : hmi.BMS20
        fsParams.bmsDrawer.light19.state: hmi.msgMotorOld ? "" : hmi.BMS19
        fsParams.bmsDrawer.light18.state: hmi.msgMotorOld ? "" : hmi.BMS18
        fsParams.bmsDrawer.light17.state: hmi.msgMotorOld ? "" : hmi.BMS17
        fsParams.bmsDrawer.light16.state: hmi.msgMotorOld ? "" : hmi.BMS16
        fsParams.bmsDrawer.light15.state: hmi.msgMotorOld ? "" : hmi.BMS15
        fsParams.bmsDrawer.light14.state: hmi.msgMotorOld ? "" : hmi.BMS14
        fsParams.bmsDrawer.light13.state: hmi.msgMotorOld ? "" : hmi.BMS13
        fsParams.bmsDrawer.light12.state: hmi.msgMotorOld ? "" : hmi.BMS12
        fsParams.bmsDrawer.light11.state: hmi.msgMotorOld ? "" : hmi.BMS11
        fsParams.bmsDrawer.light10.state: hmi.msgMotorOld ? "" : hmi.BMS10
        fsParams.bmsDrawer.light9.state: hmi.msgMotorOld ? "" : hmi.BMS9
        fsParams.bmsDrawer.light8.state: hmi.msgMotorOld ? "" : hmi.BMS8
        fsParams.bmsDrawer.light7.state: hmi.msgMotorOld ? "" : hmi.BMS7
        fsParams.bmsDrawer.light6.state: hmi.msgMotorOld ? "" : hmi.BMS6
        fsParams.bmsDrawer.light5.state: hmi.msgMotorOld ? "" : hmi.BMS5
        fsParams.bmsDrawer.light4.state: hmi.msgMotorOld ? "" : hmi.BMS4
        fsParams.bmsDrawer.light3.state: hmi.msgMotorOld ? "" : hmi.BMS3
        fsParams.bmsDrawer.light2.state: hmi.msgMotorOld ? "" : hmi.BMS2
        fsParams.bmsDrawer.light1.state: hmi.msgMotorOld ? "" : hmi.BMS1
        fsParams.bmsDrawer.light0.state: hmi.msgMotorOld ? "" : hmi.BMS0

        //fsParams.motorLight24.state: hmi.msgMotorOld ? "" : hmi.motor24
        fsParams.generalMotorDrawer.light23.state: hmi.msgMotorOld ? "" : hmi.motor23
        fsParams.generalMotorDrawer.light22.state: hmi.msgMotorOld ? "" : hmi.motor22
        fsParams.generalMotorDrawer.light21.state: hmi.msgMotorOld ? "" : hmi.motor21
        fsParams.generalMotorDrawer.light20.state: hmi.msgMotorOld ? "" : hmi.motor20

        fsParams.generalMotorDrawer.light15.state: hmi.msgMotorOld ? "" : hmi.motor15
        fsParams.generalMotorDrawer.light14.state: hmi.msgMotorOld ? "" : hmi.motor14
        fsParams.generalMotorDrawer.light13.state: hmi.msgMotorOld ? "" : hmi.motor13
        fsParams.generalMotorDrawer.light12.state: hmi.msgMotorOld ? "" : hmi.motor12

        fsParams.generalMotorDrawer.light8.state: hmi.msgMotorOld ? "" : hmi.motor8
        fsParams.generalMotorDrawer.light7.state: hmi.msgMotorOld ? "" : hmi.motor7
        fsParams.generalMotorDrawer.light6.state: hmi.msgMotorOld ? "" : hmi.motor6
        fsParams.generalMotorDrawer.light5.state: hmi.msgMotorOld ? "" : hmi.motor5
        fsParams.generalMotorDrawer.light4.state: hmi.msgMotorOld ? "" : hmi.motor4
        fsParams.generalMotorDrawer.light3.state: hmi.msgMotorOld ? "" : hmi.motor3
        fsParams.generalMotorDrawer.light2.state: hmi.msgMotorOld ? "" : hmi.motor2
        fsParams.generalMotorDrawer.light1.state: hmi.msgMotorOld ? "" : hmi.motor1
        fsParams.generalMotorDrawer.light0.state: hmi.msgMotorOld ? "" : hmi.motor0

        fsParams.txtRadioLinkErrorCounter: hmi.radiolinkErrorCounter

        fsParams.radioLinkLight8.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask8
        fsParams.radioLinkLight9.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask9

        fsParams.radioLinkLight3.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask3
        fsParams.radioLinkLight2.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask2
        fsParams.radioLinkLight1.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask1
        fsParams.radioLinkLight0.state: hmi.msgRadioLinkOld ? "" : hmi.radiolinkMask0

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

