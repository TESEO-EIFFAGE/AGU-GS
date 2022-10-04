import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    color:"transparent"

    property bool lit

    Grid {
        anchors.fill:parent
        id: gridStorage
        columnSpacing: 16
        rowSpacing: 12
        flow: Grid.TopToBottom
        columns: 4
        rows: 6


    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}
D{i:9}D{i:10}D{i:11}D{i:12}D{i:13}D{i:14}D{i:15}D{i:16}D{i:17}D{i:18}D{i:19}D{i:20}
D{i:21}D{i:22}D{i:23}D{i:24}D{i:1}
}
##^##*/
