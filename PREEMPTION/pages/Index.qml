import QtQuick 2.9
import QtQuick.Window 2.2

Item {
    //signal qmlSignal_btnStart_onClick();

    id: index
    width: 100
    height: 100
    Rectangle{
        width: 100
        height: 100
        color: "red"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                //qmlSignal_btnStart_onClick();
                scene.source="qrc:/pages/GameCanvas.qml"
            }
        }
    }
}
