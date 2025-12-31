import QtQuick

Item {
    id:imager
    property string texto: "imager"
    height:50
    width: 100
    TextInput{
        anchors.fill: parent
        text:parent.texto
    }
}
