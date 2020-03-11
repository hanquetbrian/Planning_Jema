import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.3

Dialog {
    title: qsTr("About")
    standardButtons: Dialog.Ok | Dialog.Cancel

    ColumnLayout {
        anchors.fill: parent
        Image {
            source: "qrc:/resource/img/logo_transparent.png"
        }
        Text {
            text: qsTr("Planning Jema")
            font.bold: true
        }
    }
}
