import QtQuick 2.15
import GroundSegmentUI 1.0

Row {
    id: root
    property bool up: false
    property alias text: text1.text
    spacing: 8

    Rectangle {
        id: light
        width: 16
        height: 16
        color: root.up ? "#ff0000" : "#b1b1b1"
        radius: 8
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: text1
        text: qsTr("Text")
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
        font.family: "Titillium Web"
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:0;width:0}
}
##^##*/

