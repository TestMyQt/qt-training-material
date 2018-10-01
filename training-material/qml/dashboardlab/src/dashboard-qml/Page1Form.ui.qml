import QtQuick 2.7

Item {
    id: dashboard
    width: 1024
    height: 576
    property alias rmpneedleRotation: rmpneedle.rotation
    property alias speedoneedleRotation: speedoneedle.rotation
    property alias dashboardRotation: dashboard.rotation

    Column {
        id: column
        anchors.fill: parent

        Row {
            id: row
            width: parent.width
            height: parent.height - 120
            spacing: 120

            Image {
                id: speedometerbackground
                width: parent.width * 0.5 - 60
                height: parent.height
                rotation: 0
                transformOrigin: Item.Center
                sourceSize.width: 0
                source: "speedo.png"

                Image {
                    id: speedoneedle
                    width: 13
                    height: 178
                    transformOrigin: Item.Bottom
                    rotation: -136
                    anchors.verticalCenterOffset: -height * 0.5
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "needleorange.png"
                }
            }

            Image {
                id: rpmmeterbackground
                width: parent.width * 0.5 - 60
                height: parent.height
                sourceSize.width: -5
                source: "tacho.png"

                Image {
                    id: rmpneedle
                    width: 13
                    height: 178
                    anchors.verticalCenterOffset: -height * 0.5
                    rotation: -136
                    anchors.verticalCenter: parent.verticalCenter
                    transformOrigin: Item.Bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "needlered.png"
                }
            }
        }
    }
}
