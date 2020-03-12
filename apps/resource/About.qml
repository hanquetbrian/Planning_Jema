import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.3

Dialog {
    title: qsTr("About")
    width: 400
    height: 500
    standardButtons: Dialog.Ok | Dialog.Cancel

    ColumnLayout {
        anchors.fill: parent
        Image {
            Layout.alignment: Qt.AlignHCenter
            source: "qrc:/resource/img/logo_transparent.png"
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillHeight: true

            Text {
                text: qsTr("Planning Jema")
                font.bold: true
                font.pixelSize: 18
            }

            Text {
                text: qsTr("Version " + mainWindow.project_ver)
            }


            Text {
                id: name
                text: "GitHub: <a href='https://github.com/hanquetbrian/Planning_Jema'>https://github.com/hanquetbrian/Planning_Jema</a>"
                onLinkActivated: Qt.openUrlExternally(link)
            }
        }


    }
}
