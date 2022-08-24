import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11

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

    property alias txtLatitudeGPSData:  txtLatitudeGPSData.text
    property alias txtLongitudeGPSData: txtLongitudeGPSData.text
    property alias txtAltitudeGPSData:  txtAltitudeGPSData.text
    property alias txtHasFix:           txtHasFix.text
    property alias txtHourGPSData:      txtHourGPSData.text
    property alias txtminuteGPSData:    txtminuteGPSData.text
    property alias txtsecondGPSData:    txtsecondGPSData.text

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
            Label {
                text: "TimeStamp"
            }
            Label {
                id: txtTimeStamp
                text: ""
            }
        }
        Row {
            //width: parent.width
            spacing: 8
            Label {
                text: "TimeStamp RIO"
            }
            Label {
                id: txtTimeStampRIO
            }
        }
    }
    ColumnLayout {
        anchors.fill: parent
        spacing: 16
        anchors.margins: 16
        Label {
            Layout.topMargin: 8
            text: "Position Info"
            font.pixelSize: 16
        }
        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                //Layout.alignment: Qt.AlignRight
                spacing: 8
                Row {
                    spacing: 8
                    Label {
                        text: "Latitude"
                    }
                    Label {
                        id: txtLatitude
                    }
                }

                Row {
                    spacing: 8
                    Label {
                        text: "Longitude"
                    }
                    Label {
                        id: txtLongitude
                    }
                }
                Row {

                    spacing: 8
                    Label {
                        text: "Altitude"
                    }
                    Label {
                        id: txtGNSSAltitude
                    }
                }
            }

            Column {
                spacing: 8
                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Position X"
                    }
                    Label {
                        id: txtECEFVectorPositionX
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Position Y"
                    }
                    Label {
                        id: txtECEFVectorPositionY
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Position Z"
                    }
                    Label {
                        id: txtECEFVectorPositionZ
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Altitude From Radar"
                    }
                    Label {
                        id: txtAltitudeFromRadarAltimeter
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Altitude From Payload"
                    }
                    Label {
                        id: txtAltitudeFromPayloadAltimeter
                    }
                }
            }
        }
        Label {
            text: "Air Info"
            font.pointSize: 16
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Air Speed UVector"
                    }
                    Label {
                        id: txtAirSpeed_UVector
                    }
                }

                Row {
                    spacing: 8
                    Label {
                        text: "Air Speed VVector"
                    }
                    Label {
                        id: txtAirSpeed_VVector
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Air Speed WVector"
                    }
                    Label {
                        id: txtAirSpeed_WVector
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    Label {
                        text: "Air Temperature"
                    }
                    Label {
                        id: txtAirTemperature
                    }
                }
            }
        }
        Label {
            text: "Velocity Info"
            font.pixelSize: 16
        }
        RowLayout {
            spacing: 48
            Layout.fillWidth: true
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Linear Velocity Horizontal"
                    }
                    Label {
                        id: txtLinearVelocityHorizontal
                    }
                }

                Row {
                    spacing: 8
                    Label {
                        text: "Linear Velocity Vertical"
                    }
                    Label {
                        id: txtLinearVelocityVertical
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Vector Velocity X"
                    }
                    Label {
                        id: txtECEFVectorVelocityX
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Vector Velocity Y"
                    }
                    Label {
                        id: txtECEFVectorVelocityY
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "ECEF Vector Velocity Z"
                    }
                    Label {
                        id: txtECEFVectorVelocityZ
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Linear Acceleration X"
                    }
                    Label {
                        id: txtLinearAccelerationX
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Linear Acceleration Y"
                    }
                    Label {
                        id: txtLinearAccelerationY
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Linear Acceleration Z"
                    }
                    Label {
                        id: txtLinearAccelerationZ
                    }
                }
            }
        }
        Label {
            text: "Rotation Info"
            font.pixelSize: 16
        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    Label {
                        text: "Roll Angle"
                    }
                    Label {
                        id: txtRollAngle
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Pitch Angle"
                    }
                    Label {
                        id: txtPitchAngle
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Yaw Angle"
                    }
                    Label {
                        id: txtYawAngle
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Angular Rate Roll"
                    }
                    Label {
                        id: txtAngularRateRoll
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Angular Rate Pitch"
                    }
                    Label {
                        id: txtAngularRatePitch
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Angular Rate Yaw"
                    }
                    Label {
                        id: txtAngularRateYaw
                    }
                }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {
                    spacing: 8
                    Label {
                        text: "Quaternion 0"
                    }
                    Label {
                        id: txtQuaternion0
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Quaternion 1"
                    }
                    Label {
                        id: txtQuaternion1
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Quaternion 2"
                    }
                    Label {
                        id: txtQuaternion2
                    }
                }

                Row {
                    spacing: 8
                    Label {
                        text: "Quaternion 3"
                    }
                    Label {
                        id: txtQuaternion3
                    }
                }
            }
        }
        Label {
            text: "Status Info"
            font.pixelSize: 16
        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Row {
                    spacing: 8
                    Label {
                        text: "Position Accuracy"
                    }
                    Label {
                        id: txtPositionAccuracy
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Speed Accuracy"
                    }
                    Label {
                        id: txtSpeedAccuracy
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    Label {
                        text: "Telemetry Status Mask"
                    }
                    Label {
                        id: txtTelemetryStatusMask
                    }
                }
            }
            Column {
                Layout.alignment: Qt.AlignTop
                Row {
                    spacing: 8
                    Label {
                        text: "Number Of GPS Satellite"
                    }
                    Label {
                        id: txtNumberOfGPSSatellite
                    }
                }
            }
        }


        Label {
            text: "GPSdata"
            font.pixelSize: 16
        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 48
            Column {
                spacing: 8
                Row {
                    spacing: 8
                    Label {
                        text: "Latitude from GS GPS"
                    }
                    Label {
                        id: txtLatitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Longitude from GS GPS"
                    }
                    Label {
                        id: txtLongitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Altitude from GS GPS"
                    }
                    Label {
                        id: txtAltitudeGPSData
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "HasFix from GS GPS"
                    }
                    Label {
                        id: txtHasFix
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Hour from GS GPS"
                    }
                    Label {
                        id: txtHourGPSData
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Minute from GS GPS"
                    }
                    Label {
                        id: txtminuteGPSData
                    }
                }
                Row {
                    spacing: 8
                    Label {
                        text: "Second from GS GPS"
                    }
                    Label {
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
