import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property alias txtTimeStampRIO: txtTimeStampRIO.value
    property alias txtLatitude: txtLatitude.value
    property alias txtLongitude: txtLongitude.value
    property alias txtGNSSAltitude: txtGNSSAltitude.value
    property alias txtAirSpeed_UVector: txtAirSpeed_UVector.value

    property alias txtAirSpeed_VVector: txtAirSpeed_VVector.value
    property alias txtAirSpeed_WVector: txtAirSpeed_WVector.value
    property alias txtAirTemperature: txtAirTemperature.value
    property alias txtAltitudeFromRadarAltimeter: txtAltitudeFromRadarAltimeter.value
    property alias txtAltitudeFromPayloadAltimeter: txtAltitudeFromPayloadAltimeter.value
    property alias txtLinearVelocityHorizontal: txtLinearVelocityHorizontal.value

    property alias txtLinearVelocityVertical: txtLinearVelocityVertical.value
    property alias txtPositionAccuracy: txtPositionAccuracy.value
    property alias txtSpeedAccuracy: txtSpeedAccuracy.value
    property alias txtLinearAccelerationX: txtLinearAccelerationX.value
    property alias txtLinearAccelerationY: txtLinearAccelerationY.value
    property alias txtLinearAccelerationZ: txtLinearAccelerationZ.value

    property alias txtECEFVectorPositionX: txtECEFVectorPositionX.value
    property alias txtECEFVectorPositionY: txtECEFVectorPositionY.value
    property alias txtECEFVectorPositionZ: txtECEFVectorPositionZ.value
    property alias txtECEFVectorVelocityX: txtECEFVectorVelocityX.value
    property alias txtECEFVectorVelocityY: txtECEFVectorVelocityY.value
    property alias txtECEFVectorVelocityZ: txtECEFVectorVelocityZ.value

    property alias txtRollAngle: txtRollAngle.value
    property alias txtPitchAngle: txtPitchAngle.value
    property alias txtYawAngle: txtYawAngle.value
    property alias txtAngularRateRoll: txtAngularRateRoll.value
    property alias txtAngularRatePitch: txtAngularRatePitch.value
    property alias txtAngularRateYaw: txtAngularRateYaw.value

    property alias txtNumberOfGPSSatellite: txtNumberOfGPSSatellite.value

    property alias txtAnemCommErrorCounter: txtAnemCommErrorCounter.value
    property alias txtRDAltCommErrorCounter: txtRDAltCommErrorCounter.value
    property alias txtGNSSCommErrorCounter: txtGNSSCommErrorCounter.value
    property alias txtPLAltCommErrorCounter: txtPLAltCommErrorCounter.value

    property alias txtMotorARealPosition: txtMotorARealPosition.value
    property alias txtMotorADemandPosition: txtMotorADemandPosition.value
    property alias txtMotorATorque: txtMotorATorque.value
    property alias txtMotorATemp: txtMotorATemp.value


    property alias txtMotorBRealPosition: txtMotorBRealPosition.value
    property alias txtMotorBDemandPosition: txtMotorBDemandPosition.value
    property alias txtMotorBTorque: txtMotorBTorque.value
    property alias txtMotorBTemp: txtMotorBTemp.value


    property alias txtBMS1Voltage: txtBMS1Voltage.value
    property alias txtBMS1Absorption: txtBMS1Absorption.value
    property alias txtBMS1Temp: txtBMS1Temp.value
    property alias txtMotorTimestamp: txtMotorTimestamp.value
    property alias txtChargeValue: txtChargeValue.value


    width: Constants.width / 2 //750 //C
    height: Constants.height //667 //
    color: "#ffffff"
    property alias telemetryLight0: telemetryLight0
    property alias telemetryLight31: telemetryLight31
    property alias telemetryLight30: telemetryLight30
    property alias telemetryLight29: telemetryLight29
    property alias telemetryLight28: telemetryLight28
    property alias telemetryLight27: telemetryLight27
    property alias telemetryLight26: telemetryLight26
    property alias telemetryLight25: telemetryLight25
    property alias telemetryLight24: telemetryLight24
    property alias telemetryLight23: telemetryLight23
    property alias telemetryLight22: telemetryLight22
    property alias telemetryLight21: telemetryLight21
    property alias telemetryLight20: telemetryLight20
    property alias telemetryLight19: telemetryLight19
    property alias telemetryLight18: telemetryLight18
    property alias telemetryLight17: telemetryLight17
    property alias telemetryLight16: telemetryLight16
    property alias telemetryLight15: telemetryLight15
    property alias telemetryLight14: telemetryLight14
    property alias telemetryLight13: telemetryLight13
    property alias telemetryLight12: telemetryLight12
    property alias telemetryLight11: telemetryLight11
    property alias telemetryLight10: telemetryLight10
    property alias telemetryLight9: telemetryLight9
    property alias telemetryLight8: telemetryLight8
    property alias telemetryLight7: telemetryLight7
    property alias telemetryLight6: telemetryLight6
    property alias telemetryLight5: telemetryLight5
    property alias telemetryLight4: telemetryLight4
    property alias telemetryLight3: telemetryLight3
    property alias telemetryLight2: telemetryLight2
    property alias telemetryLight1: telemetryLight1

    property alias storageLight23: storageLight23
    property alias storageLight22: storageLight22
    property alias storageLight21: storageLight21
    property alias storageLight20: storageLight20
    property alias storageLight19: storageLight19
    property alias storageLight18: storageLight18
    property alias storageLight17: storageLight17
    property alias storageLight16: storageLight16
    property alias storageLight15: storageLight15
    property alias storageLight14: storageLight14
    property alias storageLight13: storageLight13
    property alias storageLight12: storageLight12
    property alias storageLight11: storageLight11
    property alias storageLight10: storageLight10
    property alias storageLight8: storageLight8
    property alias storageLight7: storageLight7
    property alias storageLight6: storageLight6
    property alias storageLight5: storageLight5
    property alias storageLight4: storageLight4
    property alias storageLight3: storageLight3
    property alias storageLight2: storageLight2
    property alias storageLight1: storageLight1
    property alias storageLight0: storageLight0

    property alias motorLight25: motorLight23
    property alias motorLight24: motorLight22
    property alias motorLight23: motorLight23
    property alias motorLight22: motorLight22
    property alias motorLight21: motorLight21
    property alias motorLight20: motorLight20
    property alias motorLight19: motorLight19
    property alias motorLight18: motorLight18
    property alias motorLight17: motorLight17
    property alias motorLight16: motorLight16
    property alias motorLight15: motorLight15
    property alias motorLight14: motorLight14
    property alias motorLight13: motorLight13
    property alias motorLight12: motorLight12
    property alias motorLight11: motorLight11
    property alias motorLight10: motorLight10
    property alias motorLight8: motorLight8
    property alias motorLight7: motorLight7
    property alias motorLight6: motorLight6
    property alias motorLight5: motorLight5
    property alias motorLight4: motorLight4
    property alias motorLight3: motorLight3
    property alias motorLight2: motorLight2
    property alias motorLight1: motorLight1
    property alias motorLight0: motorLight0

    property alias bmsLight0: bmsLight0
    property alias bmsLight31: bmsLight31
    property alias bmsLight30: bmsLight30
    property alias bmsLight29: bmsLight29
    property alias bmsLight28: bmsLight28
    property alias bmsLight27: bmsLight27
    property alias bmsLight26: bmsLight26
    property alias bmsLight25: bmsLight25
    property alias bmsLight24: bmsLight24
    property alias bmsLight23: bmsLight23
    property alias bmsLight22: bmsLight22
    property alias bmsLight21: bmsLight21
    property alias bmsLight20: bmsLight20
    property alias bmsLight19: bmsLight19
    property alias bmsLight18: bmsLight18
    property alias bmsLight17: bmsLight17
    property alias bmsLight16: bmsLight16
    property alias bmsLight15: bmsLight15
    property alias bmsLight14: bmsLight14
    property alias bmsLight13: bmsLight13
    property alias bmsLight12: bmsLight12
    property alias bmsLight11: bmsLight11
    property alias bmsLight10: bmsLight10
    property alias bmsLight9: bmsLight9
    property alias bmsLight8: bmsLight8
    property alias bmsLight7: bmsLight7
    property alias bmsLight6: bmsLight6
    property alias bmsLight5: bmsLight5
    property alias bmsLight4: bmsLight4
    property alias bmsLight3: bmsLight3
    property alias bmsLight2: bmsLight2
    property alias bmsLight1: bmsLight1

    ColumnLayout {
        anchors.fill: parent
        spacing: 20 //24
        anchors.margins: 32

        Column {
            spacing: 0

            SectionLabel {
                text: "Flight Segment"
            }

            ParamRow {
                text: "TimeStamp RIO"
                span: 6
                id: txtTimeStampRIO
            }
        }

        Row {

            Column {
                spacing: 32
                width: 40
                Image {
                    x: 3
                    y: 0
                    source: "images/svgs/solid/satellite.svg"
                    fillMode: Image.PreserveAspectFit
                    sourceSize.height: 24
                    sourceSize.width: 24
                }

                ParamGrp1Label {
                    text: "GNSS"
                    transform: Rotation {
                        angle: 90
                        origin.x: 25
                    }
                }
            }

            GridLayout {
                Layout.fillWidth: true
                rowSpacing: 24 //32
                columnSpacing: 40 //48
                columns: 4
                rows: 2
                //48
                Column {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    //Layout.alignment: Qt.AlignRight
                    spacing: 8

                    ParamGrp2Label {
                        text: "Coordinates (°)"
                    }

                    ParamRow {
                        id: txtLatitude
                        text: "Latitude"
                        span: 4
                    }

                    ParamRow {
                        text: "Longitude"
                        span: 4
                        id: txtLongitude
                    }
                    ParamRow {
                        text: "Altitude"
                        span: 4
                        id: txtGNSSAltitude
                    }
                }

                Column {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    spacing: 8
                    ParamGrp2Label {
                        text: "ECEF Position (°)"
                    }

                    ParamRow {
                        text: "X"
                        id: txtECEFVectorPositionX
                    }
                    ParamRow {
                        text: "Y"
                        id: txtECEFVectorPositionY
                    }
                    ParamRow {
                        text: "Z"
                        id: txtECEFVectorPositionZ
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    ParamGrp2Label {
                        text: "ECEF Velocity (m/s)"
                    }

                    ParamRow {
                        text: "X"
                        id: txtECEFVectorVelocityX
                    }
                    ParamRow {
                        text: "Y"
                        id: txtECEFVectorVelocityY
                    }
                    ParamRow {
                        text: "Z"
                        id: txtECEFVectorVelocityZ
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    ParamGrp2Label {
                        text: "Linear Velocity (m/s)"
                    }

                    ParamRow {
                        text: "Horizontal"
                        span: 4
                        id: txtLinearVelocityHorizontal
                    }

                    ParamRow {
                        text: "Vertical"
                        span: 4
                        id: txtLinearVelocityVertical
                    }
                }

                Column {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    spacing: 8

                    ParamGrp2Label {
                        text: "Accuracy"
                    }

                    ParamRow {
                        text: "Position"
                        span: 7
                        id: txtPositionAccuracy
                    }

                    ParamRow {
                        text: "Speed"
                        span: 7
                        id: txtSpeedAccuracy
                    }

                    ParamRow {
                        text: "# GNSS satellites"
                        span: 7
                        id: txtNumberOfGPSSatellite
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    ParamGrp2Label {
                        text: "Angle (°)"
                    }

                    ParamRow {
                        text: "Roll"
                        span: 2
                        id: txtRollAngle
                    }
                    ParamRow {
                        text: "Pitch"
                        span: 2
                        id: txtPitchAngle
                    }
                    ParamRow {
                        text: "Yaw"
                        span: 2
                        id: txtYawAngle
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    ParamGrp2Label {
                        text: "Angular Rate"
                    }

                    ParamRow {
                        text: "Roll"
                        span: 2
                        id: txtAngularRateRoll
                    }
                    ParamRow {
                        text: "Pitch"
                        span: 2
                        id: txtAngularRatePitch
                    }

                    ParamRow {
                        text: "Yaw"
                        span: 2
                        id: txtAngularRateYaw
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    ParamGrp2Label {
                        text: "Linear Acceleration (m/s²)"
                    }

                    ParamRow {
                        text: "X"
                        id: txtLinearAccelerationX
                    }
                    ParamRow {
                        text: "Y"
                        id: txtLinearAccelerationY
                    }
                    ParamRow {
                        text: "Z"
                        id: txtLinearAccelerationZ
                    }
                }
            }
            Item {
                width: 24
                height: 1
            }
            Row {

                Column {
                    spacing: 32
                    width: 40
                    Image {
                        x: 3
                        y: 0
                        source: "images/svgs/solid/wind.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }
                    ParamGrp1Label {
                        text: "Anemometer"
                        transform: Rotation {
                            angle: 90
                            origin.x: 25
                        }
                    }
                }
                Column {
                    spacing: 8
                    ParamRow {
                        text: "Air Speed U"
                        span: 5
                        id: txtAirSpeed_UVector
                    }

                    ParamRow {
                        text: "Air Speed V"
                        span: 5
                        id: txtAirSpeed_VVector
                    }
                    ParamRow {
                        text: "Air Speed W"
                        span: 5
                        id: txtAirSpeed_WVector
                    }

                    ParamRow {
                        text: "Air Temp."
                        span: 5
                        id: txtAirTemperature
                    }
                }
            }
            Item {
                width: 24
                height: 1
            }
            Row {
                Column {
                    spacing: 32
                    width: 40
                    Image {
                        x: 3
                        y: 0
                        source: "images/svgs/solid/satellite-dish.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }
                    ParamGrp1Label {
                        text: "Radar"
                        transform: Rotation {
                            angle: 90
                            origin.x: 25
                        }
                    }
                }

                ParamRow {
                    text: "Altitude"

                    span: 3
                    id: txtAltitudeFromRadarAltimeter
                }
            }
            Item {
                width: 24
                height: 32
            }
            Row {
                Column {
                    spacing: 32
                    width: 40
                    Image {
                        x: 3
                        y: 0
                        source: "images/svgs/solid/weight-hanging.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "Payload"
                        transform: Rotation {
                            angle: 90
                            origin.x: 25
                        }
                    }
                }

                ParamRow {
                    text: "Altitude"
                    span: 3
                    id: txtAltitudeFromPayloadAltimeter
                }
            }
        }
        Rectangle {
            id: rectangle
            width: 200
            height: 200
            color: "#d9d9d9"
            Layout.preferredHeight: 1
            Layout.fillWidth: true
        }

        Row {
            Layout.fillWidth: true
            Layout.preferredHeight: childrenRect.height + 10
            Column {
                spacing: 32
                width: 40
                Image {
                    x: 3
                    y: 0
                    width: 24
                    source: "images/svgs/solid/triangle-exclamation.svg"
                    fillMode: Image.PreserveAspectFit
                }

                ParamGrp1Label {
                    text: "Telemetry status"

                    transform: Rotation {
                        angle: 90
                        origin.x: 25
                    }
                }
            }
            Grid {
                id: grid
                columnSpacing: 16
                rowSpacing: 12
                flow: Grid.TopToBottom
                columns: 8
                rows: 5

                StatusLight {
                    id: telemetryLight0
                    text: "Anemom NOT present"
                }

                StatusLight {
                    id: telemetryLight1
                    text: "RD Altimeter NOT present"
                }

                StatusLight {
                    id: telemetryLight2
                    text: "GNSS NOT present"
                }

                StatusLight {
                    id: telemetryLight3
                    text: "PL Altimeter NOT present"
                }
                StatusLight {
                    id: telemetryLight4
                    text: "Anemom TO"
                }

                StatusLight {
                    id: telemetryLight5
                    text: "Anemom CS"
                }
                StatusLight {
                    id: telemetryLight6
                    text: "RD Altimeter TO"
                }

                StatusLight {
                    id: telemetryLight7
                    text: "RD Altimeter CS"
                }
                StatusLight {
                    id: telemetryLight8
                    text: "GNSS pack1 TO"
                }

                StatusLight {
                    id: telemetryLight9
                    text: "GNSS pack1 CS"
                }
                StatusLight {
                    id: telemetryLight10
                    text: "GNSS pack2 TO"
                }

                StatusLight {
                    id: telemetryLight11
                    text: "GNSS pack2 CS"
                }

                StatusLight {
                    id: telemetryLight12
                    text: "GNSS pack3 TO"
                }

                StatusLight {
                    id: telemetryLight13
                    text: "GNSS pack3 CS"
                }
                StatusLight {
                    id: telemetryLight14
                    text: "PL Altimeter TO"
                }

                StatusLight {
                    id: telemetryLight15
                    text: "RS232 HW failure"
                }
                StatusLight {
                    id: telemetryLight16
                    text: "RS422 HW failure"
                }

                StatusLight {
                    id: telemetryLight17
                    text: "CAN HW failure"
                }
                StatusLight {
                    id: telemetryLight18
                    text: "GNSS_time NOT valid"
                }

                StatusLight {
                    id: telemetryLight19
                    text: "GNSS_pos NOT valid"
                }
                StatusLight {
                    id: telemetryLight20
                    text: "Anem_speed NOT valid"
                }

                StatusLight {
                    id: telemetryLight21
                    text: "Anem_temp NOT valid"
                }

                StatusLight {
                    id: telemetryLight22
                    text: "RD_altitude NOT valid"
                }

                StatusLight {
                    id: telemetryLight23
                    text: "PL_altitude NOT valid"
                }
                StatusLight {
                    id: telemetryLight24
                    text: "GNSS_vel NOT valid"
                }

                StatusLight {
                    id: telemetryLight25
                    text: "GNSS_acc NOT valid"
                }
                StatusLight {
                    id: telemetryLight26
                    text: "GNSS_ECEFpos NOT valid"
                }

                StatusLight {
                    id: telemetryLight27
                    text: "GNSS_ECEFvel NOT valid"
                }
                StatusLight {
                    id: telemetryLight28
                    text: "GNSS_angle NOT valid"
                }

                StatusLight {
                    id: telemetryLight29
                    text: "GNSS_angRate NOT valid"
                }
                StatusLight {
                    id: telemetryLight30
                    text: "GNSS_quat NOT valid"
                }

                StatusLight {
                    id: telemetryLight31
                    text: "GNSS_fix done"
                }
                Item {
                    height: 1
                    width: 1
                }
                Item {
                    height: 1
                    width: 1
                }
                Item {
                    height: 1
                    width: 1
                }

                ParamRow {
                    id: txtAnemCommErrorCounter
                    text: "Anemometer Comm error counter"
                    span: 12
                }
                ParamRow {
                    id: txtRDAltCommErrorCounter
                    text: "RD Altimeter Comm error counter"
                    span: 12
                }
                ParamRow {
                    id: txtGNSSCommErrorCounter
                    text: "GNSS Comm error counter"
                    span: 12
                }
                ParamRow {
                    id: txtPLAltCommErrorCounter
                    text: "PL Altimeter Comm error counter"
                    span: 12
                }
            }
        }

        Rectangle {
            id: rectangle1

            color: "#d9d9d9"
            Layout.fillWidth: true
            Layout.preferredHeight: 1
        }

        Row {
            Column {
                spacing: 32
                width: 40
                Image {
                    x: 3
                    y: 0
                    source: "images/svgs/solid/gear.svg"
                    fillMode: Image.PreserveAspectFit
                    sourceSize.height: 24
                    sourceSize.width: 24
                }

                ParamGrp1Label {
                    text: "Motors & BMS"
                    transform: Rotation {
                        angle: 90
                        origin.x: 25
                    }
                }
            }
            GridLayout {
                columnSpacing: 16
                rowSpacing: 16
                flow: Grid.TopToBottom
                columns: 6
                rows: 1
                Column {

                    spacing: 8

                    ParamGrp2Label {
                        text: "General"
                    }
                    ParamRow {
                        id:txtMotorTimestamp
                        text: "TimeStamp"
                        span: 6
                    }
                    ParamRow {
                        id: txtBMS1Voltage
                        text: "BMS1 Voltage"
                        span: 6
                    }
                    ParamRow {
                        id: txtBMS1Absorption
                        text: "BMS1 Absorption"
                        span: 6
                    }
                    ParamRow {
                        id: txtBMS1Temp
                        text: "BMS1 Temperature"
                        span: 6
                    }
                    StatusLight {
                        id: motorLight4
                        text: "MotorControllerA comm error"
                    }
                    StatusLight {
                        id: motorLight5
                        text: "MotorControllerB comm error"
                    }
                    StatusLight {
                        id: motorLight0
                        text: "RS232 HW failure"
                    }
                    StatusLight {
                        id: motorLight1
                        text: "CAN HW failure"
                    }
                    StatusLight {
                        id: motorLight2
                        text: "PT100 HW failure"
                    }
                    StatusLight {
                        id: motorLight3
                        text: "GPIO HW failure"
                    }
                    StatusLight {
                        id: motorLight6
                        text: "PT100 A sensor breakage"
                    }
                    StatusLight {
                        id: motorLight7
                        text: "PT100 B sensor breakage"
                    }

                    StatusLight {
                        id: motorLight8
                        text: "BMS comm error"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    ParamGrp2Label {
                        text: "Motor A"
                    }
                    ParamRow {
                        id: txtMotorARealPosition
                        text: "MotorA RealPosition"
                        span: 8
                    }

                    ParamRow {
                        id: txtMotorADemandPosition
                        text: "MotorA DemandPosition"
                        span: 8
                    }
                    ParamRow {
                        id: txtMotorATorque

                        text: "MotorA Torque"
                        span: 5
                    }
                    ParamRow {
                        id: txtMotorATemp

                        text: "MotorA Temp"
                        span: 5
                    }

                    StatusLight {
                        id: motorLight10
                        text: "MotorA breakage error"
                    }
                    StatusLight {
                        id: motorLight12
                        text: "MotorA demand pos error"
                    }
                    StatusLight {
                        id: motorLight14
                        text: "MotorA over-torque error"
                    }
                    StatusLight {
                        id: motorLight16
                        text: "MotorA over-current error"
                    }

                    StatusLight {
                        id: motorLight18
                        text: "MotorA under-voltage error"
                    }
                    StatusLight {
                        id: motorLight20
                        text: "MotorA resolver err"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    ParamGrp2Label {
                        text: "Motor B"
                    }
                    ParamRow {
                        id: txtMotorBRealPosition

                        text: "MotorB RealPosition"
                        span: 8
                    }
                    ParamRow {
                        id: txtMotorBDemandPosition

                        text: "MotorB DemandPosition"
                        span: 8
                    }

                    ParamRow {
                        id: txtMotorBTorque

                        text: "MotorB Torque"
                        span: 5
                    }

                    ParamRow {
                        id: txtMotorBTemp

                        text: "MotorB Temp"
                        span: 5
                    }

                    StatusLight {
                        id: motorLight11
                        text: "MotorB breakage error"
                    }
                    StatusLight {
                        id: motorLight13
                        text: "MotorB demand pos error"
                    }

                    StatusLight {
                        id: motorLight15
                        text: "MotorB over-torque error"
                    }
                    StatusLight {
                        id: motorLight17
                        text: "MotorB over-current error"
                    }
                    StatusLight {
                        id: motorLight19
                        text: "MotorB under-voltage error"
                    }

                    StatusLight {
                        id: motorLight21
                        text: "MotorB resolver error"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    ParamGrp2Label {
                        text: "BMS"
                    }

                    ParamRow {
                        id: txtChargeValue
                        text: "Charge %"
                        span: 3
                    }
                    StatusLight {
                        id: motorLight25
                        text: "Battery LOW"
                    }
                    StatusLight {
                        id: motorLight22
                        text: "BMS INDICATION"
                    }
                    StatusLight {
                        id: motorLight23
                        text: "BMS FAULT"
                    }
                    StatusLight {
                        id: motorLight24
                        text: "BMS REQUEST"
                    }

                    StatusLight {
                        id: bmsLight0
                        text: "Battery OVERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        id: bmsLight1
                        text: "Battery OVERVOLTAGE FAULT"
                    }
                    StatusLight {
                        id: bmsLight2
                        text: "Battery UNDERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        id: bmsLight3
                        text: "Battery UNDERVOLTAGE FAULT"
                    }
                    StatusLight {
                        id: bmsLight4
                        text: "Battery EXCESSIVE INDICATION"
                    }
                    StatusLight {
                        id: bmsLight5
                        text: "Battery EXCESSIVE FAULT"
                    }
                    StatusLight {
                        id: bmsLight6
                        text: "Battery temp HIGH INDICATION"
                    }
                    StatusLight {
                        id: bmsLight7
                        text: "Battery temp HIGH FAULT"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    Item {
                        height: 16
                        width: 1
                    }

                    StatusLight {
                        id: bmsLight8
                        text: "Battery temp LOW INDICATION"
                    }
                    StatusLight {
                        id: bmsLight9
                        text: "Battery temp LOW FAULT"
                    }

                    StatusLight {
                        id: bmsLight10
                        text: "Cell UNDERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        id: bmsLight11
                        text: "Cell UNDERVOLTAGE FAULT"
                    }

                    StatusLight {
                        id: bmsLight12
                        text: "Cell OVERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        id: bmsLight13
                        text: "Cell OVERVOLTAGE FAULT"
                    }
                    StatusLight {
                        id: bmsLight14
                        text: "Cell voltage difference INDICATION"
                    }
                    StatusLight {
                        id: bmsLight15
                        text: "Cell voltage difference FAULT"
                    }
                    StatusLight {
                        id: bmsLight16
                        text: "Cell temp difference INDICATION"
                    }
                    StatusLight {
                        id: bmsLight17
                        text: "Cell temp difference FAULT"
                    }

                    StatusLight {
                        id: bmsLight18
                        text: "Cell temp sensor FAULT"
                    }
                    StatusLight {
                        id: bmsLight19
                        text: "Generic HW FAULT"
                    }

                    StatusLight {
                        id: bmsLight20
                        text: "Charge switch FAULT"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    Item {
                        height: 16
                        width: 1
                    }

                    StatusLight {
                        id: bmsLight21
                        text: "Discharge switch FAULT"
                    }

                    StatusLight {
                        id: bmsLight22
                        text: "Self-test FAULT"
                    }
                    StatusLight {
                        id: bmsLight23
                        text: "Collection line FAULT"
                    }

                    StatusLight {
                         id: bmsLight24
                        text: "Temp line FAULT"
                    }
                    StatusLight {
                        id: bmsLight25
                        text: "BMS alarm FAULT"
                    }
                    StatusLight {
                        id: bmsLight26
                        text: "Activity limit request"
                    }
                    StatusLight {
                        id: bmsLight27
                        text: "Discharge current limit request"
                    }
                    StatusLight {
                        id: bmsLight28
                        text: "Consumption STOP request"
                    }
                    StatusLight {
                        id: bmsLight29
                        text: "Charging temp low FAULT"
                    }
                    StatusLight {
                        id: bmsLight30
                        text: "Charging temp high FAULT"
                    }
                    StatusLight {
                        id: bmsLight31
                        text: "Excessive charging current FAULT"
                    }
                }
            }
        }

        Rectangle {
            id: rectangle3

            color: "#d9d9d9"
            Layout.preferredHeight: 1
            Layout.fillWidth: true
        }

        Row {
            Layout.fillWidth: true
            Layout.preferredHeight: childrenRect.height
            Column {
                spacing: 32
                width: 40
                Image {
                    x: 3
                    y: 0
                    width: 24
                    source: "images/svgs/solid/database.svg"
                    fillMode: Image.PreserveAspectFit
                }

                ParamGrp1Label {
                    text: "Storage"

                    transform: Rotation {
                        angle: 90
                        origin.x: 25
                    }
                }
            }
            Grid {
                id: gridStorage
                columnSpacing: 16
                rowSpacing: 12
                flow: Grid.TopToBottom
                columns: 6
                rows: 4

                StatusLight {
                    id: storageLight0
                    text: "uSD HW failure"
                }

                StatusLight {
                    id: storageLight1
                    text: "uSD not present error"
                }

                StatusLight {
                    id: storageLight2
                    text: "uSD full"
                }

                StatusLight {
                    id: storageLight3
                    text: "System Status log write error"
                }
                StatusLight {
                    id: storageLight4
                    text: "Telemetry module log write error"
                }

                StatusLight {
                    id: storageLight5
                    text: "Storage module log write error"
                }
                StatusLight {
                    id: storageLight6
                    text: "Radio link module log write error"
                }

                StatusLight {
                    id: storageLight7
                    text: "Motor control log write error"
                }
                StatusLight {
                    id: storageLight8
                    text: "Guidance module log write error"
                }

                StatusLight {
                    id: storageLight10
                    text: "PCNC initialization verification error"
                }

                StatusLight {
                    id: storageLight11
                    text: "PCNC initialization storage error"
                }

                StatusLight {
                    id: storageLight12
                    text: "PCNC flight path verification error"
                }

                StatusLight {
                    id: storageLight13
                    text: "PCNC flight path storage error"
                }
                StatusLight {
                    id: storageLight14
                    text: "Trim script verification error"
                }

                StatusLight {
                    id: storageLight15
                    text: "Trim script storage error"
                }
                StatusLight {
                    id: storageLight16
                    text: "Open-Loop script verification error"
                }

                StatusLight {
                    id: storageLight17
                    text: "Open-Loop script storage error"
                }
                StatusLight {
                    id: storageLight18
                    text: "Recovery-A script verification error"
                }

                StatusLight {
                    id: storageLight19
                    text: "Recovery-A script storage error"
                }
                StatusLight {
                    id: storageLight20
                    text: "Recovery-B script verification error"
                }

                StatusLight {
                    id: storageLight21
                    text: "Recovery-B script storage error"
                }

                StatusLight {
                    id: storageLight22
                    text: "Flare script verification error"
                }

                StatusLight {
                    id: storageLight23
                    text: "Flare script storage error"
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1600}D{i:3}D{i:4}D{i:2}D{i:7}D{i:8}D{i:6}D{i:12}D{i:13}D{i:14}
D{i:15}D{i:11}D{i:17}D{i:18}D{i:19}D{i:20}D{i:16}D{i:22}D{i:23}D{i:24}D{i:25}D{i:21}
D{i:27}D{i:28}D{i:29}D{i:26}D{i:31}D{i:32}D{i:33}D{i:34}D{i:30}D{i:36}D{i:37}D{i:38}
D{i:39}D{i:35}D{i:41}D{i:42}D{i:43}D{i:44}D{i:40}D{i:46}D{i:47}D{i:48}D{i:49}D{i:45}
D{i:10}D{i:50}D{i:53}D{i:54}D{i:52}D{i:57}D{i:58}D{i:59}D{i:60}D{i:56}D{i:51}D{i:61}
D{i:64}D{i:65}D{i:63}D{i:67}D{i:62}D{i:68}D{i:71}D{i:72}D{i:70}D{i:74}D{i:69}D{i:5}
D{i:75}D{i:78}D{i:79}D{i:77}D{i:82}D{i:83}D{i:84}D{i:85}D{i:86}D{i:87}D{i:88}D{i:89}
D{i:90}D{i:91}D{i:92}D{i:93}D{i:94}D{i:95}D{i:96}D{i:97}D{i:98}D{i:99}D{i:100}D{i:101}
D{i:102}D{i:103}D{i:104}D{i:105}D{i:106}D{i:107}D{i:108}D{i:109}D{i:110}D{i:111}D{i:112}
D{i:113}D{i:114}D{i:115}D{i:116}D{i:117}D{i:118}D{i:119}D{i:120}D{i:81}D{i:76}D{i:121}
D{i:124}D{i:125}D{i:123}D{i:129}D{i:130}D{i:131}D{i:132}D{i:133}D{i:134}D{i:135}D{i:136}
D{i:137}D{i:138}D{i:139}D{i:140}D{i:141}D{i:142}D{i:128}D{i:144}D{i:145}D{i:146}D{i:147}
D{i:148}D{i:149}D{i:150}D{i:151}D{i:152}D{i:153}D{i:154}D{i:143}D{i:156}D{i:157}D{i:158}
D{i:159}D{i:160}D{i:161}D{i:162}D{i:163}D{i:164}D{i:165}D{i:166}D{i:155}D{i:168}D{i:169}
D{i:170}D{i:171}D{i:172}D{i:173}D{i:174}D{i:175}D{i:176}D{i:177}D{i:178}D{i:179}D{i:180}
D{i:181}D{i:167}D{i:183}D{i:184}D{i:185}D{i:186}D{i:187}D{i:188}D{i:189}D{i:190}D{i:191}
D{i:192}D{i:193}D{i:194}D{i:195}D{i:196}D{i:182}D{i:198}D{i:199}D{i:200}D{i:201}D{i:202}
D{i:203}D{i:204}D{i:205}D{i:206}D{i:207}D{i:208}D{i:209}D{i:197}D{i:127}D{i:122}D{i:210}
D{i:213}D{i:214}D{i:212}D{i:217}D{i:218}D{i:219}D{i:220}D{i:221}D{i:222}D{i:223}D{i:224}
D{i:225}D{i:226}D{i:227}D{i:228}D{i:229}D{i:230}D{i:231}D{i:232}D{i:233}D{i:234}D{i:235}
D{i:236}D{i:237}D{i:238}D{i:239}D{i:216}D{i:211}D{i:240}D{i:1}
}
##^##*/

