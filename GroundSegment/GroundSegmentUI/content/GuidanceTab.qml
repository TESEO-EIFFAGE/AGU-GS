import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    color:"transparent"

    property bool lit


    Flow {
        width:parent.width
        height: childrenRect.height
        id: gridGuidance
spacing: 16


    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}
}
##^##*/
