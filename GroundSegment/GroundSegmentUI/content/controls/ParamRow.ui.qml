import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0

Row {
    id: row
    spacing: 8
    property bool hovered: mouseArea.containsMouse
    property bool pressed: 0
    property real span: 1
    property alias text: paramLabel.text
    property alias value: paramValue.text
    ParamLabel {
        id: paramLabel
        anchors.verticalCenter: parent.verticalCenter
        width: 16 * span
        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent

            Connections {
                target: mouseArea
                function onPressed() {
                    row.pressed = 1
                }
                function onReleased() {
                    row.pressed = 0
                }
            }
        }
    }
    ParamValue {
        id: paramValue
        anchors.verticalCenter: parent.verticalCenter
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3}D{i:2}D{i:1}D{i:4}
}
##^##*/

