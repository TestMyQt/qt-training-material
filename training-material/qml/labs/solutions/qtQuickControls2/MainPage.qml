import QtQuick 2.8
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    footer: ToolBar {
        id: bottomToolbar
        RowLayout {
            anchors.fill: parent

            // Page 1 - ImageViewPage
            ToolButton {
                id: toolBtn1
                text: qsTr("Image")
                onClicked: {
                    pageStack.push(imageViewPage)
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
                text: qsTr("Cloud")
                onClicked: {
                    pageStack.push(webViewPage);
                }
            }
            // Page 3 - Add images to the C++ model with the file dialog
            ToolButton {
                text: qsTr("Download")
                onClicked: {
                    console.log("No implementation yet");
                }
            }
            // Page 4 - Capture images with the camera
            ToolButton {
                text: qsTr("Camera")
                onClicked: {
                    pageStack.push(imageCapturePage);
                }
            }
            Item { Layout.fillWidth: true }
            ToolButton {
                text: qsTr("Exit")
                onClicked: {
                    console.log("Exit");
                    Qt.quit();
                }
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

    Component.onCompleted: console.log("MainPage created")
    Component.onDestruction: console.log("MainPage destructed")
}

