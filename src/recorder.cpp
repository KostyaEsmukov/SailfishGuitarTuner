#include "recorder.h"

Recorder::Recorder(QObject *parent) : QObject(parent) {
    _recording = false;

}

Recorder::~Recorder() {

    if (p_record) {
        pa_simple_free(p_record);
    }
}

void Recorder::startRecord() {
    _recording = true;

    pa_sample_spec p_spec;

    p_spec.format = PA_SAMPLE_S16NE;
    p_spec.channels = 1;
    p_spec.rate = Recorder::rate;

    p_record = pa_simple_new(
            NULL,
            NAME,
            PA_STREAM_RECORD,
            NULL,
            "Tuner record",
            &p_spec,
            NULL,
            NULL,
            NULL
            );

}

void Recorder::stopRecord() {
    _recording = false;

    if (p_record) {
        pa_simple_free(p_record);
    }

    p_record = nullptr;
}

int Recorder::getData(int16_t * buf, int bufSize) {
    int err = pa_simple_read(p_record, (void*) buf, bufSize << 1, NULL);
    if (err < 0) {
        qWarning() << "pulseaudio read error " << err;
    }
    return bufSize;
}

