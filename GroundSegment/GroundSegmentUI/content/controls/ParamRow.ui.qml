import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0

Row {
    id: row
    spacing: 8
    property real span: 1
    property alias text: paramLabel.text
    property alias value: paramValue.text
    ParamLabel {
        id: paramLabel
        anchors.verticalCenter: parent.verticalCenter
        width: 16 * span
    }
    ParamValue {
        id: paramValue
        anchors.verticalCenter: parent.verticalCenter
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

