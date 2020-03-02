import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

Rectangle {
    color: '#66b2e8'
    height: brandImg.height*1.3

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: parent.height * 0.1
        spacing: 20

        Image {
            id: brandImg
            source: "qrc:/resource/img/logo_transparent_small.png"
        }
        Text {
            text: "Planning Jema"
            color: "white"
            font.pixelSize: 25
        }
        ComboBox {
            Layout.leftMargin: mainLayout.width * 0.05
            model: ['Jour', 'Semaine', 'Mois', 'Année']
            currentIndex: 2
        }

        DatePicker {}

        Item {
            Layout.fillWidth: true
        }

        PButton {
            iconSrc: "qrc:/resource/icon/tools.svg"
        }

        PButton {
            iconSrc: "qrc:/resource/icon/user.svg"
        }

    }

}
