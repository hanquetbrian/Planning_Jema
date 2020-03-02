import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

RowLayout {

    TextField {
        id: textDatePicker

        placeholderText: qsTr("Entrer un jour")
        font.bold: true
        font.pointSize: 10

        MouseArea {
            anchors.fill: parent
            onClicked: calendarDialog.open()
        }
    }

    Dialog {
        id: calendarDialog
        background: {}
        topMargin: 50

        Calendar {
            id: calendarView
            z:1
            clip: false
            onClicked: {
                textDatePicker.text = Qt.formatDate(calendarView.selectedDate, "dd-MM-yyyy");
                calendarDialog.close()
            }
        }
    }


}


