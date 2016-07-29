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


Page {
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
        y: page.height / 2 - height
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
        y: parent.height / 2 - height
        source: (Math.abs(needleAngle) < 10) ? "img/NeedleGreen.png" : "img/NeedleRed.png"
        smooth: true
        transform: Rotation {
            origin.x: needle.width / 2
            origin.y: needle.height*0.87
            angle: needleAngle
        }
    }

    Image {
        id: ukuHead
        source: "img/guitar.png"
        height: parent.height / 2.2
        width: height * 0.77
        x: parent.width / 2 - width / 2
        y: parent.height - height
        smooth: true
    }

    // guitar strigs buttons
    Button {
        id: stringD
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.55
        width: 100
        height: 100
        text: "E"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: stringA
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.25
        width: 100
        height: 100
        text: "A"
        color: Theme.highlightBackgroundColor
    }


    Button {
        id: stringE
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.75
        width: 100
        height: 100
        text: "D"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: stringG
        x: ukuHead.x + ukuHead.width
        y: ukuHead.y + ukuHead.height * 0.25
        width: 100
        height: 100
        text: "G"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: stringB
        x: ukuHead.x + ukuHead.width
        y: ukuHead.y + ukuHead.height * 0.55
        width: 100
        height: 100
        text: "B"
        color: Theme.highlightBackgroundColor
    }


    Button {
        id: stringE2
        x: ukuHead.x + ukuHead.width
        y: ukuHead.y + ukuHead.height * 0.75
        width: 100
        height: 100
        text: "E"
        color: Theme.highlightBackgroundColor
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




