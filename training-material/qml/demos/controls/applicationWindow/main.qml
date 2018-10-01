import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Application Window")
    minimumHeight: 300
    minimumWidth: 330

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    header: Label {
        horizontalAlignment: Text.AlignHCenter
        height: 60
        font.pixelSize: 108
        minimumPixelSize: 8
        fontSizeMode: Text.Fit
        text: mainPage.title
        background: Rectangle {
            anchors.fill: parent
            border { width: 2; color: "black" }
            color: "lightgreen"
        }
    }

    footer:
        RowLayout {
        Button {
            text: qsTr("Previous")
            Layout.fillWidth: true
            onClicked: console.log("Previous page")
            font.pixelSize: 24
        }
        Label {
            text: "0"
            font.pixelSize: 24
        }
        Button {
            text: qsTr("Next")
            font.pixelSize: 24
            Layout.fillWidth: true
            onClicked: console.log("Next page")
        }
    }

    Page {
        id: mainPage
        title: qsTr("Header: Page title")
        anchors.fill: parent

        MainPage {
            anchors.fill: parent
        }
    }
}
