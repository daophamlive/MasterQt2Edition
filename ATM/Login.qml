import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item{
    id: loginform
    anchors.fill: parent
    property bool isLogin: false
    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: 3
        spacing: 5
        TextField {
            id: txtPin
            Layout.fillWidth: true
            placeholderText: "<Please enter your pin>"
            echoMode: TextInput.Password
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            id: btnProcess
            text: "Login"
            Layout.alignment: Qt.AlignCenter
            anchors.top: txtPin.bottom
            onClicked: {
                if(txtPin.text === "1234")
                {
                    loginform.visible = false;
                    loginform.isLogin = true;
                }
                else
                {
                    loginform.visible = true;
                    loginform.isLogin = false;
                }
            }
        }
    }
}
