

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    border.width: 0
    property alias gsParams: gsParams
    property alias fsParams: fsParams

    MapViewer {
        id: map
        //color: "lightblue"
        width: parent.width * 4 / 12
        height: parent.height
        anchors.left: parent.left
    }

    FSParamsViewer {
        id: fsParams
        width: parent.width * 6 / 12
        height: parent.height
        anchors.left: map.right
        anchors.right: gsParams.left
    }

    GSParamsViewer {
        id: gsParams
        width: parent.width * 2 / 12
        height: parent.height
        color: "#e9f2de"
        anchors.right: parent.right
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

