import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 360

    CustomItem1 {
        id: customItem1
        width: 100
        height: 100
        anchors.left: parent.left
        color: "red"
    }

    CustomItem2 {
        width: 100
        height: 100
        anchors.right: parent.right
        hello: customItem1
        color: "green"
    }
}
