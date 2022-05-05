import QtQuick 2.0

Window {
    property string name: "pic.jpg"

    id: window
    width: 1200
    height: 1000
    visible: true
    title: qsTr("Hello World")

    Image {
        id: img
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
            rightMargin: window.width * 0.1

        }
        width: window.height * 0.5
        height: window.height * 0.5
        source: "file:images/" + name
    }
}
