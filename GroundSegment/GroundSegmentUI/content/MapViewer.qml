import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15
import agu.gnss 1.0

Item {
    id: root
    property bool hasGps: gpsData.hasFix
    property alias latitude: customCursor.latitude
    property alias longitude: customCursor.longitude
    property alias customCursor: customCursor
    property alias customCursorIcon: customCursorIcon
    property alias mapBoundaries: mapBoundaries

    CustomCursor {
        id: customCursor
    }

    Map {
        id: map
        anchors.fill: parent
        gesture.acceptedGestures: MapGestureArea.NoGesture
        plugin: Plugin {
            id: mapPlugin
            name: "osm"
            PluginParameter {
                name: "osm.mapping.offline.directory"
                value: ":/Offline_tiles/"
            }
        }
        center: gpsData.hasFix ? QtPositioning.coordinate(gpsData.latitude, gpsData.longitude) : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
        zoomLevel: 0
        minimumZoomLevel: -1

        MapQuickItem {
            id: gpsCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "purple"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(gpsData.latitude, gpsData.longitude)

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
            visible: !gpsData.hasFix && customCursor.latitudeIsSet && customCursor.longitudeIsSet
        }
        MapQuickItem {
            id: flyingObjectCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "blue"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(hmi.Latitude, hmi.Longitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: true
        }
        MapRectangle {
            id: mapBoundaries
            autoFadeIn: false
            opacity: 1
            border.color: "green"
            border.width: 3
            topLeft: QtPositioning.coordinate(-0.3354, 1.4524)
            bottomRight: QtPositioning.coordinate(1, 3)
        }
    }

    Rectangle {
        id: gpsDataRectangle
        width: 160; height: 110
        anchors.left:parent.left
        anchors.leftMargin: 8
        color: "#FFD2D2D2"
        opacity: 0.75
        x: 5; y: 5
        border.color: "black"

        Rectangle {
            id: legendSection
            anchors.top:parent.top
            anchors.left: parent.left; anchors.leftMargin: 10

            Column {
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
                Row {
                    width: parent.width
                    spacing: 4
                    Rectangle { width: 20; height: 20; color: "yellow"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                    Text{text: "GS (Manual)"; anchors.verticalCenter: parent.verticalCenter}
                }
                Row {
                    width: parent.width
                    spacing: 4
                    Rectangle { width: 20; height: 20; color: "purple"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                    Text{text: "GS (GNSS)"; anchors.verticalCenter: parent.verticalCenter}
                }
                Row {
                    width: parent.width
                    spacing: 4
                    Rectangle { width: 20; height: 20; color: "blue"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                    Text{text: "Flight Segment"; anchors.verticalCenter: parent.verticalCenter}
                }
            }
        }
    }
    Rectangle {
        id: zoomLevelSection
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        height: 100
        width: 50
        border.color: "black"
        Column {
            anchors.centerIn: parent
            width:parent.width
            spacing:4
            Button {
                id: zoomInBtn
                height: 40
                width:parent.width-4
                anchors.topMargin: 2
                anchors.horizontalCenter: parent.horizontalCenter
                text: "+"
                onClicked: {
                    map.center = gpsData.hasFix ? QtPositioning.coordinate(gpsData.latitude, gpsData.longitude) : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
                    map.zoomLevel+=1
                }
            }
            Button {
                id: zoomOutBtn
                height: 40
                width:parent.width-4
                anchors.horizontalCenter: parent.horizontalCenter
                text: "-"
                onClicked: {
                    map.center = gpsData.hasFix ? QtPositioning.coordinate(gpsData.latitude, gpsData.longitude) : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
                    map.zoomLevel-=1
                }
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
