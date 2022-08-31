import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    id: params

    property alias txtTimeStamp: txtTimeStamp.value

    property alias txtLatitudeGPSData: txtLatitudeGPSData.value
    property alias txtLongitudeGPSData: txtLongitudeGPSData.value
    property alias txtAltitudeGPSData: txtAltitudeGPSData.value
    property alias txtHasFix: txtHasFix.value
    property alias txtHourGPSData: txtHourGPSData.value
    property alias txtminuteGPSData: txtminuteGPSData.value
    property alias txtsecondGPSData: txtsecondGPSData.value

    width: Constants.width / 2 //750 //C
    height: Constants.height //667 //
    color: "#ffffff"
    border.color: "#ffffff"
    ColumnLayout {
        anchors.fill: parent
        spacing: 16
        anchors.margins: 32

        Row {
            id: row
            spacing: 32

            SectionLabel {
                text: "Ground Segment"
                anchors.verticalCenter: parent.verticalCenter
            }

            ParamRow {
                text: "TimeStamp"
                anchors.verticalCenter: parent.verticalCenter
                id: txtTimeStamp
            }
        }
        RowLayout {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            spacing: 48
            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                spacing: 8
                ParamRow {
                    text: "Latitude"
                    id: txtLatitudeGPSData
                }
                ParamRow {
                    text: "Longitude"
                    id: txtLongitudeGPSData
                }
                ParamRow {
                    text: "Altitude"
                    id: txtAltitudeGPSData
                }
                ParamRow {
                    text: "HasFix"
                    id: txtHasFix
                }

                Row {
                    spacing: 8
                    ParamRow {
                        text: "Time"
                        id: txtHourGPSData
                    }
                    ParamRow {
                        text: ":"
                        id: txtminuteGPSData
                    }
                    ParamRow {
                        text: ":"
                        id: txtsecondGPSData
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}

/*##^##
Designer {
    D{i:0;height:900;width:320}
}
##^##*/

