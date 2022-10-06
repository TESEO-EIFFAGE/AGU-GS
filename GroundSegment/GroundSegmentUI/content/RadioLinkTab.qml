import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    color:"transparent"

    property bool lit


    property alias radioLinkLight9: radioLinkLight9
    property alias radioLinkLight8: radioLinkLight8

    property alias radioLinkLight3: radioLinkLight3
    property alias radioLinkLight2: radioLinkLight2
    property alias radioLinkLight1: radioLinkLight1
    property alias radioLinkLight0: radioLinkLight0
    property alias txtRadioLinkErrorCounter: txtRadioLinkErrorCounter.value

    Flow {
        //anchors.fill:parent
        id: gridRL
        //columnSpacing: 16
        //rowSpacing: 12

spacing: 16
width:parent.width
height: childrenRect.height
        //columns: 8
        //rows: 6

            StatusLight {
                id: radioLinkLight0
                text: "RS232 HW failure"
            }

            StatusLight {
                id: radioLinkLight1
                text: "USB to V-COM failure"
            }

            StatusLight {
                id: radioLinkLight2
                text: "Monitor comm error"
            }

            StatusLight {
                id: radioLinkLight3
                text: "RSSI value invalid"
            }

            StatusLight {
                id: radioLinkLight8
                text: "Heartbeat timeout error"
            }

            StatusLight {
                id: radioLinkLight9
                text: "Heartbeat checksum error"
            }

            ParamRow {
                id: txtRadioLinkErrorCounter
                text: "Error counter"
                span: 4
                ToolTip.text: text
                ToolTip.visible: pressed
            }


    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}
D{i:1}
}
##^##*/
