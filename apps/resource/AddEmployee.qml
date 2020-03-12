import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.14
import PlanningModel 1.0

Dialog {
    property PlanningModel pModel

    title: qsTr("Ajouter un employé")

    ColumnLayout {
        Label {
            text: qsTr("Nom: ")
        }

        TextField {
            id: name
            placeholderText: qsTr("Nom de l'employé")
        }

        Label {
            text: qsTr("Cacher: ")
        }

        CheckBox {
            id: hide
            text: qsTr("Cacher")
        }
    }

    onAccepted: {
        pModel.addEmployee(name.text, hide.checked)
    }
}
