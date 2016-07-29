#include "wrapper.h"

Wrapper::Wrapper(QObject *parent) : QObject(parent)
{
    _recordFacade = new RecordFacade(this);

    _guitarStrings.append(new StandardGuitar(this));

    _ukuleleStrings.append(new TenorUkulele(this));

    _activeStrings = _ukuleleStrings[0];
}

Wrapper::~Wrapper() {
    delete _recordFacade;

    for (auto it : _ukuleleStrings) {
        delete it;
    }
    for (auto it : _guitarStrings) {
        delete it;
    }
}

RecordFacade * Wrapper::getRecordFacade() {
    return _recordFacade;
}


QStringsResult * Wrapper::getStringsResult() {
    QStringsResult * r = new QStringsResult(this);

    RecordResult recordResult;
    if (!_recordFacade->getResult(recordResult)) {
        r->active = false;

    } else {
        StringsResult stringsResult;
        _activeStrings->getResult(recordResult, stringsResult);
        r->active = true;
        r->deviation = stringsResult.deviation;
        r->stringIdx = stringsResult.stringIdx;
    }
    return r;
}
