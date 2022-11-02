import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0

Row {
    id: row
    spacing: 8
    property bool hovered: mouseArea.containsMouse
    property bool pressed: false
    property real span: 1
    property alias text: paramLabel.text
    property alias value: paramValue.text
    ParamLabel {
        id: paramLabel
        anchors.verticalCenter: parent.verticalCenter

        width: 16 * span
        color: enabled ? "#000000" : "#878787"
        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent

            Connections {
                target: mouseArea
                function onPressed() {
                    row.pressed = true
                }
                function onReleased() {
                    row.pressed = false
                }
            }
        }
    }
    ParamValue {
        id: paramValue
        color: enabled ? "#000000" : "#878787"

        anchors.verticalCenter: parent.verticalCenter
        width: 60
    }
}
