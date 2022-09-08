import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {

    property alias txtMotorARealPosition: txtMotorARealPosition.value
    property alias txtMotorADemandPosition: txtMotorADemandPosition.value
    property alias txtMotorATorque: txtMotorATorque.value
    property alias txtMotorATemp: txtMotorATemp.value

    property alias txtMotorBRealPosition: txtMotorBRealPosition.value
    property alias txtMotorBDemandPosition: txtMotorBDemandPosition.value
    property alias txtMotorBTorque: txtMotorBTorque.value
    property alias txtMotorBTemp: txtMotorBTemp.value

    property alias txtBMS1Voltage: txtBMS1Voltage.value
    property alias txtBMS1Absorption: txtBMS1Absorption.value
    property alias txtBMS1Temp: txtBMS1Temp.value
    property alias txtMotorTimestamp: txtMotorTimestamp.value
    property alias txtChargeValue: txtChargeValue.value

    //    property alias motorLight25: motorLight25
    //    property alias motorLight24: motorLight24
    property alias motorLight23: motorLight23
    property alias motorLight22: motorLight22
    property alias motorLight21: motorLight21
    //    property alias motorLight20: motorLight20
    //    property alias motorLight19: motorLight19
    //    property alias motorLight18: motorLight18
    //    property alias motorLight17: motorLight17
    //    property alias motorLight16: motorLight16
    property alias motorLight15: motorLight15
    property alias motorLight14: motorLight14
    property alias motorLight13: motorLight13
    property alias motorLight12: motorLight12
    //    property alias motorLight11: motorLight11
    //    property alias motorLight10: motorLight10
    property alias motorLight8: motorLight8
    property alias motorLight7: motorLight7
    property alias motorLight6: motorLight6
    property alias motorLight5: motorLight5
    property alias motorLight4: motorLight4
    property alias motorLight3: motorLight3
    property alias motorLight2: motorLight2
    property alias motorLight1: motorLight1
    property alias motorLight0: motorLight0

    property alias bmsLight0: bmsLight0
    property alias bmsLight31: bmsLight31
    property alias bmsLight30: bmsLight30
    property alias bmsLight29: bmsLight29
    property alias bmsLight28: bmsLight28
    property alias bmsLight27: bmsLight27
    property alias bmsLight26: bmsLight26
    property alias bmsLight25: bmsLight25
    property alias bmsLight24: bmsLight24
    property alias bmsLight23: bmsLight23
    property alias bmsLight22: bmsLight22
    property alias bmsLight21: bmsLight21
    property alias bmsLight20: bmsLight20
    property alias bmsLight19: bmsLight19
    property alias bmsLight18: bmsLight18
    property alias bmsLight17: bmsLight17
    property alias bmsLight16: bmsLight16
    property alias bmsLight15: bmsLight15
    property alias bmsLight14: bmsLight14
    property alias bmsLight13: bmsLight13
    property alias bmsLight12: bmsLight12
    property alias bmsLight11: bmsLight11
    property alias bmsLight10: bmsLight10
    property alias bmsLight9: bmsLight9
    property alias bmsLight8: bmsLight8
    property alias bmsLight7: bmsLight7
    property alias bmsLight6: bmsLight6
    property alias bmsLight5: bmsLight5
    property alias bmsLight4: bmsLight4
    property alias bmsLight3: bmsLight3
    property alias bmsLight2: bmsLight2
    property alias bmsLight1: bmsLight1

    RowLayout {
        anchors.fill:parent
spacing: 16

        Column {
            Layout.alignment: Qt.AlignTop

            spacing: 8

            ParamGrp2Label {
                text: "General"
            }
            ParamRow {
                id: txtMotorTimestamp
                text: "TimeStamp"
                span: 4
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtBMS1Voltage
                text: "BMS1 Voltage"
                span: 6
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtBMS1Absorption
                text: "BMS1 Absorption"
                span: 6
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtBMS1Temp
                text: "BMS1 Temperature"
                span: 6
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            StatusLight {
                id: motorLight4
                text: "MotorControllerA comm error"
            }
            StatusLight {
                id: motorLight5
                text: "MotorControllerB comm error"
            }
            StatusLight {
                id: motorLight0
                text: "RS232 HW failure"
            }
            StatusLight {
                id: motorLight1
                text: "CAN HW failure"
            }
            StatusLight {
                id: motorLight2
                text: "PT100 HW failure"
            }
            StatusLight {
                id: motorLight3
                text: "GPIO HW failure"
            }
            StatusLight {
                id: motorLight6
                text: "PT100 A sensor breakage"
            }
            StatusLight {
                id: motorLight7
                text: "PT100 B sensor breakage"
            }

            StatusLight {
                id: motorLight8
                text: "BMS comm error"
            }
        }
        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop
            ParamGrp2Label {
                text: "Motor A"
            }
            ParamRow {
                id: txtMotorARealPosition
                text: "MotorA RealPosition"
                span: 8
                ToolTip.text: text
                ToolTip.visible: hovered
            }

            ParamRow {
                id: txtMotorADemandPosition
                text: "MotorA DemandPosition"
                span: 8
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtMotorATorque

                text: "MotorA Torque"
                span: 5
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtMotorATemp

                text: "MotorA Temp"
                span: 5
                ToolTip.text: text
                ToolTip.visible: hovered
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
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            ParamRow {
                id: txtMotorBDemandPosition

                text: "MotorB DemandPosition"
                span: 8
                ToolTip.text: text
                ToolTip.visible: hovered
            }

            ParamRow {
                id: txtMotorBTorque

                text: "MotorB Torque"
                span: 5
                ToolTip.text: text
                ToolTip.visible: hovered
            }

            ParamRow {
                id: txtMotorBTemp

                text: "MotorB Temp"
                span: 5
                ToolTip.text: text
                ToolTip.visible: hovered
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
                text: "BMS"
            }

            ParamRow {
                id: txtChargeValue
                text: "Charge %"
                span: 3
                ToolTip.text: text
                ToolTip.visible: hovered
            }
            StatusLight {
                id: motorLight23
                text: "Battery LOW"
            }

            StatusLight {
                id: motorLight20
                text: "BMS active INDICATION"
            }
            StatusLight {
                id: motorLight21
                text: "BMS active FAULT"
            }
            StatusLight {
                id: motorLight22
                text: "BMS active REQUEST"
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
                id: bmsLight4
                text: "Battery EXCESSIVE INDICATION"
            }
            StatusLight {
                id: bmsLight5
                text: "Battery EXCESSIVE FAULT"
            }
            StatusLight {
                id: bmsLight6
                text: "Battery temp HIGH INDICATION"
            }
            StatusLight {
                id: bmsLight7
                text: "Battery temp HIGH FAULT"
            }
        }

        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop

            Item {
                height: 16
                width: 1
            }

            StatusLight {
                id: bmsLight8
                text: "Battery temp LOW INDICATION"
            }
            StatusLight {
                id: bmsLight9
                text: "Battery temp LOW FAULT"
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
            StatusLight {
                id: bmsLight14
                text: "Cell voltage difference INDICATION"
            }
            StatusLight {
                id: bmsLight15
                text: "Cell voltage difference FAULT"
            }
            StatusLight {
                id: bmsLight16
                text: "Cell temp difference INDICATION"
            }
            StatusLight {
                id: bmsLight17
                text: "Cell temp difference FAULT"
            }

            StatusLight {
                id: bmsLight18
                text: "Cell temp sensor FAULT"
            }
            StatusLight {
                id: bmsLight19
                text: "Generic HW FAULT"
            }

            StatusLight {
                id: bmsLight20
                text: "Charge switch FAULT"
            }
        }

        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop
            Item {
                height: 16
                width: 1
            }

            StatusLight {
                id: bmsLight21
                text: "Discharge switch FAULT"
            }

            StatusLight {
                id: bmsLight22
                text: "Self-test FAULT"
            }
            StatusLight {
                id: bmsLight23
                text: "Collection line FAULT"
            }

            StatusLight {
                id: bmsLight24
                text: "Temp line FAULT"
            }
            StatusLight {
                id: bmsLight25
                text: "BMS alarm FAULT"
            }
            StatusLight {
                id: bmsLight26
                text: "Activity limit request"
            }
            StatusLight {
                id: bmsLight27
                text: "Discharge current limit request"
            }
            StatusLight {
                id: bmsLight28
                text: "Consumption STOP request"
            }
            StatusLight {
                id: bmsLight29
                text: "Charging temp low FAULT"
            }
            StatusLight {
                id: bmsLight30
                text: "Charging temp high FAULT"
            }
            StatusLight {
                id: bmsLight31
                text: "Excessive charging current FAULT"
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}D{i:9}
D{i:10}D{i:11}D{i:12}D{i:13}D{i:14}D{i:15}D{i:16}D{i:2}D{i:18}D{i:19}D{i:20}D{i:21}
D{i:22}D{i:23}D{i:24}D{i:17}D{i:26}D{i:27}D{i:28}D{i:29}D{i:30}D{i:31}D{i:32}D{i:25}
D{i:34}D{i:35}D{i:36}D{i:37}D{i:38}D{i:39}D{i:40}D{i:41}D{i:42}D{i:43}D{i:44}D{i:45}
D{i:46}D{i:47}D{i:33}D{i:49}D{i:50}D{i:51}D{i:52}D{i:53}D{i:54}D{i:55}D{i:56}D{i:57}
D{i:58}D{i:59}D{i:60}D{i:61}D{i:62}D{i:48}D{i:64}D{i:65}D{i:66}D{i:67}D{i:68}D{i:69}
D{i:70}D{i:71}D{i:72}D{i:73}D{i:74}D{i:75}D{i:63}D{i:1}
}
##^##*/
