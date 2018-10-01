import QtQuick 2.8

Rectangle {
    id: rectangle
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360
    color: "#41cd52"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        text: qsTr("Hello World!")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Rectangle {
        id: myRect
        x: 52
        y: 212
        width: 256
        height: 93
        color: "#245ed2"
        radius: 20
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: 3

        Text {
            id: text1
            x: 78
            y: 39
            width: 100
            height: 15
            text: textEdit.text
            font.pixelSize: 12
        }
    }
}
