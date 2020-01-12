import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Song Player")

    ColumnLayout
    {
        width: parent.width
        height: parent.height

        TabBar {
            id: tabHeader
            Layout.fillWidth: true
            anchors.top: parent.top

            currentIndex: swipeView.currentIndex

            TabButton {
                text: qsTr("Songs")
            }
            TabButton {
                text: qsTr("Playlist")
            }
        }

        SwipeView {
            id: swipeView
            Layout.fillWidth: true;
            anchors.top: tabHeader.bottom
            anchors.bottom: framePlayer.top
            currentIndex: tabHeader.currentIndex
            Frame
            {

                id: frameSongForm
                Songs {
                    id: songForm
                    anchors.centerIn: parent

                }
            }

            Frame {
                id: framePlaylistForm
                Playlists {
                    id:playlistForm
                }
            }
        }

        Frame
        {
            id:framePlayer
            anchors.bottom: parent.bottom
            Layout.fillWidth: true
            implicitHeight: tabHeader.implicitHeight
            PlayerForm{
                id: playerForm
                anchors.centerIn: parent
            }
        }
    }
}
