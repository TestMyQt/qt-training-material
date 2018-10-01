import QtQuick 2.8
import QtQuick.Controls 2.0

ApplicationWindow {
    property int bottomMargin: 10
    property int columnSpacing: 50

    visible: true
    width: 640
    height: 480
    title: qsTr("Image App")

    StackView {
        id: pageStack
        anchors.fill: parent
        initialItem: "qrc:/MainPage.qml"

        // Page animations
        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 250
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 250
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 250
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 250
            }
        }
    }

    Component {
        id: imageCapturePage
        ImageCapturePage {
            Component.onCompleted: console.log("Stack depth:", pageStack.depth)
        }
    }

    Component {
        id: imageViewPage
        ImageViewPage {
            Component.onCompleted: console.log("Stack depth:", pageStack.depth)
        }
    }

    Component {
        id: webViewPage
        WebViewPage {
            Component.onCompleted: console.log("Stack depth:", pageStack.depth)
        }
    }
}

