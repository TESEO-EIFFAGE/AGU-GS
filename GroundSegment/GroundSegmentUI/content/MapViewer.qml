import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 1.4
import QtLocation 5.15
import QtPositioning 5.6
import agu.gnss 1.0

Item{
    id: mapviewer
    property bool hasGps: gpsData.hasFix
    property int latitude
    property int longitude
    property int zoomLevel: 1//0

    property alias customCursor: customCursor
    //width: Qt.platform.os =ss= "android" ? Screen.width : 512
    //height: Qt.platform.os == "android" ? Screen.height : 512


    visible: true


    //    GPSData {
    //       id: gpsData
    //    }
    //    GroundControlStation {
    //        id: groundControlStation
    //    }
    CustomCursor {
        id: customCursor
        latitude: mapviewer.latitude
        longitude: mapviewer.longitude
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
        center: hasGps ? QtPositioning.coordinate(gpsData.latitude, gpsData.longitude) : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
        zoomLevel: mapviewer.zoomLevel

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
            coordinate : QtPositioning.coordinate(latitude, longitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: customCursor.latitudeIsSet && customCursor.longitudeIsSet
        }
        MapQuickItem {
            id: flyingObjectCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "blue"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(hmi.Latitude, hmi.Longitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: true
        }
        MapRectangle{
            autoFadeIn: false
            opacity: 1
            color:"green"
            topLeft:QtPositioning.coordinate(-0.3354, 1.4524)
            bottomRight:QtPositioning.coordinate(1, 3)
//            topLeft: {
//                longitude:10
//                latitude:-27
//            }
//            bottomRight:
//            {
//                longitude:100
//                latitude:-29
//            }

            //property variant region: QtPositioning.circle(QtPositioning.coordinate(-0.3354+1, 1.4524+1), 1000000)
        }

        //        MapQuickItem {
        //            id: flyingObjectBorder
        //            sourceItem: Rectangle { width: 100; height: 100; color: "transparent"; border.width: 2; border.color: "green"; smooth: true;  }
        //            coordinate : QtPositioning.coordinate(hmi.Latitude, hmi.Longitude)
        //            opacity: 1.0
        //            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
        //            visible: true
        //        }

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

        //        Rectangle {
        //            id: gpsDataSection
        //            anchors.left: gpsDataRectangle.left; anchors.leftMargin: 5
        //            anchors.right: parent.right; anchors.rightMargin: 5
        //            height: 150
        //            color: "transparent"

        //            Text {
        //                id: gpsDataSectionTitle
        //                visible: false
        //                text: "GPS data"
        //                font.pointSize: 13; font.bold: true
        //                anchors.top: gpsDataSection.top
        //                anchors.horizontalCenter: parent.horizontalCenter
        //            }

        //            Text {
        //                id: longitude
        //                visible: false
        //                text: "Longitude: " + (gpsData.longitude).toFixed(5) + "°"
        //                font.pointSize: 11;
        //                anchors.top: gpsDataSectionTitle.bottom
        //            }

        //            Text {
        //                id: latitude
        //                visible: false
        //                text: "Latitude: " + (gpsData.latitude).toFixed(5) + "°"
        //                font.pointSize: 11;
        //                anchors.top: longitude.bottom
        //            }

        //            Text {
        //                id: altitude
        //                visible: false
        //                text: "Altitude: " + gpsData.altitude + "m"
        //                font.pointSize: 11;
        //                anchors.top: latitude.bottom
        //            }

        //            Text {
        //                id: time
        //                visible: false
        //                text: "UTC Time: " + gpsData.hour.valueOf() + ":" + gpsData.minute.valueOf() + ":" + gpsData.second.valueOf()
        //                font.pointSize: 11;
        //                anchors.top: altitude.bottom
        //            }

        //            Text {
        //                id: hasFix
        //                visible: false
        //                text: "Has fix: " + gpsData.hasFix
        //                font.pointSize: 11;
        //                anchors.top: time.bottom
        //            }
        //        }


        Rectangle {
            id: legendSection
            anchors.top:parent.top
            anchors.left: parent.left; anchors.leftMargin: 10
            // anchors.right: parent.right
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
                    Text{text: "GS (Manual)"; anchors.verticalCenter: parent.verticalCenter}
                }
                Row{
                    width: parent.width
                    spacing: 4
                    Rectangle { width: 20; height: 20; color: "purple"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
                    Text{text: "GS (GNSS)"; anchors.verticalCenter: parent.verticalCenter}
                }
                Row{
                    width: parent.width
                    spacing: 4
                    Rectangle { width: 20; height: 20; color: "blue"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
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
            width:parent.width
            spacing:4
            Button{
                id: zoomInBtn
                height: 40
                width:parent.width-4
                anchors.topMargin: 2
                anchors.horizontalCenter: parent.horizontalCenter
                text: "+"

                onClicked:{
                    mapviewer.zoomLevel+=1
                    console.log("zooming in")
                    if(mapviewer.hasGps){
                        map.center= QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
                    }
                    else{
                        map.center= QtPositioning.coordinate(customCursor.longitude, customCursor.latitude)
                    }

                }
            }
            Button{
                id: zoomOutBtn
                height: 40
                width:parent.width-4
                anchors.horizontalCenter: parent.horizontalCenter

                text: "-"
                onClicked:{ mapviewer.zoomLevel-=1
                    console.log("zooming out")

                    if(mapviewer.hasGps){
                        map.center= QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
                    }
                    else{
                        map.center= QtPositioning.coordinate(customCursor.longitude, customCursor.latitude)
                    }

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
