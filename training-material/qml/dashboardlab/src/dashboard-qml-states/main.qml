import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.VirtualKeyboard 2.1

ApplicationWindow {
    visible: true
    width: 1024
    height: 576
    title: qsTr("Dashboard")
    id: root
    color: "black"

    Page1{
        id:dashboard
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Left) {
                dashboard.state = "navigating"
            }
            if (event.key == Qt.Key_Right) {
                dashboard.state = "multimedia"
            }
            if (event.key == Qt.Key_Up) {
                dashboard.state = ""
            }
        }
    }

    Connections{
        target: rpmEngine
        onRpmReady:{
            dashboard.rmpneedleRotation = -136 + rpm/8000*240;
        }
        onSpeedReady:{
            dashboard.speedoneedleRotation = -136 + speed/260*240;
        }
    }

}
