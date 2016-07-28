#include "recorder.h"

Recorder::Recorder(QObject *parent) : QObject(parent) {
    _recording = false;

    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
      qWarning() << "Default format not supported, trying to use the nearest.";
      format = info.nearestFormat(format);
    }

    _audioInput = new QAudioInput(format, this);

    connect(_audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
}

Recorder::~Recorder() {
    delete _audioInput;
}

void Recorder::startRecord() {
    _recording = true;
    _ioDevice = _audioInput->start();
}

void Recorder::stopRecord() {
    _recording = false;
    _audioInput->stop();
}

int Recorder::getData(float * buf, int bufSize) {
    char * charbuf = new char[bufSize];
    int read = _ioDevice->read(charbuf, bufSize);
    for (int i = 0; i < read; i++) {
        buf[i] = charbuf[i] / (sizeof(char) * 255);
    }

    delete[] buf;
    return read;
}

void Recorder::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
        case QAudio::StoppedState:
            if (_audioInput->error() != QAudio::NoError) {
                // Error handling
                qWarning() << "Error handling";
            } else {
                // Finished recording
                qWarning() << "Finished recording";
            }
            break;

        case QAudio::ActiveState:
            // Started recording - read from IO device
            qWarning() << "Started recording - read from IO device";
            break;

        default:
            // ... other cases as appropriate
            qWarning() << "... other cases as appropriate";
            break;
    }
}
