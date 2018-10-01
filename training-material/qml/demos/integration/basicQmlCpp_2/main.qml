import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    width: 640
    height: 480
    visible: true

    Rectangle {
        objectName: "rectangle"
        width: 200; height: 100
        color: myBackgroundColor

        function toggleText() {
            // Toggle the text field visibility. Notice that this could be
            // done without actually using a function by simply directly
            // manipulating the property from C++ - a funtion is used purely
            // for demonstration purposes!
            textField.visible = !textField.visible;
        }

        Text {
            id: textField
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
