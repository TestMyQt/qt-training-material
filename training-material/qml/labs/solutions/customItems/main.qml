import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Image App")

    NotificationMessage {
        anchors.centerIn: parent
        width: 200
        height: 150

        onRandomSignal: {
            console.log(note);
        }

        Component.onCompleted: show(qsTr("Notification"));
    }
}
