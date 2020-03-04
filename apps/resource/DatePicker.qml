import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import PlanningModel 1.0

ColumnLayout {
    property PlanningModel pModel
    TextField {
        id: textDatePicker

        placeholderText: qsTr("Entrer un jour")
        font.pointSize: 10
        Layout.maximumWidth: 100
        text: pModel.firstDate


        MouseArea {
            anchors.fill: parent
            onClicked: calendarDialog.open()
        }
    }

    Dialog {
        id: calendarDialog
        background: Item{}
        topMargin: 50

        Calendar {
            id: calendarView
            z:1
            clip: false
            onClicked: {
                pModel.firstDate = Qt.formatDate(calendarView.selectedDate, "dd/MM/yyyy");
                //textDatePicker.text = pModel.firstDate
                pModel.updateCalendar();
                calendarDialog.close()
            }
        }
    }


}


