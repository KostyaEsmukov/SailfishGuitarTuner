#ifndef STANDARDGUITAR_H
#define STANDARDGUITAR_H

#include "basestrings.h"
#include "../notes.h"

class StandardGuitar : public BaseStrings
{
public:
    explicit StandardGuitar(QObject *parent = 0) : BaseStrings(parent) {
        _notes = new int[6]{NOTE_E, NOTE_A, NOTE_D, NOTE_G, NOTE_B, NOTE_E};
        _octaves = new int[6]{-1, -1, 0, 0, 0, 1};
    }
    ~StandardGuitar() {
        delete _notes;
        delete _octaves;
    }

protected:
    virtual const int getStringsCount() {
        return 6;
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

#endif // STANDARDGUITAR_H
