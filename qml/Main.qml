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

    SplitView {
        orientation: Qt.Horizontal
        anchors.fill:parent
        Rectangle {
            // Panel izquierdo (Template Creator)
            id: leftPanel
            SplitView.preferredWidth: 320
            color: "yellow"
            TemplateCreator{
                id:templateCreator
                anchors.fill: parent
            }

            Button{
                height: 100
                width: 100
                x:parent.x+10
                text:"agregar testo"
                onClicked: templateCreator.exampleModel.append({"text":"ingrese otro texto",
                                                   "title":"testo",
                                                   "type":"texter"})
            }
            Button{
                height: 100
                width: 100
                x:parent.x+10+100
                text:"agregar imagen"
                onClicked: templateCreator.exampleModel.append({"text":"ingrese otra imagen",
                                                   "title":"testo",
                                                   "type":"imager"})
            }
            Button{
                height: 100
                width: 100
                x:parent.x+10+100
                y:parent.height-100
                text:"agregar a libreria"
                onClicked: CreatorBases.createQmlObject("qrc:/assets/TemplateCreator.qml",rightPanel,templateCreator)
            }
        }

        Rectangle {
            // Panel derecho (Template Libraries)

            id: rightPanel
            SplitView.preferredWidth: 320
            color: "red"

        }
    }
}
