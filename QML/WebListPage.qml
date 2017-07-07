import QtQuick 2.0
import PageModel 1.0

Item {
    id: webListPage;

    WebListPageModel {
        id: pageModel
    }

    ListModel {
        id: webs
        ListElement {
            name: "smbc"
            index: 1
        }
        ListElement {
            name: "Homestuck"
            index: 2
        }
    }

    ListView {
        anchors.fill: parent
        model: pageModel.webs
        delegate : Row {
            Text { text: modelData}
        }
    }
}
