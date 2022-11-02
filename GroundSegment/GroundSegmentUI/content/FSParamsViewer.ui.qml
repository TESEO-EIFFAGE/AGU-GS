import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property int tabIndex: 0

    signal telemetryTabClicked
    signal motorsBMSTabClicked
    signal storageTabClicked
    signal guidanceTabClicked
    signal coreTabClicked
    signal radioLinkTabClicked

    property alias telemetryTab: telemetryTab
    property alias storageTab: storageTab
    property alias motorsBMSTab: motorsBMSTab
    property alias homeTab: homeTab
    property alias coreTab: coreTab
    property alias radioLinkTab: radioLinkTab
    property alias guidanceTab: guidanceTab

    property alias telemetryTabLight: telemetryTabLight
    property alias storageTabLight: storageTabLight
    property alias motorsBMSTabLight: motorsBMSTabLight

    property alias coreTabLight: coreTabLight
    property alias radioLinkTabLight: radioLinkTabLight
    property alias guidanceTabLight: guidanceTabLight

    property alias txtTimeStampRIO: txtTimeStampRIO.value

    property alias txtLatitude: telemetryTab.txtLatitude
    property alias txtLongitude: telemetryTab.txtLongitude
    property alias txtGNSSAltitude: telemetryTab.txtGNSSAltitude

    property alias txtLatitudeHome: homeTab.txtLatitude
    property alias txtLongitudeHome: homeTab.txtLongitude
    property alias txtGNSSAltitudeHome: homeTab.txtGNSSAltitude


    property alias txtTelemetryMsgCounter: telemetryTab.txtTelemetryMsgCounter

    property alias txtAirSpeed_UVector: telemetryTab.txtAirSpeed_UVector
    property alias txtAirSpeed_VVector: telemetryTab.txtAirSpeed_VVector
    property alias txtAirSpeed_WVector: telemetryTab.txtAirSpeed_WVector

    property alias txtAirSpeed_UVectorHome: homeTab.txtAirSpeed_UVector
    property alias txtAirSpeed_VVectorHome: homeTab.txtAirSpeed_VVector
    property alias txtAirSpeed_WVectorHome: homeTab.txtAirSpeed_WVector

    property alias txtAirTemperature: telemetryTab.txtAirTemperature

    property alias payloadDrawer: telemetryTab.payloadDrawer
    property alias radarDrawer: telemetryTab.radarDrawer

    property alias txtLinearVelocityHorizontal: telemetryTab.txtLinearVelocityHorizontal
    property alias txtLinearVelocityVertical: telemetryTab.txtLinearVelocityVertical

    property alias txtLinearVelocityHorizontalHome: homeTab.txtLinearVelocityHorizontal
    property alias txtLinearVelocityVerticalHome: homeTab.txtLinearVelocityVertical

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

    property alias txtRollAngleHome: homeTab.txtRollAngle
    property alias txtPitchAngleHome: homeTab.txtPitchAngle
    property alias txtYawAngleHome: homeTab.txtYawAngle

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
    property alias txtChargeValue: motorsBMSTab.txtChargeValue

    property alias txtMotorMsgCounter: motorsBMSTab.txtMotorMsgCounter

    width: Constants.width / 2 //750 //C
    height: Constants.height //667 //
    color: "#ffffff"


    property alias telemetryStatusDrawer: telemetryTab.telemetryStatusDrawer
    property alias telemetryLight0: telemetryTab.telemetryLight0
    property alias telemetryLight3: telemetryTab.telemetryLight3
    property alias telemetryLight2: telemetryTab.telemetryLight2
    property alias telemetryLight1: telemetryTab.telemetryLight1


    property alias txtFreeDataStorageSize: storageTab.txtFreeDataStorageSize

    property alias txtStorageMsgCounter: storageTab.txtStorageMsgCounter

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

    property alias coreLight15: coreTab.coreLight15
    property alias coreLight14: coreTab.coreLight14
    property alias coreLight13: coreTab.coreLight13
    property alias coreLight12: coreTab.coreLight12
    property alias coreLight11: coreTab.coreLight11
    property alias coreLight10: coreTab.coreLight10
    property alias coreLight9: coreTab.coreLight9
    property alias coreLight8: coreTab.coreLight8
    property alias coreLight7: coreTab.coreLight7
    property alias coreLight6: coreTab.coreLight6
    property alias coreLight5: coreTab.coreLight5
    property alias coreLight4: coreTab.coreLight4
    property alias coreLight3: coreTab.coreLight3
    property alias coreLight2: coreTab.coreLight2
    property alias coreLight1: coreTab.coreLight1
    property alias coreLight0: coreTab.coreLight0

    property alias radioLinkLight9: radioLinkTab.radioLinkLight9
    property alias radioLinkLight8: radioLinkTab.radioLinkLight8

    property alias radioLinkLight3: radioLinkTab.radioLinkLight3
    property alias radioLinkLight2: radioLinkTab.radioLinkLight2
    property alias radioLinkLight1: radioLinkTab.radioLinkLight1
    property alias radioLinkLight0: radioLinkTab.radioLinkLight0

    property alias txtRadioLinkErrorCounter: radioLinkTab.txtRadioLinkErrorCounter

    property alias txtRadioLinkMsgCounter: radioLinkTab.txtRadioLinkMsgCounter

    property alias txtSystemMsgCounter: homeTab.txtSystemMsgCounter

    ColumnLayout {
        //anchors.fill: parent
        id: col
        spacing: 20 //24
        //anchors.margins: 32
        anchors.fill: parent
        anchors.topMargin: 32
        anchors.leftMargin: 32
        anchors.rightMargin: 32
        Column {
            spacing: 0

            SectionLabel {
                text: "Flight Segment"
            }

            ParamRow {
                id: txtTimeStampRIO
                text: "TimeStampRIO"
                span: 14
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }
        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            contentHeight: rowTabs.height
            contentWidth: parent.width
            clip: true
            RowLayout {

                id: rowTabs
                width: parent.width
                height: childrenRect.height

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

                        Image {
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.topMargin: 8
                            anchors.leftMargin: 8
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/house.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: 6
                            y: 64
                            //anchors.verticalCenter: parent.verticalCenter
                            text: "Home"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
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

                        Image {
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.margins: 8
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/triangle-exclamation.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 65
                            text: "Telemetry"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }
                        Rectangle {
                            id: telemetryTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: telemetryTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaGNSS

                            anchors.fill: parent
                            Connections {
                                target: mouseAreaGNSS
                                onClicked: {
                                    params.tabIndex = 1
                                    params.telemetryTabClicked()
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

                        Image {
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.margins: 8
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 65
                            text: "Motors & BMS"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }

                        Rectangle {
                            id: motorsBMSTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: motorsBMSTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaMotorsBMS
                            anchors.fill: parent
                            Connections {
                                target: mouseAreaMotorsBMS
                                onClicked: {
                                    params.tabIndex = 2
                                    params.motorsBMSTabClicked()
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

                        Image {
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.margins: 8
                            //anchors.horizontalCenter: parent.horizontalCenter
                            width: 24
                            source: "images/svgs/solid/database.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 67

                            text: "Storage"

                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }

                        Rectangle {
                            id: storageTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: storageTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaStorage
                            anchors.fill: parent
                            Connections {
                                target: mouseAreaStorage
                                onClicked: {
                                    params.tabIndex = 3
                                    params.storageTabClicked()
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

                        Image {
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.margins: 8
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 64

                            text: "Core"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }

                        Rectangle {
                            id: coreTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: coreTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaCore
                            anchors.fill: parent
                            Connections {
                                target: mouseAreaCore
                                onClicked: {
                                    params.tabIndex = 6
                                    params.coreTabClicked()
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

                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/radio.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.margins: 8
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 64
                            text: "Radio Link"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }

                        Rectangle {
                            id: radioLinkTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: radioLinkTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaRadioLink
                            anchors.fill: parent
                            Connections {
                                target: mouseAreaRadioLink
                                onClicked: {
                                    params.tabIndex = 4
                                    params.radioLinkTabClicked()
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

                        Image {
                            //anchors.horizontalCenter: parent.horizontalCenter
                            source: "images/svgs/solid/gear.svg"
                            fillMode: Image.PreserveAspectFit
                            sourceSize.height: 24
                            sourceSize.width: 24
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.margins: 8
                        }

                        ParamGrp1Label {
                            x: 5
                            y: 65

                            text: "Guidance"
                            transform: Rotation {
                                angle: 90
                                origin.x: 25
                            }
                        }

                        Rectangle {
                            id: guidanceTabLight
                            anchors.left: parent.left
                            anchors.leftMargin: 12
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 8
                            width: 16
                            height: 16
                            //color: guidanceTab.lit ? "#ff0000" : "#b1b1b1"
                            radius: 8
                        }
                        MouseArea {
                            id: mouseAreaGuidance
                            anchors.fill: parent
                            Connections {
                                target: mouseAreaGuidance
                                onClicked: {
                                    params.tabIndex = 5
                                    params.guidanceTabClicked()
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
        }
        Item {
            Layout.fillHeight: true
        }
    }
}


