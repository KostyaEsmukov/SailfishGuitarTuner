# Sailfish GuitarTuner

This was a hackathon project made for the event by the Open Mobile Platform which took part from 27 to 30 of July 2016 in Innopolis city, Russia.

## Status

It should work as is, but with Ukulele tuning only.

It was never published neither to the Harbour nor to the openrepos.

Feel free to drop me a note if you're interested in bringing this project to life.

## Dev setup

to add pulseaudio dev to MerSDK:

    sudo zypper in pulseaudio-devel
    sb2 -t SailfishOS-i486 -m sdk-install -R zypper in pulseaudio-devel
    sb2 -t SailfishOS-armv7hl -m sdk-install -R zypper in pulseaudio-devel

for libresource:

    sudo zypper in libresource-devel
    sb2 -t SailfishOS-i486 -m sdk-install -R zypper in libaudioresource-devel
    sb2 -t SailfishOS-armv7hl -m sdk-install -R zypper in libaudioresource-devel
