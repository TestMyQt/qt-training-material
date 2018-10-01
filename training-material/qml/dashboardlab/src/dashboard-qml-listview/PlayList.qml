import QtQuick 2.0

ListView {
    model: ListModel {
        ListElement {
            icon: ""
            artist: "Avicii"
            album: ""
            song: "Wake me up"
        }
        ListElement {
            icon: ""
            artist: "Portishead"
            album: "Dummy"
            song: "Glory Box"
        }
        ListElement {
            icon: ""
            artist: "Morcheeba"
            album: "Greatest Hits"
            song: "Rome wasn't built in a day"
        }
    }
    spacing : 12
    header: Text{
        text:"Playlist"
    }

    delegate: Rectangle{
        color: "#4d3c3c"
        border.color: "lightgrey"
        border.width: 2
        radius: 16
        width: parent.width
        height: 60
        Column{
            anchors.fill: parent
            Text{
                x:12
                color: "white"
                text: "Artist : " + artist
            }
            Text{
                x:12
                color: "white"
                text: "Album : " + album
            }
            Text{
                x:12
                color: "white"
                text: "Song : " + song
            }
        }
    }
}
