import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property int tabIndex: 0

    property alias telemetryTab: telemetryTab
    property alias storageTab: storageTab
    property alias motorsBMSTab: motorsBMSTab
    property alias homeTab: homeTab
    property alias coreTab: coreTab
    property alias radioLinkTab: radioLinkTab
    property alias guidanceTab: guidanceTab

    property alias txtTimeStampRIO: txtTimeStampRIO.value
    property alias txtLatitude: telemetryTab.txtLatitude
    property alias txtLongitude: telemetryTab.txtLongitude
    property alias txtGNSSAltitude: telemetryTab.txtGNSSAltitude
    property alias txtAirSpeed_UVector: telemetryTab.txtAirSpeed_UVector

    property alias txtAirSpeed_VVector: telemetryTab.txtAirSpeed_VVector
    property alias txtAirSpeed_WVector: telemetryTab.txtAirSpeed_WVector
    property alias txtAirTemperature: telemetryTab.txtAirTemperature

    property alias payloadDrawer: telemetryTab.payloadDrawer
    property alias radarDrawer: telemetryTab.radarDrawer
    property alias txtLinearVelocityHorizontal: telemetryTab.txtLinearVelocityHorizontal

    property alias txtLinearVelocityVertical: telemetryTab.txtLinearVelocityVertical
    property alias txtPositionAccuracy: telemetryTab.txtPositionAccuracy
    property alias txtSpeedAccuracy: telemetryTab.txtSpeedAccuracy

    //    property alias txtLinearAccelerationX: telemetryTab.txtLinearAccelerationX
    //    property alias txtLinearAccelerationY: telemetryTab.txtLinearAccelerationY
    //    property alias txtLinearAccelerationZ: telemetryTab.txtLinearAccelerationZ
    property alias linearAccDrawer: telemetryTab.linearAccDrawer

    property alias txtECEFVectorPositionX: telemetryTab.txtECEFVectorPositionX
    property alias txtECEFVectorPositionY: telemetryTab.txtECEFVectorPositionY
    property alias txtECEFVectorPositionZ: telemetryTab.txtECEFVectorPositionZ

    property alias ecefVelocityDrawer: telemetryTab.ecefVelocityDrawer

    //    property alias txtECEFVectorVelocityX: telemetryTab.txtECEFVectorVelocityX
    //    property alias txtECEFVectorVelocityY: telemetryTab.txtECEFVectorVelocityY
    //    property alias txtECEFVectorVelocityZ: telemetryTab.txtECEFVectorVelocityZ
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
    border.color: "#ffffff"

    property alias telemetryStatusDrawer: telemetryTab.telemetryStatusDrawer
    property alias telemetryLight0: telemetryTab.telemetryLight0
    property alias telemetryLight3: telemetryTab.telemetryLight3
    property alias telemetryLight2: telemetryTab.telemetryLight2
    property alias telemetryLight1: telemetryTab.telemetryLight1

    property alias storageDrawer: storageTab.storageDrawer


    property alias motorLight23: motorsBMSTab.motorLight23
    property alias motorLight22: motorsBMSTab.motorLight22
    property alias motorLight21: motorsBMSTab.motorLight21
    property alias motorLight20: motorsBMSTab.motorLight20

    property alias motorLight15: motorsBMSTab.motorLight15
    property alias motorLight14: motorsBMSTab.motorLight14
    property alias motorLight13: motorsBMSTab.motorLight13
    property alias motorLight12: motorsBMSTab.motorLight12

    property alias generalMotorDrawer: motorsBMSTab.generalMotorDrawer
    property alias motorLight5: motorsBMSTab.motorLight5
    property alias motorLight4: motorsBMSTab.motorLight4

    property alias bmsDrawer: motorsBMSTab.bmsDrawer

    property alias bmsLight0: motorsBMSTab.bmsLight0
    property alias bmsLight13: motorsBMSTab.bmsLight13
    property alias bmsLight12: motorsBMSTab.bmsLight12
    property alias bmsLight11: motorsBMSTab.bmsLight11
    property alias bmsLight10: motorsBMSTab.bmsLight10
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
                spacing: 2 //24
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 95
                    Layout.preferredWidth: 60 //40

                    border.width: 0
                    width: 40
                    color: params.tabIndex === 0 ? "#F5F5F5" : "#E0E0E0"
                    Column {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.topMargin: 8
                        anchors.leftMargin: 8

                        spacing: 32
                        width: 40
                        height: 95
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/house.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3
                            text: "Home"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }

                    MouseArea {
                        id: mouseAreaHome

                        anchors.fill: parent
                        Connections {
                            target: mouseAreaHome
                            onClicked: {
                                params.tabIndex = 0
                            }
                        }
                    }
                }

                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 140
                    Layout.preferredWidth: 60 //40

                    border.width: 0
                    width: 40
                    color: params.tabIndex === 1 ? "#F5F5F5" : "#E0E0E0"
                    Column {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 140
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
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: telemetryTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaGNSS

                        anchors.fill: parent
                        Connections {
                            target: mouseAreaGNSS
                            onClicked: {
                                params.tabIndex = 1
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 174
                    Layout.preferredWidth: 60 //40
                    color: params.tabIndex === 2 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Column {
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 174
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
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: motorsBMSTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaMotorsBMS
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaMotorsBMS
                            onClicked: {
                                params.tabIndex = 2
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    color: params.tabIndex === 3 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Layout.preferredHeight: 128
                    Layout.preferredWidth: 60 //40
                    Column {
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 130

                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            width: 24
                            source: "images/svgs/solid/database.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
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
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: storageTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaStorage
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaStorage
                            onClicked: {
                                params.tabIndex = 3
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 145
                    Layout.preferredWidth: 60 //40
                    color: params.tabIndex === 4 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Column {
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 145
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/radio.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3

                            text: "Radio Link"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: radioLinkTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaRadioLink
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaRadioLink
                            onClicked: {
                                params.tabIndex = 4
                            }
                        }
                    }
                }
                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 140
                    Layout.preferredWidth: 60 //40
                    color: params.tabIndex === 5 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Column {
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 140
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3

                            text: "Guidance"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: guidanceTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaGuidance
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaGuidance
                            onClicked: {
                                params.tabIndex = 5
                            }
                        }
                    }
                }

                Rectangle {
                    radius: 8
                    Layout.preferredHeight: 105
                    Layout.preferredWidth: 60 //40
                    color: params.tabIndex === 6 ? "#F5F5F5" : "#E0E0E0"
                    border.width: 0

                    Column {
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.margins: 8
                        spacing: 32
                        width: 40
                        height: 105
                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: -3

                            text: "Core"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                    }
                    Rectangle {
                        anchors.left: parent.left
                        anchors.leftMargin: 12
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 8
                        width: 16
                        height: 16
                        color: coreTab.lit ? "#ff0000" : "green"
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreaCore
                        anchors.fill: parent
                        Connections {
                            target: mouseAreaCore
                            onClicked: {
                                params.tabIndex = 6
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
                    HomeTab {
                        id: homeTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

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
                    RadioLinkTab {
                        id: radioLinkTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    GuidanceTab {
                        id: guidanceTab
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    CoreTab {
                        id: coreTab
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
    D{i:0;height:1080;width:1600}D{i:3}D{i:4}D{i:2}D{i:9}D{i:10}D{i:8}D{i:13}D{i:12}D{i:7}
D{i:16}D{i:17}D{i:15}D{i:19}D{i:21}D{i:20}D{i:14}D{i:24}D{i:25}D{i:23}D{i:27}D{i:29}
D{i:28}D{i:22}D{i:32}D{i:33}D{i:31}D{i:35}D{i:37}D{i:36}D{i:30}D{i:40}D{i:41}D{i:39}
D{i:43}D{i:45}D{i:44}D{i:38}D{i:48}D{i:49}D{i:47}D{i:51}D{i:53}D{i:52}D{i:46}D{i:56}
D{i:57}D{i:55}D{i:59}D{i:61}D{i:60}D{i:54}D{i:6}D{i:64}D{i:65}D{i:66}D{i:67}D{i:68}
D{i:69}D{i:70}D{i:63}D{i:62}D{i:5}D{i:1}D{i:71}
}
##^##*/

