import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    Rectangle {
        id: input
        width: 200
        height: 50
        anchors.centerIn: parent
        border {
            width: 2
            color: "red"
        }

        TextInput {

            wrapMode: TextInput.NoWrap
            anchors {
                fill: parent
                leftMargin: 5
                rightMargin: 5
                topMargin: 5
                bottomMargin: 5
            }
            clip: true
            verticalAlignment: TextInput.AlignVCenter
        }
    }

    Button {
        anchors {
            verticalCenter: parent.verticalCenter
            left: input.right
            leftMargin: 5
        }

        text: "GO"
    }
}
