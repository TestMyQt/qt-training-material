import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Shapes 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Shapes")

    Shape {
        id: shape
        anchors.fill: parent
        ShapePath {
            strokeWidth: 10
            strokeColor: "lightGreen"
            fillGradient: RadialGradient {
                centerX: shape.width / 2; centerY: shape.height / 2
                centerRadius: shape.width * 0.1
                focalX: centerX; focalY: centerY
                spread: ShapeGradient.RepeatSpread
                GradientStop { position: 0; color: "black" }
                GradientStop { position: 1; color: "yellow" }
            }
            strokeStyle: ShapePath.SolidLine
            startX: shape.width * 0.3; startY: shape.height * 0.1
            PathLine { x: shape.width * 0.7; y: shape.height * 0.1 }
            PathLine { x: shape.width * 0.9; y: shape.height * 0.3 }
            PathLine { x: shape.width * 0.9; y: shape.height * 0.7 }
            PathLine { x: shape.width * 0.7; y: shape.height * 0.9 }
            PathLine { x: shape.width * 0.3; y: shape.height * 0.9 }
            PathLine { x: shape.width * 0.1; y: shape.height * 0.7 }
            PathLine { x: shape.width * 0.1; y: shape.height * 0.3 }
            PathLine { x: shape.width * 0.3; y: shape.height * 0.1 }
        }
    }
}
