import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

import GroundSegmentUI 1.0

Rectangle {
    id: root
    property alias columnTitle: columnTitle

    color: Constants.colorWhite
    radius: 8
    height: contentColumn.height

    states: [
        State {
            name: "open"
            when: open
            PropertyChanges {
                target: advancedSectionBody
                opacity: 1
                visible: true
                height: 90 //advancedSectionBody.childrenRect.height
            }
        }
    ]
    transitions: [
        Transition {
            id: openTransition
            to: "open"
            reversible: true
            enabled: false
            SequentialAnimation {
                PropertyAction {
                    target: advancedSectionBody
                    properties: "visible"
                }
                NumberAnimation {
                    target: advancedSectionBody
                    properties: "height, opacity"
                    duration: 90 //contentColumn.implicitHeight / 2
                }
            }
        }
    ]

    property bool open: false

    Column {
        id: contentColumn

        height: childrenRect.height
        width: valuesColumn.width //parent.width

        spacing: 8 //0
        anchors.top: parent.top
        Rectangle {
            id: overviewBox
            height: 16
            width: parent.width
            anchors.top: parent.top

            MouseArea {
                id: headerArea
                anchors.fill: parent
                Connections {

                    target: headerArea

                    function onClicked() {
                        openTransition.enabled = !openTransition.enabled
                        root.open = !root.open
                        console.log("clicked header")
                    }
                }
            }
            color: Constants.colorPrimaryDark
            radius: 8
            ParamGrp2Label {
                id: columnTitle
                anchors.top: parent.top
                anchors.left: parent.left
                //anchors.topMargin: 8
                anchors.leftMargin: 16

                text: "[title]"
            }
        }
        Rectangle {
            id: advancedSectionBody
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: overviewBox.bottom

            height: root.open ? 90 : 0

            Column {
                id: valuesColumn
                anchors.fill: parent
                anchors.topMargin: 8
                anchors.rightMargin: 16
                anchors.leftMargin: 16
                anchors.bottomMargin: 16
                spacing: 8 //64

                ParamRow {
                    text: "Position"
                    span: 7
                    id: txtPositionAccuracy
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }

                ParamRow {
                    text: "Speed"
                    span: 7
                    id: txtSpeedAccuracy
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }

                ParamRow {
                    text: "# GNSS satellites"
                    span: 7
                    id: txtNumberOfGPSSatellite
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Item {
                implicitWidth: 1
                implicitHeight: 1
            }
        }
    }
}
