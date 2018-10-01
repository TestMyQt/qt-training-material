import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

Page {
    id: item1
    width: 1024
    height: 576
    property alias rpmGauge: rpmGauge
    property alias speedGauge: speedGauge

    ColumnLayout {
        id: columnLayout
        anchors.rightMargin: 15
        anchors.leftMargin: 15
        anchors.bottomMargin: 5
        anchors.topMargin: 15
        anchors.fill: parent

        RowLayout {
            id: rowLayout1
            width: parent.width
            height: 100
            spacing: parent.width * 0.1
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true

            CircularGauge {
                id: speedGauge
                Layout.fillHeight: true
                Layout.fillWidth: true
                maximumValue: 300
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                style: CircularGaugeStyle {
                    tickmarkStepSize: 20
                }
                Text {
                    id: speedText
                    x: 525
                    y: 154
                    width: 67
                    height: 34
                    color: "#ffffff"
                    text: qsTr("Km/h")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    font.bold: true
                    font.pixelSize: 30
                }
            }

            CircularGauge {
                id: rpmGauge
                Layout.fillHeight: true
                Layout.fillWidth: true
                minimumValue: 0
                value: 0
                maximumValue: 9
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                style: CircularGaugeStyle {
                    tickmarkStepSize: 1
                    labelStepSize: 1
                }
                Text {
                    id: rpmText
                    color: "#ffffff"
                    text: qsTr("1000xRPM")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    font.bold: true
                    font.pixelSize: 30
                }
            }
        }

        RowLayout {
            id: rowLayout
            width: 100
            height: 100
            spacing: parent.width * 0.125
            Layout.maximumHeight: parent.height * 0.2
            Layout.maximumWidth: parent.width
            Layout.fillWidth: true

            Picture {
                id: picture
                color: "#ffffff"
                source: "qrc:/iso-icons/iso_grs_7000_4_0635A.dat"
            }

            Picture {
                id: picture2
                color: "#ffffff"
                source: "qrc:/iso-icons/iso_grs_7000_4_0636A.dat"
            }

            Gauge {
                id: gauge
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                maximumValue: 40
                orientation: Qt.Horizontal

                Text {
                    id: text1
                    x: 0
                    y: 8
                    color: "#ffffff"
                    text: qsTr("Fuel")
                    font.bold: true
                    font.pixelSize: 16
                }
            }

            Picture {
                id: picture1
                color: "#ffffff"
                source: "qrc:/iso-icons/iso_grs_7000_4_0647.dat"
            }

            Picture {
                id: picture3
                color: "#ffffff"
                source: "qrc:/iso-icons/iso_grs_7000_4_1424.dat"
            }
        }
    }
}
