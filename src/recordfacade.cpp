#include "recordfacade.h"

RecordFacade::RecordFacade(QObject *parent) : QObject(parent) {
    _recorder = new Recorder(this);
}


RecordFacade::~RecordFacade() {
    delete _recorder;
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

int RecordFacade::getFrequency() {
    // todo fft
    return 123;
}
