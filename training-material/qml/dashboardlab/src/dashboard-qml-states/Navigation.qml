import QtQuick 2.9
import QtLocation 5.9
import QtPositioning 5.8

Rectangle {
    color: "black"
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(37.56, 126.97) // Seoul
        zoomLevel: 14
    }
}
