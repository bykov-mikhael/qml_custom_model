import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 250
    height: 150
    visible: true
    title: "METANIT.COM"

    ListView {
        model: myModel
        anchors.fill: parent
        delegate: Text {
            text: model.date + " " + model.time + " " + model.message + " " + model.random
        }
    }
}
