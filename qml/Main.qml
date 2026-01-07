import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import "modular"
import com.facu.utils

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property TemplateCreator templateExample: TemplateCreator{}
    SplitView {
        orientation: Qt.Horizontal
        anchors.fill:parent
        Rectangle {
            // Panel izquierdo (Template Creator)
            id: leftPanel
            SplitView.preferredWidth: 320
            color: "yellow"
            Item{
                id:templateContainer
                anchors.fill: parent
                Item{
                    id:centerContainer
                    width: templateExample.width
                    height: templateExample.height
                    anchors.centerIn: parent
                }

                Component.onCompleted: CreatorBases.createQmlObjectTemplate("qrc:/assets/TemplateCreator.qml",centerContainer)
            }

            Button{
                height: 100
                width: 100
                x:parent.x+10
                text:"agregar testo"
                onClicked:CreatorBases.getTemplate().exampleModel.append({"text":"ingrese otro texto",
                                                                             "title":"testo",
                                                                             "type":"texter"})
            }
            Button{
                height: 100
                width: 100
                x:parent.x+10+100
                text:"agregar imagen"
                onClicked:CreatorBases.getTemplate().exampleModel.append({"text":"ingrese otra imagen",
                                                                             "title":"testo",
                                                                             "type":"imager"})
            }
            Button{
                height: 100
                width: 100
                x:parent.x+10+100
                y:parent.height-100
                text:"agregar a libreria"
                onClicked: CreatorBases.moveToMostrador(0,centerContainer)
            }
        }

        Rectangle {
            // Panel derecho (Template Libraries)

            id: rightPanel
            SplitView.preferredWidth: 320
            color: "red"
            Flickable {
                id: flick
                //height:300; width: 300
                anchors.fill: parent
                //contentWidth/Height es el area que permite
                //scrollear.
                contentWidth: mostrador.width
                contentHeight: mostrador.height
                clip: true

                // Esto permite que la rueda del mouse mueva el contenido
                interactive: true
                boundsMovement: Flickable.StopAtBounds
                acceptedButtons: Qt.MiddleButton
                /*
                Column {
                    id:mostrador
                    width: 500
                    height: 500
                    spacing: 2

                    Rectangle { color: "red"; width: 50; height: 100 }
                    Rectangle { color: "green"; width: 20; height: 200 }
                    Rectangle { color: "blue"; width: 50; height: 200 }
                }
                */


                TemplateContainer{
                    id:mostrador
                    width: parent.width
                    height: 500
                    Component.onCompleted:CreatorBases.setTemplateContainer(this)
                }


            }
        }
    }
}
