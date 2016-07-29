#ifndef RECORDFACADE_H
#define RECORDFACADE_H


#include <QAudio>
#include <QAudioInput>
#include <QMultimedia>
#include <QObject>
#include <QUrl>

#include <QDebug>

#include "recorder.h"
#include "recordresultcomputation.h"



class RecordFacade : public QObject
{
    Q_OBJECT


public:
    explicit RecordFacade(QObject *parent = 0);
    ~RecordFacade();

    Q_INVOKABLE void startRecord();
    Q_INVOKABLE void stopRecord();
    Q_INVOKABLE bool getResult(RecordResult &recordResult);
    Q_INVOKABLE double getResultFreq();
    Q_INVOKABLE bool isRecording();


private:
    static const int bufSize = 2048;
    char * buf;

    Recorder *_recorder;
    RecordResultComputation *_recordResultComputation;


signals:

public slots:
};

#endif // RECORDFACADE_H
