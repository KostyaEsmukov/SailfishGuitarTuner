#ifndef BASESTRINGS_H
#define BASESTRINGS_H

#include <QObject>

#include "../recordfacade.h";


struct StringsResult {
    int stringIdx;
    float deviation;
};

class BaseStrings : public QObject
{
    Q_OBJECT
public:
    explicit BaseStrings(QObject *parent = 0);

    virtual void getResult(RecordResult &recordResult, StringsResult &stringsResult) = 0;


signals:

public slots:
};

#endif // BASESTRINGS_H
