import QtQuick 2.0
import PageModel 1.0

Item {
    id: webListPage;

    property int webId


    WebListPageModel {
        id: pageModel
        onWebIdChanged: {
            webId = newWebId;
        }
    }



    ListView {
        id: listView
        anchors.fill: parent
        model: pageModel.webs
        delegate : Item {
            property alias text: text.text
            width: parent.width
            height: 55
            Text {
                id:text
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

        onCurrentItemChanged: {
            pageModel.selectItem(currentItem.text)
        }
    }
}
