import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    id: toastForm


    Rectangle {
        id: rect
        width: 100; height: 100
        color: "red"
        anchors.fill: parent

        ParallelAnimation {
            running: true
            NumberAnimation { target: rect; property: "x"; to: 50; duration: 1000 }
            NumberAnimation { target: rect; property: "y"; to: 50; duration: 1000 }
        }
    }

}
