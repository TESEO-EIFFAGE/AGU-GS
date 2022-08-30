import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property alias txtTimeStamp: txtTimeStamp.text
    property alias txtTimeStampRIO: txtTimeStampRIO.text
    property alias txtLatitude: txtLatitude.text
    property alias txtLongitude: txtLongitude.text
    property alias txtGNSSAltitude: txtGNSSAltitude.text
    property alias txtAirSpeed_UVector: txtAirSpeed_UVector.text

    property alias txtAirSpeed_VVector: txtAirSpeed_VVector.text
    property alias txtAirSpeed_WVector: txtAirSpeed_WVector.text
    property alias txtAirTemperature: txtAirTemperature.text
    property alias txtAltitudeFromRadarAltimeter: txtAltitudeFromRadarAltimeter.text
    property alias txtAltitudeFromPayloadAltimeter: txtAltitudeFromPayloadAltimeter.text
    property alias txtLinearVelocityHorizontal: txtLinearVelocityHorizontal.text

    property alias txtLinearVelocityVertical: txtLinearVelocityVertical.text
    property alias txtPositionAccuracy: txtPositionAccuracy.text
    property alias txtSpeedAccuracy: txtSpeedAccuracy.text
    property alias txtLinearAccelerationX: txtLinearAccelerationX.text
    property alias txtLinearAccelerationY: txtLinearAccelerationY.text
    property alias txtLinearAccelerationZ: txtLinearAccelerationZ.text

    property alias txtECEFVectorPositionX: txtECEFVectorPositionX.text
    property alias txtECEFVectorPositionY: txtECEFVectorPositionY.text
    property alias txtECEFVectorPositionZ: txtECEFVectorPositionZ.text
    property alias txtECEFVectorVelocityX: txtECEFVectorVelocityX.text
    property alias txtECEFVectorVelocityY: txtECEFVectorVelocityY.text
    property alias txtECEFVectorVelocityZ: txtECEFVectorVelocityZ.text

    property alias txtRollAngle: txtRollAngle.text
    property alias txtPitchAngle: txtPitchAngle.text
    property alias txtYawAngle: txtYawAngle.text
    property alias txtAngularRateRoll: txtAngularRateRoll.text
    property alias txtAngularRatePitch: txtAngularRatePitch.text
    property alias txtAngularRateYaw: txtAngularRateYaw.text

    property alias txtQuaternion0: txtQuaternion0.text
    property alias txtQuaternion1: txtQuaternion1.text
    property alias txtQuaternion2: txtQuaternion2.text
    property alias txtQuaternion3: txtQuaternion3.text
    property alias txtTelemetryStatusMask: txtTelemetryStatusMask.text
    property alias txtNumberOfGPSSatellite: txtNumberOfGPSSatellite.text

    property alias txtLatitudeGPSData: txtLatitudeGPSData.text
    property alias txtLongitudeGPSData: txtLongitudeGPSData.text
    property alias txtAltitudeGPSData: txtAltitudeGPSData.text
    property alias txtHasFix: txtHasFix.text
    property alias txtHourGPSData: txtHourGPSData.text
    property alias txtminuteGPSData: txtminuteGPSData.text
    property alias txtsecondGPSData: txtsecondGPSData.text

    width: 667 //Constants.width / 2
    height: 750 //Constants.height
    color: "#ffffff"
    Column {
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        spacing: 8
        RowLayout {
            spacing: 8
            ParamLabel {
                text: "TimeStamp"
            }
            ParamValue {
                id: txtTimeStamp
                text: ""
            }
        }
        Row {
            //width: parent.width
            spacing: 8
            ParamLabel {
                text: "TimeStamp RIO"
            }
            ParamValue {
                id: txtTimeStampRIO
            }
        }
    }
    ColumnLayout {
        anchors.fill: parent
        spacing: 16
        anchors.margins: 16
        ParamGrpLabel {
            Layout.topMargin: 8
            text: "Position Info"
        }
        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                //Layout.alignment: Qt.AlignRight
                spacing: 8
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Latitude"
                    }
                    ParamValue {
                        id: txtLatitude
                    }
                }

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Longitude"
                    }
                    ParamValue {
                        id: txtLongitude
                    }
                }
                Row {

                    spacing: 8
                    ParamLabel {
                        text: "Altitude"
                    }
                    ParamValue {
                        id: txtGNSSAltitude
                    }
                }
            }

            Column {
                spacing: 8
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Position X"
                    }
                    ParamValue {
                        id: txtECEFVectorPositionX
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Position Y"
                    }
                    ParamValue {
                        id: txtECEFVectorPositionY
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Position Z"
                    }
                    ParamValue {
                        id: txtECEFVectorPositionZ
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Altitude From Radar"
                    }
                    ParamValue {
                        id: txtAltitudeFromRadarAltimeter
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Altitude From Payload"
                    }
                    ParamValue {
                        id: txtAltitudeFromPayloadAltimeter
                    }
                }
            }
        }
        ParamGrpLabel {
            text: "Air Info"

        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Air Speed UVector"
                    }
                    ParamValue {
                        id: txtAirSpeed_UVector
                    }
                }

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Air Speed VVector"
                    }
                    ParamValue {
                        id: txtAirSpeed_VVector
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Air Speed WVector"
                    }
                    ParamValue {
                        id: txtAirSpeed_WVector
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Air Temperature"
                    }
                    ParamValue {
                        id: txtAirTemperature
                    }
                }
            }
        }
        ParamGrpLabel {
            text: "Velocity Info"

        }
        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Linear Velocity Horizontal"
                    }
                    ParamValue {
                        id: txtLinearVelocityHorizontal
                    }
                }

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Linear Velocity Vertical"
                    }
                    ParamValue {
                        id: txtLinearVelocityVertical
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Vector Velocity X"
                    }
                    ParamValue {
                        id: txtECEFVectorVelocityX
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Vector Velocity Y"
                    }
                    ParamValue {
                        id: txtECEFVectorVelocityY
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "ECEF Vector Velocity Z"
                    }
                    ParamValue {
                        id: txtECEFVectorVelocityZ
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Linear Acceleration X"
                    }
                    ParamValue {
                        id: txtLinearAccelerationX
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Linear Acceleration Y"
                    }
                    ParamValue {
                        id: txtLinearAccelerationY
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Linear Acceleration Z"
                    }
                    ParamValue {
                        id: txtLinearAccelerationZ
                    }
                }
            }
        }
        ParamGrpLabel {
            text: "Rotation Info"

        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Roll Angle"
                    }
                    ParamValue {
                        id: txtRollAngle
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Pitch Angle"
                    }
                    ParamValue {
                        id: txtPitchAngle
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Yaw Angle"
                    }
                    ParamValue {
                        id: txtYawAngle
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Angular Rate Roll"
                    }
                    ParamValue {
                        id: txtAngularRateRoll
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Angular Rate Pitch"
                    }
                    ParamValue {
                        id: txtAngularRatePitch
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Angular Rate Yaw"
                    }
                    ParamValue {
                        id: txtAngularRateYaw
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Quaternion 0"
                    }
                    ParamValue {
                        id: txtQuaternion0
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Quaternion 1"
                    }
                    ParamValue {
                        id: txtQuaternion1
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Quaternion 2"
                    }
                    ParamValue {
                        id: txtQuaternion2
                    }
                }

                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Quaternion 3"
                    }
                    ParamValue {
                        id: txtQuaternion3
                    }
                }
            }
        }
        ParamGrpLabel {
            text: "Status Info"

        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Position Accuracy"
                    }
                    ParamValue {
                        id: txtPositionAccuracy
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Speed Accuracy"
                    }
                    ParamValue {
                        id: txtSpeedAccuracy
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Telemetry Status Mask"
                    }
                    ParamValue {
                        id: txtTelemetryStatusMask
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Number Of GPS Satellite"
                    }
                    ParamValue {
                        id: txtNumberOfGPSSatellite
                    }
                }
            }
        }

        ParamGrpLabel {
            text: "GPSdata"

        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Latitude from GS GPS"
                    }
                    ParamValue {
                        id: txtLatitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Longitude from GS GPS"
                    }
                    ParamValue {
                        id: txtLongitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Altitude from GS GPS"
                    }
                    ParamValue {
                        id: txtAltitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "HasFix from GS GPS"
                    }
                    ParamValue {
                        id: txtHasFix
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Hour from GS GPS"
                    }
                    ParamValue {
                        id: txtHourGPSData
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Minute from GS GPS"
                    }
                    ParamValue {
                        id: txtminuteGPSData
                    }
                }
                Row {
                    spacing: 8
                    ParamLabel {
                        text: "Second from GS GPS"
                    }
                    ParamValue {
                        id: txtsecondGPSData
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
