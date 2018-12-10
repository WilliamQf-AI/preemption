import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4

Item {
    property alias text: txt.text

    function show() {
        dialog.open();
    }

    id: msgbox
    objectName: "msgbox"
    visible: false
    width: 400
    height: 200
    anchors.centerIn: parent

    Popup {
            id: dialog
            width: parent.width
            height: parent.height
            modal: true
            focus: true
            closePolicy: Popup.CloseOnPressOutside

            background: Rectangle {
                color: "#CC000000"
            }

            Text {
                id: txt
                anchors.fill: parent
                color: "white"
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
}
