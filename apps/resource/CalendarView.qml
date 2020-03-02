import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14

ListView {
    id: flickable
    property date firstDay: new Date()
    property int nbDay: 31


    model: CalendarModel{}
    delegate: calendarDelegate
    ScrollBar.vertical: ScrollBar {
        id: myscrollBar
        policy : {
            if (size >=1) {
                return ScrollBar.AlwaysOff
            } else {
                return ScrollBar.AlwaysOn

            }
        }
    }

    header: calendarHeader

    Component {
        id: calendarHeader
        RowLayout {
           height: 50
           width: parent.width
           spacing: 0

            Rectangle {
                Layout.fillHeight: true
                Layout.preferredWidth: 200

                border.width: 0.5
                border.color: 'lightgray'
                color: "#f7f7f7"

            }

            ColumnLayout {
                Rectangle {

                }
            }
        }
    }


    Component {
        id: calendarDelegate

        RowLayout {
            height: 100
            width: parent.width
            spacing: 0

            Rectangle {
                Layout.fillHeight: true
                Layout.preferredWidth: 200
                border.width: 0.5
                border.color: 'lightgray'
                color: "#f7f7f7"


                Label {
                    text: model.name
                    color: "#424547"
                    font.pixelSize: 18
                    font.bold: true

                    anchors.fill: parent
                    anchors.margins: 15

                }
            }
            Repeater {
                model: flickable.nbDay
                Tile {

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }

        }

    }
}
