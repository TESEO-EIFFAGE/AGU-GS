import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property int tabIndex: 0

    property alias txtTimeStampRIO: txtTimeStampRIO.value
    property alias txtLatitude: telemetryTab.txtLatitude
    property alias txtLongitude: telemetryTab.txtLongitude
    property alias txtGNSSAltitude: telemetryTab.txtGNSSAltitude
    property alias txtAirSpeed_UVector: telemetryTab.txtAirSpeed_UVector

    property alias txtAirSpeed_VVector: telemetryTab.txtAirSpeed_VVector
    property alias txtAirSpeed_WVector: telemetryTab.txtAirSpeed_WVector
    property alias txtAirTemperature: telemetryTab.txtAirTemperature
    property alias txtAltitudeFromRadarAltimeter: telemetryTab.txtAltitudeFromRadarAltimeter
    property alias txtAltitudeFromPayloadAltimeter: telemetryTab.txtAltitudeFromPayloadAltimeter
    property alias txtLinearVelocityHorizontal: telemetryTab.txtLinearVelocityHorizontal

    property alias txtLinearVelocityVertical: telemetryTab.txtLinearVelocityVertical
    property alias txtPositionAccuracy: telemetryTab.txtPositionAccuracy
    property alias txtSpeedAccuracy: telemetryTab.txtSpeedAccuracy
    property alias txtLinearAccelerationX: telemetryTab.txtLinearAccelerationX
    property alias txtLinearAccelerationY: telemetryTab.txtLinearAccelerationY
    property alias txtLinearAccelerationZ: telemetryTab.txtLinearAccelerationZ

    property alias txtECEFVectorPositionX: telemetryTab.txtECEFVectorPositionX
    property alias txtECEFVectorPositionY: telemetryTab.txtECEFVectorPositionY
    property alias txtECEFVectorPositionZ: telemetryTab.txtECEFVectorPositionZ
    property alias txtECEFVectorVelocityX: telemetryTab.txtECEFVectorVelocityX
    property alias txtECEFVectorVelocityY: telemetryTab.txtECEFVectorVelocityY
    property alias txtECEFVectorVelocityZ: telemetryTab.txtECEFVectorVelocityZ

    property alias txtRollAngle: telemetryTab.txtRollAngle
    property alias txtPitchAngle: telemetryTab.txtPitchAngle
    property alias txtYawAngle: telemetryTab.txtYawAngle
    property alias txtAngularRateRoll: telemetryTab.txtAngularRateRoll
    property alias txtAngularRatePitch: telemetryTab.txtAngularRatePitch
    property alias txtAngularRateYaw: telemetryTab.txtAngularRateYaw

    property alias txtNumberOfGPSSatellite: telemetryTab.txtNumberOfGPSSatellite

    property alias txtAnemCommErrorCounter: telemetryTab.txtAnemCommErrorCounter
    property alias txtRDAltCommErrorCounter: telemetryTab.txtRDAltCommErrorCounter
    property alias txtGNSSCommErrorCounter: telemetryTab.txtGNSSCommErrorCounter
    property alias txtPLAltCommErrorCounter: telemetryTab.txtPLAltCommErrorCounter

    property alias txtMotorARealPosition: motorsBMSTab.txtMotorARealPosition
    property alias txtMotorADemandPosition: motorsBMSTab.txtMotorADemandPosition
    property alias txtMotorATorque: motorsBMSTab.txtMotorATorque
    property alias txtMotorATemp: motorsBMSTab.txtMotorATemp

    property alias txtMotorBRealPosition: motorsBMSTab.txtMotorBRealPosition
    property alias txtMotorBDemandPosition: motorsBMSTab.txtMotorBDemandPosition
    property alias txtMotorBTorque: motorsBMSTab.txtMotorBTorque
    property alias txtMotorBTemp: motorsBMSTab.txtMotorBTemp

    property alias txtBMS1Voltage: motorsBMSTab.txtBMS1Voltage
    property alias txtBMS1Absorption: motorsBMSTab.txtBMS1Absorption
    property alias txtBMS1Temp: motorsBMSTab.txtBMS1Temp
    property alias txtMotorTimestamp: motorsBMSTab.txtMotorTimestamp
    property alias txtChargeValue: motorsBMSTab.txtChargeValue

    width: Constants.width / 2 //750 //C
    height: Constants.height //667 //
    color: "#ffffff"
    property alias telemetryLight0: telemetryTab.telemetryLight0
    property alias telemetryLight31: telemetryTab.telemetryLight31
    property alias telemetryLight30: telemetryTab.telemetryLight30
    property alias telemetryLight29: telemetryTab.telemetryLight29
    property alias telemetryLight28: telemetryTab.telemetryLight28
    property alias telemetryLight27: telemetryTab.telemetryLight27
    property alias telemetryLight26: telemetryTab.telemetryLight26
    property alias telemetryLight25: telemetryTab.telemetryLight25
    property alias telemetryLight24: telemetryTab.telemetryLight24
    property alias telemetryLight23: telemetryTab.telemetryLight23
    property alias telemetryLight22: telemetryTab.telemetryLight22
    property alias telemetryLight21: telemetryTab.telemetryLight21
    property alias telemetryLight20: telemetryTab.telemetryLight20
    property alias telemetryLight19: telemetryTab.telemetryLight19
    property alias telemetryLight18: telemetryTab.telemetryLight18
    property alias telemetryLight17: telemetryTab.telemetryLight17
    property alias telemetryLight16: telemetryTab.telemetryLight16
    property alias telemetryLight15: telemetryTab.telemetryLight15
    property alias telemetryLight14: telemetryTab.telemetryLight14
    property alias telemetryLight13: telemetryTab.telemetryLight13
    property alias telemetryLight12: telemetryTab.telemetryLight12
    property alias telemetryLight11: telemetryTab.telemetryLight11
    property alias telemetryLight10: telemetryTab.telemetryLight10
    property alias telemetryLight9: telemetryTab.telemetryLight9
    property alias telemetryLight8: telemetryTab.telemetryLight8
    property alias telemetryLight7: telemetryTab.telemetryLight7
    property alias telemetryLight6: telemetryTab.telemetryLight6
    property alias telemetryLight5: telemetryTab.telemetryLight5
    property alias telemetryLight4: telemetryTab.telemetryLight4
    property alias telemetryLight3: telemetryTab.telemetryLight3
    property alias telemetryLight2: telemetryTab.telemetryLight2
    property alias telemetryLight1: telemetryTab.telemetryLight1

    property alias storageLight23: storageTab.storageLight23
    property alias storageLight22: storageTab.storageLight22
    property alias storageLight21: storageTab.storageLight21
    property alias storageLight20: storageTab.storageLight20
    property alias storageLight19: storageTab.storageLight19
    property alias storageLight18: storageTab.storageLight18
    property alias storageLight17: storageTab.storageLight17
    property alias storageLight16: storageTab.storageLight16
    property alias storageLight15: storageTab.storageLight15
    property alias storageLight14: storageTab.storageLight14
    property alias storageLight13: storageTab.storageLight13
    property alias storageLight12: storageTab.storageLight12
    property alias storageLight11: storageTab.storageLight11
    property alias storageLight10: storageTab.storageLight10
    property alias storageLight8: storageTab.storageLight8
    property alias storageLight7: storageTab.storageLight7
    property alias storageLight6: storageTab.storageLight6
    property alias storageLight5: storageTab.storageLight5
    property alias storageLight4: storageTab.storageLight4
    property alias storageLight3: storageTab.storageLight3
    property alias storageLight2: storageTab.storageLight2
    property alias storageLight1: storageTab.storageLight1
    property alias storageLight0: storageTab.storageLight0

    //    property alias motorLight25: motorLight25
    //    property alias motorLight24: motorLight24
    property alias motorLight23: motorsBMSTab.motorLight23
    property alias motorLight22: motorsBMSTab.motorLight22
    property alias motorLight21: motorsBMSTab.motorLight21
    //    property alias motorLight20: motorLight20
    //    property alias motorLight19: motorLight19
    //    property alias motorLight18: motorLight18
    //    property alias motorLight17: motorLight17
    //    property alias motorLight16: motorLight16
    property alias motorLight15: motorsBMSTab.motorLight15
    property alias motorLight14: motorsBMSTab.motorLight14
    property alias motorLight13: motorsBMSTab.motorLight13
    property alias motorLight12: motorsBMSTab.motorLight12
    //    property alias motorLight11: motorLight11
    //    property alias motorLight10: motorLight10
    property alias motorLight8: motorsBMSTab.motorLight8
    property alias motorLight7: motorsBMSTab.motorLight7
    property alias motorLight6: motorsBMSTab.motorLight6
    property alias motorLight5: motorsBMSTab.motorLight5
    property alias motorLight4: motorsBMSTab.motorLight4
    property alias motorLight3: motorsBMSTab.motorLight3
    property alias motorLight2: motorsBMSTab.motorLight2
    property alias motorLight1: motorsBMSTab.motorLight1
    property alias motorLight0: motorsBMSTab.motorLight0

    property alias bmsLight0: motorsBMSTab.bmsLight0
    property alias bmsLight31: motorsBMSTab.bmsLight31
    property alias bmsLight30: motorsBMSTab.bmsLight30
    property alias bmsLight29: motorsBMSTab.bmsLight29
    property alias bmsLight28: motorsBMSTab.bmsLight28
    property alias bmsLight27: motorsBMSTab.bmsLight27
    property alias bmsLight26: motorsBMSTab.bmsLight26
    property alias bmsLight25: motorsBMSTab.bmsLight25
    property alias bmsLight24: motorsBMSTab.bmsLight24
    property alias bmsLight23: motorsBMSTab.bmsLight23
    property alias bmsLight22: motorsBMSTab.bmsLight22
    property alias bmsLight21: motorsBMSTab.bmsLight21
    property alias bmsLight20: motorsBMSTab.bmsLight20
    property alias bmsLight19: motorsBMSTab.bmsLight19
    property alias bmsLight18: motorsBMSTab.bmsLight18
    property alias bmsLight17: motorsBMSTab.bmsLight17
    property alias bmsLight16: motorsBMSTab.bmsLight16
    property alias bmsLight15: motorsBMSTab.bmsLight15
    property alias bmsLight14: motorsBMSTab.bmsLight14
    property alias bmsLight13: motorsBMSTab.bmsLight13
    property alias bmsLight12: motorsBMSTab.bmsLight12
    property alias bmsLight11: motorsBMSTab.bmsLight11
    property alias bmsLight10: motorsBMSTab.bmsLight10
    property alias bmsLight9: motorsBMSTab.bmsLight9
    property alias bmsLight8: motorsBMSTab.bmsLight8
    property alias bmsLight7: motorsBMSTab.bmsLight7
    property alias bmsLight6: motorsBMSTab.bmsLight6
    property alias bmsLight5: motorsBMSTab.bmsLight5
    property alias bmsLight4: motorsBMSTab.bmsLight4
    property alias bmsLight3: motorsBMSTab.bmsLight3
    property alias bmsLight2: motorsBMSTab.bmsLight2
    property alias bmsLight1: motorsBMSTab.bmsLight1

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
                text: "TimeStampRIO"
                span: 5
                id: txtTimeStampRIO
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: -20
            ColumnLayout {

                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.preferredWidth: 10
                Layout.fillHeight: true
                //width: 30
                //implicitWidth: 30
                spacing: 16 //24
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 120
                    Layout.preferredWidth: 60 //40

                    border.width: 0
                    width: 40
                    color: params.tabIndex === 0 ? "#F5F5F5" : "#E0E0E0"
                    Column {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 120
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/triangle-exclamation.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3
                            text: "Telemetry"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    MouseArea {
                        id: mouseAreaGNSS

                        anchors.fill: parent
                        Connections {
                            target: mouseAreaGNSS
                            onClicked: {
                                params.tabIndex = 0
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 150
                    Layout.preferredWidth: 60 //40
                    color: params.tabIndex === 1 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Column {
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 150
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3
                            text: "Motors & BMS"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    MouseArea {
                        id: mouseAreaMotorsBMS
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaMotorsBMS
                            onClicked: {
                                params.tabIndex = 1
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    color: params.tabIndex === 2 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Layout.preferredHeight: 110
                    Layout.preferredWidth: 60 //40
                    Column {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 100

                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            width: 24
                            source: "images/svgs/solid/database.svg"
                            fillMode: Image.PreserveAspectFit
                        }

                        ParamGrp1Label {
                            x: -3
                            text: "Storage"

                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    MouseArea {
                        id: mouseAreaStorage
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaStorage
                            onClicked: {
                                params.tabIndex = 2
                            }
                        }
                    }
                }
            }
            Rectangle {
                x: -10
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft

                color: "#f5f5f5"
                //x: 40
                //z:-1
                radius: 8
                Layout.fillWidth: true
                Layout.fillHeight: true
                StackLayout {
                    currentIndex: params.tabIndex
                    anchors.fill: parent
                    anchors.margins: 24
                    TelemetryTab {
                        id: telemetryTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    MotorsBMSTab {
                        id: motorsBMSTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    StorageTab {
                        id: storageTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                }
            }
        }

        //        Rectangle {
        //            id: rectangle3

        //            color: "#d9d9d9"
        //            Layout.preferredHeight: 1
        //            Layout.fillWidth: true
        //        }
    }
    Item {
        Layout.fillHeight: true
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1600}
}
##^##*/

