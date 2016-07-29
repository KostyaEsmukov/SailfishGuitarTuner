/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../Views"

Page {
    id: page

    property string temperamentName: "Standart tenor"

    property list<Button> indicators
    property int someId: 0

    function setLight(id){
        for(var i = 0; i < 4; i++)
            indicators[i].color = Theme.highlightBackgroundColor
        indicators[id].color = Theme.primaryColor
    }

    SilicaFlickable {
        anchors.fill: parent
        PullDownMenu{
            MenuItem{
                text:qsTr("Ukulele temperaments")
                onClicked: pageStack.push(Qt.resolvedUrl("Stroi.qml"), {head: text, type: 4})
            }
            MenuItem{
                text:qsTr("Guitar temperaments")
                onClicked: pageStack.push(Qt.resolvedUrl("Stroi.qml"), {head: text, type : 6})
            }
            MenuItem{
                text:qsTr("Chande Light")
                onClicked: {
                    if (someId == 3)
                        someId = 0
                    else
                        someId++
                    setLight(someId)
                }

            }
        }

        Text{
            text : temperamentName
            font.pixelSize: 65
            color: Theme.primaryColor
            anchors.horizontalCenter: parent.horizontalCenter
            y: parent.height * 0.08
        }

        Tuner {
            x:0
            y:0
            height: parent.height / 2
            width: parent.width
        }

        Image {
            id: ukuHead
            source: "img/Ukulele1.png"
            height: parent.height / 2.2
            width: height * 0.77
            x: parent.width / 2 - width / 2
            y: parent.height - height
            smooth: true
        }


        // guitar strigs buttons
        Button {
            id: string3
            x: ukuHead.x + ukuHead.width
            y: ukuHead.y + ukuHead.height * 0.55
            width: 100
            height: 100
            text: "A"
            color: Theme.highlightBackgroundColor
        }

        Button {
            id: string2
            x: ukuHead.x + ukuHead.width
            y: ukuHead.y + ukuHead.height * 0.25
            width: 100
            height: 100
            text: "E"
            color: Theme.highlightBackgroundColor
        }
        Button {
            id: string1
            x: ukuHead.x - width
            y: ukuHead.y + ukuHead.height * 0.25
            width: 100
            height: 100
            text: "C"
            color: Theme.highlightBackgroundColor
        }
        Button {
            id: string0
            x: ukuHead.x - width
            y: ukuHead.y + ukuHead.height * 0.55
            width: 100
            height: 100
            text: "G"
            color: Theme.highlightBackgroundColor
        }
        Component.onCompleted: {
            indicators = [string0, string1, string2, string3]
        }

    }
}
