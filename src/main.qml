import QtQuick 2.0
import QtQuick.Controls 2.12
import Qt.labs.folderlistmodel 1.0
import QtQuick.Window 2.15
import Qt.labs.platform

import "Components/"

Window {
    property string currFileName: "image-00000.dcm"
    property int containerWidth: window.width * 0.4
    property int containerHeight: window.width * 0.4
    property int containerMargin: window.width * 0.05


    id: window
    width: 1200
    height: 800
    visible: true
    title: qsTr("Dicom Picture Viewer")

    TextField {
        text: "Text"
        cursorVisible: true
        width: containerWidth * 2
        height: containerHeight * 0.1
        selectByMouse : true

        background: Rectangle {
            radius: 2
            border.color: "#333"
            border.width: 1
        }

        anchors {
            horizontalCenter: parent.horizontalCenter
            topMargin: containerHeight * 0.1
            top: parent.top
            right: img.right
        }

    }

    FolderListModel {
        id: folderModel
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation) + "/images/DICOM/"
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
        source: "image://DicomImageProvider/" + currFileName
    }
}
