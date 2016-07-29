

to add pulseaudio dev to MerSDK:

    sudo zypper in pulseaudio-devel
    sb2 -t SailfishOS-i486 -m sdk-install -R zypper in pulseaudio-devel
    sb2 -t SailfishOS-armv7hl -m sdk-install -R zypper in pulseaudio-devel

for libresource:

    sudo zypper in libresource-devel
    sb2 -t SailfishOS-i486 -m sdk-install -R zypper in libaudioresource-devel
    sb2 -t SailfishOS-armv7hl -m sdk-install -R zypper in libaudioresource-devel
