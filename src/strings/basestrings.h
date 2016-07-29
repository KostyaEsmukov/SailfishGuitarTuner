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


        for (int i = 0; i < cnt-1; i++) {
            if (noteFreqs[i] - EPS <= recordResult.frequency
                    && recordResult.frequency <= noteFreqs[i+1] + EPS) {

                double d = noteFreqs[i+1] - noteFreqs[i];

                if (recordResult.frequency < noteFreqs[i] + d/2) {
                    stringsResult.stringIdx = i;
                    stringsResult.deviation = (recordResult.frequency - noteFreqs[i]) / (d/2);
                } else {
                    stringsResult.stringIdx = i + 1;
                    stringsResult.deviation = (recordResult.frequency - noteFreqs[i+1]) / (d/2);
                }
                break;
            }
        }


        if (noteFreqs[cnt-1] + EPS <= recordResult.frequency) {
            stringsResult.stringIdx = cnt-1;
            stringsResult.deviation = (recordResult.frequency - noteFreqs[cnt-1])
                    / ((noteFreqs[cnt-1] - noteFreqs[cnt-2]) / 2);
            if (stringsResult.deviation > 1)
                stringsResult.deviation = 1;
            return;
        }


        // if (recordResult.frequency <= noteFreqs[0] - EPS) {
            stringsResult.stringIdx = 0;
            stringsResult.deviation = (recordResult.frequency - noteFreqs[0])
                    / ((noteFreqs[1] - noteFreqs[0]) / 2);
            if (stringsResult.deviation < -1)
                stringsResult.deviation = -1;

            return;
        // }

    }


    const double* getFreqs() {
        if (_freqs == nullptr) {
            Scale scale;

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
