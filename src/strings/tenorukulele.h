#ifndef TENORUKULELE_H
#define TENORUKULELE_H


#include "basestrings.h"
#include "../notes.h"


class TenorUkulele : public BaseStrings
{
public:
    explicit TenorUkulele(QObject *parent = 0) : BaseStrings(parent) {
        _notes = new int[4]{NOTE_G, NOTE_C, NOTE_E, NOTE_A};
        _octaves = new int[4]{4, 4, 4, 4};
    }
    ~TenorUkulele() {
        delete _notes;
        delete _octaves;
    }

protected:
    virtual const int getStringsCount() {
        return 4;
    }

    virtual const int* getNotes() {
        return _notes;
    }

    virtual const int* getOctaves() {
        return _octaves;
    }

private:
    int * _notes;
    int * _octaves;

};

#endif // TENORUKULELE_H
