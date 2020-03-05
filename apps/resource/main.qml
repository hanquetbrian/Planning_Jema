import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14
import CalendarModel 1.0
import PlanningModel 1.0


ApplicationWindow {
    id: mainWindow
    visible: true
    title: qsTr("Planning Jema")
    width: screen.width * 0.8
    height: screen.height * 0.8

    property PlanningModel pModel: PlanningModel{}
    //Calendar {anchors.fill: parent}

    header: Header{
        id: header
        pModel: mainWindow.pModel
    }

    StackView {
        initialItem: CalendarView{
            pModel: mainWindow.pModel
            model: mainWindow.pModel.calendarModel
        }
        anchors.fill: parent

    }


}
