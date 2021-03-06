import QtQuick 2.0
import QtQuick.Controls
import Qt.labs.folderlistmodel 1.0

import "Components/"

Window {
    property string currFileName: "pic.jpg"
    property int containerWidth: window.width * 0.4
    property int containerHeight: window.width * 0.4
    property int containerMargin: window.width * 0.05


    id: window
    width: 1200
    height: 800
    visible: true
    title: qsTr("Hello World")

    FolderListModel {
        id: folderModel
        folder: "file:images/"
        nameFilters: [ "*" ]
    }

    ScrollView {
        id: menu
        width: containerWidth
        height: containerHeight
        clip: true

        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: containerMargin
        }

        ListView {
            property var currentSelectedItem
            id: listView
            model: folderModel
            anchors.fill: parent
            delegate: FileListItem {
                id: delegate
                height: 50
                width: parent.width
                label: fileName
                MouseArea {
                    anchors.fill: parent
                    onClicked: { 
                        listView.currentIndex = index;
                        currFileName = delegate.label
                    }
                }
            }
        }
    }

    Image {
        id: img
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
            rightMargin: containerMargin
        }
        width: containerWidth
        height: containerHeight
        source: "file:images/" + currFileName
    }
}
