import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14
//import QtQuick.Controls 1.4

ApplicationWindow  {
    visible: true
    title: qsTr("Hello World")

    //Calendar {anchors.fill: parent}

    ColumnLayout {
        anchors.fill: parent

        GridLayout {
            id: gridLayout
            columns: 12
            columnSpacing: 0
            rowSpacing: 0



            Repeater {
                model: 60
                Tile {
                    color: "aliceblue"

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }

        }

        Rectangle {
            Layout.fillWidth: true
            height: 5
            color: "black"
        }
    }



}
