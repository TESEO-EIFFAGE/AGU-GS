import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    color:"transparent"

    property bool lit

    property alias txtCommErrorCounter: txtCommErrorCounter.value
    property alias coreLight15: coreLight15
    property alias coreLight14: coreLight14
    property alias coreLight13: coreLight13
    property alias coreLight12: coreLight12
    property alias coreLight11: coreLight11
    property alias coreLight10: coreLight10
    property alias coreLight9: coreLight9
    property alias coreLight8: coreLight8
    property alias coreLight7: coreLight7
    property alias coreLight6: coreLight6
    property alias coreLight5: coreLight5
    property alias coreLight4: coreLight4
    property alias coreLight3: coreLight3
    property alias coreLight2: coreLight2
    property alias coreLight1: coreLight1
    property alias coreLight0: coreLight0

    Flow {
        id: gridCore
        spacing: 16
        width:parent.width
        height: childrenRect.height
        StatusLight {
            id: coreLight0
            text: "EMERGENCY"
        }

        StatusLight {
            id: coreLight1
            text: "SAFETY CHAIN STATUS"
        }

        StatusLight {
            id: coreLight2
            text: "PARAFOIL DEP. STATUS"
        }

        StatusLight {
            id: coreLight3
            text: "EMERGENCY BOARD FAILURE"
        }
        StatusLight {
            id: coreLight4
            text: "POWER FAILURE"
        }

        StatusLight {
            id: coreLight5
            text: "STOA"
        }
        StatusLight {
            id: coreLight6
            text: "STOB"
        }

        StatusLight {
            id: coreLight7
            text: "TELEMETRY STATUS"
        }
        StatusLight {
            id: coreLight8
            text: "MOTOR CONTROL"
        }
        StatusLight {
            id: coreLight9
            text: "LOG"
        }
        StatusLight {
            id: coreLight10
            text: "RADIO LINK"
        }

        StatusLight {
            id: coreLight11
            text: "GUIDANCE"
        }

        StatusLight {
            id: coreLight12
            text: "CORE"
        }

        StatusLight {
            id: coreLight13
            text: "Emergency BOARD NOT Present"
        }
        StatusLight {
            id: coreLight14
            text: "Communication Time Out"
        }

        StatusLight {
            id: coreLight15
            text: "Communication CRC Error"
        }
        ParamRow {
            visible: false
            id: txtCommErrorCounter
            text: "Comm Error counter"
            span: 6
            ToolTip.text: text
            ToolTip.visible: pressed
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}
D{i:9}D{i:10}D{i:11}D{i:12}D{i:13}D{i:14}D{i:15}D{i:16}D{i:17}D{i:18}D{i:1}
}
##^##*/
