#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"

class Enigma {
public:
    Enigma(int *r, int n);
    void printRotors();
    void printReflector();
    void setCode(int* pos);
    char process(char c);
    ~Enigma();
private:
    bool validate(char* c);
    void increment();
    Rotor* rotors[3];
    Reflector* reflector;
    int* pos;
};

#endif //ENIGMA_H