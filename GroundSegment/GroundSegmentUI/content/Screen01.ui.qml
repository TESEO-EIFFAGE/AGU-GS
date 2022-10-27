

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
    property alias tabIndex: fsParams.tabIndex
    property alias telemetryTab: fsParams.telemetryTab
    property alias motorsBMSTab: fsParams.motorsBMSTab
    property alias storageTab: fsParams.storageTab
    property alias radioLinkTab: fsParams.radioLinkTab
    property alias guidanceTab: fsParams.guidanceTab
    property alias coreTab: fsParams.coreTab

    property alias customCursor: map.customCursor
    property alias map: map
    property alias mapBoundaries: map.mapBoundaries
    RowLayout {
        anchors.fill: parent
        spacing: 0
        ColumnLayout {
            Layout.preferredWidth: 550
            Layout.minimumWidth: 550
            Layout.maximumWidth: 550
            Layout.fillHeight: true
            spacing: 0
            GSParamsViewer {
                id: gsParams
                Layout.minimumHeight: 350 //parent.height * 12 / 30

                //Layout.minimumHeight: parent.height * 12 / 30
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "#e9f2de"
            }
            MapViewer {
                id: map
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumHeight: 550 //parent.height * 18 / 30
                Layout.preferredHeight: 550 //(parent.height * 18 / 30) - 1
                //width: 550 //parent.width * 3.6 / 12
                //height: parent.height * 18 / 30
                //        anchors.top: gsParams.bottom
                //        anchors.left: parent.left
            }
        }

        FSParamsViewer {
            id: fsParams
            Layout.fillHeight: true
            Layout.fillWidth: true
            //width: parent.width -map.width//* 8.4 / 12
            //height: parent.height
            //anchors.left: parent.right
        }
    }
    Image {
        id: teseoLogo
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 16
        anchors.topMargin: 24
        height: sourceSize.height / 4
        width: sourceSize.width / 4
        visible: parent.width < 1100 ? false : true
        source: "images/Teseo_01_colour_RGB_LR.jpg"
        fillMode: Image.PreserveAspectFit
    }
    Image {
        anchors.right: teseoLogo.left
        anchors.top: parent.top
        anchors.rightMargin: 16
        anchors.topMargin: 16
        height: sourceSize.height / 3
        width: sourceSize.width / 3
        visible: parent.width < 1200 ? false : true
        source: "images/Thales_Alenia_Space_logo.png"
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

