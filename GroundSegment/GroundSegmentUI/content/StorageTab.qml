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
    Flow {
        //anchors.fill:parent
        height: childrenRect.height
        width:parent.width
        id: gridStorage
        spacing:16
        //columnSpacing: 16
        //rowSpacing: 12
        //flow: Grid.TopToBottom
        //columns: 4
        //rows: 6

        StatusLight {
            id: storageLight0
            text: "uSD HW failure"
        }

        StatusLight {
            id: storageLight1
            text: "uSD not present err"
        }

        StatusLight {
            id: storageLight2
            text: "uSD full"
        }

        StatusLight {
            id: storageLight3
            text: "System Status log write err"
        }
        StatusLight {
            id: storageLight4
            text: "TLM module log write err"
        }

        StatusLight {
            id: storageLight5
            text: "Storage module log write err"
        }
        StatusLight {
            id: storageLight6
            text: "RL module log write err"
        }

        StatusLight {
            id: storageLight7
            text: "Motor control log write err"
        }
        StatusLight {
            id: storageLight8
            text: "Guidance module log write err"
        }
        StatusLight {
            id: storageLight9
            text: "Config file NOT loaded"
        }
        StatusLight {
            id: storageLight10
            text: "PCNC init verif err"
        }

        StatusLight {
            id: storageLight11
            text: "PCNC init storage err"
        }

        StatusLight {
            id: storageLight12
            text: "PCNC flight path verif err"
        }

        StatusLight {
            id: storageLight13
            text: "PCNC flight path storage err"
        }
        StatusLight {
            id: storageLight14
            text: "Trim script verif err"
        }

        StatusLight {
            id: storageLight15
            text: "Trim script storage err"
        }
        StatusLight {
            id: storageLight16
            text: "Open-Loop script verif err"
        }

        StatusLight {
            id: storageLight17
            text: "Open-Loop script storage err"
        }
        StatusLight {
            id: storageLight18
            text: "Recovery-A script verif err"
        }

        StatusLight {
            id: storageLight19
            text: "Recovery-A script storage err"
        }
        StatusLight {
            id: storageLight20
            text: "Recovery-B script verif err"
        }

        StatusLight {
            id: storageLight21
            text: "Recovery-B script storage err"
        }

        StatusLight {
            id: storageLight22
            text: "Flare script verif err"
        }

        StatusLight {
            id: storageLight23
            text: "Flare script storage err"
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
    }
}



}

