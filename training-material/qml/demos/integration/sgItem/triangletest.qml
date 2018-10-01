import QtQuick 2.9
import QtQuick.Window 2.3
import ShapeObjects 1.0

Window {
    width: 640; height: 480
    visible: true

    Item {
        width: 300; height: 200

        Triangle {
            x: 50; y: 50
            width: 200; height: 100
        }
    }
}
