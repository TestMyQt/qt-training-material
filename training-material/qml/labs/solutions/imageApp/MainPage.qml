import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

Item {
    property var webViewPage

    ToolBar {
        id: bottomToolbar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: scale * bottomMargin
        width: parent.width
        scale: (Qt.platform.os === "android" || Qt.platform.os === "ios") ? 2.0 : 1.0
        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: columnSpacing

            // Page 1 - ImageViewPage
            ToolButton {
                id: toolBtn1
                iconSource: "qrc:/images/image.png"
                onClicked: {
                    pageStack.push({item: "qrc:/ImageViewPage.qml"});
                    if (animation.running) {
                        animation.stop();
                    }
                    else {
                        animation.start();
                    }
                }
            }

            // Page 2 - WebViewPage
            ToolButton {
                iconSource: "qrc:/images/cloud.png"
                onClicked: {
                    if (!(Qt.platform.os === "windows")) {
                        pageStack.push({item: webViewPage});
                    }
                    else {
                        console.log("Disabled for Windows (mingw would be enough)")
                    }
                }
            }
            // Page 3 - Add images to the C++ model with the file dialog
            ToolButton {
                iconSource: "qrc:/images/download.png"
                onClicked: {
                    fileDialog.open();
                }
            }
            // Page 4 - Capture images with the camera
            ToolButton {
                iconSource: "qrc:/images/camera.png"
                onClicked: {
                    pageStack.push({item: "qrc:/ImageCapturePage.qml"});
                }
            }
        }
        style: ToolBarStyle {
            background: Item {
            }
        }
    }
    PropertyAnimation {
        id: animation
        target: toolBtn1
        property: "rotation"
        easing.amplitude: 2
        easing.type: Easing.OutInElastic
        from: 0
        to: 3600
        duration: 10000
    }

    Component.onCompleted: {
        if (!(Qt.platform.os === "windows")) {
            var component = Qt.createComponent("qrc:/WebViewPage.qml");
            var incubator = component.incubateObject();
            if (incubator.status !== Component.Ready) {
                incubator.onStatusChanged = function(status) {
                    if (status === Component.Ready) {
                        webViewPage = incubator.object;
                    }
                }
            } else {
                webViewPage = incubator.object;
            }
        }
    }

    FileDialog {
         id: fileDialog
         title: "Please choose image files"
         folder: shortcuts.home
         onAccepted: {
             for (var i = 0; i < fileUrls.length; ++i) {
                 imageModel.addImage(fileUrls[i]);
             }
             notification.show(qsTr("Images added to the model"));
         }
     }

    NotificationMessage {
        id: notification
        anchors.centerIn: parent
        width: parent.width * 0.5
        height: parent.height * 0.5
    }
}
