import QtQuick 2.9

LightWithLabelForm {
    width: 120
    height: 120

    property bool normal: true
    property bool warning: false
    property bool failure: false
    pictureColor: normal? "lightgrey" : warning ? "orange" : "red"
    text1Color: pictureColor
    Timer{
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            if(normal) {
                warning=true
                normal=false
                failure=false
            }
            else if (warning){
                warning=false
                normal=false
                failure=true
            }
            else{
                warning=false
                normal=true
                failure=false
            }
        }
    }
}
