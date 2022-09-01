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

    property alias txtQuaternion0: txtQuaternion0.value
    property alias txtQuaternion1: txtQuaternion1.value
    property alias txtQuaternion2: txtQuaternion2.value
    property alias txtQuaternion3: txtQuaternion3.value
    property alias txtTelemetryStatusMask: txtTelemetryStatusMask.value
    property alias txtNumberOfGPSSatellite: txtNumberOfGPSSatellite.value

    width: Constants.width / 2 //750 //C
    height: Constants.height //667 //
    color: "#ffffff"
    property alias statusLight0: statusLight0
    property alias statusLight31: statusLight31
    property alias statusLight30: statusLight30
    property alias statusLight29: statusLight29
    property alias statusLight28: statusLight28
    property alias statusLight27: statusLight27
    property alias statusLight26: statusLight26
    property alias statusLight25: statusLight25
    property alias statusLight24: statusLight24
    property alias statusLight23: statusLight23
    property alias statusLight22: statusLight22
    property alias statusLight21: statusLight21
    property alias statusLight20: statusLight20
    property alias statusLight19: statusLight19
    property alias statusLight18: statusLight18
    property alias statusLight17: statusLight17
    property alias statusLight16: statusLight16
    property alias statusLight15: statusLight15
    property alias statusLight14: statusLight14
    property alias statusLight13: statusLight13
    property alias statusLight12: statusLight12
    property alias statusLight11: statusLight11
    property alias statusLight10: statusLight10
    property alias statusLight9: statusLight9
    property alias statusLight8: statusLight8
    property alias statusLight7: statusLight7
    property alias statusLight6: statusLight6
    property alias statusLight5: statusLight5
    property alias statusLight4: statusLight4
    property alias statusLight3: statusLight3
    property alias statusLight2: statusLight2
    property alias statusLight1: statusLight1
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
                    text: "Quaternion"
                }

                ParamRow {
                    text: "Q0"
                    id: txtQuaternion0
                }
                ParamRow {
                    text: "Q1"
                    id: txtQuaternion1
                }
                ParamRow {
                    text: "Q2"
                    id: txtQuaternion2
                }

                ParamRow {
                    text: "Q3"
                    id: txtQuaternion3
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
                ParamRow {
                    text: "Telemetry Status Mask"
                    span: 9
                    id: txtTelemetryStatusMask
                }

                Grid {
                    id: grid
                    columnSpacing: 16
                    rowSpacing: 16
                    flow: Grid.TopToBottom
                    columns: 4
                    rows: 8

                    StatusLight {
                        id: statusLight0
                        text: "0 - Anemom NOT present"
                    }

                    StatusLight {
                        id: statusLight1
                        text: "1 - RD Altimeter NOT present"
                    }

                    StatusLight {
                        id: statusLight2
                        text: "2 - GNSS NOT present"
                    }

                    StatusLight {
                        id: statusLight3
                        text: "3 - PL Altimeter NOT present"
                    }
                    StatusLight {
                        id: statusLight4
                        text: "4 - Anemom TO"
                    }

                    StatusLight {
                        id: statusLight5
                        text: "5 - Anemom CS"
                    }
                    StatusLight {
                        id: statusLight6
                        text: "6 - RD Altimeter TO"
                    }

                    StatusLight {
                        id: statusLight7
                        text: "7 - RD Altimeter CS"
                    }
                    StatusLight {
                        id: statusLight8
                        text: "8 - GNSS pack1 TO"
                    }

                    StatusLight {
                        id: statusLight9
                        text: "9 - GNSS pack1 CS"
                    }
                    StatusLight {
                        id: statusLight10
                        text: "10 - GNSS pack2 TO"
                    }

                    StatusLight {
                        id: statusLight11
                        text: "11 - GNSS pack2 CS"
                    }

                    StatusLight {
                        id: statusLight12
                        text: "12 - GNSS pack3 TO"
                    }

                    StatusLight {
                        id: statusLight13
                        text: "13 - GNSS pack3 CS"
                    }
                    StatusLight {
                        id: statusLight14
                        text: "14 - PL Altimeter TO"
                    }

                    StatusLight {
                        id: statusLight15
                        text: "15 - RS232 HW failure"
                    }
                    StatusLight {
                        id: statusLight16
                        text: "16 - RS422 HW failure"
                    }

                    StatusLight {
                        id: statusLight17
                        text: "17 - CAN HW failure"
                    }
                    StatusLight {
                        id: statusLight18
                        text: "18 - GNSS_time NOT valid"
                    }

                    StatusLight {
                        id: statusLight19
                        text: "19 - GNSS_pos NOT valid"
                    }
                    StatusLight {
                        id: statusLight20
                        text: "20 - Anem_speed NOT valid"
                    }

                    StatusLight {
                        id: statusLight21
                        text: "21 - Anem_temp NOT valid"
                    }

                    StatusLight {
                        id: statusLight22
                        text: "22 - RD_altitude NOT valid"
                    }

                    StatusLight {
                        id: statusLight23
                        text: "23 - PL_altitude NOT valid"
                    }
                    StatusLight {
                        id: statusLight24
                        text: "24 - GNSS_vel NOT valid"
                    }

                    StatusLight {
                        id: statusLight25
                        text: "25 - GNSS_acc NOT valid"
                    }
                    StatusLight {
                        id: statusLight26
                        text: "26 - GNSS_ECEFpos NOT valid"
                    }

                    StatusLight {
                        id: statusLight27
                        text: "27 - GNSS_ECEFvel NOT valid"
                    }
                    StatusLight {
                        id: statusLight28
                        text: "28 - GNSS_angle NOT valid"
                    }

                    StatusLight {
                        id: statusLight29
                        text: "29 - GNSS_angRate NOT valid"
                    }
                    StatusLight {
                        id: statusLight30
                        text: "30 - GNSS_quat NOT valid"
                    }

                    StatusLight {
                        id: statusLight31
                        text: "31 - GNSS_fix done"
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
