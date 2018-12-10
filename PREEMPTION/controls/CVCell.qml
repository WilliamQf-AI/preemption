import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import customitems 1.0

Item {
    property color maskColor: "transparent"
    property int num: 0
    property int hex_x: 0
    property int hex_y: 0
    property real rect_x: 0
    property real rect_y: 0

    onHex_xChanged: {
        console.log("onHex_xChanged");
        gameCanvas.qmlSignal_cell_onPositionChange(root);
    }
    onHex_yChanged: {
        console.log("onHex_yChanged");
        gameCanvas.qmlSignal_cell_onPositionChange(root);
    }

    onXChanged: {
        console.log("onXChanged");
    }

    onYChanged: {
        console.log("onYChanged");
    }

    id: root
    objectName: "Cell"
    width: 100
    height: 100
    x: rect_x+gameCanvas.offsetX
    y: rect_y+gameCanvas.offsetY

    Image {
        id: img
        z: -1
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "../images/cell.png"

        Component.onCompleted: {
            mouseArea.maskSource=img.source;
        }
    }

    MaskedMouseArea {
        id: mouseArea
        y: 7
        width: img.width
        height: img.height
        alphaThreshold: 0.4

        onClicked: {
            gameCanvas.qmlSignal_cell_onClick(hex_x,hex_y);
        }
    }

    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
        text: num.toString()
        z: 1
        font.pointSize: 20
        visible: num!=0
    }

    ColorOverlay {
        id: overlay
        anchors.fill: img
        source: img
        color: maskColor

        opacity: mouseArea.containsMouse ? 0.7 : 0.8
        Behavior on opacity {
            NumberAnimation { duration: 50 }
        }
    }

    CVArrow {id: arrow0; objectName: "arrow0"; x: 27; y: -11; z: 2; direction: 0; num: 0}
    CVArrow {id: arrow1; objectName: "arrow1"; x: 74; y: 15; z: 2; direction: 1; num: 0}
    CVArrow {id: arrow2; objectName: "arrow2"; x: 75; y: 71; z: 2; direction: 2; num: 0}
    CVArrow {id: arrow3; objectName: "arrow3"; x: 29; y: 97; z: 2; direction: 3; num: 0}
    CVArrow {id: arrow4; objectName: "arrow4"; x: -19; y: 70; z: 2; direction: 4; num: 0}
    CVArrow {id: arrow5; objectName: "arrow5"; x: -19; y: 16; z: 2; direction: 5; num: 0}
}
