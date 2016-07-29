import QtQuick 2.0
import Sailfish.Silica 1.0
Page{
    SilicaListView {
        width: 480; height: 800
        model: 10
        delegate: Component {
            //x: Theme.paddingMedium
            //width: ListView.view.width
            Loader{
                source: index % 2 == 0 ? "part.qml" : "ClassicGuitar.qml"
            }

            //height: Theme.itemSizeSmall
            //Label { text: index }
        }
    }
}
