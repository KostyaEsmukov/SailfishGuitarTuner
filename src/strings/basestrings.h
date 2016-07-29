#ifndef BASESTRINGS_H
#define BASESTRINGS_H

#include <QObject>

#include "../recordfacade.h";
#include "../vendor/Scale.hpp";


struct StringsResult {
    int stringIdx;
    float deviation;
};

const double EPS = 1e-2;

class BaseStrings : public QObject
{
    Q_OBJECT
public:
    explicit BaseStrings(QObject *parent = 0) : QObject(parent)
    {

    }

    virtual ~BaseStrings() {
        delete _freqs;
    }

    void getResult(RecordResult &recordResult, StringsResult &stringsResult) {

        const double * noteFreqs = this->getFreqs();
        const int cnt = this->getStringsCount();


        int choice = 0;
        double choiceDelta;
        for (int i = 0; i < cnt; i++) {
            double curDelta = (noteFreqs[i] - recordResult.frequency);
            if (curDelta < 0) curDelta *= -1.0;

            if (i == 0 || curDelta < choiceDelta) {
                choiceDelta = curDelta;
                choice = i;
            }
        }

        stringsResult.stringIdx = choice;
        stringsResult.deviation = (recordResult.frequency - noteFreqs[choice]) / 30.0;


        if (stringsResult.deviation < -1)
            stringsResult.deviation = -1;

        if (stringsResult.deviation > 1)
            stringsResult.deviation = 1;

    }


    const double* getFreqs() {
        if (_freqs == nullptr) {
            Scale scale;
            scale.ConstructEqualTemperament();

            const int * notes = this->getNotes();
            const int * octaves = this->getOctaves();

            _freqs = new double[this->getStringsCount()];
            for (int i = 0; i < this->getStringsCount(); i++) {
                _freqs[i] = scale.GetNoteFreq(notes[i], octaves[i]);
            }

        }
        return _freqs;
    }

    QList<int> & getStringNotes() {
        QList<int> ret;
        const int * notes = this->getNotes();
        for (int i = 0; i < this->getStringsCount(); i++) {
            ret << notes[i];
        }
        return ret;
    }

protected:
    virtual const int getStringsCount() = 0;
    virtual const int* getNotes() = 0;
    virtual const int* getOctaves() = 0;

private:
    double * _freqs = nullptr;

};

#endif // BASESTRINGS_H
