import QtQuick 2.0
import PageModel 1.0

Item {
    id: webListPage;

    WebListPageModel {
        id: pageModel
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: pageModel.webs
        delegate : Item {
            width: parent.width
            height: 55
            Text {
            text: modelData
        }
        MouseArea {
            anchors.fill: parent
            onClicked: listView.currentIndex = index
            }
        }
        focus: true

        highlight: Rectangle {
            width: parent.width; height: 55
            color: "#FFFF88"
            y: listView.currentItem.y;
        }
        highlightFollowsCurrentItem: false
    }
}
