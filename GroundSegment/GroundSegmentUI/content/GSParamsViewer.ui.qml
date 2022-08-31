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

        Column {
            spacing: 0

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
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            spacing: 48
            Column {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                spacing: 8
                Row {
                    id: row1
                    Image {
                        id: satellite
                        source: "images/svgs/solid/satellite.svg"
                        fillMode: Image.PreserveAspectFit
                        sourceSize.height: 24
                        sourceSize.width: 24
                    }

                    ParamGrp1Label {
                        text: "GNSS"
                        Layout.topMargin: 8
                    }
                    spacing: 8
                }

                ParamRow {
                    text: "Latitude"
                    span: 4
                    id: txtLatitudeGPSData
                }
                ParamRow {
                    text: "Longitude"
                    span: 4
                    id: txtLongitudeGPSData
                }
                ParamRow {
                    text: "Altitude"
                    span: 4
                    id: txtAltitudeGPSData
                }
                ParamRow {
                    text: "HasFix"
                    span: 4
                    id: txtHasFix
                }

                Row {
                    spacing: 8
                    ParamRow {
                        text: "Time"
                        span: 4
                        id: txtHourGPSData
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

