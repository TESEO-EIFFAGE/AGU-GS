import QtQuick 2.15
import QtQuick.Controls 2.15
import GroundSegmentUI 1.0
import QtQuick.Layouts 1.11
import "controls"

Rectangle {
    color:"transparent"

    property bool lit

    property alias txtLatitude: txtLatitude.value
    property alias txtLongitude: txtLongitude.value
    property alias txtGNSSAltitude: txtGNSSAltitude.value
    property alias txtAirSpeed_UVector: txtAirSpeed_UVector.value

    property alias txtAirSpeed_VVector: txtAirSpeed_VVector.value
    property alias txtAirSpeed_WVector: txtAirSpeed_WVector.value
    property alias txtAirTemperature: txtAirTemperature.value
    property alias txtAltitudeFromRadarAltimeter: txtAltitudeFromRadarAltimeter.value
    property alias txtAltitudeFromPayloadAltimeter: txtAltitudeFromPayloadAltimeter.value
    property alias txtLinearVelocityHorizontal: txtLinearVelocityHorizontal.value

    property alias txtLinearVelocityVertical: txtLinearVelocityVertical.value
    property alias txtPositionAccuracy: txtPositionAccuracy.value
    property alias txtSpeedAccuracy: txtSpeedAccuracy.value
    property alias txtLinearAccelerationX: txtLinearAccelerationX.value
    property alias txtLinearAccelerationY: txtLinearAccelerationY.value
    property alias txtLinearAccelerationZ: txtLinearAccelerationZ.value

    property alias txtECEFVectorPositionX: txtECEFVectorPositionX.value
    property alias txtECEFVectorPositionY: txtECEFVectorPositionY.value
    property alias txtECEFVectorPositionZ: txtECEFVectorPositionZ.value
    property alias txtECEFVectorVelocityX: txtECEFVectorVelocityX.value
    property alias txtECEFVectorVelocityY: txtECEFVectorVelocityY.value
    property alias txtECEFVectorVelocityZ: txtECEFVectorVelocityZ.value

    property alias txtRollAngle: txtRollAngle.value
    property alias txtPitchAngle: txtPitchAngle.value
    property alias txtYawAngle: txtYawAngle.value
    property alias txtAngularRateRoll: txtAngularRateRoll.value
    property alias txtAngularRatePitch: txtAngularRatePitch.value
    property alias txtAngularRateYaw: txtAngularRateYaw.value

    property alias txtNumberOfGPSSatellite: txtNumberOfGPSSatellite.value

    property alias txtAnemCommErrorCounter: txtAnemCommErrorCounter.value
    property alias txtRDAltCommErrorCounter: txtRDAltCommErrorCounter.value
    property alias txtGNSSCommErrorCounter: txtGNSSCommErrorCounter.value
    property alias txtPLAltCommErrorCounter: txtPLAltCommErrorCounter.value

    property alias telemetryLight0: telemetryLight0
    property alias telemetryLight31: telemetryLight31
    property alias telemetryLight30: telemetryLight30
    property alias telemetryLight29: telemetryLight29
    property alias telemetryLight28: telemetryLight28
    property alias telemetryLight27: telemetryLight27
    property alias telemetryLight26: telemetryLight26
    property alias telemetryLight25: telemetryLight25
    property alias telemetryLight24: telemetryLight24
    property alias telemetryLight23: telemetryLight23
    property alias telemetryLight22: telemetryLight22
    property alias telemetryLight21: telemetryLight21
    property alias telemetryLight20: telemetryLight20
    property alias telemetryLight19: telemetryLight19
    property alias telemetryLight18: telemetryLight18
    property alias telemetryLight17: telemetryLight17
    property alias telemetryLight16: telemetryLight16
    property alias telemetryLight15: telemetryLight15
    property alias telemetryLight14: telemetryLight14
    property alias telemetryLight13: telemetryLight13
    property alias telemetryLight12: telemetryLight12
    property alias telemetryLight11: telemetryLight11
    property alias telemetryLight10: telemetryLight10
    property alias telemetryLight9: telemetryLight9
    property alias telemetryLight8: telemetryLight8
    property alias telemetryLight7: telemetryLight7
    property alias telemetryLight6: telemetryLight6
    property alias telemetryLight5: telemetryLight5
    property alias telemetryLight4: telemetryLight4
    property alias telemetryLight3: telemetryLight3
    property alias telemetryLight2: telemetryLight2
    property alias telemetryLight1: telemetryLight1

Column{
    anchors.fill:parent
    spacing:16
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

            }
        }
    GridLayout {
        //anchors.fill:parent
        width:parent.width
        height: childrenRect.height

        rowSpacing: 24 //32
        columnSpacing: 40 //48
        columns: 4
        rows: 2
        //48
        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            //Layout.alignment: Qt.AlignRight
            spacing: 8

            ParamGrp2Label {
                text: "Coordinates (°)"
            }

            ParamRow {
                id: txtLatitude
                text: "Latitude"
                span: 4
                ToolTip.text: text
                ToolTip.visible: pressed
            }

            ParamRow {
                text: "Longitude"
                span: 4
                id: txtLongitude
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Altitude"
                span: 4
                id: txtGNSSAltitude
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }

        Column {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            spacing: 8
            ParamGrp2Label {
                text: "ECEF Position (°)"
            }

            ParamRow {
                text: "X"
                id: txtECEFVectorPositionX
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Y"
                id: txtECEFVectorPositionY
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Z"
                id: txtECEFVectorPositionZ
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }
        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop

            ParamGrp2Label {

                text: "ECEF Velocity (m/s)"
            }

            ParamRow {
                text: "X"
                id: txtECEFVectorVelocityX
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Y"
                id: txtECEFVectorVelocityY
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Z"
                id: txtECEFVectorVelocityZ
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }

        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop

            ParamGrp2Label {
                text: "Linear Velocity (m/s)"
            }

            ParamRow {
                text: "Horizontal"
                span: 4
                id: txtLinearVelocityHorizontal
                ToolTip.text: text
                ToolTip.visible: pressed
            }

            ParamRow {
                text: "Vertical"
                span: 4
                id: txtLinearVelocityVertical
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }
ParamsDrawer{
    columnTitle: "Accuracy"
    width: 180
    height: open ? 96 : 24
    Layout.alignment: Qt.AlignTop

    open:true
}

//        Column {
//            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
//            spacing: 8

//            ParamGrp2Label {
//                text: "Accuracy"
//            }

//            ParamRow {
//                text: "Position"
//                span: 7
//                id: txtPositionAccuracy
//                ToolTip.text: text
//                ToolTip.visible: pressed
//            }

//            ParamRow {
//                text: "Speed"
//                span: 7
//                id: txtSpeedAccuracy
//                ToolTip.text: text
//                ToolTip.visible: pressed
//            }

//            ParamRow {
//                text: "# GNSS satellites"
//                span: 7
//                id: txtNumberOfGPSSatellite
//                ToolTip.text: text
//                ToolTip.visible: pressed
//            }
//        }

        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop
            ParamGrp2Label {
                text: "Angle (°)"
            }

            ParamRow {
                text: "Roll"
                span: 2
                id: txtRollAngle
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Pitch"
                span: 2
                id: txtPitchAngle
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Yaw"
                span: 2
                id: txtYawAngle
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }

        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop

            ParamGrp2Label {
                text: "Angular Rate"
            }

            ParamRow {
                text: "Roll"
                span: 2
                id: txtAngularRateRoll
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Pitch"
                span: 2
                id: txtAngularRatePitch
                ToolTip.text: text
                ToolTip.visible: pressed
            }

            ParamRow {
                text: "Yaw"
                span: 2
                id: txtAngularRateYaw
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }
        Column {
            spacing: 8
            Layout.alignment: Qt.AlignTop

            ParamGrp2Label {
                text: "Linear Acceleration (m/s²)"
            }

            ParamRow {
                text: "X"
                id: txtLinearAccelerationX
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Y"
                id: txtLinearAccelerationY
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Z"
                id: txtLinearAccelerationZ
                ToolTip.text: text
                ToolTip.visible: pressed
            }
        }
    }

//    Row {
    Rectangle {
        width: parent.width
        height: 1
        color: "#d9d9d9"

    }
    RowLayout{
        spacing: 32
    Column {
        spacing: 8
        height: childrenRect.height
        width: parent.width
        Row {
            spacing: 8
            Image {
                x: 3
                y: 0
                source: "images/svgs/solid/wind.svg"
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 24
                sourceSize.width: 24
            }
            ParamGrp1Label {
                text: "Anemometer"
            }
        }

            ParamRow {
                text: "Air Speed U"
                span: 5
                id: txtAirSpeed_UVector
                ToolTip.text: text
                ToolTip.visible: pressed
            }

            ParamRow {
                text: "Air Speed V"
                span: 5
                id: txtAirSpeed_VVector
                ToolTip.text: text
                ToolTip.visible: pressed
            }
            ParamRow {
                text: "Air Speed W"
                span: 5
                id: txtAirSpeed_WVector
                ToolTip.text: text
                ToolTip.visible: pressed
            }

            ParamRow {
                text: "Air Temp."
                span: 5
                id: txtAirTemperature
                ToolTip.text: text
                ToolTip.visible: pressed
            }

    }
//    Item {
//        width: 24
//        height: 1
//    }
    Column{
        spacing:8
        Layout.alignment: Qt.AlignTop
    Row {

            spacing: 8
            Image {
                x: 3
                y: 0
                source: "images/svgs/solid/satellite-dish.svg"
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 24
                sourceSize.width: 24
            }
            ParamGrp1Label {
                text: "Radar"

            }
        }

        ParamRow {
            text: "Altitude"

            span: 3
            id: txtAltitudeFromRadarAltimeter
            ToolTip.text: text
            ToolTip.visible: pressed
        }
}


        Column {
            Layout.alignment: Qt.AlignTop

            spacing: 8
            Row{
                spacing:8
            Image {

                source: "images/svgs/solid/weight-hanging.svg"
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 24
                sourceSize.width: 24
            }

            ParamGrp1Label {
                text: "Payload"

            }
            }


        ParamRow {
            text: "Altitude"
            span: 3
            id: txtAltitudeFromPayloadAltimeter
            ToolTip.text: text
            ToolTip.visible: pressed
        }
        }
    }
    //}

Rectangle {
    id: rectangle
    width: parent.width
    height: 1
    color: "#d9d9d9"

}

//Row {
//    Layout.fillWidth: true
//    Layout.preferredHeight: childrenRect.height + 10
    Row {
        spacing: 8
        Image {

            width: 24
            source: "images/svgs/solid/triangle-exclamation.svg"
            fillMode: Image.PreserveAspectFit
            sourceSize.height: 24
            sourceSize.width: 24
        }

        ParamGrp1Label {
            text: "Telemetry status"


        }
    }
    Grid {
        id: grid
        columnSpacing: 16
        rowSpacing: 12
        flow: Grid.TopToBottom
        columns: 6
        rows: 7
        StatusLight {
            id: telemetryLight0
            text: "Anemom NOT present"
        }

        StatusLight {
            id: telemetryLight1
            text: "RD Altimeter NOT present"
        }

        StatusLight {
            id: telemetryLight2
            text: "GNSS NOT present"
        }

        StatusLight {
            id: telemetryLight3
            text: "PL Altimeter NOT present"
        }
        StatusLight {
            id: telemetryLight4
            text: "Anemom TO"
        }

        StatusLight {
            id: telemetryLight5
            text: "Anemom CS"
        }
        StatusLight {
            id: telemetryLight6
            text: "RD Altimeter TO"
        }

        StatusLight {
            id: telemetryLight7
            text: "RD Altimeter CS"
        }
        StatusLight {
            id: telemetryLight8
            text: "GNSS pack1 TO"
        }

        StatusLight {
            id: telemetryLight9
            text: "GNSS pack1 CS"
        }
        StatusLight {
            id: telemetryLight10
            text: "GNSS pack2 TO"
        }

        StatusLight {
            id: telemetryLight11
            text: "GNSS pack2 CS"
        }

        StatusLight {
            id: telemetryLight12
            text: "GNSS pack3 TO"
        }

        StatusLight {
            id: telemetryLight13
            text: "GNSS pack3 CS"
        }
        StatusLight {
            id: telemetryLight14
            text: "PL Altimeter TO"
        }

        StatusLight {
            id: telemetryLight15
            text: "RS232 HW failure"
        }
        StatusLight {
            id: telemetryLight16
            text: "RS422 HW failure"
        }

        StatusLight {
            id: telemetryLight17
            text: "CAN HW failure"
        }
        StatusLight {
            id: telemetryLight18
            text: "GNSS_time NOT valid"
        }

        StatusLight {
            id: telemetryLight19
            text: "GNSS_pos NOT valid"
        }
        StatusLight {
            id: telemetryLight20
            text: "Anem_speed NOT valid"
        }

        StatusLight {
            id: telemetryLight21
            text: "Anem_temp NOT valid"
        }

        StatusLight {
            id: telemetryLight22
            text: "RD_altitude NOT valid"
        }

        StatusLight {
            id: telemetryLight23
            text: "PL_altitude NOT valid"
        }
        StatusLight {
            id: telemetryLight24
            text: "GNSS_vel NOT valid"
        }

        StatusLight {
            id: telemetryLight25
            text: "GNSS_acc NOT valid"
        }
        StatusLight {
            id: telemetryLight26
            text: "GNSS_ECEFpos NOT valid"
        }

        StatusLight {
            id: telemetryLight27
            text: "GNSS_ECEFvel NOT valid"
        }
        StatusLight {
            id: telemetryLight28
            text: "GNSS_angle NOT valid"
        }

        StatusLight {
            id: telemetryLight29
            text: "GNSS_angRate NOT valid"
        }
        StatusLight {
            id: telemetryLight30
            text: "GNSS_quat NOT valid"
        }

        StatusLight {
            id: telemetryLight31
            text: "GNSS_fix done"
        }
        Item {
            height: 1
            width: 1
        }
        Item {
            height: 1
            width: 1
        }
        Item {
            height: 1
            width: 1
        }

        ParamRow {
            id: txtAnemCommErrorCounter
            text: "Anemometer Comm error counter"
            span: 12
            ToolTip.text: text
            ToolTip.visible: pressed
        }
        ParamRow {
            id: txtRDAltCommErrorCounter
            text: "RD Altimeter Comm error counter"
            span: 12
            ToolTip.text: text
            ToolTip.visible: pressed
        }
        ParamRow {
            id: txtGNSSCommErrorCounter
            text: "GNSS Comm error counter"
            span: 12
            ToolTip.text: text
            ToolTip.visible: pressed
        }
        ParamRow {
            id: txtPLAltCommErrorCounter
            text: "PL Altimeter Comm error counter"
            span: 12
            ToolTip.text: text
            ToolTip.visible: pressed
        //}
    }
}
}
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3}D{i:4}D{i:2}D{i:7}D{i:8}D{i:9}D{i:10}
D{i:6}D{i:12}D{i:13}D{i:14}D{i:15}D{i:11}D{i:17}D{i:18}D{i:19}D{i:20}D{i:16}D{i:22}
D{i:23}D{i:24}D{i:21}D{i:25}D{i:27}D{i:28}D{i:29}D{i:30}D{i:26}D{i:32}D{i:33}D{i:34}
D{i:35}D{i:31}D{i:37}D{i:38}D{i:39}D{i:40}D{i:36}D{i:5}D{i:41}D{i:45}D{i:46}D{i:44}
D{i:47}D{i:48}D{i:49}D{i:50}D{i:43}D{i:53}D{i:54}D{i:52}D{i:55}D{i:51}D{i:58}D{i:59}
D{i:57}D{i:60}D{i:56}D{i:42}D{i:61}D{i:63}D{i:64}D{i:62}D{i:66}D{i:67}D{i:68}D{i:69}
D{i:70}D{i:71}D{i:72}D{i:73}D{i:74}D{i:75}D{i:76}D{i:77}D{i:78}D{i:79}D{i:80}D{i:81}
D{i:82}D{i:83}D{i:84}D{i:85}D{i:86}D{i:87}D{i:88}D{i:89}D{i:90}D{i:91}D{i:92}D{i:93}
D{i:94}D{i:95}D{i:96}D{i:97}D{i:98}D{i:99}D{i:100}D{i:101}D{i:102}D{i:103}D{i:104}
D{i:65}D{i:1}
}
##^##*/
