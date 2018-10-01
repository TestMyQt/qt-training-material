import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import ImageModule 1.0

ApplicationWindow {
    property int bottomMargin: 10
    property int columnSpacing: 50

    visible: true
    width: 640
    height: 480
    title: qsTr("Image App")
    style: ApplicationWindowStyle {
        background: Rectangle {
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: "#000000";
                }
                GradientStop {
                    position: 1.00;
                    color: "#b9b3b3";
                }
            }
        }
    }

    StackView {
        id: pageStack
        anchors.fill: parent
        initialItem: "qrc:/MainPage.qml"
        delegate: stackViewDelegate
    }

    StackViewDelegate {
        id: stackViewDelegate
        function getTransition(properties)
        {
            return pushTransition
        }

        function transitionFinished(properties)
        {
            properties.exitItem.opacity = 1
        }

        property Component pushTransition: StackViewTransition {
            PropertyAnimation {
                target: enterItem
                property: "opacity"
                from: 0
                to: 1
                duration: 700
            }
            PropertyAnimation {
                target: exitItem
                property: "opacity"
                from: 1
                to: 0
                duration: 700
            }
        }
    }

    ImageModel {
        id: imageModel
    }
}

