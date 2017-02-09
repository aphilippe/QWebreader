import QtQuick 2.0
import QtWebEngine 1.2
import PageModel 1.0

Item {
    property int web_id: 0
    onWeb_idChanged: pageModel.setWebId(web_id)
    ReaderPageModel {
        id: pageModel
        onUrlChanged: webView.url = url
    }

    WebEngineView {
        id: webView
        anchors.fill: parent
        url: pageModel.url
        settings.pluginsEnabled: true
        Binding {
            target: pageModel
            property: 'url'
            value: webView.url
        }
        onUrlChanged: console.log(url)
    }
}
