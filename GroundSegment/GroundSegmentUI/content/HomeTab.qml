import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Pane {
    background: Rectangle{
    color:"transparent"
    }


    property bool lit

    property alias txtSystemMsgCounter: txtSystemMsgCounter.value

    property alias txtLatitude: txtLatitude
    property alias txtLongitude: txtLongitude
    property alias txtGNSSAltitude: txtGNSSAltitude


    property alias txtRollAngle: txtRollAngle
    property alias txtPitchAngle: txtPitchAngle
    property alias txtYawAngle: txtYawAngle


    property alias txtLinearVelocityHorizontal: txtLinearVelocityHorizontal
    property alias txtLinearVelocityVertical: txtLinearVelocityVertical
    property alias txtAirSpeed_UVector: txtAirSpeed_UVector
    property alias txtAirSpeed_VVector: txtAirSpeed_VVector
    property alias txtAirSpeed_WVector: txtAirSpeed_WVector

    property alias coreLight4: coreLight4
    property alias coreLight3: coreLight3
    property alias coreLight2: coreLight2
    property alias coreLight1: coreLight1
    property alias coreLight0: coreLight0

    Flow {
        width:parent.width
        height: childrenRect.height
        //anchors.fill:parent
        id: gridHome
        spacing: 32
        //columnSpacing: 24
        //rowSpacing: 12

        //columns: 6
        //rows: 1
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Module Status"
            }
        StatusLight {
            id: coreLight0
            text: "Telemetry module status"
        }
        StatusLight {
            id: coreLight1
            text: "Guidance module status"
        }
        StatusLight {
            id: coreLight2
            text: "Motor Control module status"
        }
        StatusLight {
            id: coreLight3
            text: "Radio Link module status"
        }
        StatusLight {
            id: coreLight4
            text: "Storage module status"
        }
}
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Coordinates"
            }
        ParamRow {
            id: txtLatitude
            text: "Latitude (°)"
            span: 7
            ToolTip.text: desc
            ToolTip.visible: pressed
        }

        ParamRow {
            text: "Longitude (°)"
            span: 7
            id: txtLongitude
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        ParamRow {
            text: "Altitude (m)"
            span: 7
            id: txtGNSSAltitude
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        }
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Rotation (°)"
            }
        ParamRow {
            text: "Roll"
            span: 3
            id: txtRollAngle
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        ParamRow {
            text: "Pitch"
            span: 3
            id: txtPitchAngle
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        ParamRow {
            text: "Yaw"
            span: 3
            id: txtYawAngle
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        }
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Velocity (m/s)"
            }
        ParamRow {
            text: "Horizontal Velocity"
            span: 7
            id: txtLinearVelocityHorizontal
            ToolTip.text: desc
            ToolTip.visible: pressed
        }

        ParamRow {
            text: "Vertical Velocity"
            span: 7
            id: txtLinearVelocityVertical
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        }
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Air Speed (m/s)"
            }
        ParamRow {
            text: "Air Speed U"
            span: 5
            id: txtAirSpeed_UVector
            ToolTip.text: desc
            ToolTip.visible: pressed
        }

        ParamRow {
            text: "Air Speed V"
            span: 5
            id: txtAirSpeed_VVector
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        ParamRow {
            text: "Air Speed W"
            span: 5
            id: txtAirSpeed_WVector
            ToolTip.text: desc
            ToolTip.visible: pressed
        }
        }
        ParamRow {
            text: "N. System msg"
            span: 5
            id: txtSystemMsgCounter
            ToolTip.text: text
            ToolTip.visible: pressed
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:1080}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}D{i:2}
D{i:10}D{i:11}D{i:12}D{i:13}D{i:9}D{i:15}D{i:16}D{i:17}D{i:18}D{i:14}D{i:20}D{i:21}
D{i:22}D{i:19}D{i:24}D{i:25}D{i:26}D{i:27}D{i:23}D{i:28}D{i:1}
}
##^##*/
