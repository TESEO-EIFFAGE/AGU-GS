import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11

Rectangle {
    id: map

    color: "#ffffff"
    MapViewer{
        anchors.fill:parent
    }

}
