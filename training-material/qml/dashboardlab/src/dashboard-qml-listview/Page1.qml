import QtQuick 2.7

Page1Form {
    id: form
    transitions: [Transition {
            from: ""
            to: "multimedia"
            PropertyAnimation {
                property: "rpmmeterScale"
                target: form
                duration: 1000
                from: 1.0
                to: 0.4
            }
        },
        Transition {
            from: ""
            to: "navigating"
            PropertyAnimation {
                property: "rpmmeterScale"
                target: form
                duration: 1000
                from: 1.0
                to: 0.4
            }
        },
        Transition {
            from: ""
            to: "playlist"
            ParallelAnimation{
            PropertyAnimation {
                property: "rpmmeterOpacity"
                target: form
                duration: 1000
                from: 1.0
                to: 0.4
            }
            PropertyAnimation {
                property: "rpmmeterScale"
                target: form
                duration: 1000
                from: 1.0
                to: 0.4
            }
            PropertyAnimation{
                property: "rpmmeterX"
                target: form
                duration: 1000
                from: -136
                to: -180
            }
            }
        },
        Transition {
            from: "*"
            to: ""
            PropertyAnimation {
                property: "rpmmeterScale"
                target: form
                duration: 1000
                from: 0.4
                to: 1.0
            }
        }
    ]
}
