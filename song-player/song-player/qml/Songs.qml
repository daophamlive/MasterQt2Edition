import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Song 1.0

ColumnLayout{
    property bool checkboxVisible: false
    Frame{
        Layout.fillWidth: true
        Layout.fillHeight: true
        ListView {
            anchors.fill: parent
            implicitWidth: 200
            implicitHeight: 300
            clip: true
            model: SongModel{
                mSongList: songList
            }


            delegate: RowLayout {
                width: parent.width
                CheckBox {
                    onClicked: model.selected = !model.selected
                    visible: checkboxVisible
                }

                ColumnLayout {
                    Label {
                        Layout.fillWidth: true
                        text: model.name
                    }
                    Label {
                        Layout.fillWidth: true
                        text: model.author
                    }

                    Label {
                        Layout.fillWidth: true
                        text:
                        {
                            if(model.selected)
                                "selected"
                            else
                                ""
                        }
                    }
                }
            }
        }
    }

    RowLayout{
        Layout.fillHeight: true
        Button{
            text: qsTr("Add new song")
            Layout.fillWidth: true
            onClicked: songList.appendItem()
        }

        Button{
            text: qsTr("Remove selected song")
            Layout.fillWidth: true
            onClicked: songList.removeCompletedItems()
        }

        Button{
            text: qsTr("Set item selected")
            Layout.fillWidth: true
            onClicked: songList.removeCompletedItems()
        }

        Button{
            text: qsTr("Show checkbox")
            Layout.fillWidth: true
            onClicked: checkboxVisible = !checkboxVisible
        }
    }
}
