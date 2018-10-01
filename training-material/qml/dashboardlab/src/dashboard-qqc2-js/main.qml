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

    Page1{
        id:dashboard
    }

    RpmEngine{
        id: rpmEngine
    }

    Connections{
        enabled: true
        target: rpmEngine
        onRpmReady:{
            dashboard.rpmGauge.value=rpm/1000;
        }
        onSpeedReady:{
            dashboard.speedGauge.value=speed;
        }
    }

}
