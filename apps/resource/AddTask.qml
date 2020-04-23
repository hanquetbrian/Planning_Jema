import QtQuick 2.14
import QtQuick.Window 2.2
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import PlanningModel 1.0


Window {
    id: addTaskDialog
    property PlanningModel pModel
    title: qsTr("Ajout d'une tâche")
    minimumWidth: 400
    minimumHeight: 600
    color: "whitesmoke"
    flags: Qt.Dialog
    modality: Qt.WindowModal

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        ComboBox {
            width: 200
            model: [ qsTr("SO, IR, IG"), qsTr("Test"), qsTr("Autre") ]
            onActivated: stack.currentIndex = index;
        }

        StackLayout {
            id: stack
            currentIndex: 0

            GroupBox {
                title: qsTr("Numéro commande")
                Layout.fillHeight: false
                GridLayout {
                    columns: 2

                    Label {
                        text: qsTr("Titre: ")
                    }

                    TextField {
                        placeholderText: qsTr("Titre")
                    }

                    Label {
                        text: qsTr("SO: ")
                    }

                    TextField {
                        placeholderText: qsTr("SO")
                    }

                    Label {
                        text: qsTr("WO:")
                    }

                    TextField {
                        placeholderText: qsTr("WO")
                    }

                    Label {
                        text: qsTr("Date du début: ")
                    }

                    TextField {
                        placeholderText: qsTr("Date du début")
                    }

                    Label {
                        text: qsTr("Date de fin: ")
                    }

                    TextField {
                        placeholderText: qsTr("Date de fin")
                    }

                    Label {
                        text: qsTr("Heure du début: ")
                    }

                    TextField {
                        placeholderText: qsTr("Heure du début")
                    }


                    Label {
                        text: qsTr("Heure de fin: ")
                    }

                    TextField {
                        placeholderText: qsTr("Heure de fin")
                    }

                    Label {
                        text: qsTr("Commentaire: ")
                    }

                    TextArea {
                        placeholderText: qsTr("Commentaire")
                        background: Rectangle {
                            color: "white"
                            border.color: 'lightgrey'
                            border.width: 1
                        }
                        implicitWidth: 200
                        implicitHeight: 50
                    }

                    Label {
                        text: qsTr("Etat: ")
                    }

                    ComboBox {
                        width: 200
                        model: [ qsTr("Terminé"), qsTr("En cours"), qsTr("Autre") ]
                    }

                }

            }

            GroupBox {
                title: qsTr("Test")
                Layout.fillHeight: false
                GridLayout {
                    columns: 2

                    Label {
                        text: qsTr("Titre: ")
                    }

                    TextField {
                        placeholderText: qsTr("Titre")
                    }

                    Label {
                        text: qsTr("WO: ")
                    }

                    TextField {
                        placeholderText: qsTr("n° WO")
                    }

                    Label {
                        text: qsTr("Date: ")
                    }

                    TextField {
                        placeholderText: qsTr("Date du test")
                    }

                    Label {
                        text: qsTr("Commentaire: ")
                    }

                    TextArea {
                        placeholderText: qsTr("Commentaire")
                        background: Rectangle {
                            color: "white"
                            border.color: 'lightgrey'
                            border.width: 1
                        }
                        implicitWidth: 200
                        implicitHeight: 50
                    }

                    Label {
                        text: qsTr("Etat: ")
                    }

                    ComboBox {
                        width: 200
                        model: [ qsTr("Terminé"), qsTr("En cours"), qsTr("Autre") ]
                    }

                }
            }

            GroupBox {
                title: qsTr("Test")
                Layout.fillHeight: false
                GridLayout {
                    columns: 2

                    Label {
                        text: qsTr("Titre: ")
                    }

                    TextField {
                        placeholderText: qsTr("Titre")
                    }

                    Label {
                        text: qsTr("Date: ")
                    }

                    TextField {
                        placeholderText: qsTr("Date du test")
                    }

                    Label {
                        text: qsTr("Commentaire: ")
                    }

                    TextArea {
                        placeholderText: qsTr("Commentaire")
                        background: Rectangle {
                            color: "white"
                            border.color: 'lightgrey'
                            border.width: 1
                        }
                        implicitWidth: 200
                        implicitHeight: 50
                    }

                    Label {
                        text: qsTr("Etat: ")
                    }

                    ComboBox {
                        width: 200
                        model: [ qsTr("Terminé"), qsTr("En cours"), qsTr("Autre") ]
                        currentIndex: 1
                    }

                }
            }
        }

        Button {
            text: "Ok"
            onClicked: {

                pModel.addTaskTest("test", 10, "2020-03-16", "test", 1)
                addTaskDialog.close()
            }
        }
    }
}
