

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
    property alias params: params

    //    RowLayout {
    //        id: rowLayout
    //        anchors.fill: parent
    MapViewer {
        id: map
        width: parent.width / 2
        height: parent.height
        anchors.left: parent.left
        //width: parent.implicitWidth
        //Layout.preferredWidth: 512
        //            Layout.fillHeight: true
        //            Layout.fillWidth: true
    }

    ParamsViewer {
        id: params
        width: parent.width / 2
        height: parent.height
        anchors.right: parent.right
        //            Layout.fillHeight: true
        //            Layout.fillWidth: true
    }
    //  }
}

/*##^##
Designer {
    D{i:0;height:600;width:1200}
}
##^##*/
