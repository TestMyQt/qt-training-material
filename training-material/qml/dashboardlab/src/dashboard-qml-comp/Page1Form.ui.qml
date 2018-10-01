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

        Row {
            id: row1
            width: parent.width
            spacing: 60

            LightWithLabel {
                id: lightWithLabel
                pictureSource: "qrc:/iso-icons/iso_grs_7000_4_0248.dat"
                text1Text: "Oil"
            }

            LightWithLabel {
                id: lightWithLabel1
                pictureSource: "qrc:/iso-icons/iso_grs_7000_4_0246.dat"
                text1Text: "Temperature"
            }

            LightWithLabel {
                id: lightWithLabel2
                text1Text: "Preheat"
                pictureSource: "qrc:/iso-icons/iso_grs_7000_4_0457.dat"
            }

            LightWithLabel {
                id: lightWithLabel3
                text1Text: "Stop"
                pictureSource: "qrc:/iso-icons/iso_grs_7000_4_3026.dat"
            }

            LightWithLabel {
                id: lightWithLabel4
                text1Text: "Wiper"
                pictureSource: "qrc:/iso-icons/iso_grs_7000_4_0086.dat"
            }

            LightWithLabel {
                id: lightWithLabel5
                text1Text: "Fuel"
            }
        }
    }
}
