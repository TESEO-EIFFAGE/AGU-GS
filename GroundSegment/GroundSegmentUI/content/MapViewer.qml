import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 1.4
import QtLocation 5.15
import QtPositioning 5.6
import io.qt.examples.gps_data 1.0


Item{
    id: mapviewer
    property bool hasGps: gpsData.hasFix
    property int zoomLevel: 10
    //width: Qt.platform.os =ss= "android" ? Screen.width : 512
    //height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true


    GPSData {
       id: gpsData
    }

    CustomCursor {
       id: customCursor
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            id: mapPlugin
            name: "osm"
             PluginParameter {
                 name: "osm.mapping.offline.directory"
                 value: ":/Offline_tiles/"
            }
        }
        center: hasGps ? QtPositioning.coordinate(gpsData.longitude, gpsData.latitude) : QtPositioning.coordinate(customCursor.longitude, customCursor.latitude)
        zoomLevel: mapviewer.zoomLevel

        MapQuickItem {
            id: gpsCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "red"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: gpsData.hasFix
        }

        MapQuickItem {
            id: customCursorIcon
            sourceItem: Rectangle { width: 20; height: 20; color: "yellow"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: customCursor.latitudeIsSet && customCursor.longitudeIsSet
        }
        MapQuickItem {
            id: flightSegmentIcon
            sourceItem: Rectangle { width: 20; height: 20; color: "red"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(customCursor.latitude+0.1, customCursor.longitude+0.2)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: customCursor.latitudeIsSet && customCursor.longitudeIsSet
        }
    }

    Rectangle {
        id: gpsDataRectangle
        width: 200; height: 310
        color: "#FFD2D2D2"
        opacity: 0.75
        x: 5; y: 5
        border.color: "black"

        Rectangle {
            id: gpsDataSection
            anchors.left: gpsDataRectangle.left; anchors.leftMargin: 5
            anchors.right: parent.right; anchors.rightMargin: 5
            height: 150
            color: "transparent"

            Text {
                id: gpsDataSectionTitle
                text: "GPS data"
                font.pointSize: 13; font.bold: true
                anchors.top: gpsDataSection.top
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: longitude
                text: "Longitude: " + (gpsData.longitude).toFixed(5) + "°"
                font.pointSize: 11;
                anchors.top: gpsDataSectionTitle.bottom
            }

            Text {
                id: latitude
                text: "Latitude: " + (gpsData.latitude).toFixed(5) + "°"
                font.pointSize: 11;
                anchors.top: longitude.bottom
            }

            Text {
                id: altitude
                text: "Altitude: " + gpsData.altitude + "m"
                font.pointSize: 11;
                anchors.top: latitude.bottom
            }

            Text {
                id: time
                text: "UTC Time: " + gpsData.hour.valueOf() + ":" + gpsData.minute.valueOf() + ":" + gpsData.second.valueOf()
                font.pointSize: 11;
                anchors.top: altitude.bottom
            }

            Text {
                id: hasFix
                text: "Has fix: " + gpsData.hasFix
                font.pointSize: 11;
                anchors.top: time.bottom
            }
        }

        Rectangle {
            id: customCursorSection
            color: "#00000000"
            height: childrenRect.height
            anchors.top: gpsDataSection.bottom
            anchors.left: parent.left; anchors.leftMargin: 5
            anchors.right: parent.right

            Text {
                id: customCursorSectionTitle
                text: "Custom cursor"
                font.pointSize: 13; font.bold: true
                anchors.top: customCursorSection.top
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: latitudeLabel
                text: "Lat: "
                font.pointSize: 11;
                anchors.top: customCursorSectionTitle.bottom
                anchors.topMargin: 4
            }

            TextField {
                placeholderText: qsTr("Latitude  ...")
                anchors.top: latitudeLabel.top
                anchors.left: latitudeLabel.right
                anchors.right: customCursorSection.right; anchors.rightMargin: 5
                onEditingFinished: text !== "" ? customCursor.latitude = text : customCursor.latitudeIsSet = false
            }

            Text {
                id: longitudeLabel
                text: "Long: "
                font.pointSize: 11;
                anchors.top: latitudeLabel.bottom
                anchors.topMargin: 5
            }

            TextField {
                placeholderText: qsTr("Longitude ...")
                anchors.top: longitudeLabel.top
                anchors.left: longitudeLabel.right;
                anchors.right: customCursorSection.right; anchors.rightMargin: 5
                onEditingFinished: text !== "" ? customCursor.longitude = text : customCursor.longitudeIsSet = false
            }
        }
        Rectangle {
            id: legendSection
            anchors.top: customCursorSection.bottom
            anchors.left: parent.left; anchors.leftMargin: 5
            anchors.right: parent.right
            Column{
                anchors.top:parent.top
                height: childrenRect.height+14
                anchors.topMargin: 8
                spacing: 4
                Text {
                    id: legendSectionTitle
                    text: "Legend"
                    font.pointSize: 13; font.bold: true

                    anchors.horizontalCenter: parent.horizontalCenter
                }
            Row{
                width: parent.width
                spacing: 4
                Rectangle { width: 20; height: 20; color: "yellow"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                Text{text: "Ground Segment"; anchors.verticalCenter: parent.verticalCenter}
            }
            Row{
                width: parent.width
                spacing: 4
                Rectangle { width: 20; height: 20; color: "red"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                Text{text: "Flight Segment"; anchors.verticalCenter: parent.verticalCenter}
            }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:4}D{i:6}D{i:8}D{i:1}D{i:12}D{i:13}D{i:14}
D{i:15}D{i:16}D{i:17}D{i:11}D{i:19}D{i:20}D{i:21}D{i:22}D{i:23}D{i:18}D{i:26}D{i:28}
D{i:29}D{i:27}D{i:31}D{i:32}D{i:30}D{i:25}D{i:24}D{i:10}
}
##^##*/
