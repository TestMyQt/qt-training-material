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
                    console.log("Back");
                    onClicked: pageStack.pop()
                }
            }
        }
    }

    Component.onCompleted: console.log("Page created")
    Component.onDestruction: console.log("Page destructed")
}
