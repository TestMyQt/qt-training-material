import QtQuick 2.9
import QtQuick.Window 2.3
import People 1.0

Window {
    width: 640; height: 480
    visible: true

    Rectangle {
        anchors.fill: parent

        // Person is implemented in C++
        Person {
            id: person
            name: "Bob Jones"
            shoeSize: 12
            onNameChanged: {
                console.log("New name: " + name);
            }
        }

        Column {
            anchors.fill:  parent
            spacing: 20
            Text {
                font.bold: true
                font.pixelSize: 26
                text: "Person name: " + person.name
            }
            Text {
                font.bold: true
                font.pixelSize: 26
                text: "Person shoe size: " + person.shoeSize
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                person.name = "John Doe";
            }
        }
    }

}

