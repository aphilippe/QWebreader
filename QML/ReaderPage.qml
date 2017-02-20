import QtQuick 2.0
import QtWebEngine 1.2
import PageModel 1.0

Item {
    property string url: webView.url
    onUrlChanged: webView.url = url

    WebEngineView {
        id: webView
        anchors.fill: parent
        settings.pluginsEnabled: true
        onUrlChanged: console.log(url)
    }
}
