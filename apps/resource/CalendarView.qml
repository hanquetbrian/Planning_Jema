import QtQuick 2.14
import QtQuick.Layouts 1.14

ColumnLayout {
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
