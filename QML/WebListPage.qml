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

                anchors {
                    fill: parent
                    leftMargin: 10
                    rightMargin: 10
                }

                text: modelData
                clip: true
                verticalAlignment: Text.AlignVCenter
            }
            Rectangle {
                height: 1
                color: "lightgrey"
                anchors {
                    left: parent.left
                    leftMargin: 5
                    right: parent.right
                    rightMargin: 5
                    top: parent.bottom
                }
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

        onCurrentIndexChanged: {
            pageModel.selectItem(currentIndex)
        }
    }
}
