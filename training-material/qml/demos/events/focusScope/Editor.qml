import QtQuick 2.4

Rectangle {
    property alias text: editor.text

    TextInput {
        id: editor
        anchors.centerIn: parent
        focus: true
    }
}

