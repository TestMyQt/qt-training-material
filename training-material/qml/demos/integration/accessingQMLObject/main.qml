import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Accessing QML from C++")

    Rectangle {
        objectName: "blueRect"
        width: parent.width
        height: parent.height
        color: "lightblue"
        Text {
            anchors.centerIn: parent
            font.pixelSize: 24
            text: qsTr("QML accessed from C++");
        }
    }
}
