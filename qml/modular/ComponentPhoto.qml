import QtQuick

Item {
    id:texter
    property string texto: "texter"
    height:50
    width: 100
    TextInput{
        anchors.fill: parent
        text:parent.texto
    }
}
