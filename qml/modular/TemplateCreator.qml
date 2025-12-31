import QtQuick
import QtQuick.Controls
import com.facu.utils
BaseTemplate {
    //seria basicamente esto, pero en un
    //QAbstractListModel
    //despues borrar todo lo relacionado al Listmodel de qml
    //se tiene que ajustar a las cosas que se aniaden
    property alias exampleModel:examplemodel
    id:root
    anchors.fill: parent
    ListModel{
        id:examplemodel
        ListElement{
            text: "ingrese texto"
            title:"testo"
            type:"texter"
        }
        ListElement{
            text: "ingrese imagen"
            title:"imagen"
            type:"imager"
        }
    }
    //Tengo que poder crear mas de este Rectangle pero desde C++.
    Rectangle{
        id:base
        width: 180; height: 200
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"cyan"
        clip:true
        ListView {
            anchors.fill: parent
            model: examplemodel
            delegate: Loader{
                id:loader
                source:{
                    switch (model.type){
                    case "texter":
                        return "qrc:/components/ComponentLabel.qml";
                    case "imager":
                        return "qrc:/components/ComponentPhoto.qml";
                }}
                onLoaded: {
                    loader.item.texto = model.text
                }
            }

        }
    }

}
