import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    anchors.centerIn: parent

    header: Label {
        text: qsTr("This place is used for searching")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
