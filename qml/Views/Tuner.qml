import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: page
    property double needleAngle: 0

    Image {
        property double origWidth: 508
        property double origHeight: 267
        property double imgAspectRatio: origHeight / origWidth
        id: gauge
        width: page.width * 0.9
        height: width * imgAspectRatio
        x: page.width / 2 - width / 2
        y: page.height - height
        source: "img/gauge1.png"
        smooth: true


    }

    Image {
        property double origWidth: 104
        property double origHeight: 591
        property double imgAspectRatio: origWidth / origHeight

        id: needle
        height: gauge.height * 0.9
        width: height * imgAspectRatio
        x: parent.width / 2 - width / 2
        y: parent.height - height
        source: (Math.abs(needleAngle) < 10) ? "img/NeedleGreen.png" : "img/NeedleRed.png"
        smooth: true
        transform: Rotation {
            origin.x: needle.width / 2
            origin.y: needle.height*0.87
            angle: needleAngle
        }
    }

    //debug buttons
    Button{
        x: 100
        y: 100
        width: 100
        height: 100
        text: "-"
        onClicked: needleAngle -= 5
    }

    Button{
        x: 300
        y: 100
        width: 100
        height: 100
        text: "+"
        onClicked: needleAngle += 5
    }
}

