import QtQuick 2.0
import QtQuick.Controls 2.0


ItemDelegate {
    property alias label: contentText.text
    property int selectedTableIndex
    id: delegate
    highlighted: selectedTableIndex == index
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
