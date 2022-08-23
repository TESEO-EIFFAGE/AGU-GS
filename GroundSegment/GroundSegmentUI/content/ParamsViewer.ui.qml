import QtQuick 2.15
import QtQuick.Controls 2.15
//import GroundSegmentUI 1.0
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

    property alias txtLinearVelocityVertical:txtLinearVelocityVertical.text
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





    width: 200
    height: 200
    color: "#ffffff"
    ColumnLayout{
        anchors.fill:parent
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Label{
                id: txtTimeStamp

            }
            Column{
                width:parent.width
                Label{
                    text:"TimeStamp RIO"
                }
                Label{
                    id:txtTimeStampRIO
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Latitude"
                }
                Label{
                    id:txtLatitude
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"Longitude"
                }
                Label{
                    id:txtLongitude
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"GNSS Altitude"
                }
                Label{
                    id:txtGNSSAltitude
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Air Speed UVector"
                }
                Label{
                    id:txtAirSpeed_UVector
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Column{
                width:parent.width
                Label{
                    text:"Air Speed VVector"
                }
                Label{
                    id:txtAirSpeed_VVector
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Air Speed WVector"
                }
                Label{
                    id:txtAirSpeed_WVector
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Air Temperature"
                }
                Label{
                    id:txtAirTemperature
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"Altitude From RadarAltimeter"
                }
                Label{
                    id:txtAltitudeFromRadarAltimeter
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Altitude From Payload Altimeter"
                }
                Label{
                    id:txtAltitudeFromPayloadAltimeter
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Linear Velocity Horizontal"
                }
                Label{
                    id:txtLinearVelocityHorizontal
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Column{
                width:parent.width
                Label{
                    text:"Linear Velocity Vertical"
                }
                Label{
                    id:txtLinearVelocityVertical
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Position Accuracy"
                }
                Label{
                    id:txtPositionAccuracy
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Speed Accuracy"
                }
                Label{
                    id:txtSpeedAccuracy
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"Linear Acceleration X"
                }
                Label{
                    id:txtLinearAccelerationX
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Linear Acceleration Y"
                }
                Label{
                    id:txtLinearAccelerationY
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Linear Acceleration Z"
                }
                Label{
                    id:txtLinearAccelerationZ
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Position X"
                }
                Label{
                    id:txtECEFVectorPositionX
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Position Y"
                }
                Label{
                    id:txtECEFVectorPositionY
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Position Z"
                }
                Label{
                    id:txtECEFVectorPositionZ
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Velocity X"
                }
                Label{
                    id:txtECEFVectorVelocityX
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Velocity Y"
                }
                Label{
                    id:txtECEFVectorVelocityY
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"ECEF Vector Velocity Z"
                }
                Label{
                    id:txtECEFVectorVelocityZ
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Column{
                width:parent.width
                Label{
                    text:"Roll Angle"
                }
                Label{
                    id:txtRollAngle
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Pitch Angle"
                }
                Label{
                    id:txtPitchAngle
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Yaw Angle"
                }
                Label{
                    id:txtYawAngle
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"Angular Rate Roll"
                }
                Label{
                    id:txtAngularRateRoll
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Angular Rate Pitch"
                }
                Label{
                    id:txtAngularRatePitch
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Angular Rate Yaw"
                }
                Label{
                    id:txtAngularRateYaw
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Column{
                width:parent.width
                Label{
                    text:"Quaternion 0"
                }
                Label{
                    id:txtQuaternion0
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Quaternion 1"
                }
                Label{
                    id:txtQuaternion1
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Quaternion 2"
                }
                Label{
                    id:txtQuaternion2
                }
            }

            Column{
                width:parent.width
                Label{
                    text:"Quaternion 3"
                }
                Label{
                    id:txtQuaternion3
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Telemetry Status Mask"
                }
                Label{
                    id:txtTelemetryStatusMask
                }
            }
            Column{
                width:parent.width
                Label{
                    text:"Number Of GPS Satellite"
                }
                Label{
                    id:txtNumberOfGPSSatellite
                }
            }
        }
    }
}

