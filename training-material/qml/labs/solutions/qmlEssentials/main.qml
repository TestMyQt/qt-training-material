import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Image App")

    Rectangle {
        id: rect
        anchors.fill: parent
        property alias someName: textField.text

        function show(notificationText) {
            textField.text = notificationText;
        }

        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#000000";
            }
            GradientStop {
                position: 1.00;
                color: "#b9b3b3";
            }
        }

        Text {
            id: textField
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Hello world")
            width: parent.width
            height: parent.height
            fontSizeMode: Text.Fit
            minimumPixelSize: 10
            font.pixelSize: 108
            wrapMode: Text.WordWrap
            color: "white"
        }
    }
}
