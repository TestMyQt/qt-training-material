import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

Item {
    Component {
        id: imageDelegate
        Image {
            id: image
            property string fileId: ""
            width: parent.width * 0.1
            height: parent.height * 0.1
            source: model.fileId

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    pageStack.push({item: "qrc:/EffectsPage.qml", properties: {fileId: model.fileId}});
                }
            }
        }
    }

    PathView {
        anchors.top: parent.top
        anchors.bottom: bottomToolbar.top
        width: root.width
        pathItemCount: 60
        model: imageModel
        delegate: imageDelegate
        clip: true
        path: Path {
            startX: parent.width * 0.05
            startY: parent.height * 0.05
            PathLine { x: parent.width  / 2; y: parent.height * 0.85 }
            PathLine { x: parent.width * 0.95 ; y: parent.height *0.05 }
        }
    }

    ToolBar {
        id: bottomToolbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: scale * bottomMargin
        width: parent.width
        scale: (Qt.platform.os === "android" || Qt.platform.os === "ios") ? 2.0 : 1.0

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: columnSpacing
            ToolButton {
                iconSource: "qrc:/images/arrow_left.png"
                onClicked: {
                    pageStack.pop();
                }
            }
        }
        style: ToolBarStyle {
            background: Item {
            }
        }
    }
}

