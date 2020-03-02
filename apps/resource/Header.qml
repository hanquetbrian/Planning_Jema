import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

Rectangle {
    color: '#66b2e8'
//    clip: true
    height: brandImg.height*1.3

    RowLayout {
        anchors.fill: parent
        anchors.margins: parent.height * 0.1

        Image {
            id: brandImg
            source: "qrc:/resource/img/logo_transparent_small.png"
        }
        Text {
            text: "Planning Jema"
            color: "white"
            font.pixelSize: 25
            anchors.left: brandImg.right
            anchors.leftMargin: 20
        }
        ComboBox {
            model: ['Jour', 'Semaine', 'Mois', 'Année']
            currentIndex: 2
        }



        DatePicker {

        }
    }

}
