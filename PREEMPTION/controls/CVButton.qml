import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Rectangle {
    property int diameter: 60
    property alias bgColor: root.color
    property alias foreColor: overlay.color
    property alias imgSource: img.source

    id: root
    width: diameter
    height: diameter
    radius: 10
    clip: true
    scale: mouseArea.containsMouse ? 0.9 : 1
    Behavior on scale {
        NumberAnimation {
            duration: 50
        }
    }

    Image {
        id: img
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit

    }

    ColorOverlay {
        id: overlay
        anchors.fill: img
        source: img
    }
}
