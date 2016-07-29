import QtQuick 2.0
import Sailfish.Silica 1.0
Page {
    property string head
    property int type: 10
    SilicaListView {
        header: PageHeader{ title: head}

        anchors.fill: parent
        model: ListModel{
            ListElement{
                name: "Some temperament"
            }
            ListElement{
                name: "Some temperament 2"
            }
            ListElement{
                name: "Some temperament 3"
            }
        }

        delegate: Item{
            width: ListView.view.width
            height: Theme.itemSizeSmall
            Column{
                Text{
                    id:nameField
                    color: Theme.primaryColor
                    x: Theme.horizontalPageMargin
                    text : name
                    font.weight: Font.Black
                }
                Text{
                    color: Theme.primaryColor
                    x: Theme.horizontalPageMargin
                    font.pixelSize: nameField.font.pixelSize * 0.7
                    text: name
                }


            }
        }
    }
    Component.onCompleted: console.log(type)
}

