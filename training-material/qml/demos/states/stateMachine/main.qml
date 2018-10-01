import QtQuick 2.9
import QtQuick.Window 2.2
import QtQml.StateMachine 1.0 as FSM

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Traffic lights")

    TrafficLight {
        id: trafficLight
        anchors.fill: parent
        MouseArea {
            anchors.fill: parent
            onClicked: stateMachine.stop();
        }
    }

    FSM.StateMachine {
        id: stateMachine
        initialState: running
        running: true
        FSM.State {
            id: running
            initialState: go

            FSM.State {
                id: go
                FSM.TimeoutTransition {
                    targetState: leavingGo
                    timeout: 1000
                }
                onEntered: trafficLight.currentState = "go";
            }
            FSM.State {
                id: stop
                FSM.TimeoutTransition {
                    targetState: leavingStop
                    timeout: 1000
                }
                onEntered: trafficLight.currentState = "stop";
            }
            FSM.State {
                id: leavingGo
                FSM.TimeoutTransition {
                    targetState: stop
                    timeout: 500
                }
                onEntered: trafficLight.currentState = "leavingGo";
            }
            FSM.State {
                id: leavingStop
                FSM.TimeoutTransition {
                    targetState: go
                    timeout: 500
                }
                onEntered: trafficLight.currentState = "leavingStop";
            }
        }
        FSM.FinalState {
            id: finalState // unreachable - left for demo purposes
        }
        onStopped: Qt.quit()
    }
}
