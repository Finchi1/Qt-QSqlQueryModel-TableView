import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("SqlTableView")
    color: "transparent"
    // BACKGROUND
    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.7
    }
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: "white"
    }
    // HEADER
    Row {
        anchors.top: parent.top
        id: columnsHeader
        Repeater {
            model: tableViewBody.columns > 0 ? tableViewBody.columns : 1
            Label {
                width: tableViewBody.columnWidthProvider(modelData)
                height: 50
                text: myModel.headerData(modelData, Qt.Horizontal)
                font.pixelSize: 15
                padding: 10
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "lightgrey"
                    border.color: "black"
                    border.width: 1
                }
            }
        }
    }
    // BODY
    TableView {
        id: tableViewBody
        columnWidthProvider: function (column) { return 160; }
        anchors.top: columnsHeader.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        columnSpacing: 1
        rowSpacing: 1
        clip: true
        model: myModel
        delegate:
            Rectangle {
            id: contentRectangle
            implicitWidth: parent.width/4-2*border.width
            implicitHeight: 50
            border.width: 1
            border.color: "white"
            color: "transparent"
            Text {
                anchors.centerIn: parent
                text: display
                color: "white"
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
        ScrollIndicator.horizontal: ScrollIndicator {}
    }
}