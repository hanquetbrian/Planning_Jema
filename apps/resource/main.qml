import QtQuick 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14



ApplicationWindow  {
    visible: true
    title: qsTr("Planning Jema")
    width: screen.width * 0.8
    height: screen.height * 0.8

    //Calendar {anchors.fill: parent}

    header: Header{
        id: header

//        anchors.fill: parent
    }

    StackView {
        initialItem: CalendarView{}
        anchors.fill: parent

    }


}
