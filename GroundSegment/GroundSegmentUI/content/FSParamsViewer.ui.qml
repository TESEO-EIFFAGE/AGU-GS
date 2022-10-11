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
    property alias storageLight9: storageTab.storageLight9
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
    property alias motorLight20: motorsBMSTab.motorLight20
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
                text: "TimeStampRIO"
                span: 14
                id: txtTimeStampRIO
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
                                    params.storageTabClicked()
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
                                    params.guidanceTabClicked()
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
                                    params.coreTabClicked()
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
/*##^##
Designer {
<<<<<<< HEAD
    D{i:0;height:1080;width:1600}
=======
    D{i:0;height:700;width:1600}D{i:3}D{i:4}D{i:2}D{i:9}D{i:10}D{i:13}D{i:12}D{i:8}D{i:15}
D{i:16}D{i:18}D{i:20}D{i:19}D{i:14}D{i:22}D{i:23}D{i:25}D{i:27}D{i:26}D{i:21}D{i:29}
D{i:30}D{i:32}D{i:34}D{i:33}D{i:28}D{i:36}D{i:37}D{i:39}D{i:41}D{i:40}D{i:35}D{i:43}
D{i:44}D{i:46}D{i:48}D{i:47}D{i:42}D{i:50}D{i:51}D{i:53}D{i:55}D{i:54}D{i:49}D{i:7}
D{i:58}D{i:59}D{i:60}D{i:61}D{i:62}D{i:63}D{i:64}D{i:57}D{i:56}D{i:6}D{i:5}D{i:65}
D{i:1}
>>>>>>> feature/fix_ui_responsive
}
##^##*/

