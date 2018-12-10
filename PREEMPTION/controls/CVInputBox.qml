import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4

Item {
    property alias value: slider.value
    property alias maxValue: slider.maximumValue

    function show() {
        dialog.open();
    }

    id: inputBox
    objectName: "inputBox"
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
                width: 200
                height: 40
                color: "white"
                font.pixelSize: 20
                text: "Num to send: "+slider.value.toString()
                anchors.left: parent.horizontalCenter
                anchors.leftMargin: -width/2
                anchors.top: parent.top
                anchors.topMargin: 30
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            Slider {
                id: slider
                anchors.centerIn: parent
                width: parent.width*0.35
                scale: 2
                stepSize: 1
            }

            Button {
                id: btnDiscard
                width: 60
                height: 30
                text: "DISCARD"
                anchors.right: parent.right
                anchors.rightMargin: width
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                onClicked: {
                    dialog.close();
                    gameCanvas.qmlSignal_inputBox_discard();
                }
            }

            Button {
                id: btnAccept
                width: 60
                height: 30
                text: "ACCEPT"
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                onClicked: {
                    dialog.close();
                    gameCanvas.qmlSignal_inputBox_accept();
                }
            }
        }
}
