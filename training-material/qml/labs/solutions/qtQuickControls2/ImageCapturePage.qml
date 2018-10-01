import QtQuick 2.8
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            Item { Layout.fillWidth: true }
            ToolButton {
                text: qsTr("Back")
                onClicked: {
                    onClicked: pageStack.pop()
                }
            }
        }
    }

    Component.onCompleted: console.log("ImageCapturePage created")
    Component.onDestruction: console.log("ImageCapturePage destructed")
}
