import QtQuick 2.15
import GroundSegmentUI 1.0

Row {
    id: root
    property var up
    property alias text: text1.text
    spacing: 8
    width: 200
    states: [
        State {
            name: ""
            when: typeof (up) == "undefined"
            PropertyChanges {
                target: light
                color: "yellow"
            }
        },
        State {
            name: "lightUp"
            when: up //=== 1
            PropertyChanges {
                target: light
                color: "#ff0000"
            }
        },
        State {
            name: "lightDown"
            when: !up //=== 0
            PropertyChanges {
                target: light
                color: "#b1b1b1"
            }
        }
    ]
    Rectangle {
        id: light
        width: 16
        height: 16
        color: "#b1b1b1" //root.up == true ? "#ff0000" : (root.up == false ? "#b1b1b1" : "yellow")
        radius: 8
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: text1
        text: qsTr("Text")
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
        font.family: "Roboto"
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:0;width:0}
}
##^##*/

