import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4

Button {
    id: button
    property url iconSrc
    display: AbstractButton.IconOnly

    icon.source: iconSrc
    icon.color: "White"
    background: Rectangle {
        color: button.down ? "#7caacc": "#7db4db"
        implicitWidth: 45
        implicitHeight: 45
        radius: 5
    }

    onPressed: {

    }


}
