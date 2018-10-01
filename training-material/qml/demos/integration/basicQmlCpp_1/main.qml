import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    width: 640
    height: 480
    visible: true

Rectangle {
        width: 200; height: 100
        color: myBackgroundColor
        Text {
            anchors.centerIn: parent
            font.pixelSize: 18
            text: myText
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                application.quit();
            }
        }
    }
}



