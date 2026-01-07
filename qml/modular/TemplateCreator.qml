import QtQuick
import QtQuick.Controls
import com.facu.utils
BaseTemplate {
    //seria basicamente esto, pero en un
    //QAbstractListModel
    //despues borrar todo lo relacionado al Listmodel de qml
    //se tiene que ajustar a las cosas que se aniaden
    property alias exampleModel:examplemodel
    property alias enabledButt:deleteButton.enabled
    id:root
    width: 150; height: 180
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
        width: parent.width; height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"cyan"
        clip:true
        Text{
            id:aidi
            anchors.top:parent.top
            anchors.right: parent.right
            height: 8
            text:root.ide
        }
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
        Button{
            id:deleteButton
            enabled:false
            anchors{
                right: parent.right
                bottom: parent.bottom
            }
            height: 10
            width: 10
            onClicked: CreatorBases.borrarItem(root.ide)
        }
    }

}
