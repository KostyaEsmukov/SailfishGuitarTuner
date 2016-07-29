#ifndef RECORDRESULTCOMPUTATION_H
#define RECORDRESULTCOMPUTATION_H

#include "recorder.h"

#include "vendor/LinearFilter.hpp"
#include "vendor/ZeroCross.hpp"
#include "vendor/Scale.hpp"


struct RecordResult {
    double deviation = 0;
    double frequency = 0;
    int note = 0;
    int octave = 0;
};

class RecordResultComputation
{
public:
    RecordResultComputation();
    ~RecordResultComputation();

    bool getResult(RecordResult &recordResult, int16_t * buf, int read);

private:

    static const int defaultNbFrame = 2048;
    static const int defaultFreqMin = 30;
    static const int defaultFreqMax = 3000;
    /// number of analyses to confirm a note
    static const int nbConfirm = 3;
    /// number of analyses to drop a note
    static const int nbDefect = 14;
    /// number of deviation values for average
    static const int nbDeviationValues = 4;

    LinearFilter<int16_t> *high_filter;
    ZeroCross<int16_t> *cross;
    Scale *scale;

    bool updated;
    int note_found, octave_found, count_found, count_not_found;
    int nb_deviation, deviation_start;
    double deviation_sum;
    double deviation_values[nbDeviationValues];

    bool result_found;


    void Reset();
    void ComputeFrame(int16_t v);
    void ResetDeviation();
    void UpdateDeviation(double d);
    void SetNotFound();
    // int FindNote(double freq, int &octave, double &deviation);


signals:

public slots:
};

#endif // RECORDRESULTCOMPUTATION_H
