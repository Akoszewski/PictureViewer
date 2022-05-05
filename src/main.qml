import QtQuick 2.0

Window {
    property string name: "pic.jpg"

    id: window
    width: 1200
    height: 800
    visible: true
    title: qsTr("Hello World")

    Image {
        id: img
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
            rightMargin: window.width * 0.05

        }
        width: window.width * 0.4
        height: window.width * 0.4
        source: "file:images/" + name
    }
}
