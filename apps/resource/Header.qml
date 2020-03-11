import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import PlanningModel 1.0

Rectangle {
    id: header

    property PlanningModel pModel
    height: brandImg.height*1.3
    gradient: Gradient {
        orientation: Gradient.Horizontal
        GradientStop {position: 0.0; color: "#5eade6"}
        GradientStop {position: 1.0; color: "#93ccf5"}
    }

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
            onCurrentIndexChanged: {
                pModel.interval = currentIndex;
            }

        }


        DatePicker {
            pModel: header.pModel
        }

        Item {
            Layout.fillWidth: true
        }

        PButton {
            iconSrc: "qrc:/resource/icon/sort-down.svg"
            implicitWidth: 30
            implicitHeight: 25
        }

        PButton {
            id: setting
            iconSrc: "qrc:/resource/icon/tools.svg"
        }

        PButton {
            id: userConfig
            iconSrc: "qrc:/resource/icon/user.svg"
        }

        PButton {
            id: aboutDialog
            iconSrc: "qrc:/resource/icon/question.svg"
            onClicked: about.open()
        }

        About {
                id: about
            }

    }

}
