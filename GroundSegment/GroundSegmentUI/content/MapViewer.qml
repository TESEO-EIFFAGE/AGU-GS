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
    GroundControlStation {
        id: groundControlStation
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
            id: flyingObjectCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "blue"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(groundControlStation.flyingObjectLatitude, groundControlStation.flyingObjectLongitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: true
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
    Rectangle{
        id: zoomLevelSection
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        height: 100
        width: 50
        border.color: "black"
        Column{
            anchors.centerIn: parent

            spacing:4
            Button{
                id: zoomInBtn
                height: 40
                width:parent.width-4
                anchors.topMargin: 2
                anchors.horizontalCenter: parent.horizontalCenter
                text: "+"

                function onClicked(){ m
                    apviewer.zoomLevel+=1
                    console.log("zooming in")
                }
            }
            Button{
                id: zoomOutBtn
                height: 40
                width:parent.width-4
                anchors.horizontalCenter: parent.horizontalCenter

                text: "-"
                function onClicked(){ mapviewer.zoomLevel-=1
                    console.log("zooming out")

                }

            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:4}D{i:6}D{i:8}D{i:1}D{i:11}D{i:18}D{i:24}
D{i:10}D{i:35}D{i:36}D{i:34}D{i:33}
}
##^##*/
