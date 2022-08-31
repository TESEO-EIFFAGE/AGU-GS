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
        spacing: 16
        anchors.margins: 32

        Row {
            id: row
            spacing: 32

            SectionLabel {
                text: "Flight Segment"
                anchors.verticalCenter: parent.verticalCenter
            }

            ParamRow {
                text: "TimeStamp RIO"
                anchors.verticalCenter: parent.verticalCenter
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

            ParamGrpLabel {
                text: "GNSS"
                Layout.topMargin: 8
            }
        }

        ParamSubGrpLabel {
            text: "Position"
        }
        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                //Layout.alignment: Qt.AlignRight
                spacing: 8
                ParamRow {
                    id: txtLatitude
                    text: "Latitude"
                }

                ParamRow {
                    text: "Longitude"
                    id: txtLongitude
                }
                ParamRow {
                    text: "Altitude"
                    id: txtGNSSAltitude
                }

                ParamRow {
                    text: "# GPS satellites"
                    id: txtNumberOfGPSSatellite
                }
            }

            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                spacing: 8
                ParamRow {
                    text: "ECEF Position X"
                    id: txtECEFVectorPositionX
                }
                ParamRow {
                    text: "ECEF Position Y"
                    id: txtECEFVectorPositionY
                }
                ParamRow {
                    text: "ECEF Position Z"
                    id: txtECEFVectorPositionZ
                }
            }
            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                spacing: 8

                ParamRow {
                    text: "Altitude From Radar"
                    id: txtAltitudeFromRadarAltimeter
                }
                ParamRow {
                    text: "Altitude From Payload"
                    id: txtAltitudeFromPayloadAltimeter
                }

                ParamRow {
                    text: "Position Accuracy"
                    id: txtPositionAccuracy
                }

                ParamRow {
                    text: "Speed Accuracy"
                    id: txtSpeedAccuracy
                }
            }
        }
        ParamSubGrpLabel {
            text: "Velocity"
        }

        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "Linear Velocity Horizontal"
                    id: txtLinearVelocityHorizontal
                }

                ParamRow {
                    text: "Linear Velocity Vertical"
                    id: txtLinearVelocityVertical
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "ECEF Vector Velocity X"
                    id: txtECEFVectorVelocityX
                }
                ParamRow {
                    text: "ECEF Vector Velocity Y"
                    id: txtECEFVectorVelocityY
                }
                ParamRow {
                    text: "ECEF Vector Velocity Z"
                    id: txtECEFVectorVelocityZ
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "Linear Acceleration X"
                    id: txtLinearAccelerationX
                }
                ParamRow {
                    text: "Linear Acceleration Y"
                    id: txtLinearAccelerationY
                }
                ParamRow {
                    text: "Linear Acceleration Z"
                    id: txtLinearAccelerationZ
                }
            }
        }

        ParamSubGrpLabel {
            text: "Rotation"
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                ParamRow {
                    text: "Roll Angle"
                    id: txtRollAngle
                }
                ParamRow {
                    text: "Pitch Angle"
                    id: txtPitchAngle
                }
                ParamRow {
                    text: "Yaw Angle"
                    id: txtYawAngle
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "Angular Rate Roll"
                    id: txtAngularRateRoll
                }
                ParamRow {
                    text: "Angular Rate Pitch"
                    id: txtAngularRatePitch
                }

                ParamRow {
                    text: "Angular Rate Yaw"
                    id: txtAngularRateYaw
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "Quaternion 0"
                    id: txtQuaternion0
                }
                ParamRow {
                    text: "Quaternion 1"
                    id: txtQuaternion1
                }
                ParamRow {
                    text: "Quaternion 2"
                    id: txtQuaternion2
                }

                ParamRow {
                    text: "Quaternion 3"
                    id: txtQuaternion3
                }
            }
        }

        Row {
            id: row2
            width: 200
            height: 400
            spacing: 8

            Image {
                id: wind
                x: 0
                y: 0
                source: "images/svgs/solid/wind.svg"
                sourceSize.height: 24
                sourceSize.width: 24
                fillMode: Image.PreserveAspectFit
            }
            ParamGrpLabel {
                text: "Anemometer"
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                ParamRow {
                    text: "Air Speed UVector"
                    id: txtAirSpeed_UVector
                }

                ParamRow {
                    text: "Air Speed VVector"
                    id: txtAirSpeed_VVector
                }
                ParamRow {
                    text: "Air Speed WVector"
                    id: txtAirSpeed_WVector
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                ParamRow {
                    text: "Air Temperature"
                    id: txtAirTemperature
                }
            }
        }
        Row {
            id: row3
            width: 200
            height: 400
            spacing: 8

            Image {
                id: triangleexclamation
                x: 0
                y: 0
                width: 24
                source: "images/svgs/solid/triangle-exclamation.svg"
                fillMode: Image.PreserveAspectFit
            }

            ParamGrpLabel {
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
                    id: txtTelemetryStatusMask
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}

/*##^##
Designer {
    D{i:0;height:900;width:640}D{i:3}D{i:7}D{i:52}D{i:62}
}
##^##*/

