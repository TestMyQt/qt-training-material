import QtQuick 2.9
import QtMultimedia 5.9

Rectangle {
    color: "black"

    Video {
        id: video
        anchors.fill: parent
        source: "qrc:/hst_1.mpg"//"http://hubblesource.stsci.edu/sources/video/clips/details/images/hst_1.mpg"
        autoPlay: true
        autoLoad: true
        loops: MediaPlayer.Infinite

        MouseArea {
            anchors.fill: parent
            onClicked: {
                video.play()
            }
        }
    }
}
