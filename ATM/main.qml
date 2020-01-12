import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "qrc:/"


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("ATM application")

    property alias isLogin: login.isLogin

    ColumnLayout
    {
        spacing: 5
        anchors.fill: parent

        Login {
            id: login
            Layout.fillWidth: true
        }

        ProcessForm{
            id: process
             Layout.fillWidth: true
             visible: isLogin
        }

        Toast{
            id: message

        }

    }
}
