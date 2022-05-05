import QtQuick 2.0
import QtQuick.Controls

import "Components/"

Window {
    property string name: "pic.jpg"
    property int containerWidth: window.width * 0.4
    property int containerHeight: window.width * 0.4
    property int containerMargin: window.width * 0.05


    id: window
    width: 1200
    height: 800
    visible: true
    title: qsTr("Hello World")

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
            id: listView
            model: 20
            anchors.fill: parent
            delegate: FileListItem {
                height: 50
                width: parent.width
                label: "model " + index
                MouseArea {
                    anchors.fill: parent
                    onClicked: listView.currentIndex = index
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
        source: "file:images/" + name
    }
}
