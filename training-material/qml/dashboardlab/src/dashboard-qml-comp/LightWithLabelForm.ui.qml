import QtQuick 2.7
import QtQuick.Extras 1.4

Rectangle {
    id: item1
    width: 300
    height: 300
    color: "black"
    border.color: "lightgrey"
    border.width: 2
    radius: 2
    property alias text1Color: text1.color
    property alias pictureColor: picture.color
    property alias pictureSource: picture.source
    property alias text1Text: text1.text

    Column {
        id: column
        anchors.left: column1.right
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        spacing: 4

        Text {
            id: text1
            width: parent.width
            color: "lightgrey"
            text: qsTr("Text")
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        Picture {
            id: picture
            width: parent.width
            color: "lightgrey"
            source: "qrc:/iso-icons/iso_grs_7000_4_0245.dat"
        }
    }

    Column {
        id: column1
        width: parent.width * 0.6
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Gauge {
            id: gauge
        }

        Gauge {
            id: gauge1
        }
    }
}
