import QtQuick 2.0
import PageModel 1.0

Item {
    MainPageModel {
        id: pageModel

    }

    Component {
        id: readerPage
        ReaderPage {

        }
    }

    Component {
        id: newPage
        NewPage {

        }
    }


    Loader {
        id: pageLoader
        anchors.fill: parent
        property bool isWebOpened: pageModel.isWebOpened
        //source: (isWebOpened) ? "ReaderPage.qml" : "NewPage.qml"
        sourceComponent: (isWebOpened) ? readerPage : newPage
    }
}
