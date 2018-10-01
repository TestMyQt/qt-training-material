import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    width: 640; height: 480
    visible: true

    ListView {
        anchors.fill: parent
        model: myModel
        delegate: Row {
            spacing: 10
            TextInput {
                text: "Animal type: " + type

                onTextChanged: {
                    var newString = text.substring(13, text.length);
                    if (type != newString)
                        type = newString;
                }
            }
            TextInput {
                text: "Animal size: " + size

                onTextChanged: {
                    var newString = text.substring(13, text.length);
                    if (size != newString)
                        size = newString;
                }
            }
        }
    }

}

