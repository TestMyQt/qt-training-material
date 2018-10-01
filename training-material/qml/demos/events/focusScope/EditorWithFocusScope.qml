import QtQuick 2.4

Rectangle {
    width: 100
    height: 62

    property alias text: editor.text

    TextInput {
        id: editor
        anchors.centerIn: parent
        focus: true
    }
}

/*
FocusScope {
    property alias text: editor.text

    Rectangle {
        id: rectangle
        anchors.fill: parent

        TextInput {
            id: editor
            anchors.centerIn: parent
            focus: true
        }
    }
}
*/
