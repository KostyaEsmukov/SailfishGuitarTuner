#include <assert.h>

#include "recordresultcomputation.h"


/* with scpy:
 *
 * nyq=rate/2
 * norm=cutoff/nyq
 * b, a = butter(order, norm, btype='high', analog=False)
 */

// high 10hz / 16k
static double a10[] = { 1        , -2.99214602,  2.98432286, -0.99217678 };
static double b10[] = { 0.99608071, -2.98824212,  2.98824212, -0.99608071 };



RecordResultComputation::RecordResultComputation()
{
    high_filter = new LinearFilter<int16_t>(3, a10, b10);

    ZeroCross<int16_t>::Config cross_config({Recorder::rate, defaultNbFrame, defaultFreqMin, defaultFreqMax});
    cross = new ZeroCross<int16_t>(cross_config);

    scale = new Scale();

    Reset();
}


RecordResultComputation::~RecordResultComputation()
{
    delete high_filter;
    delete cross;
    delete scale;
}

/// reset analyse values
void RecordResultComputation::Reset()
{
    updated = false;
    count_found = count_not_found = 0;
    note_found = octave_found = -1;
    ResetDeviation();
    high_filter->Clear();
    cross->Clear();
}


void RecordResultComputation::ComputeFrame(int16_t v)
{
    v = (*high_filter)(v);
    (*cross)(v);
}

void RecordResultComputation::ResetDeviation()
{
    // reset deviation values
    nb_deviation = 0;
    deviation_start = 0;
    deviation_sum = 0;
}

void RecordResultComputation::UpdateDeviation(double d)
{
    if (nb_deviation == nbDeviationValues) {
        deviation_sum -= deviation_values[deviation_start];
        deviation_start = (deviation_start + 1) % nbDeviationValues;
        nb_deviation--;
    }
    deviation_values[(deviation_start + nb_deviation) % nbDeviationValues] = d;
    nb_deviation++;
    deviation_sum += d;
}


void RecordResultComputation::SetNotFound()
{
    if (count_not_found++ >= nbDefect) {
        count_found = 0;
        if (result_found) {
            result_found = false;
            ResetDeviation();
            updated = true;
        }
    }
}

bool RecordResultComputation::getResult(RecordResult &recordResult, char * buf, int read) {

    while (read--) ComputeFrame(*buf++);

    if (cross->Freq()) {
        int n, o = 0;
        double d = 0;

        n = scale->FindNote(cross->Freq(), o, d);

        recordResult.octave = o;
        recordResult.note = n;

        if (n != note_found || o != octave_found) {
            note_found = n;
            octave_found = o;
            count_found = 0;
            SetNotFound();

            ResetDeviation();
            UpdateDeviation(d);
        }
        else if (count_found++ >= nbConfirm) {
            count_not_found = 0;
            UpdateDeviation(d);

            recordResult.deviation = deviation_sum / nb_deviation;
            recordResult.frequency = cross->Freq();
            result_found = true;

            updated = true;
        }
        else {
            UpdateDeviation(d);
        }

        return true;
    }
    else {
        SetNotFound();

        return false;
    }
}

/*
int RecordResultComputation::FindNote(double freq, int &octave, double &deviation)
{
    assert (freq > 0);

    octave = 1;
    deviation = 0.2;
    return 3;

    if (!freq_setted) {
        std::cerr << "Scale " << __func__ << ": notes not setted" << std::endl;
        ConstructEqualTemperament();
    }

    int note = 0;
    octave = findOctave(freq);

    //std::cerr << octave << "  " << freq << std::endl;
    assert(freq >= actualRange[0] && freq <= actualRange[1]);

    while (actualNoteFreq[note] < freq && note < nbNote - 1) note++;

    if (note > 0) {
        if (freq / actualNoteFreq[note - 1] < actualNoteFreq[note] / freq) note--;
    }

    int sign = freq > actualNoteFreq[note] ? 1 : -1;

    if (sign == 1) deviation = log(freq / actualNoteFreq[note]) / log(halfToneFactor(note, sign));
    else deviation = log(actualNoteFreq[note] / freq) / log(halfToneFactor(note, sign));

    return note;

}

    */
