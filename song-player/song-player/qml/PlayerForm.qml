import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ColumnLayout {

    Label {
        text: qsTr("This place is used for player ")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        id: text
        text: qsTr("Song list")
        font.pixelSize: Qt.application.font.pixelSize
    }
}
