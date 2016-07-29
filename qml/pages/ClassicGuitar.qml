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

    Tuner {
        x:0
        y:0
        height: parent.height / 2
        width: parent.width
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
        id: string0
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.61-height/2
        width: 100
        height: 100
        text: "E"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: string1
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.435- height/2
        width: 100
        height: 100
        text: "A"
        color: Theme.highlightBackgroundColor
    }


    Button {
        id: string2
        x: ukuHead.x - width
        y: ukuHead.y + ukuHead.height * 0.26 - height/2
        width: 100
        height: 100
        text: "D"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: string3
        x: ukuHead.x + ukuHead.width
        y: string2.y
        width: 100
        height: 100
        text: "G"
        color: Theme.highlightBackgroundColor
    }

    Button {
        id: string4
        x: ukuHead.x + ukuHead.width
        y: string1.y
        width: 100
        height: 100
        text: "B"
        color: Theme.highlightBackgroundColor
    }


    Button {
        id: string5
        x: ukuHead.x + ukuHead.width
        y: string0.y
        width: 100
        height: 100
        text: "E"
        color: Theme.highlightBackgroundColor
    }

    property list<Button> strings
    Component.onCompleted: {
        strings = [string0, string1, string2,
                   string3, string4, string5]
    }
}





