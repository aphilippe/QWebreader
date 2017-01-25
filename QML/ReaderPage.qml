import QtQuick 2.0
import QtWebEngine 1.2
import PageModel 1.0

Item {
    ReaderPageModel {
        id: pageModel
    }

    WebEngineView {
        anchors.fill: parent
        url: pageModel.openedWeb
        settings.pluginsEnabled: true
    }
}
