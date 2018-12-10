import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import "../controls"

Rectangle {
    property bool active: true
    property int offsetX: 0
    property int offsetY: 0
    property var cvcell:Qt.createComponent("qrc:/controls/CVCell.qml");

    signal qmlSignal_gameCanvas_onCompleted(var sender);
    signal qmlSignal_gameCanvas_onDestroyed();
    signal qmlSignal_inputBox_discard();
    signal qmlSignal_inputBox_accept();
    signal qmlSignal_cell_onClick(int x,int y);
    signal qmlSignal_cell_onMouseLeave(int x,int y);
    signal qmlSignal_arrow_onClick(int x,int y,int dir);
    signal qmlSignal_btnRun_onClick();
    signal qmlSignal_cell_onPositionChange(var sender);

    function createCell(_x,_y,_maskColor,_num){
        console.log("createCell");
        var cell= cvcell.createObject(gameCanvas,{
                              "z":0,
                              "hex_x":_x,
                              "hex_y":_y,
                              "maskColor":_maskColor,
                              "num":_num});

        return cell;
    }

    Component.onCompleted: {
        qmlSignal_gameCanvas_onCompleted(gameCanvas);
        //visible=true;
    }

//    Component.onDestroyed: {
//        qmlSignal_gameCanvas_onDestroyed();
//    }

    id: gameCanvas
    objectName: "gameCanvas"   
    anchors.fill: parent
    color: "#00000000"
    //visible: false

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.Stretch
        z: -1
        source: "../images/bg.jpg"
    }

    CVButton {
        id: btnRun
        objectName: "btnRun"
        bgColor: "#e7ae78"
        foreColor: "#22f022"
        imgSource: "../images/run.png"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                gameCanvas.qmlSignal_btnRun_onClick();
            }
        }
    }

    Rectangle {
        color:"transparent"
        z: 2
        visible: !active
        anchors.fill: parent
        MouseArea {
            anchors.fill: parent
        }
    }

    CVInputBox {}
    CVMessageBox {}
}
