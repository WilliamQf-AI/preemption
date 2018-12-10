import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Rectangle {
    property int num: 0
    property int direction: 0
    property var arrow_dir: [0,60,120,180,240,300]
    property var txt_dir: [0,60,-60,0,60,-60]

    visible: false

    id: root
    width: 45
    height: 15
    color: "transparent"
    rotation: arrow_dir[direction]

    Text {
        id: txt
        anchors.centerIn: parent
        font.pointSize: 10
        color: "white"
        z: 3
        rotation: txt_dir[direction]-arrow_dir[direction]
        text: num.toString()
        visible: num!=0
    }

    Image {
        id: img
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "../images/arrow.png"
    }

    ColorOverlay {
        id: overlay
        color: num!=0?"#105306":"#EFEFEF";
        z: 2
        anchors.fill: img
        source: img
    }

    Glow {
        visible: mouseArea.containsMouse
        anchors.fill: img
        color: "#FFFFFF"
        source: img
        radius: 8
        spread: 0.2
        samples: 16
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            gameCanvas.qmlSignal_arrow_onClick(hex_x,hex_y,direction);
        }
    }
}
