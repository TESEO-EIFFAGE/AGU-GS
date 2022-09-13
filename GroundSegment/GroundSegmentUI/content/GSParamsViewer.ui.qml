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
    property alias txtRLHeartbeatCounter: txtRLHeartbeatCounter.value
    property alias txtRadioLinkErrorCounter: txtRadioLinkErrorCounter.value
    property alias radioLinkLight9: radioLinkLight9
    property alias radioLinkLight8: radioLinkLight8
    property alias radioLinkLight3: radioLinkLight3
    property alias radioLinkLight2: radioLinkLight2
    property alias radioLinkLight1: radioLinkLight1
    property alias radioLinkLight0: radioLinkLight0

    ColumnLayout {
        anchors.fill: parent
        spacing: 24 //20
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
            Column {
                Layout.alignment: Qt.AlignTop
                spacing: 8
                Row {
                    spacing: 8
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
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                ParamRow {
                    text: "Latitude"
                    span: 4
                    id: txtLatitudeGPSData
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
                ParamRow {
                    text: "Longitude"
                    span: 4
                    id: txtLongitudeGPSData
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
                ParamRow {
                    text: "Altitude"
                    span: 4
                    id: txtAltitudeGPSData
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
                ParamRow {
                    text: "HasFix"
                    span: 4
                    id: txtHasFix
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }

                Row {
                    spacing: 4
                    ParamRow {
                        text: "Time"
                        span: 4
                        id: txtHourGPSData
                        ToolTip.text: text
                        ToolTip.visible: pressed
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
                Row {
                    Text {
                        text: "Manual coordinates"
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Switch {
                        id: gnssSwitch
                        height: 24
                    }
                }
                Rectangle {
                    visible: gnssSwitch.checked
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
                                //font.pointSize: 11
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
                                //font.pointSize: 11
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

            //        Rectangle {
            //            id: rectangle
            //            width: 200
            //            height: 200
            //            color: "#d9d9d9"
            //            Layout.preferredHeight: 1
            //            Layout.fillWidth: true
            //        }
            Column {
                spacing: 8
                Layout.alignment: Qt.AlignTop

                Row {

                    spacing: 8

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
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
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
                    text: "Monitor comm error"
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
                    id: txtRLHeartbeatCounter
                    text: "Heartbeat counter"
                    span: 6
                    ToolTip.text: text
                    ToolTip.visible: pressed
                }
                ParamRow {
                    id: txtRadioLinkErrorCounter
                    text: "Error counter"
                    span: 4
                    ToolTip.text: text
                    ToolTip.visible: pressed
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
