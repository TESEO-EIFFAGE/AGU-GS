

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
    border.color: "#ffffff"
    border.width: 0
    property alias gsParams: gsParams
    property alias fsParams: fsParams
    property alias customCursor: map.customCursor
    property alias map: map
    GSParamsViewer {
        id: gsParams
        width: parent.width * 3 / 12
        height: parent.height * 10 / 30
        color: "#e9f2de"
        anchors.left: parent.left
        anchors.top: parent.top
    }
    MapViewer {
        id: map
        //color: "lightblue"
        width: parent.width * 3 / 12
        height: parent.height * 20 / 30
        anchors.top: gsParams.bottom
        anchors.left: parent.left
    }

    FSParamsViewer {
        id: fsParams
        width: parent.width * 9 / 12
        height: parent.height
        anchors.left: map.right
    }
    Image {
        id: teseoLogo
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 16
        anchors.topMargin: 20
        height: sourceSize.height / 4
        width: sourceSize.width / 4
        source: "images/Teseo_01_colour_RGB_LR.jpg"
        fillMode: Image.PreserveAspectFit
    }
    Image {
        anchors.right: teseoLogo.left
        anchors.top: parent.top
        anchors.rightMargin: 16
        anchors.topMargin: 16
        height: sourceSize.height / 8
        width: sourceSize.width / 8
        source: "images/Thales_Alenia_Space_logo.png"
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:4}D{i:5}
}
##^##*/

