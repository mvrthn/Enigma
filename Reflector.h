#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "RotorFabric.h"

class Reflector {
public:
    Reflector(RotorFabric* rf, int n);
    char process(char c);
    ~Reflector();
private:
    char* connections;
};

#endif //REFLECTOR_H