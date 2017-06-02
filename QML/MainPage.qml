import QtQuick 2.0
import QtQuick.Dialogs 1.2
import PageModel 1.0

Item {
    MainPageModel {
        id: pageModel
    }

    Rectangle {
        id:leftPanel
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        height: parent.height
        width: 200
        color: "red"
    }

    WebPage{
        id: webPage
        height: parent.height
        anchors {
            left: leftPanel.right
            right: parent.right
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            pageModel.onSaveDirectoryChange(fileDialog.fileUrl)
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
        visible: false
    }

    Component.onCompleted: {
        fileDialog.visible = !pageModel.saveDirectorySet;
    }
}
