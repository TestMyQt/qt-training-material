import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    color: "green"
    //color: "#008000"
    //color: Qt.rgba(0,0.5,0,1)
    width: 640
    height: 480
    title: qsTr("Hello World")

    //flags: Qt.FramelessWindowHint
    MainForm {
        //visible: false
        //opacity: 0.7
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
        mouseArea.onDoubleClicked: {
            console.log("Double clicked. Quitting now..")
            Qt.quit();
        }
    }
}
