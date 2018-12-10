import QtQuick 2.9
import QtQuick.Window 2.2
import "controls"
import "pages"

Window {  
    objectName: "mainWindow"
    visible: true
    width: 1100
    height: 650
    x: Screen.width / 2 - width / 2
    y: Screen.height / 2 - height / 2

    Loader {
        id: scene
        objectName: "scene"
        anchors.fill: parent
        source: "qrc:/pages/GameCanvas.qml"
    }
}
