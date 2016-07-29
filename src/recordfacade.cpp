#include "recordfacade.h"

RecordFacade::RecordFacade(QObject *parent) : QObject(parent) {

    buf = new int16_t[bufSize];

    _recorder = new Recorder(this);
    _recordResultComputation = new RecordResultComputation();
}


RecordFacade::~RecordFacade() {
    delete _recorder;
    delete _recordResultComputation;
    delete buf;
}

void RecordFacade::startRecord() {
    _recorder->startRecord();
}

void RecordFacade::stopRecord() {
    _recorder->stopRecord();
}

bool RecordFacade::isRecording() {
    return _recorder->isRecording();
}

bool RecordFacade::getResult(RecordResult &recordResult) {
    int read = _recorder->getData(buf, bufSize);
    return _recordResultComputation->getResult(recordResult, buf, read);
}

double RecordFacade::getResultFreq() {
    RecordResult recordResult;
    this->getResult(recordResult);

    return recordResult.frequency;
}
