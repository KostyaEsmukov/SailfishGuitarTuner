#ifndef WRAPPER_H
#define WRAPPER_H

#include <memory>

#include <QAudio>
#include <QAudioInput>
#include <QMultimedia>
#include <QObject>
#include <QUrl>
#include <QVector>

#include <QDebug>

#include "recordfacade.h"
#include "./strings/basestrings.h"
#include "./strings/standardguitar.h"
#include "./strings/tenorukulele.h"


class QStringsResult : public QObject {
    Q_OBJECT

public:
    bool active;
    int stringIdx;
    float deviation;

    explicit QStringsResult(QObject *parent = 0) : QObject(parent) {}
};

class Wrapper : public QObject
{
    Q_OBJECT

public:
    explicit Wrapper(QObject *parent = 0);
    ~Wrapper();

    Q_INVOKABLE RecordFacade * getRecordFacade();

    Q_INVOKABLE QStringsResult * getStringsResult();

private:
    RecordFacade * _recordFacade;
    BaseStrings * _activeStrings;
    QVector<BaseStrings*> _guitarStrings;
    QVector<BaseStrings*> _ukuleleStrings;

signals:

public slots:
};

#endif // WRAPPER_H
