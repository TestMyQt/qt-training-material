import QtQuick 2.9
import QtQuick.Window 2.3
import Charts 1.0

Window {
    width: 640; height: 480
    visible: true
    Item {
        anchors.fill: parent

        PieChart {
            id: aPieChart
            anchors.centerIn: parent
            width: 100; height: 100
            name: "A simple pie chart"
            color: "red"
        }

        Text {
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 15 }
            font.pixelSize: 20
            text: aPieChart.name
        }
    }
}
