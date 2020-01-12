import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item{
    id: form
    anchors.fill: parent
    property real totalBalance: 5000000
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 3
        spacing: 5

        Label{
            id:lblTotalBalance
            Layout.fillWidth: true
            text:
            {
                "Total value " + String(totalBalance)
            }
        }

        TextField {
            id: txtWithdrawMoney
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter
            placeholderText: "How much do you want to withdraw?"
        }

        Button {
            id: btnWithDraw
            text: "Process"
            Layout.alignment: Qt.AlignCenter
            anchors.top: txtWithdrawMoney.bottom
        }
    }
}
