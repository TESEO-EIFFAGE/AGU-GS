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
            spacing: 48
            Layout.fillWidth: true
            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                //Layout.alignment: Qt.AlignRight
                spacing: 8

                ParamGrp2Label {
                    text: "Coordinates"
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
                    text: "ECEF Position"
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
                    text: "ECEF Velocity"
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
                    text: "Linear Velocity"
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
                    text: "Linear Acceleration"
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
                    text: "Angle"
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
                    columns: 16
                    rows: 16
                    flow: Grid.TopToBottom

                    StatusLight {
                        text: "0 - Anemom NOT present"
                    }

                    StatusLight {
                        text: "0 - Anemom NOT present"
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
