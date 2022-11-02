import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

import GroundSegmentUI 1.0

Item {
    id: root
    property alias columnTitle: columnTitle
    property alias contentColumn: contentColumn
    //    property alias gridColumns: valuesGrid.columns
    //    property alias gridRows: valuesGrid.rows

    property alias light31: light31
    property alias light30: light30
    property alias light29: light29
    property alias light28: light28
    property alias light27: light27
    property alias light26: light26
    property alias light25: light25
    property alias light24: light24
    property alias light23: light23
    property alias light22: light22
    property alias light21: light21
    property alias light20: light20
    property alias light19: light19
    property alias light18: light18
    property alias light17: light17
    property alias light16: light16
    property alias light15: light15
    property alias light14: light14
    property alias light13: light13
    property alias light12: light12
    property alias light11: light11
    property alias light10: light10
    property alias light9: light9
    property alias light8: light8
    property alias light7: light7
    property alias light6: light6
    property alias light5: light5
    property alias light4: light4
    property alias light3: light3
    property alias light2: light2
    property alias light1: light1
    property alias light0: light0

    height: contentColumn.height
    width: 400

    states: [
        State {
            name: "open"
            when: open
            PropertyChanges {
                target: advancedSectionBody
                opacity: 1
                visible: true
                height: 222 //advancedSectionBody.childrenRect.height
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
                    duration: 222 //contentColumn.implicitHeight / 2
                }
            }
        }
    ]

    property bool open: true

    Column {
        id: contentColumn

        height: childrenRect.height
        width: parent.width
        clip: true
        spacing: 8//0
        //anchors.top: parent.top
        Rectangle {
            id: overviewBox
            color: "transparent"
            height: 24
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
            Row{
                anchors.fill: parent
                spacing:24
                anchors.top: parent.top
                anchors.left: parent.left
                ParamGrp2Label {
                    id: columnTitle

                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.topMargin: 8
                    //anchors.leftMargin: 16
                    text: "[title]"
                }
                Image {
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
        }
        Item {
            id: advancedSectionBody
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 8
//            anchors.top: overviewBox.bottom
            clip: true
            height: root.open ? 222 : 0

            Flow {
                id: valuesGrid
                width:parent.width
                height:parent.height
                spacing: 16
                //                columnSpacing: 16
                //                rowSpacing: 12
                flow: Grid.TopToBottom
                //                columns: 4
                //                rows: 8
                anchors.topMargin: 8
                anchors.rightMargin: 16
                //anchors.leftMargin: 16
                anchors.bottomMargin: 16
                //spacing: 8 //64


                StatusLight {
                    id: light0
                    text: "[light]"
                }

                StatusLight {
                    id: light1
                    text: "[light]"
                }

                StatusLight {
                    id: light2
                    text: "[light]"
                }

                StatusLight {
                    id: light3
                    text: "[light]"
                }
                StatusLight {
                    id: light4
                    text: "[light]"
                }

                StatusLight {
                    id: light5
                    text: "[light]"
                }
                StatusLight {
                    id: light6
                    text: "[light]"
                }

                StatusLight {
                    id: light7
                    text: "[light]"
                }
                StatusLight {
                    id: light8
                    text: "[light]"
                }
                StatusLight {
                    id: light9
                    text: "[light]"
                }
                StatusLight {
                    id: light10
                    text: "[light]"
                }

                StatusLight {
                    id: light11
                    text: "[light]"
                }

                StatusLight {
                    id: light12
                    text: "[light]"
                }

                StatusLight {
                    id: light13
                    text: "[light]"
                }
                StatusLight {
                    id: light14
                    text: "[light]"
                }

                StatusLight {
                    id: light15
                    text: "[light]"
                }
                StatusLight {
                    id: light16
                    text: "[light]"
                }

                StatusLight {
                    id: light17
                    text: "[light]"
                }
                StatusLight {
                    id: light18
                    text: "[light]"
                }

                StatusLight {
                    id: light19
                    text: "[light]"
                }
                StatusLight {
                    id: light20
                    text: "[light]"
                }

                StatusLight {
                    id: light21
                    text: "[light]"
                }

                StatusLight {
                    id: light22
                    text: "[light]"
                }

                StatusLight {
                    id: light23
                    text: "[light]"
                }
                StatusLight {
                    id: light24
                    text: "[light]"
                }

                StatusLight {
                    id: light25
                    text: "[light]"
                }
                StatusLight {
                    id: light26
                    text: "[light]"
                }

                StatusLight {
                    id: light27
                    text: "[light]"
                }
                StatusLight {
                    id: light28
                    text: "[light]"
                }

                StatusLight {
                    id: light29
                    text: "[light]"
                }

                StatusLight {
                    id: light30
                    text: "[light]"
                }

                StatusLight {
                    id: light31
                    text: "[light]"
                }
            }
        }

//        Item {
//            Layout.fillWidth: true
//            Layout.fillHeight: true
//            Item {
//                implicitWidth: 1
//                implicitHeight: 1
//            }
//        }
    }
}
