import QtQuick 2.3

Rectangle {
    signal customItem1Signal

    MouseArea {
        anchors.fill: parent
        onClicked: customItem1Signal();
    }

}
