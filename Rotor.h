#ifndef ROTOR_H
#define ROTOR_H

#include "RotorFabric.h"

class Rotor {
public:
    Rotor(RotorFabric* rf, int n);
    char process(char c, int pos);
    ~Rotor();
private:
    char* connections;
};

#endif //ROTOR_H