import QtQuick 2.0
import PageModel 1.0

Item {
    id: mainPage
    property string url: pageModel.url

    MainPageModel {
        id: pageModel
    }

    Component {
        id: readerPageComponent
        ReaderPage {
            id: readerPage
            url: mainPage.url
            onUrlChanged: pageModel.onUrlUpdated(url)
        }
    }

    Component {
        id: newPageComponent
        NewPage {
            id: newPage
            onUrlChanged: {
                mainPage.url = url
                pageLoader.sourceComponent = readerPageComponent
            }
        }
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
        sourceComponent: (mainPage.url != "") ? readerPageComponent : newPageComponent
    }
}
