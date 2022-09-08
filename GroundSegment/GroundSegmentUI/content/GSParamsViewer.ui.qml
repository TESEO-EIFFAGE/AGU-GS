import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params
    property int latitude
    property int longitude

    property alias gnssSwitch: gnssSwitch

    property alias txtTimeStamp: txtTimeStamp.value

    property alias txtLatitudeGPSData: txtLatitudeGPSData.value
    property alias txtLongitudeGPSData: txtLongitudeGPSData.value
    property alias txtAltitudeGPSData: txtAltitudeGPSData.value
    property alias txtHasFix: txtHasFix.value
    property alias txtHourGPSData: txtHourGPSData.value
    property alias txtminuteGPSData: txtminuteGPSData.value
    property alias txtsecondGPSData: txtsecondGPSData.value

    width: Constants.width / 2 //750 //C
    height: Constants.height * 1 / 3 //667 //
    color: "#ffffff"
    border.color: "#ffffff"
    property alias txtRadioLinkErrorCounter: txtRadioLinkErrorCounter.value
    property alias radioLinkLight9: radioLinkLight9
    property alias radioLinkLight8: radioLinkLight8
    property alias radioLinkLight3: radioLinkLight3
    property alias radioLinkLight2: radioLinkLight2
    property alias radioLinkLight1: radioLinkLight1
    property alias radioLinkLight0: radioLinkLight0

    ColumnLayout {
        anchors.fill: parent
        spacing: 20
        anchors.margins: 32

        //anchors.leftMargin: 48
        Column {
            spacing: 0 //16
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop

            SectionLabel {
                text: "Ground Segment"
            }

            ParamRow {
                text: "TimeStamp"
                span: 4
                id: txtTimeStamp
            }
        }
        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 12

            //48
            Row {
                Layout.alignment: Qt.AlignTop
                Column {
                    spacing: 32
                    width: 40
                    Image {
                        x: 3
                        y: 0
                        source: "images/svgs/solid/satellite.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "GNSS"
                        transform: Rotation {
                            angle: 90
                            origin.x: 25
                        }
                    }
                }
                Column {
                    spacing: 8

                    ParamRow {
                        text: "Latitude"
                        span: 4
                        id: txtLatitudeGPSData
                        ToolTip.text: text
                        ToolTip.visible: hovered
                    }
                    ParamRow {
                        text: "Longitude"
                        span: 4
                        id: txtLongitudeGPSData
                        ToolTip.text: text
                        ToolTip.visible: hovered
                    }
                    ParamRow {
                        text: "Altitude"
                        span: 4
                        id: txtAltitudeGPSData
                        ToolTip.text: text
                        ToolTip.visible: hovered
                    }
                    ParamRow {
                        text: "HasFix"
                        span: 4
                        id: txtHasFix
                        ToolTip.text: text
                        ToolTip.visible: hovered
                    }

                    Row {
                        spacing: 4
                        ParamRow {
                            text: "Time"
                            span: 4
                            id: txtHourGPSData
                            ToolTip.text: text
                            ToolTip.visible: hovered
                        }
                        ParamRow {
                            text: ":"
                            span: 0.5
                            id: txtminuteGPSData
                        }
                        ParamRow {
                            text: ":"
                            span: 0.5
                            id: txtsecondGPSData
                        }
                    }
                    Switch {
                        id: gnssSwitch

                        text: "Manual Coordinates"
                        height: 24
                        width: 200
                    }
                    Rectangle {
                        visible: true //gnssSwitch.checked
                        width: parent.width //childrenRect.width
                        height: 72 //childrenRect.height
                        color: "transparent"
                        Column {
                            anchors.fill: parent
                            spacing: 4

                            Row {
                                //anchors.horizontalCenter: parent.horizontalCenter
                                Text {
                                    id: latitudeLabel
                                    text: "Latitude: "
                                    font.pointSize: 11
                                    width: 72
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                TextField {
                                    height: 24
                                    width: 120
                                    placeholderText: qsTr("Latitude  ...")
                                    onEditingFinished: text !== "" ? params.latitude = text : params.latitudeIsSet = false
                                }
                            }
                            Row {

                                //anchors.horizontalCenter: parent.horizontalCenter
                                Text {
                                    id: longitudeLabel
                                    text: "Longitude: "
                                    font.pointSize: 11
                                    width: 72
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                TextField {
                                    height: 24
                                    width: 120
                                    placeholderText: qsTr("Longitude ...")

                                    onEditingFinished: text !== "" ? params.longitude = text : params.longitudeIsSet = false
                                }
                            }
                        }
                    }
                }
            }

            //        Rectangle {
            //            id: rectangle
            //            width: 200
            //            height: 200
            //            color: "#d9d9d9"
            //            Layout.preferredHeight: 1
            //            Layout.fillWidth: true
            //        }
            Row {
                Column {

                    spacing: 32
                    width: 40
                    Image {
                        x: 3
                        y: 0
                        source: "images/svgs/solid/radio.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "Radio Link"
                        transform: Rotation {
                            angle: 90
                            origin.x: 25
                        }
                    }
                }

                Column {
                    spacing: 8
                    StatusLight {
                        id: radioLinkLight0
                        text: "RS232 HW failure"
                    }

                    StatusLight {
                        id: radioLinkLight1
                        text: "USB to V-COM failure"
                    }

                    StatusLight {
                        id: radioLinkLight2
                        text: "Radio link monitor comm error"
                    }

                    StatusLight {
                        id: radioLinkLight3
                        text: "RSSI value invalid"
                    }

                    StatusLight {
                        id: radioLinkLight8
                        text: "Heartbeat timeout error"
                    }

                    StatusLight {
                        id: radioLinkLight9
                        text: "Heartbeat checksum error"
                    }

                    ParamRow {
                        id: txtRadioLinkErrorCounter
                        text: "Error counter"
                        span: 4
                        ToolTip.text: text
                        ToolTip.visible: hovered
                    }
                }
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            Item {
                Layout.fillWidth: true
            }
        }
        Item {
            Layout.fillHeight: true
        }
    }
}

/*##^##
Designer {
    D{i:0;height:900;width:700}D{i:3}D{i:4}D{i:2}D{i:8}D{i:9}D{i:7}D{i:12}D{i:13}D{i:14}
D{i:15}D{i:17}D{i:18}D{i:19}D{i:16}D{i:20}D{i:24}D{i:25}D{i:23}D{i:27}D{i:28}D{i:26}
D{i:22}D{i:21}D{i:11}D{i:6}D{i:31}D{i:32}D{i:30}D{i:35}D{i:36}D{i:37}D{i:38}D{i:39}
D{i:40}D{i:41}D{i:34}D{i:29}D{i:42}D{i:5}D{i:43}D{i:1}
}
##^##*/

