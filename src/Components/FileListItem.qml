import QtQuick 2.0
import QtQuick.Controls


ItemDelegate {
    property alias label: contentText.text
    id: delegate
    highlighted: ListView.isCurrentItem
    contentItem: Text {
        id: contentText
        font.pixelSize: 20
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    background: Rectangle {
        anchors.fill: delegate
        color: delegate.highlighted ? "#add8e6" : "transparent"
    }
}
