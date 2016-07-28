#ifndef RECORDER_H
#define RECORDER_H

#include <QAudio>
#include <QAudioInput>
#include <QMultimedia>
#include <QObject>
#include <QUrl>

#include <QDebug>

class Recorder : public QObject
{
    Q_OBJECT

public:
    explicit Recorder(QObject *parent = 0);
    ~Recorder();

    void startRecord();
    void stopRecord();
    int getData(float * buf, int bufSize);
    bool isRecording() { return _recording; }

private:
    QAudioInput *_audioInput;
    QIODevice *_ioDevice;

    bool _recording;

    void handleStateChanged(QAudio::State newState);
};

#endif // RECORDER_H
