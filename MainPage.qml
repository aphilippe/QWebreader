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

        }
    }

    Component {
        id: newPage
        NewPage {
            onUrlChanged: pageModel.url = url
        }
    }


    Loader {
        id: pageLoader
        anchors.fill: parent
        property bool isWebOpened: pageModel.isWebOpened
        sourceComponent: (isWebOpened) ? readerPage : newPage
    }
}
