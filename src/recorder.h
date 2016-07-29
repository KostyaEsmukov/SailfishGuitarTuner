#ifndef RECORDER_H
#define RECORDER_H

#include <QAudio>
#include <QAudioInput>
#include <QMultimedia>
#include <QObject>
#include <QUrl>

#include <QDebug>

extern "C" {
#include <pulse/simple.h>
}

#define name_(x) #x
#define name(x) name_(x)
#define NAME name(TARGET)


class Recorder : public QObject
{
    Q_OBJECT

public:
    explicit Recorder(QObject *parent = 0);
    ~Recorder();

    void startRecord();
    void stopRecord();
    int getData(int16_t * buf, int bufSize);
    bool isRecording() { return _recording; }

    static const int rate = 16000;

private:
    pa_simple *p_record;

    bool _recording;

    void handleStateChanged(QAudio::State newState);
};

#endif // RECORDER_H
