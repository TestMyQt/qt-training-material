import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.VirtualKeyboard 2.1
import com.hmc 1.0
import QtQuick.Window 2.3

ApplicationWindow {
    visible: true
    width: 1024
    height: 576
    title: qsTr("Dashboard")
    id: root

    RpmEngine{
        id: rpmEngine
        onRpmReady:{
            dashboard.rpmGauge.value=rpm/1000;
        }
        onSpeedReady:{
            dashboard.speedGauge.value=speed;
        }
    }

    Timer{
        repeat: true
        running: true
        interval: 300
        onTriggered: {
            rpmEngine.generateRpm();
            rpmEngine.generateSpeed();
        }
    }
    property string objectName: "whateverobject"

    function whatever() {
        console.log("whatever")
    }

    Page1{
        id:dashboard
    }

    /*Connections{
        target: rpmEngine
        onRpmReady:{
            dashboard.rpmGauge.value=rpm/1000;
        }
        onSpeedReady:{
            dashboard.speedGauge.value=speed;
        }
    }*/

}
