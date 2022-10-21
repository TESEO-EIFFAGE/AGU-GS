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

    property alias txtFreeDataStorageSize: txtFreeDataStorageSize.value
    property alias txtStorageMsgCounter: txtStorageMsgCounter.value
    property alias storageLight23: storageLight23
    property alias storageLight22: storageLight22
    property alias storageLight21: storageLight21
    property alias storageLight20: storageLight20
    property alias storageLight19: storageLight19
    property alias storageLight18: storageLight18
    property alias storageLight17: storageLight17
    property alias storageLight16: storageLight16
    property alias storageLight15: storageLight15
    property alias storageLight14: storageLight14
    property alias storageLight13: storageLight13
    property alias storageLight12: storageLight12
    property alias storageLight11: storageLight11
    property alias storageLight10: storageLight10
    property alias storageLight9: storageLight9
    property alias storageLight8: storageLight8
    property alias storageLight7: storageLight7
    property alias storageLight6: storageLight6
    property alias storageLight5: storageLight5
    property alias storageLight4: storageLight4
    property alias storageLight3: storageLight3
    property alias storageLight2: storageLight2
    property alias storageLight1: storageLight1
    property alias storageLight0: storageLight0


    property alias storageDrawer: storageStatusDrawer
    //    property alias storageLight23: storageLight23
    //    property alias storageLight22: storageLight22
    //    property alias storageLight21: storageLight21
    //    property alias storageLight20: storageLight20
    //    property alias storageLight19: storageLight19
    //    property alias storageLight18: storageLight18
    //    property alias storageLight17: storageLight17
    //    property alias storageLight16: storageLight16
    //    property alias storageLight15: storageLight15
    //    property alias storageLight14: storageLight14
    //    property alias storageLight13: storageLight13
    //    property alias storageLight12: storageLight12
    //    property alias storageLight11: storageLight11
    //    property alias storageLight10: storageLight10
    //    property alias storageLight8: storageLight8
    //    property alias storageLight7: storageLight7
    //    property alias storageLight6: storageLight6
    //    property alias storageLight5: storageLight5
    //    property alias storageLight4: storageLight4
    //    property alias storageLight3: storageLight3
    //    property alias storageLight2: storageLight2
    //    property alias storageLight1: storageLight1
    //    property alias storageLight0: storageLight0
    Flow {
        anchors.fill:parent
        id: gridStorage
        spacing: 16
//        rowSpacing: 12
        //flow: Grid.TopToBottom
//        columns: 1
//        rows: 6
        LightsDrawer{
            id:storageStatusDrawer
            width:parent.width
            columnTitle.text: "Storage Status"
            open:true


            light24.visible: false
            light25.visible: false
            light26.visible: false
            light27.visible: false
            light28.visible: false
            light29.visible: false
            light30.visible: false
            light31.visible: false

            light0.text: "uSD HW failure"
            light1.text: "uSD not present error"
            light2.text: "uSD full"
            light3.text: "System Status log write error"
            light4.text: "Telemetry module log write error"
            light5.text: "Storage module log write error"
            light6.text: "Radio link module log write error"
            light7.text: "Motor control log write error"
            light8.text: "Guidance module log write error"
            light9.text: "Config file not loaded"
            light10.text: "PGNC initialization verification error"
            light11.text: "PGNC initialization storage error"
            light12.text: "PGNC flight path verification error"
            light13.text: "PGNC flight path storage error"
            light14.text: "Trim script verification error"
            light15.text: "Trim script storage error"
            light16.text: "Open-Loop script verification error"
            light17.text: "Open-Loop script storage error"
            light18.text: "Recovery-A script verification error"
            light19.text: "Recovery-A script storage error"
            light20.text: "Recovery-B script verification error"
            light21.text: "Recovery-B script storage error"
            light22.text: "Flare script verification error"
            light23.text: "Flare script storage error"


        }

        ParamRow{

            id: txtFreeDataStorageSize

            text: "Free Data Size"
            span: 6
            ToolTip.text: text
            ToolTip.visible: pressed
        ParamRow{
            text: "N. Storage Msg"
            span: 6
            id: txtStorageMsgCounter
            ToolTip.text: text
            ToolTip.visible: pressed
        }
        //        StatusLight {
        //            id: storageLight0
        //            text: "uSD HW failure"
        //        }

        //        StatusLight {
        //            id: storageLight1
        //            text: "uSD not present error"
        //        }

        //        StatusLight {
        //            id: storageLight2
        //            text: "uSD full"
        //        }

        //        StatusLight {
        //            id: storageLight3
        //            text: "System Status log write error"
        //        }
        //        StatusLight {
        //            id: storageLight4
        //            text: "Telemetry module log write error"
        //        }

        //        StatusLight {
        //            id: storageLight5
        //            text: "Storage module log write error"
        //        }
        //        StatusLight {
        //            id: storageLight6
        //            text: "Radio link module log write error"
        //        }

        //        StatusLight {
        //            id: storageLight7
        //            text: "Motor control log write error"
        //        }
        //        StatusLight {
        //            id: storageLight8
        //            text: "Guidance module log write error"
        //        }

        //        StatusLight {
        //            id: storageLight10
        //            text: "PGNC initialization verification error"
        //        }

        //        StatusLight {
        //            id: storageLight11
        //            text: "PGNC initialization storage error"
        //        }

        //        StatusLight {
        //            id: storageLight12
        //            text: "PGNC flight path verification error"
        //        }

        //        StatusLight {
        //            id: storageLight13
        //            text: "PGNC flight path storage error"
        //        }
        //        StatusLight {
        //            id: storageLight14
        //            text: "Trim script verification error"
        //        }

        //        StatusLight {
        //            id: storageLight15
        //            text: "Trim script storage error"
        //        }
        //        StatusLight {
        //            id: storageLight16
        //            text: "Open-Loop script verification error"
        //        }

        //        StatusLight {
        //            id: storageLight17
        //            text: "Open-Loop script storage error"
        //        }
        //        StatusLight {
        //            id: storageLight18
        //            text: "Recovery-A script verification error"
        //        }

        //        StatusLight {
        //            id: storageLight19
        //            text: "Recovery-A script storage error"
        //        }
        //        StatusLight {
        //            id: storageLight20
        //            text: "Recovery-B script verification error"
        //        }

        //        StatusLight {
        //            id: storageLight21
        //            text: "Recovery-B script storage error"
        //        }

        //        StatusLight {
        //            id: storageLight22
        //            text: "Flare script verification error"
        //        }

        //        StatusLight {
        //            id: storageLight23
        //            text: "Flare script storage error"
        //        }

    }
}
}




/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
