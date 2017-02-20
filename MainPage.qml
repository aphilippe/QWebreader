import QtQuick 2.0
import PageModel 1.0

Item {
    MainPageModel {
        id: pageModel
        onIsWebOpenedChanged: function() {
            pageLoader.sourceComponent = (isWebOpened) ? readerPage : newPage;
        }
    }

    Component {
        id: readerPage
        ReaderPage {
            url: pageModel.url
        }
    }

    Component {
        id: newPage
        NewPage {
            onUrlChanged: pageModel.onNewUrlChosed(url)
        }
    }


    Loader {
        id: pageLoader
        anchors.fill: parent
        property bool isWebOpened: pageModel.isWebOpened
        sourceComponent: (isWebOpened) ? readerPage : newPage
    }
}
