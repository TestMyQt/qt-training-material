import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtMultimedia 5.5

Item {
    Camera {
        id: camera

        imageCapture {
            onImageCaptured: {
                imageModel.addImage(preview);
                notification.show(qsTr("Image captured and added to the model"));
            }
        }
    }

    VideoOutput {
        source: camera
        anchors.fill: parent
        focus : visible
    }

    NotificationMessage {
        id: notification
        anchors.centerIn: parent
        width: parent.width * 0.5
        height: parent.height * 0.5
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
                iconSource: "qrc:/images/camera.png"
                onClicked: {
                    camera.imageCapture.capture();
                }
            }

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
