import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.3
import PlanningModel 1.0


Dialog {
    property PlanningModel pModel
    title: qsTr("Ajout d'une tâche")

    ColumnLayout {
        ComboBox {
            width: 200
            model: [ "SO, IR, IG", "Test", "Autre" ]
        }

        StackView {
            initialItem: soView
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Component {
            id: soView
            Label {
                text: "test"
            }
        }

//        Component {
//            id: testView
//        }

//        Component {
//            id: otherView
//        }
    }
}
