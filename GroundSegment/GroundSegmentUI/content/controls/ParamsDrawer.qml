import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

import GroundSegmentUI 1.0

Item {
    id: root
    property alias columnTitle: columnTitle
    property alias contentColumn: contentColumn
    property alias spacer: spacer
    property alias param1: param1
    property alias param2: param2
    property alias param3: param3

    height: contentColumn.height
    width: 180

    states: [
        State {
            name: "open"
            when: open
            PropertyChanges {
                target: advancedSectionBody
                opacity: 1
                visible: true
                height: 80 //advancedSectionBody.childrenRect.height
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
                    duration: 80 //contentColumn.implicitHeight / 2
                }
            }
        }
    ]

    property bool open: false

    Column {
        id: contentColumn

        height: childrenRect.height+8
        width: parent.width
        clip: true
        spacing: 0
        anchors.top: parent.top
        Rectangle {
            id: overviewBox
            color: "transparent"
            height: 16
            width: parent.width
            //anchors.top: parent.top

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

            radius: 8

            ParamGrp2Label {
                id: columnTitle
                anchors.top: parent.top
                anchors.left: parent.left

                //anchors.topMargin: 8
                //anchors.leftMargin: 16
                text: "[title]"
            }
            Item{
                id: spacer
                width: 1
            }

            Image {
                anchors.right: parent.right
                anchors.rightMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                source: "../images/svgs/solid/chevron-down.svg"
                fillMode: Image.PreserveAspectFit
                height:16
                width: 16
                rotation: root.open ? 0 : 180
                sourceSize.height: 16
                sourceSize.width: 16
                z:1
            }
        }
        Item {
            implicitHeight: 1
            implicitWidth: 1
        }
        Item {
            id: advancedSectionBody
            anchors.left: parent.left
            anchors.right: parent.right
            clip: true
            height: root.open ? 80 : 0

            Column {
                id: valuesColumn
                anchors.fill: parent
                anchors.topMargin: 8
                anchors.rightMargin: 16
                //anchors.leftMargin: 16
                anchors.bottomMargin: 16
                spacing: 8 //64

                ParamRow {

                    text: "[param1]"

                    id: param1
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                ParamRow {
                    text: "[param2]"

                    id: param2
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }

                ParamRow {
                    text: "[param3]"

                    id: param3
                    ToolTip.text: desc
                    ToolTip.visible: pressed
                }
            }
        }
    }
}
