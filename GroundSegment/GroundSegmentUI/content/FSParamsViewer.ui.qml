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
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    id: row2
                    spacing: 8

                    Image {
                        x: 0
                        y: 0
                        source: "images/svgs/solid/wind.svg"
                        sourceSize.height: 24
                        sourceSize.width: 24
                        fillMode: Image.PreserveAspectFit
                    }
                    ParamGrp1Label {
                        text: "Anemometer"
                    }
                }

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
            Item {
                width: 24
                height: 1
            }
            Column {

                Row {
                    id: row4
                    Image {
                        x: 0
                        y: 0
                        source: "images/svgs/solid/satellite-dish.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "Radar"
                    }
                    spacing: 8
                }

                ParamRow {
                    text: "Altitude"

                    span: 3
                    id: txtAltitudeFromRadarAltimeter
                }
                Item {
                    width: 1
                    height: 8
                }

                Layout.alignment: Qt.AlignTop
                spacing: 8
                Row {
                    id: row5
                    Image {
                        x: 0
                        y: 0
                        source: "images/svgs/solid/weight-hanging.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "Payload"
                    }
                    spacing: 8
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
                    text: "Motor"
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
                rows: 2
                Column {

                    spacing: 8
                    ParamRow {
                        text: "TimeStamp"
                        span: 6
                    }
                    ParamRow {
                        text: "BMS1 Voltage"
                        span: 6
                    }
                    ParamRow {
                        text: "BMS1 Absorption"
                        span: 6
                    }
                    ParamRow {
                        text: "BMS1 Temperature"
                        span: 6
                    }

                    ParamRow {
                        text: "MotorA RealPosition"
                        span: 8
                    }

                    ParamRow {
                        text: "MotorA DemandPosition"
                        span: 8
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    ParamRow {
                        text: "MotorA Torque"
                        span: 5
                    }
                    ParamRow {
                        text: "MotorA Temp"
                        span: 5
                    }

                    ParamRow {
                        text: "MotorB RealPosition"
                        span: 8
                    }
                    ParamRow {
                        text: "MotorB DemandPosition"
                        span: 8
                    }

                    ParamRow {
                        text: "MotorB Torque"
                        span: 5
                    }

                    ParamRow {
                        text: "MotorB Temp"
                        span: 5
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "RS232 HW failure"
                    }
                    StatusLight {
                        text: "CAN HW failure"
                    }
                    StatusLight {
                        text: "PT100 HW failure"
                    }
                    StatusLight {
                        text: "GPIO HW failure"
                    }

                    StatusLight {
                        text: "MotorControllerA comm error"
                    }
                    StatusLight {
                        text: "MotorControllerB comm error"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "PT100 A sensor breakage"
                    }
                    StatusLight {
                        text: "PT100 B sensor breakage"
                    }

                    StatusLight {
                        text: "BMS comm error"
                    }
                    StatusLight {
                        text: "MotorA breakage error"
                    }
                    StatusLight {
                        text: "MotorB breakage error"
                    }
                    StatusLight {
                        text: "MotorA demand pos error"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "MotorB demand pos error"
                    }
                    StatusLight {
                        text: "MotorA over-torque error"
                    }

                    StatusLight {
                        text: "MotorB over-torque error"
                    }
                    StatusLight {
                        text: "MotorA over-current error"
                    }

                    StatusLight {
                        text: "MotorB over-current error"
                    }
                    StatusLight {
                        text: "MotorA under-voltage error"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "MotorB under-voltage error"
                    }
                    StatusLight {
                        text: "MotorA resolver err"
                    }

                    StatusLight {
                        text: "MotorB resolver error"
                    }
                    StatusLight {
                        text: "BMS INDICATION"
                    }
                    StatusLight {
                        text: "BMS FAULT"
                    }
                    StatusLight {
                        text: "BMS REQUEST"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "Battery LOW"
                    }
                    ParamRow {
                        text: "Charge %"
                        span: 3
                    }

                    StatusLight {
                        text: "Battery OVERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        text: "Battery OVERVOLTAGE FAULT"
                    }
                    StatusLight {
                        text: "Battery UNDERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        text: "Battery UNDERVOLTAGE FAULT"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    StatusLight {
                        text: "Battery EXCESSIVE INDICATION"
                    }
                    StatusLight {
                        text: "Battery EXCESSIVE FAULT"
                    }

                    StatusLight {
                        text: "Battery temp HIGH INDICATION"
                    }
                    StatusLight {
                        text: "Battery temp HIGH FAULT"
                    }

                    StatusLight {
                        text: "Battery temp LOW INDICATION"
                    }
                    StatusLight {
                        text: "Battery temp LOW FAULT"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "Cell UNDERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        text: "Cell UNDERVOLTAGE FAULT"
                    }

                    StatusLight {
                        text: "Cell OVERVOLTAGE INDICATION"
                    }
                    StatusLight {
                        text: "Cell OVERVOLTAGE FAULT"
                    }
                    StatusLight {
                        text: "Cell voltage difference INDICATION"
                    }
                    StatusLight {
                        text: "Cell voltage difference FAULT"
                    }
                }

                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    StatusLight {
                        text: "Cell temp difference INDICATION"
                    }
                    StatusLight {
                        text: "Cell temp difference FAULT"
                    }

                    StatusLight {
                        text: "Cell temp sensor FAULT"
                    }
                    StatusLight {
                        text: "Generic HW FAULT"
                    }

                    StatusLight {
                        text: "Charge switch FAULT"
                    }
                    StatusLight {
                        text: "Discharge switch FAULT"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop

                    StatusLight {
                        text: "Self-test FAULT"
                    }
                    StatusLight {
                        text: "Collection line FAULT"
                    }

                    StatusLight {
                        text: "Temp line FAULT"
                    }
                    StatusLight {
                        text: "BMS alarm FAULT"
                    }
                    StatusLight {
                        text: "Activity limit request"
                    }
                    StatusLight {
                        text: "Discharge current limit request"
                    }
                }
                Column {
                    spacing: 8
                    Layout.alignment: Qt.AlignTop
                    StatusLight {
                        text: "Consumption STOP request"
                    }
                    StatusLight {
                        text: "Charging temp low FAULT"
                    }
                    StatusLight {
                        text: "Charging temp high FAULT"
                    }
                    StatusLight {
                        text: "Excessive charging current FAULT"
                    }
                }
            }
        }
        Rectangle {
            id: rectangle1
            width: 200
            height: 200
            color: "#d9d9d9"
            Layout.fillWidth: true
            Layout.preferredHeight: 1
        }

        Row {
            Layout.fillWidth: true
            Layout.preferredHeight: childrenRect.height + 20
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
                anchors.verticalCenter: parent.verticalCenter
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
            id: rectangle3
            width: 200
            height: 200
            color: "#d9d9d9"
            Layout.preferredHeight: 1
            Layout.fillWidth: true
        }

        Row {
            Layout.fillWidth: true
            Layout.preferredHeight: childrenRect.height + 20
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
                    text: "Storage status"

                    transform: Rotation {
                        angle: 90
                        origin.x: 25
                    }
                }
            }
            Grid {
                id: gridStorage
                anchors.verticalCenter: parent.verticalCenter
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
    D{i:0;height:1080;width:1600}D{i:3}D{i:4}D{i:2}D{i:7}D{i:8}D{i:6}D{i:11}D{i:16}D{i:21}
D{i:26}D{i:30}D{i:35}D{i:40}D{i:45}D{i:10}D{i:50}D{i:52}D{i:55}D{i:56}D{i:57}D{i:58}
D{i:51}D{i:59}D{i:62}D{i:63}D{i:61}D{i:64}D{i:65}D{i:67}D{i:68}D{i:66}D{i:69}D{i:60}
D{i:5}D{i:70}D{i:73}D{i:74}D{i:72}D{i:78}D{i:79}D{i:80}D{i:81}D{i:82}D{i:83}D{i:77}
D{i:85}D{i:86}D{i:87}D{i:88}D{i:89}D{i:90}D{i:84}D{i:92}D{i:93}D{i:94}D{i:95}D{i:96}
D{i:97}D{i:91}D{i:99}D{i:100}D{i:101}D{i:102}D{i:103}D{i:104}D{i:98}D{i:106}D{i:107}
D{i:108}D{i:109}D{i:110}D{i:111}D{i:105}D{i:113}D{i:114}D{i:115}D{i:116}D{i:117}D{i:118}
D{i:112}D{i:120}D{i:121}D{i:122}D{i:123}D{i:124}D{i:125}D{i:119}D{i:127}D{i:128}D{i:129}
D{i:130}D{i:131}D{i:132}D{i:126}D{i:134}D{i:135}D{i:136}D{i:137}D{i:138}D{i:139}D{i:133}
D{i:141}D{i:142}D{i:143}D{i:144}D{i:145}D{i:146}D{i:140}D{i:148}D{i:149}D{i:150}D{i:151}
D{i:152}D{i:153}D{i:147}D{i:155}D{i:156}D{i:157}D{i:158}D{i:154}D{i:76}D{i:71}D{i:159}
D{i:162}D{i:163}D{i:161}D{i:166}D{i:167}D{i:168}D{i:169}D{i:170}D{i:171}D{i:172}D{i:173}
D{i:174}D{i:175}D{i:176}D{i:177}D{i:178}D{i:179}D{i:180}D{i:181}D{i:182}D{i:183}D{i:184}
D{i:185}D{i:186}D{i:187}D{i:188}D{i:189}D{i:190}D{i:191}D{i:192}D{i:193}D{i:194}D{i:195}
D{i:196}D{i:197}D{i:198}D{i:199}D{i:200}D{i:201}D{i:202}D{i:203}D{i:204}D{i:165}D{i:160}
D{i:205}D{i:208}D{i:209}D{i:207}D{i:212}D{i:213}D{i:214}D{i:215}D{i:216}D{i:217}D{i:218}
D{i:219}D{i:220}D{i:221}D{i:222}D{i:223}D{i:224}D{i:225}D{i:226}D{i:227}D{i:228}D{i:229}
D{i:230}D{i:231}D{i:232}D{i:233}D{i:234}D{i:211}D{i:206}D{i:235}D{i:1}
}
##^##*/

