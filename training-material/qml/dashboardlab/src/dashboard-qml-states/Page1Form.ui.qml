import QtQuick 2.7

Item {
    id: dashboard
    width: 1024
    height: 576
    property alias rpmmeterScale: rpmmeter.scale
    property alias rpmmeterOpacity: rpmmeter.opacity
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

            Item {
                id: rpmcontainer
                width: parent.width * 0.5 - 60
                height: parent.height
                opacity: 1

                Item {
                    id: rpmmeter
                    width: 452
                    height: 456
                    anchors.leftMargin: 0
                    anchors.bottomMargin: 0
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left

                    Image {
                        id: rpmmeterbackground
                        anchors.fill: parent
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

                Item {
                    id: multimedia
                    visible: false
                    anchors.fill: parent

                    MultiMediaPlayer {
                        id: multiMediaPlayer
                        anchors.fill: parent
                    }
                }

                Item {
                    id: navigation1
                    visible: false
                    anchors.fill: parent

                    Navigation {
                        id: navigation
                        anchors.fill: parent
                    }
                }
            }
        }
    }
    states: [
        State {
            name: "navigating"
            PropertyChanges {
                target: rpmmeter
                anchors.leftMargin: -136
                anchors.bottomMargin: -137
                anchors.bottom: rpmcontainer.bottom
                anchors.left: rpmcontainer.left
                z: 1
                scale: 0.4
            }

            PropertyChanges {
                target: navigation1
                visible: true
            }

            PropertyChanges {
                target: multimedia
                visible: false
            }
        },
        State {
            name: "multimedia"
            PropertyChanges {
                target: rpmmeter
                z: 1
                anchors.leftMargin: -136
                anchors.bottomMargin: -137
                anchors.bottom: rpmcontainer.bottom
                anchors.left: rpmcontainer.left
                scale: 0.4
            }

            PropertyChanges {
                target: multimedia
                visible: true
            }

            PropertyChanges {
                target: navigation1
                visible: false
            }
        }
    ]
}
