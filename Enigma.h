#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"
#include "Keyboard.h"

class Enigma {
public:
    Enigma(int *r, int n);
    void setCode(int* pos);
    void listen();
    ~Enigma();
private:
    char process(char c);
    void increment();
    void print(char* buffer);
    Rotor* rotors[3];
    Reflector* reflector;
    Keyboard* keyboard;
    int* pos;
};

#endif //ENIGMA_H