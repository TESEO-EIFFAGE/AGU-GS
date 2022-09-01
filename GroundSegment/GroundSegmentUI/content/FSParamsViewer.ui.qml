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
    property alias storageLight9: storageLight9
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
        spacing: 24
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
            id: row1
            width: 200
            height: 400
            spacing: 8

            Image {
                id: satellite
                source: "images/svgs/solid/satellite.svg"
                sourceSize.height: 24
                sourceSize.width: 24
                fillMode: Image.PreserveAspectFit
            }

            ParamGrp1Label {
                text: "GNSS"
                Layout.topMargin: 8
            }
        }
        RowLayout {
            spacing: 40 //48
            Layout.fillWidth: true
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
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
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

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            color: "#d9d9d9"
            Layout.preferredHeight: 1
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 104
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
                Layout.alignment: Qt.AlignTop
                spacing: 8
            }

            Column {
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
                Layout.alignment: Qt.AlignTop
                spacing: 8
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
            id: row3
            width: 200
            height: 400
            spacing: 8

            Image {
                x: 0
                y: 0
                width: 24
                source: "images/svgs/solid/triangle-exclamation.svg"
                fillMode: Image.PreserveAspectFit
            }

            ParamGrp1Label {
                text: "Telemetry status"
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                Layout.alignment: Qt.AlignTop

                Grid {
                    id: grid
                    columnSpacing: 16
                    rowSpacing: 16
                    flow: Grid.TopToBottom
                    columns: 4
                    rows: 8

                    StatusLight {
                        id: telemetryLight0
                        text: "0 - Anemom NOT present"
                    }

                    StatusLight {
                        id: telemetryLight1
                        text: "1 - RD Altimeter NOT present"
                    }

                    StatusLight {
                        id: telemetryLight2
                        text: "2 - GNSS NOT present"
                    }

                    StatusLight {
                        id: telemetryLight3
                        text: "3 - PL Altimeter NOT present"
                    }
                    StatusLight {
                        id: telemetryLight4
                        text: "4 - Anemom TO"
                    }

                    StatusLight {
                        id: telemetryLight5
                        text: "5 - Anemom CS"
                    }
                    StatusLight {
                        id: telemetryLight6
                        text: "6 - RD Altimeter TO"
                    }

                    StatusLight {
                        id: telemetryLight7
                        text: "7 - RD Altimeter CS"
                    }
                    StatusLight {
                        id: telemetryLight8
                        text: "8 - GNSS pack1 TO"
                    }

                    StatusLight {
                        id: telemetryLight9
                        text: "9 - GNSS pack1 CS"
                    }
                    StatusLight {
                        id: telemetryLight10
                        text: "10 - GNSS pack2 TO"
                    }

                    StatusLight {
                        id: telemetryLight11
                        text: "11 - GNSS pack2 CS"
                    }

                    StatusLight {
                        id: telemetryLight12
                        text: "12 - GNSS pack3 TO"
                    }

                    StatusLight {
                        id: telemetryLight13
                        text: "13 - GNSS pack3 CS"
                    }
                    StatusLight {
                        id: telemetryLight14
                        text: "14 - PL Altimeter TO"
                    }

                    StatusLight {
                        id: telemetryLight15
                        text: "15 - RS232 HW failure"
                    }
                    StatusLight {
                        id: telemetryLight16
                        text: "16 - RS422 HW failure"
                    }

                    StatusLight {
                        id: telemetryLight17
                        text: "17 - CAN HW failure"
                    }
                    StatusLight {
                        id: telemetryLight18
                        text: "18 - GNSS_time NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight19
                        text: "19 - GNSS_pos NOT valid"
                    }
                    StatusLight {
                        id: telemetryLight20
                        text: "20 - Anem_speed NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight21
                        text: "21 - Anem_temp NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight22
                        text: "22 - RD_altitude NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight23
                        text: "23 - PL_altitude NOT valid"
                    }
                    StatusLight {
                        id: telemetryLight24
                        text: "24 - GNSS_vel NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight25
                        text: "25 - GNSS_acc NOT valid"
                    }
                    StatusLight {
                        id: telemetryLight26
                        text: "26 - GNSS_ECEFpos NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight27
                        text: "27 - GNSS_ECEFvel NOT valid"
                    }
                    StatusLight {
                        id: telemetryLight28
                        text: "28 - GNSS_angle NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight29
                        text: "29 - GNSS_angRate NOT valid"
                    }
                    StatusLight {
                        id: telemetryLight30
                        text: "30 - GNSS_quat NOT valid"
                    }

                    StatusLight {
                        id: telemetryLight31
                        text: "31 - GNSS_fix done"
                    }
                }
            }
        }
        Row {
            id: row6
            width: 200
            height: 400
            spacing: 8

            Image {
                x: 0
                y: 0
                width: 24
                source: "images/svgs/solid/database.svg"
                fillMode: Image.PreserveAspectFit
            }

            ParamGrp1Label {
                text: "Storage status"
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                Layout.alignment: Qt.AlignTop
                Grid {
                    id: gridStorage
                    columnSpacing: 16
                    rowSpacing: 16
                    flow: Grid.TopToBottom
                    columns: 4
                    rows: 6

                    StatusLight {
                        id: storageLight0
                        text: "0 - uSD HW failure"
                    }

                    StatusLight {
                        id: storageLight1
                        text: "1 - uSD not present error"
                    }

                    StatusLight {
                        id: storageLight2
                        text: "2 - uSD full"
                    }

                    StatusLight {
                        id: storageLight3
                        text: "3 - System Status log write error"
                    }
                    StatusLight {
                        id: storageLight4
                        text: "4 - Telemetry module log write error"
                    }

                    StatusLight {
                        id: storageLight5
                        text: "5 - Storage module log write error"
                    }
                    StatusLight {
                        id: storageLight6
                        text: "6 - Radio link module log write error"
                    }

                    StatusLight {
                        id: storageLight7
                        text: "7 - Motor control log write error"
                    }
                    StatusLight {
                        id: storageLight8
                        text: "8 - Guidance module log write error"
                    }

                    StatusLight {
                        id: storageLight9
                        text: "9 - "
                    }
                    StatusLight {
                        id: storageLight10
                        text: "10 - PCNC initialization verification error"
                    }

                    StatusLight {
                        id: storageLight11
                        text: "11 - PCNC initialization storage error"
                    }

                    StatusLight {
                        id: storageLight12
                        text: "12 - PCNC flight path verification error"
                    }

                    StatusLight {
                        id: storageLight13
                        text: "13 - PCNC flight path storage error"
                    }
                    StatusLight {
                        id: storageLight14
                        text: "14 - Trim script verification error"
                    }

                    StatusLight {
                        id: storageLight15
                        text: "15 - Trim script storage error"
                    }
                    StatusLight {
                        id: storageLight16
                        text: "16 - Open-Loop script verification error"
                    }

                    StatusLight {
                        id: storageLight17
                        text: "17 - Open-Loop script storage error"
                    }
                    StatusLight {
                        id: storageLight18
                        text: "18 - Recovery-A script verification error"
                    }

                    StatusLight {
                        id: storageLight19
                        text: "19 - Recovery-A script storage error"
                    }
                    StatusLight {
                        id: storageLight20
                        text: "20 - Recovery-B script verification error"
                    }

                    StatusLight {
                        id: storageLight21
                        text: "21 - Recovery-B script storage error"
                    }

                    StatusLight {
                        id: storageLight22
                        text: "22 - Flare script verification error"
                    }

                    StatusLight {
                        id: storageLight23
                        text: "23 - Flare script storage error"
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
