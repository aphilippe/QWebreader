import QtQuick 2.0
import QtWebEngine 1.2

Item {
    WebEngineView {
        anchors.fill: parent
        url: "http://www.mspaintadventures.com?s=6&p=005595"
        settings.pluginsEnabled: true
    }
}
