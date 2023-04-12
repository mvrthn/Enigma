#ifndef ROTOR_H
#define ROTOR_H

#include "RotorFabric.h"

class Rotor {
public:
    Rotor(RotorFabric* rf, int n);
    void print();
    char process(char c, int pos);
    ~Rotor();
private:
    char* connections;
};

#endif //ROTOR_H