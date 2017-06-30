import QtQuick 2.0
import PageModel 1.0

Item {
    id: webListPage;

    WebListPageModel {
        id: pageModel
    }

    Rectangle {
        color: "blue";
        anchors.fill: parent;
    }
}
