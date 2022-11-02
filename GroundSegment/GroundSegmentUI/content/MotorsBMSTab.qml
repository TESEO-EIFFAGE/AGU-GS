import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Pane {
    background: Rectangle{
        color:"transparent"
    }

    property bool lit

    property alias txtMotorMsgCounter: txtMotorMsgCounter.value

    property alias txtMotorARealPosition: txtMotorARealPosition
    property alias txtMotorADemandPosition: txtMotorADemandPosition
    property alias txtMotorATorque: txtMotorATorque
    property alias txtMotorATemp: txtMotorATemp

    property alias txtMotorBRealPosition: txtMotorBRealPosition
    property alias txtMotorBDemandPosition: txtMotorBDemandPosition
    property alias txtMotorBTorque: txtMotorBTorque
    property alias txtMotorBTemp: txtMotorBTemp

    property alias txtBMS1Voltage: txtBMS1Voltage
    property alias txtBMS1Absorption: txtBMS1Absorption
    property alias txtBMS1Temp: txtBMS1Temp
    property alias txtChargeValue: txtChargeValue

    property alias generalMotorDrawer: generalMotorDrawer
    property alias motorLight20: motorLight20
    property alias motorLight21: motorLight21

    property alias motorLight22: motorLight22
    property alias motorLight23: motorLight23


    property alias motorLight15: motorLight15
    property alias motorLight14: motorLight14
    property alias motorLight13: motorLight13
    property alias motorLight12: motorLight12
    //    property alias motorLight11: motorLight11
    //    property alias motorLight10: motorLight10
    //    property alias motorLight8: motorLight8
    //    property alias motorLight7: motorLight7
    //    property alias motorLight6: motorLight6
    property alias motorLight5: motorLight5
    property alias motorLight4: motorLight4
    //    property alias motorLight3: motorLight3
    //    property alias motorLight2: motorLight2
    //    property alias motorLight1: motorLight1
    //    property alias motorLight0: motorLight0

    property alias bmsDrawer: bmsDrawer

    property alias bmsLight0: bmsLight0


    property alias bmsLight13: bmsLight13
    property alias bmsLight12: bmsLight12
    property alias bmsLight11: bmsLight11
    property alias bmsLight10: bmsLight10

    property alias bmsLight3: bmsLight3
    property alias bmsLight2: bmsLight2
    property alias bmsLight1: bmsLight1

    Column{
        width:parent.width
        spacing:24
        Row {
            width:parent.width
            height: childrenRect.height
            spacing: 16

            Column {
                Layout.alignment: Qt.AlignTop
                Layout.preferredHeight: childrenRect.height
                spacing: 8
                Layout.preferredWidth: 300
                ParamGrp2Label {
                    text: "General"
                }

                ParamRow {
                    id: txtBMS1Voltage
                    text: "BMS1 Voltage"
                    span: 6
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtBMS1Absorption
                    text: "BMS1 Absorption"
                    span: 6
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtBMS1Temp
                    text: "BMS1 Temperature"
                    span: 6
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                StatusLight {
                    id: motorLight4
                    text: "MotorControllerA comm error"
                }
                StatusLight {
                    id: motorLight5
                    text: "MotorControllerB comm error"
                }
                LightsDrawer
                {
                    id:generalMotorDrawer
                    width:180

                    columnTitle.text: "General Motor Status"
                    light4.visible: false
                    light5.visible: false

                    light9.visible: false
                    light10.visible: false
                    light11.visible: false
                    light12.visible: false
                    light13.visible: false
                    light14.visible: false
                    light15.visible: false
                    light16.visible: false
                    light17.visible: false
                    light18.visible: false
                    light19.visible: false
                    light20.visible: false
                    light21.visible: false
                    light22.visible: false
                    light23.visible: false
                    light24.visible: false
                    light25.visible: false
                    light26.visible: false
                    light27.visible: false
                    light28.visible: false
                    light29.visible: false
                    light30.visible: false
                    light31.visible: false

                    light0.text: "RS232 HW failure"
                    light1.text: "CAN HW failure"

                    light2.text: "PT100 HW failure"

                    light3.text: "GPIO HW failure"

                    light6.text: "PT100 A sensor breakage"

                    light7.text: "PT100 B sensor breakage"

                    light8.text: "BMS comm error"

                }

                //            StatusLight {
                //                id: motorLight0
                //                text: "RS232 HW failure"
                //            }
                //            StatusLight {
                //                id: motorLight1
                //                text: "CAN HW failure"
                //            }
                //            StatusLight {
                //                id: motorLight2
                //                text: "PT100 HW failure"
                //            }
                //            StatusLight {
                //                id: motorLight3
                //                text: "GPIO HW failure"
                //            }
                //            StatusLight {
                //                id: motorLight6
                //                text: "PT100 A sensor breakage"
                //            }
                //            StatusLight {
                //                id: motorLight7
                //                text: "PT100 B sensor breakage"
                //            }

                //            StatusLight {
                //                id: motorLight8
                //                text: "BMS comm error"
                //            }
            }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: 240
                ParamGrp2Label {
                    text: "Motor A"
                }
                ParamRow {
                    id: txtMotorARealPosition
                    text: "MotorA RealPosition"
                    span: 8
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                ParamRow {
                    id: txtMotorADemandPosition
                    text: "MotorA DemandPosition"
                    span: 8
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtMotorATorque

                    text: "MotorA Torque"
                    span: 5
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtMotorATemp

                    text: "MotorA Temp"
                    span: 5
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                //                    StatusLight {
                //                        id: motorLight10
                //                        text: "MotorA breakage error"
                //                    }
                StatusLight {
                    id: motorLight12
                    text: "MotorA active INDICATION"
                }
                StatusLight {
                    id: motorLight14
                    text: "MotorA active FAULT"
                }
                //                    StatusLight {
                //                        id: motorLight16
                //                        text: "MotorA over-current error"
                //                    }

                //                    StatusLight {
                //                        id: motorLight18
                //                        text: "MotorA under-voltage error"
                //                    }
                //                    StatusLight {
                //                        id: motorLight20
                //                        text: "MotorA resolver err"
                //                    }
            }

            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                ParamGrp2Label {
                    text: "Motor B"
                }
                ParamRow {
                    id: txtMotorBRealPosition

                    text: "MotorB RealPosition"
                    span: 8
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtMotorBDemandPosition

                    text: "MotorB DemandPosition"
                    span: 8
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                ParamRow {
                    id: txtMotorBTorque

                    text: "MotorB Torque"
                    span: 5
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                ParamRow {
                    id: txtMotorBTemp

                    text: "MotorB Temp"
                    span: 5
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                //                    StatusLight {
                //                        id: motorLight11
                //                        text: "MotorB breakage error"
                //                    }
                StatusLight {
                    id: motorLight13
                    text: "MotorB active INDICATION"
                }

                StatusLight {
                    id: motorLight15
                    text: "MotorB active FAULT"
                }
                //                    StatusLight {
                //                        id: motorLight17
                //                        text: "MotorB over-current error"
                //                    }
                //                    StatusLight {
                //                        id: motorLight19
                //                        text: "MotorB under-voltage error"
                //                    }

                //                    StatusLight {
                //                        id: motorLight21
                //                        text: "MotorB resolver error"
                //                    }
            }

            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                ParamGrp2Label {
                    text: "Message Counter"
                }
                ParamRow {
                    Layout.alignment: Qt.AlignTop
                    text: "N. Motor Msg"
                    span: 5
                    id: txtMotorMsgCounter
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
            }
            Item {
                Layout.fillWidth: true
            }
        }
        RowLayout{
            width:parent.width
            height: childrenRect.height
            spacing: 16
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: 300
                ParamGrp2Label {
                    text: "BMS"
                }
                ParamRow {
                    id: txtChargeValue
                    text: "Charge %"
                    span: 3
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
                StatusLight {
                    id: motorLight23
                    text: "Battery LOW"
                }

                StatusLight {
                    id: motorLight20
                    text: "BMS INDICATION"
                }
                StatusLight {
                    id: motorLight21
                    text: "BMS FAULT"
                }
                StatusLight {
                    id: motorLight22
                    text: "BMS REQUEST"
                }
                StatusLight {
                    id: bmsLight0
                    text: "Battery OVERVOLTAGE INDICATION"
                }
                StatusLight {
                    id: bmsLight1
                    text: "Battery OVERVOLTAGE FAULT"
                }
                StatusLight {
                    id: bmsLight2
                    text: "Battery UNDERVOLTAGE INDICATION"
                }
                StatusLight {
                    id: bmsLight3
                    text: "Battery UNDERVOLTAGE FAULT"
                }
                StatusLight {
                    id: bmsLight10
                    text: "Cell UNDERVOLTAGE INDICATION"
                }
                StatusLight {
                    id: bmsLight11
                    text: "Cell UNDERVOLTAGE FAULT"
                }
                StatusLight {
                    id: bmsLight12
                    text: "Cell OVERVOLTAGE INDICATION"
                }
                StatusLight {
                    id: bmsLight13
                    text: "Cell OVERVOLTAGE FAULT"
                }
            }
            LightsDrawer{
                id:bmsDrawer
                width:180
                Layout.fillWidth: true
                Layout.fillHeight: true
                columnTitle.text: "BMS Status"

                light0.visible: false
                light1.visible: false
                light2.visible: false
                light3.visible: false
                light4.visible: true
                light5.visible: true
                light6.visible: true
                light7.visible: true
                light8.visible: true
                light9.visible: true
                light10.visible: false
                light11.visible: false
                light12.visible:false
                light13.visible: false

                light14.visible: true
                light15.visible: true
                light16.visible: true
                light17.visible: true
                light18.visible: true
                light19.visible: true
                light20.visible: true
                light21.visible: true
                light22.visible: true
                light23.visible: true
                light24.visible: true
                light25.visible: true
                light26.visible: true
                light27.visible: true
                light28.visible: true
                light29.visible: true
                light30.visible: true
                light31.visible: true

                light4.text: "Battery EXCESSIVE INDICATION"
                light5.text: "Battery EXCESSIVE FAULT"
                light6.text: "Battery temp HIGH INDICATION"
                light7.text: "Battery temp HIGH FAULT"
                light8.text: "Battery temp LOW INDICATION"
                light9.text: "Battery temp LOW FAULT"
                light14.text: "Cell voltage difference INDICATION"
                light15.text: "Cell voltage difference FAULT"
                light16.text: "Cell temp difference INDICATION"
                light17.text: "Cell temp difference FAULT"
                light18.text: "Cell temp sensor FAULT"
                light19.text: "Generic HW FAULT"
                light20.text: "Charge switch FAULT"
                light21.text: "Discharge switch FAULT"
                light22.text: "Self-test FAULT"
                light23.text: "Collection line FAULT"
                light24.text: "Temp line FAULT"
                light25.text: "BMS alarm FAULT"
                light26.text: "Activity limit request"
                light27.text: "Discharge current limit request"
                light28.text: "Consumption STOP request"
                light29.text: "Charging temp low FAULT"
                light30.text: "Charging temp high FAULT"
                light31.text: "Excessive charging current FAULT"
            }
            Item{
                Layout.fillWidth: true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;width:1000}
}
##^##*/
