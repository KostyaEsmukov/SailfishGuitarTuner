#ifndef STANDARDGUITAR_H
#define STANDARDGUITAR_H

#include "basestrings.h"

class StandardGuitar : public BaseStrings
{
public:
    explicit StandardGuitar(QObject *parent = 0) : BaseStrings(parent) { }

    virtual void getResult(RecordResult &recordResult, StringsResult &stringsResult);

private:
    // todo note + octave -> string mapping

signals:

public slots:
};

#endif // STANDARDGUITAR_H
